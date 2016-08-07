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

	if (s == "idle") return IDLE;
	else if (s == "notify") return NOTIFY;
	else if (s == "poll") return POLL;

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


