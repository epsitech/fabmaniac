/**
  * \file VecFmncVValuelist.h
  * vector VecFmncVValuelist (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVVALUELIST_H
#define VECFMNCVVALUELIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVValuelist
	*/
namespace VecFmncVValuelist {
	const uint VLSTFMNCUMPERSONTITLE = 1;
	const uint VLSTFMNCUMSAMPLEMATERIAL = 2;
	const uint VLSTFMNCUMTOOLTRAINING = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);
};

#endif

