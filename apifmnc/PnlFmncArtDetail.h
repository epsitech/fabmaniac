/**
  * \file PnlFmncArtDetail.h
  * API code for job PnlFmncArtDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCARTDETAIL_H
#define PNLFMNCARTDETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncArtDetail
  */
namespace PnlFmncArtDetail {
	/**
		* VecVDo (full: VecVFmncArtDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTORGVIEWCLICK = 2;
		static const uint BUTTOLVIEWCLICK = 3;
		static const uint BUTTYPEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncArtDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPTYP = 2;
		static const uint TXFTYP = 3;
		static const uint TXFCMT = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupTyp = 1, const string& TxfTyp = "", const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupTyp;
		string TxfTyp;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncArtDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTORG = 2;
		static const uint TXTTOL = 3;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtOrg = "", const string& TxtTol = "");

	public:
		string TxtSrf;
		string TxtOrg;
		string TxtTol;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncArtDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint PUPTYPALT = 2;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool PupTypAlt = false);

	public:
		uint ixFmncVExpstate;
		bool PupTypAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncArtDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFTYPVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint BUTORGVIEWAVAIL = 4;
		static const uint BUTTOLVIEWAVAIL = 5;
		static const uint BUTTYPEDITAVAIL = 6;

	public:
		StatShr(const bool TxfTypValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButOrgViewAvail = true, const bool ButTolViewAvail = true, const bool ButTypEditAvail = true);

	public:
		bool TxfTypValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButOrgViewAvail;
		bool ButTolViewAvail;
		bool ButTypEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncArtDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTIT = 3;
		static const uint CPTORG = 4;
		static const uint CPTTOL = 5;
		static const uint CPTTYP = 6;
		static const uint CPTCMT = 7;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTit = "", const string& CptOrg = "", const string& CptTol = "", const string& CptTyp = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTit;
		string CptOrg;
		string CptTol;
		string CptTyp;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncArtDetailData)
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
		* DpchAppDo (full: DpchAppFmncArtDetailDo)
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
		* DpchEngData (full: DpchEngFmncArtDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPTYP = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

