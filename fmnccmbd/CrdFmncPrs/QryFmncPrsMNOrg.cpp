/**
  * \file QryFmncPrsMNOrg.cpp
  * job handler for job QryFmncPrsMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncPrsMNOrg.h"

// IP blksInclude --- BEGIN
#include "QryFmncPrsMNOrg_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncPrsMNOrg
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncPrsMNOrg::QryFmncPrsMNOrg(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCPRSMNORG, jrefSup, ixFmncVLocale) {
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

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncPrsMNOrg::~QryFmncPrsMNOrg() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncPrsMNOrg::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncPrsMNOrg::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefPrs = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPRS, jref);
	int preX1 = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCPRSMNORG_X1, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCORGRPRSMOD_PRSEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqprsmnorg->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncRMOrgMPerson.ref)";
	sqlstr += " FROM TblFmncRMOrgMPerson, TblFmncMOrg";
	sqlstr += " WHERE TblFmncRMOrgMPerson.refFmncMOrg = TblFmncMOrg.ref";
	sqlstr += " AND TblFmncRMOrgMPerson.refFmncMPerson = " + to_string(preRefPrs) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQPrsMNOrg(jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMOrg.ref, TblFmncRMOrgMPerson.ref, TblFmncRMOrgMPerson.x1Startd, TblFmncRMOrgMPerson.x1Stopd, TblFmncRMOrgMPerson.srefKFunction";
	sqlstr += " FROM TblFmncRMOrgMPerson, TblFmncMOrg";
	sqlstr += " WHERE TblFmncRMOrgMPerson.refFmncMOrg = TblFmncMOrg.ref";
	sqlstr += " AND TblFmncRMOrgMPerson.refFmncMPerson = " + to_string(preRefPrs) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY TblFmncMOrg.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQPrsMNOrg SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCORGRPRSMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefPrs, Clstn::VecVJactype::LOCK);
};

void QryFmncPrsMNOrg::refresh_filtSQL(
			string& sqlstr
			, const int preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncRMOrgMPerson.x1Startd <= " + to_string(preX1) + "";
	};

	if (preX1 != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncRMOrgMPerson.x1Stopd >= " + to_string(preX1) + "";
	};
};

void QryFmncPrsMNOrg::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncPrsMNOrg::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQPrsMNOrg* rec = NULL;

	dbsfmnc->tblfmncqprsmnorg->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubFmnc::getStubOrgStd(dbsfmnc, rec->mref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmX1Startd = Ftm::date(rec->x1Startd);
			rec->ftmX1Stopd = Ftm::date(rec->x1Stopd);
			rec->titSrefKFunction = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKRMORGMPERSONFUNCTION, rec->srefKFunction, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncPrsMNOrg", "fetch");
	};

	refreshJnum();
};

uint QryFmncPrsMNOrg::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQPrsMNOrg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncPrsMNOrg::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQPrsMNOrg* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncPrsMNOrg::handleRequest(
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

bool QryFmncPrsMNOrg::handleRefresh(
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

bool QryFmncPrsMNOrg::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQPrsMNOrg* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1Startd";
	cout << "\tftmX1Startd";
	cout << "\tx1Stopd";
	cout << "\tftmX1Stopd";
	cout << "\tsrefKFunction";
	cout << "\ttitSrefKFunction";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1Startd;
		cout << "\t" << rec->ftmX1Startd;
		cout << "\t" << rec->x1Stopd;
		cout << "\t" << rec->ftmX1Stopd;
		cout << "\t" << rec->srefKFunction;
		cout << "\t" << rec->titSrefKFunction;
		cout << endl;
	};
	return retval;
};

void QryFmncPrsMNOrg::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCORGRPRSMOD_PRSEQ) {
		call->abort = handleCallFmncOrgRprsMod_prsEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncPrsMNOrg::handleCallFmncStubChg(
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

bool QryFmncPrsMNOrg::handleCallFmncOrgRprsMod_prsEq(
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


