/**
  * \file Fmnccmbd_exe.cpp
  * Fmnc combined daemon main (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "Fmnccmbd.h"

#include "Fmnccmbd_exe.h"

/******************************************************************************
 class PrefFmnccmbd
 ******************************************************************************/

PrefFmnccmbd::PrefFmnccmbd(
			StgFmnccmbd* stgfmnccmbd
			, StgFmncDatabase* stgfmncdatabase
			, StgFmncMonitor* stgfmncmonitor
			, StgFmncPath* stgfmncpath
			, const set<uint>& mask
		) : Block() {
	if (stgfmnccmbd) this->stgfmnccmbd = *stgfmnccmbd;
	if (stgfmncdatabase) this->stgfmncdatabase = *stgfmncdatabase;
	if (stgfmncmonitor) this->stgfmncmonitor = *stgfmncmonitor;
	if (stgfmncpath) this->stgfmncpath = *stgfmncpath;

	if (find(mask, ALL)) this->mask = {STGFMNCCMBD, STGFMNCDATABASE, STGFMNCMONITOR, STGFMNCPATH};
	else this->mask = mask;
};

bool PrefFmnccmbd::all(
			const set<uint>& items
		) {
	if (!find(items, STGFMNCCMBD)) return false;
	if (!find(items, STGFMNCDATABASE)) return false;
	if (!find(items, STGFMNCMONITOR)) return false;
	if (!find(items, STGFMNCPATH)) return false;

	return true;
};

void PrefFmnccmbd::readXMLFromFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/", true);

	closeParsed(doc, docctx);
};

void PrefFmnccmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PrefFmnccmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (stgfmnccmbd.readXML(docctx, basexpath, true)) add(STGFMNCCMBD);
		if (stgfmncdatabase.readXML(docctx, basexpath, true)) add(STGFMNCDATABASE);
		if (stgfmncmonitor.readXML(docctx, basexpath, true)) add(STGFMNCMONITOR);
		if (stgfmncpath.readXML(docctx, basexpath, true)) add(STGFMNCPATH);
	} else {
		stgfmnccmbd = StgFmnccmbd();
		stgfmncdatabase = StgFmncDatabase();
		stgfmncmonitor = StgFmncMonitor();
		stgfmncpath = StgFmncPath();
	};
};

void PrefFmnccmbd::writeXMLToFile(
			const string& fullpath
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr);
	closewriteFile(wr);
};

void PrefFmnccmbd::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "PrefFmnccmbd");
		if (has(STGFMNCCMBD)) stgfmnccmbd.writeXML(wr);
		if (has(STGFMNCDATABASE)) stgfmncdatabase.writeXML(wr);
		if (has(STGFMNCMONITOR)) stgfmncmonitor.writeXML(wr);
		if (has(STGFMNCPATH)) stgfmncpath.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class Fmnccmbd
 ******************************************************************************/

Fmnccmbd::Fmnccmbd(
			const string& exedir
		) {
	this->exedir = exedir;

	jrefCmd = 0;

	xchg = NULL;
	
	root = NULL;

	appsrv = NULL;

	initdone = false;
	init();
};

Fmnccmbd::~Fmnccmbd() {
	term();
};

void Fmnccmbd::init() {
	pthread_attr_t attr;

	srand(time(NULL));

	// 1. create exchange object
	xchg = new XchgFmnccmbd();

	// 2. establish root job
	root = new RootFmnc(xchg);
	xchg->jrefRoot = root->jref;
	jrefCmd = xchg->jrefRoot;

	// 3. load preferences
	loadPref();

	// 4. initialize exchange data objects
	initXchgdataJobprc();
	initXchgdataOpprc();

	// 5. connect to database
	dbsfmnc.init(xchg->stgfmncdatabase.ixDbsVDbstype, "", xchg->stgfmncdatabase.dbsname, xchg->stgfmncdatabase.ip
			, xchg->stgfmncdatabase.port, xchg->stgfmncdatabase.username, xchg->stgfmncdatabase.password);

	// 6. clear query tables (within root job)
	root->clearQtb(&dbsfmnc);

	// 7. start job processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (unsigned int i=0;i<xchg->stgfmnccmbd.jobprcn;i++) {
		// thread
		jobprcs.push_back(0);
		pthread_create(&(jobprcs[i]), &attr, &FmnccmbdJobprc::run, (void*) xchg);
	};

	// 8. start op processor threads
	for (unsigned int i=0;i<xchg->stgfmnccmbd.opprcn;i++) {
		// thread
		opprcs.push_back(0);
		pthread_create(&(opprcs[i]), &attr, &FmnccmbdOpprc::run, (void*) xchg);
	};

	pthread_attr_destroy(&attr);

	// 9. start web server
	appsrv = FmnccmbdAppsrv::start(xchg);

	initdone = true;
};

void Fmnccmbd::term() {
	if (initdone) {
		// 1. stop web server
		FmnccmbdAppsrv::stop(appsrv);

		// 2. end op processor threads
		for (unsigned int i=0;i<opprcs.size();i++) {
			//if (opprcs[i]) {
				pthread_cancel(opprcs[i]);
				pthread_join(opprcs[i], NULL);
			//};
		};

		// 3. end job processor threads
		for (unsigned int i=0;i<jobprcs.size();i++) {
			//if (jobprcs[i]) {
				pthread_cancel(jobprcs[i]);
				pthread_join(jobprcs[i], NULL);
			//};
		};

		// 4. clean-up exchange data objects
		termXchgdataOpprc();
		termXchgdataJobprc();

		// 5. store preferences
		storePref();

		// 6. delete root job
		delete root;
		root = NULL;
		xchg->jrefRoot = 0;

		// 7. delete exchange object
		delete xchg;
	};
};

void Fmnccmbd::loadPref() {
	PrefFmnccmbd pref;

	pref.readXMLFromFile(exedir + "/PrefFmnccmbd.xml");

	xchg->stgfmnccmbd = pref.stgfmnccmbd;
	xchg->stgfmncdatabase = pref.stgfmncdatabase;
	xchg->stgfmncmonitor = pref.stgfmncmonitor;
	xchg->stgfmncpath = pref.stgfmncpath;

	xchg->acvpath = xchg->stgfmncpath.acvpath;
	xchg->tmppath = xchg->stgfmncpath.tmppath;
	xchg->helpurl = xchg->stgfmncpath.helpurl;
};

void Fmnccmbd::storePref() {
	PrefFmnccmbd pref(&(xchg->stgfmnccmbd), &(xchg->stgfmncdatabase), &(xchg->stgfmncmonitor), &(xchg->stgfmncpath));

	pref.writeXMLToFile(exedir + "/PrefFmnccmbd.xml");
};

void Fmnccmbd::initXchgdataJobprc() {
// IP initXchgdataJobprc --- INSERT
};

void Fmnccmbd::termXchgdataJobprc() {
// IP termXchgdataJobprc --- INSERT
};

void Fmnccmbd::initXchgdataOpprc() {
// IP initXchgdataOpprc --- INSERT
};

void Fmnccmbd::termXchgdataOpprc() {
// IP termXchgdataOpprc --- INSERT
};

/******************************************************************************
 main program
 ******************************************************************************/

void showSubjobs(
			XchgFmnccmbd* xchg
			, JobFmnc* job
			, bool clstns
			, bool ops
			, bool presets
			, bool dcolcont
			, bool stmgrcont
			, unsigned int indent
		) {
	string id;

	// http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	DcolFmnc* dcol = NULL;
	StmgrFmnc* stmgr = NULL;

	vector<uint> icsFmncVCall;
	vector<uint> icsVJobmask;

	vector<uint> icsFmncVPreset;
	vector<Arg> args;

	// indentation
	for (unsigned int i=0;i<indent;i++) id = id + "\t";

	// actual entry
	if (job->jrefsSub.empty()) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";
	cout << VecFmncVJob::getSref(job->ixFmncVJob);

	if (job->jrefMast == job->jref) cout << "/M";
	else if (job->jrefMast != 0) cout << "/S";

	cout << " (" << job->jref;

	dcol = xchg->getDcolByJref(job->jref, false);
	if (dcol) {
		cout << ", dcol";
		dcol->unlockAccess("", "showSubjobs");
	};

	stmgr = xchg->getStmgrByJref(job->jref);
	if (stmgr) {
		cout << ", stmgr";
		stmgr->unlockAccess("", "showSubjobs");
	};

	cout << ")" << endl;

	if (clstns) {
		// call listeners
		cout << setgray;

		xchg->getClstnsByJref(job->jref, false, icsFmncVCall, icsVJobmask);
		for (unsigned int i=0;i<icsFmncVCall.size();i++)
					cout << "\t\t" << id << VecFmncVCall::getSref(icsFmncVCall[i]) << " (" << Clstn::VecVJobmask::getSref(icsVJobmask[i]) << ")" << endl;

		xchg->getClstnsByJref(job->jref, true, icsFmncVCall, icsVJobmask);
		for (unsigned int i=0;i<icsFmncVCall.size();i++)
					cout << "\t\t" << id << "stmgr: " << VecFmncVCall::getSref(icsFmncVCall[i]) << endl;

		cout << reset;
	};

	if (ops) {
		// ops
		cout << setgray;

		Mutex::lock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		for (auto it=job->ops.begin();it!=job->ops.end();it++)
					cout << "\t\t" << id << VecFmncVDpch::getSref((*it)->ixVDpch).substr(4+3) << " (" << to_string((*it)->oref) << "): " << (*it)->squawk << endl;

		Mutex::unlock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		cout << reset;
	};

	if (presets) {
		// presettings
		cout << setgray;

		xchg->getPresetsByJref(job->jref, icsFmncVPreset, args);

		for (unsigned int i=0;i<icsFmncVPreset.size();i++)
					cout << "\t\t" << id << VecFmncVPreset::getSref(icsFmncVPreset[i]) << ": " << args[i].writeText() << endl;

		cout << reset;
	};

	if (dcolcont) {
		// dispatch collector content
		dcol = xchg->getDcolByJref(job->jref, false);

		if (dcol) {
			cout << setgray;

			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();it++)
						cout << "\t\t" << id << VecFmncVDpch::getSref((*it)->ixFmncVDpch) << " (" << (*it)->jref << ")" << endl;

			dcol->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	if (stmgrcont) {
		// stub manager content
		stmgr = xchg->getStmgrByJref(job->jref);

		if (stmgr) {
			cout << setgray;

			for (auto it=stmgr->stcch->nodes.begin();it!=stmgr->stcch->nodes.end();it++)
						cout << "\t\t" << id << VecFmncVStub::getSref(it->second->stref.ixVStub) << " (" << it->second->stref.ref << "): " << it->second->stub << endl;

			stmgr->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	// sub-entries
	JobFmnc* subjob;
	for (auto it=job->jrefsSub.begin();it!=job->jrefsSub.end();it++) {
		subjob = xchg->getJobByJref(*it);
		if (subjob) showSubjobs(xchg, subjob, clstns, ops, presets, dcolcont, stmgrcont, indent+1);
	};
};

void handleSignal(
			int sig
		) {
	// deleting fmnccmbd forces PrefFmnccmbd to be written
	if (fmnccmbd) delete fmnccmbd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	bool nocp = false;

	char* buf = NULL;
	string exedir;
	size_t ptr;

	pthread_mutex_t mcDummy;
	pthread_cond_t cDummy;

	string cmd;

	string input;
	int iinput;

	string s, s_backup;

	XchgFmnccmbd* xchg;

	JobFmnc* job;

	ReqFmnc* req;

	timeval now;
	timespec nexttime;

	fmnccmbd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// evaluate command-line options
	for (int i=1;i<argc;i++) if (!nocp) if (strcmp(argv[i], "-nocp") == 0) nocp = true;

	try {
		// determine executable path
		buf = new char[4096];

		if (readlink("/proc/self/exe", buf, 4096) >= 1) {
			exedir = buf;

		} else {
			if (strlen(argv[0]) >= 1) {
				exedir = argv[0];

				if (exedir[0] != '/') {
					if (getcwd(buf, 4096)) {
						exedir = "/" + exedir;
						exedir = buf + exedir;
					};
				};
			};
		};

		delete[] buf;

		ptr = exedir.rfind('/');
		if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);

		// calls fmnccmbd.init()
		fmnccmbd = new Fmnccmbd(exedir);
		xchg = fmnccmbd->xchg;

		if (nocp) {
			// wait on a dummy condition
			Mutex::init(&mcDummy, false, "mcDummy", "", "main");
			Cond::init(&cDummy, "cDummy", "", "main");
			Mutex::lock(&mcDummy, "mcDummy", "", "main");
			Cond::wait(&cDummy, &mcDummy, "cDummy", "", "main");
			Mutex::unlock(&mcDummy, "mcDummy", "", "main");
			Mutex::destroy(&mcDummy, false, "mcDummy", "", "main");
			Cond::destroy(&cDummy, "cDummy", "", "main");

		} else {
			// main command loop
			while (cmd.compare("quit") != 0) {
				cout << "Fmnccmbd >> ";
				cin >> cmd;

				if (cmd.compare("quit") == 0) {

				} else if (cmd.compare("cmdsetStd") == 0) {
					cout << "\tquit" << endl;

					cout << "\tstartMon" << endl;
					cout << "\tstopMon" << endl;

					cout << "\tshowJobs" << endl;
					cout << "\tshowSubjobs" << endl;

					cout << "\tgotoJob" << endl;
					cout << "\tgotoSupjob" << endl;

					cout << "\tshowClstns" << endl;
					cout << "\tshowOps" << endl;
					cout << "\tshowPresets" << endl;

					cout << "\tshowDcolContent" << endl;
					cout << "\tshowStmgrContent" << endl;

				} else if (cmd.compare("startMon") == 0) {
					xchg->startMon();

				} else if (cmd.compare("stopMon") == 0) {
					xchg->stopMon();

				} else if (cmd.compare("showJobs") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd.compare("showSubjobs") == 0) {
					job = xchg->getJobByJref(xchg->jrefCmd);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd.compare("gotoJob") == 0) {
					cout << "\tjob reference: ";
					cin >> input;
					iinput = atoi(input.c_str());

					job = xchg->getJobByJref(iinput);

					if (job) xchg->jrefCmd = job->jref;
					else cout << "\tjob reference doesn't exist!" << endl;

				} else if (cmd.compare("gotoSupjob") == 0) {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						job = xchg->getJobByJref(job->jrefSup);

						if (job) xchg->jrefCmd = job->jref;
						else cout << "\talready at topmost job!" << endl;
					};

				} else if (cmd.compare("showClstns") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, true, false, false, false, false, 0);

				} else if (cmd.compare("showOps") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, true, false, false, false, 0);

				} else if (cmd.compare("showPresets") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, true, false, false, 0);

				} else if (cmd.compare("showDcolContent") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, true, false, 0);

				} else if (cmd.compare("showStmgrContent") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, true, 0);

				} else {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						req = new ReqFmnc(ReqFmnc::VecVBasetype::CMD, ReqFmnc::VecVState::RECEIVE);
						req->cmd = cmd;
						req->jref = xchg->jrefCmd;

						gettimeofday(&now, NULL);
						nexttime.tv_sec = now.tv_sec + 1;
						nexttime.tv_nsec = 1000*now.tv_usec;

						xchg->addReq(req);

						s_backup = "";

						while (req->ixVState != ReqFmnc::VecVState::REPLY) {
							// wait for job processor to finish or to time out
							Mutex::lock(&(req->mcReady), "req->mcReady", "", "main");
							Cond::timedwait(&(req->cReady), &(req->mcReady), &nexttime, "req->cReady", "", "main");
							Mutex::unlock(&(req->mcReady), "req->mcReady", "", "main");

							if (req->ixVState == ReqFmnc::VecVState::WAITPRC) {
								cout << "\twaiting for processing" << endl;

							} else if (req->ixVState == ReqFmnc::VecVState::PRC) {
								s = job->getSquawk(&(fmnccmbd->dbsfmnc));
								if (s.compare(s_backup) != 0) {
									cout << "\t" << s << endl;
									s_backup = s;
								};
							};
							nexttime.tv_sec += 1;
						};

						delete req;
					};
				};
			};
		};

		delete fmnccmbd;

	} catch (DbsException e) {
		cout << e.err << endl;
	};
	
	return(0);
};


