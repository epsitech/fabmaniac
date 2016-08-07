/**
  * \file DlgFmncPrjNew.js
  * web client functionality for dialog DlgFmncPrjNew
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

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncPrjNew", "Cpt"));

	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgFmncPrjNew", "DetCptTit"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgFmncPrjNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgFmncPrjNew", "ButCre"));

	refresh();
};

function refresh() {
// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgFmncPrjNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgFmncPrjNew", "ButCreActive") == "true");
// IP refresh.vars --- END

// IP refresh --- BEGIN
	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgFmncPrjNew", "DetTxfTit"), true, false, true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgFmncPrjNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgFmncPrjNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncPrjNewData", scrJref, "ContIacDlgFmncPrjNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgFmncPrjNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncPrjNewData", scrJref, "ContIacDlgFmncPrjNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncPrjNewData", "ContIacDlgFmncPrjNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncPrjNewData", "ContInfDlgFmncPrjNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncPrjNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncPrjNewData", "StatAppDlgFmncPrjNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncPrjNewData", "StatShrDlgFmncPrjNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncPrjNewData", "TagDlgFmncPrjNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgFmncPrjNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgFmncPrjNewData") {
		handleDpchEngDlgFmncPrjNewData(dom);
	};
};

function handleDpchEngDlgFmncPrjNewData(dom) {
// IP handleDpchEngDlgFmncPrjNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncPrjNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncPrjNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


