/**
  * \file PnlFmncStartLogout.js
  * web client functionality for Fmnc logout panel
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

function refresh(srefIxFmncVLocale) {
	if (srefIxFmncVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Logout");
		setTextContent(doc, doc.getElementById("CptMessage"), "Your session has been terminated.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Login screen");
	} else if (srefIxFmncVLocale == "dech") {
		setTextContent(doc, doc.getElementById("Cpt"), "Abmeldung");
		setTextContent(doc, doc.getElementById("CptMessage"), "Ihre Sitzung wurde beendet.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Anmeldefenster");
	} else if (srefIxFmncVLocale == "frch") {
		setTextContent(doc, doc.getElementById("Cpt"), "D\\u00e9connexion");
		setTextContent(doc, doc.getElementById("CptMessage"), "Votre s\\u00e9ance a \\u00e9t\\u00e9 termin\\u00e9e.");
		setTextContent(doc, doc.getElementById("ButLogin"), "\\u00c9cran connexion");
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


