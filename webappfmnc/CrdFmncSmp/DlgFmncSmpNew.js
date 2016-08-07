/**
  * \file DlgFmncSmpNew.js
  * web client functionality for dialog DlgFmncSmpNew
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

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncSmpNew", "Cpt"));

	initCpt(contdoc, "DetCptSup", retrieveTi(srcdoc, "TagDlgFmncSmpNew", "DetCptSup"));
	initCpt(contdoc, "DetCptSrf", retrieveTi(srcdoc, "TagDlgFmncSmpNew", "DetCptSrf"));
	initCpt(contdoc, "DetCptArt", retrieveTi(srcdoc, "TagDlgFmncSmpNew", "DetCptArt"));
	initCpt(contdoc, "DetCptMat", retrieveTi(srcdoc, "TagDlgFmncSmpNew", "DetCptMat"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgFmncSmpNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgFmncSmpNew", "ButCre"));

	refresh();
};

function refresh() {
// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgFmncSmpNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgFmncSmpNew", "ButCreActive") == "true");
// IP refresh.vars --- END

// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupSup", "", "FeedFDetPupSup", retrieveCi(srcdoc, "ContIacDlgFmncSmpNew", "numFDetPupSup"), true, false);

	refreshTxf(contdoc, "DetTxfSrf", "s", retrieveCi(srcdoc, "ContIacDlgFmncSmpNew", "DetTxfSrf"), true, false, true);

	refreshPup(contdoc, srcdoc, "DetPupArt", "", "FeedFDetPupArt", retrieveCi(srcdoc, "ContIacDlgFmncSmpNew", "numFDetPupArt"), true, false);

	refreshTxf(contdoc, "DetTxfMat", "", retrieveCi(srcdoc, "ContIacDlgFmncSmpNew", "DetTxfMat"), true, false, true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgFmncSmpNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgFmncSmpNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncSmpNewData", scrJref, "ContIacDlgFmncSmpNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgFmncSmpNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncSmpNewData", scrJref, "ContIacDlgFmncSmpNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgFmncSmpNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncSmpNewData", scrJref, "ContIacDlgFmncSmpNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "ContIacDlgFmncSmpNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "ContInfDlgFmncSmpNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "FeedFDetPupArt", srcdoc)) mask.push("feedFDetPupArt");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "FeedFDetPupSup", srcdoc)) mask.push("feedFDetPupSup");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "StatAppDlgFmncSmpNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "StatShrDlgFmncSmpNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpNewData", "TagDlgFmncSmpNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgFmncSmpNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgFmncSmpNewData") {
		handleDpchEngDlgFmncSmpNewData(dom);
	};
};

function handleDpchEngDlgFmncSmpNewData(dom) {
// IP handleDpchEngDlgFmncSmpNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncSmpNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncSmpNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


