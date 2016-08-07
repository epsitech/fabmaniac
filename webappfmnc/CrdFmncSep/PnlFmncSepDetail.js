/**
  * \file PnlFmncSepDetail.js
  * web client functionality for panel PnlFmncSepDetail
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncSepDetail", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncSepDetail", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlFmncSepDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncSepDetail_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncSepDetail", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncSepDetail", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Detail_side").src = "./PnlFmncSepDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncSepDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncSepDetail", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
// IP initB.ftrdoc --- BEGIN
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;
// IP initB.ftrdoc --- END

// IP initB --- BEGIN
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagFmncSepDetail", "CptTit"));
	initCpt(contcontdoc, "CptAct", retrieveTi(srcdoc, "TagFmncSepDetail", "CptAct"));
	initCpt(contcontdoc, "CptRlu", retrieveTi(srcdoc, "TagFmncSepDetail", "CptRlu"));
	refreshPup(contcontdoc, srcdoc, "PupRlt", "xs", "FeedFPupRlt", retrieveCi(srcdoc, "ContIacFmncSepDetail", "numFPupRlt"), true, false);
	initCpt(contcontdoc, "CptStp", retrieveTi(srcdoc, "TagFmncSepDetail", "CptStp"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagFmncSepDetail", "CptSta"));
	initCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagFmncSepDetail", "CptPrs"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncSepDetail", "srefIxFmncVExpstate");
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
	var height = 263; // full cont height

// IP refreshB.vars --- BEGIN

	var ButActViewAvail = (retrieveSi(srcdoc, "StatShrFmncSepDetail", "ButActViewAvail") == "true");

	var LstFcfAlt = (retrieveSi(srcdoc, "StatAppFmncSepDetail", "LstFcfAlt") == "true");

	var ButPrsViewAvail = (retrieveSi(srcdoc, "StatShrFmncSepDetail", "ButPrsViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrFmncSepDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacFmncSepDetail", "TxfTit"), true, false, true);

	if ((ButActViewAvail == !contcontdoc.getElementById("ButActView"))) {
		mytd = contcontdoc.getElementById("rdynAct");
		clearElem(mytd);

		first = true;

		if (ButActViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButActView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtAct", retrieveCi(srcdoc, "ContInfFmncSepDetail", "TxtAct"));

	refreshTxt(contcontdoc, "TxtRlu", retrieveCi(srcdoc, "ContInfFmncSepDetail", "TxtRlu"));
	contcontdoc.getElementById("PupRlt").value = retrieveCi(srcdoc, "ContIacFmncSepDetail", "numFPupRlt");

	refreshTxt(contcontdoc, "TxtStp", retrieveCi(srcdoc, "ContInfFmncSepDetail", "TxtStp"));

	height -= setCtlAvail(contcontdoc, "Fcf2", !LstFcfAlt, 71);
	if ( (LstFcfAlt == !contcontdoc.getElementById("ButFcfExpand")) || (!LstFcfAlt == !contcontdoc.getElementById("ButFcfCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynFcf");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptFcf", retrieveTi(srcdoc, "TagFmncSepDetail", "CptFcf")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstFcfAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFcfExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButFcfCollapse", "icon/collapse"));
	};

	if ( (LstFcfAlt == !contcontdoc.getElementById("TxtFcf")) || (!LstFcfAlt == !contcontdoc.getElementById("LstFcf")) ) {
		mytd = contcontdoc.getElementById("dynFcf");
		clearElem(mytd);

		if (LstFcfAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtFcf", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstFcf", false));
		};

	} else {
		if (!LstFcfAlt) refreshLst(contcontdoc.getElementById("LstFcf").contentWindow.document, srcdoc, true, "FeedFLstFcf",
					parseInt(retrieveSi(srcdoc, "StatAppFmncSepDetail", "LstFcfNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numsFLstFcf")));
	};

	if (LstFcfAlt) refreshTxt(contcontdoc, "TxtFcf", retrieveCi(srcdoc, "ContInfFmncSepDetail", "TxtFcf"));

	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacFmncSepDetail", "TxfSta"), true, false, true);

	if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView"))) {
		mytd = contcontdoc.getElementById("rdynPrs");
		clearElem(mytd);

		first = true;

		if (ButPrsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrs", retrieveCi(srcdoc, "ContInfFmncSepDetail", "TxtPrs"));

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
// IP refreshB --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
// IP refresh.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncSepDetail", "srefIxFmncVExpstate");
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
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncSepDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncSepDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSepDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSepDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncSepDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncSepDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacFmncSepDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacFmncSepDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncSepDetailData", scrJref, "ContIacFmncSepDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppFmncSepDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppFmncSepDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacFmncSepDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacFmncSepDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncSepDetailData", scrJref, "ContIacFmncSepDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacFmncSepDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppFmncSepDetailData", scrJref, "ContIacFmncSepDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacFmncSepDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncSepDetailData", scrJref, "ContIacFmncSepDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "ContIacFmncSepDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "ContInfFmncSepDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "FeedFLstFcf", srcdoc)) mask.push("feedFLstFcf");
	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "FeedFPupRlt", srcdoc)) mask.push("feedFPupRlt");
	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "StatAppFmncSepDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "StatShrFmncSepDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncSepDetailData", "TagFmncSepDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncSepDetailData") {
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
			if (blk.nodeName == "DpchEngFmncSepDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
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

			} else if (blk.nodeName == "DpchEngFmncSepDetailData") {
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


