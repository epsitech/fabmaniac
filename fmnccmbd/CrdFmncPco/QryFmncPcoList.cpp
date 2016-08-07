/**
  * \file QryFmncPcoList.cpp
  * job handler for job QryFmncPcoList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncPcoList.h"

// IP blksInclude --- BEGIN
#include "QryFmncPcoList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncPcoList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncPcoList::QryFmncPcoList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCPCOLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCPCOMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncPcoList::~QryFmncPcoList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncPcoList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCPCOUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCPCOUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncPcoList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCPCOLIST_SRF, jref);
	int preDat = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCPCOLIST_DAT, jref);
	ubigint prePco = xchg->getRefPreset(VecFmncVPreset::PREFMNCPCOLIST_PCO, jref);
	ubigint preSpl = xchg->getRefPreset(VecFmncVPreset::PREFMNCPCOLIST_SPL, jref);
	ubigint preFil = xchg->getRefPreset(VecFmncVPreset::PREFMNCPCOLIST_FIL, jref);
	uint preSte = xchg->getIxPreset(VecFmncVPreset::PREFMNCPCOLIST_STE, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqpcolist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMPurchorder.ref)";
	sqlstr += " FROM TblFmncMPurchorder";
	refresh_filtSQL(sqlstr, preSrf, preDat, prePco, preSpl, preFil, preSte, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQPcoList(jref, jnum, ref, sref, Date, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, ixVState, Amount)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMPurchorder.ref, TblFmncMPurchorder.sref, TblFmncMPurchorder.Date, TblFmncMPurchorder.pcoRefFmncMOrg, TblFmncMPurchorder.splRefFmncMOrg, TblFmncMPurchorder.refFmncMFile, TblFmncMPurchorder.ixVState, TblFmncMPurchorder.Amount";
	sqlstr += " FROM TblFmncMPurchorder";
	refresh_filtSQL(sqlstr, preSrf, preDat, prePco, preSpl, preFil, preSte, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQPcoList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncPcoList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const int preDat
			, const ubigint prePco
			, const ubigint preSpl
			, const ubigint preFil
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPurchorder.sref = '" + preSrf + "'";
	};

	if (preDat != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPurchorder.Date = " + to_string(preDat) + "";
	};

	if (prePco != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPurchorder.pcoRefFmncMOrg = " + to_string(prePco) + "";
	};

	if (preSpl != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPurchorder.splRefFmncMOrg = " + to_string(preSpl) + "";
	};

	if (preFil != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPurchorder.refFmncMFile = " + to_string(preFil) + "";
	};

	if (preSte != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPurchorder.ixVState = " + to_string(preSte) + "";
	};
};

void QryFmncPcoList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncPcoList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMPurchorder.sref ASC";
	else if (preIxOrd == VecVOrd::DAT) sqlstr += " ORDER BY TblFmncMPurchorder.Date ASC";
	else if (preIxOrd == VecVOrd::PCO) sqlstr += " ORDER BY TblFmncMPurchorder.pcoRefFmncMOrg ASC";
	else if (preIxOrd == VecVOrd::SPL) sqlstr += " ORDER BY TblFmncMPurchorder.splRefFmncMOrg ASC";
	else if (preIxOrd == VecVOrd::FIL) sqlstr += " ORDER BY TblFmncMPurchorder.refFmncMFile ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblFmncMPurchorder.ixVState ASC";
};

void QryFmncPcoList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQPcoList* rec = NULL;

	dbsfmnc->tblfmncqpcolist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->ftmDate = Ftm::date(rec->Date);
			rec->stubPcoRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->pcoRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSplRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->splRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMFile = StubFmnc::getStubFilStd(dbsfmnc, rec->refFmncMFile, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecFmncVMPurchorderState::getSref(rec->ixVState);
			rec->titIxVState = VecFmncVMPurchorderState::getTitle(rec->ixVState, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncPcoList", "fetch");
	};

	refreshJnum();
};

uint QryFmncPcoList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQPcoList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncPcoList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQPcoList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncPcoList::handleRequest(
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

bool QryFmncPcoList::handleRefresh(
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

bool QryFmncPcoList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQPcoList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tDate";
	cout << "\tftmDate";
	cout << "\tpcoRefFmncMOrg";
	cout << "\tstubPcoRefFmncMOrg";
	cout << "\tsplRefFmncMOrg";
	cout << "\tstubSplRefFmncMOrg";
	cout << "\trefFmncMFile";
	cout << "\tstubRefFmncMFile";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tAmount";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Date;
		cout << "\t" << rec->ftmDate;
		cout << "\t" << rec->pcoRefFmncMOrg;
		cout << "\t" << rec->stubPcoRefFmncMOrg;
		cout << "\t" << rec->splRefFmncMOrg;
		cout << "\t" << rec->stubSplRefFmncMOrg;
		cout << "\t" << rec->refFmncMFile;
		cout << "\t" << rec->stubRefFmncMFile;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->Amount;
		cout << endl;
	};
	return retval;
};

void QryFmncPcoList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPCOMOD) {
		call->abort = handleCallFmncPcoMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPCOUPD_REFEQ) {
		call->abort = handleCallFmncPcoUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncPcoList::handleCallFmncStubChg(
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

bool QryFmncPcoList::handleCallFmncPcoMod(
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

bool QryFmncPcoList::handleCallFmncPcoUpd_refEq(
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


