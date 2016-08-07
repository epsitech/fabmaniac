/**
  * \file VecFmncVLop.cpp
  * vector VecFmncVLop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVLop.h"

/******************************************************************************
 namespace VecFmncVLop
 ******************************************************************************/

uint VecFmncVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	else if (s == "rmv") return RMV;

	return(0);
};

string VecFmncVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	else if (ix == RMV) return("rmv");

	return("");
};

