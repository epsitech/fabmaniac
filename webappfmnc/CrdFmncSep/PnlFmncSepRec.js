/**
  * \file PnlFmncSepRec.js
  * web client functionality for panel PnlFmncSepRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncSepRec", "scrJrefDetail");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrFmncSepRec", "scrJrefAPar");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrFmncSepRec", "scrJrefRef1NFile");
	scrJrefMNFile = retrieveSi(srcdoc, "StatShrFmncSepRec", "scrJrefMNFile");
	scrJrefMNSample = retrieveSi(srcdoc, "StatShrFmncSepRec", "scrJrefMNSample");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncSepRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncSepRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppFmncSepRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppFmncSepRec", "initdoneMNFile", "false");
	setSi(srcdoc, "StatAppFmncSepRec", "initdoneMNSample", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAPar = 30;
	heightRef1NFile = 30;
	heightMNFile = 30;
	heightMNSample = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncSepRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncSepRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneAPar") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneRef1NFile") == "true");
	var initdoneMNFile = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneMNFile") == "true");
	var initdoneMNSample = (retrieveSi(srcdoc, "StatAppFmncSepRec", "initdoneMNSample") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncSepDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlFmncSepAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlFmncSepRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNFile) {
		rhsdoc.getElementById("MNFile").src = "./PnlFmncSepMNFile.html?scrJref=" + scrJrefMNFile;
	} else if (!initdoneMNSample) {
		rhsdoc.getElementById("MNSample").src = "./PnlFmncSepMNSample.html?scrJref=" + scrJrefMNSample;

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
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNFile") heightMNFile = height;
		else if (short == "MNSample") heightMNSample = height;
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

	doc.getElementById("Rec_side").src = "./PnlFmncSepRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncSepRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlFmncSepRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncSepRec_b.html";
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
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNFile") heightMNFile = height;
	else if (pnlshort == "MNSample") heightMNSample = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAPar+13 + 5;
	heightRhs = heightRef1NFile+13 + heightMNFile+13 + heightMNSample+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncSepRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncSepRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSepRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncSepRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncSepRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncSepRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSepRec", "srefIxFmncVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncSepRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncSepRecData", "ContInfFmncSepRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncSepRecData", "StatAppFmncSepRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncSepRecData", "StatShrFmncSepRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncSepRecData", "TagFmncSepRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSepRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncSepRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSepRec", "srefIxFmncVExpstate");

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
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFile) {
				rhsdoc.getElementById("MNFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNSample) {
				rhsdoc.getElementById("MNSample").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngFmncSepRecData") {
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

			} else if (blk.nodeName == "DpchEngFmncSepRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSepRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncSepRec", "srefIxFmncVExpstate");

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


