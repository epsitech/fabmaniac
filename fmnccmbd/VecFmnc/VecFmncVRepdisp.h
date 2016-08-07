/**
  * \file VecFmncVRepdisp.h
  * vector VecFmncVRepdisp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVREPDISP_H
#define VECFMNCVREPDISP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVRepdisp
	*/
namespace VecFmncVRepdisp {
	const uint OFF = 1;
	const uint TXT = 2;
	const uint TBL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void appendToFeed(const uint ix, const uint ixFmncVLocale, Feed& feed);
	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif


