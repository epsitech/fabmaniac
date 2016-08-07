/**
  * \file VecFmncVLat.h
  * vector VecFmncVLat (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVLAT_H
#define VECFMNCVLAT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVLat
	*/
namespace VecFmncVLat {
	const uint DLO = 1;
	const uint INI = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

