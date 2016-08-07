/**
  * \file VecFmncVMAddressHkTbl.cpp
  * vector VecFmncVMAddressHkTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMAddressHkTbl.h"

/******************************************************************************
 namespace VecFmncVMAddressHkTbl
 ******************************************************************************/

uint VecFmncVMAddressHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "org") return ORG;
	else if (s == "prs") return PRS;

	return(0);
};

string VecFmncVMAddressHkTbl::getSref(
			const uint ix
		) {
	if (ix == ORG) return("org");
	else if (ix == PRS) return("prs");

	return("");
};

string VecFmncVMAddressHkTbl::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == ORG) return("organization");
		else if (ix == PRS) return("person");
	} else if (ixFmncVLocale == 2) {
		if (ix == ORG) return("Organisation");
		else if (ix == PRS) return("Person");
	} else if (ixFmncVLocale == 3) {
		if (ix == ORG) return("organisme");
		else if (ix == PRS) return("individu");
	};

	return("");
};

void VecFmncVMAddressHkTbl::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

