/**
  * \file VecFmncVMFabuserState.cpp
  * vector VecFmncVMFabuserState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMFabuserState.h"

/******************************************************************************
 namespace VecFmncVMFabuserState
 ******************************************************************************/

uint VecFmncVMFabuserState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	else if (s == "dsg") return DSG;
	else if (s == "due") return DUE;
	else if (s == "exp") return EXP;

	return(0);
};

string VecFmncVMFabuserState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	else if (ix == DSG) return("dsg");
	else if (ix == DUE) return("due");
	else if (ix == EXP) return("exp");

	return("");
};

string VecFmncVMFabuserState::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == ACT) return("active");
		else if (ix == DSG) return("designated");
		else if (ix == DUE) return("due for expiration");
		else if (ix == EXP) return("expired");
	} else if (ixFmncVLocale == 2) {
		if (ix == ACT) return("aktiv");
		else if (ix == DSG) return("vorgesehen");
		else if (ix == DUE) return("l\\u00e4uft ab");
		else if (ix == EXP) return("abgelaufen");
	} else if (ixFmncVLocale == 3) {
		if (ix == ACT) return("active");
		else if (ix == DSG) return("pr\\u00e9vu");
		else if (ix == DUE) return("se termine");
		else if (ix == EXP) return("termin\\u00e9");
	};

	return("");
};

void VecFmncVMFabuserState::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

