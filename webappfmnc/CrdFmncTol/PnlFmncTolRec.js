/**
  * \file PnlFmncTolRec.js
  * web client functionality for panel PnlFmncTolRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefDetail");
	scrJrefKSteppar = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefKSteppar");
	scrJrefKToolchar = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefKToolchar");
	scrJrefAAvl = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefAAvl");
	scrJrefAChar = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefAChar");
	scrJrefARes = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefARes");
	scrJrefAUtil = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefAUtil");
	scrJref1NArticle = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJref1NArticle");
	scrJrefRlv1NStep = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefRlv1NStep");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefRef1NFile");
	scrJrefMNTooltype = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefMNTooltype");
	scrJrefMNFabuser = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefMNFabuser");
	scrJrefSvcMNOrg = retrieveSi(srcdoc, "StatShrFmncTolRec", "scrJrefSvcMNOrg");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneKSteppar", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneKToolchar", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneAAvl", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneAChar", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneARes", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneAUtil", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdone1NArticle", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneRlv1NStep", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneMNTooltype", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneMNFabuser", "false");
	setSi(srcdoc, "StatAppFmncTolRec", "initdoneSvcMNOrg", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKSteppar = 30;
	heightKToolchar = 30;
	heightAAvl = 30;
	heightAChar = 30;
	heightARes = 30;
	heightAUtil = 30;
	height1NArticle = 30;
	heightRlv1NStep = 30;
	heightRef1NFile = 30;
	heightMNTooltype = 30;
	heightMNFabuser = 30;
	heightSvcMNOrg = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncTolRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncTolRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneDetail") == "true");
	var initdoneKSteppar = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneKSteppar") == "true");
	var initdoneKToolchar = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneKToolchar") == "true");
	var initdoneAAvl = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneAAvl") == "true");
	var initdoneAChar = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneAChar") == "true");
	var initdoneARes = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneARes") == "true");
	var initdoneAUtil = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneAUtil") == "true");
	var initdone1NArticle = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdone1NArticle") == "true");
	var initdoneRlv1NStep = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneRlv1NStep") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneRef1NFile") == "true");
	var initdoneMNTooltype = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneMNTooltype") == "true");
	var initdoneMNFabuser = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneMNFabuser") == "true");
	var initdoneSvcMNOrg = (retrieveSi(srcdoc, "StatAppFmncTolRec", "initdoneSvcMNOrg") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncTolDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKSteppar) {
		lhsdoc.getElementById("KSteppar").src = "./PnlFmncTolKSteppar.html?scrJref=" + scrJrefKSteppar;
	} else if (!initdoneKToolchar) {
		lhsdoc.getElementById("KToolchar").src = "./PnlFmncTolKToolchar.html?scrJref=" + scrJrefKToolchar;
	} else if (!initdoneAAvl) {
		lhsdoc.getElementById("AAvl").src = "./PnlFmncTolAAvl.html?scrJref=" + scrJrefAAvl;
	} else if (!initdoneAChar) {
		lhsdoc.getElementById("AChar").src = "./PnlFmncTolAChar.html?scrJref=" + scrJrefAChar;
	} else if (!initdoneARes) {
		lhsdoc.getElementById("ARes").src = "./PnlFmncTolARes.html?scrJref=" + scrJrefARes;
	} else if (!initdoneAUtil) {
		lhsdoc.getElementById("AUtil").src = "./PnlFmncTolAUtil.html?scrJref=" + scrJrefAUtil;
	} else if (!initdone1NArticle) {
		rhsdoc.getElementById("1NArticle").src = "./PnlFmncTol1NArticle.html?scrJref=" + scrJref1NArticle;
	} else if (!initdoneRlv1NStep) {
		rhsdoc.getElementById("Rlv1NStep").src = "./PnlFmncTolRlv1NStep.html?scrJref=" + scrJrefRlv1NStep;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlFmncTolRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNTooltype) {
		rhsdoc.getElementById("MNTooltype").src = "./PnlFmncTolMNTooltype.html?scrJref=" + scrJrefMNTooltype;
	} else if (!initdoneMNFabuser) {
		rhsdoc.getElementById("MNFabuser").src = "./PnlFmncTolMNFabuser.html?scrJref=" + scrJrefMNFabuser;
	} else if (!initdoneSvcMNOrg) {
		rhsdoc.getElementById("SvcMNOrg").src = "./PnlFmncTolSvcMNOrg.html?scrJref=" + scrJrefSvcMNOrg;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KSteppar") || (short == "KToolchar") || (short == "AAvl") || (short == "AChar") || (short == "ARes") || (short == "AUtil")) lhsrhsdoc = lhsdoc;
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
		else if (short == "AAvl") heightAAvl = height;
		else if (short == "AChar") heightAChar = height;
		else if (short == "ARes") heightARes = height;
		else if (short == "AUtil") heightAUtil = height;
		else if (short == "1NArticle") height1NArticle = height;
		else if (short == "Rlv1NStep") heightRlv1NStep = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNTooltype") heightMNTooltype = height;
		else if (short == "MNFabuser") heightMNFabuser = height;
		else if (short == "SvcMNOrg") heightSvcMNOrg = height;
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

	doc.getElementById("Rec_side").src = "./PnlFmncTolRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncTolRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 352);
	doc.getElementById("tdSide").setAttribute("height", "352");
	doc.getElementById("Rec_side").setAttribute("height", "352");
	doc.getElementById("Rec_cont").setAttribute("height", "352");

	doc.getElementById("Rec_side").src = "./PnlFmncTolRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncTolRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KSteppar") || (pnlshort == "KToolchar") || (pnlshort == "AAvl") || (pnlshort == "AChar") || (pnlshort == "ARes") || (pnlshort == "AUtil")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KSteppar") heightKSteppar = height;
	else if (pnlshort == "KToolchar") heightKToolchar = height;
	else if (pnlshort == "AAvl") heightAAvl = height;
	else if (pnlshort == "AChar") heightAChar = height;
	else if (pnlshort == "ARes") heightARes = height;
	else if (pnlshort == "AUtil") heightAUtil = height;
	else if (pnlshort == "1NArticle") height1NArticle = height;
	else if (pnlshort == "Rlv1NStep") heightRlv1NStep = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNTooltype") heightMNTooltype = height;
	else if (pnlshort == "MNFabuser") heightMNFabuser = height;
	else if (pnlshort == "SvcMNOrg") heightSvcMNOrg = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKSteppar+13 + heightKToolchar+13 + heightAAvl+13 + heightAChar+13 + heightARes+13 + heightAUtil+13 + 5;
	heightRhs = height1NArticle+13 + heightRlv1NStep+13 + heightRef1NFile+13 + heightMNTooltype+13 + heightMNFabuser+13 + heightSvcMNOrg+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncTolRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncTolRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTolRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncTolRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncTolRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncTolRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTolRec", "srefIxFmncVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncTolRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncTolRecData", "ContInfFmncTolRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncTolRecData", "StatAppFmncTolRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncTolRecData", "StatShrFmncTolRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncTolRecData", "TagFmncTolRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTolRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncTolRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTolRec", "srefIxFmncVExpstate");

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
			} else if (_scrJref == scrJrefAAvl) {
				lhsdoc.getElementById("AAvl").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAChar) {
				lhsdoc.getElementById("AChar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefARes) {
				lhsdoc.getElementById("ARes").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAUtil) {
				lhsdoc.getElementById("AUtil").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NArticle) {
				rhsdoc.getElementById("1NArticle").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRlv1NStep) {
				rhsdoc.getElementById("Rlv1NStep").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNTooltype) {
				rhsdoc.getElementById("MNTooltype").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFabuser) {
				rhsdoc.getElementById("MNFabuser").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSvcMNOrg) {
				rhsdoc.getElementById("SvcMNOrg").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngFmncTolRecData") {
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

			} else if (blk.nodeName == "DpchEngFmncTolRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTolRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncTolRec", "srefIxFmncVExpstate");

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


