/**
  * \file VecFmncVAccess.h
  * vector VecFmncVAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVACCESS_H
#define VECFMNCVACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVAccess
	*/
namespace VecFmncVAccess {
	const uint FULL = 1;
	const uint NONE = 2;
	const uint VIEW = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

