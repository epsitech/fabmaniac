/**
  * \file CrdFmncNav.js
  * web client functionality for card CrdFmncNav
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppFmncNav", "initdoneHeadbar") == "true");
	var initdonePre = (retrieveSi(srcdoc, "StatAppFmncNav", "initdonePre") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppFmncNav", "initdoneAdmin") == "true");
	var initdoneLabbook = (retrieveSi(srcdoc, "StatAppFmncNav", "initdoneLabbook") == "true");
	var initdoneFabmgmt = (retrieveSi(srcdoc, "StatAppFmncNav", "initdoneFabmgmt") == "true");
	var initdoneSupply = (retrieveSi(srcdoc, "StatAppFmncNav", "initdoneSupply") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlFmncNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdonePre) {
		doc.getElementById("Pre").src = "./PnlFmncNavPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlFmncNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneLabbook) {
		doc.getElementById("Labbook").src = "./PnlFmncNavLabbook.html?scrJref=" + scrJrefLabbook;
	} else if (!initdoneFabmgmt) {
		doc.getElementById("Fabmgmt").src = "./PnlFmncNavFabmgmt.html?scrJref=" + scrJrefFabmgmt;
	} else if (!initdoneSupply) {
		doc.getElementById("Supply").src = "./PnlFmncNavSupply.html?scrJref=" + scrJrefSupply;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	if (doc.getElementById("trPre").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdPre").getAttribute("height"));
	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trLabbook").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdLabbook").getAttribute("height")) + 8;
	if (doc.getElementById("trFabmgmt").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdFabmgmt").getAttribute("height")) + 8;
	if (doc.getElementById("trSupply").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdSupply").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppFmncNav", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppFmncNav", "shortMenu", short);
	setSi(srcdoc, "StatAppFmncNav", "widthMenu", "" + (width-3));

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppFmncNav", "shortMenu", "");

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

// IP initMenAppCrdnav --- BEGIN
function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	var MspApp2Avail = (retrieveSi(srcdoc, "StatShrFmncNav", "MspApp2Avail") == "true");
	var MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppFmncNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagFmncNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagFmncNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagFmncNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};
// IP initMenAppCrdnav --- END

// IP initMenSes --- BEGIN
function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppFmncNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfFmncNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfFmncNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfFmncNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagFmncNav", "MitSesTrm"));
};
// IP initMenSes --- END

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrFmncNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdUsrAvail") == "true");
	MitCrdOrgAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdOrgAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdPrsAvail") == "true");
	MitCrdAdrAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdAdrAvail") == "true");
	MitCrdFilAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdFilAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrFmncNav", "MspCrd2Avail") == "true");
	MitCrdStpAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdStpAvail") == "true");
	MitCrdPrjAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdPrjAvail") == "true");
	MitCrdRunAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdRunAvail") == "true");
	MitCrdActAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdActAvail") == "true");
	MitCrdActActive = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdActActive") == "true");
	MitCrdSepAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdSepAvail") == "true");
	MitCrdSepActive = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdSepActive") == "true");
	MitCrdSmpAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdSmpAvail") == "true");
	MspCrd3Avail = (retrieveSi(srcdoc, "StatShrFmncNav", "MspCrd3Avail") == "true");
	MitCrdFabAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdFabAvail") == "true");
	MitCrdFusAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdFusAvail") == "true");
	MitCrdFusActive = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdFusActive") == "true");
	MitCrdTtyAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdTtyAvail") == "true");
	MitCrdTolAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdTolAvail") == "true");
	MitCrdTolActive = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdTolActive") == "true");
	MitCrdFpjAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdFpjAvail") == "true");
	MitCrdFpjActive = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdFpjActive") == "true");
	MitCrdBilAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdBilAvail") == "true");
	MitCrdBilActive = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdBilActive") == "true");
	MspCrd4Avail = (retrieveSi(srcdoc, "StatShrFmncNav", "MspCrd4Avail") == "true");
	MitCrdArtAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdArtAvail") == "true");
	MitCrdSkiAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdSkiAvail") == "true");
	MitCrdPcoAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "MitCrdPcoAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppFmncNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdOrg"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdOrg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdAdr"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdAdr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFil"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdFil"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdStp"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdStp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrj"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdPrj"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdRun"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdRun"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdAct"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdAct"));
	setMitActive("MitCrdAct", MitCrdActActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSep"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdSep"));
	setMitActive("MitCrdSep", MitCrdSepActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSmp"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdSmp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFab"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdFab"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFus"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdFus"));
	setMitActive("MitCrdFus", MitCrdFusActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdTty"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdTty"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdTol"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdTol"));
	setMitActive("MitCrdTol", MitCrdTolActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdFpj"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdFpj"));
	setMitActive("MitCrdFpj", MitCrdFpjActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdBil"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdBil"));
	setMitActive("MitCrdBil", MitCrdBilActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdArt"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdArt"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdSki"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdSki"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPco"), retrieveTi(srcdoc, "TagFmncNav", "MitCrdPco"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdOrg", MitCrdOrgAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MitCrdAdr", MitCrdAdrAvail, 20);
	height -= setMitMspAvail("MitCrdFil", MitCrdFilAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdStp", MitCrdStpAvail, 20);
	height -= setMitMspAvail("MitCrdPrj", MitCrdPrjAvail, 20);
	height -= setMitMspAvail("MitCrdRun", MitCrdRunAvail, 20);
	height -= setMitMspAvail("MitCrdAct", MitCrdActAvail, 20);
	height -= setMitMspAvail("MitCrdSep", MitCrdSepAvail, 20);
	height -= setMitMspAvail("MitCrdSmp", MitCrdSmpAvail, 20);
	height -= setMitMspAvail("MspCrd3", MspCrd3Avail, 1);
	height -= setMitMspAvail("MitCrdFab", MitCrdFabAvail, 20);
	height -= setMitMspAvail("MitCrdFus", MitCrdFusAvail, 20);
	height -= setMitMspAvail("MitCrdTty", MitCrdTtyAvail, 20);
	height -= setMitMspAvail("MitCrdTol", MitCrdTolAvail, 20);
	height -= setMitMspAvail("MitCrdFpj", MitCrdFpjAvail, 20);
	height -= setMitMspAvail("MitCrdBil", MitCrdBilAvail, 20);
	height -= setMitMspAvail("MspCrd4", MspCrd4Avail, 1);
	height -= setMitMspAvail("MitCrdArt", MitCrdArtAvail, 20);
	height -= setMitMspAvail("MitCrdSki", MitCrdSkiAvail, 20);
	height -= setMitMspAvail("MitCrdPco", MitCrdPcoAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	srefDlg = sref;
	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divShld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgFmncNavLoaini")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	srefDlg = "";
	scrJrefDlg = "";

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divShld"));
	body.removeChild(doc.getElementById("divDlg"));
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfFmncAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divShld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	scrJrefAlr = "";

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divShld"));
	body.removeChild(doc.getElementById("divAlr"));
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfFmncAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfFmncAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divShld = doc.getElementById("divShld");

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Labbook") {
		doc.getElementById("tdLabbook").setAttribute("height", "" + height);
		doc.getElementById("Labbook").setAttribute("height", "" + height);
	} else if (pnlshort == "Fabmgmt") {
		doc.getElementById("tdFabmgmt").setAttribute("height", "" + height);
		doc.getElementById("Fabmgmt").setAttribute("height", "" + height);
	} else if (pnlshort == "Supply") {
		doc.getElementById("tdSupply").setAttribute("height", "" + height);
		doc.getElementById("Supply").setAttribute("height", "" + height);
	};

	if (divShld) divShld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefDlgloaini");
	var pnlpreAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "pnlpreAvail") == "true");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "pnladminAvail") == "true");
	var pnllabbookAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "pnllabbookAvail") == "true");
	var pnlfabmgmtAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "pnlfabmgmtAvail") == "true");
	var pnlsupplyAvail = (retrieveSi(srcdoc, "StatShrFmncNav", "pnlsupplyAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgFmncNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Pre", pnlpreAvail);
	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Labbook", pnllabbookAvail);
	setPnlAvail("Fabmgmt", pnlfabmgmtAvail);
	setPnlAvail("Supply", pnlsupplyAvail);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavDo", scrJref, "close");
	sendReq(str, doc);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfFmncNav", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncNavData", "ContInfFmncNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngFmncNavData", "StatAppFmncNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncNavData", "StatShrFmncNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncNavData", "TagFmncNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngFmncNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefHeadbar");
				scrJrefPre = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefPre");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefAdmin");
				scrJrefLabbook = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefLabbook");
				scrJrefFabmgmt = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefFabmgmt");
				scrJrefSupply = retrieveSi(srcdoc, "StatShrFmncNav", "scrJrefSupply");

				srefDlg = "";
				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//fmnc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngFmncConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngFmncAlert") {
				// show alert with new content
				showAlr(retrieveValue(dom, "//fmnc:DpchEngFmncAlert/fmnc:scrJref"),
						retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:ContInfFmncAlert"),
						retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:FeedFMcbAlert"));

			} else if (blk.nodeName == "DpchEngFmncNavData") {
				mergeDpchEngData(dom);
				refresh();
			};

			restartNotify();
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
				showAlr(retrieveValue(dom, "//fmnc:DpchEngFmncAlert/fmnc:scrJref"),
						retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:ContInfFmncAlert"),
						retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};
// IP handleDpchAppDoCrdopenReply --- END

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

// IP terminateCrdnav --- BEGIN
	window.open("../CrdFmncStart/CrdFmncStart.html?do=Logout", "_self");
// IP terminateCrdnav --- END
};

function restartNotify() {
	var srefIxFmncVReqitmode = retrieveSi(srcdoc, "StatAppFmncNav", "srefIxFmncVReqitmode");

	if (srefIxFmncVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxFmncVReqitmode = "notify";
		setSi(srcdoc, "StatAppFmncNav", "srefIxFmncVReqitmode", srefIxFmncVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxFmncVReqitmode = retrieveSi(srcdoc, "StatAppFmncNav", "srefIxFmncVReqitmode");

	if (srefIxFmncVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppFmncResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");

		if (blk) if (blk.nodeName == "DpchEngFmncAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxFmncVReqitmode = retrieveSi(srcdoc, "StatAppFmncNav", "srefIxFmncVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppFmncNav", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//fmnc:*");

			if (blk) {
				if (blk.nodeName == "DpchEngFmncAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngFmncSuspend") {
					// change to "poll" mode
					news = true;

					srefIxFmncVReqitmode = "poll";
					setSi(srcdoc, "StatAppFmncNav", "srefIxFmncVReqitmode", srefIxFmncVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");

					if (blk.nodeName == "DpchEngFmncAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//fmnc:DpchEngFmncAlert/fmnc:scrJref"),
								retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:ContInfFmncAlert"),
								retrieveBlock(dom, "//fmnc:DpchEngFmncAlert/fmnc:FeedFMcbAlert"));

					} else {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngFmncConfirm") {
								accepted = retrieveValue(dom, "//fmnc:DpchEngFmncConfirm/fmnc:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngFmncNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else if (_scrJref == scrJrefDlg) {
							doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, blk.nodeName);

						} else if (_scrJref == scrJrefPre) {
							doc.getElementById("Pre").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefAdmin) {
							doc.getElementById("Admin").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefLabbook) {
							doc.getElementById("Labbook").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefFabmgmt) {
							doc.getElementById("Fabmgmt").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefSupply) {
							doc.getElementById("Supply").contentWindow.handleDpchEng(dom, blk.nodeName);

// IP iterateReqit.invalid --- BEGIN
						} else {
							// alert("got a '" + blk.nodeName + "' from job with scrJref " + _scrJref);
// IP iterateReqit.invalid --- END
						};
					};
				};
			};
		};
	};

	if ((srefIxFmncVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxFmncVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};


