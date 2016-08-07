/**
  * \file VecFmncVReqitmode.h
  * vector VecFmncVReqitmode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVREQITMODE_H
#define VECFMNCVREQITMODE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVReqitmode
	*/
namespace VecFmncVReqitmode {
	const uint IDLE = 1;
	const uint NOTIFY = 2;
	const uint POLL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


