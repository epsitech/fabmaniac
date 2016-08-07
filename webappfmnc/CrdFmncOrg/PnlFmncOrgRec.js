/**
  * \file PnlFmncOrgRec.js
  * web client functionality for panel PnlFmncOrgRec
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefDetail");
	scrJrefKStocklcn = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefKStocklcn");
	scrJrefADetail = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefADetail");
	scrJrefBio1NFabproject = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefBio1NFabproject");
	scrJrefMnf1NTool = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefMnf1NTool");
	scrJref1NArticle = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJref1NArticle");
	scrJrefPco1NPurchorder = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefPco1NPurchorder");
	scrJrefSpl1NPurchorder = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefSpl1NPurchorder");
	scrJref1NStockitem = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJref1NStockitem");
	scrJrefSup1NOrg = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefSup1NOrg");
	scrJrefHk1NAddress = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefHk1NAddress");
	scrJrefMNPerson = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefMNPerson");
	scrJrefSvcMNTool = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefSvcMNTool");
	scrJrefMNArticle = retrieveSi(srcdoc, "StatShrFmncOrgRec", "scrJrefMNArticle");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneKStocklcn", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneADetail", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneBio1NFabproject", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneMnf1NTool", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdone1NArticle", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdonePco1NPurchorder", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneSpl1NPurchorder", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdone1NStockitem", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneSup1NOrg", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneHk1NAddress", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneMNPerson", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneSvcMNTool", "false");
	setSi(srcdoc, "StatAppFmncOrgRec", "initdoneMNArticle", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKStocklcn = 30;
	heightADetail = 30;
	heightBio1NFabproject = 30;
	heightMnf1NTool = 30;
	height1NArticle = 30;
	heightPco1NPurchorder = 30;
	heightSpl1NPurchorder = 30;
	height1NStockitem = 30;
	heightSup1NOrg = 30;
	heightHk1NAddress = 30;
	heightMNPerson = 30;
	heightSvcMNTool = 30;
	heightMNArticle = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppFmncOrgRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneDetail") == "true");
	var initdoneKStocklcn = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneKStocklcn") == "true");
	var initdoneADetail = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneADetail") == "true");
	var initdoneBio1NFabproject = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneBio1NFabproject") == "true");
	var initdoneMnf1NTool = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneMnf1NTool") == "true");
	var initdone1NArticle = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdone1NArticle") == "true");
	var initdonePco1NPurchorder = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdonePco1NPurchorder") == "true");
	var initdoneSpl1NPurchorder = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneSpl1NPurchorder") == "true");
	var initdone1NStockitem = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdone1NStockitem") == "true");
	var initdoneSup1NOrg = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneSup1NOrg") == "true");
	var initdoneHk1NAddress = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneHk1NAddress") == "true");
	var initdoneMNPerson = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneMNPerson") == "true");
	var initdoneSvcMNTool = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneSvcMNTool") == "true");
	var initdoneMNArticle = (retrieveSi(srcdoc, "StatAppFmncOrgRec", "initdoneMNArticle") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlFmncOrgDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKStocklcn) {
		lhsdoc.getElementById("KStocklcn").src = "./PnlFmncOrgKStocklcn.html?scrJref=" + scrJrefKStocklcn;
	} else if (!initdoneADetail) {
		lhsdoc.getElementById("ADetail").src = "./PnlFmncOrgADetail.html?scrJref=" + scrJrefADetail;
	} else if (!initdoneBio1NFabproject) {
		rhsdoc.getElementById("Bio1NFabproject").src = "./PnlFmncOrgBio1NFabproject.html?scrJref=" + scrJrefBio1NFabproject;
	} else if (!initdoneMnf1NTool) {
		rhsdoc.getElementById("Mnf1NTool").src = "./PnlFmncOrgMnf1NTool.html?scrJref=" + scrJrefMnf1NTool;
	} else if (!initdone1NArticle) {
		rhsdoc.getElementById("1NArticle").src = "./PnlFmncOrg1NArticle.html?scrJref=" + scrJref1NArticle;
	} else if (!initdonePco1NPurchorder) {
		rhsdoc.getElementById("Pco1NPurchorder").src = "./PnlFmncOrgPco1NPurchorder.html?scrJref=" + scrJrefPco1NPurchorder;
	} else if (!initdoneSpl1NPurchorder) {
		rhsdoc.getElementById("Spl1NPurchorder").src = "./PnlFmncOrgSpl1NPurchorder.html?scrJref=" + scrJrefSpl1NPurchorder;
	} else if (!initdone1NStockitem) {
		rhsdoc.getElementById("1NStockitem").src = "./PnlFmncOrg1NStockitem.html?scrJref=" + scrJref1NStockitem;
	} else if (!initdoneSup1NOrg) {
		rhsdoc.getElementById("Sup1NOrg").src = "./PnlFmncOrgSup1NOrg.html?scrJref=" + scrJrefSup1NOrg;
	} else if (!initdoneHk1NAddress) {
		rhsdoc.getElementById("Hk1NAddress").src = "./PnlFmncOrgHk1NAddress.html?scrJref=" + scrJrefHk1NAddress;
	} else if (!initdoneMNPerson) {
		rhsdoc.getElementById("MNPerson").src = "./PnlFmncOrgMNPerson.html?scrJref=" + scrJrefMNPerson;
	} else if (!initdoneSvcMNTool) {
		rhsdoc.getElementById("SvcMNTool").src = "./PnlFmncOrgSvcMNTool.html?scrJref=" + scrJrefSvcMNTool;
	} else if (!initdoneMNArticle) {
		rhsdoc.getElementById("MNArticle").src = "./PnlFmncOrgMNArticle.html?scrJref=" + scrJrefMNArticle;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KStocklcn") || (short == "ADetail")) lhsrhsdoc = lhsdoc;
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
		else if (short == "KStocklcn") heightKStocklcn = height;
		else if (short == "ADetail") heightADetail = height;
		else if (short == "Bio1NFabproject") heightBio1NFabproject = height;
		else if (short == "Mnf1NTool") heightMnf1NTool = height;
		else if (short == "1NArticle") height1NArticle = height;
		else if (short == "Pco1NPurchorder") heightPco1NPurchorder = height;
		else if (short == "Spl1NPurchorder") heightSpl1NPurchorder = height;
		else if (short == "1NStockitem") height1NStockitem = height;
		else if (short == "Sup1NOrg") heightSup1NOrg = height;
		else if (short == "Hk1NAddress") heightHk1NAddress = height;
		else if (short == "MNPerson") heightMNPerson = height;
		else if (short == "SvcMNTool") heightSvcMNTool = height;
		else if (short == "MNArticle") heightMNArticle = height;
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

	doc.getElementById("Rec_side").src = "./PnlFmncOrgRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncOrgRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 524);
	doc.getElementById("tdSide").setAttribute("height", "524");
	doc.getElementById("Rec_side").setAttribute("height", "524");
	doc.getElementById("Rec_cont").setAttribute("height", "524");

	doc.getElementById("Rec_side").src = "./PnlFmncOrgRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlFmncOrgRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KStocklcn") || (pnlshort == "ADetail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KStocklcn") heightKStocklcn = height;
	else if (pnlshort == "ADetail") heightADetail = height;
	else if (pnlshort == "Bio1NFabproject") heightBio1NFabproject = height;
	else if (pnlshort == "Mnf1NTool") heightMnf1NTool = height;
	else if (pnlshort == "1NArticle") height1NArticle = height;
	else if (pnlshort == "Pco1NPurchorder") heightPco1NPurchorder = height;
	else if (pnlshort == "Spl1NPurchorder") heightSpl1NPurchorder = height;
	else if (pnlshort == "1NStockitem") height1NStockitem = height;
	else if (pnlshort == "Sup1NOrg") heightSup1NOrg = height;
	else if (pnlshort == "Hk1NAddress") heightHk1NAddress = height;
	else if (pnlshort == "MNPerson") heightMNPerson = height;
	else if (pnlshort == "SvcMNTool") heightSvcMNTool = height;
	else if (pnlshort == "MNArticle") heightMNArticle = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKStocklcn+13 + heightADetail+13 + 5;
	heightRhs = heightBio1NFabproject+13 + heightMnf1NTool+13 + height1NArticle+13 + heightPco1NPurchorder+13 + heightSpl1NPurchorder+13 + height1NStockitem+13 + heightSup1NOrg+13 + heightHk1NAddress+13 + heightMNPerson+13 + heightSvcMNTool+13 + heightMNArticle+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncOrgRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncOrgRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncOrgRec", "srefIxFmncVExpstate");

	if (srefIxFmncVExpstate == "mind") {
		minimize();
	} else if (srefIxFmncVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrFmncOrgRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncOrgRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfFmncOrgRec", "TxtRef"));

};

function refresh() {
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncOrgRec", "srefIxFmncVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncOrgRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncOrgRecData", "ContInfFmncOrgRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncOrgRecData", "StatAppFmncOrgRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncOrgRecData", "StatShrFmncOrgRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncOrgRecData", "TagFmncOrgRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxFmncVExpstate, newSrefIxFmncVExpstate;

	_scrJref = retrieveValue(dom, "//fmnc:*/fmnc:scrJref");
	srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncOrgRec", "srefIxFmncVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngFmncOrgRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncOrgRec", "srefIxFmncVExpstate");

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
			} else if (_scrJref == scrJrefKStocklcn) {
				lhsdoc.getElementById("KStocklcn").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefADetail) {
				lhsdoc.getElementById("ADetail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefBio1NFabproject) {
				rhsdoc.getElementById("Bio1NFabproject").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMnf1NTool) {
				rhsdoc.getElementById("Mnf1NTool").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NArticle) {
				rhsdoc.getElementById("1NArticle").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefPco1NPurchorder) {
				rhsdoc.getElementById("Pco1NPurchorder").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSpl1NPurchorder) {
				rhsdoc.getElementById("Spl1NPurchorder").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NStockitem) {
				rhsdoc.getElementById("1NStockitem").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NOrg) {
				rhsdoc.getElementById("Sup1NOrg").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NAddress) {
				rhsdoc.getElementById("Hk1NAddress").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNPerson) {
				rhsdoc.getElementById("MNPerson").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSvcMNTool) {
				rhsdoc.getElementById("SvcMNTool").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNArticle) {
				rhsdoc.getElementById("MNArticle").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngFmncOrgRecData") {
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

			} else if (blk.nodeName == "DpchEngFmncOrgRecData") {
				srefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncOrgRec", "srefIxFmncVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxFmncVExpstate = retrieveSi(srcdoc, "StatShrFmncOrgRec", "srefIxFmncVExpstate");

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


