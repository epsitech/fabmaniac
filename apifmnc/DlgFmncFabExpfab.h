/**
  * \file DlgFmncFabExpfab.h
  * API code for job DlgFmncFabExpfab (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCFABEXPFAB_H
#define DLGFMNCFABEXPFAB_H

#include "ApiFmnc_blks.h"

/**
  * DlgFmncFabExpfab
  */
namespace DlgFmncFabExpfab {
	/**
		* VecVDit (full: VecVDlgFmncFabExpfabDit)
		*/
	class VecVDit {

	public:
		static const uint PRP = 1;
		static const uint FIA = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgFmncFabExpfabDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPrp (full: VecVDlgFmncFabExpfabDoPrp)
		*/
	class VecVDoPrp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncFabExpfabSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint COLIDLE = 2;
		static const uint COLLECT = 3;
		static const uint EXPORT = 4;
		static const uint PACK = 5;
		static const uint DONE = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgFmncFabExpfab)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgFmncFabExpfab)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfPrp (full: ContInfDlgFmncFabExpfabPrp)
	  */
	class ContInfPrp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfPrp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfPrp* comp);
		set<uint> diff(const ContInfPrp* comp);
	};

	/**
	  * StatApp (full: StatAppDlgFmncFabExpfab)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONE = 1;
		static const uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const string& shortMenu = "");

	public:
		bool initdone;
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgFmncFabExpfab)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrFia (full: StatShrDlgFmncFabExpfabFia)
	  */
	class StatShrFia : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrFia* comp);
		set<uint> diff(const StatShrFia* comp);
	};

	/**
	  * StatShrPrp (full: StatShrDlgFmncFabExpfabPrp)
	  */
	class StatShrPrp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrPrp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrPrp* comp);
		set<uint> diff(const StatShrPrp* comp);
	};

	/**
	  * Tag (full: TagDlgFmncFabExpfab)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDNE = 2;

	public:
		Tag(const string& Cpt = "", const string& ButDne = "");

	public:
		string Cpt;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagFia (full: TagDlgFmncFabExpfabFia)
	  */
	class TagFia : public Block {

	public:
		static const uint DLD = 1;

	public:
		TagFia(const string& Dld = "");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagPrp (full: TagDlgFmncFabExpfabPrp)
	  */
	class TagPrp : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagPrp(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncFabExpfabData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgFmncFabExpfabDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOPRP = 3;
		static const uint ALL = 4;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoPrp = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoPrp;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgFmncFabExpfabData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFPRP = 4;
		static const uint FEEDFDSE = 5;
		static const uint FEEDFSGE = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint STATSHRFIA = 9;
		static const uint STATSHRPRP = 10;
		static const uint TAG = 11;
		static const uint TAGFIA = 12;
		static const uint TAGPRP = 13;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfPrp continfprp;
		Feed feedFDse;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrFia statshrfia;
		StatShrPrp statshrprp;
		Tag tag;
		TagFia tagfia;
		TagPrp tagprp;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

