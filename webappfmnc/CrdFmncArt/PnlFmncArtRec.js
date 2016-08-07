/**
  * \file PnlFmncArtRec.js
  * web client functionality for panel PnlFmncArtRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncArtRec", "scrJrefDetail");
	scrJref1NSample = retrieveSi(srcdoc, "StatShrFmncArtRec", "scrJref1NSample");
	scrJref1NStockitem = retrieveSi(srcdoc, "StatShrFmncArtRec", "scrJref1NStockitem");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrFmncArtRec", "scrJrefRef1NFile");
	scrJrefMNOrg = retrieveSi(srcdoc, "StatShrFmncArtRec", "scrJrefMNOrg");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncArtRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncArtRec", "initdone1NSample", "false");
	setSi(srcdoc, "StatAppFmncArtRec", "initdone1NStockitem", "false");
	setSi(srcdoc, "StatAppFmncArtRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppFmncArtRec", "initdoneMNOrg", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NSample = 30;
	height1NStockitem = 30;
	heightRef1NFile = 30;
	heightMNOrg = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncArtRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncArtRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdoneDetail") == "true");
	var initdone1NSample = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdone1NSample") == "true");
	var initdone1NStockitem = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdone1NStockitem") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdoneRef1NFile") == "true");
	var initdoneMNOrg = (retrieveSi(srcdoc, "StatAppFmncArtRec", "initdoneMNOrg") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncArtDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NSample) {
		rhsdoc.getElementById("1NSample").src = "./PnlFmncArt1NSample.html?scrJref=" + scrJref1NSample;
	} else if (!initdone1NStockitem) {
		rhsdoc.getElementById("1NStockitem").src = "./PnlFmncArt1NStockitem.html?scrJref=" + scrJref1NStockitem;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlFmncArtRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNOrg) {
		rhsdoc.getElementById("MNOrg").src = "./PnlFmncArtMNOrg.html?scrJref=" + scrJrefMNOrg;

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
		else if (short == "1NSample") height1NSample = height;
		else if (short == "1NStockitem") height1NStockitem = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNOrg") heightMNOrg = height;
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

	doc.getElementById("Rec_side").src = "./PnlFmncArtRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncArtRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 223);
	doc.getElementById("tdSide").setAttribute("height", "223");
	doc.getElementById("Rec_side").setAttribute("height", "223");
	doc.getElementById("Rec_cont").setAttribute("height", "223");

	doc.getElementById("Rec_side").src = "./PnlFmncArtRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncArtRec_b.html";
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
	else if (pnlshort == "1NSample") height1NSample = height;
	else if (pnlshort == "1NStockitem") height1NStockitem = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNOrg") heightMNOrg = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NSample+13 + height1NStockitem+13 + heightRef1NFile+13 + heightMNOrg+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncArtRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncArtRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncArtRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncArtRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncArtRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncArtRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncArtRec", "srefIxFmncVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncArtRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncArtRecData", "ContInfFmncArtRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncArtRecData", "StatAppFmncArtRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncArtRecData", "StatShrFmncArtRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncArtRecData", "TagFmncArtRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncArtRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncArtRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncArtRec", "srefIxFmncVExpstate");

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
			} else if (_scrJref == scrJref1NSample) {
				rhsdoc.getElementById("1NSample").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NStockitem) {
				rhsdoc.getElementById("1NStockitem").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNOrg) {
				rhsdoc.getElementById("MNOrg").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngFmncArtRecData") {
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

			} else if (blk.nodeName == "DpchEngFmncArtRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncArtRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncArtRec", "srefIxFmncVExpstate");

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


