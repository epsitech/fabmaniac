/**
  * \file PnlFmncSmpRec.js
  * web client functionality for panel PnlFmncSmpRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefDetail");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefAPar");
	scrJrefSup1NSample = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefSup1NSample");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefRef1NFile");
	scrJrefMNStep = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefMNStep");
	scrJrefMNFile = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefMNFile");
	scrJrefMNRun = retrieveSi(srcdoc, "StatShrFmncSmpRec", "scrJrefMNRun");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneSup1NSample", "false");
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneMNStep", "false");
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneMNFile", "false");
	setSi(srcdoc, "StatAppFmncSmpRec", "initdoneMNRun", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAPar = 30;
	heightSup1NSample = 30;
	heightRef1NFile = 30;
	heightMNStep = 30;
	heightMNFile = 30;
	heightMNRun = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncSmpRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneAPar") == "true");
	var initdoneSup1NSample = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneSup1NSample") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneRef1NFile") == "true");
	var initdoneMNStep = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneMNStep") == "true");
	var initdoneMNFile = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneMNFile") == "true");
	var initdoneMNRun = (retrieveSi(srcdoc, "StatAppFmncSmpRec", "initdoneMNRun") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncSmpDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlFmncSmpAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneSup1NSample) {
		rhsdoc.getElementById("Sup1NSample").src = "./PnlFmncSmpSup1NSample.html?scrJref=" + scrJrefSup1NSample;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlFmncSmpRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNStep) {
		rhsdoc.getElementById("MNStep").src = "./PnlFmncSmpMNStep.html?scrJref=" + scrJrefMNStep;
	} else if (!initdoneMNFile) {
		rhsdoc.getElementById("MNFile").src = "./PnlFmncSmpMNFile.html?scrJref=" + scrJrefMNFile;
	} else if (!initdoneMNRun) {
		rhsdoc.getElementById("MNRun").src = "./PnlFmncSmpMNRun.html?scrJref=" + scrJrefMNRun;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Sup1NSample") heightSup1NSample = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNStep") heightMNStep = height;
		else if (short == "MNFile") heightMNFile = height;
		else if (short == "MNRun") heightMNRun = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlFmncSmpRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncSmpRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlFmncSmpRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncSmpRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Sup1NSample") heightSup1NSample = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNStep") heightMNStep = height;
	else if (pnlshort == "MNFile") heightMNFile = height;
	else if (pnlshort == "MNRun") heightMNRun = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAPar+13 + 5;
	heightRhs = heightSup1NSample+13 + heightRef1NFile+13 + heightMNStep+13 + heightMNFile+13 + heightMNRun+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncSmpRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncSmpRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSmpRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncSmpRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncSmpRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncSmpRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSmpRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxFmncVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSmpRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncSmpRecData", "ContInfFmncSmpRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncSmpRecData", "StatAppFmncSmpRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncSmpRecData", "StatShrFmncSmpRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncSmpRecData", "TagFmncSmpRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSmpRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncSmpRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSmpRec", "srefIxFmncVExpstate");

				if (newSrefIxFmncVExpstate != srefIxFmncVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxFmncVExpstate == "mind") {
						minimize();
					} else if (newSrefIxFmncVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxFmncVExpstate != "mind") {
			if (_scrJref == scrJrefDetail) {
				lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NSample) {
				rhsdoc.getElementById("Sup1NSample").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNStep) {
				rhsdoc.getElementById("MNStep").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFile) {
				rhsdoc.getElementById("MNFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNRun) {
				rhsdoc.getElementById("MNRun").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngFmncSmpRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//fmnc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngFmncConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngFmncSmpRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSmpRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSmpRec", "srefIxFmncVExpstate");

					if (newSrefIxFmncVExpstate != srefIxFmncVExpstate) {
						updateScrJrefs();

						if (newSrefIxFmncVExpstate == "mind") {
							minimize();
						} else if (newSrefIxFmncVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};


