/**
  * \file PnlFmncTolAChar.h
  * API code for job PnlFmncTolAChar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCTOLACHAR_H
#define PNLFMNCTOLACHAR_H

#include "ApiFmnc_blks.h"

#include "FmncQTolAChar.h"

#include "QryFmncTolAChar.h"

/**
  * PnlFmncTolAChar
  */
namespace PnlFmncTolAChar {
	/**
		* VecVDo (full: VecVFmncTolACharDo)
		*/
	class VecVDo {

	public:
		static const uint BUTNEWCLICK = 1;
		static const uint BUTDUPLICATECLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncTolAChar)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncTolAChar)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND);

	public:
		uint ixFmncVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncTolAChar)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDUPLICATEACTIVE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const bool ButDuplicateActive = true, const bool ButDeleteActive = true);

	public:
		bool ButDuplicateActive;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacFmncTolAChar)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOTCHWIDTH = 1;
		static const uint TCOVALWIDTH = 2;
		static const uint TCOCMTWIDTH = 3;

	public:
		StgIac(const uint TcoTchWidth = 100, const uint TcoValWidth = 100, const uint TcoCmtWidth = 100);

	public:
		uint TcoTchWidth;
		uint TcoValWidth;
		uint TcoCmtWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagFmncTolAChar)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOTCH = 5;
		static const uint TCOVAL = 6;
		static const uint TCOCMT = 7;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoTch = "", const string& TcoVal = "", const string& TcoCmt = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoTch;
		string TcoVal;
		string TcoCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncTolACharData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryFmncTolAChar::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryFmncTolAChar::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppFmncTolACharDo)
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
		* DpchEngData (full: DpchEngFmncTolACharData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListFmncQTolAChar rst;
		QryFmncTolAChar::StatApp statappqry;
		QryFmncTolAChar::StatShr statshrqry;
		QryFmncTolAChar::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

