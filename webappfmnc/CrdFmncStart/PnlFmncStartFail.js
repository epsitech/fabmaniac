/**
  * \file PnlFmncStartFail.js
  * web client functionality for Fmnc login failure panel
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function refresh(srefIxFmncVLocale) {
	if (srefIxFmncVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Error");
		setTextContent(doc, doc.getElementById("CptMessage"), "Login failed.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Back");
	} else if (srefIxFmncVLocale == "dech") {
		setTextContent(doc, doc.getElementById("Cpt"), "Fehler");
		setTextContent(doc, doc.getElementById("CptMessage"), "Anmeldung fehlgeschlagen.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Zur\\u00fcck");
	} else if (srefIxFmncVLocale == "frch") {
		setTextContent(doc, doc.getElementById("Cpt"), "Erreur");
		setTextContent(doc, doc.getElementById("CptMessage"), "\\u00c9chec de connexion.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Retour");
	};
};

function handleLoad() {
	doc = document;

	// set captions according to card locale
	refresh(getCrdwnd().getLocale());
};

function handleButLoginClick() {
	getCrdwnd().setCont("Login");
};


