/**
  * \file VecFmncVExpstate.h
  * vector VecFmncVExpstate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVEXPSTATE_H
#define VECFMNCVEXPSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVExpstate
	*/
namespace VecFmncVExpstate {
	const uint DETD = 1;
	const uint MAXD = 2;
	const uint MIND = 3;
	const uint REGD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


