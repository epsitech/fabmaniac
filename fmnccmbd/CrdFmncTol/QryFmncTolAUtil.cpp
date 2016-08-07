/**
  * \file QryFmncTolAUtil.cpp
  * job handler for job QryFmncTolAUtil (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTolAUtil.h"

// IP blksInclude --- BEGIN
#include "QryFmncTolAUtil_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTolAUtil
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTolAUtil::QryFmncTolAUtil(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTOLAUTIL, jrefSup, ixFmncVLocale) {
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

QryFmncTolAUtil::~QryFmncTolAUtil() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTolAUtil::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTolAUtil::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTol = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref);
	ubigint preX1 = xchg->getRefPreset(VecFmncVPreset::PREFMNCTOLAUTIL_X1, jref);
	ubigint preX2 = xchg->getRefPreset(VecFmncVPreset::PREFMNCTOLAUTIL_X2, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLAUTIMOD_TOLEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqtolautil->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMToolUtil.ref)";
	sqlstr += " FROM TblFmncAMToolUtil";
	sqlstr += " WHERE TblFmncAMToolUtil.refFmncMTool = " + to_string(preRefTol) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTolAUtil(jref, jnum, ref, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMToolUtil.ref, TblFmncAMToolUtil.x1RefFmncMFabproject, TblFmncAMToolUtil.x2RefFmncMFabuser, TblFmncAMToolUtil.startd, TblFmncAMToolUtil.startt, TblFmncAMToolUtil.stopt, TblFmncAMToolUtil.Unitprice, TblFmncAMToolUtil.Comment";
	sqlstr += " FROM TblFmncAMToolUtil";
	sqlstr += " WHERE TblFmncAMToolUtil.refFmncMTool = " + to_string(preRefTol) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTolAUtil SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLAUTIMOD_TOLEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefTol, Clstn::VecVJactype::LOCK);
};

void QryFmncTolAUtil::refresh_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const ubigint preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolUtil.x1RefFmncMFabproject = " + to_string(preX1) + "";
	};

	if (preX2 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolUtil.x2RefFmncMFabuser = " + to_string(preX2) + "";
	};
};

void QryFmncTolAUtil::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncTolAUtil::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTolAUtil* rec = NULL;

	dbsfmnc->tblfmncqtolautil->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefFmncMFabproject = StubFmnc::getStubFpjStd(dbsfmnc, rec->x1RefFmncMFabproject, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubX2RefFmncMFabuser = StubFmnc::getStubFusStd(dbsfmnc, rec->x2RefFmncMFabuser, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmStartd = Ftm::date(rec->startd);
			rec->ftmStartt = Ftm::time(rec->startt);
			rec->ftmStopt = Ftm::time(rec->stopt);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTolAUtil", "fetch");
	};

	refreshJnum();
};

uint QryFmncTolAUtil::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTolAUtil* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTolAUtil::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTolAUtil* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTolAUtil::handleRequest(
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

bool QryFmncTolAUtil::handleRefresh(
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

bool QryFmncTolAUtil::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTolAUtil* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefFmncMFabproject";
	cout << "\tstubX1RefFmncMFabproject";
	cout << "\tx2RefFmncMFabuser";
	cout << "\tstubX2RefFmncMFabuser";
	cout << "\tstartd";
	cout << "\tftmStartd";
	cout << "\tstartt";
	cout << "\tftmStartt";
	cout << "\tstopt";
	cout << "\tftmStopt";
	cout << "\tUnitprice";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefFmncMFabproject;
		cout << "\t" << rec->stubX1RefFmncMFabproject;
		cout << "\t" << rec->x2RefFmncMFabuser;
		cout << "\t" << rec->stubX2RefFmncMFabuser;
		cout << "\t" << rec->startd;
		cout << "\t" << rec->ftmStartd;
		cout << "\t" << rec->startt;
		cout << "\t" << rec->ftmStartt;
		cout << "\t" << rec->stopt;
		cout << "\t" << rec->ftmStopt;
		cout << "\t" << rec->Unitprice;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryFmncTolAUtil::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLAUTIMOD_TOLEQ) {
		call->abort = handleCallFmncTolAutiMod_tolEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTolAUtil::handleCallFmncStubChg(
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

bool QryFmncTolAUtil::handleCallFmncTolAutiMod_tolEq(
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


