/**
  * \file VecFmncVLocale.h
  * vector VecFmncVLocale (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVLOCALE_H
#define VECFMNCVLOCALE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVLocale
	*/
namespace VecFmncVLocale {
	const uint ENUS = 1;
	const uint DECH = 2;
	const uint FRCH = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

