/**
  * \file QryFmncSmpAPar.cpp
  * job handler for job QryFmncSmpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncSmpAPar.h"

// IP blksInclude --- BEGIN
#include "QryFmncSmpAPar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncSmpAPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncSmpAPar::QryFmncSmpAPar(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSMPAPAR, jrefSup, ixFmncVLocale) {
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

QryFmncSmpAPar::~QryFmncSmpAPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncSmpAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncSmpAPar::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefSmp = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSMP, jref);
	string preX1 = xchg->getSrefPreset(VecFmncVPreset::PREFMNCSMPAPAR_X1, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSMPAPARMOD_SMPEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqsmpapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMSamplePar.ref)";
	sqlstr += " FROM TblFmncAMSamplePar";
	sqlstr += " WHERE TblFmncAMSamplePar.refFmncMSample = " + to_string(preRefSmp) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQSmpAPar(jref, jnum, ref, x1SrefKKey, osrefKVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMSamplePar.ref, TblFmncAMSamplePar.x1SrefKKey, TblFmncAMSamplePar.osrefKVal";
	sqlstr += " FROM TblFmncAMSamplePar";
	sqlstr += " WHERE TblFmncAMSamplePar.refFmncMSample = " + to_string(preRefSmp) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQSmpAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCSMPAPARMOD_SMPEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSmp, Clstn::VecVJactype::LOCK);
};

void QryFmncSmpAPar::refresh_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMSamplePar.x1SrefKKey = '" + preX1 + "'";
	};
};

void QryFmncSmpAPar::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncSmpAPar::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQSmpAPar* rec = NULL;

	dbsfmnc->tblfmncqsmpapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKKey = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKAMSAMPLEPARKEY, rec->x1SrefKKey, ixFmncVLocale);
			rec->titOsrefKVal = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKAMSAMPLEPARVAL, rec->osrefKVal, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncSmpAPar", "fetch");
	};

	refreshJnum();
};

uint QryFmncSmpAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQSmpAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncSmpAPar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQSmpAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncSmpAPar::handleRequest(
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

bool QryFmncSmpAPar::handleRefresh(
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

bool QryFmncSmpAPar::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQSmpAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1SrefKKey";
	cout << "\ttitX1SrefKKey";
	cout << "\tosrefKVal";
	cout << "\ttitOsrefKVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1SrefKKey;
		cout << "\t" << rec->titX1SrefKKey;
		cout << "\t" << rec->osrefKVal;
		cout << "\t" << rec->titOsrefKVal;
		cout << endl;
	};
	return retval;
};

void QryFmncSmpAPar::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSMPAPARMOD_SMPEQ) {
		call->abort = handleCallFmncSmpAparMod_smpEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncSmpAPar::handleCallFmncStubChg(
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

bool QryFmncSmpAPar::handleCallFmncSmpAparMod_smpEq(
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


