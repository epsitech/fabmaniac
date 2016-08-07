/**
  * \file VecFmncWMPersonDerivate.cpp
  * vector VecFmncWMPersonDerivate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncWMPersonDerivate.h"

/******************************************************************************
 namespace VecFmncWMPersonDerivate
 ******************************************************************************/

uint VecFmncWMPersonDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "fus") ix |= FUS;
		else if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void VecFmncWMPersonDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*USR);i*=2) if (ix & i) ics.insert(i);
};

string VecFmncWMPersonDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FUS) ss.push_back("fus");
	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecFmncWMPersonDerivate::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == FUS) return("fab user");
		else if (ix == USR) return("user");
	} else if (ixFmncVLocale == 2) {
		if (ix == FUS) return("Reinraumnutzer");
		else if (ix == USR) return("Benutzer");
	} else if (ixFmncVLocale == 3) {
		if (ix == FUS) return("utilisateur salle blanche");
		else if (ix == USR) return("utilisateur");
	};

	return("");
};

void VecFmncWMPersonDerivate::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=USR;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixFmncVLocale));
};

