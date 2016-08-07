/**
  * \file QryFmncFusList.cpp
  * job handler for job QryFmncFusList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncFusList.h"

// IP blksInclude --- BEGIN
#include "QryFmncFusList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncFusList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncFusList::QryFmncFusList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCFUSLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCFUSMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncFusList::~QryFmncFusList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncFusList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCFUSUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCFUSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncFusList::refresh(
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
	ubigint prePrs = xchg->getRefPreset(VecFmncVPreset::PREFMNCFUSLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCFUSLIST_SRF, jref);
	ubigint preFab = xchg->getRefPreset(VecFmncVPreset::PREFMNCFUSLIST_FAB, jref);
	ubigint preFpj = xchg->getRefPreset(VecFmncVPreset::PREFMNCFUSLIST_FPJ, jref);
	uint preSte = xchg->getIxPreset(VecFmncVPreset::PREFMNCFUSLIST_STE, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqfuslist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecFmncVPreset::PREFMNCREFFAB) {
		sqlstr = "SELECT COUNT(TblFmncMFabuser.ref)";
		sqlstr += " FROM TblFmncMFabuser";
		sqlstr += " WHERE TblFmncMFabuser.refFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, prePrs, preSrf, preFab, preFpj, preSte, false);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblFmncMFabuser.ref)";
		sqlstr += " FROM TblFmncMFabuser";
		refresh_filtSQL(sqlstr, prePrs, preSrf, preFab, preFpj, preSte, true);
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
		sqlstr += " FROM TblFmncMFabuser";
		sqlstr += " WHERE TblFmncMFabuser.refFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, prePrs, preSrf, preFab, preFpj, preSte, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMFabuser";
		refresh_filtSQL(sqlstr, prePrs, preSrf, preFab, preFpj, preSte, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblFmncQFusList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncFusList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblFmncQFusList(jref, jnum, ref, refFmncMPerson, sref, refFmncMFab, refFmncMFabproject, ixVState)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMFabuser.ref, TblFmncMFabuser.refFmncMPerson, TblFmncMFabuser.sref, TblFmncMFabuser.refFmncMFab, TblFmncMFabuser.refFmncMFabproject, TblFmncMFabuser.ixVState";
};

void QryFmncFusList::refresh_filtSQL(
			string& sqlstr
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preFab
			, const ubigint preFpj
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePrs != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabuser.refFmncMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabuser.sref = '" + preSrf + "'";
	};

	if (preFab != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabuser.refFmncMFab = " + to_string(preFab) + "";
	};

	if (preFpj != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabuser.refFmncMFabproject = " + to_string(preFpj) + "";
	};

	if (preSte != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMFabuser.ixVState = " + to_string(preSte) + "";
	};
};

void QryFmncFusList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncFusList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblFmncMFabuser.refFmncMPerson ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMFabuser.sref ASC";
	else if (preIxOrd == VecVOrd::FAB) sqlstr += " ORDER BY TblFmncMFabuser.refFmncMFab ASC";
	else if (preIxOrd == VecVOrd::FPJ) sqlstr += " ORDER BY TblFmncMFabuser.refFmncMFabproject ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblFmncMFabuser.ixVState ASC";
};

void QryFmncFusList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQFusList* rec = NULL;

	dbsfmnc->tblfmncqfuslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefFmncMPerson = StubFmnc::getStubPrsStd(dbsfmnc, rec->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMFab = StubFmnc::getStubFabStd(dbsfmnc, rec->refFmncMFab, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMFabproject = StubFmnc::getStubFusStd(dbsfmnc, rec->refFmncMFabproject, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecFmncVMFabuserState::getSref(rec->ixVState);
			rec->titIxVState = VecFmncVMFabuserState::getTitle(rec->ixVState, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncFusList", "fetch");
	};

	refreshJnum();
};

uint QryFmncFusList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQFusList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncFusList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQFusList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncFusList::handleRequest(
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

bool QryFmncFusList::handleRefresh(
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

bool QryFmncFusList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQFusList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefFmncMPerson";
	cout << "\tstubRefFmncMPerson";
	cout << "\tsref";
	cout << "\trefFmncMFab";
	cout << "\tstubRefFmncMFab";
	cout << "\trefFmncMFabproject";
	cout << "\tstubRefFmncMFabproject";
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
		cout << "\t" << rec->refFmncMPerson;
		cout << "\t" << rec->stubRefFmncMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refFmncMFab;
		cout << "\t" << rec->stubRefFmncMFab;
		cout << "\t" << rec->refFmncMFabproject;
		cout << "\t" << rec->stubRefFmncMFabproject;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << endl;
	};
	return retval;
};

void QryFmncFusList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFUSMOD) {
		call->abort = handleCallFmncFusMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFUSUPD_REFEQ) {
		call->abort = handleCallFmncFusUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncFusList::handleCallFmncStubChg(
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

bool QryFmncFusList::handleCallFmncFusMod(
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

bool QryFmncFusList::handleCallFmncFusUpd_refEq(
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


