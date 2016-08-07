/**
  * \file VecFmncVQrystate.cpp
  * vector VecFmncVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVQrystate.h"

/******************************************************************************
 namespace VecFmncVQrystate
 ******************************************************************************/

uint VecFmncVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	else if (s == "ood") return OOD;
	else if (s == "slm") return SLM;
	else if (s == "utd") return UTD;

	return(0);
};

string VecFmncVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	else if (ix == OOD) return("ood");
	else if (ix == SLM) return("slm");
	else if (ix == UTD) return("utd");

	return("");
};

string VecFmncVQrystate::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		else if (ix == OOD) return("out of date");
		else if (ix == SLM) return("slightly modified");
		else if (ix == UTD) return("up to date");
	} else if (ixFmncVLocale == 2) {
		if (ix == MNR) return("eventuell veraltet");
		else if (ix == OOD) return("veraltet");
		else if (ix == SLM) return("geringf\\u00fcgig ver\\u00e4ndert");
		else if (ix == UTD) return("aktuell");
	} else if (ixFmncVLocale == 3) {
		if (ix == MNR) return("probablement obsol\\u00e8te");
		else if (ix == OOD) return("obsol\\u00e8te");
		else if (ix == SLM) return("modifi\\u00e9 marginalement");
		else if (ix == UTD) return("\\u00e0 jour");
	};

	return("");
};

void VecFmncVQrystate::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};


