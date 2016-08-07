/**
  * \file VecFmncVMPurchorderState.cpp
  * vector VecFmncVMPurchorderState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMPurchorderState.h"

/******************************************************************************
 namespace VecFmncVMPurchorderState
 ******************************************************************************/

uint VecFmncVMPurchorderState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "prep") return PREP;
	else if (s == "sbm") return SBM;
	else if (s == "due") return DUE;
	else if (s == "rcv") return RCV;
	else if (s == "pay") return PAY;

	return(0);
};

string VecFmncVMPurchorderState::getSref(
			const uint ix
		) {
	if (ix == PREP) return("prep");
	else if (ix == SBM) return("sbm");
	else if (ix == DUE) return("due");
	else if (ix == RCV) return("rcv");
	else if (ix == PAY) return("pay");

	return("");
};

string VecFmncVMPurchorderState::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == PREP) return("in preparation");
		else if (ix == SBM) return("sumitted");
		else if (ix == DUE) return("delivery due");
		else if (ix == RCV) return("received");
		else if (ix == PAY) return("paid");
	} else if (ixFmncVLocale == 2) {
		if (ix == PREP) return("in Vorbereitung");
		else if (ix == SBM) return("abgeschickt");
		else if (ix == DUE) return("Lieferung f\\u00e4llig");
		else if (ix == RCV) return("empfangen");
		else if (ix == PAY) return("bezahlt");
	} else if (ixFmncVLocale == 3) {
		if (ix == PREP) return("en pr\\u00e9paration");
		else if (ix == SBM) return("envoy\\u00e9e");
		else if (ix == DUE) return("livraison due");
		else if (ix == RCV) return("re\\u00e7ue");
		else if (ix == PAY) return("pay\\u00e9e");
	};

	return("");
};

void VecFmncVMPurchorderState::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

