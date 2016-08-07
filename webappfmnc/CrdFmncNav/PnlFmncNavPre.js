/**
  * \file PnlFmncNavPre.js
  * web client functionality for panel PnlFmncNavPre
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtFabAvail = (retrieveSi(srcdoc, "StatShrFmncNavPre", "TxtFabAvail") == "true"); if (TxtFabAvail) n++;
	var TxtRunAvail = (retrieveSi(srcdoc, "StatShrFmncNavPre", "TxtRunAvail") == "true"); if (TxtRunAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtFabAvail) {
		i++;

		line.appendChild(makeImgBut("ButFabRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagFmncNavPre", "CptFab") + ": " + retrieveCi(srcdoc, "ContInfFmncNavPre", "TxtFab")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagFmncNavPre", "CptFab") + ": " + retrieveCi(srcdoc, "ContInfFmncNavPre", "TxtFab") + ",\u00a0\u00a0"));
	};

	if (TxtRunAvail) {
		i++;

		line.appendChild(makeImgBut("ButRunRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagFmncNavPre", "CptRun") + ": " + retrieveCi(srcdoc, "ContInfFmncNavPre", "TxtRun")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagFmncNavPre", "CptRun") + ": " + retrieveCi(srcdoc, "ContInfFmncNavPre", "TxtRun") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncNavPreData", "ContInfFmncNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncNavPreData", "StatShrFmncNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncNavPreData", "TagFmncNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncNavPreData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngFmncNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
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

			} else if (blk.nodeName == "DpchEngFmncNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


