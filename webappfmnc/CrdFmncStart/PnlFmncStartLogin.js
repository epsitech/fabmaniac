/**
  * \file PnlFmncStartLogin.js
  * web client functionality for Fmnc login panel
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function refresh(srefIxFmncVLocale) {
	var pup = doc.getElementById("PupLocale");
	var opt;

	clearElem(pup);

	if (srefIxFmncVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Login");

		opt = doc.createElement("option");
		opt.setAttribute("value", "enus");
		setTextContent(doc, opt, "English (United States)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "dech");
		setTextContent(doc, opt, "German (Switzerland)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "frch");
		setTextContent(doc, opt, "French (Switzerland)");
		pup.appendChild(opt);

		setTextContent(doc, doc.getElementById("CptUsername"), "User name");
		setTextContent(doc, doc.getElementById("CptPassword"), "Password");
		setTextContent(doc, doc.getElementById("ButReset"), "Reset");
		setTextContent(doc, doc.getElementById("ButLogin"), "Login");
	} else if (srefIxFmncVLocale == "dech") {
		setTextContent(doc, doc.getElementById("Cpt"), "Anmeldung");

		opt = doc.createElement("option");
		opt.setAttribute("value", "enus");
		setTextContent(doc, opt, "Englisch (Vereinigte Staaten)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "dech");
		setTextContent(doc, opt, "Deutsch (Schweiz)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "frch");
		setTextContent(doc, opt, "Franz\u00f6sisch (Schweiz)");
		pup.appendChild(opt);

		setTextContent(doc, doc.getElementById("CptUsername"), "Benutzername");
		setTextContent(doc, doc.getElementById("CptPassword"), "Passwort");
		setTextContent(doc, doc.getElementById("ButReset"), "Zur\\u00fccksetzen");
		setTextContent(doc, doc.getElementById("ButLogin"), "Anmelden");
	} else if (srefIxFmncVLocale == "frch") {
		setTextContent(doc, doc.getElementById("Cpt"), "Connexion");

		opt = doc.createElement("option");
		opt.setAttribute("value", "enus");
		setTextContent(doc, opt, "Anglais (\u00c9tats-Unis)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "dech");
		setTextContent(doc, opt, "Allemand (Suisse)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "frch");
		setTextContent(doc, opt, "Fran\u00e7ais (Suisse)");
		pup.appendChild(opt);

		setTextContent(doc, doc.getElementById("CptUsername"), "Nom d'utilisateur");
		setTextContent(doc, doc.getElementById("CptPassword"), "Mot de passe");
		setTextContent(doc, doc.getElementById("ButReset"), "Reculer");
		setTextContent(doc, doc.getElementById("ButLogin"), "Se connecter");
	};

	pup.value = srefIxFmncVLocale;
};

function handleLoad() {
	doc = document;

	// set captions according to card locale
	refresh(getCrdwnd().getLocale());
};

function handlePupLocaleChange() {
	srefIxFmncVLocale = doc.getElementById("PupLocale").value;
	refresh(srefIxFmncVLocale);

	// notify card to change cookie
	getCrdwnd().setLocale(srefIxFmncVLocale);
};

function handleTxfPasswordKey(evt) {
	if (evt.keyCode == 13) {
		handleButLoginClick();
		return false;
	};

	return true;
};

function handleButResetClick() {
	doc.getElementById("TxfUsername").value = "";
	doc.getElementById("TxfPassword").value = "";
};

function handleButLoginClick() {
	var str = serializeDpchAppLogin(doc.getElementById("TxfPassword").value, doc.getElementById("TxfUsername").value, getCrdwnd().getLocale());
	sendReq(str, doc, handleDpchAppLoginReply);
};

function handleDpchAppLoginReply() {
	var dom;

	var accepted, scrJref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		accepted = retrieveValue(dom, "//fmnc:DpchEngFmncConfirm/fmnc:accepted");
		scrJref = retrieveValue(dom, "//fmnc:DpchEngFmncConfirm/fmnc:scrJref");

		if (accepted == "true") {
			var str = serializeDpchApp("DpchAppFmncInit", scrJref);
			sendReq(str, doc, handleDpchAppInitReply);

		} else {
			getCrdwnd().setCont("Fail");
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//fmnc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngSessFmncData") {
				var scrJrefCrdnav = retrieveValue(dom, "//fmnc:DpchEngSessFmncData/fmnc:StatShrSessFmnc/fmnc:Si[@sref='scrJrefCrdnav']");

				if (scrJrefCrdnav == "") getCrdwnd().setCont("Fail");
				else window.open("/web/CrdFmncNav/CrdFmncNav.html?scrJref=" + scrJrefCrdnav, "_parent");
			};
		};
	};
};

function serializeDpchAppLogin(password, username, srefIxFmncVLocale) {
	var dpch, elem, txt;
	var ser;
	var str;

	dpch = doc.createElement("DpchAppRootFmncLogin");

	elem = doc.createElement("password");
	txt = doc.createTextNode(password);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("username");
	txt = doc.createTextNode(username);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("srefIxFmncVLocale");
	txt = doc.createTextNode(srefIxFmncVLocale);
	elem.appendChild(txt);
	dpch.appendChild(elem);	

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};


