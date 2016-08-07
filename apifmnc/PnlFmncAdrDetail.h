/**
  * \file PnlFmncAdrDetail.h
  * API code for job PnlFmncAdrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCADRDETAIL_H
#define PNLFMNCADRDETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncAdrDetail
  */
namespace PnlFmncAdrDetail {
	/**
		* VecVDo (full: VecVFmncAdrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTHKUVIEWCLICK = 2;
		static const uint BUTATYEDITCLICK = 3;
		static const uint BUTCRYEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncAdrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFAD1 = 1;
		static const uint TXFCTY = 2;
		static const uint TXFSTA = 3;
		static const uint NUMFPUPHKT = 4;
		static const uint NUMFPUPATY = 5;
		static const uint TXFATY = 6;
		static const uint TXFAD2 = 7;
		static const uint TXFZIP = 8;
		static const uint TXFSTE = 9;
		static const uint NUMFPUPCRY = 10;
		static const uint TXFCRY = 11;

	public:
		ContIac(const string& TxfAd1 = "", const string& TxfCty = "", const string& TxfSta = "", const uint numFPupHkt = 1, const uint numFPupAty = 1, const string& TxfAty = "", const string& TxfAd2 = "", const string& TxfZip = "", const string& TxfSte = "", const uint numFPupCry = 1, const string& TxfCry = "");

	public:
		string TxfAd1;
		string TxfCty;
		string TxfSta;
		uint numFPupHkt;
		uint numFPupAty;
		string TxfAty;
		string TxfAd2;
		string TxfZip;
		string TxfSte;
		uint numFPupCry;
		string TxfCry;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncAdrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTHKU = 1;

	public:
		ContInf(const string& TxtHku = "");

	public:
		string TxtHku;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncAdrDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint PUPATYALT = 2;
		static const uint PUPCRYALT = 3;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool PupAtyAlt = false, const bool PupCryAlt = false);

	public:
		uint ixFmncVExpstate;
		bool PupAtyAlt;
		bool PupCryAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncAdrDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFATYVALID = 1;
		static const uint TXFCRYVALID = 2;
		static const uint BUTSAVEAVAIL = 3;
		static const uint BUTSAVEACTIVE = 4;
		static const uint BUTATYEDITAVAIL = 5;
		static const uint BUTCRYEDITAVAIL = 6;

	public:
		StatShr(const bool TxfAtyValid = false, const bool TxfCryValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButAtyEditAvail = true, const bool ButCryEditAvail = true);

	public:
		bool TxfAtyValid;
		bool TxfCryValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButAtyEditAvail;
		bool ButCryEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncAdrDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTAD1 = 2;
		static const uint CPTCTY = 3;
		static const uint CPTSTA = 4;
		static const uint CPTHKU = 5;
		static const uint CPTATY = 6;
		static const uint CPTAD2 = 7;
		static const uint CPTZIP = 8;
		static const uint CPTSTE = 9;
		static const uint CPTCRY = 10;

	public:
		Tag(const string& Cpt = "", const string& CptAd1 = "", const string& CptCty = "", const string& CptSta = "", const string& CptHku = "", const string& CptAty = "", const string& CptAd2 = "", const string& CptZip = "", const string& CptSte = "", const string& CptCry = "");

	public:
		string Cpt;
		string CptAd1;
		string CptCty;
		string CptSta;
		string CptHku;
		string CptAty;
		string CptAd2;
		string CptZip;
		string CptSte;
		string CptCry;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncAdrDetailData)
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
		* DpchAppDo (full: DpchAppFmncAdrDetailDo)
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
		* DpchEngData (full: DpchEngFmncAdrDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPATY = 4;
		static const uint FEEDFPUPCRY = 5;
		static const uint FEEDFPUPHKT = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAty;
		Feed feedFPupCry;
		Feed feedFPupHkt;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

