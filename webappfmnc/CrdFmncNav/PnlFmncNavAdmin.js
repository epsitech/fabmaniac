/**
  * \file PnlFmncNavAdmin.js
  * web client functionality for panel PnlFmncNavAdmin
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncNavAdmin", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	// change container heights
	getCrdwnd().changeHeight("Admin", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Admin_side").setAttribute("height", "30");
	doc.getElementById("Admin_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Admin_side").src = "./PnlFmncNavAdmin_aside.html";
	doc.getElementById("Admin_cont").src = "./PnlFmncNavAdmin_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncNavAdmin", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	// change content (container heights in refreshB)
	doc.getElementById("Admin_side").src = "./PnlFmncNavAdmin_bside.html";
	doc.getElementById("Admin_cont").src = "./PnlFmncNavAdmin_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Admin_side").contentDocument;
	contdoc = doc.getElementById("Admin_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavAdmin", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Admin_side").contentDocument;
	contdoc = doc.getElementById("Admin_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Admin_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Admin_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagFmncNavAdmin", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavAdmin", "srefIxFmncVExpstate");
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
	var LstUsgAlt = (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstUsgAlt") == "true");
	var LstUsgAvail = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "LstUsgAvail") == "true");
	var ButUsgViewAvail = !LstUsgAlt;
	var ButUsgViewActive = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "ButUsgViewActive") == "true");

	var LstUsrAlt = (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstUsrAlt") == "true");
	var LstUsrAvail = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "LstUsrAvail") == "true");
	var ButUsrViewAvail = !LstUsrAlt;
	var ButUsrViewActive = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "ButUsrViewActive") == "true");

	var LstOrgAlt = (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstOrgAlt") == "true");
	var LstOrgAvail = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "LstOrgAvail") == "true");
	var ButOrgViewAvail = !LstOrgAlt;
	var ButOrgViewActive = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "ButOrgViewActive") == "true");

	var LstPrsAlt = (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstPrsAlt") == "true");
	var LstPrsAvail = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "LstPrsAvail") == "true");
	var ButPrsViewAvail = !LstPrsAlt;
	var ButPrsViewActive = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "ButPrsViewActive") == "true");

	var LstAdrAlt = (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstAdrAlt") == "true");
	var LstAdrAvail = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "LstAdrAvail") == "true");
	var ButAdrViewAvail = !LstAdrAlt;
	var ButAdrViewActive = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "ButAdrViewActive") == "true");

	var LstFilAlt = (retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstFilAlt") == "true");
	var LstFilAvail = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "LstFilAvail") == "true");
	var ButFilViewAvail = !LstFilAlt;
	var ButFilViewActive = (retrieveSi(srcdoc, "StatShrFmncNavAdmin", "ButFilViewActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Usg", LstUsgAvail, 96);
	height -= setCtlAvail(contcontdoc, "Usg2", LstUsgAvail && !LstUsgAlt, 71);
	if (LstUsgAvail) {
		if ( (LstUsgAlt == !contcontdoc.getElementById("ButUsgExpand")) || (!LstUsgAlt == !contcontdoc.getElementById("ButUsgCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynUsg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptUsg", retrieveTi(srcdoc, "TagFmncNavAdmin", "CptUsg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstUsgAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButUsgExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButUsgCollapse", "icon/collapse"));
		};

		if (!LstUsgAlt == !contcontdoc.getElementById("LstUsg")) {
			mytd = contcontdoc.getElementById("rdynUsg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynUsg");
			clearElem(mytd);

			if (LstUsgAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstUsg", true));
			};

		} else {
			if (!LstUsgAlt) refreshLst(contcontdoc.getElementById("LstUsg").contentWindow.document, srcdoc, false, "FeedFLstUsg",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstUsgNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numFLstUsg"))]);
		};

		if ((ButUsgViewAvail == !contcontdoc.getElementById("ButUsgView")) || !contcontdoc.getElementById("ButUsgNewcrd")) {
			if (LstUsgAlt) mytd = contcontdoc.getElementById("dynUsg");
			else mytd = contcontdoc.getElementById("rdynUsg");
			clearElem(mytd);

			first = true;

			if (ButUsgViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUsgView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsgNewcrd", "icon/newcrd"));
		};

		if (ButUsgViewAvail) refreshButicon(contcontdoc, "ButUsgView", "icon/view", ButUsgViewActive, false);

	} else setCtlAvail(contcontdoc, "Usg2", false, 0);

	height -= setCtlAvail(contcontdoc, "Usr", LstUsrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Usr2", LstUsrAvail && !LstUsrAlt, 71);
	if (LstUsrAvail) {
		if ( (LstUsrAlt == !contcontdoc.getElementById("ButUsrExpand")) || (!LstUsrAlt == !contcontdoc.getElementById("ButUsrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynUsr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptUsr", retrieveTi(srcdoc, "TagFmncNavAdmin", "CptUsr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstUsrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButUsrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButUsrCollapse", "icon/collapse"));
		};

		if (!LstUsrAlt == !contcontdoc.getElementById("LstUsr")) {
			mytd = contcontdoc.getElementById("rdynUsr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynUsr");
			clearElem(mytd);

			if (LstUsrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstUsr", true));
			};

		} else {
			if (!LstUsrAlt) refreshLst(contcontdoc.getElementById("LstUsr").contentWindow.document, srcdoc, false, "FeedFLstUsr",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstUsrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numFLstUsr"))]);
		};

		if ((ButUsrViewAvail == !contcontdoc.getElementById("ButUsrView")) || !contcontdoc.getElementById("ButUsrNewcrd")) {
			if (LstUsrAlt) mytd = contcontdoc.getElementById("dynUsr");
			else mytd = contcontdoc.getElementById("rdynUsr");
			clearElem(mytd);

			first = true;

			if (ButUsrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUsrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsrNewcrd", "icon/newcrd"));
		};

		if (ButUsrViewAvail) refreshButicon(contcontdoc, "ButUsrView", "icon/view", ButUsrViewActive, false);

	} else setCtlAvail(contcontdoc, "Usr2", false, 0);

	height -= setCtlAvail(contcontdoc, "Org", LstOrgAvail, 96);
	height -= setCtlAvail(contcontdoc, "Org2", LstOrgAvail && !LstOrgAlt, 71);
	if (LstOrgAvail) {
		if ( (LstOrgAlt == !contcontdoc.getElementById("ButOrgExpand")) || (!LstOrgAlt == !contcontdoc.getElementById("ButOrgCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynOrg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptOrg", retrieveTi(srcdoc, "TagFmncNavAdmin", "CptOrg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstOrgAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOrgExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButOrgCollapse", "icon/collapse"));
		};

		if (!LstOrgAlt == !contcontdoc.getElementById("LstOrg")) {
			mytd = contcontdoc.getElementById("rdynOrg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynOrg");
			clearElem(mytd);

			if (LstOrgAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstOrg", true));
			};

		} else {
			if (!LstOrgAlt) refreshLst(contcontdoc.getElementById("LstOrg").contentWindow.document, srcdoc, false, "FeedFLstOrg",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstOrgNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numFLstOrg"))]);
		};

		if ((ButOrgViewAvail == !contcontdoc.getElementById("ButOrgView")) || !contcontdoc.getElementById("ButOrgNewcrd")) {
			if (LstOrgAlt) mytd = contcontdoc.getElementById("dynOrg");
			else mytd = contcontdoc.getElementById("rdynOrg");
			clearElem(mytd);

			first = true;

			if (ButOrgViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButOrgView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOrgNewcrd", "icon/newcrd"));
		};

		if (ButOrgViewAvail) refreshButicon(contcontdoc, "ButOrgView", "icon/view", ButOrgViewActive, false);

	} else setCtlAvail(contcontdoc, "Org2", false, 0);

	height -= setCtlAvail(contcontdoc, "Prs", LstPrsAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prs2", LstPrsAvail && !LstPrsAlt, 71);
	if (LstPrsAvail) {
		if ( (LstPrsAlt == !contcontdoc.getElementById("ButPrsExpand")) || (!LstPrsAlt == !contcontdoc.getElementById("ButPrsCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrs");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagFmncNavAdmin", "CptPrs")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrsAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrsExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrsCollapse", "icon/collapse"));
		};

		if (!LstPrsAlt == !contcontdoc.getElementById("LstPrs")) {
			mytd = contcontdoc.getElementById("rdynPrs");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrs");
			clearElem(mytd);

			if (LstPrsAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrs", true));
			};

		} else {
			if (!LstPrsAlt) refreshLst(contcontdoc.getElementById("LstPrs").contentWindow.document, srcdoc, false, "FeedFLstPrs",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstPrsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numFLstPrs"))]);
		};

		if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView")) || !contcontdoc.getElementById("ButPrsNewcrd")) {
			if (LstPrsAlt) mytd = contcontdoc.getElementById("dynPrs");
			else mytd = contcontdoc.getElementById("rdynPrs");
			clearElem(mytd);

			first = true;

			if (ButPrsViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsNewcrd", "icon/newcrd"));
		};

		if (ButPrsViewAvail) refreshButicon(contcontdoc, "ButPrsView", "icon/view", ButPrsViewActive, false);

	} else setCtlAvail(contcontdoc, "Prs2", false, 0);

	height -= setCtlAvail(contcontdoc, "Adr", LstAdrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Adr2", LstAdrAvail && !LstAdrAlt, 71);
	if (LstAdrAvail) {
		if ( (LstAdrAlt == !contcontdoc.getElementById("ButAdrExpand")) || (!LstAdrAlt == !contcontdoc.getElementById("ButAdrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynAdr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptAdr", retrieveTi(srcdoc, "TagFmncNavAdmin", "CptAdr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstAdrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButAdrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButAdrCollapse", "icon/collapse"));
		};

		if (!LstAdrAlt == !contcontdoc.getElementById("LstAdr")) {
			mytd = contcontdoc.getElementById("rdynAdr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynAdr");
			clearElem(mytd);

			if (LstAdrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstAdr", true));
			};

		} else {
			if (!LstAdrAlt) refreshLst(contcontdoc.getElementById("LstAdr").contentWindow.document, srcdoc, false, "FeedFLstAdr",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstAdrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numFLstAdr"))]);
		};

		if ((ButAdrViewAvail == !contcontdoc.getElementById("ButAdrView")) || !contcontdoc.getElementById("ButAdrNewcrd")) {
			if (LstAdrAlt) mytd = contcontdoc.getElementById("dynAdr");
			else mytd = contcontdoc.getElementById("rdynAdr");
			clearElem(mytd);

			first = true;

			if (ButAdrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButAdrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButAdrNewcrd", "icon/newcrd"));
		};

		if (ButAdrViewAvail) refreshButicon(contcontdoc, "ButAdrView", "icon/view", ButAdrViewActive, false);

	} else setCtlAvail(contcontdoc, "Adr2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fil", LstFilAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fil2", LstFilAvail && !LstFilAlt, 71);
	if (LstFilAvail) {
		if ( (LstFilAlt == !contcontdoc.getElementById("ButFilExpand")) || (!LstFilAlt == !contcontdoc.getElementById("ButFilCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFil");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFil", retrieveTi(srcdoc, "TagFmncNavAdmin", "CptFil")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFilAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFilExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFilCollapse", "icon/collapse"));
		};

		if (!LstFilAlt == !contcontdoc.getElementById("LstFil")) {
			mytd = contcontdoc.getElementById("rdynFil");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFil");
			clearElem(mytd);

			if (LstFilAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFil", true));
			};

		} else {
			if (!LstFilAlt) refreshLst(contcontdoc.getElementById("LstFil").contentWindow.document, srcdoc, false, "FeedFLstFil",
						parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", "LstFilNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numFLstFil"))]);
		};

		if ((ButFilViewAvail == !contcontdoc.getElementById("ButFilView")) || !contcontdoc.getElementById("ButFilNewcrd")) {
			if (LstFilAlt) mytd = contcontdoc.getElementById("dynFil");
			else mytd = contcontdoc.getElementById("rdynFil");
			clearElem(mytd);

			first = true;

			if (ButFilViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFilView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFilNewcrd", "icon/newcrd"));
		};

		if (ButFilViewAvail) refreshButicon(contcontdoc, "ButFilView", "icon/view", ButFilViewActive, false);

	} else setCtlAvail(contcontdoc, "Fil2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Admin", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Admin_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Admin_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Admin_cont").setAttribute("height", "" + height);
};

function refresh() {
// IP refresh.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncNavAdmin", "srefIxFmncVExpstate");
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
	srcdoc = doc.getElementById("Admin_src").contentDocument;

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
	setSi(srcdoc, "StatAppFmncNavAdmin", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppFmncNavAdmin", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavAdminDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavAdminDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacFmncNavAdmin", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacFmncNavAdmin", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppFmncNavAdminData", scrJref, "ContIacFmncNavAdmin");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppFmncNavAdmin", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppFmncNavAdmin", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacFmncNavAdmin", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "ContIacFmncNavAdmin", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "FeedFLstAdr", srcdoc)) mask.push("feedFLstAdr");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "FeedFLstFil", srcdoc)) mask.push("feedFLstFil");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "FeedFLstOrg", srcdoc)) mask.push("feedFLstOrg");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "FeedFLstPrs", srcdoc)) mask.push("feedFLstPrs");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "FeedFLstUsg", srcdoc)) mask.push("feedFLstUsg");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "FeedFLstUsr", srcdoc)) mask.push("feedFLstUsr");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "StatAppFmncNavAdmin", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "StatShrFmncNavAdmin", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncNavAdminData", "TagFmncNavAdmin", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncNavAdminData") {
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
			if (blk.nodeName == "DpchEngFmncNavAdminData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Admin");
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

			} else if (blk.nodeName == "DpchEngFmncNavAdminData") {
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


