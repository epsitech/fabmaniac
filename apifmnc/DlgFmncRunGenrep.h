/**
  * \file DlgFmncRunGenrep.h
  * API code for job DlgFmncRunGenrep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCRUNGENREP_H
#define DLGFMNCRUNGENREP_H

#include "ApiFmnc_blks.h"

/**
  * DlgFmncRunGenrep
  */
namespace DlgFmncRunGenrep {
	/**
		* VecVDit (full: VecVDlgFmncRunGenrepDit)
		*/
	class VecVDit {

	public:
		static const uint OPT = 1;
		static const uint STO = 2;
		static const uint GEN = 3;
		static const uint FIA = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgFmncRunGenrepDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoGen (full: VecVDlgFmncRunGenrepDoGen)
		*/
	class VecVDoGen {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncRunGenrepSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRPIDLE = 2;
		static const uint PREPARE = 3;
		static const uint TYPESET = 4;
		static const uint PACK = 5;
		static const uint DONE = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgFmncRunGenrep)
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
	  * ContIacOpt (full: ContIacDlgFmncRunGenrepOpt)
	  */
	class ContIacOpt : public Block {

	public:
		static const uint NUMFRBUHIS = 1;
		static const uint CHKSSU = 2;
		static const uint NUMFRBUFAB = 3;
		static const uint NUMFRBUPRS = 4;
		static const uint NUMFRBUFIL = 5;
		static const uint NUMFRBUSMP = 6;
		static const uint NUMFLSTSPA = 7;

	public:
		ContIacOpt(const uint numFRbuHis = 1, const bool ChkSsu = false, const uint numFRbuFab = 1, const uint numFRbuPrs = 1, const uint numFRbuFil = 1, const uint numFRbuSmp = 1, const uint numFLstSpa = 1);

	public:
		uint numFRbuHis;
		bool ChkSsu;
		uint numFRbuFab;
		uint numFRbuPrs;
		uint numFRbuFil;
		uint numFRbuSmp;
		uint numFLstSpa;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacOpt* comp);
		set<uint> diff(const ContIacOpt* comp);
	};

	/**
	  * ContIacSto (full: ContIacDlgFmncRunGenrepSto)
	  */
	class ContIacSto : public Block {

	public:
		static const uint CHKDET = 1;
		static const uint NUMFRBUFIL = 2;
		static const uint NUMFLSTIMF = 3;
		static const uint NUMFLSTPAR = 4;
		static const uint NUMFRBUCPA = 5;
		static const uint NUMFRBUFSP = 6;
		static const uint NUMFRBUSSP = 7;

	public:
		ContIacSto(const bool ChkDet = false, const uint numFRbuFil = 1, const uint numFLstImf = 1, const uint numFLstPar = 1, const uint numFRbuCpa = 1, const uint numFRbuFsp = 1, const uint numFRbuSsp = 1);

	public:
		bool ChkDet;
		uint numFRbuFil;
		uint numFLstImf;
		uint numFLstPar;
		uint numFRbuCpa;
		uint numFRbuFsp;
		uint numFRbuSsp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacSto* comp);
		set<uint> diff(const ContIacSto* comp);
	};

	/**
	  * ContInf (full: ContInfDlgFmncRunGenrep)
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
	  * ContInfGen (full: ContInfDlgFmncRunGenrepGen)
	  */
	class ContInfGen : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfGen(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfGen* comp);
		set<uint> diff(const ContInfGen* comp);
	};

	/**
	  * StatApp (full: StatAppDlgFmncRunGenrep)
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
	  * StatAppOpt (full: StatAppDlgFmncRunGenrepOpt)
	  */
	class StatAppOpt : public Block {

	public:
		static const uint LSTSPANUMFIRSTDISP = 1;

	public:
		StatAppOpt(const uint LstSpaNumFirstdisp = 1);

	public:
		uint LstSpaNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatAppOpt* comp);
		set<uint> diff(const StatAppOpt* comp);
	};

	/**
	  * StatAppSto (full: StatAppDlgFmncRunGenrepSto)
	  */
	class StatAppSto : public Block {

	public:
		static const uint LSTIMFNUMFIRSTDISP = 1;
		static const uint LSTPARNUMFIRSTDISP = 2;

	public:
		StatAppSto(const uint LstImfNumFirstdisp = 1, const uint LstParNumFirstdisp = 1);

	public:
		uint LstImfNumFirstdisp;
		uint LstParNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatAppSto* comp);
		set<uint> diff(const StatAppSto* comp);
	};

	/**
	  * StatShr (full: StatShrDlgFmncRunGenrep)
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
	  * StatShrGen (full: StatShrDlgFmncRunGenrepGen)
	  */
	class StatShrGen : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrGen(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrGen* comp);
		set<uint> diff(const StatShrGen* comp);
	};

	/**
	  * Tag (full: TagDlgFmncRunGenrep)
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
	  * TagFia (full: TagDlgFmncRunGenrepFia)
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
	  * TagGen (full: TagDlgFmncRunGenrepGen)
	  */
	class TagGen : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagGen(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagOpt (full: TagDlgFmncRunGenrepOpt)
	  */
	class TagOpt : public Block {

	public:
		static const uint CPTHIS = 1;
		static const uint CPTSSU = 2;
		static const uint CPTFAB = 3;
		static const uint CPTPRS = 4;
		static const uint CPTFIL = 5;
		static const uint CPTSMP = 6;
		static const uint CPTSPA = 7;

	public:
		TagOpt(const string& CptHis = "", const string& CptSsu = "", const string& CptFab = "", const string& CptPrs = "", const string& CptFil = "", const string& CptSmp = "", const string& CptSpa = "");

	public:
		string CptHis;
		string CptSsu;
		string CptFab;
		string CptPrs;
		string CptFil;
		string CptSmp;
		string CptSpa;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagSto (full: TagDlgFmncRunGenrepSto)
	  */
	class TagSto : public Block {

	public:
		static const uint CPTDET = 1;
		static const uint CPTFIL = 2;
		static const uint CPTIMF = 3;
		static const uint CPTPAR = 4;
		static const uint CPTCPA = 5;
		static const uint CPTFSP = 6;
		static const uint CPTSSP = 7;

	public:
		TagSto(const string& CptDet = "", const string& CptFil = "", const string& CptImf = "", const string& CptPar = "", const string& CptCpa = "", const string& CptFsp = "", const string& CptSsp = "");

	public:
		string CptDet;
		string CptFil;
		string CptImf;
		string CptPar;
		string CptCpa;
		string CptFsp;
		string CptSsp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncRunGenrepData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACOPT = 3;
		static const uint CONTIACSTO = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, ContIacOpt* contiacopt = NULL, ContIacSto* contiacsto = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacOpt contiacopt;
		ContIacSto contiacsto;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgFmncRunGenrepDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOGEN = 3;
		static const uint ALL = 4;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoGen = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoGen;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgFmncRunGenrepData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACOPT = 3;
		static const uint CONTIACSTO = 4;
		static const uint CONTINF = 5;
		static const uint CONTINFGEN = 6;
		static const uint FEEDFDSE = 7;
		static const uint FEEDFOPTLSTSPA = 8;
		static const uint FEEDFOPTRBUFAB = 9;
		static const uint FEEDFOPTRBUFIL = 10;
		static const uint FEEDFOPTRBUHIS = 11;
		static const uint FEEDFOPTRBUPRS = 12;
		static const uint FEEDFOPTRBUSMP = 13;
		static const uint FEEDFSGE = 14;
		static const uint FEEDFSTOLSTIMF = 15;
		static const uint FEEDFSTOLSTPAR = 16;
		static const uint FEEDFSTORBUCPA = 17;
		static const uint FEEDFSTORBUFIL = 18;
		static const uint FEEDFSTORBUFSP = 19;
		static const uint FEEDFSTORBUSSP = 20;
		static const uint STATAPP = 21;
		static const uint STATAPPOPT = 22;
		static const uint STATAPPSTO = 23;
		static const uint STATSHR = 24;
		static const uint STATSHRGEN = 25;
		static const uint TAG = 26;
		static const uint TAGFIA = 27;
		static const uint TAGGEN = 28;
		static const uint TAGOPT = 29;
		static const uint TAGSTO = 30;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacOpt contiacopt;
		ContIacSto contiacsto;
		ContInf continf;
		ContInfGen continfgen;
		Feed feedFDse;
		Feed feedFOptLstSpa;
		Feed feedFOptRbuFab;
		Feed feedFOptRbuFil;
		Feed feedFOptRbuHis;
		Feed feedFOptRbuPrs;
		Feed feedFOptRbuSmp;
		Feed feedFSge;
		Feed feedFStoLstImf;
		Feed feedFStoLstPar;
		Feed feedFStoRbuCpa;
		Feed feedFStoRbuFil;
		Feed feedFStoRbuFsp;
		Feed feedFStoRbuSsp;
		StatApp statapp;
		StatAppOpt statappopt;
		StatAppSto statappsto;
		StatShr statshr;
		StatShrGen statshrgen;
		Tag tag;
		TagFia tagfia;
		TagGen taggen;
		TagOpt tagopt;
		TagSto tagsto;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

