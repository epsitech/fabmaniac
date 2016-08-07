/**
  * \file DlgFmncOrgExporg.js
  * web client functionality for dialog DlgFmncOrgExporg
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initPrp() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initPrp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgFmncOrgExporgPrp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgFmncOrgExporgPrp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgFmncOrgExporgPrp", "ButSto"));
// IP initPrp --- END

	setSi(srcdoc, "StatAppDlgFmncOrgExporg", "initdone", "true");

	refreshPrp();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgFmncOrgExporgFia", "Dld"));
// IP initFia --- END

	setSi(srcdoc, "StatAppDlgFmncOrgExporg", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncOrgExporg", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgFmncOrgExporg", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncOrgExporg", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=2 ; num++) {
		sref = retrieveValue(srcdoc, "//fmnc:FeedFDse/fmnc:Fi[@num='" + num + "']/fmnc:sref");
		Title = retrieveValue(srcdoc, "//fmnc:FeedFDse/fmnc:Fi[@num='" + num + "']/fmnc:tit1");

		myspan = hdrdoc.getElementById("Cpt" + sref);
		myrect = hdrdoc.getElementById("Dit" + sref);

		setTextContent(hdrdoc, myspan, Title);

		if (num == numFDse) {
			myspan.setAttribute("class", "hdr_ditsel");
			myrect.setAttribute("class", "hdr_ditsels");
		} else {
			myspan.setAttribute("class", "hdr_dit");
			myspan.setAttribute("onclick", "handleDseSelect(" + num + ")");
			myrect.setAttribute("class", "hdr_dits");
			myrect.setAttribute("onclick", "handleDseSelect(" + num + ")");
		};
	};
};

function refreshPrp() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshPrp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgFmncOrgExporgPrp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgFmncOrgExporgPrp", "ButStoActive") == "true");

// IP refreshPrp.vars --- END

// IP refreshPrp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgFmncOrgExporgPrp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshPrp --- END
};

function refreshFia() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshFia.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgFmncOrgExporgFia", "DldActive") == "true");

// IP refreshFia.vars --- END

// IP refreshFia --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgFmncOrgExporg", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgFmncOrgExporg", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgFmncOrgExporg" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Prp") {
			refreshPrp();
		} else if (shortDit == "Fia") {
			refreshFia();
		};
	};

// IP refresh --- BEGIN
	refreshBut(ftrdoc, "ButDne", ButDneActive, false);
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

// --- specific event handlers for app controls of dialog item Prp

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgFmncOrgExporgDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncOrgExporg", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgFmncOrgExporg", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgFmncOrgExporg", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncOrgExporgData", scrJref, "ContIacDlgFmncOrgExporg");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "ContIacDlgFmncOrgExporg", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "ContInfDlgFmncOrgExporg", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "ContInfDlgFmncOrgExporgPrp", srcdoc)) mask.push("continfprp");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "StatAppDlgFmncOrgExporg", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "StatShrDlgFmncOrgExporg", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "StatShrDlgFmncOrgExporgFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "StatShrDlgFmncOrgExporgPrp", srcdoc)) mask.push("statshrprp");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "TagDlgFmncOrgExporg", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "TagDlgFmncOrgExporgFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgFmncOrgExporgData", "TagDlgFmncOrgExporgPrp", srcdoc)) mask.push("tagprp");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgFmncOrgExporgData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgFmncOrgExporgData") {
		handleDpchEngDlgFmncOrgExporgData(dom);
	};
};

function handleDpchEngDlgFmncOrgExporgData(dom) {
// IP handleDpchEngDlgFmncOrgExporgData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncOrgExporgData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

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

			} else if (blk.nodeName == "DpchEngDlgFmncOrgExporgData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


