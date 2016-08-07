/**
  * \file QryFmncBilAPos.cpp
  * job handler for job QryFmncBilAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncBilAPos.h"

// IP blksInclude --- BEGIN
#include "QryFmncBilAPos_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncBilAPos
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncBilAPos::QryFmncBilAPos(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCBILAPOS, jrefSup, ixFmncVLocale) {
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

QryFmncBilAPos::~QryFmncBilAPos() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncBilAPos::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncBilAPos::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefBil = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFBIL, jref);
	ubigint preX1 = xchg->getRefPreset(VecFmncVPreset::PREFMNCBILAPOS_X1, jref);
	ubigint preX2 = xchg->getRefPreset(VecFmncVPreset::PREFMNCBILAPOS_X2, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCBILAPOSMOD_BILEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqbilapos->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMBillPos.ref)";
	sqlstr += " FROM TblFmncAMBillPos";
	sqlstr += " WHERE TblFmncAMBillPos.bilRefFmncMBill = " + to_string(preRefBil) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQBilAPos(jref, jnum, ref, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMBillPos.ref, TblFmncAMBillPos.bilNum, TblFmncAMBillPos.x1RefFmncMFabuser, TblFmncAMBillPos.x2RefFmncMTool, TblFmncAMBillPos.Quantity, TblFmncAMBillPos.Article, TblFmncAMBillPos.Unitprice, TblFmncAMBillPos.Price";
	sqlstr += " FROM TblFmncAMBillPos";
	sqlstr += " WHERE TblFmncAMBillPos.bilRefFmncMBill = " + to_string(preRefBil) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " ORDER BY bilNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQBilAPos SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCBILAPOSMOD_BILEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefBil, Clstn::VecVJactype::LOCK);
};

void QryFmncBilAPos::refresh_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const ubigint preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMBillPos.x1RefFmncMFabuser = " + to_string(preX1) + "";
	};

	if (preX2 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMBillPos.x2RefFmncMTool = " + to_string(preX2) + "";
	};
};

void QryFmncBilAPos::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncBilAPos::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQBilAPos* rec = NULL;

	dbsfmnc->tblfmncqbilapos->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefFmncMFabuser = StubFmnc::getStubFusStd(dbsfmnc, rec->x1RefFmncMFabuser, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubX2RefFmncMTool = StubFmnc::getStubTolStd(dbsfmnc, rec->x2RefFmncMTool, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncBilAPos", "fetch");
	};

	refreshJnum();
};

uint QryFmncBilAPos::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQBilAPos* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncBilAPos::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQBilAPos* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncBilAPos::handleRequest(
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

bool QryFmncBilAPos::handleRefresh(
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

bool QryFmncBilAPos::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQBilAPos* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tbilNum";
	cout << "\tx1RefFmncMFabuser";
	cout << "\tstubX1RefFmncMFabuser";
	cout << "\tx2RefFmncMTool";
	cout << "\tstubX2RefFmncMTool";
	cout << "\tQuantity";
	cout << "\tArticle";
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
		cout << "\t" << rec->bilNum;
		cout << "\t" << rec->x1RefFmncMFabuser;
		cout << "\t" << rec->stubX1RefFmncMFabuser;
		cout << "\t" << rec->x2RefFmncMTool;
		cout << "\t" << rec->stubX2RefFmncMTool;
		cout << "\t" << rec->Quantity;
		cout << "\t" << rec->Article;
		cout << "\t" << rec->Unitprice;
		cout << "\t" << rec->Price;
		cout << endl;
	};
	return retval;
};

void QryFmncBilAPos::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCBILAPOSMOD_BILEQ) {
		call->abort = handleCallFmncBilAposMod_bilEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncBilAPos::handleCallFmncStubChg(
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

bool QryFmncBilAPos::handleCallFmncBilAposMod_bilEq(
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


