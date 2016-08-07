/**
  * \file VecFmncVRepfsp.h
  * vector VecFmncVRepfsp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVREPFSP_H
#define VECFMNCVREPFSP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVRepfsp
	*/
namespace VecFmncVRepfsp {
	const uint RFIL = 1;
	const uint RPAR = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void appendToFeed(const uint ix, const uint ixFmncVLocale, Feed& feed);
	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif


