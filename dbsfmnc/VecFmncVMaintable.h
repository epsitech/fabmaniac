/**
  * \file VecFmncVMaintable.h
  * vector VecFmncVMaintable (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVMAINTABLE_H
#define VECFMNCVMAINTABLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVMaintable
	*/
namespace VecFmncVMaintable {
	const uint VOID = 1;
	const uint TBLFMNCMACTIVITY = 2;
	const uint TBLFMNCMADDRESS = 3;
	const uint TBLFMNCMARTICLE = 4;
	const uint TBLFMNCMBILL = 5;
	const uint TBLFMNCMFAB = 6;
	const uint TBLFMNCMFABPROJECT = 7;
	const uint TBLFMNCMFABUSER = 8;
	const uint TBLFMNCMFILE = 9;
	const uint TBLFMNCMORG = 10;
	const uint TBLFMNCMPERSON = 11;
	const uint TBLFMNCMPROJECT = 12;
	const uint TBLFMNCMPURCHORDER = 13;
	const uint TBLFMNCMRUN = 14;
	const uint TBLFMNCMSAMPLE = 15;
	const uint TBLFMNCMSESSION = 16;
	const uint TBLFMNCMSTEP = 17;
	const uint TBLFMNCMSTOCKITEM = 18;
	const uint TBLFMNCMTOOL = 19;
	const uint TBLFMNCMTOOLTYPE = 20;
	const uint TBLFMNCMUSER = 21;
	const uint TBLFMNCMUSERGROUP = 22;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

