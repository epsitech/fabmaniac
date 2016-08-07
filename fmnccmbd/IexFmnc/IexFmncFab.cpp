/**
  * \file IexFmncFab.cpp
  * import/export handler for database DbsFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "IexFmncFab.h"

#include "IexFmncFab_blks.cpp"

/******************************************************************************
 class IexFmncFab
 ******************************************************************************/

IexFmncFab::IexFmncFab(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::IEXFMNCFAB, jrefSup, ixFmncVLocale) {

	jref = xchg->addJob(this);
};

IexFmncFab::~IexFmncFab() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexFmncFab::reset() {
	imeimtool.clear();

	lineno = 0;
	impcnt = 0;
};

void IexFmncFab::import(
			DbsFmnc* dbsfmnc
		) {
	ImeitemIMTool* tol = NULL;
	ImeitemIAMToolAvl* tolAavl = NULL;
	ImeitemIAMToolChar* tolAcha = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIFabSMPersonMTool* fprsStol = NULL;
	ImeitemIJMToolUnitprice* tolJupr = NULL;
	ImeitemIMArticle* art = NULL;
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMnfSMPersonMTool* mprsStol = NULL;
	ImeitemIMStep* ste = NULL;
	ImeitemIRMToolMTooltype* tolRtty = NULL;
	ImeitemISvcRMOrgMTool* sorgRtol = NULL;
	ImeitemIAMStepPar* steApar = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIRMArticleMOrg* artRorg = NULL;
	ImeitemISvcTMPersonMTool* sprsTtol = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;

// IP import --- IBEGIN
	vector<string> ss;
// IP import --- IEND

// IP import.traverse --- RBEGIN

	// -- ImeIMTool
	for (unsigned int ix0=0;ix0<imeimtool.nodes.size();ix0++) {
		tol = imeimtool.nodes[ix0];

		//tol->fabRefFmncMFab: THINT ; look for sref of fab org, format: StubFmncFabSref ("pta")
		dbsfmnc->loadUbigintBySQL("SELECT TblFmncMFab.ref FROM TblFmncMFab, TblFmncMOrg WHERE TblFmncMFab.refFmncMOrg = TblFmncMOrg.ref AND TblFmncMOrg.sref = '" + tol->hintFabRefFmncMFab + "'", tol->fabRefFmncMFab);
		//tol->mnfRefFmncMOrg: CUSTSQL
		StrMod::stringToVector(tol->hsrefMnfRefFmncMOrg, ss);
		for (unsigned int i=0;i<ss.size();i++) if (!dbsfmnc->tblfmncmorg->loadRefBySupSrf(tol->mnfRefFmncMOrg, ss[i], tol->mnfRefFmncMOrg)) break;
		//tol->Title: TBL
		//tol->refJUnitprice: SUB
		//tol->Training: TBL
		//tol->Comment: TBL

		dbsfmnc->tblfmncmtool->insertRec(tol);
		impcnt++;

		for (unsigned int ix1=0;ix1<tol->imeiamtoolavl.nodes.size();ix1++) {
			tolAavl = tol->imeiamtoolavl.nodes[ix1];

			tolAavl->refFmncMTool = tol->ref;
			//tolAavl->x2IxVWkday: IXSREF
			//tolAavl->x3Startt: INVFTM
			//tolAavl->x3Stopt: INVFTM
			//tolAavl->srefKAvltype: TBL

			dbsfmnc->tblfmncamtoolavl->insertRec(tolAavl);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<tol->imeiamtoolchar.nodes.size();ix1++) {
			tolAcha = tol->imeiamtoolchar.nodes[ix1];

			tolAcha->refFmncMTool = tol->ref;
			//tolAcha->x1OsrefFmncKToolchar: TBL
			//tolAcha->Val: TBL
			//tolAcha->Comment: TBL

			dbsfmnc->tblfmncamtoolchar->insertRec(tolAcha);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<tol->imeiavkeylistkey1.nodes.size();ix1++) {
			klsAkey1 = tol->imeiavkeylistkey1.nodes[ix1];

			//klsAkey1->klsIxFmncVKeylist: IXSREF
			klsAkey1->x1IxFmncVMaintable = VecFmncVMaintable::TBLFMNCMTOOL;
			klsAkey1->x1Uref = tol->ref;
			klsAkey1->Fixed = true;
			//klsAkey1->sref: TBL
			//klsAkey1->Avail: TBL
			//klsAkey1->Implied: TBL
			//klsAkey1->refJ: SUB

			dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey1);
			impcnt++;

			for (unsigned int ix2=0;ix2<klsAkey1->imeijavkeylistkey1.nodes.size();ix2++) {
				kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix2];

				kakJkey1->refFmncAVKeylistKey = klsAkey1->ref;
				//kakJkey1->x1IxFmncVLocale: IXSREF
				//kakJkey1->Title: TBL
				//kakJkey1->Comment: TBL

				dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey1);
				impcnt++;
			};

			if (klsAkey1->imeijavkeylistkey1.nodes.size() > 0) {
				kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[0];

				klsAkey1->refJ = kakJkey1->ref;
				klsAkey1->Title = kakJkey1->Title;
				klsAkey1->Comment = kakJkey1->Comment;

				dbsfmnc->tblfmncavkeylistkey->updateRec(klsAkey1);
			};
		};

		for (unsigned int ix1=0;ix1<tol->imeifabsmpersonmtool.nodes.size();ix1++) {
			fprsStol = tol->imeifabsmpersonmtool.nodes[ix1];

			//fprsStol->refFmncMPerson: THINT ; look for person in the tool fab's org, format StubFmncPrsStd
			StrMod::stringToVector(fprsStol->hintRefFmncMPerson, ss, ' ');
			if (ss.size() == 2) {
				dbsfmnc->loadUbigintBySQL("SELECT TblFmncMPerson.ref FROM TblFmncMFab, TblFmncRMOrgMPerson, TblFmncMPerson WHERE TblFmncMFab.ref = " + to_string(tol->fabRefFmncMFab)
							+ " AND TblFmncRMOrgMPerson.refFmncMOrg = TblFmncMFab.refFmncMOrg AND TblFmncMPerson.ref = TblFmncRMOrgMPerson.refFmncMPerson AND TblFmncMPerson.Lastname = '"
							+ StrMod::esc(ss[1]) + "' AND TblFmncMPerson.Firstname = '" + StrMod::esc(ss[0]) + "'", fprsStol->refFmncMPerson);
			};
			fprsStol->refM = tol->ref;

			dbsfmnc->tblfmncfabsmpersonmtool->insertRec(fprsStol);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<tol->imeijmtoolunitprice.nodes.size();ix1++) {
			tolJupr = tol->imeijmtoolunitprice.nodes[ix1];

			tolJupr->refFmncMTool = tol->ref;
			//tolJupr->Unitprice: TBL

			dbsfmnc->tblfmncjmtoolunitprice->insertRec(tolJupr);
			impcnt++;
		};

		if (tol->imeijmtoolunitprice.nodes.size() > 0) {
			tolJupr = tol->imeijmtoolunitprice.nodes[0];

			tol->refJUnitprice = tolJupr->ref;
			tol->Unitprice = tolJupr->Unitprice;

			dbsfmnc->tblfmncmtool->updateRec(tol);
		};

		for (unsigned int ix1=0;ix1<tol->imeimarticle.nodes.size();ix1++) {
			art = tol->imeimarticle.nodes[ix1];

			//art->refFmncMOrg: CUSTSQL
			StrMod::stringToVector(art->hsrefRefFmncMOrg, ss);
			for (unsigned int i=0;i<ss.size();i++) if (!dbsfmnc->tblfmncmorg->loadRefBySupSrf(art->refFmncMOrg, ss[i], art->refFmncMOrg)) break;
			art->refFmncMTool = tol->ref;
			//art->sref: TBL
			//art->Title: TBL
			art->srefKType = "spr";
			//art->Comment: TBL

			dbsfmnc->tblfmncmarticle->insertRec(art);
			impcnt++;

			for (unsigned int ix2=0;ix2<art->imeimfile2.nodes.size();ix2++) {
				fil2 = art->imeimfile2.nodes[ix2];

				fil2->refIxVTbl = VecFmncVMFileRefTbl::ART;
				fil2->refUref = art->ref;
				//fil2->osrefKContent: TBL
				//fil2->Filename: TBL
				//fil2->srefKMimetype: TBL
				//fil2->Comment: TBL

				dbsfmnc->tblfmncmfile->insertRec(fil2);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<art->imeirmarticlemorg.nodes.size();ix2++) {
				artRorg = art->imeirmarticlemorg.nodes[ix2];

				artRorg->refFmncMArticle = art->ref;
				//artRorg->refFmncMOrg: CUSTSQL
				StrMod::stringToVector(artRorg->hsrefRefFmncMOrg, ss);
				for (unsigned int i=0;i<ss.size();i++) if (!dbsfmnc->tblfmncmorg->loadRefBySupSrf(artRorg->refFmncMOrg, ss[i], artRorg->refFmncMOrg)) break;
				art->refFmncMTool = tol->ref;
				//artRorg->Itemno: TBL

				dbsfmnc->tblfmncrmarticlemorg->insertRec(artRorg);
				impcnt++;
			};
		};

		for (unsigned int ix1=0;ix1<tol->imeimfile1.nodes.size();ix1++) {
			fil1 = tol->imeimfile1.nodes[ix1];

			fil1->refIxVTbl = VecFmncVMFileRefTbl::TOL;
			fil1->refUref = tol->ref;
			//fil1->osrefKContent: TBL
			//fil1->Filename: TBL
			//fil1->srefKMimetype: TBL
			//fil1->Comment: TBL

			dbsfmnc->tblfmncmfile->insertRec(fil1);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<tol->imeimnfsmpersonmtool.nodes.size();ix1++) {
			mprsStol = tol->imeimnfsmpersonmtool.nodes[ix1];

			//mprsStol->refFmncMPerson: THINT ; look for person in the tool manufacturer's org, format StubFmncPrsStd
			StrMod::stringToVector(mprsStol->hintRefFmncMPerson, ss, ' ');
			if (ss.size() == 2) {
				dbsfmnc->loadUbigintBySQL("SELECT TblFmncMPerson.ref FROM TblFmncRMOrgMPerson, TblFmncMPerson WHERE TblFmncRMOrgMPerson.refFmncMOrg = " + to_string(tol->mnfRefFmncMOrg)
							+ " AND TblFmncMPerson.ref = TblFmncRMOrgMPerson.refFmncMPerson AND TblFmncMPerson.Lastname = '" + StrMod::esc(ss[1]) + "' AND TblFmncMPerson.Firstname = '" + StrMod::esc(ss[0]) + "'", mprsStol->refFmncMPerson);
			};
			mprsStol->refM = tol->ref;

			dbsfmnc->tblfmncmnfsmpersonmtool->insertRec(mprsStol);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<tol->imeimstep.nodes.size();ix1++) {
			ste = tol->imeimstep.nodes[ix1];

			ste->rlvIxVTbl = VecFmncVMStepRlvTbl::TOL;
			ste->rlvUref = tol->ref;
			//ste->ixWFilecfg: IXSREF
			//ste->Title: TBL

			dbsfmnc->tblfmncmstep->insertRec(ste);
			impcnt++;

			for (unsigned int ix2=0;ix2<ste->imeiamsteppar.nodes.size();ix2++) {
				steApar = ste->imeiamsteppar.nodes[ix2];

				steApar->refFmncMStep = ste->ref;
				//steApar->x1OsrefFmncKSteppar: TBL
				steApar->x2IxVTbl = VecFmncVAMStepParTbl::VOID;
				//steApar->Val: TBL
				//steApar->Comment: TBL

				dbsfmnc->tblfmncamsteppar->insertRec(steApar);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<ste->imeiavkeylistkey2.nodes.size();ix2++) {
				klsAkey2 = ste->imeiavkeylistkey2.nodes[ix2];

				klsAkey2->klsIxFmncVKeylist = VecFmncVKeylist::KLSTFMNCKSTEPPAR;
				klsAkey2->x1IxFmncVMaintable = VecFmncVMaintable::TBLFMNCMSTEP;
				klsAkey2->x1Uref = ste->ref;
				klsAkey2->Fixed = true;
				//klsAkey2->sref: TBL
				//klsAkey2->Avail: TBL
				//klsAkey2->Implied: TBL
				//klsAkey2->refJ: SUB

				dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey2);
				impcnt++;

				for (unsigned int ix3=0;ix3<klsAkey2->imeijavkeylistkey2.nodes.size();ix3++) {
					kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix3];

					kakJkey2->refFmncAVKeylistKey = klsAkey2->ref;
					//kakJkey2->x1IxFmncVLocale: IXSREF
					//kakJkey2->Title: TBL
					//kakJkey2->Comment: TBL

					dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey2);
					impcnt++;
				};

				if (klsAkey2->imeijavkeylistkey2.nodes.size() > 0) {
					kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[0];

					klsAkey2->refJ = kakJkey2->ref;
					klsAkey2->Title = kakJkey2->Title;
					klsAkey2->Comment = kakJkey2->Comment;

					dbsfmnc->tblfmncavkeylistkey->updateRec(klsAkey2);
				};
			};
		};

		for (unsigned int ix1=0;ix1<tol->imeirmtoolmtooltype.nodes.size();ix1++) {
			tolRtty = tol->imeirmtoolmtooltype.nodes[ix1];

			tolRtty->refFmncMTool = tol->ref;
			//tolRtty->refFmncMTooltype: CUSTSQL
			StrMod::stringToVector(tolRtty->hsrefRefFmncMTooltype, ss);
			for (unsigned int i=0;i<ss.size();i++) if (!dbsfmnc->tblfmncmtooltype->loadRefBySupSrf(tolRtty->refFmncMTooltype, ss[i], tolRtty->refFmncMTooltype)) break;
			//tolRtty->srefsFmncKToolchar: TBL
			//tolRtty->defSrefsFmncKSteppar: TBL
			//tolRtty->optSrefsFmncKSteppar: TBL

			dbsfmnc->tblfmncrmtoolmtooltype->insertRec(tolRtty);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<tol->imeisvcrmorgmtool.nodes.size();ix1++) {
			sorgRtol = tol->imeisvcrmorgmtool.nodes[ix1];

			//sorgRtol->refFmncMOrg: CUSTSQL
			StrMod::stringToVector(sorgRtol->hsrefRefFmncMOrg, ss);
			for (unsigned int i=0;i<ss.size();i++) if (!dbsfmnc->tblfmncmorg->loadRefBySupSrf(sorgRtol->refFmncMOrg, ss[i], sorgRtol->refFmncMOrg)) break;
			sorgRtol->refFmncMTool = tol->ref;

			dbsfmnc->tblfmncsvcrmorgmtool->insertRec(sorgRtol);
			impcnt++;

			for (unsigned int ix2=0;ix2<sorgRtol->imeisvctmpersonmtool.nodes.size();ix2++) {
				sprsTtol = sorgRtol->imeisvctmpersonmtool.nodes[ix2];

				//sprsTtol->refFmncMPerson: THINT ; look for person in the tool's servicing org, format StubFmncPrsStd
				StrMod::stringToVector(sprsTtol->hintRefFmncMPerson, ss, ' ');
				if (ss.size() == 2) {
					dbsfmnc->loadUbigintBySQL("SELECT TblFmncMPerson.ref FROM TblFmncRMOrgMPerson, TblFmncMPerson WHERE TblFmncRMOrgMPerson.refFmncMOrg = " + to_string(sorgRtol->refFmncMOrg)
								+ " AND TblFmncMPerson.ref = TblFmncRMOrgMPerson.refFmncMPerson AND TblFmncMPerson.Lastname = '" + StrMod::esc(ss[1]) + "' AND TblFmncMPerson.Firstname = '" + StrMod::esc(ss[0]) + "'", sprsTtol->refFmncMPerson);
				};
				sprsTtol->refR = sorgRtol->ref;

				dbsfmnc->tblfmncsvctmpersonmtool->insertRec(sprsTtol);
				impcnt++;
			};
		};
	};
// IP import.traverse --- REND

// IP import.ppr --- INSERT
};

void IexFmncFab::collect(
			DbsFmnc* dbsfmnc
			, const map<uint,uint>& icsFmncVIop
		) {
	ImeitemIMTool* tol = NULL;
	ImeitemIAMToolAvl* tolAavl = NULL;
	ImeitemIAMToolChar* tolAcha = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIFabSMPersonMTool* fprsStol = NULL;
	ImeitemIJMToolUnitprice* tolJupr = NULL;
	ImeitemIMArticle* art = NULL;
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMnfSMPersonMTool* mprsStol = NULL;
	ImeitemIMStep* ste = NULL;
	ImeitemIRMToolMTooltype* tolRtty = NULL;
	ImeitemISvcRMOrgMTool* sorgRtol = NULL;
	ImeitemIAMStepPar* steApar = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIRMArticleMOrg* artRorg = NULL;
	ImeitemISvcTMPersonMTool* sprsTtol = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;

	uint ixFmncVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

// IP collect.traverse --- BEGIN

	// -- ImeIMTool
	for (unsigned int ix0=0;ix0<imeimtool.nodes.size();ix0++) {
		tol = imeimtool.nodes[ix0];

		if (tol->ref != 0) {
			tol->hintFabRefFmncMFab = StubFmnc::getStubFabSref(dbsfmnc, tol->fabRefFmncMFab, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
			tol->hsrefMnfRefFmncMOrg = StubFmnc::getStubOrgHsref(dbsfmnc, tol->mnfRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMTOOLAVL, ixFmncVIop)) {
			dbsfmnc->tblfmncamtoolavl->loadRefsByTol(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeiamtoolavl.nodes.push_back(new ImeitemIAMToolAvl(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeiamtoolavl.nodes.size();ix1++) {
			tolAavl = tol->imeiamtoolavl.nodes[ix1];

			if (tolAavl->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMTOOLCHAR, ixFmncVIop)) {
			dbsfmnc->tblfmncamtoolchar->loadRefsByTol(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeiamtoolchar.nodes.push_back(new ImeitemIAMToolChar(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeiamtoolchar.nodes.size();ix1++) {
			tolAcha = tol->imeiamtoolchar.nodes[ix1];

			if (tolAcha->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAVKEYLISTKEY1, ixFmncVIop)) {
			dbsfmnc->tblfmncavkeylistkey->loadRefsByMtbUrf(VecFmncVMaintable::TBLFMNCMTOOL, tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeiavkeylistkey1.nodes.push_back(new ImeitemIAVKeylistKey1(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeiavkeylistkey1.nodes.size();ix1++) {
			klsAkey1 = tol->imeiavkeylistkey1.nodes[ix1];

			if (klsAkey1->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY1, ixFmncVIop)) {
				dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey1->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey1->refJ) {refs[i] = refs[0]; refs[0] = klsAkey1->refJ; break;};
				for (unsigned int i=0;i<refs.size();i++) klsAkey1->imeijavkeylistkey1.nodes.push_back(new ImeitemIJAVKeylistKey1(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<klsAkey1->imeijavkeylistkey1.nodes.size();ix2++) {
				kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix2];

				if (kakJkey1->ref != 0) {
				};
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIFABSMPERSONMTOOL, ixFmncVIop)) {
			dbsfmnc->tblfmncfabsmpersonmtool->loadRefsByM(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeifabsmpersonmtool.nodes.push_back(new ImeitemIFabSMPersonMTool(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeifabsmpersonmtool.nodes.size();ix1++) {
			fprsStol = tol->imeifabsmpersonmtool.nodes[ix1];

			if (fprsStol->ref != 0) {
				fprsStol->hintRefFmncMPerson = StubFmnc::getStubPrsStd(dbsfmnc, fprsStol->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMTOOLUNITPRICE, ixFmncVIop)) {
			dbsfmnc->tblfmncjmtoolunitprice->loadRefsByTol(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == tol->refJUnitprice) {refs[i] = refs[0]; refs[0] = tol->refJUnitprice; break;};
			for (unsigned int i=0;i<refs.size();i++) tol->imeijmtoolunitprice.nodes.push_back(new ImeitemIJMToolUnitprice(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeijmtoolunitprice.nodes.size();ix1++) {
			tolJupr = tol->imeijmtoolunitprice.nodes[ix1];

			if (tolJupr->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMARTICLE, ixFmncVIop)) {
			dbsfmnc->tblfmncmarticle->loadRefsByTol(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeimarticle.nodes.push_back(new ImeitemIMArticle(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeimarticle.nodes.size();ix1++) {
			art = tol->imeimarticle.nodes[ix1];

			if (art->ref != 0) {
				art->hsrefRefFmncMOrg = StubFmnc::getStubOrgHsref(dbsfmnc, art->refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMFILE2, ixFmncVIop)) {
				dbsfmnc->tblfmncmfile->loadRefsByRetReu(VecFmncVMFileRefTbl::ART, art->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) art->imeimfile2.nodes.push_back(new ImeitemIMFile2(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<art->imeimfile2.nodes.size();ix2++) {
				fil2 = art->imeimfile2.nodes[ix2];

				if (fil2->ref != 0) {
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMARTICLEMORG, ixFmncVIop)) {
				dbsfmnc->tblfmncrmarticlemorg->loadRefsByArt(art->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) art->imeirmarticlemorg.nodes.push_back(new ImeitemIRMArticleMOrg(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<art->imeirmarticlemorg.nodes.size();ix2++) {
				artRorg = art->imeirmarticlemorg.nodes[ix2];

				if (artRorg->ref != 0) {
					artRorg->hsrefRefFmncMOrg = StubFmnc::getStubOrgHsref(dbsfmnc, artRorg->refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMFILE1, ixFmncVIop)) {
			dbsfmnc->tblfmncmfile->loadRefsByRetReu(VecFmncVMFileRefTbl::TOL, tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeimfile1.nodes.push_back(new ImeitemIMFile1(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeimfile1.nodes.size();ix1++) {
			fil1 = tol->imeimfile1.nodes[ix1];

			if (fil1->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMNFSMPERSONMTOOL, ixFmncVIop)) {
			dbsfmnc->tblfmncmnfsmpersonmtool->loadRefsByM(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeimnfsmpersonmtool.nodes.push_back(new ImeitemIMnfSMPersonMTool(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeimnfsmpersonmtool.nodes.size();ix1++) {
			mprsStol = tol->imeimnfsmpersonmtool.nodes[ix1];

			if (mprsStol->ref != 0) {
				mprsStol->hintRefFmncMPerson = StubFmnc::getStubPrsStd(dbsfmnc, mprsStol->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMSTEP, ixFmncVIop)) {
			dbsfmnc->tblfmncmstep->loadRefsByRltRlu(VecFmncVMStepRlvTbl::TOL, tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeimstep.nodes.push_back(new ImeitemIMStep(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeimstep.nodes.size();ix1++) {
			ste = tol->imeimstep.nodes[ix1];

			if (ste->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMSTEPPAR, ixFmncVIop)) {
				dbsfmnc->tblfmncamsteppar->loadRefsBySte(ste->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) ste->imeiamsteppar.nodes.push_back(new ImeitemIAMStepPar(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<ste->imeiamsteppar.nodes.size();ix2++) {
				steApar = ste->imeiamsteppar.nodes[ix2];

				if (steApar->ref != 0) {
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAVKEYLISTKEY2, ixFmncVIop)) {
				dbsfmnc->tblfmncavkeylistkey->loadRefsByMtbUrf(VecFmncVMaintable::TBLFMNCMSTEP, ste->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) ste->imeiavkeylistkey2.nodes.push_back(new ImeitemIAVKeylistKey2(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<ste->imeiavkeylistkey2.nodes.size();ix2++) {
				klsAkey2 = ste->imeiavkeylistkey2.nodes[ix2];

				if (klsAkey2->ref != 0) {
				};

				if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY2, ixFmncVIop)) {
					dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey2->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey2->refJ) {refs[i] = refs[0]; refs[0] = klsAkey2->refJ; break;};
					for (unsigned int i=0;i<refs.size();i++) klsAkey2->imeijavkeylistkey2.nodes.push_back(new ImeitemIJAVKeylistKey2(dbsfmnc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<klsAkey2->imeijavkeylistkey2.nodes.size();ix3++) {
					kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix3];

					if (kakJkey2->ref != 0) {
					};
				};
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMTOOLMTOOLTYPE, ixFmncVIop)) {
			dbsfmnc->tblfmncrmtoolmtooltype->loadRefsByTol(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeirmtoolmtooltype.nodes.push_back(new ImeitemIRMToolMTooltype(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeirmtoolmtooltype.nodes.size();ix1++) {
			tolRtty = tol->imeirmtoolmtooltype.nodes[ix1];

			if (tolRtty->ref != 0) {
				tolRtty->hsrefRefFmncMTooltype = StubFmnc::getStubTtyStd(dbsfmnc, tolRtty->refFmncMTooltype, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEISVCRMORGMTOOL, ixFmncVIop)) {
			dbsfmnc->tblfmncsvcrmorgmtool->loadRefsByTol(tol->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tol->imeisvcrmorgmtool.nodes.push_back(new ImeitemISvcRMOrgMTool(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tol->imeisvcrmorgmtool.nodes.size();ix1++) {
			sorgRtol = tol->imeisvcrmorgmtool.nodes[ix1];

			if (sorgRtol->ref != 0) {
				sorgRtol->hsrefRefFmncMOrg = StubFmnc::getStubOrgHsref(dbsfmnc, sorgRtol->refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEISVCTMPERSONMTOOL, ixFmncVIop)) {
				dbsfmnc->tblfmncsvctmpersonmtool->loadRefsByR(sorgRtol->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) sorgRtol->imeisvctmpersonmtool.nodes.push_back(new ImeitemISvcTMPersonMTool(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<sorgRtol->imeisvctmpersonmtool.nodes.size();ix2++) {
				sprsTtol = sorgRtol->imeisvctmpersonmtool.nodes[ix2];

				if (sprsTtol->ref != 0) {
					sprsTtol->hintRefFmncMPerson = StubFmnc::getStubPrsStd(dbsfmnc, sprsTtol->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};
	};
// IP collect.traverse --- END

// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexFmncFab::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIMTOOL) {
				parseok = imeimtool.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexFmncFab::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexFmncFab");

	if (basefound) {
		// look for XML sub-blocks
		imeimtool.readXML(docctx, basexpath);
	} else {
		imeimtool = ImeIMTool();
	};
};

bool IexFmncFab::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexFmncFab::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexFmncFab::writeTxt(
			fstream& outfile
		) {
	imeimtool.writeTxt(outfile);
};

void IexFmncFab::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexFmncFab");
		imeimtool.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexFmncFab::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexFmncFab::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexFmncFab::icsFmncVIopInsAll() {
	return {{(uint)VecVIme::IMEIMTOOL,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMTOOLAVL,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMTOOLCHAR,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY1,VecFmncVIop::INS},{(uint)VecVIme::IMEIFABSMPERSONMTOOL,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMTOOLUNITPRICE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMARTICLE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMFILE1,VecFmncVIop::INS},{(uint)VecVIme::IMEIMNFSMPERSONMTOOL,VecFmncVIop::INS},{(uint)VecVIme::IMEIMSTEP,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMTOOLMTOOLTYPE,VecFmncVIop::INS},{(uint)VecVIme::IMEISVCRMORGMTOOL,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMSTEPPAR,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY2,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY1,VecFmncVIop::INS},{(uint)VecVIme::IMEIMFILE2,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMARTICLEMORG,VecFmncVIop::INS},{(uint)VecVIme::IMEISVCTMPERSONMTOOL,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY2,VecFmncVIop::INS}};
};

uint IexFmncFab::getIxFmncVIop(
			const map<uint,uint>& icsFmncVIop
			, const uint ixVIme
			, uint& ixFmncVIop
		) {
	ixFmncVIop = 0;

	auto it = icsFmncVIop.find(ixVIme);
	if (it != icsFmncVIop.end()) ixFmncVIop = it->second;

	return ixFmncVIop;
};

void IexFmncFab::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexFmncFab::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
};


