/**
  * \file VecFmncVMSampleState.cpp
  * vector VecFmncVMSampleState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMSampleState.h"

/******************************************************************************
 namespace VecFmncVMSampleState
 ******************************************************************************/

uint VecFmncVMSampleState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stk") return STK;
	else if (s == "act") return ACT;
	else if (s == "cpl") return CPL;
	else if (s == "disp") return DISP;
	else if (s == "lost") return LOST;

	return(0);
};

string VecFmncVMSampleState::getSref(
			const uint ix
		) {
	if (ix == STK) return("stk");
	else if (ix == ACT) return("act");
	else if (ix == CPL) return("cpl");
	else if (ix == DISP) return("disp");
	else if (ix == LOST) return("lost");

	return("");
};

string VecFmncVMSampleState::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == STK) return("in stock");
		else if (ix == ACT) return("active");
		else if (ix == CPL) return("processing completed");
		else if (ix == DISP) return("disposed of");
		else if (ix == LOST) return("lost");
	} else if (ixFmncVLocale == 2) {
		if (ix == STK) return("auf Lager");
		else if (ix == ACT) return("aktiv");
		else if (ix == CPL) return("Prozessierung abgeschlossen");
		else if (ix == DISP) return("entsorgt");
		else if (ix == LOST) return("verloren");
	} else if (ixFmncVLocale == 3) {
		if (ix == STK) return("en r\\u00e9serve");
		else if (ix == ACT) return("active");
		else if (ix == CPL) return("fa\\u00e7onnage finie");
		else if (ix == DISP) return("elimin\\u00e9");
		else if (ix == LOST) return("perdu");
	};

	return("");
};

void VecFmncVMSampleState::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

