/**
  * \file IexFmncOrg.cpp
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

#include "IexFmncOrg.h"

#include "IexFmncOrg_blks.cpp"

/******************************************************************************
 class IexFmncOrg
 ******************************************************************************/

IexFmncOrg::IexFmncOrg(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::IEXFMNCORG, jrefSup, ixFmncVLocale) {

	jref = xchg->addJob(this);
};

IexFmncOrg::~IexFmncOrg() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexFmncOrg::reset() {
	imeimorg.clear();
	imeimperson.clear();
	imeirmorgmperson.clear();

	lineno = 0;
	impcnt = 0;
};

void IexFmncOrg::import(
			DbsFmnc* dbsfmnc
		) {
	ImeitemIMOrg* org = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIRMOrgMPerson* orgRprs = NULL;
	ImeitemIAMOrgDetail* orgAdet = NULL;
	ImeitemIAMPersonDetail* prsAdet = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJMOrgTitle* orgJtit = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIMAddress1* adr1 = NULL;
	ImeitemIMAddress2* adr2 = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;

// IP import --- IBEGIN
	ImeitemIMOrg* org2 = NULL;

	string s;
// IP import --- IEND

// IP import.traverse --- RBEGIN

	// -- ImeIMOrg
	for (unsigned int ix0=0;ix0<imeimorg.nodes.size();ix0++) {
		org = imeimorg.nodes[ix0];

		//org->ixWDerivate: IXSREF
		//org->refFmncMAddress: SUB
		//org->supRefFmncMOrg: PREVIMP
		for (unsigned int i=0;i<ix0;i++) {
			org2 = imeimorg.nodes[i];

			s = org2->sref;
			if (org2->hsrefSupRefFmncMOrg.length() > 0) s = org2->hsrefSupRefFmncMOrg + ";" + s;
			
			if (s == org->hsrefSupRefFmncMOrg) {
				org->supRefFmncMOrg = org2->ref;
				break;
			};
		};
		//org->sref: TBL
		//org->refJTitle: SUB
		//org->telRefADetail: SUB
		//org->emlRefADetail: SUB

		dbsfmnc->tblfmncmorg->insertRec(org);
		impcnt++;

		if (org->ixWDerivate & VecFmncWMOrgDerivate::FAB) dbsfmnc->tblfmncmfab->insertNewRec(NULL, 0, 0, org->ref);

		for (unsigned int ix1=0;ix1<org->imeiamorgdetail.nodes.size();ix1++) {
			orgAdet = org->imeiamorgdetail.nodes[ix1];

			orgAdet->refFmncMOrg = org->ref;
			//orgAdet->x1SrefKType: TBL
			//orgAdet->Val: TBL

			dbsfmnc->tblfmncamorgdetail->insertRec(orgAdet);
			impcnt++;

			if (orgAdet->x1SrefKType == "tel") {
				org->telRefADetail = orgAdet->ref;
				org->Tel = orgAdet->Val;

				dbsfmnc->tblfmncmorg->updateRec(org);

			} else if (orgAdet->x1SrefKType == "eml") {
				org->emlRefADetail = orgAdet->ref;
				org->Eml = orgAdet->Val;

				dbsfmnc->tblfmncmorg->updateRec(org);
			};
		};

		for (unsigned int ix1=0;ix1<org->imeiavkeylistkey.nodes.size();ix1++) {
			klsAkey = org->imeiavkeylistkey.nodes[ix1];

			klsAkey->klsIxFmncVKeylist = VecFmncVKeylist::KLSTFMNCKSTOCKLCN;
			klsAkey->x1IxFmncVMaintable = VecFmncVMaintable::TBLFMNCMORG;
			klsAkey->x1Uref = org->ref;
			klsAkey->Fixed = true;
			//klsAkey->sref: TBL
			//klsAkey->Avail: TBL
			//klsAkey->Implied: TBL
			//klsAkey->refJ: SUB

			dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey);
			impcnt++;

			for (unsigned int ix2=0;ix2<klsAkey->imeijavkeylistkey.nodes.size();ix2++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];

				kakJkey->refFmncAVKeylistKey = klsAkey->ref;
				//kakJkey->x1IxFmncVLocale: IXSREF
				//kakJkey->Title: TBL
				//kakJkey->Comment: TBL

				dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey);
				impcnt++;
			};
		};

		for (unsigned int ix1=0;ix1<org->imeijmorgtitle.nodes.size();ix1++) {
			orgJtit = org->imeijmorgtitle.nodes[ix1];

			orgJtit->refFmncMOrg = org->ref;
			//orgJtit->Title: TBL

			dbsfmnc->tblfmncjmorgtitle->insertRec(orgJtit);
			impcnt++;
		};

		if (org->imeijmorgtitle.nodes.size() > 0) {
			orgJtit = org->imeijmorgtitle.nodes[0];

			org->refJTitle = orgJtit->ref;
			org->Title = orgJtit->Title;
			
			dbsfmnc->tblfmncmorg->updateRec(org);
		};

		for (unsigned int ix1=0;ix1<org->imeimaddress1.nodes.size();ix1++) {
			adr1 = org->imeimaddress1.nodes[ix1];

			adr1->hkIxVTbl = VecFmncVMAddressHkTbl::ORG;
			adr1->hkUref = org->ref;
			//adr1->srefKAdrtype: TBL
			//adr1->Address1: TBL
			//adr1->Address2: TBL
			//adr1->Zipcode: TBL
			//adr1->City: TBL
			//adr1->State: TBL
			//adr1->srefKCountry: TBL

			dbsfmnc->tblfmncmaddress->insertRec(adr1);
			impcnt++;
		};

		if (org->imeimaddress1.nodes.size() > 0) {
			adr1 = org->imeimaddress1.nodes[0];

			org->refFmncMAddress = adr1->ref;
			
			dbsfmnc->tblfmncmorg->updateRec(org);
		};
	};

	// -- ImeIMPerson
	for (unsigned int ix0=0;ix0<imeimperson.nodes.size();ix0++) {
		prs = imeimperson.nodes[ix0];

		//prs->ref: IDIREF
		//prs->refFmncMAddress: SUB
		//prs->refROrg: IMPPP
		//prs->ixVSex: IXSREF
		//prs->Title: TBL
		//prs->Firstname: TBL
		//prs->refJLastname: SUB
		//prs->telRefADetail: SUB
		//prs->emlRefADetail: SUB

		dbsfmnc->tblfmncmperson->insertRec(prs);
		impcnt++;

		for (unsigned int ix1=0;ix1<prs->imeiampersondetail.nodes.size();ix1++) {
			prsAdet = prs->imeiampersondetail.nodes[ix1];

			prsAdet->refFmncMPerson = prs->ref;
			//prsAdet->x1SrefKType: TBL
			//prsAdet->Val: TBL

			dbsfmnc->tblfmncampersondetail->insertRec(prsAdet);
			impcnt++;

			if (prsAdet->x1SrefKType == "tel") {
				prs->telRefADetail = prsAdet->ref;
				prs->Tel = prsAdet->Val;

				dbsfmnc->tblfmncmperson->updateRec(prs);

			} else if (prsAdet->x1SrefKType == "eml") {
				prs->emlRefADetail = prsAdet->ref;
				prs->Eml = prsAdet->Val;

				dbsfmnc->tblfmncmperson->updateRec(prs);
			};
		};

		for (unsigned int ix1=0;ix1<prs->imeijmpersonlastname.nodes.size();ix1++) {
			prsJlnm = prs->imeijmpersonlastname.nodes[ix1];

			prsJlnm->refFmncMPerson = prs->ref;
			//prsJlnm->Lastname: TBL

			dbsfmnc->tblfmncjmpersonlastname->insertRec(prsJlnm);
			impcnt++;
		};

		if (prs->imeijmpersonlastname.nodes.size() > 0) {
			prsJlnm = prs->imeijmpersonlastname.nodes[0];

			prs->refJLastname = prsJlnm->ref;
			prs->Lastname = prsJlnm->Lastname;
			
			dbsfmnc->tblfmncmperson->updateRec(prs);
		};

		for (unsigned int ix1=0;ix1<prs->imeimaddress2.nodes.size();ix1++) {
			adr2 = prs->imeimaddress2.nodes[ix1];

			adr2->hkIxVTbl = VecFmncVMAddressHkTbl::PRS;
			adr2->hkUref = prs->ref;
			//adr2->srefKAdrtype: TBL
			//adr2->Address1: TBL
			//adr2->Address2: TBL
			//adr2->Zipcode: TBL
			//adr2->City: TBL
			//adr2->State: TBL
			//adr2->srefKCountry: TBL

			dbsfmnc->tblfmncmaddress->insertRec(adr2);
			impcnt++;
		};

		if (prs->imeimaddress2.nodes.size() > 0) {
			adr2 = prs->imeimaddress2.nodes[0];

			prs->refFmncMAddress = adr2->ref;
			
			dbsfmnc->tblfmncmperson->updateRec(prs);
		};
	};

	// -- ImeIRMOrgMPerson
	for (unsigned int ix0=0;ix0<imeirmorgmperson.nodes.size();ix0++) {
		orgRprs = imeirmorgmperson.nodes[ix0];

		//orgRprs->refFmncMPerson: PREVIMP
		for (unsigned int i=0;i<imeimperson.nodes.size();i++) {
			prs = imeimperson.nodes[i];

			if (prs->iref == orgRprs->irefRefFmncMPerson) {
				orgRprs->refFmncMPerson = prs->ref;
				break;
			};
		};
		//orgRprs->refFmncMOrg: PREVIMP
		for (unsigned int i=0;i<imeimorg.nodes.size();i++) {
			org = imeimorg.nodes[i];

			s = org->sref;
			if (org->hsrefSupRefFmncMOrg.length() > 0) s = org->hsrefSupRefFmncMOrg + ";" + s;
			
			if (s == orgRprs->hsrefRefFmncMOrg) {
				orgRprs->refFmncMOrg = org->ref;
				break;
			};
		};
		//orgRprs->srefKFunction: TBL

		dbsfmnc->tblfmncrmorgmperson->insertRec(orgRprs);
		impcnt++;
	};
// IP import.traverse --- REND

// IP import.ppr --- IBEGIN
	for (unsigned int ix0=0;ix0<imeimperson.nodes.size();ix0++) {
		prs = imeimperson.nodes[ix0];

		for (unsigned int i=0;i<imeirmorgmperson.nodes.size();i++) {
			orgRprs = imeirmorgmperson.nodes[i];
			
			if (prs->ref == orgRprs->refFmncMPerson) {
				prs->refROrg = orgRprs->ref;
				prs->refFmncMOrg = orgRprs->refFmncMOrg;

				dbsfmnc->tblfmncmperson->updateRec(prs);
				
				break;
			};
		};
	};
// IP import.ppr --- IEND
};

void IexFmncOrg::collect(
			DbsFmnc* dbsfmnc
			, const map<uint,uint>& icsFmncVIop
		) {
	ImeitemIMOrg* org = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIRMOrgMPerson* orgRprs = NULL;
	ImeitemIAMOrgDetail* orgAdet = NULL;
	ImeitemIAMPersonDetail* prsAdet = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJMOrgTitle* orgJtit = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIMAddress1* adr1 = NULL;
	ImeitemIMAddress2* adr2 = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;

	uint ixFmncVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

// IP collect.traverse --- BEGIN

	// -- ImeIMOrg
	for (unsigned int ix0=0;ix0<imeimorg.nodes.size();ix0++) {
		org = imeimorg.nodes[ix0];

		if (org->ref != 0) {
			org->hsrefSupRefFmncMOrg = StubFmnc::getStubOrgHsref(dbsfmnc, org->supRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMORGDETAIL, ixFmncVIop)) {
			dbsfmnc->tblfmncamorgdetail->loadRefsByOrg(org->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) org->imeiamorgdetail.nodes.push_back(new ImeitemIAMOrgDetail(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<org->imeiamorgdetail.nodes.size();ix1++) {
			orgAdet = org->imeiamorgdetail.nodes[ix1];

			if (orgAdet->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAVKEYLISTKEY, ixFmncVIop)) {
			dbsfmnc->tblfmncavkeylistkey->loadRefsByMtbUrf(VecFmncVMaintable::TBLFMNCMORG, org->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) org->imeiavkeylistkey.nodes.push_back(new ImeitemIAVKeylistKey(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<org->imeiavkeylistkey.nodes.size();ix1++) {
			klsAkey = org->imeiavkeylistkey.nodes[ix1];

			if (klsAkey->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY, ixFmncVIop)) {
				dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
				for (unsigned int i=0;i<refs.size();i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<klsAkey->imeijavkeylistkey.nodes.size();ix2++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];

				if (kakJkey->ref != 0) {
				};
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMORGTITLE, ixFmncVIop)) {
			dbsfmnc->tblfmncjmorgtitle->loadRefsByOrg(org->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == org->refJTitle) {refs[i] = refs[0]; refs[0] = org->refJTitle; break;};
			for (unsigned int i=0;i<refs.size();i++) org->imeijmorgtitle.nodes.push_back(new ImeitemIJMOrgTitle(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<org->imeijmorgtitle.nodes.size();ix1++) {
			orgJtit = org->imeijmorgtitle.nodes[ix1];

			if (orgJtit->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMADDRESS1, ixFmncVIop)) {
			dbsfmnc->tblfmncmaddress->loadRefsByHktHku(VecFmncVMAddressHkTbl::ORG, org->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) org->imeimaddress1.nodes.push_back(new ImeitemIMAddress1(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<org->imeimaddress1.nodes.size();ix1++) {
			adr1 = org->imeimaddress1.nodes[ix1];

			if (adr1->ref != 0) {
			};
		};
	};

	// -- ImeIMPerson
	for (unsigned int ix0=0;ix0<imeimperson.nodes.size();ix0++) {
		prs = imeimperson.nodes[ix0];

		if (prs->ref != 0) {
			prs->iref = ix0+1;
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMPERSONDETAIL, ixFmncVIop)) {
			dbsfmnc->tblfmncampersondetail->loadRefsByPrs(prs->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) prs->imeiampersondetail.nodes.push_back(new ImeitemIAMPersonDetail(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<prs->imeiampersondetail.nodes.size();ix1++) {
			prsAdet = prs->imeiampersondetail.nodes[ix1];

			if (prsAdet->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMPERSONLASTNAME, ixFmncVIop)) {
			dbsfmnc->tblfmncjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
			for (unsigned int i=0;i<refs.size();i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<prs->imeijmpersonlastname.nodes.size();ix1++) {
			prsJlnm = prs->imeijmpersonlastname.nodes[ix1];

			if (prsJlnm->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMADDRESS2, ixFmncVIop)) {
			dbsfmnc->tblfmncmaddress->loadRefsByHktHku(VecFmncVMAddressHkTbl::PRS, prs->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) prs->imeimaddress2.nodes.push_back(new ImeitemIMAddress2(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<prs->imeimaddress2.nodes.size();ix1++) {
			adr2 = prs->imeimaddress2.nodes[ix1];

			if (adr2->ref != 0) {
			};
		};
	};

	// -- ImeIRMOrgMPerson
	for (unsigned int ix0=0;ix0<imeirmorgmperson.nodes.size();ix0++) {
		orgRprs = imeirmorgmperson.nodes[ix0];

		if (orgRprs->ref != 0) {
			//orgRprs->irefRefFmncMPerson: IREF
			orgRprs->hsrefRefFmncMOrg = StubFmnc::getStubOrgHsref(dbsfmnc, orgRprs->refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};
// IP collect.traverse --- END

// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexFmncOrg::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIMORG) {
				parseok = imeimorg.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMPERSON) {
				parseok = imeimperson.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIRMORGMPERSON) {
				parseok = imeirmorgmperson.readTxt(txtrd); if (!parseok) break;
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

void IexFmncOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexFmncOrg");

	if (basefound) {
		// look for XML sub-blocks
		imeimorg.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
		imeirmorgmperson.readXML(docctx, basexpath);
	} else {
		imeimorg = ImeIMOrg();
		imeimperson = ImeIMPerson();
		imeirmorgmperson = ImeIRMOrgMPerson();
	};
};

bool IexFmncOrg::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexFmncOrg::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexFmncOrg::writeTxt(
			fstream& outfile
		) {
	imeimorg.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
	imeirmorgmperson.writeTxt(outfile);
};

void IexFmncOrg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexFmncOrg");
		imeimorg.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
		imeirmorgmperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexFmncOrg::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexFmncOrg::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexFmncOrg::icsFmncVIopInsAll() {
	return {{(uint)VecVIme::IMEIMORG,VecFmncVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMORGMPERSON,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMORGDETAIL,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMPERSONDETAIL,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMORGTITLE,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecFmncVIop::INS},{(uint)VecVIme::IMEIMADDRESS1,VecFmncVIop::INS},{(uint)VecVIme::IMEIMADDRESS2,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecFmncVIop::INS}};
};

uint IexFmncOrg::getIxFmncVIop(
			const map<uint,uint>& icsFmncVIop
			, const uint ixVIme
			, uint& ixFmncVIop
		) {
	ixFmncVIop = 0;

	auto it = icsFmncVIop.find(ixVIme);
	if (it != icsFmncVIop.end()) ixFmncVIop = it->second;

	return ixFmncVIop;
};

void IexFmncOrg::handleRequest(
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

void IexFmncOrg::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
};


