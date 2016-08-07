/**
  * \file QryFmncActList.cpp
  * job handler for job QryFmncActList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncActList.h"

// IP blksInclude --- BEGIN
#include "QryFmncActList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncActList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncActList::QryFmncActList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCACTLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCACTMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncActList::~QryFmncActList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncActList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCACTUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCACTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncActList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	ubigint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXPRE, jref);
	ubigint preRefRun = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref);
	ubigint preRun = xchg->getRefPreset(VecFmncVPreset::PREFMNCACTLIST_RUN, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqactlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecFmncVPreset::PREFMNCREFRUN) {
		sqlstr = "SELECT COUNT(TblFmncMActivity.ref)";
		sqlstr += " FROM TblFmncMActivity";
		sqlstr += " WHERE TblFmncMActivity.runRefFmncMRun = " + to_string(preRefRun) + "";
		refresh_filtSQL(sqlstr, preRun, false);
		dbsfmnc->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblFmncMActivity.ref)";
		sqlstr += " FROM TblFmncMActivity";
		refresh_filtSQL(sqlstr, preRun, true);
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
		sqlstr += " FROM TblFmncMActivity";
		sqlstr += " WHERE TblFmncMActivity.runRefFmncMRun = " + to_string(preRefRun) + "";
		refresh_filtSQL(sqlstr, preRun, false);
		sqlstr += " ORDER BY TblFmncMActivity.runRefFmncMRun ASC";
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblFmncMActivity";
		refresh_filtSQL(sqlstr, preRun, true);
		sqlstr += " ORDER BY TblFmncMActivity.runRefFmncMRun ASC";
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsfmnc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblFmncQActList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncActList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblFmncQActList(jref, jnum, ref, Title, runRefFmncMRun)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMActivity.ref, TblFmncMActivity.Title, TblFmncMActivity.runRefFmncMRun";
};

void QryFmncActList::refresh_filtSQL(
			string& sqlstr
			, const ubigint preRun
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preRun != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMActivity.runRefFmncMRun = " + to_string(preRun) + "";
	};
};

void QryFmncActList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncActList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQActList* rec = NULL;

	dbsfmnc->tblfmncqactlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRunRefFmncMRun = StubFmnc::getStubRunStd(dbsfmnc, rec->runRefFmncMRun, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncActList", "fetch");
	};

	refreshJnum();
};

uint QryFmncActList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQActList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncActList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQActList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncActList::handleRequest(
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

bool QryFmncActList::handleRefresh(
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

bool QryFmncActList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQActList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\trunRefFmncMRun";
	cout << "\tstubRunRefFmncMRun";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->runRefFmncMRun;
		cout << "\t" << rec->stubRunRefFmncMRun;
		cout << endl;
	};
	return retval;
};

void QryFmncActList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCACTMOD) {
		call->abort = handleCallFmncActMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCACTUPD_REFEQ) {
		call->abort = handleCallFmncActUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncActList::handleCallFmncStubChg(
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

bool QryFmncActList::handleCallFmncActMod(
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

bool QryFmncActList::handleCallFmncActUpd_refEq(
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


