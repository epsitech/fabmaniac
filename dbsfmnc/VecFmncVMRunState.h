/**
  * \file VecFmncVMRunState.h
  * vector VecFmncVMRunState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMRUNSTATE_H
#define VECFMNCVMRUNSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMRunState
	*/
namespace VecFmncVMRunState {
	const uint PLAN = 1;
	const uint ACT = 2;
	const uint CPL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

