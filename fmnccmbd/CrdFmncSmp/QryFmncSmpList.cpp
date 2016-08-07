/**
  * \file QryFmncSmpList.cpp
  * job handler for job QryFmncSmpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncSmpList.h"

// IP blksInclude --- BEGIN
#include "QryFmncSmpList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncSmpList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncSmpList::QryFmncSmpList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSMPLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCSMPMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncSmpList::~QryFmncSmpList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncSmpList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSMPUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCSMPUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncSmpList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCSMPLIST_SRF, jref);
	ubigint preSup = xchg->getRefPreset(VecFmncVPreset::PREFMNCSMPLIST_SUP, jref);
	ubigint preArt = xchg->getRefPreset(VecFmncVPreset::PREFMNCSMPLIST_ART, jref);
	uint preSte = xchg->getIxPreset(VecFmncVPreset::PREFMNCSMPLIST_STE, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqsmplist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMSample.ref)";
	sqlstr += " FROM TblFmncMSample";
	refresh_filtSQL(sqlstr, preSrf, preSup, preArt, preSte, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQSmpList(jref, jnum, ref, sref, supRefFmncMSample, refFmncMArticle, Material, ixVState)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMSample.ref, TblFmncMSample.sref, TblFmncMSample.supRefFmncMSample, TblFmncMSample.refFmncMArticle, TblFmncMSample.Material, TblFmncMSample.ixVState";
	sqlstr += " FROM TblFmncMSample";
	refresh_filtSQL(sqlstr, preSrf, preSup, preArt, preSte, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQSmpList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncSmpList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preSup
			, const ubigint preArt
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMSample.sref = '" + preSrf + "'";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMSample.supRefFmncMSample = " + to_string(preSup) + "";
	};

	if (preArt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMSample.refFmncMArticle = " + to_string(preArt) + "";
	};

	if (preSte != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMSample.ixVState = " + to_string(preSte) + "";
	};
};

void QryFmncSmpList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncSmpList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMSample.sref ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblFmncMSample.supRefFmncMSample ASC";
	else if (preIxOrd == VecVOrd::ART) sqlstr += " ORDER BY TblFmncMSample.refFmncMArticle ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblFmncMSample.ixVState ASC";
};

void QryFmncSmpList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQSmpList* rec = NULL;

	dbsfmnc->tblfmncqsmplist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubSupRefFmncMSample = StubFmnc::getStubSmpStd(dbsfmnc, rec->supRefFmncMSample, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMArticle = StubFmnc::getStubArtStd(dbsfmnc, rec->refFmncMArticle, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecFmncVMSampleState::getSref(rec->ixVState);
			rec->titIxVState = VecFmncVMSampleState::getTitle(rec->ixVState, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncSmpList", "fetch");
	};

	refreshJnum();
};

uint QryFmncSmpList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQSmpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncSmpList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQSmpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncSmpList::handleRequest(
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

bool QryFmncSmpList::handleRefresh(
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

bool QryFmncSmpList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQSmpList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tsupRefFmncMSample";
	cout << "\tstubSupRefFmncMSample";
	cout << "\trefFmncMArticle";
	cout << "\tstubRefFmncMArticle";
	cout << "\tMaterial";
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
		cout << "\t" << rec->supRefFmncMSample;
		cout << "\t" << rec->stubSupRefFmncMSample;
		cout << "\t" << rec->refFmncMArticle;
		cout << "\t" << rec->stubRefFmncMArticle;
		cout << "\t" << rec->Material;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << endl;
	};
	return retval;
};

void QryFmncSmpList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSMPMOD) {
		call->abort = handleCallFmncSmpMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSMPUPD_REFEQ) {
		call->abort = handleCallFmncSmpUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncSmpList::handleCallFmncStubChg(
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

bool QryFmncSmpList::handleCallFmncSmpMod(
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

bool QryFmncSmpList::handleCallFmncSmpUpd_refEq(
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


