/**
  * \file PnlFmncSkiDetail.h
  * API code for job PnlFmncSkiDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSKIDETAIL_H
#define PNLFMNCSKIDETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncSkiDetail
  */
namespace PnlFmncSkiDetail {
	/**
		* VecVDo (full: VecVFmncSkiDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTORGVIEWCLICK = 2;
		static const uint BUTARTVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;
		static const uint BUTLCNEDITCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncSkiDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJ = 1;
		static const uint NUMFPUPLCN = 2;
		static const uint TXFLCN = 3;
		static const uint TXFEXD = 4;
		static const uint TXFCMT = 5;

	public:
		ContIac(const uint numFPupJ = 1, const uint numFPupLcn = 1, const string& TxfLcn = "", const string& TxfExd = "", const string& TxfCmt = "");

	public:
		uint numFPupJ;
		uint numFPupLcn;
		string TxfLcn;
		string TxfExd;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncSkiDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTORG = 1;
		static const uint TXTART = 2;
		static const uint TXTQTY = 3;

	public:
		ContInf(const string& TxtOrg = "", const string& TxtArt = "", const string& TxtQty = "");

	public:
		string TxtOrg;
		string TxtArt;
		string TxtQty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncSkiDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint PUPLCNALT = 2;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool PupLcnAlt = false);

	public:
		uint ixFmncVExpstate;
		bool PupLcnAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncSkiDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFLCNVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint BUTORGVIEWAVAIL = 4;
		static const uint BUTARTVIEWAVAIL = 5;
		static const uint BUTJEDITAVAIL = 6;
		static const uint BUTLCNEDITAVAIL = 7;

	public:
		StatShr(const bool TxfLcnValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButOrgViewAvail = true, const bool ButArtViewAvail = true, const bool ButJEditAvail = true, const bool ButLcnEditAvail = true);

	public:
		bool TxfLcnValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButOrgViewAvail;
		bool ButArtViewAvail;
		bool ButJEditAvail;
		bool ButLcnEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncSkiDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTORG = 2;
		static const uint CPTART = 3;
		static const uint CPTQTY = 4;
		static const uint CPTLCN = 5;
		static const uint CPTEXD = 6;
		static const uint CPTCMT = 7;

	public:
		Tag(const string& Cpt = "", const string& CptOrg = "", const string& CptArt = "", const string& CptQty = "", const string& CptLcn = "", const string& CptExd = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptOrg;
		string CptArt;
		string CptQty;
		string CptLcn;
		string CptExd;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncSkiDetailData)
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
		* DpchAppDo (full: DpchAppFmncSkiDetailDo)
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
		* DpchEngData (full: DpchEngFmncSkiDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJ = 4;
		static const uint FEEDFPUPLCN = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJ;
		Feed feedFPupLcn;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

