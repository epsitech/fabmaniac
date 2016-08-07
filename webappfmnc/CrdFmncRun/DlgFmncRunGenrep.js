/**
  * \file DlgFmncRunGenrep.js
  * web client functionality for dialog DlgFmncRunGenrep
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initOpt() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initOpt --- BEGIN
	initCpt(contdoc, "CptHis", retrieveTi(srcdoc, "TagDlgFmncRunGenrepOpt", "CptHis"));
	refreshRbu(contdoc, srcdoc, "RbuHis", "FeedFOptRbuHis", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuHis"), true);
	initCpt(contdoc, "CptSsu", retrieveTi(srcdoc, "TagDlgFmncRunGenrepOpt", "CptSsu"));
	initCpt(contdoc, "CptFab", retrieveTi(srcdoc, "TagDlgFmncRunGenrepOpt", "CptFab"));
	refreshRbu(contdoc, srcdoc, "RbuFab", "FeedFOptRbuFab", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuFab"), true);
	initCpt(contdoc, "CptPrs", retrieveTi(srcdoc, "TagDlgFmncRunGenrepOpt", "CptPrs"));
	refreshRbu(contdoc, srcdoc, "RbuPrs", "FeedFOptRbuPrs", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuPrs"), true);
	initCpt(contdoc, "CptFil", retrieveTi(srcdoc, "TagDlgFmncRunGenrepOpt", "CptFil"));
	refreshRbu(contdoc, srcdoc, "RbuFil", "FeedFOptRbuFil", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuFil"), true);
	initCpt(contdoc, "CptSmp", retrieveTi(srcdoc, "TagDlgFmncRunGenrepOpt", "CptSmp"));
	refreshRbu(contdoc, srcdoc, "RbuSmp", "FeedFOptRbuSmp", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuSmp"), true);
// IP initOpt --- END

	setSi(srcdoc, "StatAppDlgFmncRunGenrep", "initdone", "true");

	refreshOpt();
};

function initSto() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initSto --- BEGIN
	initCpt(contdoc, "CptDet", retrieveTi(srcdoc, "TagDlgFmncRunGenrepSto", "CptDet"));
	initCpt(contdoc, "CptFil", retrieveTi(srcdoc, "TagDlgFmncRunGenrepSto", "CptFil"));
	refreshRbu(contdoc, srcdoc, "RbuFil", "FeedFStoRbuFil", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuFil"), true);
	initCpt(contdoc, "CptCpa", retrieveTi(srcdoc, "TagDlgFmncRunGenrepSto", "CptCpa"));
	refreshRbu(contdoc, srcdoc, "RbuCpa", "FeedFStoRbuCpa", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuCpa"), true);
	initCpt(contdoc, "CptFsp", retrieveTi(srcdoc, "TagDlgFmncRunGenrepSto", "CptFsp"));
	refreshRbu(contdoc, srcdoc, "RbuFsp", "FeedFStoRbuFsp", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuFsp"), true);
	initCpt(contdoc, "CptSsp", retrieveTi(srcdoc, "TagDlgFmncRunGenrepSto", "CptSsp"));
	refreshRbu(contdoc, srcdoc, "RbuSsp", "FeedFStoRbuSsp", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuSsp"), true);
// IP initSto --- END

	setSi(srcdoc, "StatAppDlgFmncRunGenrep", "initdone", "true");

	refreshSto();
};

function initGen() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initGen --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgFmncRunGenrepGen", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgFmncRunGenrepGen", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgFmncRunGenrepGen", "ButSto"));
// IP initGen --- END

	setSi(srcdoc, "StatAppDlgFmncRunGenrep", "initdone", "true");

	refreshGen();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgFmncRunGenrepFia", "Dld"));
// IP initFia --- END

	setSi(srcdoc, "StatAppDlgFmncRunGenrep", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgFmncRunGenrep", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgFmncRunGenrep", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep", "numFDse"));

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

function refreshOpt() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshOpt.vars --- BEGIN

// IP refreshOpt.vars --- END

// IP refreshOpt --- BEGIN
	setRbuValue(contdoc, "RbuHis", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuHis"), true);

	refreshChk(contdoc, "ChkSsu", (retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "ChkSsu") == "true"), true);

	setRbuValue(contdoc, "RbuFab", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuFab"), true);

	setRbuValue(contdoc, "RbuPrs", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuPrs"), true);

	setRbuValue(contdoc, "RbuFil", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuFil"), true);

	setRbuValue(contdoc, "RbuSmp", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepOpt", "numFRbuSmp"), true);

// IP refreshOpt --- END
};

function refreshSto() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshSto.vars --- BEGIN

// IP refreshSto.vars --- END

// IP refreshSto --- BEGIN
	refreshChk(contdoc, "ChkDet", (retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "ChkDet") == "true"), true);

	setRbuValue(contdoc, "RbuFil", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuFil"), true);

	setRbuValue(contdoc, "RbuCpa", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuCpa"), true);

	setRbuValue(contdoc, "RbuFsp", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuFsp"), true);

	setRbuValue(contdoc, "RbuSsp", retrieveCi(srcdoc, "ContIacDlgFmncRunGenrepSto", "numFRbuSsp"), true);

// IP refreshSto --- END
};

function refreshGen() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshGen.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgFmncRunGenrepGen", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgFmncRunGenrepGen", "ButStoActive") == "true");

// IP refreshGen.vars --- END

// IP refreshGen --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgFmncRunGenrepGen", "TxtPrg"));

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
	var numFDse = retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgFmncRunGenrep", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgFmncRunGenrep" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Opt") {
			refreshOpt();
		} else if (shortDit == "Sto") {
			refreshSto();
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

// --- specific event handlers for app controls of dialog item Sto

// --- specific event handlers for app controls of dialog item Gen

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgFmncRunGenrepDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ditshort, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunGenrepData", scrJref, "ContIacDlgFmncRunGenrep" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgFmncRunGenrep", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgFmncRunGenrep", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunGenrepData", scrJref, "ContIacDlgFmncRunGenrep");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleLstLoad(lstdoc, ditshort, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ditshort + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgFmncRunGenrep" + ditshort, ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ditshort + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgFmncRunGenrep" + ditshort, ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numF" + ctlsref))]);
	};
};

function handleLstSelect(ditshort, ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numsF" + ctlsref));

		found = false;

		for (var i=0;i<oldNumsFLst.length;i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j=0;j<oldNumsFLst.length;j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i=0;i<oldNumsFLst.length;i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunGenrepData", scrJref, "ContIacDlgFmncRunGenrep" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ditshort, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppDlgFmncRunGenrep" + ditshort, ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ditshort + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppDlgFmncRunGenrep" + ditshort, ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ditshort + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ditshort + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numF" + ctlsref))]);
	};
};

function handleRbuSelect(_doc, ditshort, ctlsref, num) {
	setCi(srcdoc, "ContIacDlgFmncRunGenrep" + ditshort, "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgFmncRunGenrepData", scrJref, "ContIacDlgFmncRunGenrep" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "ContIacDlgFmncRunGenrep", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "ContIacDlgFmncRunGenrepOpt", srcdoc)) mask.push("contiacopt");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "ContIacDlgFmncRunGenrepSto", srcdoc)) mask.push("contiacsto");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "ContInfDlgFmncRunGenrep", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "ContInfDlgFmncRunGenrepGen", srcdoc)) mask.push("continfgen");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFOptLstSpa", srcdoc)) mask.push("feedFOptLstSpa");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFOptRbuFab", srcdoc)) mask.push("feedFOptRbuFab");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFOptRbuFil", srcdoc)) mask.push("feedFOptRbuFil");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFOptRbuHis", srcdoc)) mask.push("feedFOptRbuHis");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFOptRbuPrs", srcdoc)) mask.push("feedFOptRbuPrs");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFOptRbuSmp", srcdoc)) mask.push("feedFOptRbuSmp");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFStoLstImf", srcdoc)) mask.push("feedFStoLstImf");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFStoLstPar", srcdoc)) mask.push("feedFStoLstPar");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFStoRbuCpa", srcdoc)) mask.push("feedFStoRbuCpa");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFStoRbuFil", srcdoc)) mask.push("feedFStoRbuFil");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFStoRbuFsp", srcdoc)) mask.push("feedFStoRbuFsp");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "FeedFStoRbuSsp", srcdoc)) mask.push("feedFStoRbuSsp");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "StatAppDlgFmncRunGenrep", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "StatAppDlgFmncRunGenrepOpt", srcdoc)) mask.push("statappopt");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "StatAppDlgFmncRunGenrepSto", srcdoc)) mask.push("statappsto");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "StatShrDlgFmncRunGenrep", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "StatShrDlgFmncRunGenrepGen", srcdoc)) mask.push("statshrgen");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "TagDlgFmncRunGenrep", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "TagDlgFmncRunGenrepFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "TagDlgFmncRunGenrepGen", srcdoc)) mask.push("taggen");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "TagDlgFmncRunGenrepOpt", srcdoc)) mask.push("tagopt");
	if (updateSrcblock(dom, "DpchEngDlgFmncRunGenrepData", "TagDlgFmncRunGenrepSto", srcdoc)) mask.push("tagsto");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgFmncRunGenrepData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgFmncRunGenrepData") {
		handleDpchEngDlgFmncRunGenrepData(dom);
	};
};

function handleDpchEngDlgFmncRunGenrepData(dom) {
// IP handleDpchEngDlgFmncRunGenrepData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgFmncRunGenrepData") {
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

			} else if (blk.nodeName == "DpchEngDlgFmncRunGenrepData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


