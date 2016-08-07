/**
  * \file QryFmncTolMNFabuser.cpp
  * job handler for job QryFmncTolMNFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTolMNFabuser.h"

// IP blksInclude --- BEGIN
#include "QryFmncTolMNFabuser_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTolMNFabuser
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTolMNFabuser::QryFmncTolMNFabuser(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTOLMNFABUSER, jrefSup, ixFmncVLocale) {
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

QryFmncTolMNFabuser::~QryFmncTolMNFabuser() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTolMNFabuser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTolMNFabuser::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTol = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCFUSRTOLMOD_TOLEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqtolmnfabuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncRMFabuserMTool.ref)";
	sqlstr += " FROM TblFmncRMFabuserMTool, TblFmncMFabuser";
	sqlstr += " WHERE TblFmncRMFabuserMTool.refFmncMFabuser = TblFmncMFabuser.ref";
	sqlstr += " AND TblFmncRMFabuserMTool.refFmncMTool = " + to_string(preRefTol) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTolMNFabuser(jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMFabuser.ref, TblFmncRMFabuserMTool.ref, TblFmncRMFabuserMTool.trnRefFmncMPerson, TblFmncRMFabuserMTool.srefKLvl";
	sqlstr += " FROM TblFmncRMFabuserMTool, TblFmncMFabuser";
	sqlstr += " WHERE TblFmncRMFabuserMTool.refFmncMFabuser = TblFmncMFabuser.ref";
	sqlstr += " AND TblFmncRMFabuserMTool.refFmncMTool = " + to_string(preRefTol) + "";
	sqlstr += " ORDER BY TblFmncMFabuser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTolMNFabuser SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCFUSRTOLMOD_TOLEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefTol, Clstn::VecVJactype::LOCK);
};

void QryFmncTolMNFabuser::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTolMNFabuser* rec = NULL;

	dbsfmnc->tblfmncqtolmnfabuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubFmnc::getStubFusStd(dbsfmnc, rec->mref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubTrnRefFmncMPerson = StubFmnc::getStubPrsStd(dbsfmnc, rec->trnRefFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefKLvl = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKRMFABUSERMTOOLLVL, rec->srefKLvl, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTolMNFabuser", "fetch");
	};

	refreshJnum();
};

uint QryFmncTolMNFabuser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTolMNFabuser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTolMNFabuser::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTolMNFabuser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTolMNFabuser::handleRequest(
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

bool QryFmncTolMNFabuser::handleRefresh(
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

bool QryFmncTolMNFabuser::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTolMNFabuser* rec = NULL;

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

void QryFmncTolMNFabuser::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFUSRTOLMOD_TOLEQ) {
		call->abort = handleCallFmncFusRtolMod_tolEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTolMNFabuser::handleCallFmncStubChg(
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

bool QryFmncTolMNFabuser::handleCallFmncFusRtolMod_tolEq(
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


