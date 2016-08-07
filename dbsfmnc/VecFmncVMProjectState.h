/**
  * \file VecFmncVMProjectState.h
  * vector VecFmncVMProjectState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMPROJECTSTATE_H
#define VECFMNCVMPROJECTSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMProjectState
	*/
namespace VecFmncVMProjectState {
	const uint PLAN = 1;
	const uint ACT = 2;
	const uint CPL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

