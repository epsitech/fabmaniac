/**
  * \file QryFmncArtList.cpp
  * job handler for job QryFmncArtList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncArtList.h"

// IP blksInclude --- BEGIN
#include "QryFmncArtList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncArtList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncArtList::QryFmncArtList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCARTLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCARTMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncArtList::~QryFmncArtList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncArtList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCARTUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCARTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncArtList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCARTLIST_SRF, jref);
	ubigint preOrg = xchg->getRefPreset(VecFmncVPreset::PREFMNCARTLIST_ORG, jref);
	ubigint preTol = xchg->getRefPreset(VecFmncVPreset::PREFMNCARTLIST_TOL, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqartlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMArticle.ref)";
	sqlstr += " FROM TblFmncMArticle";
	refresh_filtSQL(sqlstr, preSrf, preOrg, preTol, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQArtList(jref, jnum, ref, sref, Title, refFmncMOrg, refFmncMTool, srefKType)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMArticle.ref, TblFmncMArticle.sref, TblFmncMArticle.Title, TblFmncMArticle.refFmncMOrg, TblFmncMArticle.refFmncMTool, TblFmncMArticle.srefKType";
	sqlstr += " FROM TblFmncMArticle";
	refresh_filtSQL(sqlstr, preSrf, preOrg, preTol, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQArtList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncArtList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preOrg
			, const ubigint preTol
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMArticle.sref = '" + preSrf + "'";
	};

	if (preOrg != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMArticle.refFmncMOrg = " + to_string(preOrg) + "";
	};

	if (preTol != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMArticle.refFmncMTool = " + to_string(preTol) + "";
	};
};

void QryFmncArtList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncArtList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMArticle.sref ASC";
	else if (preIxOrd == VecVOrd::ORG) sqlstr += " ORDER BY TblFmncMArticle.refFmncMOrg ASC";
	else if (preIxOrd == VecVOrd::TOL) sqlstr += " ORDER BY TblFmncMArticle.refFmncMTool ASC";
};

void QryFmncArtList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQArtList* rec = NULL;

	dbsfmnc->tblfmncqartlist->loadRstByJref(jref, false, rst);
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
			rec->stubRefFmncMTool = StubFmnc::getStubTolStd(dbsfmnc, rec->refFmncMTool, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefKType = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKMARTICLETYPE, rec->srefKType, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncArtList", "fetch");
	};

	refreshJnum();
};

uint QryFmncArtList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQArtList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncArtList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQArtList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncArtList::handleRequest(
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

bool QryFmncArtList::handleRefresh(
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

bool QryFmncArtList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQArtList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\trefFmncMOrg";
	cout << "\tstubRefFmncMOrg";
	cout << "\trefFmncMTool";
	cout << "\tstubRefFmncMTool";
	cout << "\tsrefKType";
	cout << "\ttitSrefKType";
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
		cout << "\t" << rec->refFmncMOrg;
		cout << "\t" << rec->stubRefFmncMOrg;
		cout << "\t" << rec->refFmncMTool;
		cout << "\t" << rec->stubRefFmncMTool;
		cout << "\t" << rec->srefKType;
		cout << "\t" << rec->titSrefKType;
		cout << endl;
	};
	return retval;
};

void QryFmncArtList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCARTMOD) {
		call->abort = handleCallFmncArtMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCARTUPD_REFEQ) {
		call->abort = handleCallFmncArtUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncArtList::handleCallFmncStubChg(
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

bool QryFmncArtList::handleCallFmncArtMod(
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

bool QryFmncArtList::handleCallFmncArtUpd_refEq(
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


