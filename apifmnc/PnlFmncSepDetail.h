/**
  * \file PnlFmncSepDetail.h
  * API code for job PnlFmncSepDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSEPDETAIL_H
#define PNLFMNCSEPDETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncSepDetail
  */
namespace PnlFmncSepDetail {
	/**
		* VecVDo (full: VecVFmncSepDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTACTVIEWCLICK = 2;
		static const uint BUTRLUVIEWCLICK = 3;
		static const uint BUTPRSVIEWCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncSepDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPRLT = 2;
		static const uint NUMSFLSTFCF = 3;
		static const uint TXFSTA = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupRlt = 1, const vector<uint>& numsFLstFcf = {}, const string& TxfSta = "");

	public:
		string TxfTit;
		uint numFPupRlt;
		vector<uint> numsFLstFcf;
		string TxfSta;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncSepDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTACT = 1;
		static const uint TXTRLU = 2;
		static const uint TXTSTP = 3;
		static const uint TXTFCF = 4;
		static const uint TXTPRS = 5;

	public:
		ContInf(const string& TxtAct = "", const string& TxtRlu = "", const string& TxtStp = "", const string& TxtFcf = "", const string& TxtPrs = "");

	public:
		string TxtAct;
		string TxtRlu;
		string TxtStp;
		string TxtFcf;
		string TxtPrs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncSepDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint LSTFCFALT = 2;
		static const uint LSTFCFNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstFcfAlt = true, const uint LstFcfNumFirstdisp = 1);

	public:
		uint ixFmncVExpstate;
		bool LstFcfAlt;
		uint LstFcfNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncSepDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTACTVIEWAVAIL = 3;
		static const uint BUTPRSVIEWAVAIL = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButActViewAvail = true, const bool ButPrsViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButActViewAvail;
		bool ButPrsViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncSepDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTACT = 3;
		static const uint CPTRLU = 4;
		static const uint CPTSTP = 5;
		static const uint CPTFCF = 6;
		static const uint CPTSTA = 7;
		static const uint CPTPRS = 8;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptAct = "", const string& CptRlu = "", const string& CptStp = "", const string& CptFcf = "", const string& CptSta = "", const string& CptPrs = "");

	public:
		string Cpt;
		string CptTit;
		string CptAct;
		string CptRlu;
		string CptStp;
		string CptFcf;
		string CptSta;
		string CptPrs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncSepDetailData)
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
		* DpchAppDo (full: DpchAppFmncSepDetailDo)
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
		* DpchEngData (full: DpchEngFmncSepDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTFCF = 4;
		static const uint FEEDFPUPRLT = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstFcf;
		Feed feedFPupRlt;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

