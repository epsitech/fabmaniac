/**
  * \file PnlFmncArtDetail.js
  * web client functionality for panel PnlFmncArtDetail
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncArtDetail", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncArtDetail", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlFmncArtDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncArtDetail_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncArtDetail", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncArtDetail", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Detail_side").src = "./PnlFmncArtDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncArtDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncArtDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagFmncArtDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagFmncArtDetail", "CptTit"));
	initCpt(contcontdoc, "CptOrg", retrieveTi(srcdoc, "TagFmncArtDetail", "CptOrg"));
	initCpt(contcontdoc, "CptTol", retrieveTi(srcdoc, "TagFmncArtDetail", "CptTol"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagFmncArtDetail", "CptTyp"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagFmncArtDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncArtDetail", "srefIxFmncVExpstate");
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
	var height = 217; // full cont height

// IP refreshB.vars --- BEGIN

	var ButOrgViewAvail = (retrieveSi(srcdoc, "StatShrFmncArtDetail", "ButOrgViewAvail") == "true");

	var ButTolViewAvail = (retrieveSi(srcdoc, "StatShrFmncArtDetail", "ButTolViewAvail") == "true");

	var PupTypAlt = (retrieveSi(srcdoc, "StatAppFmncArtDetail", "PupTypAlt") == "true");
	var TxfTypValid = (retrieveSi(srcdoc, "StatShrFmncArtDetail", "TxfTypValid") == "true");
	var ButTypEditAvail = (retrieveSi(srcdoc, "StatShrFmncArtDetail", "ButTypEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrFmncArtDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfFmncArtDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacFmncArtDetail", "TxfTit"), true, false, true);

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

	refreshTxt(contcontdoc, "TxtOrg", retrieveCi(srcdoc, "ContInfFmncArtDetail", "TxtOrg"));

	if ((ButTolViewAvail == !contcontdoc.getElementById("ButTolView"))) {
		mytd = contcontdoc.getElementById("rdynTol");
		clearElem(mytd);

		first = true;

		if (ButTolViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTolView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTol", retrieveCi(srcdoc, "ContInfFmncArtDetail", "TxtTol"));

	if ( (PupTypAlt == !contcontdoc.getElementById("TxfTyp")) || (!PupTypAlt == !contcontdoc.getElementById("PupTyp")) ) {
		mytd = contcontdoc.getElementById("dynTyp");
		clearElem(mytd);

		if (PupTypAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfTyp", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupTyp", ""));
	};

	if (PupTypAlt) refreshTxf(contcontdoc, "TxfTyp", "", retrieveCi(srcdoc, "ContIacFmncArtDetail", "TxfTyp"), true, false, TxfTypValid);
	else refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacFmncArtDetail", "numFPupTyp"), true, false);

	if ((ButTypEditAvail == !contcontdoc.getElementById("ButTypEdit"))) {
		mytd = contcontdoc.getElementById("rdynTyp");
		clearElem(mytd);

		first = true;

		if (ButTypEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTypEdit", "icon/edit"));
		};
	};

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacFmncArtDetail", "TxfCmt"), true, false, true);

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
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncArtDetail", "srefIxFmncVExpstate");
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

	if (retrieveSi(srcdoc, "StatAppFmncArtDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppFmncArtDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncArtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncArtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncArtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacFmncArtDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncArtDetailData", scrJref, "ContIacFmncArtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacFmncArtDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppFmncArtDetailData", scrJref, "ContIacFmncArtDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacFmncArtDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncArtDetailData", scrJref, "ContIacFmncArtDetail");
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

	setCi(srcdoc, "ContIacFmncArtDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncArtDetailData", scrJref, "ContIacFmncArtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncArtDetailData", "ContIacFmncArtDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncArtDetailData", "ContInfFmncArtDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncArtDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngFmncArtDetailData", "StatAppFmncArtDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncArtDetailData", "StatShrFmncArtDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncArtDetailData", "TagFmncArtDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncArtDetailData") {
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
			if (blk.nodeName == "DpchEngFmncArtDetailData") {
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

			} else if (blk.nodeName == "DpchEngFmncArtDetailData") {
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


