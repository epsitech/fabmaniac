/**
  * \file QryFmncTtyList.cpp
  * job handler for job QryFmncTtyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTtyList.h"

// IP blksInclude --- BEGIN
#include "QryFmncTtyList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTtyList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTtyList::QryFmncTtyList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTTYLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCTTYMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncTtyList::~QryFmncTtyList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTtyList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTTYUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCTTYUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncTtyList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecFmncVPreset::PREFMNCTTYLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecFmncVPreset::PREFMNCTTYLIST_TIT, jref);
	ubigint preSup = xchg->getRefPreset(VecFmncVPreset::PREFMNCTTYLIST_SUP, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqttylist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMTooltype.ref)";
	sqlstr += " FROM TblFmncMTooltype";
	refresh_filtSQL(sqlstr, preSrf, preTit, preSup, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTtyList(jref, jnum, ref, sref, Title, supRefFmncMTooltype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMTooltype.ref, TblFmncMTooltype.sref, TblFmncMTooltype.Title, TblFmncMTooltype.supRefFmncMTooltype";
	sqlstr += " FROM TblFmncMTooltype";
	refresh_filtSQL(sqlstr, preSrf, preTit, preSup, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTtyList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncTtyList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preTit
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMTooltype.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMTooltype.Title LIKE '" + preTit + "'";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMTooltype.supRefFmncMTooltype = " + to_string(preSup) + "";
	};
};

void QryFmncTtyList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncTtyList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblFmncMTooltype.sref ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblFmncMTooltype.Title ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblFmncMTooltype.supRefFmncMTooltype ASC";
};

void QryFmncTtyList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTtyList* rec = NULL;

	dbsfmnc->tblfmncqttylist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubSupRefFmncMTooltype = StubFmnc::getStubTtyStd(dbsfmnc, rec->supRefFmncMTooltype, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTtyList", "fetch");
	};

	refreshJnum();
};

uint QryFmncTtyList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTtyList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTtyList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTtyList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTtyList::handleRequest(
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

bool QryFmncTtyList::handleRefresh(
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

bool QryFmncTtyList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTtyList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tsupRefFmncMTooltype";
	cout << "\tstubSupRefFmncMTooltype";
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
		cout << "\t" << rec->supRefFmncMTooltype;
		cout << "\t" << rec->stubSupRefFmncMTooltype;
		cout << endl;
	};
	return retval;
};

void QryFmncTtyList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTTYMOD) {
		call->abort = handleCallFmncTtyMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTTYUPD_REFEQ) {
		call->abort = handleCallFmncTtyUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTtyList::handleCallFmncStubChg(
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

bool QryFmncTtyList::handleCallFmncTtyMod(
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

bool QryFmncTtyList::handleCallFmncTtyUpd_refEq(
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


