/**
  * \file VecFmncVRepfsp.cpp
  * vector VecFmncVRepfsp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVRepfsp.h"

/******************************************************************************
 namespace VecFmncVRepfsp
 ******************************************************************************/

uint VecFmncVRepfsp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "rfil") return RFIL;
	else if (s == "rpar") return RPAR;

	return(0);
};

string VecFmncVRepfsp::getSref(
			const uint ix
		) {
	if (ix == RFIL) return("rfil");
	else if (ix == RPAR) return("rpar");

	return("");
};

string VecFmncVRepfsp::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == RFIL) return("file per row");
		else if (ix == RPAR) return("parameter per row");
	} else if (ixFmncVLocale == 2) {
		if (ix == RFIL) return("Datei pro Zeile");
		else if (ix == RPAR) return("Parameter pro Zeile");
	} else if (ixFmncVLocale == 3) {
		if (ix == RFIL) return("fichier par ligne");
		else if (ix == RPAR) return("param\\u00e8tre par ligne");
	};

	return("");
};

void VecFmncVRepfsp::appendToFeed(
			const uint ix
			, const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixFmncVLocale));
};

void VecFmncVRepfsp::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};


