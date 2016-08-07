/**
  * \file VecFmncWMOrgDerivate.h
  * vector VecFmncWMOrgDerivate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCWMORGDERIVATE_H
#define VECFMNCWMORGDERIVATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncWMOrgDerivate
	*/
namespace VecFmncWMOrgDerivate {
	const uint FAB = 1;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

