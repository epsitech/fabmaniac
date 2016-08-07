/**
  * \file DlgFmncFabImpfab.js
  * web client functionality for dialog DlgFmncFabImpfab
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgFmncFabImpfabIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgFmncFabImpfabIfi", "Uld");
// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgFmncFabImpfab", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgFmncFabImpfabImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgFmncFabImpfabImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgFmncFabImpfabImp", "ButSto"));
// IP initImp --- END

	setSi(srcdoc, "StatAppDlgFmncFabImpfab", "initdone", "true");

	refreshImp();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initFia --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgFmncFabImpfabFia", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgFmncFabImpfabFia", "Uld");
// IP initFia --- END

	setSi(srcdoc, "StatAppDlgFmncFabImpfab", "initdone", "true");

	refreshFia();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgFmncFabImpfabLfi", "Dld"));
// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgFmncFabImpfab", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncFabImpfab", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgFmncFabImpfab", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncFabImpfab", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=4 ; num++) {
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

function refreshIfi() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshIfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabImpfabIfi", "UldActive") == "true");

// IP refreshIfi.vars --- END

// IP refreshIfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

// IP refreshIfi --- END
};

function refreshImp() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshImp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabImpfabImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabImpfabImp", "ButStoActive") == "true");

// IP refreshImp.vars --- END

// IP refreshImp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgFmncFabImpfabImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshImp --- END
};

function refreshFia() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshFia.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabImpfabFia", "UldActive") == "true");

// IP refreshFia.vars --- END

// IP refreshFia --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

// IP refreshFia --- END
};

function refreshLfi() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabImpfabLfi", "DldActive") == "true");

// IP refreshLfi.vars --- END

// IP refreshLfi --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgFmncFabImpfab", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgFmncFabImpfab", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgFmncFabImpfab" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Ifi") {
			refreshIfi();
		} else if (shortDit == "Imp") {
			refreshImp();
		} else if (shortDit == "Fia") {
			refreshFia();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Ifi

// --- specific event handlers for app controls of dialog item Imp

// --- specific event handlers for app controls of dialog item Fia

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgFmncFabImpfabDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncFabImpfab", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgFmncFabImpfab", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgFmncFabImpfab", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncFabImpfabData", scrJref, "ContIacDlgFmncFabImpfab");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "ContIacDlgFmncFabImpfab", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "ContInfDlgFmncFabImpfab", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "ContInfDlgFmncFabImpfabImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "StatAppDlgFmncFabImpfab", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "StatShrDlgFmncFabImpfab", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "StatShrDlgFmncFabImpfabFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "StatShrDlgFmncFabImpfabIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "StatShrDlgFmncFabImpfabImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "StatShrDlgFmncFabImpfabLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "TagDlgFmncFabImpfab", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "TagDlgFmncFabImpfabFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "TagDlgFmncFabImpfabIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "TagDlgFmncFabImpfabImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgFmncFabImpfabData", "TagDlgFmncFabImpfabLfi", srcdoc)) mask.push("taglfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgFmncFabImpfabData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgFmncFabImpfabData") {
		handleDpchEngDlgFmncFabImpfabData(dom);
	};
};

function handleDpchEngDlgFmncFabImpfabData(dom) {
// IP handleDpchEngDlgFmncFabImpfabData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncFabImpfabData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncFabImpfabData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


