/**
  * \file QryFmncUsrList.cpp
  * job handler for job QryFmncUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncUsrList.h"

// IP blksInclude --- BEGIN
#include "QryFmncUsrList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncUsrList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncUsrList::QryFmncUsrList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCUSRLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncUsrList::~QryFmncUsrList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCUSRUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncUsrList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	ubigint prePrs = xchg->getRefPreset(VecFmncVPreset::PREFMNCUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecFmncVPreset::PREFMNCUSRLIST_USG, jref);
	uint preSte = xchg->getIxPreset(VecFmncVPreset::PREFMNCUSRLIST_STE, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMUser.ref)";
	sqlstr += " FROM TblFmncMUser";
	refresh_filtSQL(sqlstr, prePrs, preSrf, preUsg, preSte, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQUsrList(jref, jnum, ref, refFmncMPerson, sref, refFmncMUsergroup, ixVState, ixFmncVLocale, ixFmncVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMUser.ref, TblFmncMUser.refFmncMPerson, TblFmncMUser.sref, TblFmncMUser.refFmncMUsergroup, TblFmncMUser.ixVState, TblFmncMUser.ixFmncVLocale, TblFmncMUser.ixFmncVUserlevel";
	sqlstr += " FROM TblFmncMUser";
	refresh_filtSQL(sqlstr, prePrs, preSrf, preUsg, preSte, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncUsrList::refresh_filtSQL(
			string& sqlstr
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePrs != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMUser.refFmncMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMUser.refFmncMUsergroup = " + to_string(preUsg) + "";
	};

	if (preSte != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMUser.ixVState = " + to_string(preSte) + "";
	};
};

void QryFmncUsrList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncUsrList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblFmncMUser.refFmncMPerson ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMUser.sref ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblFmncMUser.refFmncMUsergroup ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblFmncMUser.ixVState ASC";
};

void QryFmncUsrList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQUsrList* rec = NULL;

	dbsfmnc->tblfmncqusrlist->loadRstByJref(jref, false, rst);
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
			rec->stubRefFmncMUsergroup = StubFmnc::getStubUsgStd(dbsfmnc, rec->refFmncMUsergroup, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecFmncVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecFmncVMUserState::getTitle(rec->ixVState, ixFmncVLocale);
			rec->srefIxFmncVLocale = VecFmncVLocale::getSref(rec->ixFmncVLocale);
			rec->titIxFmncVLocale = VecFmncVLocale::getTitle(rec->ixFmncVLocale, ixFmncVLocale);
			rec->srefIxFmncVUserlevel = VecFmncVUserlevel::getSref(rec->ixFmncVUserlevel);
			rec->titIxFmncVUserlevel = VecFmncVUserlevel::getTitle(rec->ixFmncVUserlevel, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncUsrList", "fetch");
	};

	refreshJnum();
};

uint QryFmncUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQUsrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncUsrList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQUsrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncUsrList::handleRequest(
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

bool QryFmncUsrList::handleRefresh(
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

bool QryFmncUsrList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefFmncMPerson";
	cout << "\tstubRefFmncMPerson";
	cout << "\tsref";
	cout << "\trefFmncMUsergroup";
	cout << "\tstubRefFmncMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixFmncVLocale";
	cout << "\tsrefIxFmncVLocale";
	cout << "\ttitIxFmncVLocale";
	cout << "\tixFmncVUserlevel";
	cout << "\tsrefIxFmncVUserlevel";
	cout << "\ttitIxFmncVUserlevel";
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
		cout << "\t" << rec->refFmncMUsergroup;
		cout << "\t" << rec->stubRefFmncMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixFmncVLocale;
		cout << "\t" << rec->srefIxFmncVLocale;
		cout << "\t" << rec->titIxFmncVLocale;
		cout << "\t" << rec->ixFmncVUserlevel;
		cout << "\t" << rec->srefIxFmncVUserlevel;
		cout << "\t" << rec->titIxFmncVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryFmncUsrList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSRMOD) {
		call->abort = handleCallFmncUsrMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSRUPD_REFEQ) {
		call->abort = handleCallFmncUsrUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncUsrList::handleCallFmncStubChg(
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

bool QryFmncUsrList::handleCallFmncUsrMod(
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

bool QryFmncUsrList::handleCallFmncUsrUpd_refEq(
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


