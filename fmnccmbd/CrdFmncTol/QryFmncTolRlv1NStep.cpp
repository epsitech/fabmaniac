/**
  * \file QryFmncTolRlv1NStep.cpp
  * job handler for job QryFmncTolRlv1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTolRlv1NStep.h"

// IP blksInclude --- BEGIN
#include "QryFmncTolRlv1NStep_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTolRlv1NStep
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTolRlv1NStep::QryFmncTolRlv1NStep(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTOLRLV1NSTEP, jrefSup, ixFmncVLocale) {
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

QryFmncTolRlv1NStep::~QryFmncTolRlv1NStep() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTolRlv1NStep::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTolRlv1NStep::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTol = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSTEMOD_RLTRLUEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqtolrlv1nstep->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMStep.ref)";
	sqlstr += " FROM TblFmncMStep";
	sqlstr += " WHERE TblFmncMStep.rlvIxVTbl = " + to_string(VecFmncVMStepRlvTbl::TOL);
	sqlstr += " AND TblFmncMStep.rlvUref = " + to_string(preRefTol) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTolRlv1NStep(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMStep.ref";
	sqlstr += " FROM TblFmncMStep";
	sqlstr += " WHERE TblFmncMStep.rlvIxVTbl = " + to_string(VecFmncVMStepRlvTbl::TOL);
	sqlstr += " AND TblFmncMStep.rlvUref = " + to_string(preRefTol) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTolRlv1NStep SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCSTEMOD_RLTRLUEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVMStepRlvTbl::TOL, preRefTol, Clstn::VecVJactype::LOCK);
};

void QryFmncTolRlv1NStep::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTolRlv1NStep* rec = NULL;

	dbsfmnc->tblfmncqtolrlv1nstep->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubFmnc::getStubSteStd(dbsfmnc, rec->ref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTolRlv1NStep", "fetch");
	};

	refreshJnum();
};

uint QryFmncTolRlv1NStep::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTolRlv1NStep* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTolRlv1NStep::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTolRlv1NStep* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTolRlv1NStep::handleRequest(
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

bool QryFmncTolRlv1NStep::handleRefresh(
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

bool QryFmncTolRlv1NStep::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTolRlv1NStep* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryFmncTolRlv1NStep::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSTEMOD_RLTRLUEQ) {
		call->abort = handleCallFmncSteMod_rltRluEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool QryFmncTolRlv1NStep::handleCallFmncStubChg(
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

bool QryFmncTolRlv1NStep::handleCallFmncSteMod_rltRluEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixFmncVQrystate != VecFmncVQrystate::OOD) {
		ixFmncVQrystate = VecFmncVQrystate::OOD;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};


