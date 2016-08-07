/**
  * \file QryFmncOrgMnf1NTool.cpp
  * job handler for job QryFmncOrgMnf1NTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncOrgMnf1NTool.h"

// IP blksInclude --- BEGIN
#include "QryFmncOrgMnf1NTool_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncOrgMnf1NTool
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncOrgMnf1NTool::QryFmncOrgMnf1NTool(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCORGMNF1NTOOL, jrefSup, ixFmncVLocale) {
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

QryFmncOrgMnf1NTool::~QryFmncOrgMnf1NTool() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncOrgMnf1NTool::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncOrgMnf1NTool::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefOrg = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLMOD_MNFEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqorgmnf1ntool->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMTool.ref)";
	sqlstr += " FROM TblFmncMTool";
	sqlstr += " WHERE TblFmncMTool.mnfRefFmncMOrg = " + to_string(preRefOrg) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQOrgMnf1NTool(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMTool.ref";
	sqlstr += " FROM TblFmncMTool";
	sqlstr += " WHERE TblFmncMTool.mnfRefFmncMOrg = " + to_string(preRefOrg) + "";
	sqlstr += " ORDER BY Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQOrgMnf1NTool SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLMOD_MNFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefOrg, Clstn::VecVJactype::LOCK);
};

void QryFmncOrgMnf1NTool::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQOrgMnf1NTool* rec = NULL;

	ListFmncMnfSMPersonMTool mprsStols;
	FmncMnfSMPersonMTool* mprsStol = NULL;

	dbsfmnc->tblfmncqorgmnf1ntool->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubFmnc::getStubTolStd(dbsfmnc, rec->ref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			dbsfmnc->tblfmncmnfsmpersonmtool->loadRstByM(rec->ref, false, mprsStols);
			for (unsigned int j=0;j<mprsStols.nodes.size();j++) {
				mprsStol = mprsStols.nodes[j];
				if (j != 0) rec->stubsSrefFmncMPerson += ";";
				rec->stubsSrefFmncMPerson += StubFmnc::getStubPrsStd(dbsfmnc, mprsStol->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::DASH, stcch);
			};
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncOrgMnf1NTool", "fetch");
	};

	refreshJnum();
};

uint QryFmncOrgMnf1NTool::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQOrgMnf1NTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncOrgMnf1NTool::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQOrgMnf1NTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncOrgMnf1NTool::handleRequest(
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

bool QryFmncOrgMnf1NTool::handleRefresh(
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

bool QryFmncOrgMnf1NTool::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQOrgMnf1NTool* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << "\tstubsSrefFmncMPerson";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << "\t" << rec->stubsSrefFmncMPerson;
		cout << endl;
	};
	return retval;
};

void QryFmncOrgMnf1NTool::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLMOD_MNFEQ) {
		call->abort = handleCallFmncTolMod_mnfEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncOrgMnf1NTool::handleCallFmncStubChg(
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

bool QryFmncOrgMnf1NTool::handleCallFmncTolMod_mnfEq(
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


