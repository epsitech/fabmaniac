/**
  * \file PnlFmncNavLabbook.js
  * web client functionality for panel PnlFmncNavLabbook
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncNavLabbook", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getCrdwnd().changeHeight("Labbook", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Labbook_side").setAttribute("height", "30");
	doc.getElementById("Labbook_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Labbook_side").src = "./PnlFmncNavLabbook_aside.html";
	doc.getElementById("Labbook_cont").src = "./PnlFmncNavLabbook_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncNavLabbook", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Labbook_side").src = "./PnlFmncNavLabbook_bside.html";
	doc.getElementById("Labbook_cont").src = "./PnlFmncNavLabbook_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Labbook_side").contentDocument;
	contdoc = doc.getElementById("Labbook_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavLabbook", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Labbook_side").contentDocument;
	contdoc = doc.getElementById("Labbook_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Labbook_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Labbook_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavLabbook", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavLabbook", "srefIxFmncVExpstate");
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
	var height = 586; // full cont height

// IP refreshB.vars --- BEGIN
	var LstStpAlt = (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstStpAlt") == "true");
	var LstStpAvail = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "LstStpAvail") == "true");
	var ButStpViewAvail = !LstStpAlt;
	var ButStpViewActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButStpViewActive") == "true");

	var LstPrjAlt = (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstPrjAlt") == "true");
	var LstPrjAvail = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "LstPrjAvail") == "true");
	var ButPrjViewAvail = !LstPrjAlt;
	var ButPrjViewActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButPrjViewActive") == "true");

	var LstRunAlt = (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstRunAlt") == "true");
	var LstRunAvail = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "LstRunAvail") == "true");
	var ButRunViewAvail = !LstRunAlt;
	var ButRunViewActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButRunViewActive") == "true");

	var LstActAlt = (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstActAlt") == "true");
	var LstActAvail = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "LstActAvail") == "true");
	var ButActViewAvail = !LstActAlt;
	var ButActViewActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButActViewActive") == "true");
	var ButActNewcrdActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButActNewcrdActive") == "true");

	var LstSepAlt = (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstSepAlt") == "true");
	var LstSepAvail = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "LstSepAvail") == "true");
	var ButSepViewAvail = !LstSepAlt;
	var ButSepViewActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButSepViewActive") == "true");
	var ButSepNewcrdActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButSepNewcrdActive") == "true");

	var LstSmpAlt = (retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstSmpAlt") == "true");
	var LstSmpAvail = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "LstSmpAvail") == "true");
	var ButSmpViewAvail = !LstSmpAlt;
	var ButSmpViewActive = (retrieveSi(srcdoc, "StatShrFmncNavLabbook", "ButSmpViewActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Stp", LstStpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Stp2", LstStpAvail && !LstStpAlt, 71);
	if (LstStpAvail) {
		if ( (LstStpAlt == !contcontdoc.getElementById("ButStpExpand")) || (!LstStpAlt == !contcontdoc.getElementById("ButStpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynStp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptStp", retrieveTi(srcdoc, "TagFmncNavLabbook", "CptStp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstStpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButStpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButStpCollapse", "icon/collapse"));
		};

		if (!LstStpAlt == !contcontdoc.getElementById("LstStp")) {
			mytd = contcontdoc.getElementById("rdynStp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynStp");
			clearElem(mytd);

			if (LstStpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstStp", true));
			};

		} else {
			if (!LstStpAlt) refreshLst(contcontdoc.getElementById("LstStp").contentWindow.document, srcdoc, false, "FeedFLstStp",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstStpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numFLstStp"))]);
		};

		if ((ButStpViewAvail == !contcontdoc.getElementById("ButStpView")) || !contcontdoc.getElementById("ButStpNewcrd")) {
			if (LstStpAlt) mytd = contcontdoc.getElementById("dynStp");
			else mytd = contcontdoc.getElementById("rdynStp");
			clearElem(mytd);

			first = true;

			if (ButStpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButStpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButStpNewcrd", "icon/newcrd"));
		};

		if (ButStpViewAvail) refreshButicon(contcontdoc, "ButStpView", "icon/view", ButStpViewActive, false);

	} else setCtlAvail(contcontdoc, "Stp2", false, 0);

	height -= setCtlAvail(contcontdoc, "Prj", LstPrjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prj2", LstPrjAvail && !LstPrjAlt, 71);
	if (LstPrjAvail) {
		if ( (LstPrjAlt == !contcontdoc.getElementById("ButPrjExpand")) || (!LstPrjAlt == !contcontdoc.getElementById("ButPrjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagFmncNavLabbook", "CptPrj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrjCollapse", "icon/collapse"));
		};

		if (!LstPrjAlt == !contcontdoc.getElementById("LstPrj")) {
			mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrj");
			clearElem(mytd);

			if (LstPrjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrj", true));
			};

		} else {
			if (!LstPrjAlt) refreshLst(contcontdoc.getElementById("LstPrj").contentWindow.document, srcdoc, false, "FeedFLstPrj",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstPrjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numFLstPrj"))]);
		};

		if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView")) || !contcontdoc.getElementById("ButPrjNewcrd")) {
			if (LstPrjAlt) mytd = contcontdoc.getElementById("dynPrj");
			else mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);

			first = true;

			if (ButPrjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjNewcrd", "icon/newcrd"));
		};

		if (ButPrjViewAvail) refreshButicon(contcontdoc, "ButPrjView", "icon/view", ButPrjViewActive, false);

	} else setCtlAvail(contcontdoc, "Prj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Run", LstRunAvail, 96);
	height -= setCtlAvail(contcontdoc, "Run2", LstRunAvail && !LstRunAlt, 71);
	if (LstRunAvail) {
		if ( (LstRunAlt == !contcontdoc.getElementById("ButRunExpand")) || (!LstRunAlt == !contcontdoc.getElementById("ButRunCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynRun");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptRun", retrieveTi(srcdoc, "TagFmncNavLabbook", "CptRun")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRunAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRunExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRunCollapse", "icon/collapse"));
		};

		if (!LstRunAlt == !contcontdoc.getElementById("LstRun")) {
			mytd = contcontdoc.getElementById("rdynRun");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynRun");
			clearElem(mytd);

			if (LstRunAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstRun", true));
			};

		} else {
			if (!LstRunAlt) refreshLst(contcontdoc.getElementById("LstRun").contentWindow.document, srcdoc, false, "FeedFLstRun",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstRunNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numFLstRun"))]);
		};

		if ((ButRunViewAvail == !contcontdoc.getElementById("ButRunView")) || !contcontdoc.getElementById("ButRunNewcrd")) {
			if (LstRunAlt) mytd = contcontdoc.getElementById("dynRun");
			else mytd = contcontdoc.getElementById("rdynRun");
			clearElem(mytd);

			first = true;

			if (ButRunViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRunView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRunNewcrd", "icon/newcrd"));
		};

		if (ButRunViewAvail) refreshButicon(contcontdoc, "ButRunView", "icon/view", ButRunViewActive, false);

	} else setCtlAvail(contcontdoc, "Run2", false, 0);

	height -= setCtlAvail(contcontdoc, "Act", LstActAvail, 96);
	height -= setCtlAvail(contcontdoc, "Act2", LstActAvail && !LstActAlt, 71);
	if (LstActAvail) {
		if ( (LstActAlt == !contcontdoc.getElementById("ButActExpand")) || (!LstActAlt == !contcontdoc.getElementById("ButActCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynAct");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptAct", retrieveTi(srcdoc, "TagFmncNavLabbook", "CptAct")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstActAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButActExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButActCollapse", "icon/collapse"));
		};

		if (!LstActAlt == !contcontdoc.getElementById("LstAct")) {
			mytd = contcontdoc.getElementById("rdynAct");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynAct");
			clearElem(mytd);

			if (LstActAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstAct", true));
			};

		} else {
			if (!LstActAlt) refreshLst(contcontdoc.getElementById("LstAct").contentWindow.document, srcdoc, false, "FeedFLstAct",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstActNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numFLstAct"))]);
		};

		if ((ButActViewAvail == !contcontdoc.getElementById("ButActView")) || !contcontdoc.getElementById("ButActNewcrd")) {
			if (LstActAlt) mytd = contcontdoc.getElementById("dynAct");
			else mytd = contcontdoc.getElementById("rdynAct");
			clearElem(mytd);

			first = true;

			if (ButActViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButActView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButActNewcrd", "icon/newcrd"));
		};

		if (ButActViewAvail) refreshButicon(contcontdoc, "ButActView", "icon/view", ButActViewActive, false);
		refreshButicon(contcontdoc, "ButActNewcrd", "icon/newcrd", ButActNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Act2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sep", LstSepAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sep2", LstSepAvail && !LstSepAlt, 71);
	if (LstSepAvail) {
		if ( (LstSepAlt == !contcontdoc.getElementById("ButSepExpand")) || (!LstSepAlt == !contcontdoc.getElementById("ButSepCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSep");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSep", retrieveTi(srcdoc, "TagFmncNavLabbook", "CptSep")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSepAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSepExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSepCollapse", "icon/collapse"));
		};

		if (!LstSepAlt == !contcontdoc.getElementById("LstSep")) {
			mytd = contcontdoc.getElementById("rdynSep");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSep");
			clearElem(mytd);

			if (LstSepAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSep", true));
			};

		} else {
			if (!LstSepAlt) refreshLst(contcontdoc.getElementById("LstSep").contentWindow.document, srcdoc, false, "FeedFLstSep",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstSepNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numFLstSep"))]);
		};

		if ((ButSepViewAvail == !contcontdoc.getElementById("ButSepView")) || !contcontdoc.getElementById("ButSepNewcrd")) {
			if (LstSepAlt) mytd = contcontdoc.getElementById("dynSep");
			else mytd = contcontdoc.getElementById("rdynSep");
			clearElem(mytd);

			first = true;

			if (ButSepViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSepView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSepNewcrd", "icon/newcrd"));
		};

		if (ButSepViewAvail) refreshButicon(contcontdoc, "ButSepView", "icon/view", ButSepViewActive, false);
		refreshButicon(contcontdoc, "ButSepNewcrd", "icon/newcrd", ButSepNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Sep2", false, 0);

	height -= setCtlAvail(contcontdoc, "Smp", LstSmpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Smp2", LstSmpAvail && !LstSmpAlt, 71);
	if (LstSmpAvail) {
		if ( (LstSmpAlt == !contcontdoc.getElementById("ButSmpExpand")) || (!LstSmpAlt == !contcontdoc.getElementById("ButSmpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSmp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSmp", retrieveTi(srcdoc, "TagFmncNavLabbook", "CptSmp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSmpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSmpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSmpCollapse", "icon/collapse"));
		};

		if (!LstSmpAlt == !contcontdoc.getElementById("LstSmp")) {
			mytd = contcontdoc.getElementById("rdynSmp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSmp");
			clearElem(mytd);

			if (LstSmpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSmp", true));
			};

		} else {
			if (!LstSmpAlt) refreshLst(contcontdoc.getElementById("LstSmp").contentWindow.document, srcdoc, false, "FeedFLstSmp",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", "LstSmpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numFLstSmp"))]);
		};

		if ((ButSmpViewAvail == !contcontdoc.getElementById("ButSmpView")) || !contcontdoc.getElementById("ButSmpNewcrd")) {
			if (LstSmpAlt) mytd = contcontdoc.getElementById("dynSmp");
			else mytd = contcontdoc.getElementById("rdynSmp");
			clearElem(mytd);

			first = true;

			if (ButSmpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSmpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSmpNewcrd", "icon/newcrd"));
		};

		if (ButSmpViewAvail) refreshButicon(contcontdoc, "ButSmpView", "icon/view", ButSmpViewActive, false);

	} else setCtlAvail(contcontdoc, "Smp2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Labbook", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Labbook_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Labbook_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Labbook_cont").setAttribute("height", "" + height);
};

function refresh() {
// IP refresh.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavLabbook", "srefIxFmncVExpstate");
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
	srcdoc = doc.getElementById("Labbook_src").contentDocument;

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
	setSi(srcdoc, "StatAppFmncNavLabbook", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncNavLabbook", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavLabbookDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavLabbookDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacFmncNavLabbook", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacFmncNavLabbook", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncNavLabbookData", scrJref, "ContIacFmncNavLabbook");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppFmncNavLabbook", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppFmncNavLabbook", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacFmncNavLabbook", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "ContIacFmncNavLabbook", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "FeedFLstAct", srcdoc)) mask.push("feedFLstAct");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "FeedFLstPrj", srcdoc)) mask.push("feedFLstPrj");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "FeedFLstRun", srcdoc)) mask.push("feedFLstRun");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "FeedFLstSep", srcdoc)) mask.push("feedFLstSep");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "FeedFLstSmp", srcdoc)) mask.push("feedFLstSmp");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "FeedFLstStp", srcdoc)) mask.push("feedFLstStp");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "StatAppFmncNavLabbook", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "StatShrFmncNavLabbook", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncNavLabbookData", "TagFmncNavLabbook", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncNavLabbookData") {
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
			if (blk.nodeName == "DpchEngFmncNavLabbookData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Labbook");
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

			} else if (blk.nodeName == "DpchEngFmncNavLabbookData") {
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


