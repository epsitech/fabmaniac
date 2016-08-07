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

	if (s.compare("detd") == 0) return DETD;
	else if (s.compare("maxd") == 0) return MAXD;
	else if (s.compare("mind") == 0) return MIND;
	else if (s.compare("regd") == 0) return REGD;

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

