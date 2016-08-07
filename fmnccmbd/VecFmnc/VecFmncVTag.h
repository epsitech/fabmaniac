/**
  * \file VecFmncVTag.h
  * vector VecFmncVTag (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVTAG_H
#define VECFMNCVTAG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVTag
	*/
namespace VecFmncVTag {
	const uint ABOUT = 1;
	const uint ALWAYS = 2;
	const uint CANCEL = 3;
	const uint CLOSE = 4;
	const uint CLSESS = 5;
	const uint CREATE = 6;
	const uint DETAIL = 7;
	const uint DONE = 8;
	const uint DOWNLOAD = 9;
	const uint EMPLONG = 10;
	const uint EMPSHORT = 11;
	const uint ERROR = 12;
	const uint FILENAME = 13;
	const uint FLS = 14;
	const uint FOR = 15;
	const uint GENERAL = 16;
	const uint GOTO = 17;
	const uint HELP = 18;
	const uint IMPORT = 19;
	const uint LOAINI = 20;
	const uint NAV = 21;
	const uint NEW = 22;
	const uint NO = 23;
	const uint OK = 24;
	const uint OPSCPLLAST = 25;
	const uint OPSPREP = 26;
	const uint PROGRESS = 27;
	const uint QUEST = 28;
	const uint RUN = 29;
	const uint SESS = 30;
	const uint SHOWLONG = 31;
	const uint SHOWSHORT = 32;
	const uint STOP = 33;
	const uint TRU = 34;
	const uint UPLOAD = 35;
	const uint YES = 36;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);

	void appendToFeed(const uint ix, const uint ixFmncVLocale, Feed& feed);
};

#endif


