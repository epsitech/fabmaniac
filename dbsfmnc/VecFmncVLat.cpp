/**
  * \file VecFmncVLat.cpp
  * vector VecFmncVLat (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVLat.h"

/******************************************************************************
 namespace VecFmncVLat
 ******************************************************************************/

uint VecFmncVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	else if (s == "ini") return INI;

	return(0);
};

string VecFmncVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	else if (ix == INI) return("ini");

	return("");
};

