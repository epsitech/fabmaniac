/**
  * \file QryFmncTtyKSteppar.cpp
  * job handler for job QryFmncTtyKSteppar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTtyKSteppar.h"

// IP blksInclude --- BEGIN
#include "QryFmncTtyKSteppar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTtyKSteppar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTtyKSteppar::QryFmncTtyKSteppar(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTTYKSTEPPAR, jrefSup, ixFmncVLocale) {
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

QryFmncTtyKSteppar::~QryFmncTtyKSteppar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTtyKSteppar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTtyKSteppar::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTty = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTTY, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqttyksteppar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAVKeylistKey.ref)";
	sqlstr += " FROM TblFmncAVKeylistKey";
	sqlstr += " WHERE klsIxFmncVKeylist = " + to_string(VecFmncVKeylist::KLSTFMNCKSTEPPAR);
	sqlstr += " AND x1IxFmncVMaintable = " + to_string(VecFmncVMaintable::TBLFMNCMTOOLTYPE);
	sqlstr += " AND x1Uref = " + to_string(preRefTty) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTtyKSteppar(jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAVKeylistKey.ref, TblFmncAVKeylistKey.klsNum, TblFmncAVKeylistKey.Fixed, TblFmncAVKeylistKey.sref, TblFmncAVKeylistKey.Avail, TblFmncAVKeylistKey.Implied, TblFmncAVKeylistKey.refJ, TblFmncAVKeylistKey.Title, TblFmncAVKeylistKey.Comment";
	sqlstr += " FROM TblFmncAVKeylistKey";
	sqlstr += " WHERE klsIxFmncVKeylist = " + to_string(VecFmncVKeylist::KLSTFMNCKSTEPPAR);
	sqlstr += " AND x1IxFmncVMaintable = " + to_string(VecFmncVMaintable::TBLFMNCMTOOLTYPE);
	sqlstr += " AND x1Uref = " + to_string(preRefTty) + "";
	sqlstr += " ORDER BY TblFmncAVKeylistKey.klsNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTtyKSteppar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addIxRefSrefClstn(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVMaintable::TBLFMNCMTOOLTYPE, preRefTty, VecFmncVKeylist::getSref(VecFmncVKeylist::KLSTFMNCKSTEPPAR), Clstn::VecVJactype::LOCK);
};

void QryFmncTtyKSteppar::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTtyKSteppar* rec = NULL;

	dbsfmnc->tblfmncqttyksteppar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			if (rec->Fixed) rec->yesnoFixed = VecFmncVTag::getTitle(VecFmncVTag::YES, ixFmncVLocale); else rec->yesnoFixed = VecFmncVTag::getTitle(VecFmncVTag::NO, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTtyKSteppar", "fetch");
	};

	refreshJnum();
};

uint QryFmncTtyKSteppar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTtyKSteppar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTtyKSteppar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTtyKSteppar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTtyKSteppar::handleRequest(
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

bool QryFmncTtyKSteppar::handleRefresh(
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

bool QryFmncTtyKSteppar::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTtyKSteppar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tklsNum";
	cout << "\tFixed";
	cout << "\tyesnoFixed";
	cout << "\tsref";
	cout << "\tAvail";
	cout << "\tImplied";
	cout << "\trefJ";
	cout << "\tTitle";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->klsNum;
		cout << "\t" << rec->Fixed;
		cout << "\t" << rec->yesnoFixed;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Avail;
		cout << "\t" << rec->Implied;
		cout << "\t" << rec->refJ;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryFmncTtyKSteppar::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallFmncKlsAkeyMod_klsMtbUrfEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	};
};

bool QryFmncTtyKSteppar::handleCallFmncStubChg(
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

bool QryFmncTtyKSteppar::handleCallFmncKlsAkeyMod_klsMtbUrfEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;

	if (ixFmncVQrystate != VecFmncVQrystate::OOD) {
		ixFmncVQrystate = VecFmncVQrystate::OOD;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};


