/**
  * \file PnlFmncTtyRec.js
  * web client functionality for panel PnlFmncTtyRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncTtyRec", "scrJrefDetail");
	scrJrefKSteppar = retrieveSi(srcdoc, "StatShrFmncTtyRec", "scrJrefKSteppar");
	scrJrefKToolchar = retrieveSi(srcdoc, "StatShrFmncTtyRec", "scrJrefKToolchar");
	scrJrefSup1NTooltype = retrieveSi(srcdoc, "StatShrFmncTtyRec", "scrJrefSup1NTooltype");
	scrJrefRlv1NStep = retrieveSi(srcdoc, "StatShrFmncTtyRec", "scrJrefRlv1NStep");
	scrJrefMNTool = retrieveSi(srcdoc, "StatShrFmncTtyRec", "scrJrefMNTool");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncTtyRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncTtyRec", "initdoneKSteppar", "false");
	setSi(srcdoc, "StatAppFmncTtyRec", "initdoneKToolchar", "false");
	setSi(srcdoc, "StatAppFmncTtyRec", "initdoneSup1NTooltype", "false");
	setSi(srcdoc, "StatAppFmncTtyRec", "initdoneRlv1NStep", "false");
	setSi(srcdoc, "StatAppFmncTtyRec", "initdoneMNTool", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKSteppar = 30;
	heightKToolchar = 30;
	heightSup1NTooltype = 30;
	heightRlv1NStep = 30;
	heightMNTool = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncTtyRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneDetail") == "true");
	var initdoneKSteppar = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneKSteppar") == "true");
	var initdoneKToolchar = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneKToolchar") == "true");
	var initdoneSup1NTooltype = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneSup1NTooltype") == "true");
	var initdoneRlv1NStep = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneRlv1NStep") == "true");
	var initdoneMNTool = (retrieveSi(srcdoc, "StatAppFmncTtyRec", "initdoneMNTool") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncTtyDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKSteppar) {
		lhsdoc.getElementById("KSteppar").src = "./PnlFmncTtyKSteppar.html?scrJref=" + scrJrefKSteppar;
	} else if (!initdoneKToolchar) {
		lhsdoc.getElementById("KToolchar").src = "./PnlFmncTtyKToolchar.html?scrJref=" + scrJrefKToolchar;
	} else if (!initdoneSup1NTooltype) {
		rhsdoc.getElementById("Sup1NTooltype").src = "./PnlFmncTtySup1NTooltype.html?scrJref=" + scrJrefSup1NTooltype;
	} else if (!initdoneRlv1NStep) {
		rhsdoc.getElementById("Rlv1NStep").src = "./PnlFmncTtyRlv1NStep.html?scrJref=" + scrJrefRlv1NStep;
	} else if (!initdoneMNTool) {
		rhsdoc.getElementById("MNTool").src = "./PnlFmncTtyMNTool.html?scrJref=" + scrJrefMNTool;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KSteppar") || (short == "KToolchar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "KSteppar") heightKSteppar = height;
		else if (short == "KToolchar") heightKToolchar = height;
		else if (short == "Sup1NTooltype") heightSup1NTooltype = height;
		else if (short == "Rlv1NStep") heightRlv1NStep = height;
		else if (short == "MNTool") heightMNTool = height;
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

	doc.getElementById("Rec_side").src = "./PnlFmncTtyRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncTtyRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlFmncTtyRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncTtyRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KSteppar") || (pnlshort == "KToolchar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KSteppar") heightKSteppar = height;
	else if (pnlshort == "KToolchar") heightKToolchar = height;
	else if (pnlshort == "Sup1NTooltype") heightSup1NTooltype = height;
	else if (pnlshort == "Rlv1NStep") heightRlv1NStep = height;
	else if (pnlshort == "MNTool") heightMNTool = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKSteppar+13 + heightKToolchar+13 + 5;
	heightRhs = heightSup1NTooltype+13 + heightRlv1NStep+13 + heightMNTool+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncTtyRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncTtyRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTtyRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncTtyRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncTtyRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncTtyRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTtyRec", "srefIxFmncVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncTtyRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncTtyRecData", "ContInfFmncTtyRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncTtyRecData", "StatAppFmncTtyRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncTtyRecData", "StatShrFmncTtyRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncTtyRecData", "TagFmncTtyRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTtyRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncTtyRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTtyRec", "srefIxFmncVExpstate");

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
			} else if (_scrJref == scrJrefKSteppar) {
				lhsdoc.getElementById("KSteppar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKToolchar) {
				lhsdoc.getElementById("KToolchar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NTooltype) {
				rhsdoc.getElementById("Sup1NTooltype").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRlv1NStep) {
				rhsdoc.getElementById("Rlv1NStep").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNTool) {
				rhsdoc.getElementById("MNTool").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngFmncTtyRecData") {
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

			} else if (blk.nodeName == "DpchEngFmncTtyRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTtyRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTtyRec", "srefIxFmncVExpstate");

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


