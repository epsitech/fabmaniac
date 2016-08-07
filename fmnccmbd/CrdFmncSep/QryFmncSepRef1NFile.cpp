/**
  * \file QryFmncSepRef1NFile.cpp
  * job handler for job QryFmncSepRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "QryFmncSepRef1NFile.h"

// IP blksInclude --- BEGIN
#include "QryFmncSepRef1NFile_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryFmncSepRef1NFile
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryFmncSepRef1NFile::QryFmncSepRef1NFile(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::QRYFMNCSEPREF1NFILE, jrefSup, ixFmncVLocale) {
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

QryFmncSepRef1NFile::~QryFmncSepRef1NFile() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryFmncSepRef1NFile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryFmncSepRef1NFile::refresh(
			DbsFmnc* dbsfmnc
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefSep = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEP, jref);

	xchg->removeClstns(VecFmncVCall::CALLFMNCFILMOD_RETREUEQ, jref);

	dbsfmnc->tblfmncqselect->removeRstByJref(jref);
	dbsfmnc->tblfmncqsepref1nfile->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblFmncMFile.ref)";
	sqlstr += " FROM TblFmncMFile";
	sqlstr += " WHERE TblFmncMFile.refIxVTbl = " + to_string(VecFmncVMFileRefTbl::STE);
	sqlstr += " AND TblFmncMFile.refUref = " + to_string(preRefSep) + "";
	dbsfmnc->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblFmncQSepRef1NFile(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblFmncMFile.ref";
	sqlstr += " FROM TblFmncMFile";
	sqlstr += " WHERE TblFmncMFile.refIxVTbl = " + to_string(VecFmncVMFileRefTbl::STE);
	sqlstr += " AND TblFmncMFile.refUref = " + to_string(preRefSep) + "";
	sqlstr += " ORDER BY Filename ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsfmnc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblFmncQSepRef1NFile SET jnum = qref WHERE jref = " + to_string(jref);
	dbsfmnc->executeQuery(sqlstr);

	ixFmncVQrystate = VecFmncVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsfmnc);

	if (call) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);

	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCFILMOD_RETREUEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVMFileRefTbl::STE, preRefSep, Clstn::VecVJactype::LOCK);
};

void QryFmncSepRef1NFile::fetch(
			DbsFmnc* dbsfmnc
		) {
	string sqlstr;

	StmgrFmnc* stmgr = NULL;
	Stcch* stcch = NULL;

	FmncQSepRef1NFile* rec = NULL;

	dbsfmnc->tblfmncqsepref1nfile->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubFmnc::getStubFilStd(dbsfmnc, rec->ref, ixFmncVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryFmncSepRef1NFile", "fetch");
	};

	refreshJnum();
};

uint QryFmncSepRef1NFile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	FmncQSepRef1NFile* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryFmncSepRef1NFile::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	FmncQSepRef1NFile* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryFmncSepRef1NFile::handleRequest(
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

bool QryFmncSepRef1NFile::handleRefresh(
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

bool QryFmncSepRef1NFile::handleShow(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	FmncQSepRef1NFile* rec = NULL;

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

void QryFmncSepRef1NFile::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTUBCHG) {
		call->abort = handleCallFmncStubChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFILMOD_RETREUEQ) {
		call->abort = handleCallFmncFilMod_retReuEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool QryFmncSepRef1NFile::handleCallFmncStubChg(
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

bool QryFmncSepRef1NFile::handleCallFmncFilMod_retReuEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixFmncVQrystate != VecFmncVQrystate::OOD) {
		ixFmncVQrystate = VecFmncVQrystate::OOD;
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTATCHG, jref);
	};

	return retval;
};


