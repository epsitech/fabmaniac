/**
  * \file VecFmncVOolop.h
  * vector VecFmncVOolop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVOOLOP_H
#define VECFMNCVOOLOP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVOolop
	*/
namespace VecFmncVOolop {
	const uint INA = 1;
	const uint INB = 2;
	const uint RMV = 3;
	const uint SWP = 4;
	const uint TOA = 5;
	const uint TOB = 6;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

