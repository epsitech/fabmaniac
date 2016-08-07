/**
  * \file VecFmncWUiaccess.cpp
  * vector VecFmncWUiaccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncWUiaccess.h"

/******************************************************************************
 namespace VecFmncWUiaccess
 ******************************************************************************/

uint VecFmncWUiaccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void VecFmncWUiaccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VIEW);i*=2) if (ix & i) ics.insert(i);
};

string VecFmncWUiaccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecFmncWUiaccess::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == EDIT) return("edit");
		else if (ix == EXEC) return("execute");
		else if (ix == VIEW) return("view");
	} else if (ixFmncVLocale == 2) {
		if (ix == EDIT) return("\\u00e4ndern");
		else if (ix == EXEC) return("ausf\\u00fchren");
		else if (ix == VIEW) return("anschauen");
	} else if (ixFmncVLocale == 3) {
		if (ix == EDIT) return("modifier");
		else if (ix == EXEC) return("ex\\u00e9cuter");
		else if (ix == VIEW) return("afficher");
	};

	return("");
};

void VecFmncWUiaccess::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=VIEW;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixFmncVLocale));
};

