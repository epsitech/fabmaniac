/**
  * \file QryFmncBilList.cpp
  * job handler for job QryFmncBilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncBilList.h"

// IP blksInclude --- BEGIN
#include "QryFmncBilList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncBilList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncBilList::QryFmncBilList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCBILLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCBILMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncBilList::~QryFmncBilList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncBilList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCBILUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCBILUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncBilList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	ubigint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	ubigint preRefFab = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCBILLIST_SRF, jref);
	int preDat = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCBILLIST_DAT, jref);
	ubigint prePrj = xchg->getRefPreset(VecFmncVPreset::PREFMNCBILLIST_PRJ, jref);
	ubigint preFil = xchg->getRefPreset(VecFmncVPreset::PREFMNCBILLIST_FIL, jref);
	uint preSte = xchg->getIxPreset(VecFmncVPreset::PREFMNCBILLIST_STE, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqbillist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecFmncVPreset::PREFMNCREFFAB) {
		sqlstr = "SELECT COUNT(TblFmncMBill.ref)";
		sqlstr += " FROM TblFmncMBill, TblFmncMFabproject";
		sqlstr += " WHERE TblFmncMBill.refFmncMFabproject = TblFmncMFabproject.ref";
		sqlstr += " AND TblFmncMFabproject.refFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, preSrf, preDat, prePrj, preFil, preSte, false);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblFmncMBill.ref)";
		sqlstr += " FROM TblFmncMBill";
		refresh_filtSQL(sqlstr, preSrf, preDat, prePrj, preFil, preSte, true);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i=0;i<cnts.size();i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecFmncVPreset::PREFMNCREFFAB) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMBill, TblFmncMFabproject";
		sqlstr += " WHERE TblFmncMBill.refFmncMFabproject = TblFmncMFabproject.ref";
		sqlstr += " AND TblFmncMFabproject.refFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, preSrf, preDat, prePrj, preFil, preSte, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMBill";
		refresh_filtSQL(sqlstr, preSrf, preDat, prePrj, preFil, preSte, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblFmncQBilList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncBilList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblFmncQBilList(jref, jnum, ref, sref, Date, refFmncMFabproject, refFmncMFile, ixVState, Prdstart, Prdstop, Amount)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMBill.ref, TblFmncMBill.sref, TblFmncMBill.Date, TblFmncMBill.refFmncMFabproject, TblFmncMBill.refFmncMFile, TblFmncMBill.ixVState, TblFmncMBill.Prdstart, TblFmncMBill.Prdstop, TblFmncMBill.Amount";
};

void QryFmncBilList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const int preDat
			, const ubigint prePrj
			, const ubigint preFil
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMBill.sref = '" + preSrf + "'";
	};

	if (preDat != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMBill.Date = " + to_string(preDat) + "";
	};

	if (prePrj != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMBill.refFmncMFabproject = " + to_string(prePrj) + "";
	};

	if (preFil != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMBill.refFmncMFile = " + to_string(preFil) + "";
	};

	if (preSte != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMBill.ixVState = " + to_string(preSte) + "";
	};
};

void QryFmncBilList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncBilList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMBill.sref ASC";
	else if (preIxOrd == VecVOrd::DAT) sqlstr += " ORDER BY TblFmncMBill.Date ASC";
	else if (preIxOrd == VecVOrd::PRJ) sqlstr += " ORDER BY TblFmncMBill.refFmncMFabproject ASC";
	else if (preIxOrd == VecVOrd::FIL) sqlstr += " ORDER BY TblFmncMBill.refFmncMFile ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblFmncMBill.ixVState ASC";
};

void QryFmncBilList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQBilList* rec = NULL;

	dbsfmnc->tblfmncqbillist->loadRstByJref(jref, false, rst);
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
			rec->stubRefFmncMFabproject = StubFmnc::getStubFpjStd(dbsfmnc, rec->refFmncMFabproject, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMFile = StubFmnc::getStubFilStd(dbsfmnc, rec->refFmncMFile, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecFmncVMBillState::getSref(rec->ixVState);
			rec->titIxVState = VecFmncVMBillState::getTitle(rec->ixVState, ixFmncVLocale);
			rec->ftmPrdstart = Ftm::date(rec->Prdstart);
			rec->ftmPrdstop = Ftm::date(rec->Prdstop);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncBilList", "fetch");
	};

	refreshJnum();
};

uint QryFmncBilList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQBilList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncBilList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQBilList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncBilList::handleRequest(
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

bool QryFmncBilList::handleRefresh(
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

bool QryFmncBilList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQBilList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tDate";
	cout << "\tftmDate";
	cout << "\trefFmncMFabproject";
	cout << "\tstubRefFmncMFabproject";
	cout << "\trefFmncMFile";
	cout << "\tstubRefFmncMFile";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tPrdstart";
	cout << "\tftmPrdstart";
	cout << "\tPrdstop";
	cout << "\tftmPrdstop";
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
		cout << "\t" << rec->refFmncMFabproject;
		cout << "\t" << rec->stubRefFmncMFabproject;
		cout << "\t" << rec->refFmncMFile;
		cout << "\t" << rec->stubRefFmncMFile;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->Prdstart;
		cout << "\t" << rec->ftmPrdstart;
		cout << "\t" << rec->Prdstop;
		cout << "\t" << rec->ftmPrdstop;
		cout << "\t" << rec->Amount;
		cout << endl;
	};
	return retval;
};

void QryFmncBilList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCBILMOD) {
		call->abort = handleCallFmncBilMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCBILUPD_REFEQ) {
		call->abort = handleCallFmncBilUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncBilList::handleCallFmncStubChg(
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

bool QryFmncBilList::handleCallFmncBilMod(
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

bool QryFmncBilList::handleCallFmncBilUpd_refEq(
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


