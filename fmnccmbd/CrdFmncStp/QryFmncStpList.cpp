/**
  * \file QryFmncStpList.cpp
  * job handler for job QryFmncStpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncStpList.h"

// IP blksInclude --- BEGIN
#include "QryFmncStpList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncStpList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncStpList::QryFmncStpList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSTPLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCSTEMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncStpList::~QryFmncStpList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncStpList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSTEUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCSTEUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncStpList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	ubigint preAct = xchg->getRefPreset(VecFmncVPreset::PREFMNCSTPLIST_ACT, jref);
	uint preRlt = xchg->getIxPreset(VecFmncVPreset::PREFMNCSTPLIST_RLT, jref);
	ubigint preRlu = xchg->getRefPreset(VecFmncVPreset::PREFMNCSTPLIST_RLU, jref);
	ubigint preStp = xchg->getRefPreset(VecFmncVPreset::PREFMNCSTPLIST_STP, jref);
	int preSta = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCSTPLIST_STA, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqstplist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMStep.ref)";
	sqlstr += " FROM TblFmncMStep";
	sqlstr += " WHERE refFmncMActivity = 0";
	refresh_filtSQL(sqlstr, preAct, preRlt, preRlu, preStp, preSta, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQStpList(jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMStep.ref, TblFmncMStep.Title, TblFmncMStep.refFmncMActivity, TblFmncMStep.rlvIxVTbl, TblFmncMStep.rlvUref, TblFmncMStep.tplRefFmncMStep, TblFmncMStep.start";
	sqlstr += " FROM TblFmncMStep";
	sqlstr += " WHERE refFmncMActivity = 0";
	refresh_filtSQL(sqlstr, preAct, preRlt, preRlu, preStp, preSta, false);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQStpList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncStpList::refresh_filtSQL(
			string& sqlstr
			, const ubigint preAct
			, const uint preRlt
			, const ubigint preRlu
			, const ubigint preStp
			, const int preSta
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preAct != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStep.refFmncMActivity = " + to_string(preAct) + "";
	};

	if (preRlt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStep.rlvIxVTbl = " + to_string(preRlt) + "";
	};

	if (preRlu != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStep.rlvUref = " + to_string(preRlu) + "";
	};

	if (preStp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStep.tplRefFmncMStep = " + to_string(preStp) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMStep.start = " + to_string(preSta) + "";
	};
};

void QryFmncStpList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncStpList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::ACT) sqlstr += " ORDER BY TblFmncMStep.refFmncMActivity ASC";
	else if (preIxOrd == VecVOrd::RLT) sqlstr += " ORDER BY TblFmncMStep.rlvIxVTbl ASC";
	else if (preIxOrd == VecVOrd::RLU) sqlstr += " ORDER BY TblFmncMStep.rlvUref ASC";
	else if (preIxOrd == VecVOrd::STP) sqlstr += " ORDER BY TblFmncMStep.tplRefFmncMStep ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblFmncMStep.start ASC";
};

void QryFmncStpList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQStpList* rec = NULL;

	dbsfmnc->tblfmncqstplist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefFmncMActivity = StubFmnc::getStubActStd(dbsfmnc, rec->refFmncMActivity, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefRlvIxVTbl = VecFmncVMStepRlvTbl::getSref(rec->rlvIxVTbl);
			rec->titRlvIxVTbl = VecFmncVMStepRlvTbl::getTitle(rec->rlvIxVTbl, ixFmncVLocale);
			if (rec->rlvIxVTbl == VecFmncVMStepRlvTbl::TTY) {
				rec->stubRlvUref = StubFmnc::getStubTtyStd(dbsfmnc, rec->rlvUref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->rlvIxVTbl == VecFmncVMStepRlvTbl::TOL) {
				rec->stubRlvUref = StubFmnc::getStubTolStd(dbsfmnc, rec->rlvUref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRlvUref = "-";
			rec->stubTplRefFmncMStep = StubFmnc::getStubSteStd(dbsfmnc, rec->tplRefFmncMStep, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmStart = Ftm::stamp(rec->start);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncStpList", "fetch");
	};

	refreshJnum();
};

uint QryFmncStpList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQStpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncStpList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQStpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncStpList::handleRequest(
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

bool QryFmncStpList::handleRefresh(
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

bool QryFmncStpList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQStpList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\trefFmncMActivity";
	cout << "\tstubRefFmncMActivity";
	cout << "\trlvIxVTbl";
	cout << "\tsrefRlvIxVTbl";
	cout << "\ttitRlvIxVTbl";
	cout << "\trlvUref";
	cout << "\tstubRlvUref";
	cout << "\ttplRefFmncMStep";
	cout << "\tstubTplRefFmncMStep";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->refFmncMActivity;
		cout << "\t" << rec->stubRefFmncMActivity;
		cout << "\t" << rec->rlvIxVTbl;
		cout << "\t" << rec->srefRlvIxVTbl;
		cout << "\t" << rec->titRlvIxVTbl;
		cout << "\t" << rec->rlvUref;
		cout << "\t" << rec->stubRlvUref;
		cout << "\t" << rec->tplRefFmncMStep;
		cout << "\t" << rec->stubTplRefFmncMStep;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << endl;
	};
	return retval;
};

void QryFmncStpList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSTEMOD) {
		call->abort = handleCallFmncSteMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSTEUPD_REFEQ) {
		call->abort = handleCallFmncSteUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncStpList::handleCallFmncStubChg(
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

bool QryFmncStpList::handleCallFmncSteMod(
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

bool QryFmncStpList::handleCallFmncSteUpd_refEq(
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


