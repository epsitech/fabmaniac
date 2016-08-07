/**
  * \file DlgFmncFabNew.js
  * web client functionality for dialog DlgFmncFabNew
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

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncFabNew", "Cpt"));

	initCpt(contdoc, "DetCptOrg", retrieveTi(srcdoc, "TagDlgFmncFabNew", "DetCptOrg"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgFmncFabNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgFmncFabNew", "ButCre"));

	refresh();
};

function refresh() {
// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabNew", "ButCreActive") == "true");
// IP refresh.vars --- END

// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupOrg", "", "FeedFDetPupOrg", retrieveCi(srcdoc, "ContIacDlgFmncFabNew", "numFDetPupOrg"), true, false);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgFmncFabNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgFmncFabNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncFabNewData", scrJref, "ContIacDlgFmncFabNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "ContIacDlgFmncFabNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "ContInfDlgFmncFabNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "FeedFDetPupOrg", srcdoc)) mask.push("feedFDetPupOrg");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "StatAppDlgFmncFabNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "StatShrDlgFmncFabNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabNewData", "TagDlgFmncFabNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgFmncFabNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgFmncFabNewData") {
		handleDpchEngDlgFmncFabNewData(dom);
	};
};

function handleDpchEngDlgFmncFabNewData(dom) {
// IP handleDpchEngDlgFmncFabNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncFabNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncFabNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


