/**
  * \file VecFmncVCard.h
  * vector VecFmncVCard (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVCARD_H
#define VECFMNCVCARD_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVCard
	*/
namespace VecFmncVCard {
	const uint CRDFMNCNAV = 1;
	const uint CRDFMNCUSG = 2;
	const uint CRDFMNCUSR = 3;
	const uint CRDFMNCORG = 4;
	const uint CRDFMNCPRS = 5;
	const uint CRDFMNCADR = 6;
	const uint CRDFMNCFIL = 7;
	const uint CRDFMNCSTP = 8;
	const uint CRDFMNCPRJ = 9;
	const uint CRDFMNCRUN = 10;
	const uint CRDFMNCACT = 11;
	const uint CRDFMNCSEP = 12;
	const uint CRDFMNCSMP = 13;
	const uint CRDFMNCFAB = 14;
	const uint CRDFMNCFUS = 15;
	const uint CRDFMNCTTY = 16;
	const uint CRDFMNCTOL = 17;
	const uint CRDFMNCFPJ = 18;
	const uint CRDFMNCBIL = 19;
	const uint CRDFMNCART = 20;
	const uint CRDFMNCSKI = 21;
	const uint CRDFMNCPCO = 22;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

