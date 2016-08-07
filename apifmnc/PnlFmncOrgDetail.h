/**
  * \file PnlFmncOrgDetail.h
  * API code for job PnlFmncOrgDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCORGDETAIL_H
#define PNLFMNCORGDETAIL_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncOrgDetail
  */
namespace PnlFmncOrgDetail {
	/**
		* VecVDo (full: VecVFmncOrgDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;
		static const uint BUTADRVIEWCLICK = 3;
		static const uint BUTSUPVIEWCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncOrgDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJ = 1;
		static const uint NUMSFLSTDRV = 2;
		static const uint TXFTEL = 3;
		static const uint TXFEML = 4;

	public:
		ContIac(const uint numFPupJ = 1, const vector<uint>& numsFLstDrv = {}, const string& TxfTel = "", const string& TxfEml = "");

	public:
		uint numFPupJ;
		vector<uint> numsFLstDrv;
		string TxfTel;
		string TxfEml;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncOrgDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTTIT = 2;
		static const uint TXTDRV = 3;
		static const uint TXTADR = 4;
		static const uint TXTSUP = 5;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtTit = "", const string& TxtDrv = "", const string& TxtAdr = "", const string& TxtSup = "");

	public:
		string TxtSrf;
		string TxtTit;
		string TxtDrv;
		string TxtAdr;
		string TxtSup;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncOrgDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint LSTDRVALT = 2;
		static const uint LSTDRVNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstDrvAlt = true, const uint LstDrvNumFirstdisp = 1);

	public:
		uint ixFmncVExpstate;
		bool LstDrvAlt;
		uint LstDrvNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncOrgDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTJEDITAVAIL = 3;
		static const uint BUTADRVIEWAVAIL = 4;
		static const uint BUTSUPVIEWAVAIL = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButJEditAvail = true, const bool ButAdrViewAvail = true, const bool ButSupViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButJEditAvail;
		bool ButAdrViewAvail;
		bool ButSupViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncOrgDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTIT = 3;
		static const uint CPTDRV = 4;
		static const uint CPTADR = 5;
		static const uint CPTSUP = 6;
		static const uint CPTTEL = 7;
		static const uint CPTEML = 8;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTit = "", const string& CptDrv = "", const string& CptAdr = "", const string& CptSup = "", const string& CptTel = "", const string& CptEml = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTit;
		string CptDrv;
		string CptAdr;
		string CptSup;
		string CptTel;
		string CptEml;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncOrgDetailData)
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
		* DpchAppDo (full: DpchAppFmncOrgDetailDo)
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
		* DpchEngData (full: DpchEngFmncOrgDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTDRV = 4;
		static const uint FEEDFPUPJ = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstDrv;
		Feed feedFPupJ;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

