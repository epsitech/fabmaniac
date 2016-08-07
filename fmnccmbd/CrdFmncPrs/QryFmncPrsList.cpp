/**
  * \file QryFmncPrsList.cpp
  * job handler for job QryFmncPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncPrsList.h"

// IP blksInclude --- BEGIN
#include "QryFmncPrsList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncPrsList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncPrsList::QryFmncPrsList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCPRSLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncPrsList::~QryFmncPrsList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCPRSUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncPrsList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preJrefSess = xchg->getRefPreset(VecFmncVPreset::PREFMNCJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preLnm = xchg->getTxtvalPreset(VecFmncVPreset::PREFMNCPRSLIST_LNM, jref);
	ubigint preGrp = xchg->getRefPreset(VecFmncVPreset::PREFMNCPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecFmncVPreset::PREFMNCPRSLIST_OWN, jref);
	ubigint preOrg = xchg->getRefPreset(VecFmncVPreset::PREFMNCPRSLIST_ORG, jref);
	ubigint preAdr = xchg->getRefPreset(VecFmncVPreset::PREFMNCPRSLIST_ADR, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMPerson.ref)";
	sqlstr += " FROM TblFmncMPerson, TblFmncQSelect";
	sqlstr += " WHERE TblFmncQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblFmncMPerson.grp = TblFmncQSelect.ref";
	refresh_filtSQL(sqlstr, preLnm, preGrp, preOwn, preOrg, preAdr, false);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQPrsList(jref, jnum, ref, Title, Firstname, Lastname, grp, own, refFmncMOrg, refFmncMAddress, ixVSex, Tel, Eml)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMPerson.ref, TblFmncMPerson.Title, TblFmncMPerson.Firstname, TblFmncMPerson.Lastname, TblFmncMPerson.grp, TblFmncMPerson.own, TblFmncMPerson.refFmncMOrg, TblFmncMPerson.refFmncMAddress, TblFmncMPerson.ixVSex, TblFmncMPerson.Tel, TblFmncMPerson.Eml";
	sqlstr += " FROM TblFmncMPerson, TblFmncQSelect";
	sqlstr += " WHERE TblFmncQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblFmncMPerson.grp = TblFmncQSelect.ref";
	refresh_filtSQL(sqlstr, preLnm, preGrp, preOwn, preOrg, preAdr, false);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncPrsList::refresh_filtSQL(
			string& sqlstr
			, const string& preLnm
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint preOrg
			, const ubigint preAdr
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preLnm.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPerson.Lastname LIKE '" + preLnm + "'";
	};

	if (preGrp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPerson.own = " + to_string(preOwn) + "";
	};

	if (preOrg != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPerson.refFmncMOrg = " + to_string(preOrg) + "";
	};

	if (preAdr != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMPerson.refFmncMAddress = " + to_string(preAdr) + "";
	};
};

void QryFmncPrsList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncPrsList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblFmncMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblFmncMPerson.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblFmncMPerson.own ASC";
	else if (preIxOrd == VecVOrd::ORG) sqlstr += " ORDER BY TblFmncMPerson.refFmncMOrg ASC";
	else if (preIxOrd == VecVOrd::ADR) sqlstr += " ORDER BY TblFmncMPerson.refFmncMAddress ASC";
};

void QryFmncPrsList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQPrsList* rec = NULL;

	dbsfmnc->tblfmncqprslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubFmnc::getStubGrp(dbsfmnc, rec->grp, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubFmnc::getStubOwn(dbsfmnc, rec->own, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMOrg = StubFmnc::getStubOrgStd(dbsfmnc, rec->refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefFmncMAddress = StubFmnc::getStubAdrStd(dbsfmnc, rec->refFmncMAddress, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVSex = VecFmncVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecFmncVMPersonSex::getTitle(rec->ixVSex, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncPrsList", "fetch");
	};

	refreshJnum();
};

uint QryFmncPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQPrsList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncPrsList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQPrsList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncPrsList::handleRequest(
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

bool QryFmncPrsList::handleRefresh(
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

bool QryFmncPrsList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefFmncMOrg";
	cout << "\tstubRefFmncMOrg";
	cout << "\trefFmncMAddress";
	cout << "\tstubRefFmncMAddress";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\tTel";
	cout << "\tEml";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->refFmncMOrg;
		cout << "\t" << rec->stubRefFmncMOrg;
		cout << "\t" << rec->refFmncMAddress;
		cout << "\t" << rec->stubRefFmncMAddress;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->Tel;
		cout << "\t" << rec->Eml;
		cout << endl;
	};
	return retval;
};

void QryFmncPrsList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPRSMOD) {
		call->abort = handleCallFmncPrsMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPRSUPD_REFEQ) {
		call->abort = handleCallFmncPrsUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncPrsList::handleCallFmncStubChg(
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

bool QryFmncPrsList::handleCallFmncPrsMod(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixFmncVQrystate == VecFmncVQrystate::UTD) || (ixFmncVQrystate == VecFmncVQrystate::SLM)) {
		ixFmncVQrystate = VecFmncVQrystate::MNR;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};

bool QryFmncPrsList::handleCallFmncPrsUpd_refEq(
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


