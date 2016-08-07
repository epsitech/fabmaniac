/**
  * \file PnlFmncNavFabmgmt.h
  * API code for job PnlFmncNavFabmgmt (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVFABMGMT_H
#define PNLFMNCNAVFABMGMT_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncNavFabmgmt
  */
namespace PnlFmncNavFabmgmt {
	/**
		* VecVDo (full: VecVFmncNavFabmgmtDo)
		*/
	class VecVDo {

	public:
		static const uint BUTFABVIEWCLICK = 1;
		static const uint BUTFABNEWCRDCLICK = 2;
		static const uint BUTFUSVIEWCLICK = 3;
		static const uint BUTFUSNEWCRDCLICK = 4;
		static const uint BUTTTYVIEWCLICK = 5;
		static const uint BUTTTYNEWCRDCLICK = 6;
		static const uint BUTTOLVIEWCLICK = 7;
		static const uint BUTTOLNEWCRDCLICK = 8;
		static const uint BUTFPJVIEWCLICK = 9;
		static const uint BUTFPJNEWCRDCLICK = 10;
		static const uint BUTBILVIEWCLICK = 11;
		static const uint BUTBILNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavFabmgmt)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTFAB = 1;
		static const uint NUMFLSTFUS = 2;
		static const uint NUMFLSTTTY = 3;
		static const uint NUMFLSTTOL = 4;
		static const uint NUMFLSTFPJ = 5;
		static const uint NUMFLSTBIL = 6;

	public:
		ContIac(const uint numFLstFab = 1, const uint numFLstFus = 1, const uint numFLstTty = 1, const uint numFLstTol = 1, const uint numFLstFpj = 1, const uint numFLstBil = 1);

	public:
		uint numFLstFab;
		uint numFLstFus;
		uint numFLstTty;
		uint numFLstTol;
		uint numFLstFpj;
		uint numFLstBil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppFmncNavFabmgmt)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint LSTFABALT = 2;
		static const uint LSTFUSALT = 3;
		static const uint LSTTTYALT = 4;
		static const uint LSTTOLALT = 5;
		static const uint LSTFPJALT = 6;
		static const uint LSTBILALT = 7;
		static const uint LSTFABNUMFIRSTDISP = 8;
		static const uint LSTFUSNUMFIRSTDISP = 9;
		static const uint LSTTTYNUMFIRSTDISP = 10;
		static const uint LSTTOLNUMFIRSTDISP = 11;
		static const uint LSTFPJNUMFIRSTDISP = 12;
		static const uint LSTBILNUMFIRSTDISP = 13;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstFabAlt = true, const bool LstFusAlt = true, const bool LstTtyAlt = true, const bool LstTolAlt = true, const bool LstFpjAlt = true, const bool LstBilAlt = true, const uint LstFabNumFirstdisp = 1, const uint LstFusNumFirstdisp = 1, const uint LstTtyNumFirstdisp = 1, const uint LstTolNumFirstdisp = 1, const uint LstFpjNumFirstdisp = 1, const uint LstBilNumFirstdisp = 1);

	public:
		uint ixFmncVExpstate;
		bool LstFabAlt;
		bool LstFusAlt;
		bool LstTtyAlt;
		bool LstTolAlt;
		bool LstFpjAlt;
		bool LstBilAlt;
		uint LstFabNumFirstdisp;
		uint LstFusNumFirstdisp;
		uint LstTtyNumFirstdisp;
		uint LstTolNumFirstdisp;
		uint LstFpjNumFirstdisp;
		uint LstBilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncNavFabmgmt)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTFABAVAIL = 1;
		static const uint BUTFABVIEWACTIVE = 2;
		static const uint LSTFUSAVAIL = 3;
		static const uint BUTFUSVIEWACTIVE = 4;
		static const uint BUTFUSNEWCRDACTIVE = 5;
		static const uint LSTTTYAVAIL = 6;
		static const uint BUTTTYVIEWACTIVE = 7;
		static const uint LSTTOLAVAIL = 8;
		static const uint BUTTOLVIEWACTIVE = 9;
		static const uint BUTTOLNEWCRDACTIVE = 10;
		static const uint LSTFPJAVAIL = 11;
		static const uint BUTFPJVIEWACTIVE = 12;
		static const uint BUTFPJNEWCRDACTIVE = 13;
		static const uint LSTBILAVAIL = 14;
		static const uint BUTBILVIEWACTIVE = 15;
		static const uint BUTBILNEWCRDACTIVE = 16;

	public:
		StatShr(const bool LstFabAvail = true, const bool ButFabViewActive = true, const bool LstFusAvail = true, const bool ButFusViewActive = true, const bool ButFusNewcrdActive = true, const bool LstTtyAvail = true, const bool ButTtyViewActive = true, const bool LstTolAvail = true, const bool ButTolViewActive = true, const bool ButTolNewcrdActive = true, const bool LstFpjAvail = true, const bool ButFpjViewActive = true, const bool ButFpjNewcrdActive = true, const bool LstBilAvail = true, const bool ButBilViewActive = true, const bool ButBilNewcrdActive = true);

	public:
		bool LstFabAvail;
		bool ButFabViewActive;
		bool LstFusAvail;
		bool ButFusViewActive;
		bool ButFusNewcrdActive;
		bool LstTtyAvail;
		bool ButTtyViewActive;
		bool LstTolAvail;
		bool ButTolViewActive;
		bool ButTolNewcrdActive;
		bool LstFpjAvail;
		bool ButFpjViewActive;
		bool ButFpjNewcrdActive;
		bool LstBilAvail;
		bool ButBilViewActive;
		bool ButBilNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncNavFabmgmt)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTFAB = 2;
		static const uint CPTFUS = 3;
		static const uint CPTTTY = 4;
		static const uint CPTTOL = 5;
		static const uint CPTFPJ = 6;
		static const uint CPTBIL = 7;

	public:
		Tag(const string& Cpt = "", const string& CptFab = "", const string& CptFus = "", const string& CptTty = "", const string& CptTol = "", const string& CptFpj = "", const string& CptBil = "");

	public:
		string Cpt;
		string CptFab;
		string CptFus;
		string CptTty;
		string CptTol;
		string CptFpj;
		string CptBil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavFabmgmtData)
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
		* DpchAppDo (full: DpchAppFmncNavFabmgmtDo)
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
		* DpchEngData (full: DpchEngFmncNavFabmgmtData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTBIL = 3;
		static const uint FEEDFLSTFAB = 4;
		static const uint FEEDFLSTFPJ = 5;
		static const uint FEEDFLSTFUS = 6;
		static const uint FEEDFLSTTOL = 7;
		static const uint FEEDFLSTTTY = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstBil;
		Feed feedFLstFab;
		Feed feedFLstFpj;
		Feed feedFLstFus;
		Feed feedFLstTol;
		Feed feedFLstTty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

