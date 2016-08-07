/**
  * \file FmnccmbdAppsrv.cpp
  * application server for Fmnc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "Fmnccmbd.h"

#include "FmnccmbdAppsrv.h"

/******************************************************************************
 namespace FmnccmbdAppsrv
 ******************************************************************************/

MHD_Daemon* FmnccmbdAppsrv::start(
			XchgFmnccmbd* xchg
		) {
//	return MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, xchg->stgfmnccmbd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_THREAD_POOL_SIZE, 16, MHD_OPTION_END);
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, xchg->stgfmnccmbd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void FmnccmbdAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int FmnccmbdAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int FmnccmbdAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgFmnc* xchg = (XchgFmnc*) cls;

  MHD_Response* response;
	int retval = MHD_YES;

	ReqFmnc* req;
	uint ixVBasetype = ReqFmnc::VecVBasetype::NONE;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	timeval now;
	timespec nexttime;

	uint ixFmncVDpch;

	ubigint jrefNotify;

	DcolFmnc* dcol;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s, s2;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		s = string(url);

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << s << "'" << endl;

			if (s.find("/web/") != string::npos) {
				// cout << "request for '" << s.substr(4) << "' by html transfer" << endl;

				// ex. "/html/CrdFmncNav/CrdFmncNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url

				// inhibit requests to ../ directories
				if (s.find("../") == string::npos) {

					// check if file exists
					s2 = xchg->stgfmncpath.webpath + s.substr(4);
					if (access(s2.c_str(), R_OK) == 0) {
						ixVBasetype = ReqFmnc::VecVBasetype::WEB;
						// cout << "MhdCallback() HTML request for '" << s2 << "'" << endl;
					};
				};

			} else if (s.find("/notify") != string::npos) {
				// always "/notify/abcd1234efgh5678/..."
				ixVBasetype = ReqFmnc::VecVBasetype::NOTIFY;

			} else if (s.find("/poll") != string::npos) {
				// always "/poll/abcd1234efgh5678/..."
				ixVBasetype = ReqFmnc::VecVBasetype::POLL;

			} else if (s.find("/download/") != string::npos) {
				// ex. "/download/abcd1234efgh5678/..."
				ixVBasetype = ReqFmnc::VecVBasetype::DOWNLOAD;
			};

		} else if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				// always "/dpch"
				ixVBasetype = ReqFmnc::VecVBasetype::REGULAR;

			} else if (s.find("/upload/") != string::npos) {
				// ex. "/upload/abcd1234efgh5678"
				ixVBasetype = ReqFmnc::VecVBasetype::UPLOAD;
			};
		};

		if (ixVBasetype == ReqFmnc::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqFmnc(ixVBasetype, ReqFmnc::VecVState::RECEIVE, ip);

			*con_cls = req;

			if (req->ixVBasetype == ReqFmnc::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = xchg->stgfmncpath.webpath + s.substr(4);

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecFmncVMimetype::getTitle(VecFmncVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecFmncVMimetype::getTitle(VecFmncVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/notify/")+8));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecFmncVPreset::PREFMNCJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixFmncVLocale = dcol->ixFmncVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngFmncAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("FmnccmbdAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngFmncSuspend(req->jref);

							dcol->unlockAccess("FmnccmbdAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngFmncAck(req->jref);
							dcol->req = req;

							gettimeofday(&now, NULL);
							nexttime.tv_sec = now.tv_sec + 15;
							nexttime.tv_nsec = 1000*now.tv_usec;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							Mutex::lock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("FmnccmbdAppsrv", "MhdCallback[3]");
							Cond::timedwait(&(req->cReady), &(req->mcReady), &nexttime, "req->cReady", "FmnccmbdAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							Mutex::unlock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("FmnccmbdAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngFmncConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqFmnc::VecVState::REPLY;

						// send reply ; note that the result of Cond::timedwait() doesn't matter
						response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("FmnccmbdAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqFmnc::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/poll/")+6));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixFmncVLocale = dcol->ixFmncVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngFmncAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("FmnccmbdAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqFmnc::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/upload/")+8));

				// generate file in tmp directory, and open it
				req->filename = xchg->stgfmncpath.tmppath + "/" + Tmp::newfile(xchg->stgfmncpath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/download/")+10));
				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					Mutex::lock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[2]");
					Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "FmnccmbdAppsrv", "MhdCallback[1]");
					Mutex::unlock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: REGULAR, UPLOAD)
		req = (ReqFmnc*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() REGULAR request complete" << endl;
					valid = req->request;
					
					if (valid) {
						//cout << req->request << endl;
						ixFmncVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixFmncVDpch == VecFmncVDpch::DPCHAPPROOTFMNCLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						Mutex::lock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqFmnc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "FmnccmbdAppsrv", "MhdCallback[2]");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						Mutex::lock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[4]");
						Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "FmnccmbdAppsrv", "MhdCallback[3]");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "FmnccmbdAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int FmnccmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t FmnccmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqFmnc* req = (ReqFmnc*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

int FmnccmbdAppsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqFmnc* req = (ReqFmnc*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
		// --- copy data into req->request (append if required)
		if (strcmp(key, "xml") != 0) return MHD_NO;

		if (size > 0) {
			if (!req->request) {
				req->request = new char[size];
				memcpy(req->request, data, size);
				req->requestlen = size;

			} else {
				olddata = req->request;

				req->request = new char[req->requestlen + size];
				memcpy(req->request, olddata, req->requestlen);
				memcpy(&(req->request[req->requestlen]), data, size);
				req->requestlen = req->requestlen + size;

				delete[] olddata;
			};
		};

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void FmnccmbdAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqFmnc* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqFmnc*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool FmnccmbdAppsrv::validateIp(
			XchgFmnccmbd* xchg
			, ReqFmnc* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		ip = xchg->getTxtvalPreset(VecFmncVPreset::PREFMNCIP, req->jref);
		if (ip.compare(req->ip) != 0) retval = false;
	};

	return retval;
};

bool FmnccmbdAppsrv::validateJrefNotify(
			XchgFmnccmbd* xchg
			, ReqFmnc* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolFmnc* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecFmncVPreset::PREFMNCJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecFmncVCall::CALLFMNCREFPRESET, dcol->jref, VecFmncVPreset::PREFMNCJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("FmnccmbdAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint FmnccmbdAppsrv::readDpchApp(
			XchgFmnccmbd* xchg
			, ReqFmnc* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixFmncVDpch = VecFmncVDpch::getIx(extractRoot(doc));

	if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCACTNEWDATA) {
		req->dpchapp = new DlgFmncActNew::DpchAppData();
		((DlgFmncActNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCACTNEWDO) {
		req->dpchapp = new DlgFmncActNew::DpchAppDo();
		((DlgFmncActNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCFABEXPFABDATA) {
		req->dpchapp = new DlgFmncFabExpfab::DpchAppData();
		((DlgFmncFabExpfab::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCFABEXPFABDO) {
		req->dpchapp = new DlgFmncFabExpfab::DpchAppDo();
		((DlgFmncFabExpfab::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCFABIMPFABDATA) {
		req->dpchapp = new DlgFmncFabImpfab::DpchAppData();
		((DlgFmncFabImpfab::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCFABIMPFABDO) {
		req->dpchapp = new DlgFmncFabImpfab::DpchAppDo();
		((DlgFmncFabImpfab::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCFABNEWDATA) {
		req->dpchapp = new DlgFmncFabNew::DpchAppData();
		((DlgFmncFabNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCFABNEWDO) {
		req->dpchapp = new DlgFmncFabNew::DpchAppDo();
		((DlgFmncFabNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCNAVLOAINIDATA) {
		req->dpchapp = new DlgFmncNavLoaini::DpchAppData();
		((DlgFmncNavLoaini::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCNAVLOAINIDO) {
		req->dpchapp = new DlgFmncNavLoaini::DpchAppDo();
		((DlgFmncNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGEXPORGDATA) {
		req->dpchapp = new DlgFmncOrgExporg::DpchAppData();
		((DlgFmncOrgExporg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGEXPORGDO) {
		req->dpchapp = new DlgFmncOrgExporg::DpchAppDo();
		((DlgFmncOrgExporg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGIMPORGDATA) {
		req->dpchapp = new DlgFmncOrgImporg::DpchAppData();
		((DlgFmncOrgImporg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGIMPORGDO) {
		req->dpchapp = new DlgFmncOrgImporg::DpchAppDo();
		((DlgFmncOrgImporg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGNEWDATA) {
		req->dpchapp = new DlgFmncOrgNew::DpchAppData();
		((DlgFmncOrgNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGNEWDO) {
		req->dpchapp = new DlgFmncOrgNew::DpchAppDo();
		((DlgFmncOrgNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCPRJEXPELBDATA) {
		req->dpchapp = new DlgFmncPrjExpelb::DpchAppData();
		((DlgFmncPrjExpelb::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCPRJEXPELBDO) {
		req->dpchapp = new DlgFmncPrjExpelb::DpchAppDo();
		((DlgFmncPrjExpelb::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCPRJIMPELBDATA) {
		req->dpchapp = new DlgFmncPrjImpelb::DpchAppData();
		((DlgFmncPrjImpelb::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCPRJIMPELBDO) {
		req->dpchapp = new DlgFmncPrjImpelb::DpchAppDo();
		((DlgFmncPrjImpelb::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCPRJNEWDATA) {
		req->dpchapp = new DlgFmncPrjNew::DpchAppData();
		((DlgFmncPrjNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCPRJNEWDO) {
		req->dpchapp = new DlgFmncPrjNew::DpchAppDo();
		((DlgFmncPrjNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDATA) {
		req->dpchapp = new DlgFmncRunGenrep::DpchAppData();
		((DlgFmncRunGenrep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDO) {
		req->dpchapp = new DlgFmncRunGenrep::DpchAppDo();
		((DlgFmncRunGenrep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCRUNNEWDATA) {
		req->dpchapp = new DlgFmncRunNew::DpchAppData();
		((DlgFmncRunNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCRUNNEWDO) {
		req->dpchapp = new DlgFmncRunNew::DpchAppDo();
		((DlgFmncRunNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCSMPGENREPDATA) {
		req->dpchapp = new DlgFmncSmpGenrep::DpchAppData();
		((DlgFmncSmpGenrep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCSMPGENREPDO) {
		req->dpchapp = new DlgFmncSmpGenrep::DpchAppDo();
		((DlgFmncSmpGenrep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCSMPNEWDATA) {
		req->dpchapp = new DlgFmncSmpNew::DpchAppData();
		((DlgFmncSmpNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCSMPNEWDO) {
		req->dpchapp = new DlgFmncSmpNew::DpchAppDo();
		((DlgFmncSmpNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACT1NSTEPDATA) {
		req->dpchapp = new PnlFmncAct1NStep::DpchAppData();
		((PnlFmncAct1NStep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACT1NSTEPDO) {
		req->dpchapp = new PnlFmncAct1NStep::DpchAppDo();
		((PnlFmncAct1NStep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACTDETAILDATA) {
		req->dpchapp = new PnlFmncActDetail::DpchAppData();
		((PnlFmncActDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACTDETAILDO) {
		req->dpchapp = new PnlFmncActDetail::DpchAppDo();
		((PnlFmncActDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACTDO) {
		req->dpchapp = new CrdFmncAct::DpchAppDo();
		((CrdFmncAct::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACTLISTDATA) {
		req->dpchapp = new PnlFmncActList::DpchAppData();
		((PnlFmncActList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACTLISTDO) {
		req->dpchapp = new PnlFmncActList::DpchAppDo();
		((PnlFmncActList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCACTRECDO) {
		req->dpchapp = new PnlFmncActRec::DpchAppDo();
		((PnlFmncActRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRDETAILDATA) {
		req->dpchapp = new PnlFmncAdrDetail::DpchAppData();
		((PnlFmncAdrDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRDETAILDO) {
		req->dpchapp = new PnlFmncAdrDetail::DpchAppDo();
		((PnlFmncAdrDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRDO) {
		req->dpchapp = new CrdFmncAdr::DpchAppDo();
		((CrdFmncAdr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRLISTDATA) {
		req->dpchapp = new PnlFmncAdrList::DpchAppData();
		((PnlFmncAdrList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRLISTDO) {
		req->dpchapp = new PnlFmncAdrList::DpchAppDo();
		((PnlFmncAdrList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRRECDO) {
		req->dpchapp = new PnlFmncAdrRec::DpchAppDo();
		((PnlFmncAdrRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCALERT) {
		req->dpchapp = new DpchAppFmncAlert();
		((DpchAppFmncAlert*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCART1NSAMPLEDATA) {
		req->dpchapp = new PnlFmncArt1NSample::DpchAppData();
		((PnlFmncArt1NSample::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCART1NSAMPLEDO) {
		req->dpchapp = new PnlFmncArt1NSample::DpchAppDo();
		((PnlFmncArt1NSample::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCART1NSTOCKITEMDATA) {
		req->dpchapp = new PnlFmncArt1NStockitem::DpchAppData();
		((PnlFmncArt1NStockitem::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCART1NSTOCKITEMDO) {
		req->dpchapp = new PnlFmncArt1NStockitem::DpchAppDo();
		((PnlFmncArt1NStockitem::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTDETAILDATA) {
		req->dpchapp = new PnlFmncArtDetail::DpchAppData();
		((PnlFmncArtDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTDETAILDO) {
		req->dpchapp = new PnlFmncArtDetail::DpchAppDo();
		((PnlFmncArtDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTDO) {
		req->dpchapp = new CrdFmncArt::DpchAppDo();
		((CrdFmncArt::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTLISTDATA) {
		req->dpchapp = new PnlFmncArtList::DpchAppData();
		((PnlFmncArtList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTLISTDO) {
		req->dpchapp = new PnlFmncArtList::DpchAppDo();
		((PnlFmncArtList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTMNORGDATA) {
		req->dpchapp = new PnlFmncArtMNOrg::DpchAppData();
		((PnlFmncArtMNOrg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTMNORGDO) {
		req->dpchapp = new PnlFmncArtMNOrg::DpchAppDo();
		((PnlFmncArtMNOrg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTRECDO) {
		req->dpchapp = new PnlFmncArtRec::DpchAppDo();
		((PnlFmncArtRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTREF1NFILEDATA) {
		req->dpchapp = new PnlFmncArtRef1NFile::DpchAppData();
		((PnlFmncArtRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTREF1NFILEDO) {
		req->dpchapp = new PnlFmncArtRef1NFile::DpchAppDo();
		((PnlFmncArtRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILAPOSDATA) {
		req->dpchapp = new PnlFmncBilAPos::DpchAppData();
		((PnlFmncBilAPos::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILAPOSDO) {
		req->dpchapp = new PnlFmncBilAPos::DpchAppDo();
		((PnlFmncBilAPos::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILDETAILDATA) {
		req->dpchapp = new PnlFmncBilDetail::DpchAppData();
		((PnlFmncBilDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILDETAILDO) {
		req->dpchapp = new PnlFmncBilDetail::DpchAppDo();
		((PnlFmncBilDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILDO) {
		req->dpchapp = new CrdFmncBil::DpchAppDo();
		((CrdFmncBil::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILLISTDATA) {
		req->dpchapp = new PnlFmncBilList::DpchAppData();
		((PnlFmncBilList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILLISTDO) {
		req->dpchapp = new PnlFmncBilList::DpchAppDo();
		((PnlFmncBilList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILRECDO) {
		req->dpchapp = new PnlFmncBilRec::DpchAppDo();
		((PnlFmncBilRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFAB1NFABPROJECTDATA) {
		req->dpchapp = new PnlFmncFab1NFabproject::DpchAppData();
		((PnlFmncFab1NFabproject::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFAB1NFABPROJECTDO) {
		req->dpchapp = new PnlFmncFab1NFabproject::DpchAppDo();
		((PnlFmncFab1NFabproject::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFAB1NFABUSERDATA) {
		req->dpchapp = new PnlFmncFab1NFabuser::DpchAppData();
		((PnlFmncFab1NFabuser::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFAB1NFABUSERDO) {
		req->dpchapp = new PnlFmncFab1NFabuser::DpchAppDo();
		((PnlFmncFab1NFabuser::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABDETAILDO) {
		req->dpchapp = new PnlFmncFabDetail::DpchAppDo();
		((PnlFmncFabDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABDO) {
		req->dpchapp = new CrdFmncFab::DpchAppDo();
		((CrdFmncFab::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABFAB1NTOOLDATA) {
		req->dpchapp = new PnlFmncFabFab1NTool::DpchAppData();
		((PnlFmncFabFab1NTool::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABFAB1NTOOLDO) {
		req->dpchapp = new PnlFmncFabFab1NTool::DpchAppDo();
		((PnlFmncFabFab1NTool::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABLISTDATA) {
		req->dpchapp = new PnlFmncFabList::DpchAppData();
		((PnlFmncFabList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABLISTDO) {
		req->dpchapp = new PnlFmncFabList::DpchAppDo();
		((PnlFmncFabList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABMNRUNDATA) {
		req->dpchapp = new PnlFmncFabMNRun::DpchAppData();
		((PnlFmncFabMNRun::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABMNRUNDO) {
		req->dpchapp = new PnlFmncFabMNRun::DpchAppDo();
		((PnlFmncFabMNRun::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABRECDO) {
		req->dpchapp = new PnlFmncFabRec::DpchAppDo();
		((PnlFmncFabRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILDETAILDATA) {
		req->dpchapp = new PnlFmncFilDetail::DpchAppData();
		((PnlFmncFilDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILDETAILDO) {
		req->dpchapp = new PnlFmncFilDetail::DpchAppDo();
		((PnlFmncFilDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILDO) {
		req->dpchapp = new CrdFmncFil::DpchAppDo();
		((CrdFmncFil::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILLISTDATA) {
		req->dpchapp = new PnlFmncFilList::DpchAppData();
		((PnlFmncFilList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILLISTDO) {
		req->dpchapp = new PnlFmncFilList::DpchAppDo();
		((PnlFmncFilList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILMNSAMPLEDATA) {
		req->dpchapp = new PnlFmncFilMNSample::DpchAppData();
		((PnlFmncFilMNSample::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILMNSAMPLEDO) {
		req->dpchapp = new PnlFmncFilMNSample::DpchAppDo();
		((PnlFmncFilMNSample::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILMNSTEPDATA) {
		req->dpchapp = new PnlFmncFilMNStep::DpchAppData();
		((PnlFmncFilMNStep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILMNSTEPDO) {
		req->dpchapp = new PnlFmncFilMNStep::DpchAppDo();
		((PnlFmncFilMNStep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILRECDO) {
		req->dpchapp = new PnlFmncFilRec::DpchAppDo();
		((PnlFmncFilRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJ1NBILLDATA) {
		req->dpchapp = new PnlFmncFpj1NBill::DpchAppData();
		((PnlFmncFpj1NBill::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJ1NBILLDO) {
		req->dpchapp = new PnlFmncFpj1NBill::DpchAppDo();
		((PnlFmncFpj1NBill::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJDETAILDATA) {
		req->dpchapp = new PnlFmncFpjDetail::DpchAppData();
		((PnlFmncFpjDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJDETAILDO) {
		req->dpchapp = new PnlFmncFpjDetail::DpchAppDo();
		((PnlFmncFpjDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJDO) {
		req->dpchapp = new CrdFmncFpj::DpchAppDo();
		((CrdFmncFpj::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJLISTDATA) {
		req->dpchapp = new PnlFmncFpjList::DpchAppData();
		((PnlFmncFpjList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJLISTDO) {
		req->dpchapp = new PnlFmncFpjList::DpchAppDo();
		((PnlFmncFpjList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJMNFABUSERDATA) {
		req->dpchapp = new PnlFmncFpjMNFabuser::DpchAppData();
		((PnlFmncFpjMNFabuser::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJMNFABUSERDO) {
		req->dpchapp = new PnlFmncFpjMNFabuser::DpchAppDo();
		((PnlFmncFpjMNFabuser::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJRECDO) {
		req->dpchapp = new PnlFmncFpjRec::DpchAppDo();
		((PnlFmncFpjRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSDETAILDATA) {
		req->dpchapp = new PnlFmncFusDetail::DpchAppData();
		((PnlFmncFusDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSDETAILDO) {
		req->dpchapp = new PnlFmncFusDetail::DpchAppDo();
		((PnlFmncFusDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSDO) {
		req->dpchapp = new CrdFmncFus::DpchAppDo();
		((CrdFmncFus::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSLISTDATA) {
		req->dpchapp = new PnlFmncFusList::DpchAppData();
		((PnlFmncFusList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSLISTDO) {
		req->dpchapp = new PnlFmncFusList::DpchAppDo();
		((PnlFmncFusList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSMNFABPROJECTDATA) {
		req->dpchapp = new PnlFmncFusMNFabproject::DpchAppData();
		((PnlFmncFusMNFabproject::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSMNFABPROJECTDO) {
		req->dpchapp = new PnlFmncFusMNFabproject::DpchAppDo();
		((PnlFmncFusMNFabproject::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSMNTOOLDATA) {
		req->dpchapp = new PnlFmncFusMNTool::DpchAppData();
		((PnlFmncFusMNTool::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSMNTOOLDO) {
		req->dpchapp = new PnlFmncFusMNTool::DpchAppDo();
		((PnlFmncFusMNTool::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSRECDO) {
		req->dpchapp = new PnlFmncFusRec::DpchAppDo();
		((PnlFmncFusRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCINIT) {
		req->dpchapp = new DpchAppFmncInit();
		((DpchAppFmncInit*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVADMINDATA) {
		req->dpchapp = new PnlFmncNavAdmin::DpchAppData();
		((PnlFmncNavAdmin::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVADMINDO) {
		req->dpchapp = new PnlFmncNavAdmin::DpchAppDo();
		((PnlFmncNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVDO) {
		req->dpchapp = new CrdFmncNav::DpchAppDo();
		((CrdFmncNav::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDATA) {
		req->dpchapp = new PnlFmncNavFabmgmt::DpchAppData();
		((PnlFmncNavFabmgmt::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDO) {
		req->dpchapp = new PnlFmncNavFabmgmt::DpchAppDo();
		((PnlFmncNavFabmgmt::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDATA) {
		req->dpchapp = new PnlFmncNavLabbook::DpchAppData();
		((PnlFmncNavLabbook::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDO) {
		req->dpchapp = new PnlFmncNavLabbook::DpchAppDo();
		((PnlFmncNavLabbook::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVPREDO) {
		req->dpchapp = new PnlFmncNavPre::DpchAppDo();
		((PnlFmncNavPre::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDATA) {
		req->dpchapp = new PnlFmncNavSupply::DpchAppData();
		((PnlFmncNavSupply::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDO) {
		req->dpchapp = new PnlFmncNavSupply::DpchAppDo();
		((PnlFmncNavSupply::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORG1NARTICLEDATA) {
		req->dpchapp = new PnlFmncOrg1NArticle::DpchAppData();
		((PnlFmncOrg1NArticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORG1NARTICLEDO) {
		req->dpchapp = new PnlFmncOrg1NArticle::DpchAppDo();
		((PnlFmncOrg1NArticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORG1NSTOCKITEMDATA) {
		req->dpchapp = new PnlFmncOrg1NStockitem::DpchAppData();
		((PnlFmncOrg1NStockitem::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORG1NSTOCKITEMDO) {
		req->dpchapp = new PnlFmncOrg1NStockitem::DpchAppDo();
		((PnlFmncOrg1NStockitem::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGADETAILDATA) {
		req->dpchapp = new PnlFmncOrgADetail::DpchAppData();
		((PnlFmncOrgADetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGADETAILDO) {
		req->dpchapp = new PnlFmncOrgADetail::DpchAppDo();
		((PnlFmncOrgADetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGBIO1NFABPROJECTDATA) {
		req->dpchapp = new PnlFmncOrgBio1NFabproject::DpchAppData();
		((PnlFmncOrgBio1NFabproject::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGBIO1NFABPROJECTDO) {
		req->dpchapp = new PnlFmncOrgBio1NFabproject::DpchAppDo();
		((PnlFmncOrgBio1NFabproject::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGDETAILDATA) {
		req->dpchapp = new PnlFmncOrgDetail::DpchAppData();
		((PnlFmncOrgDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGDETAILDO) {
		req->dpchapp = new PnlFmncOrgDetail::DpchAppDo();
		((PnlFmncOrgDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGDO) {
		req->dpchapp = new CrdFmncOrg::DpchAppDo();
		((CrdFmncOrg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGHK1NADDRESSDATA) {
		req->dpchapp = new PnlFmncOrgHk1NAddress::DpchAppData();
		((PnlFmncOrgHk1NAddress::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGHK1NADDRESSDO) {
		req->dpchapp = new PnlFmncOrgHk1NAddress::DpchAppDo();
		((PnlFmncOrgHk1NAddress::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGKSTOCKLCNDATA) {
		req->dpchapp = new PnlFmncOrgKStocklcn::DpchAppData();
		((PnlFmncOrgKStocklcn::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGKSTOCKLCNDO) {
		req->dpchapp = new PnlFmncOrgKStocklcn::DpchAppDo();
		((PnlFmncOrgKStocklcn::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGLISTDATA) {
		req->dpchapp = new PnlFmncOrgList::DpchAppData();
		((PnlFmncOrgList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGLISTDO) {
		req->dpchapp = new PnlFmncOrgList::DpchAppDo();
		((PnlFmncOrgList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNARTICLEDATA) {
		req->dpchapp = new PnlFmncOrgMNArticle::DpchAppData();
		((PnlFmncOrgMNArticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNARTICLEDO) {
		req->dpchapp = new PnlFmncOrgMNArticle::DpchAppDo();
		((PnlFmncOrgMNArticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNF1NTOOLDATA) {
		req->dpchapp = new PnlFmncOrgMnf1NTool::DpchAppData();
		((PnlFmncOrgMnf1NTool::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNF1NTOOLDO) {
		req->dpchapp = new PnlFmncOrgMnf1NTool::DpchAppDo();
		((PnlFmncOrgMnf1NTool::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNPERSONDATA) {
		req->dpchapp = new PnlFmncOrgMNPerson::DpchAppData();
		((PnlFmncOrgMNPerson::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNPERSONDO) {
		req->dpchapp = new PnlFmncOrgMNPerson::DpchAppDo();
		((PnlFmncOrgMNPerson::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGPCO1NPURCHORDERDATA) {
		req->dpchapp = new PnlFmncOrgPco1NPurchorder::DpchAppData();
		((PnlFmncOrgPco1NPurchorder::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGPCO1NPURCHORDERDO) {
		req->dpchapp = new PnlFmncOrgPco1NPurchorder::DpchAppDo();
		((PnlFmncOrgPco1NPurchorder::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGRECDO) {
		req->dpchapp = new PnlFmncOrgRec::DpchAppDo();
		((PnlFmncOrgRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGSPL1NPURCHORDERDATA) {
		req->dpchapp = new PnlFmncOrgSpl1NPurchorder::DpchAppData();
		((PnlFmncOrgSpl1NPurchorder::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGSPL1NPURCHORDERDO) {
		req->dpchapp = new PnlFmncOrgSpl1NPurchorder::DpchAppDo();
		((PnlFmncOrgSpl1NPurchorder::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGSUP1NORGDATA) {
		req->dpchapp = new PnlFmncOrgSup1NOrg::DpchAppData();
		((PnlFmncOrgSup1NOrg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGSUP1NORGDO) {
		req->dpchapp = new PnlFmncOrgSup1NOrg::DpchAppDo();
		((PnlFmncOrgSup1NOrg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGSVCMNTOOLDATA) {
		req->dpchapp = new PnlFmncOrgSvcMNTool::DpchAppData();
		((PnlFmncOrgSvcMNTool::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGSVCMNTOOLDO) {
		req->dpchapp = new PnlFmncOrgSvcMNTool::DpchAppDo();
		((PnlFmncOrgSvcMNTool::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCOAPOSDATA) {
		req->dpchapp = new PnlFmncPcoAPos::DpchAppData();
		((PnlFmncPcoAPos::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCOAPOSDO) {
		req->dpchapp = new PnlFmncPcoAPos::DpchAppDo();
		((PnlFmncPcoAPos::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCODETAILDATA) {
		req->dpchapp = new PnlFmncPcoDetail::DpchAppData();
		((PnlFmncPcoDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCODETAILDO) {
		req->dpchapp = new PnlFmncPcoDetail::DpchAppDo();
		((PnlFmncPcoDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCODO) {
		req->dpchapp = new CrdFmncPco::DpchAppDo();
		((CrdFmncPco::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCOLISTDATA) {
		req->dpchapp = new PnlFmncPcoList::DpchAppData();
		((PnlFmncPcoList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCOLISTDO) {
		req->dpchapp = new PnlFmncPcoList::DpchAppDo();
		((PnlFmncPcoList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCORECDO) {
		req->dpchapp = new PnlFmncPcoRec::DpchAppDo();
		((PnlFmncPcoRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJ1NRUNDATA) {
		req->dpchapp = new PnlFmncPrj1NRun::DpchAppData();
		((PnlFmncPrj1NRun::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJ1NRUNDO) {
		req->dpchapp = new PnlFmncPrj1NRun::DpchAppDo();
		((PnlFmncPrj1NRun::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJDETAILDATA) {
		req->dpchapp = new PnlFmncPrjDetail::DpchAppData();
		((PnlFmncPrjDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJDETAILDO) {
		req->dpchapp = new PnlFmncPrjDetail::DpchAppDo();
		((PnlFmncPrjDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJDO) {
		req->dpchapp = new CrdFmncPrj::DpchAppDo();
		((CrdFmncPrj::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJLISTDATA) {
		req->dpchapp = new PnlFmncPrjList::DpchAppData();
		((PnlFmncPrjList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJLISTDO) {
		req->dpchapp = new PnlFmncPrjList::DpchAppDo();
		((PnlFmncPrjList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRJRECDO) {
		req->dpchapp = new PnlFmncPrjRec::DpchAppDo();
		((PnlFmncPrjRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSADETAILDATA) {
		req->dpchapp = new PnlFmncPrsADetail::DpchAppData();
		((PnlFmncPrsADetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSADETAILDO) {
		req->dpchapp = new PnlFmncPrsADetail::DpchAppDo();
		((PnlFmncPrsADetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSDETAILDATA) {
		req->dpchapp = new PnlFmncPrsDetail::DpchAppData();
		((PnlFmncPrsDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSDETAILDO) {
		req->dpchapp = new PnlFmncPrsDetail::DpchAppDo();
		((PnlFmncPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSDO) {
		req->dpchapp = new CrdFmncPrs::DpchAppDo();
		((CrdFmncPrs::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSHK1NADDRESSDATA) {
		req->dpchapp = new PnlFmncPrsHk1NAddress::DpchAppData();
		((PnlFmncPrsHk1NAddress::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSHK1NADDRESSDO) {
		req->dpchapp = new PnlFmncPrsHk1NAddress::DpchAppDo();
		((PnlFmncPrsHk1NAddress::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSLISTDATA) {
		req->dpchapp = new PnlFmncPrsList::DpchAppData();
		((PnlFmncPrsList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSLISTDO) {
		req->dpchapp = new PnlFmncPrsList::DpchAppDo();
		((PnlFmncPrsList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSMNORGDATA) {
		req->dpchapp = new PnlFmncPrsMNOrg::DpchAppData();
		((PnlFmncPrsMNOrg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSMNORGDO) {
		req->dpchapp = new PnlFmncPrsMNOrg::DpchAppDo();
		((PnlFmncPrsMNOrg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSMNRUNDATA) {
		req->dpchapp = new PnlFmncPrsMNRun::DpchAppData();
		((PnlFmncPrsMNRun::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSMNRUNDO) {
		req->dpchapp = new PnlFmncPrsMNRun::DpchAppDo();
		((PnlFmncPrsMNRun::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSRECDO) {
		req->dpchapp = new PnlFmncPrsRec::DpchAppDo();
		((PnlFmncPrsRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRESUME) {
		req->dpchapp = new DpchAppFmncResume();
		((DpchAppFmncResume*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNDETAILDATA) {
		req->dpchapp = new PnlFmncRunDetail::DpchAppData();
		((PnlFmncRunDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNDETAILDO) {
		req->dpchapp = new PnlFmncRunDetail::DpchAppDo();
		((PnlFmncRunDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNDO) {
		req->dpchapp = new CrdFmncRun::DpchAppDo();
		((CrdFmncRun::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNLISTDATA) {
		req->dpchapp = new PnlFmncRunList::DpchAppData();
		((PnlFmncRunList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNLISTDO) {
		req->dpchapp = new PnlFmncRunList::DpchAppDo();
		((PnlFmncRunList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNMNFABDATA) {
		req->dpchapp = new PnlFmncRunMNFab::DpchAppData();
		((PnlFmncRunMNFab::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNMNFABDO) {
		req->dpchapp = new PnlFmncRunMNFab::DpchAppDo();
		((PnlFmncRunMNFab::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNMNPERSONDATA) {
		req->dpchapp = new PnlFmncRunMNPerson::DpchAppData();
		((PnlFmncRunMNPerson::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNMNPERSONDO) {
		req->dpchapp = new PnlFmncRunMNPerson::DpchAppDo();
		((PnlFmncRunMNPerson::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNMNSAMPLEDATA) {
		req->dpchapp = new PnlFmncRunMNSample::DpchAppData();
		((PnlFmncRunMNSample::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNMNSAMPLEDO) {
		req->dpchapp = new PnlFmncRunMNSample::DpchAppDo();
		((PnlFmncRunMNSample::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNRECDO) {
		req->dpchapp = new PnlFmncRunRec::DpchAppDo();
		((PnlFmncRunRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNREF1NFILEDATA) {
		req->dpchapp = new PnlFmncRunRef1NFile::DpchAppData();
		((PnlFmncRunRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNREF1NFILEDO) {
		req->dpchapp = new PnlFmncRunRef1NFile::DpchAppDo();
		((PnlFmncRunRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNRUN1NACTIVITYDATA) {
		req->dpchapp = new PnlFmncRunRun1NActivity::DpchAppData();
		((PnlFmncRunRun1NActivity::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNRUN1NACTIVITYDO) {
		req->dpchapp = new PnlFmncRunRun1NActivity::DpchAppDo();
		((PnlFmncRunRun1NActivity::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPAPARDATA) {
		req->dpchapp = new PnlFmncSepAPar::DpchAppData();
		((PnlFmncSepAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPAPARDO) {
		req->dpchapp = new PnlFmncSepAPar::DpchAppDo();
		((PnlFmncSepAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPDETAILDATA) {
		req->dpchapp = new PnlFmncSepDetail::DpchAppData();
		((PnlFmncSepDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPDETAILDO) {
		req->dpchapp = new PnlFmncSepDetail::DpchAppDo();
		((PnlFmncSepDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPDO) {
		req->dpchapp = new CrdFmncSep::DpchAppDo();
		((CrdFmncSep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPLISTDATA) {
		req->dpchapp = new PnlFmncSepList::DpchAppData();
		((PnlFmncSepList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPLISTDO) {
		req->dpchapp = new PnlFmncSepList::DpchAppDo();
		((PnlFmncSepList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPMNFILEDATA) {
		req->dpchapp = new PnlFmncSepMNFile::DpchAppData();
		((PnlFmncSepMNFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPMNFILEDO) {
		req->dpchapp = new PnlFmncSepMNFile::DpchAppDo();
		((PnlFmncSepMNFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPMNSAMPLEDATA) {
		req->dpchapp = new PnlFmncSepMNSample::DpchAppData();
		((PnlFmncSepMNSample::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPMNSAMPLEDO) {
		req->dpchapp = new PnlFmncSepMNSample::DpchAppDo();
		((PnlFmncSepMNSample::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPRECDO) {
		req->dpchapp = new PnlFmncSepRec::DpchAppDo();
		((PnlFmncSepRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPREF1NFILEDATA) {
		req->dpchapp = new PnlFmncSepRef1NFile::DpchAppData();
		((PnlFmncSepRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSEPREF1NFILEDO) {
		req->dpchapp = new PnlFmncSepRef1NFile::DpchAppDo();
		((PnlFmncSepRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKIDETAILDATA) {
		req->dpchapp = new PnlFmncSkiDetail::DpchAppData();
		((PnlFmncSkiDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKIDETAILDO) {
		req->dpchapp = new PnlFmncSkiDetail::DpchAppDo();
		((PnlFmncSkiDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKIDO) {
		req->dpchapp = new CrdFmncSki::DpchAppDo();
		((CrdFmncSki::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKILISTDATA) {
		req->dpchapp = new PnlFmncSkiList::DpchAppData();
		((PnlFmncSkiList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKILISTDO) {
		req->dpchapp = new PnlFmncSkiList::DpchAppDo();
		((PnlFmncSkiList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKIRECDO) {
		req->dpchapp = new PnlFmncSkiRec::DpchAppDo();
		((PnlFmncSkiRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPAPARDATA) {
		req->dpchapp = new PnlFmncSmpAPar::DpchAppData();
		((PnlFmncSmpAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPAPARDO) {
		req->dpchapp = new PnlFmncSmpAPar::DpchAppDo();
		((PnlFmncSmpAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPDETAILDATA) {
		req->dpchapp = new PnlFmncSmpDetail::DpchAppData();
		((PnlFmncSmpDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPDETAILDO) {
		req->dpchapp = new PnlFmncSmpDetail::DpchAppDo();
		((PnlFmncSmpDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPDO) {
		req->dpchapp = new CrdFmncSmp::DpchAppDo();
		((CrdFmncSmp::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPLISTDATA) {
		req->dpchapp = new PnlFmncSmpList::DpchAppData();
		((PnlFmncSmpList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPLISTDO) {
		req->dpchapp = new PnlFmncSmpList::DpchAppDo();
		((PnlFmncSmpList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPMNFILEDATA) {
		req->dpchapp = new PnlFmncSmpMNFile::DpchAppData();
		((PnlFmncSmpMNFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPMNFILEDO) {
		req->dpchapp = new PnlFmncSmpMNFile::DpchAppDo();
		((PnlFmncSmpMNFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPMNRUNDATA) {
		req->dpchapp = new PnlFmncSmpMNRun::DpchAppData();
		((PnlFmncSmpMNRun::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPMNRUNDO) {
		req->dpchapp = new PnlFmncSmpMNRun::DpchAppDo();
		((PnlFmncSmpMNRun::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPMNSTEPDATA) {
		req->dpchapp = new PnlFmncSmpMNStep::DpchAppData();
		((PnlFmncSmpMNStep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPMNSTEPDO) {
		req->dpchapp = new PnlFmncSmpMNStep::DpchAppDo();
		((PnlFmncSmpMNStep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPRECDO) {
		req->dpchapp = new PnlFmncSmpRec::DpchAppDo();
		((PnlFmncSmpRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPREF1NFILEDATA) {
		req->dpchapp = new PnlFmncSmpRef1NFile::DpchAppData();
		((PnlFmncSmpRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPREF1NFILEDO) {
		req->dpchapp = new PnlFmncSmpRef1NFile::DpchAppDo();
		((PnlFmncSmpRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPSUP1NSAMPLEDATA) {
		req->dpchapp = new PnlFmncSmpSup1NSample::DpchAppData();
		((PnlFmncSmpSup1NSample::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPSUP1NSAMPLEDO) {
		req->dpchapp = new PnlFmncSmpSup1NSample::DpchAppDo();
		((PnlFmncSmpSup1NSample::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPAPARDATA) {
		req->dpchapp = new PnlFmncStpAPar::DpchAppData();
		((PnlFmncStpAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPAPARDO) {
		req->dpchapp = new PnlFmncStpAPar::DpchAppDo();
		((PnlFmncStpAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPDETAILDATA) {
		req->dpchapp = new PnlFmncStpDetail::DpchAppData();
		((PnlFmncStpDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPDETAILDO) {
		req->dpchapp = new PnlFmncStpDetail::DpchAppDo();
		((PnlFmncStpDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPDO) {
		req->dpchapp = new CrdFmncStp::DpchAppDo();
		((CrdFmncStp::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPKSTEPPARDATA) {
		req->dpchapp = new PnlFmncStpKSteppar::DpchAppData();
		((PnlFmncStpKSteppar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPKSTEPPARDO) {
		req->dpchapp = new PnlFmncStpKSteppar::DpchAppDo();
		((PnlFmncStpKSteppar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPLISTDATA) {
		req->dpchapp = new PnlFmncStpList::DpchAppData();
		((PnlFmncStpList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPLISTDO) {
		req->dpchapp = new PnlFmncStpList::DpchAppDo();
		((PnlFmncStpList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPMNFILEDATA) {
		req->dpchapp = new PnlFmncStpMNFile::DpchAppData();
		((PnlFmncStpMNFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPMNFILEDO) {
		req->dpchapp = new PnlFmncStpMNFile::DpchAppDo();
		((PnlFmncStpMNFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPRECDO) {
		req->dpchapp = new PnlFmncStpRec::DpchAppDo();
		((PnlFmncStpRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPREF1NFILEDATA) {
		req->dpchapp = new PnlFmncStpRef1NFile::DpchAppData();
		((PnlFmncStpRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPREF1NFILEDO) {
		req->dpchapp = new PnlFmncStpRef1NFile::DpchAppDo();
		((PnlFmncStpRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPTPL1NSTEPDATA) {
		req->dpchapp = new PnlFmncStpTpl1NStep::DpchAppData();
		((PnlFmncStpTpl1NStep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPTPL1NSTEPDO) {
		req->dpchapp = new PnlFmncStpTpl1NStep::DpchAppDo();
		((PnlFmncStpTpl1NStep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOL1NARTICLEDATA) {
		req->dpchapp = new PnlFmncTol1NArticle::DpchAppData();
		((PnlFmncTol1NArticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOL1NARTICLEDO) {
		req->dpchapp = new PnlFmncTol1NArticle::DpchAppDo();
		((PnlFmncTol1NArticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLAAVLDATA) {
		req->dpchapp = new PnlFmncTolAAvl::DpchAppData();
		((PnlFmncTolAAvl::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLAAVLDO) {
		req->dpchapp = new PnlFmncTolAAvl::DpchAppDo();
		((PnlFmncTolAAvl::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLACHARDATA) {
		req->dpchapp = new PnlFmncTolAChar::DpchAppData();
		((PnlFmncTolAChar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLACHARDO) {
		req->dpchapp = new PnlFmncTolAChar::DpchAppDo();
		((PnlFmncTolAChar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLARESDATA) {
		req->dpchapp = new PnlFmncTolARes::DpchAppData();
		((PnlFmncTolARes::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLARESDO) {
		req->dpchapp = new PnlFmncTolARes::DpchAppDo();
		((PnlFmncTolARes::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLAUTILDATA) {
		req->dpchapp = new PnlFmncTolAUtil::DpchAppData();
		((PnlFmncTolAUtil::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLAUTILDO) {
		req->dpchapp = new PnlFmncTolAUtil::DpchAppDo();
		((PnlFmncTolAUtil::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLDETAILDATA) {
		req->dpchapp = new PnlFmncTolDetail::DpchAppData();
		((PnlFmncTolDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLDETAILDO) {
		req->dpchapp = new PnlFmncTolDetail::DpchAppDo();
		((PnlFmncTolDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLDO) {
		req->dpchapp = new CrdFmncTol::DpchAppDo();
		((CrdFmncTol::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLKSTEPPARDATA) {
		req->dpchapp = new PnlFmncTolKSteppar::DpchAppData();
		((PnlFmncTolKSteppar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLKSTEPPARDO) {
		req->dpchapp = new PnlFmncTolKSteppar::DpchAppDo();
		((PnlFmncTolKSteppar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLKTOOLCHARDATA) {
		req->dpchapp = new PnlFmncTolKToolchar::DpchAppData();
		((PnlFmncTolKToolchar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLKTOOLCHARDO) {
		req->dpchapp = new PnlFmncTolKToolchar::DpchAppDo();
		((PnlFmncTolKToolchar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLLISTDATA) {
		req->dpchapp = new PnlFmncTolList::DpchAppData();
		((PnlFmncTolList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLLISTDO) {
		req->dpchapp = new PnlFmncTolList::DpchAppDo();
		((PnlFmncTolList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLMNFABUSERDATA) {
		req->dpchapp = new PnlFmncTolMNFabuser::DpchAppData();
		((PnlFmncTolMNFabuser::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLMNFABUSERDO) {
		req->dpchapp = new PnlFmncTolMNFabuser::DpchAppDo();
		((PnlFmncTolMNFabuser::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLMNTOOLTYPEDATA) {
		req->dpchapp = new PnlFmncTolMNTooltype::DpchAppData();
		((PnlFmncTolMNTooltype::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLMNTOOLTYPEDO) {
		req->dpchapp = new PnlFmncTolMNTooltype::DpchAppDo();
		((PnlFmncTolMNTooltype::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLRECDO) {
		req->dpchapp = new PnlFmncTolRec::DpchAppDo();
		((PnlFmncTolRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLREF1NFILEDATA) {
		req->dpchapp = new PnlFmncTolRef1NFile::DpchAppData();
		((PnlFmncTolRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLREF1NFILEDO) {
		req->dpchapp = new PnlFmncTolRef1NFile::DpchAppDo();
		((PnlFmncTolRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLRLV1NSTEPDATA) {
		req->dpchapp = new PnlFmncTolRlv1NStep::DpchAppData();
		((PnlFmncTolRlv1NStep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLRLV1NSTEPDO) {
		req->dpchapp = new PnlFmncTolRlv1NStep::DpchAppDo();
		((PnlFmncTolRlv1NStep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLSVCMNORGDATA) {
		req->dpchapp = new PnlFmncTolSvcMNOrg::DpchAppData();
		((PnlFmncTolSvcMNOrg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLSVCMNORGDO) {
		req->dpchapp = new PnlFmncTolSvcMNOrg::DpchAppDo();
		((PnlFmncTolSvcMNOrg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYDETAILDATA) {
		req->dpchapp = new PnlFmncTtyDetail::DpchAppData();
		((PnlFmncTtyDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYDETAILDO) {
		req->dpchapp = new PnlFmncTtyDetail::DpchAppDo();
		((PnlFmncTtyDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYDO) {
		req->dpchapp = new CrdFmncTty::DpchAppDo();
		((CrdFmncTty::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYKSTEPPARDATA) {
		req->dpchapp = new PnlFmncTtyKSteppar::DpchAppData();
		((PnlFmncTtyKSteppar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYKSTEPPARDO) {
		req->dpchapp = new PnlFmncTtyKSteppar::DpchAppDo();
		((PnlFmncTtyKSteppar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYKTOOLCHARDATA) {
		req->dpchapp = new PnlFmncTtyKToolchar::DpchAppData();
		((PnlFmncTtyKToolchar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYKTOOLCHARDO) {
		req->dpchapp = new PnlFmncTtyKToolchar::DpchAppDo();
		((PnlFmncTtyKToolchar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYLISTDATA) {
		req->dpchapp = new PnlFmncTtyList::DpchAppData();
		((PnlFmncTtyList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYLISTDO) {
		req->dpchapp = new PnlFmncTtyList::DpchAppDo();
		((PnlFmncTtyList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYMNTOOLDATA) {
		req->dpchapp = new PnlFmncTtyMNTool::DpchAppData();
		((PnlFmncTtyMNTool::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYMNTOOLDO) {
		req->dpchapp = new PnlFmncTtyMNTool::DpchAppDo();
		((PnlFmncTtyMNTool::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYRECDO) {
		req->dpchapp = new PnlFmncTtyRec::DpchAppDo();
		((PnlFmncTtyRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYRLV1NSTEPDATA) {
		req->dpchapp = new PnlFmncTtyRlv1NStep::DpchAppData();
		((PnlFmncTtyRlv1NStep::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYRLV1NSTEPDO) {
		req->dpchapp = new PnlFmncTtyRlv1NStep::DpchAppDo();
		((PnlFmncTtyRlv1NStep::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYSUP1NTOOLTYPEDATA) {
		req->dpchapp = new PnlFmncTtySup1NTooltype::DpchAppData();
		((PnlFmncTtySup1NTooltype::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYSUP1NTOOLTYPEDO) {
		req->dpchapp = new PnlFmncTtySup1NTooltype::DpchAppDo();
		((PnlFmncTtySup1NTooltype::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGAACCESSDATA) {
		req->dpchapp = new PnlFmncUsgAAccess::DpchAppData();
		((PnlFmncUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGAACCESSDO) {
		req->dpchapp = new PnlFmncUsgAAccess::DpchAppDo();
		((PnlFmncUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGDETAILDATA) {
		req->dpchapp = new PnlFmncUsgDetail::DpchAppData();
		((PnlFmncUsgDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGDETAILDO) {
		req->dpchapp = new PnlFmncUsgDetail::DpchAppDo();
		((PnlFmncUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGDO) {
		req->dpchapp = new CrdFmncUsg::DpchAppDo();
		((CrdFmncUsg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGLISTDATA) {
		req->dpchapp = new PnlFmncUsgList::DpchAppData();
		((PnlFmncUsgList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGLISTDO) {
		req->dpchapp = new PnlFmncUsgList::DpchAppDo();
		((PnlFmncUsgList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGMNUSERDATA) {
		req->dpchapp = new PnlFmncUsgMNUser::DpchAppData();
		((PnlFmncUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGMNUSERDO) {
		req->dpchapp = new PnlFmncUsgMNUser::DpchAppDo();
		((PnlFmncUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSGRECDO) {
		req->dpchapp = new PnlFmncUsgRec::DpchAppDo();
		((PnlFmncUsgRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSR1NSESSIONDATA) {
		req->dpchapp = new PnlFmncUsr1NSession::DpchAppData();
		((PnlFmncUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSR1NSESSIONDO) {
		req->dpchapp = new PnlFmncUsr1NSession::DpchAppDo();
		((PnlFmncUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRAACCESSDATA) {
		req->dpchapp = new PnlFmncUsrAAccess::DpchAppData();
		((PnlFmncUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRAACCESSDO) {
		req->dpchapp = new PnlFmncUsrAAccess::DpchAppDo();
		((PnlFmncUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRDETAILDATA) {
		req->dpchapp = new PnlFmncUsrDetail::DpchAppData();
		((PnlFmncUsrDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRDETAILDO) {
		req->dpchapp = new PnlFmncUsrDetail::DpchAppDo();
		((PnlFmncUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRDO) {
		req->dpchapp = new CrdFmncUsr::DpchAppDo();
		((CrdFmncUsr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRLISTDATA) {
		req->dpchapp = new PnlFmncUsrList::DpchAppData();
		((PnlFmncUsrList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRLISTDO) {
		req->dpchapp = new PnlFmncUsrList::DpchAppDo();
		((PnlFmncUsrList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRMNUSERGROUPDATA) {
		req->dpchapp = new PnlFmncUsrMNUsergroup::DpchAppData();
		((PnlFmncUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRMNUSERGROUPDO) {
		req->dpchapp = new PnlFmncUsrMNUsergroup::DpchAppDo();
		((PnlFmncUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRRECDO) {
		req->dpchapp = new PnlFmncUsrRec::DpchAppDo();
		((PnlFmncUsrRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHAPPROOTFMNCLOGIN) {
		req->dpchapp = new RootFmnc::DpchAppLogin();
		((RootFmnc::DpchAppLogin*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixFmncVDpch;
};

void FmnccmbdAppsrv::writeDpchEng(
			XchgFmnccmbd* xchg
			, ReqFmnc* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);

	if (req->dpcheng) {
		req->dpcheng->writeXML(req->ixFmncVLocale, &(xchg->mScr), xchg->scr, xchg->descr, wr);
	} else {
		DpchEngFmncConfirm dpchconfirm(false, req->jref, "");
		dpchconfirm.writeXML(req->ixFmncVLocale, &(xchg->mScr), xchg->scr, xchg->descr, wr);
	};

	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};


