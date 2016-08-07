/**
  * \file RootFmnc.cpp
  * job handler for job RootFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "RootFmnc.h"

// IP blksInclude --- BEGIN
#include "RootFmnc_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class RootFmnc
 ******************************************************************************/

RootFmnc::RootFmnc(
			XchgFmnc* xchg
		) : JobFmnc(xchg, VecFmncVJob::ROOTFMNC, 0, ixFmncVLocale) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	// root job receives commands
	xchg->jrefCmd = jref;

	// log
	xchg->appendToLogfile("root job created");

// IP constructor.cust2 --- INSERT

// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecFmncVCall::CALLFMNCLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

RootFmnc::~RootFmnc() {
	// log
	xchg->appendToLogfile("root job deleted");

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void RootFmnc::clearAll(
			DbsFmnc* dbsfmnc
		) {
	FmncMUsergroup* usg = NULL;
	FmncRMUserMUsergroup* uru = NULL;
	FmncMUser* usr = NULL;
	ubigint refUjs = 0;
	FmncMPerson* prs = NULL;
	ubigint refPjl = 0;
	ubigint refAdr = 0;

	time_t timeval;
	uint dateval;

	string s;

	// empty out tables
	dbsfmnc->executeQuery("DELETE FROM TblFmncAccRMUserUniversal");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMBillPos");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMOrgDetail");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMPersonDetail");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMPurchorderPos");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMSamplePar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMStepPar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMToolAvl");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMToolChar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMToolRes");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMToolUtil");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMUserAccess");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAMUsergroupAccess");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAVControlPar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAVKeylistKey");
	dbsfmnc->executeQuery("DELETE FROM TblFmncAVValuelistVal");
	if (dbsfmnc->ixDbsVDbstype == VecDbsVDbstype::MY) dbsfmnc->executeQuery("DELETE FROM TblFmncCFile");
	else if (dbsfmnc->ixDbsVDbstype == VecDbsVDbstype::PG) dbsfmnc->executeQuery("ALTER SEQUENCE TblFmncCFile RESTART WITH 1");
	dbsfmnc->executeQuery("DELETE FROM TblFmncFabSMPersonMTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncHistRMUserUniversal");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJAVKeylistKey");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMBillState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMFabprojectState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMFabuserState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMOrgTitle");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMPersonLastname");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMProjectState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMPurchorderState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMRunState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMSampleState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMStockitemQuantity");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMToolUnitprice");
	dbsfmnc->executeQuery("DELETE FROM TblFmncJMUserState");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMActivity");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMAddress");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMArticle");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMBill");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMFab");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMFabproject");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMFabuser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMnfSMPersonMTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMOrg");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMPerson");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMProject");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMPurchorder");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMSession");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMStockitem");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMTooltype");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMUser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncMUsergroup");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMArticleMOrg");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMFabMRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMFabprojectMFabuser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMFabuserMTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMFileMSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMFileMStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMOrgMPerson");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMPersonMRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMRunMSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMSampleMStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMToolMTooltype");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMUsergroupUniversal");
	dbsfmnc->executeQuery("DELETE FROM TblFmncRMUserMUsergroup");
	dbsfmnc->executeQuery("DELETE FROM TblFmncSvcRMOrgMTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncSvcTMPersonMTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncTMFileMSample");

	clearQtb(dbsfmnc);

	// generate a temporary user such that a session can be generated
	dbsfmnc->tblfmncmusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbsfmnc->tblfmncamusergroupaccess->insertNewRec(NULL, usg->ref, VecFmncVCard::CRDFMNCNAV, VecFmncWUiaccess::EDIT + VecFmncWUiaccess::EXEC + VecFmncWUiaccess::VIEW);
	dbsfmnc->tblfmncrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecFmncVUserlevel::GADM);
	dbsfmnc->tblfmncmuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecFmncVMUserState::DUE, VecFmncVLocale::ENUS, VecFmncVUserlevel::GADM, "asdf1234");
	refUjs = dbsfmnc->tblfmncjmuserstate->insertNewRec(NULL, usr->ref, 0, VecFmncVMUserState::DUE);

	time(&timeval);
	dateval = 1 + (timeval - (timeval % (3600*24))) / (3600*24);

	dbsfmnc->tblfmncjmuserstate->insertNewRec(NULL, usr->ref, dateval, VecFmncVMUserState::EXP);
	dbsfmnc->tblfmncmperson->insertNewRec(&prs, usg->ref, usr->ref, VecFmncWMPersonDerivate::USR, 0, 0, 0, VecFmncVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	refAdr = dbsfmnc->tblfmncmaddress->insertNewRec(NULL, usg->ref, usr->ref, 0, VecFmncVMAddressHkTbl::PRS, prs->ref, "ofc", "1234 West 119th Street", "", "10027", "New York", "NY", "us");
	refPjl = dbsfmnc->tblfmncjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbsfmnc->tblfmncmusergroup->updateRec(usg);

	uru->refFmncMUser = usr->ref;
	dbsfmnc->tblfmncrmusermusergroup->updateRec(uru);

	usr->refFmncMPerson = prs->ref;
	usr->refJState = refUjs;
	dbsfmnc->tblfmncmuser->updateRec(usr);

	prs->refFmncMAddress = refAdr;
	prs->refJLastname = refPjl;
	dbsfmnc->tblfmncmperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::date(dateval) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootFmnc::clearQtb(
			DbsFmnc* dbsfmnc
		) {
	dbsfmnc->executeQuery("DELETE FROM TblFmncQAct1NStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQActList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQAdrList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQArt1NSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQArt1NStockitem");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQArtList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQArtMNOrg");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQArtRef1NFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQBilAPos");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQBilList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFab1NFabproject");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFab1NFabuser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFabFab1NTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFabList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFabMNRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFilList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFilMNSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFilMNStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFpj1NBill");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFpjList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFpjMNFabuser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFusList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFusMNFabproject");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQFusMNTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrg1NArticle");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrg1NStockitem");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgADetail");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgBio1NFabproject");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgHk1NAddress");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgKStocklcn");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgMNArticle");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgMnf1NTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgMNPerson");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgPco1NPurchorder");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgSpl1NPurchorder");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgSup1NOrg");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQOrgSvcMNTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPcoAPos");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPcoList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPreselect");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrj1NRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrjList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrsADetail");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrsHk1NAddress");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrsList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrsMNOrg");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQPrsMNRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQRunList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQRunMNFab");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQRunMNPerson");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQRunMNSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQRunRef1NFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQRunRun1NActivity");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSelect");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSepAPar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSepList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSepMNFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSepMNSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSepRef1NFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSkiList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpAPar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpMNFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpMNRun");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpMNStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpRef1NFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQSmpSup1NSample");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQStpAPar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQStpKSteppar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQStpList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQStpMNFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQStpRef1NFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQStpTpl1NStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTol1NArticle");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolAAvl");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolAChar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolARes");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolAUtil");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolKSteppar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolKToolchar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolMNFabuser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolMNTooltype");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolRef1NFile");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolRlv1NStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTolSvcMNOrg");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTtyKSteppar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTtyKToolchar");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTtyList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTtyMNTool");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTtyRlv1NStep");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQTtySup1NTooltype");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsgAAccess");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsgList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsgMNUser");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsr1NSession");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsrAAccess");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsrList");
	dbsfmnc->executeQuery("DELETE FROM TblFmncQUsrMNUsergroup");
};

void RootFmnc::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbsfmnc);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbsfmnc);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbsfmnc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPROOTFMNCLOGIN) {
			handleDpchAppLogin(dbsfmnc, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};
	};
};

bool RootFmnc::handleClearAll(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	clearAll(dbsfmnc);
	return retval;
};

bool RootFmnc::handleCreateSess(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	SessFmnc* sess = NULL;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (dbsfmnc->tblfmncmuser->loadRefBySrfPwd(input, input2, refUsr)) {
		sess = new SessFmnc(xchg, dbsfmnc, jref, refUsr, "127.0.0.1");
		sesss.push_back(sess);

		cout << "\tjob reference: " << sess->jref << endl;
		xchg->jrefCmd = sess->jref;

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return false;
	return retval;
};

bool RootFmnc::handleEraseSess(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	SessFmnc* sess = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=sesss.begin();it!=sesss.end();) {
		sess = *it;
		if (sess->jref == iinput) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};

	return false;
	return retval;
};

void RootFmnc::handleDpchAppLogin(
			DbsFmnc* dbsfmnc
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngFmnc** dpcheng
		) {
	ubigint refUsr;

	SessFmnc* sess = NULL;

	// verify password and create a session
	if (dbsfmnc->tblfmncmuser->loadRefBySrfPwd(dpchapplogin->username, dpchapplogin->password, refUsr)) {
		sess = new SessFmnc(xchg, dbsfmnc, jref, refUsr, ip);
		sesss.push_back(sess);

		xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngFmncConfirm(true, sess->jref, "");

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngFmncConfirm(false, 0, "");
	};
};

void RootFmnc::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCLOGOUT) {
		call->abort = handleCallFmncLogout(dbsfmnc, call->jref);
	};
};

bool RootFmnc::handleCallFmncLogout(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	SessFmnc* sess = NULL;

	for (auto it=sesss.begin();it!=sesss.end();) {
		sess = *it;
		if (sess->jref == jrefTrig) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};
	return retval;
};


