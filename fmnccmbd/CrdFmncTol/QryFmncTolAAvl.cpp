/**
  * \file QryFmncTolAAvl.cpp
  * job handler for job QryFmncTolAAvl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTolAAvl.h"

// IP blksInclude --- BEGIN
#include "QryFmncTolAAvl_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTolAAvl
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTolAAvl::QryFmncTolAAvl(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTOLAAVL, jrefSup, ixFmncVLocale) {
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

QryFmncTolAAvl::~QryFmncTolAAvl() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTolAAvl::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTolAAvl::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTol = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref);
	int preX1 = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCTOLAAVL_X1, jref);
	uint preX2 = xchg->getIxPreset(VecFmncVPreset::PREFMNCTOLAAVL_X2, jref);
	int preX3 = xchg->getIntvalPreset(VecFmncVPreset::PREFMNCTOLAAVL_X3, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLAAVLMOD_TOLEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqtolaavl->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMToolAvl.ref)";
	sqlstr += " FROM TblFmncAMToolAvl";
	sqlstr += " WHERE TblFmncAMToolAvl.refFmncMTool = " + to_string(preRefTol) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, preX3, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTolAAvl(jref, jnum, ref, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMToolAvl.ref, TblFmncAMToolAvl.x1Startd, TblFmncAMToolAvl.x2IxVWkday, TblFmncAMToolAvl.x3Startt, TblFmncAMToolAvl.x3Stopt, TblFmncAMToolAvl.srefKAvltype";
	sqlstr += " FROM TblFmncAMToolAvl";
	sqlstr += " WHERE TblFmncAMToolAvl.refFmncMTool = " + to_string(preRefTol) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, preX3, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTolAAvl SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLAAVLMOD_TOLEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefTol, Clstn::VecVJactype::LOCK);
};

void QryFmncTolAAvl::refresh_filtSQL(
			string& sqlstr
			, const int preX1
			, const uint preX2
			, const int preX3
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolAvl.x1Startd <= " + to_string(preX1) + "";
	};

	if (preX2 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolAvl.x2IxVWkday = " + to_string(preX2) + "";
	};

	if (preX3 != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolAvl.x3Startt <= " + to_string(preX3) + "";
	};

	if (preX3 != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolAvl.x3Stopt >= " + to_string(preX3) + "";
	};
};

void QryFmncTolAAvl::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncTolAAvl::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTolAAvl* rec = NULL;

	dbsfmnc->tblfmncqtolaavl->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->ftmX1Startd = Ftm::date(rec->x1Startd);
			rec->ftmX3Startt = Ftm::time(rec->x3Startt);
			rec->ftmX3Stopt = Ftm::time(rec->x3Stopt);
			rec->titSrefKAvltype = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKAMTOOLAVLAVLTYPE, rec->srefKAvltype, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTolAAvl", "fetch");
	};

	refreshJnum();
};

uint QryFmncTolAAvl::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTolAAvl* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTolAAvl::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTolAAvl* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTolAAvl::handleRequest(
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

bool QryFmncTolAAvl::handleRefresh(
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

bool QryFmncTolAAvl::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTolAAvl* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1Startd";
	cout << "\tftmX1Startd";
	cout << "\tx2IxVWkday";
	cout << "\tsrefX2IxVWkday";
	cout << "\tx3Startt";
	cout << "\tftmX3Startt";
	cout << "\tx3Stopt";
	cout << "\tftmX3Stopt";
	cout << "\tsrefKAvltype";
	cout << "\ttitSrefKAvltype";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1Startd;
		cout << "\t" << rec->ftmX1Startd;
		cout << "\t" << rec->x2IxVWkday;
		cout << "\t" << rec->srefX2IxVWkday;
		cout << "\t" << rec->x3Startt;
		cout << "\t" << rec->ftmX3Startt;
		cout << "\t" << rec->x3Stopt;
		cout << "\t" << rec->ftmX3Stopt;
		cout << "\t" << rec->srefKAvltype;
		cout << "\t" << rec->titSrefKAvltype;
		cout << endl;
	};
	return retval;
};

void QryFmncTolAAvl::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLAAVLMOD_TOLEQ) {
		call->abort = handleCallFmncTolAavlMod_tolEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTolAAvl::handleCallFmncStubChg(
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

bool QryFmncTolAAvl::handleCallFmncTolAavlMod_tolEq(
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


