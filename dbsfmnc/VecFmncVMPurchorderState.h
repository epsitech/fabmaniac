/**
  * \file VecFmncVMPurchorderState.h
  * vector VecFmncVMPurchorderState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMPURCHORDERSTATE_H
#define VECFMNCVMPURCHORDERSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMPurchorderState
	*/
namespace VecFmncVMPurchorderState {
	const uint PREP = 1;
	const uint SBM = 2;
	const uint DUE = 3;
	const uint RCV = 4;
	const uint PAY = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

