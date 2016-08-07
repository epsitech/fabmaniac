/**
  * \file VecFmncVQrystate.cpp
  * vector VecFmncVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVQrystate.h"

/******************************************************************************
 namespace VecFmncVQrystate
 ******************************************************************************/

uint VecFmncVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("mnr") == 0) return MNR;
	else if (s.compare("ood") == 0) return OOD;
	else if (s.compare("slm") == 0) return SLM;
	else if (s.compare("utd") == 0) return UTD;

	return(0);
};

string VecFmncVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	else if (ix == OOD) return("ood");
	else if (ix == SLM) return("slm");
	else if (ix == UTD) return("utd");

	return("");
};

