/**
  * \file ApiFmnc.cpp
  * Fmnc API library global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "ApiFmnc.h"

/******************************************************************************
 class StgFmncapi
 ******************************************************************************/

StgFmncapi::StgFmncapi(
			const string ip
			, const uint port
			, const string username
			, const string password
		) : Block() {
	this->ip = ip;
	this->port = port;
	this->username = username;
	this->password = password;

	mask = {IP, PORT, USERNAME, PASSWORD};
};

bool StgFmncapi::all(
			const set<uint>& items
		) {
	if (!find(items, IP)) return false;
	if (!find(items, PORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgFmncapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgFmncapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemFmncapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgFmncapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgFmncapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemFmncapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgFmncapi::compare(
			const StgFmncapi* comp
		) {
	set<uint> items;

	if (ip.compare(comp->ip) == 0) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (username.compare(comp->username) == 0) insert(items, USERNAME);
	if (password.compare(comp->password) == 0) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiFmnc
 ******************************************************************************/

uint ApiFmnc::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngFmnc** dpcheng
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(buf, buflen, &doc, &docctx);

	uint ixFmncVDpch = VecFmncVDpch::getIx(extractRoot(doc));

	if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCACTNEWDATA) {
		*dpcheng = new DlgFmncActNew::DpchEngData();
		((DlgFmncActNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCFABEXPFABDATA) {
		*dpcheng = new DlgFmncFabExpfab::DpchEngData();
		((DlgFmncFabExpfab::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCFABIMPFABDATA) {
		*dpcheng = new DlgFmncFabImpfab::DpchEngData();
		((DlgFmncFabImpfab::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCFABNEWDATA) {
		*dpcheng = new DlgFmncFabNew::DpchEngData();
		((DlgFmncFabNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCNAVLOAINIDATA) {
		*dpcheng = new DlgFmncNavLoaini::DpchEngData();
		((DlgFmncNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCORGEXPORGDATA) {
		*dpcheng = new DlgFmncOrgExporg::DpchEngData();
		((DlgFmncOrgExporg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCORGIMPORGDATA) {
		*dpcheng = new DlgFmncOrgImporg::DpchEngData();
		((DlgFmncOrgImporg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCORGNEWDATA) {
		*dpcheng = new DlgFmncOrgNew::DpchEngData();
		((DlgFmncOrgNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCPRJEXPELBDATA) {
		*dpcheng = new DlgFmncPrjExpelb::DpchEngData();
		((DlgFmncPrjExpelb::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCPRJIMPELBDATA) {
		*dpcheng = new DlgFmncPrjImpelb::DpchEngData();
		((DlgFmncPrjImpelb::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCPRJNEWDATA) {
		*dpcheng = new DlgFmncPrjNew::DpchEngData();
		((DlgFmncPrjNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCRUNGENREPDATA) {
		*dpcheng = new DlgFmncRunGenrep::DpchEngData();
		((DlgFmncRunGenrep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCRUNNEWDATA) {
		*dpcheng = new DlgFmncRunNew::DpchEngData();
		((DlgFmncRunNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCSMPGENREPDATA) {
		*dpcheng = new DlgFmncSmpGenrep::DpchEngData();
		((DlgFmncSmpGenrep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGDLGFMNCSMPNEWDATA) {
		*dpcheng = new DlgFmncSmpNew::DpchEngData();
		((DlgFmncSmpNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACK) {
		*dpcheng = new DpchEngFmncAck();
		((DpchEngFmncAck*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACT1NSTEPDATA) {
		*dpcheng = new PnlFmncAct1NStep::DpchEngData();
		((PnlFmncAct1NStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACTDATA) {
		*dpcheng = new CrdFmncAct::DpchEngData();
		((CrdFmncAct::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACTDETAILDATA) {
		*dpcheng = new PnlFmncActDetail::DpchEngData();
		((PnlFmncActDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACTHEADBARDATA) {
		*dpcheng = new PnlFmncActHeadbar::DpchEngData();
		((PnlFmncActHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACTLISTDATA) {
		*dpcheng = new PnlFmncActList::DpchEngData();
		((PnlFmncActList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCACTRECDATA) {
		*dpcheng = new PnlFmncActRec::DpchEngData();
		((PnlFmncActRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCADRDATA) {
		*dpcheng = new CrdFmncAdr::DpchEngData();
		((CrdFmncAdr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCADRDETAILDATA) {
		*dpcheng = new PnlFmncAdrDetail::DpchEngData();
		((PnlFmncAdrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCADRHEADBARDATA) {
		*dpcheng = new PnlFmncAdrHeadbar::DpchEngData();
		((PnlFmncAdrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCADRLISTDATA) {
		*dpcheng = new PnlFmncAdrList::DpchEngData();
		((PnlFmncAdrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCADRRECDATA) {
		*dpcheng = new PnlFmncAdrRec::DpchEngData();
		((PnlFmncAdrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCALERT) {
		*dpcheng = new DpchEngFmncAlert();
		((DpchEngFmncAlert*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCART1NSAMPLEDATA) {
		*dpcheng = new PnlFmncArt1NSample::DpchEngData();
		((PnlFmncArt1NSample::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCART1NSTOCKITEMDATA) {
		*dpcheng = new PnlFmncArt1NStockitem::DpchEngData();
		((PnlFmncArt1NStockitem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTDATA) {
		*dpcheng = new CrdFmncArt::DpchEngData();
		((CrdFmncArt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTDETAILDATA) {
		*dpcheng = new PnlFmncArtDetail::DpchEngData();
		((PnlFmncArtDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTHEADBARDATA) {
		*dpcheng = new PnlFmncArtHeadbar::DpchEngData();
		((PnlFmncArtHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTLISTDATA) {
		*dpcheng = new PnlFmncArtList::DpchEngData();
		((PnlFmncArtList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTMNORGDATA) {
		*dpcheng = new PnlFmncArtMNOrg::DpchEngData();
		((PnlFmncArtMNOrg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTRECDATA) {
		*dpcheng = new PnlFmncArtRec::DpchEngData();
		((PnlFmncArtRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCARTREF1NFILEDATA) {
		*dpcheng = new PnlFmncArtRef1NFile::DpchEngData();
		((PnlFmncArtRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCBILAPOSDATA) {
		*dpcheng = new PnlFmncBilAPos::DpchEngData();
		((PnlFmncBilAPos::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCBILDATA) {
		*dpcheng = new CrdFmncBil::DpchEngData();
		((CrdFmncBil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCBILDETAILDATA) {
		*dpcheng = new PnlFmncBilDetail::DpchEngData();
		((PnlFmncBilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCBILHEADBARDATA) {
		*dpcheng = new PnlFmncBilHeadbar::DpchEngData();
		((PnlFmncBilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCBILLISTDATA) {
		*dpcheng = new PnlFmncBilList::DpchEngData();
		((PnlFmncBilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCBILRECDATA) {
		*dpcheng = new PnlFmncBilRec::DpchEngData();
		((PnlFmncBilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCCONFIRM) {
		*dpcheng = new DpchEngFmncConfirm();
		((DpchEngFmncConfirm*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFAB1NFABPROJECTDATA) {
		*dpcheng = new PnlFmncFab1NFabproject::DpchEngData();
		((PnlFmncFab1NFabproject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFAB1NFABUSERDATA) {
		*dpcheng = new PnlFmncFab1NFabuser::DpchEngData();
		((PnlFmncFab1NFabuser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABDATA) {
		*dpcheng = new CrdFmncFab::DpchEngData();
		((CrdFmncFab::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABDETAILDATA) {
		*dpcheng = new PnlFmncFabDetail::DpchEngData();
		((PnlFmncFabDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABFAB1NTOOLDATA) {
		*dpcheng = new PnlFmncFabFab1NTool::DpchEngData();
		((PnlFmncFabFab1NTool::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABHEADBARDATA) {
		*dpcheng = new PnlFmncFabHeadbar::DpchEngData();
		((PnlFmncFabHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABLISTDATA) {
		*dpcheng = new PnlFmncFabList::DpchEngData();
		((PnlFmncFabList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABMNRUNDATA) {
		*dpcheng = new PnlFmncFabMNRun::DpchEngData();
		((PnlFmncFabMNRun::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFABRECDATA) {
		*dpcheng = new PnlFmncFabRec::DpchEngData();
		((PnlFmncFabRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILDATA) {
		*dpcheng = new CrdFmncFil::DpchEngData();
		((CrdFmncFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILDETAILDATA) {
		*dpcheng = new PnlFmncFilDetail::DpchEngData();
		((PnlFmncFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILHEADBARDATA) {
		*dpcheng = new PnlFmncFilHeadbar::DpchEngData();
		((PnlFmncFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILLISTDATA) {
		*dpcheng = new PnlFmncFilList::DpchEngData();
		((PnlFmncFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILMNSAMPLEDATA) {
		*dpcheng = new PnlFmncFilMNSample::DpchEngData();
		((PnlFmncFilMNSample::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILMNSTEPDATA) {
		*dpcheng = new PnlFmncFilMNStep::DpchEngData();
		((PnlFmncFilMNStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFILRECDATA) {
		*dpcheng = new PnlFmncFilRec::DpchEngData();
		((PnlFmncFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJ1NBILLDATA) {
		*dpcheng = new PnlFmncFpj1NBill::DpchEngData();
		((PnlFmncFpj1NBill::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJDATA) {
		*dpcheng = new CrdFmncFpj::DpchEngData();
		((CrdFmncFpj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJDETAILDATA) {
		*dpcheng = new PnlFmncFpjDetail::DpchEngData();
		((PnlFmncFpjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJHEADBARDATA) {
		*dpcheng = new PnlFmncFpjHeadbar::DpchEngData();
		((PnlFmncFpjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJLISTDATA) {
		*dpcheng = new PnlFmncFpjList::DpchEngData();
		((PnlFmncFpjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJMNFABUSERDATA) {
		*dpcheng = new PnlFmncFpjMNFabuser::DpchEngData();
		((PnlFmncFpjMNFabuser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFPJRECDATA) {
		*dpcheng = new PnlFmncFpjRec::DpchEngData();
		((PnlFmncFpjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSDATA) {
		*dpcheng = new CrdFmncFus::DpchEngData();
		((CrdFmncFus::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSDETAILDATA) {
		*dpcheng = new PnlFmncFusDetail::DpchEngData();
		((PnlFmncFusDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSHEADBARDATA) {
		*dpcheng = new PnlFmncFusHeadbar::DpchEngData();
		((PnlFmncFusHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSLISTDATA) {
		*dpcheng = new PnlFmncFusList::DpchEngData();
		((PnlFmncFusList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSMNFABPROJECTDATA) {
		*dpcheng = new PnlFmncFusMNFabproject::DpchEngData();
		((PnlFmncFusMNFabproject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSMNTOOLDATA) {
		*dpcheng = new PnlFmncFusMNTool::DpchEngData();
		((PnlFmncFusMNTool::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCFUSRECDATA) {
		*dpcheng = new PnlFmncFusRec::DpchEngData();
		((PnlFmncFusRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVADMINDATA) {
		*dpcheng = new PnlFmncNavAdmin::DpchEngData();
		((PnlFmncNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVDATA) {
		*dpcheng = new CrdFmncNav::DpchEngData();
		((CrdFmncNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVFABMGMTDATA) {
		*dpcheng = new PnlFmncNavFabmgmt::DpchEngData();
		((PnlFmncNavFabmgmt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVHEADBARDATA) {
		*dpcheng = new PnlFmncNavHeadbar::DpchEngData();
		((PnlFmncNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVLABBOOKDATA) {
		*dpcheng = new PnlFmncNavLabbook::DpchEngData();
		((PnlFmncNavLabbook::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVPREDATA) {
		*dpcheng = new PnlFmncNavPre::DpchEngData();
		((PnlFmncNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCNAVSUPPLYDATA) {
		*dpcheng = new PnlFmncNavSupply::DpchEngData();
		((PnlFmncNavSupply::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORG1NARTICLEDATA) {
		*dpcheng = new PnlFmncOrg1NArticle::DpchEngData();
		((PnlFmncOrg1NArticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORG1NSTOCKITEMDATA) {
		*dpcheng = new PnlFmncOrg1NStockitem::DpchEngData();
		((PnlFmncOrg1NStockitem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGADETAILDATA) {
		*dpcheng = new PnlFmncOrgADetail::DpchEngData();
		((PnlFmncOrgADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGBIO1NFABPROJECTDATA) {
		*dpcheng = new PnlFmncOrgBio1NFabproject::DpchEngData();
		((PnlFmncOrgBio1NFabproject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGDATA) {
		*dpcheng = new CrdFmncOrg::DpchEngData();
		((CrdFmncOrg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGDETAILDATA) {
		*dpcheng = new PnlFmncOrgDetail::DpchEngData();
		((PnlFmncOrgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGHEADBARDATA) {
		*dpcheng = new PnlFmncOrgHeadbar::DpchEngData();
		((PnlFmncOrgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGHK1NADDRESSDATA) {
		*dpcheng = new PnlFmncOrgHk1NAddress::DpchEngData();
		((PnlFmncOrgHk1NAddress::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGKSTOCKLCNDATA) {
		*dpcheng = new PnlFmncOrgKStocklcn::DpchEngData();
		((PnlFmncOrgKStocklcn::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGLISTDATA) {
		*dpcheng = new PnlFmncOrgList::DpchEngData();
		((PnlFmncOrgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGMNARTICLEDATA) {
		*dpcheng = new PnlFmncOrgMNArticle::DpchEngData();
		((PnlFmncOrgMNArticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGMNF1NTOOLDATA) {
		*dpcheng = new PnlFmncOrgMnf1NTool::DpchEngData();
		((PnlFmncOrgMnf1NTool::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGMNPERSONDATA) {
		*dpcheng = new PnlFmncOrgMNPerson::DpchEngData();
		((PnlFmncOrgMNPerson::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGPCO1NPURCHORDERDATA) {
		*dpcheng = new PnlFmncOrgPco1NPurchorder::DpchEngData();
		((PnlFmncOrgPco1NPurchorder::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGRECDATA) {
		*dpcheng = new PnlFmncOrgRec::DpchEngData();
		((PnlFmncOrgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGSPL1NPURCHORDERDATA) {
		*dpcheng = new PnlFmncOrgSpl1NPurchorder::DpchEngData();
		((PnlFmncOrgSpl1NPurchorder::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGSUP1NORGDATA) {
		*dpcheng = new PnlFmncOrgSup1NOrg::DpchEngData();
		((PnlFmncOrgSup1NOrg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCORGSVCMNTOOLDATA) {
		*dpcheng = new PnlFmncOrgSvcMNTool::DpchEngData();
		((PnlFmncOrgSvcMNTool::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPCOAPOSDATA) {
		*dpcheng = new PnlFmncPcoAPos::DpchEngData();
		((PnlFmncPcoAPos::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPCODATA) {
		*dpcheng = new CrdFmncPco::DpchEngData();
		((CrdFmncPco::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPCODETAILDATA) {
		*dpcheng = new PnlFmncPcoDetail::DpchEngData();
		((PnlFmncPcoDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPCOHEADBARDATA) {
		*dpcheng = new PnlFmncPcoHeadbar::DpchEngData();
		((PnlFmncPcoHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPCOLISTDATA) {
		*dpcheng = new PnlFmncPcoList::DpchEngData();
		((PnlFmncPcoList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPCORECDATA) {
		*dpcheng = new PnlFmncPcoRec::DpchEngData();
		((PnlFmncPcoRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRJ1NRUNDATA) {
		*dpcheng = new PnlFmncPrj1NRun::DpchEngData();
		((PnlFmncPrj1NRun::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRJDATA) {
		*dpcheng = new CrdFmncPrj::DpchEngData();
		((CrdFmncPrj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRJDETAILDATA) {
		*dpcheng = new PnlFmncPrjDetail::DpchEngData();
		((PnlFmncPrjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRJHEADBARDATA) {
		*dpcheng = new PnlFmncPrjHeadbar::DpchEngData();
		((PnlFmncPrjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRJLISTDATA) {
		*dpcheng = new PnlFmncPrjList::DpchEngData();
		((PnlFmncPrjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRJRECDATA) {
		*dpcheng = new PnlFmncPrjRec::DpchEngData();
		((PnlFmncPrjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSADETAILDATA) {
		*dpcheng = new PnlFmncPrsADetail::DpchEngData();
		((PnlFmncPrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSDATA) {
		*dpcheng = new CrdFmncPrs::DpchEngData();
		((CrdFmncPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSDETAILDATA) {
		*dpcheng = new PnlFmncPrsDetail::DpchEngData();
		((PnlFmncPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSHEADBARDATA) {
		*dpcheng = new PnlFmncPrsHeadbar::DpchEngData();
		((PnlFmncPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSHK1NADDRESSDATA) {
		*dpcheng = new PnlFmncPrsHk1NAddress::DpchEngData();
		((PnlFmncPrsHk1NAddress::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSLISTDATA) {
		*dpcheng = new PnlFmncPrsList::DpchEngData();
		((PnlFmncPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSMNORGDATA) {
		*dpcheng = new PnlFmncPrsMNOrg::DpchEngData();
		((PnlFmncPrsMNOrg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSMNRUNDATA) {
		*dpcheng = new PnlFmncPrsMNRun::DpchEngData();
		((PnlFmncPrsMNRun::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCPRSRECDATA) {
		*dpcheng = new PnlFmncPrsRec::DpchEngData();
		((PnlFmncPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNDATA) {
		*dpcheng = new CrdFmncRun::DpchEngData();
		((CrdFmncRun::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNDETAILDATA) {
		*dpcheng = new PnlFmncRunDetail::DpchEngData();
		((PnlFmncRunDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNHEADBARDATA) {
		*dpcheng = new PnlFmncRunHeadbar::DpchEngData();
		((PnlFmncRunHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNLISTDATA) {
		*dpcheng = new PnlFmncRunList::DpchEngData();
		((PnlFmncRunList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNMNFABDATA) {
		*dpcheng = new PnlFmncRunMNFab::DpchEngData();
		((PnlFmncRunMNFab::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNMNPERSONDATA) {
		*dpcheng = new PnlFmncRunMNPerson::DpchEngData();
		((PnlFmncRunMNPerson::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNMNSAMPLEDATA) {
		*dpcheng = new PnlFmncRunMNSample::DpchEngData();
		((PnlFmncRunMNSample::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNRECDATA) {
		*dpcheng = new PnlFmncRunRec::DpchEngData();
		((PnlFmncRunRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNREF1NFILEDATA) {
		*dpcheng = new PnlFmncRunRef1NFile::DpchEngData();
		((PnlFmncRunRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCRUNRUN1NACTIVITYDATA) {
		*dpcheng = new PnlFmncRunRun1NActivity::DpchEngData();
		((PnlFmncRunRun1NActivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPAPARDATA) {
		*dpcheng = new PnlFmncSepAPar::DpchEngData();
		((PnlFmncSepAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPDATA) {
		*dpcheng = new CrdFmncSep::DpchEngData();
		((CrdFmncSep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPDETAILDATA) {
		*dpcheng = new PnlFmncSepDetail::DpchEngData();
		((PnlFmncSepDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPHEADBARDATA) {
		*dpcheng = new PnlFmncSepHeadbar::DpchEngData();
		((PnlFmncSepHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPLISTDATA) {
		*dpcheng = new PnlFmncSepList::DpchEngData();
		((PnlFmncSepList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPMNFILEDATA) {
		*dpcheng = new PnlFmncSepMNFile::DpchEngData();
		((PnlFmncSepMNFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPMNSAMPLEDATA) {
		*dpcheng = new PnlFmncSepMNSample::DpchEngData();
		((PnlFmncSepMNSample::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPRECDATA) {
		*dpcheng = new PnlFmncSepRec::DpchEngData();
		((PnlFmncSepRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSEPREF1NFILEDATA) {
		*dpcheng = new PnlFmncSepRef1NFile::DpchEngData();
		((PnlFmncSepRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSKIDATA) {
		*dpcheng = new CrdFmncSki::DpchEngData();
		((CrdFmncSki::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSKIDETAILDATA) {
		*dpcheng = new PnlFmncSkiDetail::DpchEngData();
		((PnlFmncSkiDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSKIHEADBARDATA) {
		*dpcheng = new PnlFmncSkiHeadbar::DpchEngData();
		((PnlFmncSkiHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSKILISTDATA) {
		*dpcheng = new PnlFmncSkiList::DpchEngData();
		((PnlFmncSkiList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSKIRECDATA) {
		*dpcheng = new PnlFmncSkiRec::DpchEngData();
		((PnlFmncSkiRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPAPARDATA) {
		*dpcheng = new PnlFmncSmpAPar::DpchEngData();
		((PnlFmncSmpAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPDATA) {
		*dpcheng = new CrdFmncSmp::DpchEngData();
		((CrdFmncSmp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPDETAILDATA) {
		*dpcheng = new PnlFmncSmpDetail::DpchEngData();
		((PnlFmncSmpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPHEADBARDATA) {
		*dpcheng = new PnlFmncSmpHeadbar::DpchEngData();
		((PnlFmncSmpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPLISTDATA) {
		*dpcheng = new PnlFmncSmpList::DpchEngData();
		((PnlFmncSmpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPMNFILEDATA) {
		*dpcheng = new PnlFmncSmpMNFile::DpchEngData();
		((PnlFmncSmpMNFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPMNRUNDATA) {
		*dpcheng = new PnlFmncSmpMNRun::DpchEngData();
		((PnlFmncSmpMNRun::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPMNSTEPDATA) {
		*dpcheng = new PnlFmncSmpMNStep::DpchEngData();
		((PnlFmncSmpMNStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPRECDATA) {
		*dpcheng = new PnlFmncSmpRec::DpchEngData();
		((PnlFmncSmpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPREF1NFILEDATA) {
		*dpcheng = new PnlFmncSmpRef1NFile::DpchEngData();
		((PnlFmncSmpRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSMPSUP1NSAMPLEDATA) {
		*dpcheng = new PnlFmncSmpSup1NSample::DpchEngData();
		((PnlFmncSmpSup1NSample::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPAPARDATA) {
		*dpcheng = new PnlFmncStpAPar::DpchEngData();
		((PnlFmncStpAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPDATA) {
		*dpcheng = new CrdFmncStp::DpchEngData();
		((CrdFmncStp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPDETAILDATA) {
		*dpcheng = new PnlFmncStpDetail::DpchEngData();
		((PnlFmncStpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPHEADBARDATA) {
		*dpcheng = new PnlFmncStpHeadbar::DpchEngData();
		((PnlFmncStpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPKSTEPPARDATA) {
		*dpcheng = new PnlFmncStpKSteppar::DpchEngData();
		((PnlFmncStpKSteppar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPLISTDATA) {
		*dpcheng = new PnlFmncStpList::DpchEngData();
		((PnlFmncStpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPMNFILEDATA) {
		*dpcheng = new PnlFmncStpMNFile::DpchEngData();
		((PnlFmncStpMNFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPRECDATA) {
		*dpcheng = new PnlFmncStpRec::DpchEngData();
		((PnlFmncStpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPREF1NFILEDATA) {
		*dpcheng = new PnlFmncStpRef1NFile::DpchEngData();
		((PnlFmncStpRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSTPTPL1NSTEPDATA) {
		*dpcheng = new PnlFmncStpTpl1NStep::DpchEngData();
		((PnlFmncStpTpl1NStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCSUSPEND) {
		*dpcheng = new DpchEngFmncSuspend();
		((DpchEngFmncSuspend*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOL1NARTICLEDATA) {
		*dpcheng = new PnlFmncTol1NArticle::DpchEngData();
		((PnlFmncTol1NArticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLAAVLDATA) {
		*dpcheng = new PnlFmncTolAAvl::DpchEngData();
		((PnlFmncTolAAvl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLACHARDATA) {
		*dpcheng = new PnlFmncTolAChar::DpchEngData();
		((PnlFmncTolAChar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLARESDATA) {
		*dpcheng = new PnlFmncTolARes::DpchEngData();
		((PnlFmncTolARes::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLAUTILDATA) {
		*dpcheng = new PnlFmncTolAUtil::DpchEngData();
		((PnlFmncTolAUtil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLDATA) {
		*dpcheng = new CrdFmncTol::DpchEngData();
		((CrdFmncTol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLDETAILDATA) {
		*dpcheng = new PnlFmncTolDetail::DpchEngData();
		((PnlFmncTolDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLHEADBARDATA) {
		*dpcheng = new PnlFmncTolHeadbar::DpchEngData();
		((PnlFmncTolHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLKSTEPPARDATA) {
		*dpcheng = new PnlFmncTolKSteppar::DpchEngData();
		((PnlFmncTolKSteppar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLKTOOLCHARDATA) {
		*dpcheng = new PnlFmncTolKToolchar::DpchEngData();
		((PnlFmncTolKToolchar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLLISTDATA) {
		*dpcheng = new PnlFmncTolList::DpchEngData();
		((PnlFmncTolList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLMNFABUSERDATA) {
		*dpcheng = new PnlFmncTolMNFabuser::DpchEngData();
		((PnlFmncTolMNFabuser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLMNTOOLTYPEDATA) {
		*dpcheng = new PnlFmncTolMNTooltype::DpchEngData();
		((PnlFmncTolMNTooltype::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLRECDATA) {
		*dpcheng = new PnlFmncTolRec::DpchEngData();
		((PnlFmncTolRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLREF1NFILEDATA) {
		*dpcheng = new PnlFmncTolRef1NFile::DpchEngData();
		((PnlFmncTolRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLRLV1NSTEPDATA) {
		*dpcheng = new PnlFmncTolRlv1NStep::DpchEngData();
		((PnlFmncTolRlv1NStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTOLSVCMNORGDATA) {
		*dpcheng = new PnlFmncTolSvcMNOrg::DpchEngData();
		((PnlFmncTolSvcMNOrg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYDATA) {
		*dpcheng = new CrdFmncTty::DpchEngData();
		((CrdFmncTty::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYDETAILDATA) {
		*dpcheng = new PnlFmncTtyDetail::DpchEngData();
		((PnlFmncTtyDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYHEADBARDATA) {
		*dpcheng = new PnlFmncTtyHeadbar::DpchEngData();
		((PnlFmncTtyHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYKSTEPPARDATA) {
		*dpcheng = new PnlFmncTtyKSteppar::DpchEngData();
		((PnlFmncTtyKSteppar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYKTOOLCHARDATA) {
		*dpcheng = new PnlFmncTtyKToolchar::DpchEngData();
		((PnlFmncTtyKToolchar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYLISTDATA) {
		*dpcheng = new PnlFmncTtyList::DpchEngData();
		((PnlFmncTtyList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYMNTOOLDATA) {
		*dpcheng = new PnlFmncTtyMNTool::DpchEngData();
		((PnlFmncTtyMNTool::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYRECDATA) {
		*dpcheng = new PnlFmncTtyRec::DpchEngData();
		((PnlFmncTtyRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYRLV1NSTEPDATA) {
		*dpcheng = new PnlFmncTtyRlv1NStep::DpchEngData();
		((PnlFmncTtyRlv1NStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCTTYSUP1NTOOLTYPEDATA) {
		*dpcheng = new PnlFmncTtySup1NTooltype::DpchEngData();
		((PnlFmncTtySup1NTooltype::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGAACCESSDATA) {
		*dpcheng = new PnlFmncUsgAAccess::DpchEngData();
		((PnlFmncUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGDATA) {
		*dpcheng = new CrdFmncUsg::DpchEngData();
		((CrdFmncUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGDETAILDATA) {
		*dpcheng = new PnlFmncUsgDetail::DpchEngData();
		((PnlFmncUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGHEADBARDATA) {
		*dpcheng = new PnlFmncUsgHeadbar::DpchEngData();
		((PnlFmncUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGLISTDATA) {
		*dpcheng = new PnlFmncUsgList::DpchEngData();
		((PnlFmncUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGMNUSERDATA) {
		*dpcheng = new PnlFmncUsgMNUser::DpchEngData();
		((PnlFmncUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSGRECDATA) {
		*dpcheng = new PnlFmncUsgRec::DpchEngData();
		((PnlFmncUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSR1NSESSIONDATA) {
		*dpcheng = new PnlFmncUsr1NSession::DpchEngData();
		((PnlFmncUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRAACCESSDATA) {
		*dpcheng = new PnlFmncUsrAAccess::DpchEngData();
		((PnlFmncUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRDATA) {
		*dpcheng = new CrdFmncUsr::DpchEngData();
		((CrdFmncUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRDETAILDATA) {
		*dpcheng = new PnlFmncUsrDetail::DpchEngData();
		((PnlFmncUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRHEADBARDATA) {
		*dpcheng = new PnlFmncUsrHeadbar::DpchEngData();
		((PnlFmncUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRLISTDATA) {
		*dpcheng = new PnlFmncUsrList::DpchEngData();
		((PnlFmncUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRMNUSERGROUPDATA) {
		*dpcheng = new PnlFmncUsrMNUsergroup::DpchEngData();
		((PnlFmncUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCUSRRECDATA) {
		*dpcheng = new PnlFmncUsrRec::DpchEngData();
		((PnlFmncUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixFmncVDpch == VecFmncVDpch::DPCHENGSESSFMNCDATA) {
		*dpcheng = new SessFmnc::DpchEngData();
		((SessFmnc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixFmncVDpch;
};

void ApiFmnc::writeDpchApp(
			DpchAppFmnc* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};

