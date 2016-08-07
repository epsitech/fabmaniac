/**
  * \file PnlFmncNavFabmgmt.js
  * web client functionality for panel PnlFmncNavFabmgmt
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncNavFabmgmt", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getCrdwnd().changeHeight("Fabmgmt", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Fabmgmt_side").setAttribute("height", "30");
	doc.getElementById("Fabmgmt_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Fabmgmt_side").src = "./PnlFmncNavFabmgmt_aside.html";
	doc.getElementById("Fabmgmt_cont").src = "./PnlFmncNavFabmgmt_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncNavFabmgmt", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Fabmgmt_side").src = "./PnlFmncNavFabmgmt_bside.html";
	doc.getElementById("Fabmgmt_cont").src = "./PnlFmncNavFabmgmt_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Fabmgmt_side").contentDocument;
	contdoc = doc.getElementById("Fabmgmt_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Fabmgmt_side").contentDocument;
	contdoc = doc.getElementById("Fabmgmt_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Fabmgmt_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Fabmgmt_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "srefIxFmncVExpstate");
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
	var LstFabAlt = (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstFabAlt") == "true");
	var LstFabAvail = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "LstFabAvail") == "true");
	var ButFabViewAvail = !LstFabAlt;
	var ButFabViewActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButFabViewActive") == "true");

	var LstFusAlt = (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstFusAlt") == "true");
	var LstFusAvail = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "LstFusAvail") == "true");
	var ButFusViewAvail = !LstFusAlt;
	var ButFusViewActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButFusViewActive") == "true");
	var ButFusNewcrdActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButFusNewcrdActive") == "true");

	var LstTtyAlt = (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstTtyAlt") == "true");
	var LstTtyAvail = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "LstTtyAvail") == "true");
	var ButTtyViewAvail = !LstTtyAlt;
	var ButTtyViewActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButTtyViewActive") == "true");

	var LstTolAlt = (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstTolAlt") == "true");
	var LstTolAvail = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "LstTolAvail") == "true");
	var ButTolViewAvail = !LstTolAlt;
	var ButTolViewActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButTolViewActive") == "true");
	var ButTolNewcrdActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButTolNewcrdActive") == "true");

	var LstFpjAlt = (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstFpjAlt") == "true");
	var LstFpjAvail = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "LstFpjAvail") == "true");
	var ButFpjViewAvail = !LstFpjAlt;
	var ButFpjViewActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButFpjViewActive") == "true");
	var ButFpjNewcrdActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButFpjNewcrdActive") == "true");

	var LstBilAlt = (retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstBilAlt") == "true");
	var LstBilAvail = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "LstBilAvail") == "true");
	var ButBilViewAvail = !LstBilAlt;
	var ButBilViewActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButBilViewActive") == "true");
	var ButBilNewcrdActive = (retrieveSi(srcdoc, "StatShrFmncNavFabmgmt", "ButBilNewcrdActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Fab", LstFabAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fab2", LstFabAvail && !LstFabAlt, 71);
	if (LstFabAvail) {
		if ( (LstFabAlt == !contcontdoc.getElementById("ButFabExpand")) || (!LstFabAlt == !contcontdoc.getElementById("ButFabCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFab");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFab", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "CptFab")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFabAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFabExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFabCollapse", "icon/collapse"));
		};

		if (!LstFabAlt == !contcontdoc.getElementById("LstFab")) {
			mytd = contcontdoc.getElementById("rdynFab");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFab");
			clearElem(mytd);

			if (LstFabAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFab", true));
			};

		} else {
			if (!LstFabAlt) refreshLst(contcontdoc.getElementById("LstFab").contentWindow.document, srcdoc, false, "FeedFLstFab",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstFabNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numFLstFab"))]);
		};

		if ((ButFabViewAvail == !contcontdoc.getElementById("ButFabView")) || !contcontdoc.getElementById("ButFabNewcrd")) {
			if (LstFabAlt) mytd = contcontdoc.getElementById("dynFab");
			else mytd = contcontdoc.getElementById("rdynFab");
			clearElem(mytd);

			first = true;

			if (ButFabViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFabView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFabNewcrd", "icon/newcrd"));
		};

		if (ButFabViewAvail) refreshButicon(contcontdoc, "ButFabView", "icon/view", ButFabViewActive, false);

	} else setCtlAvail(contcontdoc, "Fab2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fus", LstFusAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fus2", LstFusAvail && !LstFusAlt, 71);
	if (LstFusAvail) {
		if ( (LstFusAlt == !contcontdoc.getElementById("ButFusExpand")) || (!LstFusAlt == !contcontdoc.getElementById("ButFusCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFus");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFus", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "CptFus")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFusAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFusExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFusCollapse", "icon/collapse"));
		};

		if (!LstFusAlt == !contcontdoc.getElementById("LstFus")) {
			mytd = contcontdoc.getElementById("rdynFus");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFus");
			clearElem(mytd);

			if (LstFusAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFus", true));
			};

		} else {
			if (!LstFusAlt) refreshLst(contcontdoc.getElementById("LstFus").contentWindow.document, srcdoc, false, "FeedFLstFus",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstFusNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numFLstFus"))]);
		};

		if ((ButFusViewAvail == !contcontdoc.getElementById("ButFusView")) || !contcontdoc.getElementById("ButFusNewcrd")) {
			if (LstFusAlt) mytd = contcontdoc.getElementById("dynFus");
			else mytd = contcontdoc.getElementById("rdynFus");
			clearElem(mytd);

			first = true;

			if (ButFusViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFusView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFusNewcrd", "icon/newcrd"));
		};

		if (ButFusViewAvail) refreshButicon(contcontdoc, "ButFusView", "icon/view", ButFusViewActive, false);
		refreshButicon(contcontdoc, "ButFusNewcrd", "icon/newcrd", ButFusNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Fus2", false, 0);

	height -= setCtlAvail(contcontdoc, "Tty", LstTtyAvail, 96);
	height -= setCtlAvail(contcontdoc, "Tty2", LstTtyAvail && !LstTtyAlt, 71);
	if (LstTtyAvail) {
		if ( (LstTtyAlt == !contcontdoc.getElementById("ButTtyExpand")) || (!LstTtyAlt == !contcontdoc.getElementById("ButTtyCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTty");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTty", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "CptTty")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTtyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTtyExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTtyCollapse", "icon/collapse"));
		};

		if (!LstTtyAlt == !contcontdoc.getElementById("LstTty")) {
			mytd = contcontdoc.getElementById("rdynTty");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTty");
			clearElem(mytd);

			if (LstTtyAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTty", true));
			};

		} else {
			if (!LstTtyAlt) refreshLst(contcontdoc.getElementById("LstTty").contentWindow.document, srcdoc, false, "FeedFLstTty",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstTtyNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numFLstTty"))]);
		};

		if ((ButTtyViewAvail == !contcontdoc.getElementById("ButTtyView")) || !contcontdoc.getElementById("ButTtyNewcrd")) {
			if (LstTtyAlt) mytd = contcontdoc.getElementById("dynTty");
			else mytd = contcontdoc.getElementById("rdynTty");
			clearElem(mytd);

			first = true;

			if (ButTtyViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTtyView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTtyNewcrd", "icon/newcrd"));
		};

		if (ButTtyViewAvail) refreshButicon(contcontdoc, "ButTtyView", "icon/view", ButTtyViewActive, false);

	} else setCtlAvail(contcontdoc, "Tty2", false, 0);

	height -= setCtlAvail(contcontdoc, "Tol", LstTolAvail, 96);
	height -= setCtlAvail(contcontdoc, "Tol2", LstTolAvail && !LstTolAlt, 71);
	if (LstTolAvail) {
		if ( (LstTolAlt == !contcontdoc.getElementById("ButTolExpand")) || (!LstTolAlt == !contcontdoc.getElementById("ButTolCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTol");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTol", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "CptTol")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTolAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTolExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTolCollapse", "icon/collapse"));
		};

		if (!LstTolAlt == !contcontdoc.getElementById("LstTol")) {
			mytd = contcontdoc.getElementById("rdynTol");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTol");
			clearElem(mytd);

			if (LstTolAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTol", true));
			};

		} else {
			if (!LstTolAlt) refreshLst(contcontdoc.getElementById("LstTol").contentWindow.document, srcdoc, false, "FeedFLstTol",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstTolNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numFLstTol"))]);
		};

		if ((ButTolViewAvail == !contcontdoc.getElementById("ButTolView")) || !contcontdoc.getElementById("ButTolNewcrd")) {
			if (LstTolAlt) mytd = contcontdoc.getElementById("dynTol");
			else mytd = contcontdoc.getElementById("rdynTol");
			clearElem(mytd);

			first = true;

			if (ButTolViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTolView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTolNewcrd", "icon/newcrd"));
		};

		if (ButTolViewAvail) refreshButicon(contcontdoc, "ButTolView", "icon/view", ButTolViewActive, false);
		refreshButicon(contcontdoc, "ButTolNewcrd", "icon/newcrd", ButTolNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Tol2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fpj", LstFpjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fpj2", LstFpjAvail && !LstFpjAlt, 71);
	if (LstFpjAvail) {
		if ( (LstFpjAlt == !contcontdoc.getElementById("ButFpjExpand")) || (!LstFpjAlt == !contcontdoc.getElementById("ButFpjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFpj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFpj", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "CptFpj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFpjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFpjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFpjCollapse", "icon/collapse"));
		};

		if (!LstFpjAlt == !contcontdoc.getElementById("LstFpj")) {
			mytd = contcontdoc.getElementById("rdynFpj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFpj");
			clearElem(mytd);

			if (LstFpjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFpj", true));
			};

		} else {
			if (!LstFpjAlt) refreshLst(contcontdoc.getElementById("LstFpj").contentWindow.document, srcdoc, false, "FeedFLstFpj",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstFpjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numFLstFpj"))]);
		};

		if ((ButFpjViewAvail == !contcontdoc.getElementById("ButFpjView")) || !contcontdoc.getElementById("ButFpjNewcrd")) {
			if (LstFpjAlt) mytd = contcontdoc.getElementById("dynFpj");
			else mytd = contcontdoc.getElementById("rdynFpj");
			clearElem(mytd);

			first = true;

			if (ButFpjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFpjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFpjNewcrd", "icon/newcrd"));
		};

		if (ButFpjViewAvail) refreshButicon(contcontdoc, "ButFpjView", "icon/view", ButFpjViewActive, false);
		refreshButicon(contcontdoc, "ButFpjNewcrd", "icon/newcrd", ButFpjNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Fpj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Bil", LstBilAvail, 96);
	height -= setCtlAvail(contcontdoc, "Bil2", LstBilAvail && !LstBilAlt, 71);
	if (LstBilAvail) {
		if ( (LstBilAlt == !contcontdoc.getElementById("ButBilExpand")) || (!LstBilAlt == !contcontdoc.getElementById("ButBilCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynBil");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptBil", retrieveTi(srcdoc, "TagFmncNavFabmgmt", "CptBil")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstBilAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButBilExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButBilCollapse", "icon/collapse"));
		};

		if (!LstBilAlt == !contcontdoc.getElementById("LstBil")) {
			mytd = contcontdoc.getElementById("rdynBil");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynBil");
			clearElem(mytd);

			if (LstBilAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstBil", true));
			};

		} else {
			if (!LstBilAlt) refreshLst(contcontdoc.getElementById("LstBil").contentWindow.document, srcdoc, false, "FeedFLstBil",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "LstBilNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numFLstBil"))]);
		};

		if ((ButBilViewAvail == !contcontdoc.getElementById("ButBilView")) || !contcontdoc.getElementById("ButBilNewcrd")) {
			if (LstBilAlt) mytd = contcontdoc.getElementById("dynBil");
			else mytd = contcontdoc.getElementById("rdynBil");
			clearElem(mytd);

			first = true;

			if (ButBilViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButBilView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBilNewcrd", "icon/newcrd"));
		};

		if (ButBilViewAvail) refreshButicon(contcontdoc, "ButBilView", "icon/view", ButBilViewActive, false);
		refreshButicon(contcontdoc, "ButBilNewcrd", "icon/newcrd", ButBilNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Bil2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Fabmgmt", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Fabmgmt_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Fabmgmt_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Fabmgmt_cont").setAttribute("height", "" + height);
};

function refresh() {
// IP refresh.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", "srefIxFmncVExpstate");
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
	srcdoc = doc.getElementById("Fabmgmt_src").contentDocument;

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
	setSi(srcdoc, "StatAppFmncNavFabmgmt", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncNavFabmgmt", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavFabmgmtDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavFabmgmtDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacFmncNavFabmgmt", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacFmncNavFabmgmt", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncNavFabmgmtData", scrJref, "ContIacFmncNavFabmgmt");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppFmncNavFabmgmt", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppFmncNavFabmgmt", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacFmncNavFabmgmt", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "ContIacFmncNavFabmgmt", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "FeedFLstBil", srcdoc)) mask.push("feedFLstBil");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "FeedFLstFab", srcdoc)) mask.push("feedFLstFab");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "FeedFLstFpj", srcdoc)) mask.push("feedFLstFpj");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "FeedFLstFus", srcdoc)) mask.push("feedFLstFus");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "FeedFLstTol", srcdoc)) mask.push("feedFLstTol");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "FeedFLstTty", srcdoc)) mask.push("feedFLstTty");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "StatAppFmncNavFabmgmt", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "StatShrFmncNavFabmgmt", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncNavFabmgmtData", "TagFmncNavFabmgmt", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncNavFabmgmtData") {
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
			if (blk.nodeName == "DpchEngFmncNavFabmgmtData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Fabmgmt");
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

			} else if (blk.nodeName == "DpchEngFmncNavFabmgmtData") {
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


