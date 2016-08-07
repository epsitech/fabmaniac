/**
  * \file QryFmncTolARes.cpp
  * job handler for job QryFmncTolARes (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncTolARes.h"

// IP blksInclude --- BEGIN
#include "QryFmncTolARes_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncTolARes
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncTolARes::QryFmncTolARes(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCTOLARES, jrefSup, ixFmncVLocale) {
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

QryFmncTolARes::~QryFmncTolARes() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncTolARes::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncTolARes::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefTol = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref);
	ubigint preX1 = xchg->getRefPreset(VecFmncVPreset::PREFMNCTOLARES_X1, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLARESMOD_TOLEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqtolares->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMToolRes.ref)";
	sqlstr += " FROM TblFmncAMToolRes";
	sqlstr += " WHERE TblFmncAMToolRes.refFmncMTool = " + to_string(preRefTol) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQTolARes(jref, jnum, ref, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMToolRes.ref, TblFmncAMToolRes.x1RefFmncMFabuser, TblFmncAMToolRes.startd, TblFmncAMToolRes.startt, TblFmncAMToolRes.stopt, TblFmncAMToolRes.srefKRestype, TblFmncAMToolRes.Comment";
	sqlstr += " FROM TblFmncAMToolRes";
	sqlstr += " WHERE TblFmncAMToolRes.refFmncMTool = " + to_string(preRefTol) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQTolARes SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLARESMOD_TOLEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefTol, Clstn::VecVJactype::LOCK);
};

void QryFmncTolARes::refresh_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMToolRes.x1RefFmncMFabuser = " + to_string(preX1) + "";
	};
};

void QryFmncTolARes::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncTolARes::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQTolARes* rec = NULL;

	dbsfmnc->tblfmncqtolares->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefFmncMFabuser = StubFmnc::getStubFusStd(dbsfmnc, rec->x1RefFmncMFabuser, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmStartd = Ftm::date(rec->startd);
			rec->ftmStartt = Ftm::time(rec->startt);
			rec->ftmStopt = Ftm::time(rec->stopt);
			rec->titSrefKRestype = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKAMTOOLRESRESTYPE, rec->srefKRestype, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncTolARes", "fetch");
	};

	refreshJnum();
};

uint QryFmncTolARes::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQTolARes* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncTolARes::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQTolARes* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncTolARes::handleRequest(
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

bool QryFmncTolARes::handleRefresh(
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

bool QryFmncTolARes::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQTolARes* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefFmncMFabuser";
	cout << "\tstubX1RefFmncMFabuser";
	cout << "\tstartd";
	cout << "\tftmStartd";
	cout << "\tstartt";
	cout << "\tftmStartt";
	cout << "\tstopt";
	cout << "\tftmStopt";
	cout << "\tsrefKRestype";
	cout << "\ttitSrefKRestype";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefFmncMFabuser;
		cout << "\t" << rec->stubX1RefFmncMFabuser;
		cout << "\t" << rec->startd;
		cout << "\t" << rec->ftmStartd;
		cout << "\t" << rec->startt;
		cout << "\t" << rec->ftmStartt;
		cout << "\t" << rec->stopt;
		cout << "\t" << rec->ftmStopt;
		cout << "\t" << rec->srefKRestype;
		cout << "\t" << rec->titSrefKRestype;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryFmncTolARes::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLARESMOD_TOLEQ) {
		call->abort = handleCallFmncTolAresMod_tolEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncTolARes::handleCallFmncStubChg(
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

bool QryFmncTolARes::handleCallFmncTolAresMod_tolEq(
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


