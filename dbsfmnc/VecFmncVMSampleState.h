/**
  * \file VecFmncVMSampleState.h
  * vector VecFmncVMSampleState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMSAMPLESTATE_H
#define VECFMNCVMSAMPLESTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMSampleState
	*/
namespace VecFmncVMSampleState {
	const uint STK = 1;
	const uint ACT = 2;
	const uint CPL = 3;
	const uint DISP = 4;
	const uint LOST = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

