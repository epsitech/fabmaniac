/**
  * \file VecFmncVMRunState.cpp
  * vector VecFmncVMRunState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMRunState.h"

/******************************************************************************
 namespace VecFmncVMRunState
 ******************************************************************************/

uint VecFmncVMRunState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "plan") return PLAN;
	else if (s == "act") return ACT;
	else if (s == "cpl") return CPL;

	return(0);
};

string VecFmncVMRunState::getSref(
			const uint ix
		) {
	if (ix == PLAN) return("plan");
	else if (ix == ACT) return("act");
	else if (ix == CPL) return("cpl");

	return("");
};

string VecFmncVMRunState::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == PLAN) return("planned");
		else if (ix == ACT) return("active");
		else if (ix == CPL) return("completed");
	} else if (ixFmncVLocale == 2) {
		if (ix == PLAN) return("geplant");
		else if (ix == ACT) return("aktiv");
		else if (ix == CPL) return("abgeschlossen");
	} else if (ixFmncVLocale == 3) {
		if (ix == PLAN) return("pr\\u00e9vu");
		else if (ix == ACT) return("active");
		else if (ix == CPL) return("fini");
	};

	return("");
};

void VecFmncVMRunState::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

