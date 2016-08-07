/**
  * \file QryFmncStpAPar.cpp
  * job handler for job QryFmncStpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncStpAPar.h"

// IP blksInclude --- BEGIN
#include "QryFmncStpAPar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncStpAPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncStpAPar::QryFmncStpAPar(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSTPAPAR, jrefSup, ixFmncVLocale) {
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

QryFmncStpAPar::~QryFmncStpAPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncStpAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncStpAPar::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefStp = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSTP, jref);
	string preX1 = xchg->getSrefPreset(VecFmncVPreset::PREFMNCSTPAPAR_X1, jref);
	uint preX2 = xchg->getIxPreset(VecFmncVPreset::PREFMNCSTPAPAR_X2, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSTEAPARMOD_STEEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqstpapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMStepPar.ref)";
	sqlstr += " FROM TblFmncAMStepPar";
	sqlstr += " WHERE TblFmncAMStepPar.refFmncMStep = " + to_string(preRefStp) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQStpAPar(jref, jnum, ref, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMStepPar.ref, TblFmncAMStepPar.x1OsrefFmncKSteppar, TblFmncAMStepPar.x2IxVTbl, TblFmncAMStepPar.x2Uref, TblFmncAMStepPar.Val, TblFmncAMStepPar.Comment";
	sqlstr += " FROM TblFmncAMStepPar";
	sqlstr += " WHERE TblFmncAMStepPar.refFmncMStep = " + to_string(preRefStp) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQStpAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCSTEAPARMOD_STEEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefStp, Clstn::VecVJactype::LOCK);
};

void QryFmncStpAPar::refresh_filtSQL(
			string& sqlstr
			, const string& preX1
			, const uint preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMStepPar.x1OsrefFmncKSteppar = " + preX1 + "";
	};

	if (preX2 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMStepPar.x2IxVTbl = " + to_string(preX2) + "";
	};

	if (preX2 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMStepPar.x2Uref = " + to_string(preX2) + "";
	};
};

void QryFmncStpAPar::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncStpAPar::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQStpAPar* rec = NULL;

	dbsfmnc->tblfmncqstpapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1OsrefFmncKSteppar = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKSTEPPAR, rec->x1OsrefFmncKSteppar, ixFmncVLocale);
			rec->srefX2IxVTbl = VecFmncVAMStepParTbl::getSref(rec->x2IxVTbl);
			rec->titX2IxVTbl = VecFmncVAMStepParTbl::getTitle(rec->x2IxVTbl, ixFmncVLocale);
			if (rec->x2IxVTbl == VecFmncVAMStepParTbl::FIL) {
				rec->stubX2Uref = StubFmnc::getStubFilStd(dbsfmnc, rec->x2Uref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->x2IxVTbl == VecFmncVAMStepParTbl::SMP) {
				rec->stubX2Uref = StubFmnc::getStubSmpStd(dbsfmnc, rec->x2Uref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubX2Uref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncStpAPar", "fetch");
	};

	refreshJnum();
};

uint QryFmncStpAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQStpAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncStpAPar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQStpAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncStpAPar::handleRequest(
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

bool QryFmncStpAPar::handleRefresh(
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

bool QryFmncStpAPar::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQStpAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1OsrefFmncKSteppar";
	cout << "\ttitX1OsrefFmncKSteppar";
	cout << "\tx2IxVTbl";
	cout << "\tsrefX2IxVTbl";
	cout << "\ttitX2IxVTbl";
	cout << "\tx2Uref";
	cout << "\tstubX2Uref";
	cout << "\tVal";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1OsrefFmncKSteppar;
		cout << "\t" << rec->titX1OsrefFmncKSteppar;
		cout << "\t" << rec->x2IxVTbl;
		cout << "\t" << rec->srefX2IxVTbl;
		cout << "\t" << rec->titX2IxVTbl;
		cout << "\t" << rec->x2Uref;
		cout << "\t" << rec->stubX2Uref;
		cout << "\t" << rec->Val;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryFmncStpAPar::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSTEAPARMOD_STEEQ) {
		call->abort = handleCallFmncSteAparMod_steEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncStpAPar::handleCallFmncStubChg(
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

bool QryFmncStpAPar::handleCallFmncSteAparMod_steEq(
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


