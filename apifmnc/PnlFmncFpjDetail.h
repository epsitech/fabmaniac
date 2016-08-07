/**
  * \file PnlFmncFpjDetail.h
  * API code for job PnlFmncFpjDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCFPJDETAIL_H
#define PNLFMNCFPJDETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncFpjDetail
  */
namespace PnlFmncFpjDetail {
	/**
		* VecVDo (full: VecVFmncFpjDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTFABVIEWCLICK = 2;
		static const uint BUTBIOVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;
		static const uint BUTBIPVIEWCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncFpjDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPSTE = 3;
		static const uint TXFCMT = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupJ;
		uint numFPupSte;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncFpjDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTFAB = 2;
		static const uint TXTBIO = 3;
		static const uint TXTBIP = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtFab = "", const string& TxtBio = "", const string& TxtBip = "");

	public:
		string TxtSrf;
		string TxtFab;
		string TxtBio;
		string TxtBip;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncFpjDetail)
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
	  * StatShr (full: StatShrFmncFpjDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTFABVIEWAVAIL = 3;
		static const uint BUTBIOVIEWAVAIL = 4;
		static const uint BUTJEDITAVAIL = 5;
		static const uint BUTBIPVIEWAVAIL = 6;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButFabViewAvail = true, const bool ButBioViewAvail = true, const bool ButJEditAvail = true, const bool ButBipViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButFabViewAvail;
		bool ButBioViewAvail;
		bool ButJEditAvail;
		bool ButBipViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncFpjDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTIT = 3;
		static const uint CPTFAB = 4;
		static const uint CPTBIO = 5;
		static const uint CPTSTE = 6;
		static const uint CPTBIP = 7;
		static const uint CPTCMT = 8;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTit = "", const string& CptFab = "", const string& CptBio = "", const string& CptSte = "", const string& CptBip = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTit;
		string CptFab;
		string CptBio;
		string CptSte;
		string CptBip;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncFpjDetailData)
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
		* DpchAppDo (full: DpchAppFmncFpjDetailDo)
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
		* DpchEngData (full: DpchEngFmncFpjDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJ = 4;
		static const uint FEEDFPUPSTE = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJ;
		Feed feedFPupSte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

