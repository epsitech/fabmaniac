/**
  * \file VecFmncVValuelist.cpp
  * vector VecFmncVValuelist (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVValuelist.h"

/******************************************************************************
 namespace VecFmncVValuelist
 ******************************************************************************/

uint VecFmncVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstfmncumpersontitle") return VLSTFMNCUMPERSONTITLE;
	else if (s == "vlstfmncumsamplematerial") return VLSTFMNCUMSAMPLEMATERIAL;
	else if (s == "vlstfmncumtooltraining") return VLSTFMNCUMTOOLTRAINING;

	return(0);
};

string VecFmncVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTFMNCUMPERSONTITLE) return("VlstFmncUMPersonTitle");
	else if (ix == VLSTFMNCUMSAMPLEMATERIAL) return("VlstFmncUMSampleMaterial");
	else if (ix == VLSTFMNCUMTOOLTRAINING) return("VlstFmncUMToolTraining");

	return("");
};

string VecFmncVValuelist::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == VLSTFMNCUMPERSONTITLE) return("title");
		else if (ix == VLSTFMNCUMSAMPLEMATERIAL) return("material");
		else if (ix == VLSTFMNCUMTOOLTRAINING) return("training");
	} else if (ixFmncVLocale == 2) {
		if (ix == VLSTFMNCUMPERSONTITLE) return("Anrede");
		else if (ix == VLSTFMNCUMSAMPLEMATERIAL) return("Material");
		else if (ix == VLSTFMNCUMTOOLTRAINING) return("Schulung");
	} else if (ixFmncVLocale == 3) {
		if (ix == VLSTFMNCUMPERSONTITLE) return("appel");
		else if (ix == VLSTFMNCUMSAMPLEMATERIAL) return("mat\\u00e9riau");
		else if (ix == VLSTFMNCUMTOOLTRAINING) return("formation");
	};

	return("");
};

