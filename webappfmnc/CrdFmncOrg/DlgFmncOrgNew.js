/**
  * \file DlgFmncOrgNew.js
  * web client functionality for dialog DlgFmncOrgNew
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncOrgNew", "Cpt"));

	initCpt(contdoc, "DetCptSrf", retrieveTi(srcdoc, "TagDlgFmncOrgNew", "DetCptSrf"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgFmncOrgNew", "DetCptTit"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgFmncOrgNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgFmncOrgNew", "ButCre"));

	refresh();
};

function refresh() {
// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgFmncOrgNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgFmncOrgNew", "ButCreActive") == "true");
// IP refresh.vars --- END

// IP refresh --- BEGIN
	refreshTxf(contdoc, "DetTxfSrf", "s", retrieveCi(srcdoc, "ContIacDlgFmncOrgNew", "DetTxfSrf"), true, false, true);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgFmncOrgNew", "DetTxfTit"), true, false, true);

	refreshBut(ftrdoc, "ButCnc", ButCncActive, false);
	refreshBut(ftrdoc, "ButCre", ButCreActive, false);
// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgFmncOrgNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgFmncOrgNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncOrgNewData", scrJref, "ContIacDlgFmncOrgNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgFmncOrgNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncOrgNewData", scrJref, "ContIacDlgFmncOrgNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncOrgNewData", "ContIacDlgFmncOrgNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgNewData", "ContInfDlgFmncOrgNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgNewData", "StatAppDlgFmncOrgNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgNewData", "StatShrDlgFmncOrgNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgNewData", "TagDlgFmncOrgNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgFmncOrgNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgFmncOrgNewData") {
		handleDpchEngDlgFmncOrgNewData(dom);
	};
};

function handleDpchEngDlgFmncOrgNewData(dom) {
// IP handleDpchEngDlgFmncOrgNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncOrgNewData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//fmnc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngFmncConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngFmncAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//fmnc:DpchEngFmncAlert/fmnc:scrJref"),
							retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:ContInfFmncAlert"),
							retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgFmncOrgNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


