/**
  * \file VecFmncVRMFileMStepDir.cpp
  * vector VecFmncVRMFileMStepDir (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVRMFileMStepDir.h"

/******************************************************************************
 namespace VecFmncVRMFileMStepDir
 ******************************************************************************/

uint VecFmncVRMFileMStepDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "in") return IN;
	else if (s == "out") return OUT;

	return(0);
};

string VecFmncVRMFileMStepDir::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == IN) return("in");
	else if (ix == OUT) return("out");

	return("");
};

string VecFmncVRMFileMStepDir::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == IN) return("input");
		else if (ix == OUT) return("output");
	} else if (ixFmncVLocale == 2) {
		if (ix == VOID) return("keine");
		else if (ix == IN) return("Input");
		else if (ix == OUT) return("Output");
	} else if (ixFmncVLocale == 3) {
		if (ix == VOID) return("aucune");
		else if (ix == IN) return("input");
		else if (ix == OUT) return("output");
	};

	return("");
};

void VecFmncVRMFileMStepDir::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

