/**
  * \file VecFmncWMStepFilecfg.h
  * vector VecFmncWMStepFilecfg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCWMSTEPFILECFG_H
#define VECFMNCWMSTEPFILECFG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncWMStepFilecfg
	*/
namespace VecFmncWMStepFilecfg {
	const uint IN = 1;
	const uint OUT = 2;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

