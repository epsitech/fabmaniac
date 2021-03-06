/**
  * \file QryFmncFilMNStep.cpp
  * job handler for job QryFmncFilMNStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncFilMNStep.h"

// IP blksInclude --- BEGIN
#include "QryFmncFilMNStep_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncFilMNStep
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncFilMNStep::QryFmncFilMNStep(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCFILMNSTEP, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixFmncVQrystate = VecFmncVQrystate::OOD;

// IP constructor.cust2 --- INSERT

	refresh(dbsfmnc);

	xchg->addClstn(VecFmncVCall::CALLFMNCSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncFilMNStep::~QryFmncFilMNStep() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncFilMNStep::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncFilMNStep::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefFil = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFIL, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCFILRSTEMOD_FILEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqfilmnstep->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncRMFileMStep.ref)";
	sqlstr += " FROM TblFmncRMFileMStep, TblFmncMStep";
	sqlstr += " WHERE TblFmncRMFileMStep.refFmncMStep = TblFmncMStep.ref";
	sqlstr += " AND TblFmncRMFileMStep.refFmncMFile = " + to_string(preRefFil) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQFilMNStep(jref, jnum, mref, ref, ixVDir)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMStep.ref, TblFmncRMFileMStep.ref, TblFmncRMFileMStep.ixVDir";
	sqlstr += " FROM TblFmncRMFileMStep, TblFmncMStep";
	sqlstr += " WHERE TblFmncRMFileMStep.refFmncMStep = TblFmncMStep.ref";
	sqlstr += " AND TblFmncRMFileMStep.refFmncMFile = " + to_string(preRefFil) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQFilMNStep SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCFILRSTEMOD_FILEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefFil, Clstn::VecVJactype::LOCK);
};

void QryFmncFilMNStep::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQFilMNStep* rec = NULL;

	ListFmncTMFileMSample filTsmps;
	FmncTMFileMSample* filTsmp = NULL;

	dbsfmnc->tblfmncqfilmnstep->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubFmnc::getStubSteStd(dbsfmnc, rec->mref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			dbsfmnc->tblfmnctmfilemsample->loadRstByR(rec->ref, false, filTsmps);
			for (unsigned int j=0;j<filTsmps.nodes.size();j++) {
				filTsmp = filTsmps.nodes[j];
				if (j != 0) rec->stubsTrefFmncMSample += ";";
				rec->stubsTrefFmncMSample += StubFmnc::getStubSmpStd(dbsfmnc, filTsmp->refFmncMSample, ixFmncVLocale, Stub::VecVNonetype::DASH, stcch);
			};
			rec->srefIxVDir = VecFmncVRMFileMStepDir::getSref(rec->ixVDir);
			rec->titIxVDir = VecFmncVRMFileMStepDir::getTitle(rec->ixVDir, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncFilMNStep", "fetch");
	};

	refreshJnum();
};

uint QryFmncFilMNStep::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQFilMNStep* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncFilMNStep::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQFilMNStep* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncFilMNStep::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\trefresh" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "refresh") {
			req->retain = handleRefresh(dbsfmnc);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbsfmnc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
	};
};

bool QryFmncFilMNStep::handleRefresh(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	refresh(dbsfmnc);
	return retval;
};

bool QryFmncFilMNStep::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQFilMNStep* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tstubsTrefFmncMSample";
	cout << "\tref";
	cout << "\tixVDir";
	cout << "\tsrefIxVDir";
	cout << "\ttitIxVDir";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->stubsTrefFmncMSample;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixVDir;
		cout << "\t" << rec->srefIxVDir;
		cout << "\t" << rec->titIxVDir;
		cout << endl;
	};
	return retval;
};

void QryFmncFilMNStep::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFILRSTEMOD_FILEQ) {
		call->abort = handleCallFmncFilRsteMod_filEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncFilMNStep::handleCallFmncStubChg(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixFmncVQrystate == VecFmncVQrystate::UTD) {
		ixFmncVQrystate = VecFmncVQrystate::SLM;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};

bool QryFmncFilMNStep::handleCallFmncFilRsteMod_filEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixFmncVQrystate != VecFmncVQrystate::OOD) {
		ixFmncVQrystate = VecFmncVQrystate::OOD;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};


