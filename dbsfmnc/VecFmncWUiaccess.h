/**
  * \file VecFmncWUiaccess.h
  * vector VecFmncWUiaccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCWUIACCESS_H
#define VECFMNCWUIACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncWUiaccess
	*/
namespace VecFmncWUiaccess {
	const uint EDIT = 1;
	const uint EXEC = 2;
	const uint VIEW = 4;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void fillFeed(const uint ixFmncVLocale, Feed& feed);
};

#endif

