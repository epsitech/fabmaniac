/**
  * \file VecFmncVAMToolAvlWkday.cpp
  * vector VecFmncVAMToolAvlWkday (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVAMToolAvlWkday.h"

/******************************************************************************
 namespace VecFmncVAMToolAvlWkday
 ******************************************************************************/

uint VecFmncVAMToolAvlWkday::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fri") return FRI;
	else if (s == "mon") return MON;
	else if (s == "sat") return SAT;
	else if (s == "sun") return SUN;
	else if (s == "thu") return THU;
	else if (s == "tue") return TUE;
	else if (s == "wed") return WED;

	return(0);
};

string VecFmncVAMToolAvlWkday::getSref(
			const uint ix
		) {
	if (ix == FRI) return("fri");
	else if (ix == MON) return("mon");
	else if (ix == SAT) return("sat");
	else if (ix == SUN) return("sun");
	else if (ix == THU) return("thu");
	else if (ix == TUE) return("tue");
	else if (ix == WED) return("wed");

	return("");
};

string VecFmncVAMToolAvlWkday::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == FRI) return("Friday");
		else if (ix == MON) return("Monday");
		else if (ix == SAT) return("Saturday");
		else if (ix == SUN) return("Sunday");
		else if (ix == THU) return("Thursday");
		else if (ix == TUE) return("Tuesday");
		else if (ix == WED) return("Wednesday");
	} else if (ixFmncVLocale == 2) {
		if (ix == FRI) return("Freitag");
		else if (ix == MON) return("Montag");
		else if (ix == SAT) return("Samstag");
		else if (ix == SUN) return("Sonntag");
		else if (ix == THU) return("Donnerstag");
		else if (ix == TUE) return("Dienstag");
		else if (ix == WED) return("Mittwoch");
	} else if (ixFmncVLocale == 3) {
		if (ix == FRI) return("vendredi");
		else if (ix == MON) return("lundi");
		else if (ix == SAT) return("samedi");
		else if (ix == SUN) return("dimanche");
		else if (ix == THU) return("jeudi");
		else if (ix == TUE) return("mardi");
		else if (ix == WED) return("mercredi");
	};

	return("");
};

void VecFmncVAMToolAvlWkday::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=7;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

