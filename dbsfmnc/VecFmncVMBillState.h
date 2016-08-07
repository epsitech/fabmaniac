/**
  * \file VecFmncVMBillState.h
  * vector VecFmncVMBillState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMBILLSTATE_H
#define VECFMNCVMBILLSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMBillState
	*/
namespace VecFmncVMBillState {
	const uint OST = 1;
	const uint PAY = 2;
	const uint REM = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

