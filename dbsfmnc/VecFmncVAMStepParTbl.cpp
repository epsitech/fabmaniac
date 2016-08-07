/**
  * \file VecFmncVAMStepParTbl.cpp
  * vector VecFmncVAMStepParTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVAMStepParTbl.h"

/******************************************************************************
 namespace VecFmncVAMStepParTbl
 ******************************************************************************/

uint VecFmncVAMStepParTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "fil") return FIL;
	else if (s == "smp") return SMP;

	return(0);
};

string VecFmncVAMStepParTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == FIL) return("fil");
	else if (ix == SMP) return("smp");

	return("");
};

string VecFmncVAMStepParTbl::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == FIL) return("file");
		else if (ix == SMP) return("sample");
	} else if (ixFmncVLocale == 2) {
		if (ix == VOID) return("keine");
		else if (ix == FIL) return("Datei");
		else if (ix == SMP) return("Sample");
	} else if (ixFmncVLocale == 3) {
		if (ix == VOID) return("aucun");
		else if (ix == FIL) return("fichier");
		else if (ix == SMP) return("\\u00e9chantillon");
	};

	return("");
};

void VecFmncVAMStepParTbl::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

