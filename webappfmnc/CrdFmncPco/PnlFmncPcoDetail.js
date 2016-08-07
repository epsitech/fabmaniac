/**
  * \file PnlFmncPcoDetail.js
  * web client functionality for panel PnlFmncPcoDetail
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncPcoDetail", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncPcoDetail", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlFmncPcoDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncPcoDetail_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncPcoDetail", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncPcoDetail", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Detail_side").src = "./PnlFmncPcoDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlFmncPcoDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncPcoDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptSrf"));
	initCpt(contcontdoc, "CptDat", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptDat"));
	initCpt(contcontdoc, "CptPco", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptPco"));
	initCpt(contcontdoc, "CptSpl", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptSpl"));
	initCpt(contcontdoc, "CptFil", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptFil"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacFmncPcoDetail", "numFPupSte"), true, false);
	initCpt(contcontdoc, "CptAmt", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptAmt"));
	initCpt(contcontdoc, "CptPcp", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptPcp"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagFmncPcoDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncPcoDetail", "srefIxFmncVExpstate");
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
	var height = 317; // full cont height

// IP refreshB.vars --- BEGIN

	var ButPcoViewAvail = (retrieveSi(srcdoc, "StatShrFmncPcoDetail", "ButPcoViewAvail") == "true");

	var ButSplViewAvail = (retrieveSi(srcdoc, "StatShrFmncPcoDetail", "ButSplViewAvail") == "true");

	var ButFilViewAvail = (retrieveSi(srcdoc, "StatShrFmncPcoDetail", "ButFilViewAvail") == "true");

	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrFmncPcoDetail", "ButJEditAvail") == "true");

	var ButPcpViewAvail = (retrieveSi(srcdoc, "StatShrFmncPcoDetail", "ButPcpViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrFmncPcoDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfFmncPcoDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfDat", "s", retrieveCi(srcdoc, "ContIacFmncPcoDetail", "TxfDat"), true, false, true);

	if ((ButPcoViewAvail == !contcontdoc.getElementById("ButPcoView"))) {
		mytd = contcontdoc.getElementById("rdynPco");
		clearElem(mytd);

		first = true;

		if (ButPcoViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPcoView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPco", retrieveCi(srcdoc, "ContInfFmncPcoDetail", "TxtPco"));

	if ((ButSplViewAvail == !contcontdoc.getElementById("ButSplView"))) {
		mytd = contcontdoc.getElementById("rdynSpl");
		clearElem(mytd);

		first = true;

		if (ButSplViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSplView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSpl", retrieveCi(srcdoc, "ContInfFmncPcoDetail", "TxtSpl"));

	if ((ButFilViewAvail == !contcontdoc.getElementById("ButFilView"))) {
		mytd = contcontdoc.getElementById("rdynFil");
		clearElem(mytd);

		first = true;

		if (ButFilViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFilView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtFil", retrieveCi(srcdoc, "ContInfFmncPcoDetail", "TxtFil"));

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

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacFmncPcoDetail", "numFPupJ"), true, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacFmncPcoDetail", "numFPupSte");

	refreshTxf(contcontdoc, "TxfAmt", "s", retrieveCi(srcdoc, "ContIacFmncPcoDetail", "TxfAmt"), true, false, true);

	if ((ButPcpViewAvail == !contcontdoc.getElementById("ButPcpView"))) {
		mytd = contcontdoc.getElementById("rdynPcp");
		clearElem(mytd);

		first = true;

		if (ButPcpViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPcpView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPcp", retrieveCi(srcdoc, "ContInfFmncPcoDetail", "TxtPcp"));

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacFmncPcoDetail", "TxfCmt"), true, false, true);

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
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncPcoDetail", "srefIxFmncVExpstate");
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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncPcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncPcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncPcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacFmncPcoDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncPcoDetailData", scrJref, "ContIacFmncPcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacFmncPcoDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppFmncPcoDetailData", scrJref, "ContIacFmncPcoDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacFmncPcoDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncPcoDetailData", scrJref, "ContIacFmncPcoDetail");
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

	setCi(srcdoc, "ContIacFmncPcoDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncPcoDetailData", scrJref, "ContIacFmncPcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "ContIacFmncPcoDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "ContInfFmncPcoDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "StatAppFmncPcoDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "StatShrFmncPcoDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncPcoDetailData", "TagFmncPcoDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncPcoDetailData") {
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
			if (blk.nodeName == "DpchEngFmncPcoDetailData") {
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

			} else if (blk.nodeName == "DpchEngFmncPcoDetailData") {
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


