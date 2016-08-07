/**
  * \file QryFmncFpjList.cpp
  * job handler for job QryFmncFpjList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncFpjList.h"

// IP blksInclude --- BEGIN
#include "QryFmncFpjList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncFpjList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncFpjList::QryFmncFpjList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCFPJLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCFPJMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncFpjList::~QryFmncFpjList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncFpjList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCFPJUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCFPJUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncFpjList::refresh(
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
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCFPJLIST_SRF, jref);
	ubigint preFab = xchg->getRefPreset(VecFmncVPreset::PREFMNCFPJLIST_FAB, jref);
	ubigint preBio = xchg->getRefPreset(VecFmncVPreset::PREFMNCFPJLIST_BIO, jref);
	uint preSte = xchg->getIxPreset(VecFmncVPreset::PREFMNCFPJLIST_STE, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqfpjlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecFmncVPreset::PREFMNCREFFAB) {
		sqlstr = "SELECT COUNT(TblFmncMFabproject.ref)";
		sqlstr += " FROM TblFmncMFabproject";
		sqlstr += " WHERE TblFmncMFabproject.refFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, preSrf, preFab, preBio, preSte, false);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblFmncMFabproject.ref)";
		sqlstr += " FROM TblFmncMFabproject";
		refresh_filtSQL(sqlstr, preSrf, preFab, preBio, preSte, true);
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
		sqlstr += " FROM TblFmncMFabproject";
		sqlstr += " WHERE TblFmncMFabproject.refFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, preSrf, preFab, preBio, preSte, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMFabproject";
		refresh_filtSQL(sqlstr, preSrf, preFab, preBio, preSte, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblFmncQFpjList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncFpjList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblFmncQFpjList(jref, jnum, ref, sref, Title, refFmncMFab, bioRefFmncMOrg, ixVState)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMFabproject.ref, TblFmncMFabproject.sref, TblFmncMFabproject.Title, TblFmncMFabproject.refFmncMFab, TblFmncMFabproject.bioRefFmncMOrg, TblFmncMFabproject.ixVState";
};

void QryFmncFpjList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preFab
			, const ubigint preBio
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabproject.sref = '" + preSrf + "'";
	};

	if (preFab != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabproject.refFmncMFab = " + to_string(preFab) + "";
	};

	if (preBio != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabproject.bioRefFmncMOrg = " + to_string(preBio) + "";
	};

	if (preSte != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabproject.ixVState = " + to_string(preSte) + "";
	};
};

void QryFmncFpjList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncFpjList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMFabproject.sref ASC";
	else if (preIxOrd == VecVOrd::FAB) sqlstr += " ORDER BY TblFmncMFabproject.refFmncMFab ASC";
	else if (preIxOrd == VecVOrd::BIO) sqlstr += " ORDER BY TblFmncMFabproject.bioRefFmncMOrg ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblFmncMFabproject.ixVState ASC";
};

void QryFmncFpjList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQFpjList* rec = NULL;

	dbsfmnc->tblfmncqfpjlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefFmncMFab = StubFmnc::getStubFabStd(dbsfmnc, rec->refFmncMFab, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubBioRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->bioRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecFmncVMFabprojectState::getSref(rec->ixVState);
			rec->titIxVState = VecFmncVMFabprojectState::getTitle(rec->ixVState, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncFpjList", "fetch");
	};

	refreshJnum();
};

uint QryFmncFpjList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQFpjList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncFpjList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQFpjList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncFpjList::handleRequest(
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

bool QryFmncFpjList::handleRefresh(
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

bool QryFmncFpjList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQFpjList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\trefFmncMFab";
	cout << "\tstubRefFmncMFab";
	cout << "\tbioRefFmncMOrg";
	cout << "\tstubBioRefFmncMOrg";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->refFmncMFab;
		cout << "\t" << rec->stubRefFmncMFab;
		cout << "\t" << rec->bioRefFmncMOrg;
		cout << "\t" << rec->stubBioRefFmncMOrg;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << endl;
	};
	return retval;
};

void QryFmncFpjList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFPJMOD) {
		call->abort = handleCallFmncFpjMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFPJUPD_REFEQ) {
		call->abort = handleCallFmncFpjUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncFpjList::handleCallFmncStubChg(
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

bool QryFmncFpjList::handleCallFmncFpjMod(
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

bool QryFmncFpjList::handleCallFmncFpjUpd_refEq(
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


