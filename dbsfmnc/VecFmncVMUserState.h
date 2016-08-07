/**
  * \file VecFmncVMUserState.h
  * vector VecFmncVMUserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMUSERSTATE_H
#define VECFMNCVMUSERSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMUserState
	*/
namespace VecFmncVMUserState {
	const uint ACT = 1;
	const uint DSG = 2;
	const uint DUE = 3;
	const uint EXP = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

