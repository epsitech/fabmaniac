/**
  * \file QryFmncTtyMNTool.cpp
  * job handler for job QryFmncTtyMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTtyMNTool.h"

// IP blksInclude --- BEGIN
#include "QryFmncTtyMNTool_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTtyMNTool
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTtyMNTool::QryFmncTtyMNTool(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTTYMNTOOL, jrefSup, ixFmncVLocale) {
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

QryFmncTtyMNTool::~QryFmncTtyMNTool() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTtyMNTool::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTtyMNTool::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTty = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTTY, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLRTTYMOD_TTYEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqttymntool->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncRMToolMTooltype.ref)";
	sqlstr += " FROM TblFmncRMToolMTooltype, TblFmncMTool";
	sqlstr += " WHERE TblFmncRMToolMTooltype.refFmncMTool = TblFmncMTool.ref";
	sqlstr += " AND TblFmncRMToolMTooltype.refFmncMTooltype = " + to_string(preRefTty) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTtyMNTool(jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMTool.ref, TblFmncRMToolMTooltype.ref, TblFmncRMToolMTooltype.srefsFmncKToolchar, TblFmncRMToolMTooltype.defSrefsFmncKSteppar, TblFmncRMToolMTooltype.optSrefsFmncKSteppar";
	sqlstr += " FROM TblFmncRMToolMTooltype, TblFmncMTool";
	sqlstr += " WHERE TblFmncRMToolMTooltype.refFmncMTool = TblFmncMTool.ref";
	sqlstr += " AND TblFmncRMToolMTooltype.refFmncMTooltype = " + to_string(preRefTty) + "";
	sqlstr += " ORDER BY TblFmncMTool.Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTtyMNTool SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLRTTYMOD_TTYEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefTty, Clstn::VecVJactype::LOCK);
};

void QryFmncTtyMNTool::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTtyMNTool* rec = NULL;

	dbsfmnc->tblfmncqttymntool->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubFmnc::getStubTolStd(dbsfmnc, rec->mref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTtyMNTool", "fetch");
	};

	refreshJnum();
};

uint QryFmncTtyMNTool::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTtyMNTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTtyMNTool::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTtyMNTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTtyMNTool::handleRequest(
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

bool QryFmncTtyMNTool::handleRefresh(
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

bool QryFmncTtyMNTool::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTtyMNTool* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tsrefsFmncKToolchar";
	cout << "\ttitsSrefsFmncKToolchar";
	cout << "\tdefSrefsFmncKSteppar";
	cout << "\ttitsDefSrefsFmncKSteppar";
	cout << "\toptSrefsFmncKSteppar";
	cout << "\ttitsOptSrefsFmncKSteppar";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->srefsFmncKToolchar;
		cout << "\t" << rec->titsSrefsFmncKToolchar;
		cout << "\t" << rec->defSrefsFmncKSteppar;
		cout << "\t" << rec->titsDefSrefsFmncKSteppar;
		cout << "\t" << rec->optSrefsFmncKSteppar;
		cout << "\t" << rec->titsOptSrefsFmncKSteppar;
		cout << endl;
	};
	return retval;
};

void QryFmncTtyMNTool::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLRTTYMOD_TTYEQ) {
		call->abort = handleCallFmncTolRttyMod_ttyEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTtyMNTool::handleCallFmncStubChg(
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

bool QryFmncTtyMNTool::handleCallFmncTolRttyMod_ttyEq(
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


