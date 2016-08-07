/**
  * \file DlgFmncRunNew.js
  * web client functionality for dialog DlgFmncRunNew
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

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncRunNew", "Cpt"));

	initCpt(contdoc, "DetCptPrj", retrieveTi(srcdoc, "TagDlgFmncRunNew", "DetCptPrj"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgFmncRunNew", "DetCptTit"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgFmncRunNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgFmncRunNew", "ButCre"));

	refresh();
};

function refresh() {
// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgFmncRunNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgFmncRunNew", "ButCreActive") == "true");
// IP refresh.vars --- END

// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupPrj", "", "FeedFDetPupPrj", retrieveCi(srcdoc, "ContIacDlgFmncRunNew", "numFDetPupPrj"), true, false);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgFmncRunNew", "DetTxfTit"), true, false, true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgFmncRunNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgFmncRunNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunNewData", scrJref, "ContIacDlgFmncRunNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgFmncRunNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunNewData", scrJref, "ContIacDlgFmncRunNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgFmncRunNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunNewData", scrJref, "ContIacDlgFmncRunNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "ContIacDlgFmncRunNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "ContInfDlgFmncRunNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "FeedFDetPupPrj", srcdoc)) mask.push("feedFDetPupPrj");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "StatAppDlgFmncRunNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "StatShrDlgFmncRunNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunNewData", "TagDlgFmncRunNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgFmncRunNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgFmncRunNewData") {
		handleDpchEngDlgFmncRunNewData(dom);
	};
};

function handleDpchEngDlgFmncRunNewData(dom) {
// IP handleDpchEngDlgFmncRunNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncRunNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncRunNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


