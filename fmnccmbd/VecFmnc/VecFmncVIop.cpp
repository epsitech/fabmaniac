/**
  * \file VecFmncVIop.cpp
  * vector VecFmncVIop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVIop.h"

/******************************************************************************
 namespace VecFmncVIop
 ******************************************************************************/

uint VecFmncVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	else if (s == "retr") return RETR;
	else if (s == "retrins") return RETRINS;
	else if (s == "retrupd") return RETRUPD;
	else if (s == "rmv") return RMV;

	return(0);
};

string VecFmncVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	else if (ix == RETR) return("retr");
	else if (ix == RETRINS) return("retrins");
	else if (ix == RETRUPD) return("retrupd");
	else if (ix == RMV) return("rmv");

	return("");
};

string VecFmncVIop::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == INS) return("insert");
		else if (ix == RETR) return("retrieve");
		else if (ix == RETRINS) return("retrieve, else insert");
		else if (ix == RETRUPD) return("retrieve and update");
		else if (ix == RMV) return("remove");
	} else if (ixFmncVLocale == 2) {
		if (ix == INS) return("einf\\u00fcgen");
		else if (ix == RETR) return("auffinden");
		else if (ix == RETRINS) return("auffinden, sonst einf\\u00fcgen");
		else if (ix == RETRUPD) return("auffinden und aktualisieren");
		else if (ix == RMV) return("entfernen");
	} else if (ixFmncVLocale == 3) {
		if (ix == INS) return("ins\\u00e9rer");
		else if (ix == RETR) return("rep\\u00e9rer");
		else if (ix == RETRINS) return("rep\\u00e9rer, sinon ins\\u00e9rer");
		else if (ix == RETRUPD) return("rep\\u00e9rer et mettre \\u00e0 jour");
		else if (ix == RMV) return("enlever");
	};

	return("");
};

void VecFmncVIop::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};


