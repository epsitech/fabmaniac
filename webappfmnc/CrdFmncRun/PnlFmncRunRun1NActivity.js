/**
  * \file PnlFmncRunRun1NActivity.js
  * web client functionality for panel PnlFmncRunRun1NActivity
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

// --- expand state management
function minimize(updh) {
// IP minimize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncRunRun1NActivity", "srefIxFmncVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppFmncRunRun1NActivity", "srefIxFmncVExpstate", "mind");

// IP minimize.estapp --- END
	getRecwnd().changeHeight("Run1NActivity", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Run1NActivity_side").setAttribute("height", "30");
	doc.getElementById("Run1NActivity_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Run1NActivity_side").src = "./PnlFmncRunRun1NActivity_aside.html";
	doc.getElementById("Run1NActivity_cont").src = "./PnlFmncRunRun1NActivity_a.html";
};

function regularize() {
// IP regularize.estapp --- BEGIN
	if (retrieveSi(srcdoc, "StatAppFmncRunRun1NActivity", "srefIxFmncVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppFmncRunRun1NActivity", "srefIxFmncVExpstate", "regd");

// IP regularize.estapp --- END
	getRecwnd().changeHeight("Run1NActivity", 255, true);
	doc.getElementById("tdSide").setAttribute("height", "255");
	doc.getElementById("Run1NActivity_side").setAttribute("height", "255");
	doc.getElementById("Run1NActivity_cont").setAttribute("height", "255");

	// change content
	doc.getElementById("Run1NActivity_side").src = "./PnlFmncRunRun1NActivity_bside.html";
	doc.getElementById("Run1NActivity_cont").src = "./PnlFmncRunRun1NActivity_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Run1NActivity_side").contentDocument;
	contdoc = doc.getElementById("Run1NActivity_cont").contentDocument;
	hdrdoc = null;
	tbldoc = null;
	ftrdoc = null;

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Run1NActivity_side").contentDocument;
	contdoc = doc.getElementById("Run1NActivity_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Run1NActivity_hdr").contentDocument;
	tbldoc = contdoc.getElementById("Run1NActivity_tbl").contentDocument;
	ftrdoc = contdoc.getElementById("Run1NActivity_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncRunRun1NActivity", "Cpt"));

	// column headers in refreshB() only

	setTextContent(ftrdoc, ftrdoc.getElementById("TrsGoto"), retrieveTi(srcdoc, "TagFmncRunRun1NActivity", "Trs"));

	refreshB(true);
};

function init() {
// IP init.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncRunRun1NActivity", "srefIxFmncVExpstate");
// IP init.estapp --- END

	if (srefIxFmncVExpstate == "mind") initA();
	else if (srefIxFmncVExpstate == "regd") initB();
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagFmncRunRun1NActivity", "Cpt") + " (" + retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "ntot") + ")");
};

function refreshB(chgcol) {
	// obtain record set characteristics
	var jnumSel = parseInt(retrieveSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnum"));
	var jnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "jnumFirstdisp"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ndisp"));
	var jnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "jnumFirstload"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "ntot"));

	var mytbl, mytr, mytd, myimg, mycg, mycol;

	var txt;
	var jnum, selclass;

	var rownode;

	var height;

	// update column characteristics
	if (chgcol) {
		// obtain column (header) characteristics
		var firstcol = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "firstcol"));
		var ncol = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ncol"));

		var TcoRefWidth = parseInt(retrieveSi(srcdoc, "StgIacFmncRunRun1NActivity", "TcoRefWidth"));

		// col data is stored in document variables
		doc.cols = new Array();
		doc.widths = new Array();
		doc.fs = new Array();

		var i, ix;
		var wtot = 0;
		var wmax = 425;

		for (i=firstcol,ix=0 ; i<=ncol ; i++) {
			ix++;

			if (i == 1) {
				doc.cols.push("TcoRef"); doc.widths.push(TcoRefWidth); doc.fs.push("ref"); wtot += TcoRefWidth;
			} else {
				ix--;
			};

			if (wtot > wmax) break;
		};

		if (wtot > wmax) {
			wtot -= doc.widths[ix-1];
			doc.cols.pop(); doc.widths.pop(); doc.fs.pop();
			i--; ix--;
		};

		doc.widths[ix-1] = doc.widths[ix-1] + (wmax-wtot);

		// column left and right button availability
		doc.cl = false;
		doc.cr = false;

		doc.cl = (firstcol > 1);
		doc.cr = (ncol > i);

		// update colgroup
		mycg = tbldoc.getElementById("cols");
		var del = mycg.childNodes[1];
		while (del) {
			mycg.removeChild(del);
			del = mycg.childNodes[1];
		};

		mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
		mycol.setAttribute("width", "20");
		mycg.appendChild(mycol);

		for (i=0;i<doc.widths.length;i++) {
			mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
			mycol.setAttribute("width", "" + doc.widths[i]);
			mycg.appendChild(mycol);
		};

		mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
		mycol.setAttribute("width", "15");
		mycg.appendChild(mycol);

		// update header row
		mytr = tbldoc.getElementById("hdr");
		clearElem(mytr);

		mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("id", "rhcl");
		mytd.setAttribute("height", "20");
		mytd.setAttribute("class", "col");
		mytd.setAttribute("style", "vertical-align:bottom");

		if (doc.cl) {
			myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
			myimg.setAttribute("id", "TblCprevious");
			myimg.setAttribute("class", "but");
			myimg.setAttribute("width", "12");
			myimg.setAttribute("height", "12");
			myimg.setAttribute("alt", "cprevious");
			myimg.setAttribute("src", "../icon/cprevious.png");
			myimg.setAttribute("onmouseover", "src='../icon/cprevious_hlt.png'");
			myimg.setAttribute("onmouseout", "src='../icon/cprevious.png'");
			myimg.setAttribute("onclick", "handleTblCpreviousClick()")
			mytd.appendChild(myimg);
		};

		mytr.appendChild(mytd);

		for (i=0;i<doc.cols.length;i++) {
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", doc.cols[i]);
			mytd.setAttribute("class", "col");
			setTextContent(tbldoc, mytd, retrieveTi(srcdoc, "TagFmncRunRun1NActivity", doc.cols[i]));

			mytr.appendChild(mytd);
		};

		mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("id", "tdTsb");
		mytr.appendChild(mytd);
	};

	mytr = tbldoc.getElementById("hdr");

	// reset jnumFirstdisp if required
	if ((jnumFirstdisp < jnumFirstload) || (jnumFirstdisp > (jnumFirstload+nload-1))) {
		jnumFirstdisp = jnumFirstload;
		setSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "jnumFirstdisp", jnumFirstdisp);
	};

	// scroll bar
	mytr.removeChild(tbldoc.getElementById("tdTsb"));
	mytr.appendChild(makeTdTsb(tbldoc, (ntot > ndisp), doc.cr, ndisp, (jnumFirstdisp - 1) / (ntot - ndisp), true));

	// clear data rows
	mytbl = tbldoc.getElementById("tbl");
	
	for (i=1;true;i++) {
		mytr = tbldoc.getElementById("r" + i);

		if (mytr) {
			mytbl.removeChild(mytr);
		} else {
			break;
		};
	};

	// fill data rows
	for (i=1;i<=ndisp;i++) {
		mytr = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:tr");
		mytr.setAttribute("id", "r" + i);

		jnum = jnumFirstdisp+i-1;

		// find element in ListFmncQRunRun1NActivity
		rownode = getRownode(srcdoc, "ListFmncQRunRun1NActivity", jnum);

		if (rownode) {
			// regular data row
			if (jnum == jnumSel) {
				selclass = "sel";
			} else {
				if ((jnum%2) == 0) selclass = "nonsel";
				else selclass = "nonselalt";
			};

			if (jnum == jnumSel) mytr.setAttribute("onclick", "handleTblSelect(0)");
			else mytr.setAttribute("onclick", "handleTblSelect(" + jnum + ")");

			// selector
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", "r" + i + "cs");
			mytd.setAttribute("height", "18");
			mytd.setAttribute("class", selclass);

			myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
			myimg.setAttribute("id", "r" + i + "s");
			myimg.setAttribute("width", "10");
			myimg.setAttribute("height", "10");
			myimg.setAttribute("alt", "sel");
			if (jnum == jnumSel) {
				myimg.setAttribute("src", "../icon/sel_hlt.png");
			} else {
				myimg.setAttribute("src", "../icon/sel.png");
				myimg.setAttribute("onmouseover", "src='../icon/sel_hlt.png'");
				myimg.setAttribute("onmouseout", "src='../icon/sel.png'");
			};

			mytd.appendChild(myimg);
			mytr.appendChild(mytd);

			// data cells
			for (j=0;j<doc.fs.length;j++) {
				mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				mytd.setAttribute("id", "r" + i + "c" + (j+1));
				mytd.setAttribute("class", selclass);

				txt = replaceUesc(retrieveRowField(srcdoc, rownode, doc.fs[j]));

				if ((jnum == jnumSel) && (txt.length > Math.ceil(doc.widths[j]*0.125))) {
					txt = txt.substring(0, Math.ceil(doc.widths[j]*0.125) -3) + "...";
				} else if ((jnum != jnumSel) && (txt.length > Math.ceil(doc.widths[j]*0.15))) {
					txt = txt.substring(0, Math.ceil(doc.widths[j]*0.15) -3) + "...";
				};

				mytd.appendChild(tbldoc.createTextNode(txt));
				mytr.appendChild(mytd);
			};

		} else {
			// empty row
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", "r" + i + "cs");
			mytd.setAttribute("height", "18");
			mytd.setAttribute("colspan", "" + (doc.widths.length + 2));
			mytr.appendChild(mytd);
		};

		mytbl.appendChild(mytr);
	};

	// footer row
	var jnumLastdisp = jnumFirstdisp + ndisp - 1;
	if (jnumLastdisp > ntot) jnumLastdisp = ntot;

	setTextContent(ftrdoc, ftrdoc.getElementById("TxtShowing"), strShowing(retrieveTi(srcdoc, "TagFmncRunRun1NActivity", "TxtShowing1"), jnumFirstdisp, jnumLastdisp, ntot, retrieveTi(srcdoc, "TagFmncRunRun1NActivity", "TxtShowing2")));

	if (ntot == 0) {
		ftrdoc.getElementById("TrsGoto").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsGoto").setAttribute("onclick", "");
	} else {
		ftrdoc.getElementById("TrsGoto").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsGoto").setAttribute("onclick", "handleTrsGotoClick()");
	};

	if ((ntot <= 1) || (jnumSel == 1)) {
		ftrdoc.getElementById("TrsFirst").src = "../icon/first_inact.png";
		ftrdoc.getElementById("TrsFirst").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseover", "");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseout", "");
		ftrdoc.getElementById("TrsFirst").setAttribute("onclick", "");

		ftrdoc.getElementById("TrsPrevious").src = "../icon/previous_inact.png";
		ftrdoc.getElementById("TrsPrevious").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseover", "");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseout", "");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onclick", "");
	} else {
		ftrdoc.getElementById("TrsFirst").src = "../icon/first.png";
		ftrdoc.getElementById("TrsFirst").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseover", "src='../icon/first_hlt.png'");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseout", "src='../icon/first.png'");
		ftrdoc.getElementById("TrsFirst").setAttribute("onclick", "handleTrsFirstClick()");

		ftrdoc.getElementById("TrsPrevious").src = "../icon/previous.png";
		ftrdoc.getElementById("TrsPrevious").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseover", "src='../icon/previous_hlt.png'");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseout", "src='../icon/previous.png'");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onclick", "handleTrsPreviousClick()");
	};

	if ((ntot <= 1) || (jnumSel == ntot)) {
		ftrdoc.getElementById("TrsNext").src = "../icon/next_inact.png";
		ftrdoc.getElementById("TrsNext").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsNext").onmouseover = null;
		ftrdoc.getElementById("TrsNext").onmouseout = null;
		ftrdoc.getElementById("TrsNext").onclick = null;

		ftrdoc.getElementById("TrsLast").src = "../icon/last_inact.png";
		ftrdoc.getElementById("TrsLast").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsLast").onmouseover = null;
		ftrdoc.getElementById("TrsLast").onmouseout = null;
		ftrdoc.getElementById("TrsLast").onclick = null;
	} else {
		ftrdoc.getElementById("TrsNext").src = "../icon/next.png";
		ftrdoc.getElementById("TrsNext").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsNext").setAttribute("onmouseover", "src='../icon/next_hlt.png'");
		ftrdoc.getElementById("TrsNext").setAttribute("onmouseout", "src='../icon/next.png'");
		ftrdoc.getElementById("TrsNext").setAttribute("onclick", "handleTrsNextClick()");

		ftrdoc.getElementById("TrsLast").src = "../icon/last.png";
		ftrdoc.getElementById("TrsLast").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsLast").setAttribute("onmouseover", "src='../icon/last_hlt.png'");
		ftrdoc.getElementById("TrsLast").setAttribute("onmouseout", "src='../icon/last.png'");
		ftrdoc.getElementById("TrsLast").setAttribute("onclick", "handleTrsLastClick()");
	};

	refreshCsi(ftrdoc, "CsiQst", srcdoc, "FeedFCsiQst", retrieveCi(srcdoc, "ContInfFmncRunRun1NActivity", "numFCsiQst"));

	height = 20 + 18*ndisp;

	getRecwnd().changeHeight("Run1NActivity", height+55, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+55));
	doc.getElementById("Run1NActivity_side").setAttribute("height", "" + (height+55));
	doc.getElementById("Run1NActivity_cont").setAttribute("height", "" + (height+55));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+55-30));
	contdoc.getElementById("tdTbl").setAttribute("height", "" + height);
	contdoc.getElementById("Run1NActivity_tbl").setAttribute("height", "" + height);
};

function refresh() {
// IP refresh.estapp --- BEGIN
	var srefIxFmncVExpstate = retrieveSi(srcdoc, "StatAppFmncRunRun1NActivity", "srefIxFmncVExpstate");
// IP refresh.estapp --- END

	if (srefIxFmncVExpstate == "mind") refreshA();
	else if (srefIxFmncVExpstate == "regd") refreshB(false);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Run1NActivity_src").contentDocument;

	var str = serializeDpchApp("DpchAppFmncInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleTblSelect(jnum) {
	var jnumFirstdisp, jnumLastdisp, jnumFirstload;

	var oldJnum = parseInt(retrieveSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnum"));
	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "ntot"));

	if (ntot == 0) return;

	if (jnum < 0) jnum = 0;
	if (jnum > ntot) jnum = ntot;

	if (oldJnum != jnum) {
		setSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnum", jnum);

		if (jnum != 0) {
			if (!((jnum >= oldJnumFirstdisp) && (jnum <= (oldJnumFirstdisp+ndisp-1)))) {
				jnumFirstdisp = jnum - Math.ceil(0.5*ndisp) + 1;
				if ((jnumFirstdisp+ndisp-1) > ntot) jnumFirstdisp = ntot-ndisp+1;
				if (jnumFirstdisp < 1) jnumFirstdisp = 1;

				setSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "jnumFirstdisp", jnumFirstdisp);

				jnumLastdisp = jnumFirstdisp + ndisp - 1;
				if (jnumLastdisp > ntot) jnumLastdisp = ntot;

				if (!((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1)))) {
					jnumFirstload = jnum - Math.ceil(0.5*nload) + 1;
					if (jnumFirstload < 1) jnumFirstload = 1;

					setSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnumFirstload", jnumFirstload);
				};
			};
		};

		var str = serializeDpchAppData(srcdoc, "DpchAppFmncRunRun1NActivityData", scrJref, "StgIacQryFmncRunRun1NActivity");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function changeTblJnumFirstdisp(jnumFirstdisp, dJnumFirstdisp, dpgJnumFirstdisp) {
	var jnumLastdisp, jnumFirstload;

	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "ntot"));

	if (ntot == 0) return;

	if (dpgJnumFirstdisp < 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp + 1;
	else if (dpgJnumFirstdisp > 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp - 1;
	else if (dJnumFirstdisp != 0) jnumFirstdisp = oldJnumFirstdisp + dJnumFirstdisp;

	if (jnumFirstdisp > (ntot-ndisp+1)) jnumFirstdisp = ntot-ndisp+1;
	if (jnumFirstdisp < 1) jnumFirstdisp = 1;

	if (oldJnumFirstdisp != jnumFirstdisp) {
		setSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "jnumFirstdisp", jnumFirstdisp);

		jnumLastdisp = jnumFirstdisp + ndisp - 1;
		if (jnumLastdisp > ntot) jnumLastdisp = ntot;

		if ((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1))) {
			refreshB(false);

		} else {
			jnumFirstload = jnumFirstdisp - Math.ceil(0.5*(nload-ndisp));
			if (jnumFirstload < 1) jnumFirstload = 1;

			setSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnumFirstload", jnumFirstload);

			var str = serializeDpchAppData(srcdoc, "DpchAppFmncRunRun1NActivityData", scrJref, "StgIacQryFmncRunRun1NActivity");
			sendReq(str, doc, handleDpchAppDataDoReply);
		};
	};
};

function handleTblCpreviousClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "firstcol"));

	setSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "firstcol", "" + (oldFirstcol-1));

	refreshB(true);
};

function handleTblCnextClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "firstcol"));

	setSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "firstcol", "" + (oldFirstcol+1));

	refreshB(true);
};

function handleTrsFirstClick() {
	handleTblSelect(1);
};

function handleTrsPreviousClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnum"));

	handleTblSelect(jnum-1);
};

function handleTrsNextClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryFmncRunRun1NActivity", "jnum"));

	handleTblSelect(jnum+1);
};

function handleTrsLastClick() {
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "ntot"));

	handleTblSelect(ntot);
};

function handleTrsGotoClick() {
	ftrdoc.getElementById("TrsGoto").style.display = "none";

	var elem = ftrdoc.getElementById("TrsRow");
	elem.style.display = "inline";
	elem.focus();
};

function handleTrsRowMou() {
	var elem = ftrdoc.getElementById("TrsRow");
	elem.value = "";
	elem.style.display = "none";

	ftrdoc.getElementById("TrsGoto").style.display = "inline";
};

function handleTrsRowKey(evt) {
	if (evt.keyCode == 13) {
		handleTblSelect(parseInt(ftrdoc.getElementById("TrsRow").value));

		handleTrsRowMou();
		return false;
	};

	return true;
};

function setTsbPos(pos) {
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ndisp"));
	var vpos = (18 + Math.round(pos * (18*(ndisp-2))));

	tbldoc.getElementById("TsbJpupr").setAttribute("height", "" + (vpos-10));
	tbldoc.getElementById("TsbJpupl").setAttribute("y2", "" + vpos);

	tbldoc.getElementById("TsbJpdownr").setAttribute("y", "" + vpos);
	tbldoc.getElementById("TsbJpdownr").setAttribute("height", "" + (18*ndisp-vpos-11));
	tbldoc.getElementById("TsbJpdownl").setAttribute("y1", "" + vpos);

	tbldoc.getElementById("Tsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleTsbUpClick() {
	changeTblJnumFirstdisp(0, -1, 0);
};

function handleTsbJpupClick() {
	changeTblJnumFirstdisp(0, 0, -1);
};

function handleTsbJpdownClick() {
	changeTblJnumFirstdisp(0, 0, 1);
};

function handleTsbDownClick() {
	changeTblJnumFirstdisp(0, 1, 0);
};

function handleTsbMdn() {
	tbldoc.getElementById("tdTsb").onmousemove = handleTsbMove;
	tbldoc.getElementById("tdTsb").onmouseup = handleTsbMup;
};

function handleTsbMove(evt) {
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ndisp"));

	if ((evt.clientY >= (18+20)) && (evt.clientY <= (18*(ndisp-1)+20))) {
		pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));
		setTsbPos(pos);
	};
};

function handleTsbMup(evt) {
	tbldoc.getElementById("tdTsb").removeAttribute("onmousemove");
	tbldoc.getElementById("tdTsb").removeAttribute("onmouseup");

	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryFmncRunRun1NActivity", "ntot"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryFmncRunRun1NActivity", "ndisp"));

	var pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));

	changeTblJnumFirstdisp(Math.round(pos*(ntot-ndisp))+1, 0, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncRunRun1NActivityDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppFmncRunRun1NActivityDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "ContInfFmncRunRun1NActivity", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "FeedFCsiQst", srcdoc)) mask.push("feedFCsiQst");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "StatAppFmncRunRun1NActivity", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "StatShrFmncRunRun1NActivity", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "StgIacFmncRunRun1NActivity", srcdoc)) mask.push("stgiac");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "TagFmncRunRun1NActivity", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "ListFmncQRunRun1NActivity", srcdoc)) mask.push("rst");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "StatAppQryFmncRunRun1NActivity", srcdoc)) mask.push("statappqry");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "StatShrQryFmncRunRun1NActivity", srcdoc)) mask.push("statshrqry");
	if (updateSrcblock(dom, "DpchEngFmncRunRun1NActivityData", "StgIacQryFmncRunRun1NActivity", srcdoc)) mask.push("stgiacqry");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngFmncRunRun1NActivityData") {
// IP handleDpchEng.estapp --- BEGIN
		mergeDpchEngData(dom);
		refresh();
// IP handleDpchEng.estapp --- END
// IP handleDpchEng --- INSERT
	};
};

// IP dpchhdls --- INSERT

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngFmncRunRun1NActivityData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Run1NActivity");
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

			} else if (blk.nodeName == "DpchEngFmncRunRun1NActivityData") {
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


