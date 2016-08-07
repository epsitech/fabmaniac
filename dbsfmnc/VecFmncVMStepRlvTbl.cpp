/**
  * \file VecFmncVMStepRlvTbl.cpp
  * vector VecFmncVMStepRlvTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMStepRlvTbl.h"

/******************************************************************************
 namespace VecFmncVMStepRlvTbl
 ******************************************************************************/

uint VecFmncVMStepRlvTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "tty") return TTY;
	else if (s == "tol") return TOL;

	return(0);
};

string VecFmncVMStepRlvTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == TTY) return("tty");
	else if (ix == TOL) return("tol");

	return("");
};

string VecFmncVMStepRlvTbl::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == TTY) return("tool type");
		else if (ix == TOL) return("tool");
	} else if (ixFmncVLocale == 2) {
		if (ix == VOID) return("keine");
		else if (ix == TTY) return("Ger\\u00e4tetyp");
		else if (ix == TOL) return("Ger\\u00e4t");
	} else if (ixFmncVLocale == 3) {
		if (ix == VOID) return("aucune");
		else if (ix == TTY) return("type d'\\u00e9quipement");
		else if (ix == TOL) return("\\u00e9quipement");
	};

	return("");
};

void VecFmncVMStepRlvTbl::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

