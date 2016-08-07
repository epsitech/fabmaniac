/**
  * \file QryFmncOrgList.cpp
  * job handler for job QryFmncOrgList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncOrgList.h"

// IP blksInclude --- BEGIN
#include "QryFmncOrgList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncOrgList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncOrgList::QryFmncOrgList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCORGLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCORGMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncOrgList::~QryFmncOrgList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncOrgList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCORGUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCORGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncOrgList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCORGLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecFmncVPreset::PREFMNCORGLIST_TIT, jref);
	uint preDrv = xchg->getIxPreset(VecFmncVPreset::PREFMNCORGLIST_DRV, jref);
	ubigint preAdr = xchg->getRefPreset(VecFmncVPreset::PREFMNCORGLIST_ADR, jref);
	ubigint preSup = xchg->getRefPreset(VecFmncVPreset::PREFMNCORGLIST_SUP, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqorglist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMOrg.ref)";
	sqlstr += " FROM TblFmncMOrg";
	refresh_filtSQL(sqlstr, preSrf, preTit, preDrv, preAdr, preSup, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQOrgList(jref, jnum, ref, sref, Title, ixWDerivate, refFmncMAddress, supRefFmncMOrg, Tel, Eml)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMOrg.ref, TblFmncMOrg.sref, TblFmncMOrg.Title, TblFmncMOrg.ixWDerivate, TblFmncMOrg.refFmncMAddress, TblFmncMOrg.supRefFmncMOrg, TblFmncMOrg.Tel, TblFmncMOrg.Eml";
	sqlstr += " FROM TblFmncMOrg";
	refresh_filtSQL(sqlstr, preSrf, preTit, preDrv, preAdr, preSup, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQOrgList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncOrgList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preTit
			, const uint preDrv
			, const ubigint preAdr
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMOrg.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMOrg.Title LIKE '" + preTit + "'";
	};

	if (preDrv != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "(TblFmncMOrg.ixWDerivate & " + to_string(preDrv) + ") <> 0";
	};

	if (preAdr != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMOrg.refFmncMAddress = " + to_string(preAdr) + "";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMOrg.supRefFmncMOrg = " + to_string(preSup) + "";
	};
};

void QryFmncOrgList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncOrgList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMOrg.sref ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblFmncMOrg.Title ASC";
	else if (preIxOrd == VecVOrd::DRV) sqlstr += " ORDER BY TblFmncMOrg.ixWDerivate ASC";
	else if (preIxOrd == VecVOrd::ADR) sqlstr += " ORDER BY TblFmncMOrg.refFmncMAddress ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblFmncMOrg.supRefFmncMOrg ASC";
};

void QryFmncOrgList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQOrgList* rec = NULL;

	dbsfmnc->tblfmncqorglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefsIxWDerivate = VecFmncWMOrgDerivate::getSrefs(rec->ixWDerivate);
			rec->stubRefFmncMAddress = StubFmnc::getStubAdrStd(dbsfmnc, rec->refFmncMAddress, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->supRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncOrgList", "fetch");
	};

	refreshJnum();
};

uint QryFmncOrgList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQOrgList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncOrgList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQOrgList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncOrgList::handleRequest(
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

bool QryFmncOrgList::handleRefresh(
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

bool QryFmncOrgList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQOrgList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tixWDerivate";
	cout << "\tsrefsIxWDerivate";
	cout << "\ttitsIxWDerivate";
	cout << "\trefFmncMAddress";
	cout << "\tstubRefFmncMAddress";
	cout << "\tsupRefFmncMOrg";
	cout << "\tstubSupRefFmncMOrg";
	cout << "\tTel";
	cout << "\tEml";
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
		cout << "\t" << rec->ixWDerivate;
		cout << "\t" << rec->srefsIxWDerivate;
		cout << "\t" << rec->titsIxWDerivate;
		cout << "\t" << rec->refFmncMAddress;
		cout << "\t" << rec->stubRefFmncMAddress;
		cout << "\t" << rec->supRefFmncMOrg;
		cout << "\t" << rec->stubSupRefFmncMOrg;
		cout << "\t" << rec->Tel;
		cout << "\t" << rec->Eml;
		cout << endl;
	};
	return retval;
};

void QryFmncOrgList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCORGMOD) {
		call->abort = handleCallFmncOrgMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCORGUPD_REFEQ) {
		call->abort = handleCallFmncOrgUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncOrgList::handleCallFmncStubChg(
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

bool QryFmncOrgList::handleCallFmncOrgMod(
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

bool QryFmncOrgList::handleCallFmncOrgUpd_refEq(
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


