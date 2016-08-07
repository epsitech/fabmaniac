/**
  * \file VecFmncVMFileRefTbl.h
  * vector VecFmncVMFileRefTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMFILEREFTBL_H
#define VECFMNCVMFILEREFTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMFileRefTbl
	*/
namespace VecFmncVMFileRefTbl {
	const uint VOID = 1;
	const uint ART = 2;
	const uint BIL = 3;
	const uint PCO = 4;
	const uint RUN = 5;
	const uint SMP = 6;
	const uint STE = 7;
	const uint TOL = 8;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

