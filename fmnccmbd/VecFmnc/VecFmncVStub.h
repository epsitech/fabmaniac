/**
  * \file VecFmncVStub.h
  * vector VecFmncVStub (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVSTUB_H
#define VECFMNCVSTUB_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVStub
	*/
namespace VecFmncVStub {
	const uint STUBFMNCACTSTD = 1;
	const uint STUBFMNCADRSTD = 2;
	const uint STUBFMNCARTSTD = 3;
	const uint STUBFMNCBILSTD = 4;
	const uint STUBFMNCFABSREF = 5;
	const uint STUBFMNCFABSTD = 6;
	const uint STUBFMNCFPJSTD = 7;
	const uint STUBFMNCFUSSTD = 8;
	const uint STUBFMNCFILSTD = 9;
	const uint STUBFMNCORGHSREF = 10;
	const uint STUBFMNCORGSREF = 11;
	const uint STUBFMNCORGSTD = 12;
	const uint STUBFMNCPRSSTD = 13;
	const uint STUBFMNCPRSWORG = 14;
	const uint STUBFMNCPRJSTD = 15;
	const uint STUBFMNCPCOSTD = 16;
	const uint STUBFMNCRUNSTD = 17;
	const uint STUBFMNCSMPHSREF = 18;
	const uint STUBFMNCSMPSTD = 19;
	const uint STUBFMNCSEPSTD = 20;
	const uint STUBFMNCSTESTD = 21;
	const uint STUBFMNCSKISTD = 22;
	const uint STUBFMNCTOLSTD = 23;
	const uint STUBFMNCTTYSTD = 24;
	const uint STUBFMNCSESMENU = 25;
	const uint STUBFMNCSESSTD = 26;
	const uint STUBFMNCOWN = 27;
	const uint STUBFMNCUSRSTD = 28;
	const uint STUBFMNCGRP = 29;
	const uint STUBFMNCUSGSTD = 30;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


