/**
  * \file PnlFmncTolAUtil.h
  * API code for job PnlFmncTolAUtil (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCTOLAUTIL_H
#define PNLFMNCTOLAUTIL_H

#include "ApiFmnc_blks.h"

#include "FmncQTolAUtil.h"

#include "QryFmncTolAUtil.h"

/**
  * PnlFmncTolAUtil
  */
namespace PnlFmncTolAUtil {
	/**
		* VecVDo (full: VecVFmncTolAUtilDo)
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
	  * ContInf (full: ContInfFmncTolAUtil)
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
	  * StatApp (full: StatAppFmncTolAUtil)
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
	  * StatShr (full: StatShrFmncTolAUtil)
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
	  * StgIac (full: StgIacFmncTolAUtil)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOFPJWIDTH = 1;
		static const uint TCOFUSWIDTH = 2;
		static const uint TCODATWIDTH = 3;
		static const uint TCOSTAWIDTH = 4;
		static const uint TCOSTOWIDTH = 5;
		static const uint TCOUPRWIDTH = 6;
		static const uint TCOCMTWIDTH = 7;

	public:
		StgIac(const uint TcoFpjWidth = 100, const uint TcoFusWidth = 100, const uint TcoDatWidth = 100, const uint TcoStaWidth = 100, const uint TcoStoWidth = 100, const uint TcoUprWidth = 100, const uint TcoCmtWidth = 100);

	public:
		uint TcoFpjWidth;
		uint TcoFusWidth;
		uint TcoDatWidth;
		uint TcoStaWidth;
		uint TcoStoWidth;
		uint TcoUprWidth;
		uint TcoCmtWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagFmncTolAUtil)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOFPJ = 5;
		static const uint TCOFUS = 6;
		static const uint TCODAT = 7;
		static const uint TCOSTA = 8;
		static const uint TCOSTO = 9;
		static const uint TCOUPR = 10;
		static const uint TCOCMT = 11;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoFpj = "", const string& TcoFus = "", const string& TcoDat = "", const string& TcoSta = "", const string& TcoSto = "", const string& TcoUpr = "", const string& TcoCmt = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoFpj;
		string TcoFus;
		string TcoDat;
		string TcoSta;
		string TcoSto;
		string TcoUpr;
		string TcoCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncTolAUtilData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryFmncTolAUtil::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryFmncTolAUtil::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppFmncTolAUtilDo)
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
		* DpchEngData (full: DpchEngFmncTolAUtilData)
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
		ListFmncQTolAUtil rst;
		QryFmncTolAUtil::StatApp statappqry;
		QryFmncTolAUtil::StatShr statshrqry;
		QryFmncTolAUtil::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

