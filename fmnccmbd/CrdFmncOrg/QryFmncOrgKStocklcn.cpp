/**
  * \file QryFmncOrgKStocklcn.cpp
  * job handler for job QryFmncOrgKStocklcn (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncOrgKStocklcn.h"

// IP blksInclude --- BEGIN
#include "QryFmncOrgKStocklcn_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncOrgKStocklcn
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncOrgKStocklcn::QryFmncOrgKStocklcn(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCORGKSTOCKLCN, jrefSup, ixFmncVLocale) {
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

QryFmncOrgKStocklcn::~QryFmncOrgKStocklcn() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncOrgKStocklcn::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncOrgKStocklcn::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefOrg = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqorgkstocklcn->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAVKeylistKey.ref)";
	sqlstr += " FROM TblFmncAVKeylistKey";
	sqlstr += " WHERE klsIxFmncVKeylist = " + to_string(VecFmncVKeylist::KLSTFMNCKSTOCKLCN);
	sqlstr += " AND x1IxFmncVMaintable = " + to_string(VecFmncVMaintable::TBLFMNCMORG);
	sqlstr += " AND x1Uref = " + to_string(preRefOrg) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQOrgKStocklcn(jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAVKeylistKey.ref, TblFmncAVKeylistKey.klsNum, TblFmncAVKeylistKey.Fixed, TblFmncAVKeylistKey.sref, TblFmncAVKeylistKey.Avail, TblFmncAVKeylistKey.Implied, TblFmncAVKeylistKey.refJ, TblFmncAVKeylistKey.Title, TblFmncAVKeylistKey.Comment";
	sqlstr += " FROM TblFmncAVKeylistKey";
	sqlstr += " WHERE klsIxFmncVKeylist = " + to_string(VecFmncVKeylist::KLSTFMNCKSTOCKLCN);
	sqlstr += " AND x1IxFmncVMaintable = " + to_string(VecFmncVMaintable::TBLFMNCMORG);
	sqlstr += " AND x1Uref = " + to_string(preRefOrg) + "";
	sqlstr += " ORDER BY TblFmncAVKeylistKey.klsNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQOrgKStocklcn SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addIxRefSrefClstn(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVMaintable::TBLFMNCMORG, preRefOrg, VecFmncVKeylist::getSref(VecFmncVKeylist::KLSTFMNCKSTOCKLCN), Clstn::VecVJactype::LOCK);
};

void QryFmncOrgKStocklcn::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQOrgKStocklcn* rec = NULL;

	dbsfmnc->tblfmncqorgkstocklcn->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryFmncOrgKStocklcn", "fetch");
	};

	refreshJnum();
};

uint QryFmncOrgKStocklcn::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQOrgKStocklcn* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncOrgKStocklcn::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQOrgKStocklcn* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncOrgKStocklcn::handleRequest(
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

bool QryFmncOrgKStocklcn::handleRefresh(
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

bool QryFmncOrgKStocklcn::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQOrgKStocklcn* rec = NULL;

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

void QryFmncOrgKStocklcn::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallFmncKlsAkeyMod_klsMtbUrfEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	};
};

bool QryFmncOrgKStocklcn::handleCallFmncStubChg(
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

bool QryFmncOrgKStocklcn::handleCallFmncKlsAkeyMod_klsMtbUrfEq(
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


