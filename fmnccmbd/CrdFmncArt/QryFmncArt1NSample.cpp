/**
  * \file QryFmncArt1NSample.cpp
  * job handler for job QryFmncArt1NSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncArt1NSample.h"

// IP blksInclude --- BEGIN
#include "QryFmncArt1NSample_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncArt1NSample
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncArt1NSample::QryFmncArt1NSample(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCART1NSAMPLE, jrefSup, ixFmncVLocale) {
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

QryFmncArt1NSample::~QryFmncArt1NSample() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncArt1NSample::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncArt1NSample::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefArt = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFART, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSMPMOD_ARTEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqart1nsample->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMSample.ref)";
	sqlstr += " FROM TblFmncMSample";
	sqlstr += " WHERE TblFmncMSample.refFmncMArticle = " + to_string(preRefArt) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQArt1NSample(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMSample.ref";
	sqlstr += " FROM TblFmncMSample";
	sqlstr += " WHERE TblFmncMSample.refFmncMArticle = " + to_string(preRefArt) + "";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQArt1NSample SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCSMPMOD_ARTEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefArt, Clstn::VecVJactype::LOCK);
};

void QryFmncArt1NSample::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQArt1NSample* rec = NULL;

	dbsfmnc->tblfmncqart1nsample->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubFmnc::getStubSmpStd(dbsfmnc, rec->ref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncArt1NSample", "fetch");
	};

	refreshJnum();
};

uint QryFmncArt1NSample::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQArt1NSample* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncArt1NSample::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQArt1NSample* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncArt1NSample::handleRequest(
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

bool QryFmncArt1NSample::handleRefresh(
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

bool QryFmncArt1NSample::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQArt1NSample* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryFmncArt1NSample::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSMPMOD_ARTEQ) {
		call->abort = handleCallFmncSmpMod_artEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncArt1NSample::handleCallFmncStubChg(
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

bool QryFmncArt1NSample::handleCallFmncSmpMod_artEq(
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


