/**
  * \file VecFmncWMOrgDerivate.cpp
  * vector VecFmncWMOrgDerivate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncWMOrgDerivate.h"

/******************************************************************************
 namespace VecFmncWMOrgDerivate
 ******************************************************************************/

uint VecFmncWMOrgDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "fab") ix |= FAB;
	};

	return(ix);
};

void VecFmncWMOrgDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*FAB);i*=2) if (ix & i) ics.insert(i);
};

string VecFmncWMOrgDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FAB) ss.push_back("fab");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecFmncWMOrgDerivate::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == FAB) return("fab");
	} else if (ixFmncVLocale == 2) {
		if (ix == FAB) return("Reinraum");
	} else if (ixFmncVLocale == 3) {
		if (ix == FAB) return("salle blanche");
	};

	return("");
};

void VecFmncWMOrgDerivate::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=FAB;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixFmncVLocale));
};

