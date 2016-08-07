/**
  * \file VecFmncVLocale.cpp
  * vector VecFmncVLocale (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVLocale.h"

/******************************************************************************
 namespace VecFmncVLocale
 ******************************************************************************/

uint VecFmncVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;
	else if (s == "dech") return DECH;
	else if (s == "frch") return FRCH;

	return(0);
};

string VecFmncVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");
	else if (ix == DECH) return("dech");
	else if (ix == FRCH) return("frch");

	return("");
};

string VecFmncVLocale::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		else if (ix == DECH) return("German (Switzerland)");
		else if (ix == FRCH) return("French (Switzerland)");
	} else if (ixFmncVLocale == 2) {
		if (ix == ENUS) return("Englisch (Vereinigte Staaten)");
		else if (ix == DECH) return("Deutsch (Schweiz)");
		else if (ix == FRCH) return("Franz\\u00f6sisch (Schweiz)");
	} else if (ixFmncVLocale == 3) {
		if (ix == ENUS) return("Anglais (\\u00c9tats-Unis)");
		else if (ix == DECH) return("Allemand (Suisse)");
		else if (ix == FRCH) return("Fran\\u00e7ais (Suisse)");
	};

	return("");
};

void VecFmncVLocale::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

