/**
  * \file QryFmncPcoAPos.cpp
  * job handler for job QryFmncPcoAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncPcoAPos.h"

// IP blksInclude --- BEGIN
#include "QryFmncPcoAPos_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncPcoAPos
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncPcoAPos::QryFmncPcoAPos(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCPCOAPOS, jrefSup, ixFmncVLocale) {
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

QryFmncPcoAPos::~QryFmncPcoAPos() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncPcoAPos::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncPcoAPos::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefPco = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPCO, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCPCOAPOSMOD_PCOEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqpcoapos->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMPurchorderPos.ref)";
	sqlstr += " FROM TblFmncAMPurchorderPos";
	sqlstr += " WHERE TblFmncAMPurchorderPos.pcoRefFmncMPurchorder = " + to_string(preRefPco) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQPcoAPos(jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMPurchorderPos.ref, TblFmncAMPurchorderPos.pcoNum, TblFmncAMPurchorderPos.Quantity, TblFmncAMPurchorderPos.Itemno, TblFmncAMPurchorderPos.refFmncMArticle, TblFmncAMPurchorderPos.Unitprice, TblFmncAMPurchorderPos.Price";
	sqlstr += " FROM TblFmncAMPurchorderPos";
	sqlstr += " WHERE TblFmncAMPurchorderPos.pcoRefFmncMPurchorder = " + to_string(preRefPco) + "";
	sqlstr += " ORDER BY pcoNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQPcoAPos SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCPCOAPOSMOD_PCOEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefPco, Clstn::VecVJactype::LOCK);
};

void QryFmncPcoAPos::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQPcoAPos* rec = NULL;

	dbsfmnc->tblfmncqpcoapos->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefFmncMArticle = StubFmnc::getStubArtStd(dbsfmnc, rec->refFmncMArticle, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncPcoAPos", "fetch");
	};

	refreshJnum();
};

uint QryFmncPcoAPos::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQPcoAPos* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncPcoAPos::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQPcoAPos* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncPcoAPos::handleRequest(
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

bool QryFmncPcoAPos::handleRefresh(
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

bool QryFmncPcoAPos::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQPcoAPos* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tpcoNum";
	cout << "\tQuantity";
	cout << "\tItemno";
	cout << "\trefFmncMArticle";
	cout << "\tstubRefFmncMArticle";
	cout << "\tUnitprice";
	cout << "\tPrice";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->pcoNum;
		cout << "\t" << rec->Quantity;
		cout << "\t" << rec->Itemno;
		cout << "\t" << rec->refFmncMArticle;
		cout << "\t" << rec->stubRefFmncMArticle;
		cout << "\t" << rec->Unitprice;
		cout << "\t" << rec->Price;
		cout << endl;
	};
	return retval;
};

void QryFmncPcoAPos::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPCOAPOSMOD_PCOEQ) {
		call->abort = handleCallFmncPcoAposMod_pcoEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncPcoAPos::handleCallFmncStubChg(
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

bool QryFmncPcoAPos::handleCallFmncPcoAposMod_pcoEq(
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


