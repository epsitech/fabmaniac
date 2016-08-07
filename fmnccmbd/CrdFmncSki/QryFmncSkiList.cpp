/**
  * \file QryFmncSkiList.cpp
  * job handler for job QryFmncSkiList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncSkiList.h"

// IP blksInclude --- BEGIN
#include "QryFmncSkiList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncSkiList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncSkiList::QryFmncSkiList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSKILIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCSKIMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncSkiList::~QryFmncSkiList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncSkiList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSKIUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCSKIUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncSkiList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	ubigint preOrg = xchg->getRefPreset(VecFmncVPreset::PREFMNCSKILIST_ORG, jref);
	ubigint preArt = xchg->getRefPreset(VecFmncVPreset::PREFMNCSKILIST_ART, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqskilist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMStockitem.ref)";
	sqlstr += " FROM TblFmncMStockitem";
	refresh_filtSQL(sqlstr, preOrg, preArt, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQSkiList(jref, jnum, ref, refFmncMOrg, refFmncMArticle, Quantity, osrefFmncKStocklcn, Expdate)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMStockitem.ref, TblFmncMStockitem.refFmncMOrg, TblFmncMStockitem.refFmncMArticle, TblFmncMStockitem.Quantity, TblFmncMStockitem.osrefFmncKStocklcn, TblFmncMStockitem.Expdate";
	sqlstr += " FROM TblFmncMStockitem";
	refresh_filtSQL(sqlstr, preOrg, preArt, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQSkiList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncSkiList::refresh_filtSQL(
			string& sqlstr
			, const ubigint preOrg
			, const ubigint preArt
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preOrg != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStockitem.refFmncMOrg = " + to_string(preOrg) + "";
	};

	if (preArt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStockitem.refFmncMArticle = " + to_string(preArt) + "";
	};
};

void QryFmncSkiList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncSkiList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::ORG) sqlstr += " ORDER BY TblFmncMStockitem.refFmncMOrg ASC";
	else if (preIxOrd == VecVOrd::ART) sqlstr += " ORDER BY TblFmncMStockitem.refFmncMArticle ASC";
};

void QryFmncSkiList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQSkiList* rec = NULL;

	dbsfmnc->tblfmncqskilist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMArticle = StubFmnc::getStubArtStd(dbsfmnc, rec->refFmncMArticle, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titOsrefFmncKStocklcn = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKSTOCKLCN, rec->osrefFmncKStocklcn, ixFmncVLocale);
			rec->ftmExpdate = Ftm::date(rec->Expdate);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncSkiList", "fetch");
	};

	refreshJnum();
};

uint QryFmncSkiList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQSkiList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncSkiList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQSkiList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncSkiList::handleRequest(
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

bool QryFmncSkiList::handleRefresh(
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

bool QryFmncSkiList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQSkiList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefFmncMOrg";
	cout << "\tstubRefFmncMOrg";
	cout << "\trefFmncMArticle";
	cout << "\tstubRefFmncMArticle";
	cout << "\tQuantity";
	cout << "\tosrefFmncKStocklcn";
	cout << "\ttitOsrefFmncKStocklcn";
	cout << "\tExpdate";
	cout << "\tftmExpdate";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refFmncMOrg;
		cout << "\t" << rec->stubRefFmncMOrg;
		cout << "\t" << rec->refFmncMArticle;
		cout << "\t" << rec->stubRefFmncMArticle;
		cout << "\t" << rec->Quantity;
		cout << "\t" << rec->osrefFmncKStocklcn;
		cout << "\t" << rec->titOsrefFmncKStocklcn;
		cout << "\t" << rec->Expdate;
		cout << "\t" << rec->ftmExpdate;
		cout << endl;
	};
	return retval;
};

void QryFmncSkiList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSKIMOD) {
		call->abort = handleCallFmncSkiMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSKIUPD_REFEQ) {
		call->abort = handleCallFmncSkiUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncSkiList::handleCallFmncStubChg(
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

bool QryFmncSkiList::handleCallFmncSkiMod(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixFmncVQrystate == VecFmncVQrystate::UTD) || (ixFmncVQrystate == VecFmncVQrystate::SLM)) {
		ixFmncVQrystate = VecFmncVQrystate::MNR;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};

bool QryFmncSkiList::handleCallFmncSkiUpd_refEq(
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


