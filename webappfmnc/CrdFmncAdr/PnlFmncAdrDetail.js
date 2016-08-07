/**
  * \file PnlFmncAdrDetail.js
  * web client functionality for panel PnlFmncAdrDetail
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncAdrDetail", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncAdrDetail", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlFmncAdrDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncAdrDetail_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncAdrDetail", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncAdrDetail", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Detail_side").src = "./PnlFmncAdrDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncAdrDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncAdrDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptAd1", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptAd1"));
	initCpt(contcontdoc, "CptCty", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptCty"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptSta"));
	initCpt(contcontdoc, "CptHku", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptHku"));
	refreshPup(contcontdoc, srcdoc, "PupHkt", "xs", "FeedFPupHkt", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "numFPupHkt"), true, false);
	initCpt(contcontdoc, "CptAty", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptAty"));
	initCpt(contcontdoc, "CptAd2", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptAd2"));
	initCpt(contcontdoc, "CptZip", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptZip"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptSte"));
	initCpt(contcontdoc, "CptCry", retrieveTi(srcdoc, "TagFmncAdrDetail", "CptCry"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncAdrDetail", "srefIxFmncVExpstate");
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
	var height = 242; // full cont height

// IP refreshB.vars --- BEGIN

	var PupAtyAlt = (retrieveSi(srcdoc, "StatAppFmncAdrDetail", "PupAtyAlt") == "true");
	var TxfAtyValid = (retrieveSi(srcdoc, "StatShrFmncAdrDetail", "TxfAtyValid") == "true");
	var ButAtyEditAvail = (retrieveSi(srcdoc, "StatShrFmncAdrDetail", "ButAtyEditAvail") == "true");

	var PupCryAlt = (retrieveSi(srcdoc, "StatAppFmncAdrDetail", "PupCryAlt") == "true");
	var TxfCryValid = (retrieveSi(srcdoc, "StatShrFmncAdrDetail", "TxfCryValid") == "true");
	var ButCryEditAvail = (retrieveSi(srcdoc, "StatShrFmncAdrDetail", "ButCryEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrFmncAdrDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfAd1", "", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfAd1"), true, false, true);

	refreshTxf(contcontdoc, "TxfCty", "", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfCty"), true, false, true);

	refreshTxf(contcontdoc, "TxfSta", "s", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfSta"), true, false, true);

	refreshTxt(contcontdoc, "TxtHku", retrieveCi(srcdoc, "ContInfFmncAdrDetail", "TxtHku"));
	contcontdoc.getElementById("PupHkt").value = retrieveCi(srcdoc, "ContIacFmncAdrDetail", "numFPupHkt");

	if ( (PupAtyAlt == !contcontdoc.getElementById("TxfAty")) || (!PupAtyAlt == !contcontdoc.getElementById("PupAty")) ) {
		mytd = contcontdoc.getElementById("dynAty");
		clearElem(mytd);

		if (PupAtyAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAty", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupAty", ""));
	};

	if (PupAtyAlt) refreshTxf(contcontdoc, "TxfAty", "", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfAty"), true, false, TxfAtyValid);
	else refreshPup(contcontdoc, srcdoc, "PupAty", "", "FeedFPupAty", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "numFPupAty"), true, false);

	if ((ButAtyEditAvail == !contcontdoc.getElementById("ButAtyEdit"))) {
		mytd = contcontdoc.getElementById("rdynAty");
		clearElem(mytd);

		first = true;

		if (ButAtyEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButAtyEdit", "icon/edit"));
		};
	};

	refreshTxf(contcontdoc, "TxfAd2", "", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfAd2"), true, false, true);

	refreshTxf(contcontdoc, "TxfZip", "xs", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfZip"), true, false, true);

	refreshTxf(contcontdoc, "TxfSte", "", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfSte"), true, false, true);

	if ( (PupCryAlt == !contcontdoc.getElementById("TxfCry")) || (!PupCryAlt == !contcontdoc.getElementById("PupCry")) ) {
		mytd = contcontdoc.getElementById("dynCry");
		clearElem(mytd);

		if (PupCryAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCry", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupCry", ""));
	};

	if (PupCryAlt) refreshTxf(contcontdoc, "TxfCry", "", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "TxfCry"), true, false, TxfCryValid);
	else refreshPup(contcontdoc, srcdoc, "PupCry", "", "FeedFPupCry", retrieveCi(srcdoc, "ContIacFmncAdrDetail", "numFPupCry"), true, false);

	if ((ButCryEditAvail == !contcontdoc.getElementById("ButCryEdit"))) {
		mytd = contcontdoc.getElementById("rdynCry");
		clearElem(mytd);

		first = true;

		if (ButCryEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCryEdit", "icon/edit"));
		};
	};

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
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncAdrDetail", "srefIxFmncVExpstate");
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

	if (retrieveSi(srcdoc, "StatAppFmncAdrDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppFmncAdrDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncAdrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncAdrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncAdrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacFmncAdrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncAdrDetailData", scrJref, "ContIacFmncAdrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacFmncAdrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppFmncAdrDetailData", scrJref, "ContIacFmncAdrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacFmncAdrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncAdrDetailData", scrJref, "ContIacFmncAdrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "ContIacFmncAdrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "ContInfFmncAdrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "FeedFPupAty", srcdoc)) mask.push("feedFPupAty");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "FeedFPupCry", srcdoc)) mask.push("feedFPupCry");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "FeedFPupHkt", srcdoc)) mask.push("feedFPupHkt");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "StatAppFmncAdrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "StatShrFmncAdrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncAdrDetailData", "TagFmncAdrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncAdrDetailData") {
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
			if (blk.nodeName == "DpchEngFmncAdrDetailData") {
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

			} else if (blk.nodeName == "DpchEngFmncAdrDetailData") {
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


