/**
  * \file VecFmncVRMFileMStepDir.h
  * vector VecFmncVRMFileMStepDir (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVRMFILEMSTEPDIR_H
#define VECFMNCVRMFILEMSTEPDIR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVRMFileMStepDir
	*/
namespace VecFmncVRMFileMStepDir {
	const uint VOID = 1;
	const uint IN = 2;
	const uint OUT = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

