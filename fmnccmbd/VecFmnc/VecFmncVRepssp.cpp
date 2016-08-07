/**
  * \file VecFmncVRepssp.cpp
  * vector VecFmncVRepssp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVRepssp.h"

/******************************************************************************
 namespace VecFmncVRepssp
 ******************************************************************************/

uint VecFmncVRepssp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "rsmp") return RSMP;
	else if (s == "rpar") return RPAR;

	return(0);
};

string VecFmncVRepssp::getSref(
			const uint ix
		) {
	if (ix == RSMP) return("rsmp");
	else if (ix == RPAR) return("rpar");

	return("");
};

string VecFmncVRepssp::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == RSMP) return("sample per row");
		else if (ix == RPAR) return("parameter per row");
	} else if (ixFmncVLocale == 2) {
		if (ix == RSMP) return("Sample pro Zeile");
		else if (ix == RPAR) return("Parameter pro Zeile");
	} else if (ixFmncVLocale == 3) {
		if (ix == RSMP) return("\\u00e9chantillon par ligne");
		else if (ix == RPAR) return("param\\u00e8tre par ligne");
	};

	return("");
};

void VecFmncVRepssp::appendToFeed(
			const uint ix
			, const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixFmncVLocale));
};

void VecFmncVRepssp::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};


