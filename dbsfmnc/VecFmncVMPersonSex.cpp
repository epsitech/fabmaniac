/**
  * \file VecFmncVMPersonSex.cpp
  * vector VecFmncVMPersonSex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMPersonSex.h"

/******************************************************************************
 namespace VecFmncVMPersonSex
 ******************************************************************************/

uint VecFmncVMPersonSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	else if (s == "m") return M;

	return(0);
};

string VecFmncVMPersonSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	else if (ix == M) return("m");

	return("");
};

string VecFmncVMPersonSex::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == F) return("female");
		else if (ix == M) return("male");
	} else if (ixFmncVLocale == 2) {
		if (ix == F) return("weiblich");
		else if (ix == M) return("m\\u00e4nnlich");
	} else if (ixFmncVLocale == 3) {
		if (ix == F) return("f\\u00e9minin");
		else if (ix == M) return("masculin");
	};

	return("");
};

void VecFmncVMPersonSex::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

