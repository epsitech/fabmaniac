/**
  * \file VecFmncVAMToolAvlWkday.h
  * vector VecFmncVAMToolAvlWkday (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVAMTOOLAVLWKDAY_H
#define VECFMNCVAMTOOLAVLWKDAY_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVAMToolAvlWkday
	*/
namespace VecFmncVAMToolAvlWkday {
	const uint FRI = 1;
	const uint MON = 2;
	const uint SAT = 3;
	const uint SUN = 4;
	const uint THU = 5;
	const uint TUE = 6;
	const uint WED = 7;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

