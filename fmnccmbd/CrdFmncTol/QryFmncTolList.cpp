/**
  * \file QryFmncTolList.cpp
  * job handler for job QryFmncTolList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTolList.h"

// IP blksInclude --- BEGIN
#include "QryFmncTolList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTolList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTolList::QryFmncTolList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTOLLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCTOLMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncTolList::~QryFmncTolList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTolList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncTolList::refresh(
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
	string preTit = xchg->getTxtvalPreset(VecFmncVPreset::PREFMNCTOLLIST_TIT, jref);
	ubigint preFab = xchg->getRefPreset(VecFmncVPreset::PREFMNCTOLLIST_FAB, jref);
	ubigint preMnf = xchg->getRefPreset(VecFmncVPreset::PREFMNCTOLLIST_MNF, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqtollist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecFmncVPreset::PREFMNCREFFAB) {
		sqlstr = "SELECT COUNT(TblFmncMTool.ref)";
		sqlstr += " FROM TblFmncMTool";
		sqlstr += " WHERE TblFmncMTool.fabRefFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, preTit, preFab, preMnf, false);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblFmncMTool.ref)";
		sqlstr += " FROM TblFmncMTool";
		refresh_filtSQL(sqlstr, preTit, preFab, preMnf, true);
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
		sqlstr += " FROM TblFmncMTool";
		sqlstr += " WHERE TblFmncMTool.fabRefFmncMFab = " + to_string(preRefFab) + "";
		refresh_filtSQL(sqlstr, preTit, preFab, preMnf, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMTool";
		refresh_filtSQL(sqlstr, preTit, preFab, preMnf, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblFmncQTolList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncTolList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblFmncQTolList(jref, jnum, ref, Title, fabRefFmncMFab, mnfRefFmncMOrg, Unitprice, Training)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMTool.ref, TblFmncMTool.Title, TblFmncMTool.fabRefFmncMFab, TblFmncMTool.mnfRefFmncMOrg, TblFmncMTool.Unitprice, TblFmncMTool.Training";
};

void QryFmncTolList::refresh_filtSQL(
			string& sqlstr
			, const string& preTit
			, const ubigint preFab
			, const ubigint preMnf
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMTool.Title LIKE '" + preTit + "'";
	};

	if (preFab != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMTool.fabRefFmncMFab = " + to_string(preFab) + "";
	};

	if (preMnf != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMTool.mnfRefFmncMOrg = " + to_string(preMnf) + "";
	};
};

void QryFmncTolList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncTolList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblFmncMTool.Title ASC";
	else if (preIxOrd == VecVOrd::FAB) sqlstr += " ORDER BY TblFmncMTool.fabRefFmncMFab ASC";
	else if (preIxOrd == VecVOrd::MNF) sqlstr += " ORDER BY TblFmncMTool.mnfRefFmncMOrg ASC";
};

void QryFmncTolList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTolList* rec = NULL;

	dbsfmnc->tblfmncqtollist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubFabRefFmncMFab = StubFmnc::getStubFabStd(dbsfmnc, rec->fabRefFmncMFab, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubMnfRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->mnfRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTolList", "fetch");
	};

	refreshJnum();
};

uint QryFmncTolList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTolList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTolList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTolList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTolList::handleRequest(
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

bool QryFmncTolList::handleRefresh(
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

bool QryFmncTolList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTolList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tfabRefFmncMFab";
	cout << "\tstubFabRefFmncMFab";
	cout << "\tmnfRefFmncMOrg";
	cout << "\tstubMnfRefFmncMOrg";
	cout << "\tUnitprice";
	cout << "\tTraining";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->fabRefFmncMFab;
		cout << "\t" << rec->stubFabRefFmncMFab;
		cout << "\t" << rec->mnfRefFmncMOrg;
		cout << "\t" << rec->stubMnfRefFmncMOrg;
		cout << "\t" << rec->Unitprice;
		cout << "\t" << rec->Training;
		cout << endl;
	};
	return retval;
};

void QryFmncTolList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLMOD) {
		call->abort = handleCallFmncTolMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLUPD_REFEQ) {
		call->abort = handleCallFmncTolUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTolList::handleCallFmncStubChg(
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

bool QryFmncTolList::handleCallFmncTolMod(
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

bool QryFmncTolList::handleCallFmncTolUpd_refEq(
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


