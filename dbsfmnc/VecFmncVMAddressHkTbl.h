/**
  * \file VecFmncVMAddressHkTbl.h
  * vector VecFmncVMAddressHkTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMADDRESSHKTBL_H
#define VECFMNCVMADDRESSHKTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMAddressHkTbl
	*/
namespace VecFmncVMAddressHkTbl {
	const uint ORG = 1;
	const uint PRS = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

