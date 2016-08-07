/**
  * \file VecFmncVExpstate.cpp
  * vector VecFmncVExpstate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVExpstate.h"

/******************************************************************************
 namespace VecFmncVExpstate
 ******************************************************************************/

uint VecFmncVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	else if (s == "maxd") return MAXD;
	else if (s == "mind") return MIND;
	else if (s == "regd") return REGD;

	return(0);
};

string VecFmncVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	else if (ix == MAXD) return("maxd");
	else if (ix == MIND) return("mind");
	else if (ix == REGD) return("regd");

	return("");
};


