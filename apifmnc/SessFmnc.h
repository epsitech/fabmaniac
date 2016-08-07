/**
  * \file SessFmnc.h
  * API code for job SessFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef SESSFMNC_H
#define SESSFMNC_H

#include "ApiFmnc_blks.h"

/**
  * SessFmnc
  */
namespace SessFmnc {
	/**
	  * StatShr (full: StatShrSessFmnc)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const string& scrJrefCrdnav = "");

	public:
		string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessFmncData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint STATSHR = 2;

	public:
		DpchEngData();

	public:
		StatShr statshr;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

