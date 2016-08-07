/**
  * \file VecFmncVMPersonSex.h
  * vector VecFmncVMPersonSex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMPERSONSEX_H
#define VECFMNCVMPERSONSEX_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMPersonSex
	*/
namespace VecFmncVMPersonSex {
	const uint F = 1;
	const uint M = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

