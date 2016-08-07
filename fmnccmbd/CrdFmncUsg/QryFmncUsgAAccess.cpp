/**
  * \file QryFmncUsgAAccess.cpp
  * job handler for job QryFmncUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncUsgAAccess.h"

// IP blksInclude --- BEGIN
#include "QryFmncUsgAAccess_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncUsgAAccess
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncUsgAAccess::QryFmncUsgAAccess(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCUSGAACCESS, jrefSup, ixFmncVLocale) {
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

QryFmncUsgAAccess::~QryFmncUsgAAccess() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncUsgAAccess::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecFmncVPreset::PREFMNCUSGAACCESS_X1, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCUSGAACCMOD_USGEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqusgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncAMUsergroupAccess.ref)";
	sqlstr += " FROM TblFmncAMUsergroupAccess";
	sqlstr += " WHERE TblFmncAMUsergroupAccess.refFmncMUsergroup = " + to_string(preRefUsg) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQUsgAAccess(jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncAMUsergroupAccess.ref, TblFmncAMUsergroupAccess.x1IxFmncVCard, TblFmncAMUsergroupAccess.ixFmncWUiaccess";
	sqlstr += " FROM TblFmncAMUsergroupAccess";
	sqlstr += " WHERE TblFmncAMUsergroupAccess.refFmncMUsergroup = " + to_string(preRefUsg) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addRefClstn(VecFmncVCall::CALLFMNCUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryFmncUsgAAccess::refresh_filtSQL(
			string& sqlstr
			, const uint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncAMUsergroupAccess.x1IxFmncVCard = " + to_string(preX1) + "";
	};
};

void QryFmncUsgAAccess::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncUsgAAccess::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQUsgAAccess* rec = NULL;

	dbsfmnc->tblfmncqusgaaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxFmncVCard = VecFmncVCard::getSref(rec->x1IxFmncVCard);
			rec->titX1IxFmncVCard = VecFmncVCard::getTitle(rec->x1IxFmncVCard, ixFmncVLocale);
			rec->srefsIxFmncWUiaccess = VecFmncWUiaccess::getSrefs(rec->ixFmncWUiaccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryFmncUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQUsgAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQUsgAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncUsgAAccess::handleRequest(
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

bool QryFmncUsgAAccess::handleRefresh(
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

bool QryFmncUsgAAccess::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQUsgAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxFmncVCard";
	cout << "\tsrefX1IxFmncVCard";
	cout << "\ttitX1IxFmncVCard";
	cout << "\tixFmncWUiaccess";
	cout << "\tsrefsIxFmncWUiaccess";
	cout << "\ttitsIxFmncWUiaccess";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxFmncVCard;
		cout << "\t" << rec->srefX1IxFmncVCard;
		cout << "\t" << rec->titX1IxFmncVCard;
		cout << "\t" << rec->ixFmncWUiaccess;
		cout << "\t" << rec->srefsIxFmncWUiaccess;
		cout << "\t" << rec->titsIxFmncWUiaccess;
		cout << endl;
	};
	return retval;
};

void QryFmncUsgAAccess::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSGAACCMOD_USGEQ) {
		call->abort = handleCallFmncUsgAaccMod_usgEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncUsgAAccess::handleCallFmncStubChg(
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

bool QryFmncUsgAAccess::handleCallFmncUsgAaccMod_usgEq(
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


