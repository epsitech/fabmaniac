/**
  * \file VecFmncVAccess.cpp
  * vector VecFmncVAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVAccess.h"

/******************************************************************************
 namespace VecFmncVAccess
 ******************************************************************************/

uint VecFmncVAccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	else if (s == "none") return NONE;
	else if (s == "view") return VIEW;

	return(0);
};

string VecFmncVAccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	else if (ix == NONE) return("none");
	else if (ix == VIEW) return("view");

	return("");
};

string VecFmncVAccess::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == FULL) return("full");
		else if (ix == NONE) return("none");
		else if (ix == VIEW) return("view");
	} else if (ixFmncVLocale == 2) {
		if (ix == FULL) return("voll");
		else if (ix == NONE) return("kein");
		else if (ix == VIEW) return("anschauen");
	} else if (ixFmncVLocale == 3) {
		if (ix == FULL) return("plein");
		else if (ix == NONE) return("aucun");
		else if (ix == VIEW) return("afficher");
	};

	return("");
};

void VecFmncVAccess::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

