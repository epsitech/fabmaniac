/**
  * \file QryFmncSepList.cpp
  * job handler for job QryFmncSepList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncSepList.h"

// IP blksInclude --- BEGIN
#include "QryFmncSepList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncSepList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncSepList::QryFmncSepList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSEPLIST, jrefSup, ixFmncVLocale) {
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

QryFmncSepList::~QryFmncSepList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncSepList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSTEUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCSTEUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncSepList::refresh(
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
	ubigint preRefRun = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref);
	ubigint preAct = xchg->getRefPreset(VecFmncVPreset::PREFMNCSEPLIST_ACT, jref);
	uint preRlt = xchg->getIxPreset(VecFmncVPreset::PREFMNCSEPLIST_RLT, jref);
	ubigint preRlu = xchg->getRefPreset(VecFmncVPreset::PREFMNCSEPLIST_RLU, jref);
	ubigint preStp = xchg->getRefPreset(VecFmncVPreset::PREFMNCSEPLIST_STP, jref);
	int preSta = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCSEPLIST_STA, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqseplist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecFmncVPreset::PREFMNCREFRUN) {
		sqlstr = "SELECT COUNT(TblFmncMStep.ref)";
		sqlstr += " FROM TblFmncMStep, TblFmncMActivity";
		sqlstr += " WHERE refFmncMActivity <> 0";
		sqlstr += " AND TblFmncMStep.refFmncMActivity = TblFmncMActivity.ref";
		sqlstr += " AND TblFmncMActivity.runRefFmncMRun = " + to_string(preRefRun) + "";
		refresh_filtSQL(sqlstr, preAct, preRlt, preRlu, preStp, preSta, false);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblFmncMStep.ref)";
		sqlstr += " FROM TblFmncMStep";
		sqlstr += " WHERE refFmncMActivity <> 0";
		refresh_filtSQL(sqlstr, preAct, preRlt, preRlu, preStp, preSta, false);
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

	if (preIxPre == VecFmncVPreset::PREFMNCREFRUN) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMStep, TblFmncMActivity";
		sqlstr += " WHERE refFmncMActivity <> 0";
		sqlstr += " AND TblFmncMStep.refFmncMActivity = TblFmncMActivity.ref";
		sqlstr += " AND TblFmncMActivity.runRefFmncMRun = " + to_string(preRefRun) + "";
		refresh_filtSQL(sqlstr, preAct, preRlt, preRlu, preStp, preSta, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMStep";
		sqlstr += " WHERE refFmncMActivity <> 0";
		refresh_filtSQL(sqlstr, preAct, preRlt, preRlu, preStp, preSta, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblFmncQSepList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncSepList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblFmncQSepList(jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMStep.ref, TblFmncMStep.Title, TblFmncMStep.refFmncMActivity, TblFmncMStep.rlvIxVTbl, TblFmncMStep.rlvUref, TblFmncMStep.tplRefFmncMStep, TblFmncMStep.start";
};

void QryFmncSepList::refresh_filtSQL(
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

void QryFmncSepList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncSepList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::ACT) sqlstr += " ORDER BY TblFmncMStep.refFmncMActivity ASC";
	else if (preIxOrd == VecVOrd::RLT) sqlstr += " ORDER BY TblFmncMStep.rlvIxVTbl ASC";
	else if (preIxOrd == VecVOrd::RLU) sqlstr += " ORDER BY TblFmncMStep.rlvUref ASC";
	else if (preIxOrd == VecVOrd::STP) sqlstr += " ORDER BY TblFmncMStep.tplRefFmncMStep ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblFmncMStep.start ASC";
};

void QryFmncSepList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQSepList* rec = NULL;

	dbsfmnc->tblfmncqseplist->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryFmncSepList", "fetch");
	};

	refreshJnum();
};

uint QryFmncSepList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQSepList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncSepList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQSepList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncSepList::handleRequest(
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

bool QryFmncSepList::handleRefresh(
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

bool QryFmncSepList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQSepList* rec = NULL;

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

void QryFmncSepList::handleCall(
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

bool QryFmncSepList::handleCallFmncStubChg(
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

bool QryFmncSepList::handleCallFmncSteMod(
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

bool QryFmncSepList::handleCallFmncSteUpd_refEq(
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


