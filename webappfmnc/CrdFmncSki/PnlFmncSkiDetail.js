/**
  * \file PnlFmncSkiDetail.js
  * web client functionality for panel PnlFmncSkiDetail
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncSkiDetail", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncSkiDetail", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlFmncSkiDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncSkiDetail_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncSkiDetail", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncSkiDetail", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Detail_side").src = "./PnlFmncSkiDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncSkiDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncSkiDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptOrg", retrieveTi(srcdoc, "TagFmncSkiDetail", "CptOrg"));
	initCpt(contcontdoc, "CptArt", retrieveTi(srcdoc, "TagFmncSkiDetail", "CptArt"));
	initCpt(contcontdoc, "CptQty", retrieveTi(srcdoc, "TagFmncSkiDetail", "CptQty"));
	initCpt(contcontdoc, "CptLcn", retrieveTi(srcdoc, "TagFmncSkiDetail", "CptLcn"));
	initCpt(contcontdoc, "CptExd", retrieveTi(srcdoc, "TagFmncSkiDetail", "CptExd"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagFmncSkiDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncSkiDetail", "srefIxFmncVExpstate");
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
	var height = 235; // full cont height

// IP refreshB.vars --- BEGIN
	var ButOrgViewAvail = (retrieveSi(srcdoc, "StatShrFmncSkiDetail", "ButOrgViewAvail") == "true");

	var ButArtViewAvail = (retrieveSi(srcdoc, "StatShrFmncSkiDetail", "ButArtViewAvail") == "true");

	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrFmncSkiDetail", "ButJEditAvail") == "true");

	var PupLcnAlt = (retrieveSi(srcdoc, "StatAppFmncSkiDetail", "PupLcnAlt") == "true");
	var TxfLcnValid = (retrieveSi(srcdoc, "StatShrFmncSkiDetail", "TxfLcnValid") == "true");
	var ButLcnEditAvail = (retrieveSi(srcdoc, "StatShrFmncSkiDetail", "ButLcnEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrFmncSkiDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	if ((ButOrgViewAvail == !contcontdoc.getElementById("ButOrgView"))) {
		mytd = contcontdoc.getElementById("rdynOrg");
		clearElem(mytd);

		first = true;

		if (ButOrgViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOrgView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtOrg", retrieveCi(srcdoc, "ContInfFmncSkiDetail", "TxtOrg"));

	if ((ButArtViewAvail == !contcontdoc.getElementById("ButArtView"))) {
		mytd = contcontdoc.getElementById("rdynArt");
		clearElem(mytd);

		first = true;

		if (ButArtViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButArtView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtArt", retrieveCi(srcdoc, "ContInfFmncSkiDetail", "TxtArt"));

	if ((ButJEditAvail == !contcontdoc.getElementById("ButJEdit"))) {
		mytd = contcontdoc.getElementById("rdynJ");
		clearElem(mytd);

		first = true;

		if (ButJEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacFmncSkiDetail", "numFPupJ"), true, false);

	refreshTxt(contcontdoc, "TxtQty", retrieveCi(srcdoc, "ContInfFmncSkiDetail", "TxtQty"));

	if ( (PupLcnAlt == !contcontdoc.getElementById("TxfLcn")) || (!PupLcnAlt == !contcontdoc.getElementById("PupLcn")) ) {
		mytd = contcontdoc.getElementById("dynLcn");
		clearElem(mytd);

		if (PupLcnAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfLcn", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupLcn", ""));
	};

	if (PupLcnAlt) refreshTxf(contcontdoc, "TxfLcn", "", retrieveCi(srcdoc, "ContIacFmncSkiDetail", "TxfLcn"), true, false, TxfLcnValid);
	else refreshPup(contcontdoc, srcdoc, "PupLcn", "", "FeedFPupLcn", retrieveCi(srcdoc, "ContIacFmncSkiDetail", "numFPupLcn"), true, false);

	if ((ButLcnEditAvail == !contcontdoc.getElementById("ButLcnEdit"))) {
		mytd = contcontdoc.getElementById("rdynLcn");
		clearElem(mytd);

		first = true;

		if (ButLcnEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLcnEdit", "icon/edit"));
		};
	};

	refreshTxf(contcontdoc, "TxfExd", "s", retrieveCi(srcdoc, "ContIacFmncSkiDetail", "TxfExd"), true, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacFmncSkiDetail", "TxfCmt"), true, false, true);

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
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncSkiDetail", "srefIxFmncVExpstate");
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

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppFmncSkiDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppFmncSkiDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSkiDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSkiDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSkiDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacFmncSkiDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncSkiDetailData", scrJref, "ContIacFmncSkiDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacFmncSkiDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppFmncSkiDetailData", scrJref, "ContIacFmncSkiDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacFmncSkiDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncSkiDetailData", scrJref, "ContIacFmncSkiDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacFmncSkiDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncSkiDetailData", scrJref, "ContIacFmncSkiDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "ContIacFmncSkiDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "ContInfFmncSkiDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "FeedFPupLcn", srcdoc)) mask.push("feedFPupLcn");
	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "StatAppFmncSkiDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "StatShrFmncSkiDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncSkiDetailData", "TagFmncSkiDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncSkiDetailData") {
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
			if (blk.nodeName == "DpchEngFmncSkiDetailData") {
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

			} else if (blk.nodeName == "DpchEngFmncSkiDetailData") {
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

// IP handleDpchAppDoDlgopenReply --- BEGIN
function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};
// IP handleDpchAppDoDlgopenReply --- END


