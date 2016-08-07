/**
  * \file PnlFmncNavSupply.js
  * web client functionality for panel PnlFmncNavSupply
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavSupply", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncNavSupply", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getCrdwnd().changeHeight("Supply", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Supply_side").setAttribute("height", "30");
	doc.getElementById("Supply_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Supply_side").src = "./PnlFmncNavSupply_aside.html";
	doc.getElementById("Supply_cont").src = "./PnlFmncNavSupply_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavSupply", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncNavSupply", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Supply_side").src = "./PnlFmncNavSupply_bside.html";
	doc.getElementById("Supply_cont").src = "./PnlFmncNavSupply_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Supply_side").contentDocument;
	contdoc = doc.getElementById("Supply_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavSupply", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Supply_side").contentDocument;
	contdoc = doc.getElementById("Supply_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Supply_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Supply_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavSupply", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavSupply", "srefIxFmncVExpstate");
// IP init.estapp --- END

	if (srefIxFmncVExpstate == "mind") {
		initA();
	} else if (srefIxFmncVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 298; // full cont height

// IP refreshB.vars --- BEGIN
	var LstArtAlt = (retrieveSi(srcdoc, "StatAppFmncNavSupply", "LstArtAlt") == "true");
	var LstArtAvail = (retrieveSi(srcdoc, "StatShrFmncNavSupply", "LstArtAvail") == "true");
	var ButArtViewAvail = !LstArtAlt;
	var ButArtViewActive = (retrieveSi(srcdoc, "StatShrFmncNavSupply", "ButArtViewActive") == "true");

	var LstSkiAlt = (retrieveSi(srcdoc, "StatAppFmncNavSupply", "LstSkiAlt") == "true");
	var LstSkiAvail = (retrieveSi(srcdoc, "StatShrFmncNavSupply", "LstSkiAvail") == "true");
	var ButSkiViewAvail = !LstSkiAlt;
	var ButSkiViewActive = (retrieveSi(srcdoc, "StatShrFmncNavSupply", "ButSkiViewActive") == "true");

	var LstPcoAlt = (retrieveSi(srcdoc, "StatAppFmncNavSupply", "LstPcoAlt") == "true");
	var LstPcoAvail = (retrieveSi(srcdoc, "StatShrFmncNavSupply", "LstPcoAvail") == "true");
	var ButPcoViewAvail = !LstPcoAlt;
	var ButPcoViewActive = (retrieveSi(srcdoc, "StatShrFmncNavSupply", "ButPcoViewActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Art", LstArtAvail, 96);
	height -= setCtlAvail(contcontdoc, "Art2", LstArtAvail && !LstArtAlt, 71);
	if (LstArtAvail) {
		if ( (LstArtAlt == !contcontdoc.getElementById("ButArtExpand")) || (!LstArtAlt == !contcontdoc.getElementById("ButArtCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynArt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptArt", retrieveTi(srcdoc, "TagFmncNavSupply", "CptArt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstArtAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButArtExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButArtCollapse", "icon/collapse"));
		};

		if (!LstArtAlt == !contcontdoc.getElementById("LstArt")) {
			mytd = contcontdoc.getElementById("rdynArt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynArt");
			clearElem(mytd);

			if (LstArtAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstArt", true));
			};

		} else {
			if (!LstArtAlt) refreshLst(contcontdoc.getElementById("LstArt").contentWindow.document, srcdoc, false, "FeedFLstArt",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavSupply", "LstArtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numFLstArt"))]);
		};

		if ((ButArtViewAvail == !contcontdoc.getElementById("ButArtView")) || !contcontdoc.getElementById("ButArtNewcrd")) {
			if (LstArtAlt) mytd = contcontdoc.getElementById("dynArt");
			else mytd = contcontdoc.getElementById("rdynArt");
			clearElem(mytd);

			first = true;

			if (ButArtViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButArtView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButArtNewcrd", "icon/newcrd"));
		};

		if (ButArtViewAvail) refreshButicon(contcontdoc, "ButArtView", "icon/view", ButArtViewActive, false);

	} else setCtlAvail(contcontdoc, "Art2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ski", LstSkiAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ski2", LstSkiAvail && !LstSkiAlt, 71);
	if (LstSkiAvail) {
		if ( (LstSkiAlt == !contcontdoc.getElementById("ButSkiExpand")) || (!LstSkiAlt == !contcontdoc.getElementById("ButSkiCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSki");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSki", retrieveTi(srcdoc, "TagFmncNavSupply", "CptSki")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSkiAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSkiExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSkiCollapse", "icon/collapse"));
		};

		if (!LstSkiAlt == !contcontdoc.getElementById("LstSki")) {
			mytd = contcontdoc.getElementById("rdynSki");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSki");
			clearElem(mytd);

			if (LstSkiAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSki", true));
			};

		} else {
			if (!LstSkiAlt) refreshLst(contcontdoc.getElementById("LstSki").contentWindow.document, srcdoc, false, "FeedFLstSki",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavSupply", "LstSkiNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numFLstSki"))]);
		};

		if ((ButSkiViewAvail == !contcontdoc.getElementById("ButSkiView")) || !contcontdoc.getElementById("ButSkiNewcrd")) {
			if (LstSkiAlt) mytd = contcontdoc.getElementById("dynSki");
			else mytd = contcontdoc.getElementById("rdynSki");
			clearElem(mytd);

			first = true;

			if (ButSkiViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSkiView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSkiNewcrd", "icon/newcrd"));
		};

		if (ButSkiViewAvail) refreshButicon(contcontdoc, "ButSkiView", "icon/view", ButSkiViewActive, false);

	} else setCtlAvail(contcontdoc, "Ski2", false, 0);

	height -= setCtlAvail(contcontdoc, "Pco", LstPcoAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pco2", LstPcoAvail && !LstPcoAlt, 71);
	if (LstPcoAvail) {
		if ( (LstPcoAlt == !contcontdoc.getElementById("ButPcoExpand")) || (!LstPcoAlt == !contcontdoc.getElementById("ButPcoCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPco");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPco", retrieveTi(srcdoc, "TagFmncNavSupply", "CptPco")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPcoAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPcoExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPcoCollapse", "icon/collapse"));
		};

		if (!LstPcoAlt == !contcontdoc.getElementById("LstPco")) {
			mytd = contcontdoc.getElementById("rdynPco");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPco");
			clearElem(mytd);

			if (LstPcoAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPco", true));
			};

		} else {
			if (!LstPcoAlt) refreshLst(contcontdoc.getElementById("LstPco").contentWindow.document, srcdoc, false, "FeedFLstPco",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavSupply", "LstPcoNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numFLstPco"))]);
		};

		if ((ButPcoViewAvail == !contcontdoc.getElementById("ButPcoView")) || !contcontdoc.getElementById("ButPcoNewcrd")) {
			if (LstPcoAlt) mytd = contcontdoc.getElementById("dynPco");
			else mytd = contcontdoc.getElementById("rdynPco");
			clearElem(mytd);

			first = true;

			if (ButPcoViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPcoView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPcoNewcrd", "icon/newcrd"));
		};

		if (ButPcoViewAvail) refreshButicon(contcontdoc, "ButPcoView", "icon/view", ButPcoViewActive, false);

	} else setCtlAvail(contcontdoc, "Pco2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Supply", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Supply_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Supply_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Supply_cont").setAttribute("height", "" + height);
};

function refresh() {
// IP refresh.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavSupply", "srefIxFmncVExpstate");
// IP refresh.estapp --- END

	if (srefIxFmncVExpstate == "mind") {
		refreshA();
	} else if (srefIxFmncVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Supply_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncNavSupply", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncNavSupply", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavSupplyDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavSupplyDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavSupply", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavSupply", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacFmncNavSupply", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacFmncNavSupply", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncNavSupplyData", scrJref, "ContIacFmncNavSupply");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppFmncNavSupply", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppFmncNavSupply", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacFmncNavSupply", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "ContIacFmncNavSupply", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "FeedFLstArt", srcdoc)) mask.push("feedFLstArt");
	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "FeedFLstPco", srcdoc)) mask.push("feedFLstPco");
	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "FeedFLstSki", srcdoc)) mask.push("feedFLstSki");
	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "StatAppFmncNavSupply", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "StatShrFmncNavSupply", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncNavSupplyData", "TagFmncNavSupply", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncNavSupplyData") {
// IP handleDpchEng.estapp --- BEGIN
		mergeDpchEngData(dom);
		refresh();
// IP handleDpchEng.estapp --- END
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngFmncNavSupplyData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Supply");
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

			} else if (blk.nodeName == "DpchEngFmncNavSupplyData") {
// IP handleDpchAppDataDoReply.estapp --- BEGIN
				mergeDpchEngData(dom);
				refresh();
// IP handleDpchAppDataDoReply.estapp --- END
			};
		};
	};
};

// IP handleDpchAppDoCrdopenReply --- BEGIN
function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngFmncConfirm") {
				accepted = retrieveValue(dom, "//fmnc:DpchEngFmncConfirm/fmnc:accepted");
				_scrJref = retrieveValue(dom, "//fmnc:DpchEngFmncConfirm/fmnc:scrJref");
				sref = retrieveValue(dom, "//fmnc:DpchEngFmncConfirm/fmnc:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngFmncAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//fmnc:DpchEngFmncAlert/fmnc:scrJref"),
						retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:ContInfFmncAlert"),
						retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:FeedFMcbAlert"));
			};
		};
	};
};
// IP handleDpchAppDoCrdopenReply --- END


