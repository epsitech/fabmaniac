/**
  * \file VecFmncVUserlevel.cpp
  * vector VecFmncVUserlevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVUserlevel.h"

/******************************************************************************
 namespace VecFmncVUserlevel
 ******************************************************************************/

uint VecFmncVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	else if (s == "gadm") return GADM;
	else if (s == "reg") return REG;
	else if (s == "vtor") return VTOR;

	return(0);
};

string VecFmncVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	else if (ix == GADM) return("gadm");
	else if (ix == REG) return("reg");
	else if (ix == VTOR) return("vtor");

	return("");
};

string VecFmncVUserlevel::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == ADM) return("administrator");
		else if (ix == GADM) return("user group administrator");
		else if (ix == REG) return("regular user");
		else if (ix == VTOR) return("visitor");
	} else if (ixFmncVLocale == 2) {
		if (ix == ADM) return("Administrator");
		else if (ix == GADM) return("Gruppenadministrator");
		else if (ix == REG) return("regul\\u00e4rer Benutzer");
		else if (ix == VTOR) return("Besucher");
	} else if (ixFmncVLocale == 3) {
		if (ix == ADM) return("administrateur");
		else if (ix == GADM) return("administrateur groupe d'utilisateurs");
		else if (ix == REG) return("utilisateur r\\u00e9gulier");
		else if (ix == VTOR) return("visiteur");
	};

	return("");
};

void VecFmncVUserlevel::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

