/**
  * \file QryFmncUsgMNUser.cpp
  * job handler for job QryFmncUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncUsgMNUser.h"

// IP blksInclude --- BEGIN
#include "QryFmncUsgMNUser_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncUsgMNUser
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncUsgMNUser::QryFmncUsgMNUser(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCUSGMNUSER, jrefSup, ixFmncVLocale) {
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

QryFmncUsgMNUser::~QryFmncUsgMNUser() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncUsgMNUser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncUsgMNUser::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFUSG, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCUSRRUSGMOD_USGEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqusgmnuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncRMUserMUsergroup.ref)";
	sqlstr += " FROM TblFmncRMUserMUsergroup, TblFmncMUser";
	sqlstr += " WHERE TblFmncRMUserMUsergroup.refFmncMUser = TblFmncMUser.ref";
	sqlstr += " AND TblFmncRMUserMUsergroup.refFmncMUsergroup = " + to_string(preRefUsg) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQUsgMNUser(jref, jnum, mref, ref, ixFmncVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMUser.ref, TblFmncRMUserMUsergroup.ref, TblFmncRMUserMUsergroup.ixFmncVUserlevel";
	sqlstr += " FROM TblFmncRMUserMUsergroup, TblFmncMUser";
	sqlstr += " WHERE TblFmncRMUserMUsergroup.refFmncMUser = TblFmncMUser.ref";
	sqlstr += " AND TblFmncRMUserMUsergroup.refFmncMUsergroup = " + to_string(preRefUsg) + "";
	sqlstr += " ORDER BY TblFmncMUser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQUsgMNUser SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCUSRRUSGMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryFmncUsgMNUser::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQUsgMNUser* rec = NULL;

	dbsfmnc->tblfmncqusgmnuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubFmnc::getStubUsrStd(dbsfmnc, rec->mref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxFmncVUserlevel = VecFmncVUserlevel::getSref(rec->ixFmncVUserlevel);
			rec->titIxFmncVUserlevel = VecFmncVUserlevel::getTitle(rec->ixFmncVUserlevel, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncUsgMNUser", "fetch");
	};

	refreshJnum();
};

uint QryFmncUsgMNUser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncUsgMNUser::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncUsgMNUser::handleRequest(
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

bool QryFmncUsgMNUser::handleRefresh(
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

bool QryFmncUsgMNUser::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQUsgMNUser* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixFmncVUserlevel";
	cout << "\tsrefIxFmncVUserlevel";
	cout << "\ttitIxFmncVUserlevel";
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
		cout << "\t" << rec->ixFmncVUserlevel;
		cout << "\t" << rec->srefIxFmncVUserlevel;
		cout << "\t" << rec->titIxFmncVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryFmncUsgMNUser::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSRRUSGMOD_USGEQ) {
		call->abort = handleCallFmncUsrRusgMod_usgEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncUsgMNUser::handleCallFmncStubChg(
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

bool QryFmncUsgMNUser::handleCallFmncUsrRusgMod_usgEq(
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


