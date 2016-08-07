/**
  * \file DlgFmncSmpGenrep.js
  * web client functionality for dialog DlgFmncSmpGenrep
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initOpt() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initOpt --- BEGIN
// IP initOpt --- END

	setSi(srcdoc, "StatAppDlgFmncSmpGenrep", "initdone", "true");

	refreshOpt();
};

function initGen() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initGen --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgFmncSmpGenrepGen", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgFmncSmpGenrepGen", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgFmncSmpGenrepGen", "ButSto"));
// IP initGen --- END

	setSi(srcdoc, "StatAppDlgFmncSmpGenrep", "initdone", "true");

	refreshGen();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgFmncSmpGenrepFia", "Dld"));
// IP initFia --- END

	setSi(srcdoc, "StatAppDlgFmncSmpGenrep", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncSmpGenrep", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgFmncSmpGenrep", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncSmpGenrep", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=3 ; num++) {
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

function refreshOpt() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshOpt.vars --- BEGIN
// IP refreshOpt.vars --- END

// IP refreshOpt --- BEGIN
// IP refreshOpt --- END
};

function refreshGen() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshGen.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgFmncSmpGenrepGen", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgFmncSmpGenrepGen", "ButStoActive") == "true");

// IP refreshGen.vars --- END

// IP refreshGen --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgFmncSmpGenrepGen", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshGen --- END
};

function refreshFia() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshFia.vars --- BEGIN

// IP refreshFia.vars --- END

// IP refreshFia --- BEGIN

// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgFmncSmpGenrep", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgFmncSmpGenrep", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgFmncSmpGenrep" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Opt") {
			refreshOpt();
		} else if (shortDit == "Gen") {
			refreshGen();
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

// --- specific event handlers for app controls of dialog item Opt

// --- specific event handlers for app controls of dialog item Gen

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgFmncSmpGenrepDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncSmpGenrep", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgFmncSmpGenrep", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgFmncSmpGenrep", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncSmpGenrepData", scrJref, "ContIacDlgFmncSmpGenrep");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "ContIacDlgFmncSmpGenrep", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "ContInfDlgFmncSmpGenrep", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "ContInfDlgFmncSmpGenrepGen", srcdoc)) mask.push("continfgen");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "StatAppDlgFmncSmpGenrep", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "StatShrDlgFmncSmpGenrep", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "StatShrDlgFmncSmpGenrepGen", srcdoc)) mask.push("statshrgen");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "TagDlgFmncSmpGenrep", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "TagDlgFmncSmpGenrepFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgFmncSmpGenrepData", "TagDlgFmncSmpGenrepGen", srcdoc)) mask.push("taggen");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgFmncSmpGenrepData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgFmncSmpGenrepData") {
		handleDpchEngDlgFmncSmpGenrepData(dom);
	};
};

function handleDpchEngDlgFmncSmpGenrepData(dom) {
// IP handleDpchEngDlgFmncSmpGenrepData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncSmpGenrepData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncSmpGenrepData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


