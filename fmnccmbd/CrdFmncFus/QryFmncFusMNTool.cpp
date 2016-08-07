/**
  * \file QryFmncFusMNTool.cpp
  * job handler for job QryFmncFusMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncFusMNTool.h"

// IP blksInclude --- BEGIN
#include "QryFmncFusMNTool_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncFusMNTool
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncFusMNTool::QryFmncFusMNTool(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCFUSMNTOOL, jrefSup, ixFmncVLocale) {
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

QryFmncFusMNTool::~QryFmncFusMNTool() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncFusMNTool::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncFusMNTool::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefFus = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFUS, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCFUSRTOLMOD_FUSEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqfusmntool->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncRMFabuserMTool.ref)";
	sqlstr += " FROM TblFmncRMFabuserMTool, TblFmncMTool";
	sqlstr += " WHERE TblFmncRMFabuserMTool.refFmncMTool = TblFmncMTool.ref";
	sqlstr += " AND TblFmncRMFabuserMTool.refFmncMFabuser = " + to_string(preRefFus) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQFusMNTool(jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMTool.ref, TblFmncRMFabuserMTool.ref, TblFmncRMFabuserMTool.trnRefFmncMPerson, TblFmncRMFabuserMTool.srefKLvl";
	sqlstr += " FROM TblFmncRMFabuserMTool, TblFmncMTool";
	sqlstr += " WHERE TblFmncRMFabuserMTool.refFmncMTool = TblFmncMTool.ref";
	sqlstr += " AND TblFmncRMFabuserMTool.refFmncMFabuser = " + to_string(preRefFus) + "";
	sqlstr += " ORDER BY TblFmncMTool.Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQFusMNTool SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCFUSRTOLMOD_FUSEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefFus, Clstn::VecVJactype::LOCK);
};

void QryFmncFusMNTool::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQFusMNTool* rec = NULL;

	dbsfmnc->tblfmncqfusmntool->loadRstByJref(jref, false, rst);
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
			rec->stubTrnRefFmncMPerson = StubFmnc::getStubPrsStd(dbsfmnc, rec->trnRefFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefKLvl = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKRMFABUSERMTOOLLVL, rec->srefKLvl, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncFusMNTool", "fetch");
	};

	refreshJnum();
};

uint QryFmncFusMNTool::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQFusMNTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncFusMNTool::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQFusMNTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncFusMNTool::handleRequest(
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

bool QryFmncFusMNTool::handleRefresh(
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

bool QryFmncFusMNTool::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQFusMNTool* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\ttrnRefFmncMPerson";
	cout << "\tstubTrnRefFmncMPerson";
	cout << "\tsrefKLvl";
	cout << "\ttitSrefKLvl";
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
		cout << "\t" << rec->trnRefFmncMPerson;
		cout << "\t" << rec->stubTrnRefFmncMPerson;
		cout << "\t" << rec->srefKLvl;
		cout << "\t" << rec->titSrefKLvl;
		cout << endl;
	};
	return retval;
};

void QryFmncFusMNTool::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFUSRTOLMOD_FUSEQ) {
		call->abort = handleCallFmncFusRtolMod_fusEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncFusMNTool::handleCallFmncStubChg(
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

bool QryFmncFusMNTool::handleCallFmncFusRtolMod_fusEq(
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


