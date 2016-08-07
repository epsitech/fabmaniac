/**
  * \file VecFmncVKeylist.h
  * vector VecFmncVKeylist (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVKEYLIST_H
#define VECFMNCVKEYLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVKeylist
	*/
namespace VecFmncVKeylist {
	const uint KLSTFMNCKSTEPPAR = 1;
	const uint KLSTFMNCKSTOCKLCN = 2;
	const uint KLSTFMNCKTOOLCHAR = 3;
	const uint KLSTFMNCKAMORGDETAILTYPE = 4;
	const uint KLSTFMNCKAMPERSONDETAILTYPE = 5;
	const uint KLSTFMNCKAMSAMPLEPARKEY = 6;
	const uint KLSTFMNCKAMSAMPLEPARVAL = 7;
	const uint KLSTFMNCKAMTOOLAVLAVLTYPE = 8;
	const uint KLSTFMNCKAMTOOLRESRESTYPE = 9;
	const uint KLSTFMNCKMADDRESSCOUNTRY = 10;
	const uint KLSTFMNCKMARTICLETYPE = 11;
	const uint KLSTFMNCKMFILECONTENT = 12;
	const uint KLSTFMNCKMFILEMIMETYPE = 13;
	const uint KLSTFMNCKRMFABUSERMTOOLLVL = 14;
	const uint KLSTFMNCKRMORGMPERSONFUNCTION = 15;
	const uint KLSTKMADDRESSADRTYPE = 16;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);
};

#endif

