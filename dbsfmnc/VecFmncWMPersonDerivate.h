/**
  * \file VecFmncWMPersonDerivate.h
  * vector VecFmncWMPersonDerivate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCWMPERSONDERIVATE_H
#define VECFMNCWMPERSONDERIVATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncWMPersonDerivate
	*/
namespace VecFmncWMPersonDerivate {
	const uint FUS = 1;
	const uint USR = 2;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

