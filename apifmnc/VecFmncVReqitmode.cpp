/**
  * \file VecFmncVReqitmode.cpp
  * vector VecFmncVReqitmode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVReqitmode.h"

/******************************************************************************
 namespace VecFmncVReqitmode
 ******************************************************************************/

uint VecFmncVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("notify") == 0) return NOTIFY;
	else if (s.compare("poll") == 0) return POLL;

	return(0);
};

string VecFmncVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == NOTIFY) return("notify");
	else if (ix == POLL) return("poll");

	return("");
};

