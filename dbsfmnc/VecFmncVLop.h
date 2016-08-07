/**
  * \file VecFmncVLop.h
  * vector VecFmncVLop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVLOP_H
#define VECFMNCVLOP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVLop
	*/
namespace VecFmncVLop {
	const uint INS = 1;
	const uint RMV = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

