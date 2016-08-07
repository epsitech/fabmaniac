/**
  * \file VecFmncVMBillState.cpp
  * vector VecFmncVMBillState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVMBillState.h"

/******************************************************************************
 namespace VecFmncVMBillState
 ******************************************************************************/

uint VecFmncVMBillState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ost") return OST;
	else if (s == "pay") return PAY;
	else if (s == "rem") return REM;

	return(0);
};

string VecFmncVMBillState::getSref(
			const uint ix
		) {
	if (ix == OST) return("ost");
	else if (ix == PAY) return("pay");
	else if (ix == REM) return("rem");

	return("");
};

string VecFmncVMBillState::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == OST) return("outstanding");
		else if (ix == PAY) return("paid");
		else if (ix == REM) return("reminder");
	} else if (ixFmncVLocale == 2) {
		if (ix == OST) return("ausstehend");
		else if (ix == PAY) return("bezahlt");
		else if (ix == REM) return("Erinnerung");
	} else if (ixFmncVLocale == 3) {
		if (ix == OST) return("non encore pay\\u00e9e");
		else if (ix == PAY) return("pay\\u00e9e");
		else if (ix == REM) return("rappel");
	};

	return("");
};

void VecFmncVMBillState::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

