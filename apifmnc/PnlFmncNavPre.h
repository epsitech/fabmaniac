/**
  * \file PnlFmncNavPre.h
  * API code for job PnlFmncNavPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVPRE_H
#define PNLFMNCNAVPRE_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncNavPre
  */
namespace PnlFmncNavPre {
	/**
		* VecVDo (full: VecVFmncNavPreDo)
		*/
	class VecVDo {

	public:
		static const uint BUTFABREMOVECLICK = 1;
		static const uint BUTRUNREMOVECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncNavPre)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFAB = 1;
		static const uint TXTRUN = 2;

	public:
		ContInf(const string& TxtFab = "", const string& TxtRun = "");

	public:
		string TxtFab;
		string TxtRun;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrFmncNavPre)
	  */
	class StatShr : public Block {

	public:
		static const uint TXTFABAVAIL = 1;
		static const uint TXTRUNAVAIL = 2;

	public:
		StatShr(const bool TxtFabAvail = true, const bool TxtRunAvail = true);

	public:
		bool TxtFabAvail;
		bool TxtRunAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncNavPre)
	  */
	class Tag : public Block {

	public:
		static const uint CPTFAB = 1;
		static const uint CPTRUN = 2;

	public:
		Tag(const string& CptFab = "", const string& CptRun = "");

	public:
		string CptFab;
		string CptRun;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppFmncNavPreDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngFmncNavPreData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATSHR = 3;
		static const uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

