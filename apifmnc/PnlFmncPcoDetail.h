/**
  * \file PnlFmncPcoDetail.h
  * API code for job PnlFmncPcoDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCPCODETAIL_H
#define PNLFMNCPCODETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncPcoDetail
  */
namespace PnlFmncPcoDetail {
	/**
		* VecVDo (full: VecVFmncPcoDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPCOVIEWCLICK = 2;
		static const uint BUTSPLVIEWCLICK = 3;
		static const uint BUTFILVIEWCLICK = 4;
		static const uint BUTJEDITCLICK = 5;
		static const uint BUTPCPVIEWCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncPcoDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFDAT = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPSTE = 3;
		static const uint TXFAMT = 4;
		static const uint TXFCMT = 5;

	public:
		ContIac(const string& TxfDat = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const string& TxfAmt = "", const string& TxfCmt = "");

	public:
		string TxfDat;
		uint numFPupJ;
		uint numFPupSte;
		string TxfAmt;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncPcoDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTPCO = 2;
		static const uint TXTSPL = 3;
		static const uint TXTFIL = 4;
		static const uint TXTPCP = 5;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtPco = "", const string& TxtSpl = "", const string& TxtFil = "", const string& TxtPcp = "");

	public:
		string TxtSrf;
		string TxtPco;
		string TxtSpl;
		string TxtFil;
		string TxtPcp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncPcoDetail)
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
	  * StatShr (full: StatShrFmncPcoDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTPCOVIEWAVAIL = 3;
		static const uint BUTSPLVIEWAVAIL = 4;
		static const uint BUTFILVIEWAVAIL = 5;
		static const uint BUTJEDITAVAIL = 6;
		static const uint BUTPCPVIEWAVAIL = 7;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButPcoViewAvail = true, const bool ButSplViewAvail = true, const bool ButFilViewAvail = true, const bool ButJEditAvail = true, const bool ButPcpViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButPcoViewAvail;
		bool ButSplViewAvail;
		bool ButFilViewAvail;
		bool ButJEditAvail;
		bool ButPcpViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncPcoDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTDAT = 3;
		static const uint CPTPCO = 4;
		static const uint CPTSPL = 5;
		static const uint CPTFIL = 6;
		static const uint CPTSTE = 7;
		static const uint CPTAMT = 8;
		static const uint CPTPCP = 9;
		static const uint CPTCMT = 10;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptDat = "", const string& CptPco = "", const string& CptSpl = "", const string& CptFil = "", const string& CptSte = "", const string& CptAmt = "", const string& CptPcp = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptSrf;
		string CptDat;
		string CptPco;
		string CptSpl;
		string CptFil;
		string CptSte;
		string CptAmt;
		string CptPcp;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncPcoDetailData)
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
		* DpchAppDo (full: DpchAppFmncPcoDetailDo)
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
		* DpchEngData (full: DpchEngFmncPcoDetailData)
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

