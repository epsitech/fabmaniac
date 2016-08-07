/**
  * \file QryFmncOrgSvcMNTool.cpp
  * job handler for job QryFmncOrgSvcMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncOrgSvcMNTool.h"

// IP blksInclude --- BEGIN
#include "QryFmncOrgSvcMNTool_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncOrgSvcMNTool
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncOrgSvcMNTool::QryFmncOrgSvcMNTool(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCORGSVCMNTOOL, jrefSup, ixFmncVLocale) {
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

QryFmncOrgSvcMNTool::~QryFmncOrgSvcMNTool() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncOrgSvcMNTool::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncOrgSvcMNTool::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefOrg = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCSORGRTOLMOD_ORGEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqorgsvcmntool->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncSvcRMOrgMTool.ref)";
	sqlstr += " FROM TblFmncSvcRMOrgMTool, TblFmncMTool";
	sqlstr += " WHERE TblFmncSvcRMOrgMTool.refFmncMTool = TblFmncMTool.ref";
	sqlstr += " AND TblFmncSvcRMOrgMTool.refFmncMOrg = " + to_string(preRefOrg) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQOrgSvcMNTool(jref, jnum, mref, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMTool.ref, TblFmncSvcRMOrgMTool.ref";
	sqlstr += " FROM TblFmncSvcRMOrgMTool, TblFmncMTool";
	sqlstr += " WHERE TblFmncSvcRMOrgMTool.refFmncMTool = TblFmncMTool.ref";
	sqlstr += " AND TblFmncSvcRMOrgMTool.refFmncMOrg = " + to_string(preRefOrg) + "";
	sqlstr += " ORDER BY TblFmncMTool.Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQOrgSvcMNTool SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCSORGRTOLMOD_ORGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefOrg, Clstn::VecVJactype::LOCK);
};

void QryFmncOrgSvcMNTool::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQOrgSvcMNTool* rec = NULL;

	ListFmncSvcTMPersonMTool sprsTtols;
	FmncSvcTMPersonMTool* sprsTtol = NULL;

	dbsfmnc->tblfmncqorgsvcmntool->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubFmnc::getStubTolStd(dbsfmnc, rec->mref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			dbsfmnc->tblfmncsvctmpersonmtool->loadRstByR(rec->ref, false, sprsTtols);
			for (unsigned int j=0;j<sprsTtols.nodes.size();j++) {
				sprsTtol = sprsTtols.nodes[j];
				if (j != 0) rec->stubsTrefFmncMPerson += ";";
				rec->stubsTrefFmncMPerson += StubFmnc::getStubPrsStd(dbsfmnc, sprsTtol->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::DASH, stcch);
			};
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncOrgSvcMNTool", "fetch");
	};

	refreshJnum();
};

uint QryFmncOrgSvcMNTool::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQOrgSvcMNTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncOrgSvcMNTool::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQOrgSvcMNTool* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncOrgSvcMNTool::handleRequest(
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

bool QryFmncOrgSvcMNTool::handleRefresh(
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

bool QryFmncOrgSvcMNTool::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQOrgSvcMNTool* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tstubsTrefFmncMPerson";
	cout << "\tref";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->stubsTrefFmncMPerson;
		cout << "\t" << rec->ref;
		cout << endl;
	};
	return retval;
};

void QryFmncOrgSvcMNTool::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSORGRTOLMOD_ORGEQ) {
		call->abort = handleCallFmncSorgRtolMod_orgEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncOrgSvcMNTool::handleCallFmncStubChg(
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

bool QryFmncOrgSvcMNTool::handleCallFmncSorgRtolMod_orgEq(
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


