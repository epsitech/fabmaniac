/**
  * \file VecFmncVMaintable.cpp
  * vector VecFmncVMaintable (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMaintable.h"

/******************************************************************************
 namespace VecFmncVMaintable
 ******************************************************************************/

uint VecFmncVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "tblfmncmactivity") return TBLFMNCMACTIVITY;
	else if (s == "tblfmncmaddress") return TBLFMNCMADDRESS;
	else if (s == "tblfmncmarticle") return TBLFMNCMARTICLE;
	else if (s == "tblfmncmbill") return TBLFMNCMBILL;
	else if (s == "tblfmncmfab") return TBLFMNCMFAB;
	else if (s == "tblfmncmfabproject") return TBLFMNCMFABPROJECT;
	else if (s == "tblfmncmfabuser") return TBLFMNCMFABUSER;
	else if (s == "tblfmncmfile") return TBLFMNCMFILE;
	else if (s == "tblfmncmorg") return TBLFMNCMORG;
	else if (s == "tblfmncmperson") return TBLFMNCMPERSON;
	else if (s == "tblfmncmproject") return TBLFMNCMPROJECT;
	else if (s == "tblfmncmpurchorder") return TBLFMNCMPURCHORDER;
	else if (s == "tblfmncmrun") return TBLFMNCMRUN;
	else if (s == "tblfmncmsample") return TBLFMNCMSAMPLE;
	else if (s == "tblfmncmsession") return TBLFMNCMSESSION;
	else if (s == "tblfmncmstep") return TBLFMNCMSTEP;
	else if (s == "tblfmncmstockitem") return TBLFMNCMSTOCKITEM;
	else if (s == "tblfmncmtool") return TBLFMNCMTOOL;
	else if (s == "tblfmncmtooltype") return TBLFMNCMTOOLTYPE;
	else if (s == "tblfmncmuser") return TBLFMNCMUSER;
	else if (s == "tblfmncmusergroup") return TBLFMNCMUSERGROUP;

	return(0);
};

string VecFmncVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == TBLFMNCMACTIVITY) return("TblFmncMActivity");
	else if (ix == TBLFMNCMADDRESS) return("TblFmncMAddress");
	else if (ix == TBLFMNCMARTICLE) return("TblFmncMArticle");
	else if (ix == TBLFMNCMBILL) return("TblFmncMBill");
	else if (ix == TBLFMNCMFAB) return("TblFmncMFab");
	else if (ix == TBLFMNCMFABPROJECT) return("TblFmncMFabproject");
	else if (ix == TBLFMNCMFABUSER) return("TblFmncMFabuser");
	else if (ix == TBLFMNCMFILE) return("TblFmncMFile");
	else if (ix == TBLFMNCMORG) return("TblFmncMOrg");
	else if (ix == TBLFMNCMPERSON) return("TblFmncMPerson");
	else if (ix == TBLFMNCMPROJECT) return("TblFmncMProject");
	else if (ix == TBLFMNCMPURCHORDER) return("TblFmncMPurchorder");
	else if (ix == TBLFMNCMRUN) return("TblFmncMRun");
	else if (ix == TBLFMNCMSAMPLE) return("TblFmncMSample");
	else if (ix == TBLFMNCMSESSION) return("TblFmncMSession");
	else if (ix == TBLFMNCMSTEP) return("TblFmncMStep");
	else if (ix == TBLFMNCMSTOCKITEM) return("TblFmncMStockitem");
	else if (ix == TBLFMNCMTOOL) return("TblFmncMTool");
	else if (ix == TBLFMNCMTOOLTYPE) return("TblFmncMTooltype");
	else if (ix == TBLFMNCMUSER) return("TblFmncMUser");
	else if (ix == TBLFMNCMUSERGROUP) return("TblFmncMUsergroup");

	return("");
};

string VecFmncVMaintable::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == TBLFMNCMACTIVITY) return("activity");
		else if (ix == TBLFMNCMADDRESS) return("address");
		else if (ix == TBLFMNCMARTICLE) return("article");
		else if (ix == TBLFMNCMBILL) return("bill");
		else if (ix == TBLFMNCMFAB) return("fab");
		else if (ix == TBLFMNCMFABPROJECT) return("fab project");
		else if (ix == TBLFMNCMFABUSER) return("fab user");
		else if (ix == TBLFMNCMFILE) return("file");
		else if (ix == TBLFMNCMORG) return("organization");
		else if (ix == TBLFMNCMPERSON) return("person");
		else if (ix == TBLFMNCMPROJECT) return("project");
		else if (ix == TBLFMNCMPURCHORDER) return("purchase order");
		else if (ix == TBLFMNCMRUN) return("run");
		else if (ix == TBLFMNCMSAMPLE) return("sample");
		else if (ix == TBLFMNCMSESSION) return("session");
		else if (ix == TBLFMNCMSTEP) return("step");
		else if (ix == TBLFMNCMSTOCKITEM) return("stock item");
		else if (ix == TBLFMNCMTOOL) return("tool");
		else if (ix == TBLFMNCMTOOLTYPE) return("tool type");
		else if (ix == TBLFMNCMUSER) return("user");
		else if (ix == TBLFMNCMUSERGROUP) return("user group");
	} else if (ixFmncVLocale == 2) {
		if (ix == VOID) return("kein");
		else if (ix == TBLFMNCMACTIVITY) return("Aktivit\\u00e4t");
		else if (ix == TBLFMNCMADDRESS) return("Adresse");
		else if (ix == TBLFMNCMARTICLE) return("Artikel");
		else if (ix == TBLFMNCMBILL) return("Rechnung");
		else if (ix == TBLFMNCMFAB) return("Reinraum");
		else if (ix == TBLFMNCMFABPROJECT) return("Reinraumprojekt");
		else if (ix == TBLFMNCMFABUSER) return("Reinraumnutzer");
		else if (ix == TBLFMNCMFILE) return("Datei");
		else if (ix == TBLFMNCMORG) return("Organisation");
		else if (ix == TBLFMNCMPERSON) return("Person");
		else if (ix == TBLFMNCMPROJECT) return("Projekt");
		else if (ix == TBLFMNCMPURCHORDER) return("Bestellung");
		else if (ix == TBLFMNCMRUN) return("Lauf");
		else if (ix == TBLFMNCMSAMPLE) return("Sample");
		else if (ix == TBLFMNCMSESSION) return("Sitzung");
		else if (ix == TBLFMNCMSTEP) return("Schritt");
		else if (ix == TBLFMNCMSTOCKITEM) return("Lagerposten");
		else if (ix == TBLFMNCMTOOL) return("Ger\\u00e4t");
		else if (ix == TBLFMNCMTOOLTYPE) return("Ger\\u00e4tetyp");
		else if (ix == TBLFMNCMUSER) return("Benutzer");
		else if (ix == TBLFMNCMUSERGROUP) return("Benutzergruppe");
	} else if (ixFmncVLocale == 3) {
		if (ix == VOID) return("aucun");
		else if (ix == TBLFMNCMACTIVITY) return("activit\\u00e9");
		else if (ix == TBLFMNCMADDRESS) return("adresse");
		else if (ix == TBLFMNCMARTICLE) return("article");
		else if (ix == TBLFMNCMBILL) return("facture");
		else if (ix == TBLFMNCMFAB) return("salle blanche");
		else if (ix == TBLFMNCMFABPROJECT) return("projet salle blanche");
		else if (ix == TBLFMNCMFABUSER) return("utilisateur salle blanche");
		else if (ix == TBLFMNCMFILE) return("fichier");
		else if (ix == TBLFMNCMORG) return("organisme");
		else if (ix == TBLFMNCMPERSON) return("individu");
		else if (ix == TBLFMNCMPROJECT) return("projet");
		else if (ix == TBLFMNCMPURCHORDER) return("commande");
		else if (ix == TBLFMNCMRUN) return("d\\u00e9roulement");
		else if (ix == TBLFMNCMSAMPLE) return("\\u00e9chantillon");
		else if (ix == TBLFMNCMSESSION) return("s\\u00e9ance");
		else if (ix == TBLFMNCMSTEP) return("\\u00e9tape");
		else if (ix == TBLFMNCMSTOCKITEM) return("poste du stock");
		else if (ix == TBLFMNCMTOOL) return("\\u00e9quipement");
		else if (ix == TBLFMNCMTOOLTYPE) return("type d'\\u00e9quipement");
		else if (ix == TBLFMNCMUSER) return("utilisateur");
		else if (ix == TBLFMNCMUSERGROUP) return("groupe d'utilisateurs");
	};

	return("");
};

void VecFmncVMaintable::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=22;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

