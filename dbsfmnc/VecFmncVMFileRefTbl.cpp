/**
  * \file VecFmncVMFileRefTbl.cpp
  * vector VecFmncVMFileRefTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMFileRefTbl.h"

/******************************************************************************
 namespace VecFmncVMFileRefTbl
 ******************************************************************************/

uint VecFmncVMFileRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "art") return ART;
	else if (s == "bil") return BIL;
	else if (s == "pco") return PCO;
	else if (s == "run") return RUN;
	else if (s == "smp") return SMP;
	else if (s == "ste") return STE;
	else if (s == "tol") return TOL;

	return(0);
};

string VecFmncVMFileRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == ART) return("art");
	else if (ix == BIL) return("bil");
	else if (ix == PCO) return("pco");
	else if (ix == RUN) return("run");
	else if (ix == SMP) return("smp");
	else if (ix == STE) return("ste");
	else if (ix == TOL) return("tol");

	return("");
};

string VecFmncVMFileRefTbl::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == ART) return("article");
		else if (ix == BIL) return("bill");
		else if (ix == PCO) return("purchase order");
		else if (ix == RUN) return("run");
		else if (ix == SMP) return("sample");
		else if (ix == STE) return("step");
		else if (ix == TOL) return("tool");
	} else if (ixFmncVLocale == 2) {
		if (ix == VOID) return("keine");
		else if (ix == ART) return("Artikel");
		else if (ix == BIL) return("Rechnung");
		else if (ix == PCO) return("Bestellung");
		else if (ix == RUN) return("Lauf");
		else if (ix == SMP) return("Sample");
		else if (ix == STE) return("Schritt");
		else if (ix == TOL) return("Ger\\u00e4t");
	} else if (ixFmncVLocale == 3) {
		if (ix == VOID) return("aucun");
		else if (ix == ART) return("article");
		else if (ix == BIL) return("facture");
		else if (ix == PCO) return("commande");
		else if (ix == RUN) return("d\\u00e9roulement");
		else if (ix == SMP) return("\\u00e9chantillon");
		else if (ix == STE) return("\\u00e9tape");
		else if (ix == TOL) return("\\u00e9quipement");
	};

	return("");
};

void VecFmncVMFileRefTbl::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=8;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

