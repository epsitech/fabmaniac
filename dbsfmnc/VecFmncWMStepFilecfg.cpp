/**
  * \file VecFmncWMStepFilecfg.cpp
  * vector VecFmncWMStepFilecfg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncWMStepFilecfg.h"

/******************************************************************************
 namespace VecFmncWMStepFilecfg
 ******************************************************************************/

uint VecFmncWMStepFilecfg::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "in") ix |= IN;
		else if (ss[i] == "out") ix |= OUT;
	};

	return(ix);
};

void VecFmncWMStepFilecfg::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*OUT);i*=2) if (ix & i) ics.insert(i);
};

string VecFmncWMStepFilecfg::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IN) ss.push_back("in");
	if (ix & OUT) ss.push_back("out");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecFmncWMStepFilecfg::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == IN) return("input");
		else if (ix == OUT) return("output");
	} else if (ixFmncVLocale == 2) {
		if (ix == IN) return("Input");
		else if (ix == OUT) return("Output");
	} else if (ixFmncVLocale == 3) {
		if (ix == IN) return("input");
		else if (ix == OUT) return("output");
	};

	return("");
};

void VecFmncWMStepFilecfg::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=OUT;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixFmncVLocale));
};

