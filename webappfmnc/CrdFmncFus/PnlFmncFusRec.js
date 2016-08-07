/**
  * \file PnlFmncFusRec.js
  * web client functionality for panel PnlFmncFusRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncFusRec", "scrJrefDetail");
	scrJrefMNTool = retrieveSi(srcdoc, "StatShrFmncFusRec", "scrJrefMNTool");
	scrJrefMNFabproject = retrieveSi(srcdoc, "StatShrFmncFusRec", "scrJrefMNFabproject");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncFusRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncFusRec", "initdoneMNTool", "false");
	setSi(srcdoc, "StatAppFmncFusRec", "initdoneMNFabproject", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightMNTool = 30;
	heightMNFabproject = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncFusRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncFusRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncFusRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncFusRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncFusRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncFusRec", "initdoneDetail") == "true");
	var initdoneMNTool = (retrieveSi(srcdoc, "StatAppFmncFusRec", "initdoneMNTool") == "true");
	var initdoneMNFabproject = (retrieveSi(srcdoc, "StatAppFmncFusRec", "initdoneMNFabproject") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncFusDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneMNTool) {
		rhsdoc.getElementById("MNTool").src = "./PnlFmncFusMNTool.html?scrJref=" + scrJrefMNTool;
	} else if (!initdoneMNFabproject) {
		rhsdoc.getElementById("MNFabproject").src = "./PnlFmncFusMNFabproject.html?scrJref=" + scrJrefMNFabproject;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail")) lhsrhsdoc = lhsdoc;
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
		else if (short == "MNTool") heightMNTool = height;
		else if (short == "MNFabproject") heightMNFabproject = height;
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

	doc.getElementById("Rec_side").src = "./PnlFmncFusRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncFusRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlFmncFusRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncFusRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "MNTool") heightMNTool = height;
	else if (pnlshort == "MNFabproject") heightMNFabproject = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = heightMNTool+13 + heightMNFabproject+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncFusRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncFusRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncFusRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncFusRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncFusRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncFusRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncFusRec", "srefIxFmncVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncFusRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncFusRecData", "ContInfFmncFusRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncFusRecData", "StatAppFmncFusRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncFusRecData", "StatShrFmncFusRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncFusRecData", "TagFmncFusRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncFusRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncFusRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncFusRec", "srefIxFmncVExpstate");

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
			} else if (_scrJref == scrJrefMNTool) {
				rhsdoc.getElementById("MNTool").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFabproject) {
				rhsdoc.getElementById("MNFabproject").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngFmncFusRecData") {
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

			} else if (blk.nodeName == "DpchEngFmncFusRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncFusRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncFusRec", "srefIxFmncVExpstate");

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


