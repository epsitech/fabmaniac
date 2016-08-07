/**
  * \file VecFmncVCard.cpp
  * vector VecFmncVCard (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVCard.h"

/******************************************************************************
 namespace VecFmncVCard
 ******************************************************************************/

uint VecFmncVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdfmncnav") return CRDFMNCNAV;
	else if (s == "crdfmncusg") return CRDFMNCUSG;
	else if (s == "crdfmncusr") return CRDFMNCUSR;
	else if (s == "crdfmncorg") return CRDFMNCORG;
	else if (s == "crdfmncprs") return CRDFMNCPRS;
	else if (s == "crdfmncadr") return CRDFMNCADR;
	else if (s == "crdfmncfil") return CRDFMNCFIL;
	else if (s == "crdfmncstp") return CRDFMNCSTP;
	else if (s == "crdfmncprj") return CRDFMNCPRJ;
	else if (s == "crdfmncrun") return CRDFMNCRUN;
	else if (s == "crdfmncact") return CRDFMNCACT;
	else if (s == "crdfmncsep") return CRDFMNCSEP;
	else if (s == "crdfmncsmp") return CRDFMNCSMP;
	else if (s == "crdfmncfab") return CRDFMNCFAB;
	else if (s == "crdfmncfus") return CRDFMNCFUS;
	else if (s == "crdfmnctty") return CRDFMNCTTY;
	else if (s == "crdfmnctol") return CRDFMNCTOL;
	else if (s == "crdfmncfpj") return CRDFMNCFPJ;
	else if (s == "crdfmncbil") return CRDFMNCBIL;
	else if (s == "crdfmncart") return CRDFMNCART;
	else if (s == "crdfmncski") return CRDFMNCSKI;
	else if (s == "crdfmncpco") return CRDFMNCPCO;

	return(0);
};

string VecFmncVCard::getSref(
			const uint ix
		) {
	if (ix == CRDFMNCNAV) return("CrdFmncNav");
	else if (ix == CRDFMNCUSG) return("CrdFmncUsg");
	else if (ix == CRDFMNCUSR) return("CrdFmncUsr");
	else if (ix == CRDFMNCORG) return("CrdFmncOrg");
	else if (ix == CRDFMNCPRS) return("CrdFmncPrs");
	else if (ix == CRDFMNCADR) return("CrdFmncAdr");
	else if (ix == CRDFMNCFIL) return("CrdFmncFil");
	else if (ix == CRDFMNCSTP) return("CrdFmncStp");
	else if (ix == CRDFMNCPRJ) return("CrdFmncPrj");
	else if (ix == CRDFMNCRUN) return("CrdFmncRun");
	else if (ix == CRDFMNCACT) return("CrdFmncAct");
	else if (ix == CRDFMNCSEP) return("CrdFmncSep");
	else if (ix == CRDFMNCSMP) return("CrdFmncSmp");
	else if (ix == CRDFMNCFAB) return("CrdFmncFab");
	else if (ix == CRDFMNCFUS) return("CrdFmncFus");
	else if (ix == CRDFMNCTTY) return("CrdFmncTty");
	else if (ix == CRDFMNCTOL) return("CrdFmncTol");
	else if (ix == CRDFMNCFPJ) return("CrdFmncFpj");
	else if (ix == CRDFMNCBIL) return("CrdFmncBil");
	else if (ix == CRDFMNCART) return("CrdFmncArt");
	else if (ix == CRDFMNCSKI) return("CrdFmncSki");
	else if (ix == CRDFMNCPCO) return("CrdFmncPco");

	return("");
};

string VecFmncVCard::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == CRDFMNCUSG) return("user groups");
		else if (ix == CRDFMNCUSR) return("users");
		else if (ix == CRDFMNCORG) return("organizations");
		else if (ix == CRDFMNCPRS) return("persons");
		else if (ix == CRDFMNCADR) return("addresses");
		else if (ix == CRDFMNCFIL) return("files");
		else if (ix == CRDFMNCSTP) return("recipes");
		else if (ix == CRDFMNCPRJ) return("projects");
		else if (ix == CRDFMNCRUN) return("runs");
		else if (ix == CRDFMNCACT) return("activities");
		else if (ix == CRDFMNCSEP) return("steps");
		else if (ix == CRDFMNCSMP) return("samples");
		else if (ix == CRDFMNCFAB) return("fabs");
		else if (ix == CRDFMNCFUS) return("fab users");
		else if (ix == CRDFMNCTTY) return("tool types");
		else if (ix == CRDFMNCTOL) return("tools");
		else if (ix == CRDFMNCFPJ) return("fab projects");
		else if (ix == CRDFMNCBIL) return("bills");
		else if (ix == CRDFMNCART) return("articles");
		else if (ix == CRDFMNCSKI) return("stock items");
		else if (ix == CRDFMNCPCO) return("purchase orders");
		else return(getSref(ix));
	} else if (ixFmncVLocale == 2) {
		if (ix == CRDFMNCUSG) return("Benutzergruppen");
		else if (ix == CRDFMNCUSR) return("Benutzer");
		else if (ix == CRDFMNCORG) return("Organisationen");
		else if (ix == CRDFMNCPRS) return("Personen");
		else if (ix == CRDFMNCADR) return("Adressen");
		else if (ix == CRDFMNCFIL) return("Dateien");
		else if (ix == CRDFMNCSTP) return("Rezepte");
		else if (ix == CRDFMNCPRJ) return("Projekte");
		else if (ix == CRDFMNCRUN) return("L\\u00e4ufe");
		else if (ix == CRDFMNCACT) return("Aktivit\\u00e4ten");
		else if (ix == CRDFMNCSEP) return("Schritte");
		else if (ix == CRDFMNCSMP) return("Samples");
		else if (ix == CRDFMNCFAB) return("Reinr\\u00e4ume");
		else if (ix == CRDFMNCFUS) return("Reinraumnutzer");
		else if (ix == CRDFMNCTTY) return("Ger\\u00e4tetypen");
		else if (ix == CRDFMNCTOL) return("Ger\\u00e4te");
		else if (ix == CRDFMNCFPJ) return("Reinraumprojekte");
		else if (ix == CRDFMNCBIL) return("Rechnungen");
		else if (ix == CRDFMNCART) return("Artikel");
		else if (ix == CRDFMNCSKI) return("Lagerposten");
		else if (ix == CRDFMNCPCO) return("Bestellungen");
		else return(getTitle(ix, 1));
	} else if (ixFmncVLocale == 3) {
		if (ix == CRDFMNCUSG) return("groupes d'utilisateurs");
		else if (ix == CRDFMNCUSR) return("utilisateurs");
		else if (ix == CRDFMNCORG) return("organismes");
		else if (ix == CRDFMNCPRS) return("individus");
		else if (ix == CRDFMNCADR) return("adresses");
		else if (ix == CRDFMNCFIL) return("fichiers");
		else if (ix == CRDFMNCSTP) return("recettes");
		else if (ix == CRDFMNCPRJ) return("projets");
		else if (ix == CRDFMNCRUN) return("d\\u00e9roulements");
		else if (ix == CRDFMNCACT) return("activit\\u00e9s");
		else if (ix == CRDFMNCSEP) return("\\u00e9tapes");
		else if (ix == CRDFMNCSMP) return("\\u00e9chantillons");
		else if (ix == CRDFMNCFAB) return("salles blanches");
		else if (ix == CRDFMNCFUS) return("utilisateurs salle blanche");
		else if (ix == CRDFMNCTTY) return("types d'\\u00e9quipement");
		else if (ix == CRDFMNCTOL) return("\\u00e9quipements");
		else if (ix == CRDFMNCFPJ) return("projets salle blanche");
		else if (ix == CRDFMNCBIL) return("factures");
		else if (ix == CRDFMNCART) return("articles");
		else if (ix == CRDFMNCSKI) return("postes du stock");
		else if (ix == CRDFMNCPCO) return("commandes");
		else return(getTitle(ix, 1));
	};

	return("");
};

void VecFmncVCard::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=22;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

