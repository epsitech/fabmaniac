/**
  * \file VecFmncVIop.h
  * vector VecFmncVIop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVIOP_H
#define VECFMNCVIOP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVIop
	*/
namespace VecFmncVIop {
	const uint INS = 1;
	const uint RETR = 2;
	const uint RETRINS = 3;
	const uint RETRUPD = 4;
	const uint RMV = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif


