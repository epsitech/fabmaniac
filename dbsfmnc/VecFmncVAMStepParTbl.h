/**
  * \file VecFmncVAMStepParTbl.h
  * vector VecFmncVAMStepParTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVAMSTEPPARTBL_H
#define VECFMNCVAMSTEPPARTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVAMStepParTbl
	*/
namespace VecFmncVAMStepParTbl {
	const uint VOID = 1;
	const uint FIL = 2;
	const uint SMP = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

