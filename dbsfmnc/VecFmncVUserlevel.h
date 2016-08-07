/**
  * \file VecFmncVUserlevel.h
  * vector VecFmncVUserlevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVUSERLEVEL_H
#define VECFMNCVUSERLEVEL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVUserlevel
	*/
namespace VecFmncVUserlevel {
	const uint ADM = 1;
	const uint GADM = 2;
	const uint REG = 3;
	const uint VTOR = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

