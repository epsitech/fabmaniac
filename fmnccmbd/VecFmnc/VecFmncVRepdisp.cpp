/**
  * \file VecFmncVRepdisp.cpp
  * vector VecFmncVRepdisp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVRepdisp.h"

/******************************************************************************
 namespace VecFmncVRepdisp
 ******************************************************************************/

uint VecFmncVRepdisp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "off") return OFF;
	else if (s == "txt") return TXT;
	else if (s == "tbl") return TBL;

	return(0);
};

string VecFmncVRepdisp::getSref(
			const uint ix
		) {
	if (ix == OFF) return("off");
	else if (ix == TXT) return("txt");
	else if (ix == TBL) return("tbl");

	return("");
};

string VecFmncVRepdisp::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == OFF) return("off");
		else if (ix == TXT) return("textual");
		else if (ix == TBL) return("tabular");
	} else if (ixFmncVLocale == 2) {
		if (ix == OFF) return("aus");
		else if (ix == TXT) return("textuell");
		else if (ix == TBL) return("tabellarisch");
	} else if (ixFmncVLocale == 3) {
		if (ix == OFF) return("d\\u00e9sactiv\\u00e9");
		else if (ix == TXT) return("textuel");
		else if (ix == TBL) return("tabulaire");
	};

	return("");
};

void VecFmncVRepdisp::appendToFeed(
			const uint ix
			, const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixFmncVLocale));
};

void VecFmncVRepdisp::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};


