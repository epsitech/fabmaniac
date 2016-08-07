/**
  * \file VecFmncVMStepRlvTbl.h
  * vector VecFmncVMStepRlvTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMSTEPRLVTBL_H
#define VECFMNCVMSTEPRLVTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMStepRlvTbl
	*/
namespace VecFmncVMStepRlvTbl {
	const uint VOID = 1;
	const uint TTY = 2;
	const uint TOL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

