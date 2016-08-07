/**
  * \file QryFmncAdrList.cpp
  * job handler for job QryFmncAdrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncAdrList.h"

// IP blksInclude --- BEGIN
#include "QryFmncAdrList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncAdrList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncAdrList::QryFmncAdrList(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCADRLIST, jrefSup, ixFmncVLocale) {
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

	xchg->addClstn(VecFmncVCall::CALLFMNCADRMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryFmncAdrList::~QryFmncAdrList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncAdrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecFmncVCall::CALLFMNCADRUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCADRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryFmncAdrList::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecFmncVPreset::PREFMNCIXORD, jref);
	string preCty = xchg->getTxtvalPreset(VecFmncVPreset::PREFMNCADRLIST_CTY, jref);
	uint preHkt = xchg->getIxPreset(VecFmncVPreset::PREFMNCADRLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecFmncVPreset::PREFMNCADRLIST_HKU, jref);
	string preAty = xchg->getSrefPreset(VecFmncVPreset::PREFMNCADRLIST_ATY, jref);
	string preCry = xchg->getSrefPreset(VecFmncVPreset::PREFMNCADRLIST_CRY, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqadrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMAddress.ref)";
	sqlstr += " FROM TblFmncMAddress";
	refresh_filtSQL(sqlstr, preCty, preHkt, preHku, preAty, preCry, true);
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQAdrList(jref, jnum, ref, Address1, City, hkIxVTbl, hkUref, srefKAdrtype, Zipcode, srefKCountry)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMAddress.ref, TblFmncMAddress.Address1, TblFmncMAddress.City, TblFmncMAddress.hkIxVTbl, TblFmncMAddress.hkUref, TblFmncMAddress.srefKAdrtype, TblFmncMAddress.Zipcode, TblFmncMAddress.srefKCountry";
	sqlstr += " FROM TblFmncMAddress";
	refresh_filtSQL(sqlstr, preCty, preHkt, preHku, preAty, preCry, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQAdrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

};

void QryFmncAdrList::refresh_filtSQL(
			string& sqlstr
			, const string& preCty
			, const uint preHkt
			, const ubigint preHku
			, const string& preAty
			, const string& preCry
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preCty.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMAddress.City LIKE '" + preCty + "'";
	};

	if (preHkt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMAddress.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMAddress.hkUref = " + to_string(preHku) + "";
	};

	if (preAty.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMAddress.srefKAdrtype = '" + preAty + "'";
	};

	if (preCry.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblFmncMAddress.srefKCountry = '" + preCry + "'";
	};
};

void QryFmncAdrList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryFmncAdrList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::CTY) sqlstr += " ORDER BY TblFmncMAddress.City ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblFmncMAddress.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblFmncMAddress.hkUref ASC";
	else if (preIxOrd == VecVOrd::ATY) sqlstr += " ORDER BY TblFmncMAddress.srefKAdrtype ASC";
	else if (preIxOrd == VecVOrd::CRY) sqlstr += " ORDER BY TblFmncMAddress.srefKCountry ASC";
};

void QryFmncAdrList::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQAdrList* rec = NULL;

	dbsfmnc->tblfmncqadrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefHkIxVTbl = VecFmncVMAddressHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecFmncVMAddressHkTbl::getTitle(rec->hkIxVTbl, ixFmncVLocale);
			if (rec->hkIxVTbl == VecFmncVMAddressHkTbl::ORG) {
				rec->stubHkUref = StubFmnc::getStubOrgStd(dbsfmnc, rec->hkUref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecFmncVMAddressHkTbl::PRS) {
				rec->stubHkUref = StubFmnc::getStubPrsStd(dbsfmnc, rec->hkUref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
			rec->titSrefKAdrtype = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTKMADDRESSADRTYPE, rec->srefKAdrtype, ixFmncVLocale);
			rec->titSrefKCountry = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKMADDRESSCOUNTRY, rec->srefKCountry, ixFmncVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncAdrList", "fetch");
	};

	refreshJnum();
};

uint QryFmncAdrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQAdrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncAdrList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQAdrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncAdrList::handleRequest(
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

bool QryFmncAdrList::handleRefresh(
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

bool QryFmncAdrList::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQAdrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tAddress1";
	cout << "\tCity";
	cout << "\thkIxVTbl";
	cout << "\tsrefHkIxVTbl";
	cout << "\ttitHkIxVTbl";
	cout << "\thkUref";
	cout << "\tstubHkUref";
	cout << "\tsrefKAdrtype";
	cout << "\ttitSrefKAdrtype";
	cout << "\tZipcode";
	cout << "\tsrefKCountry";
	cout << "\ttitSrefKCountry";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Address1;
		cout << "\t" << rec->City;
		cout << "\t" << rec->hkIxVTbl;
		cout << "\t" << rec->srefHkIxVTbl;
		cout << "\t" << rec->titHkIxVTbl;
		cout << "\t" << rec->hkUref;
		cout << "\t" << rec->stubHkUref;
		cout << "\t" << rec->srefKAdrtype;
		cout << "\t" << rec->titSrefKAdrtype;
		cout << "\t" << rec->Zipcode;
		cout << "\t" << rec->srefKCountry;
		cout << "\t" << rec->titSrefKCountry;
		cout << endl;
	};
	return retval;
};

void QryFmncAdrList::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCADRMOD) {
		call->abort = handleCallFmncAdrMod(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCADRUPD_REFEQ) {
		call->abort = handleCallFmncAdrUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool QryFmncAdrList::handleCallFmncStubChg(
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

bool QryFmncAdrList::handleCallFmncAdrMod(
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

bool QryFmncAdrList::handleCallFmncAdrUpd_refEq(
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


