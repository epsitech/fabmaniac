/**
  * \file CrdFmncNav.h
  * API code for job CrdFmncNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef CRDFMNCNAV_H
#define CRDFMNCNAV_H

#include "ApiFmnc_blks.h"

/**
  * CrdFmncNav
  */
namespace CrdFmncNav {
	/**
		* VecVDo (full: VecVFmncNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESTRMCLICK = 3;
		static const uint MITCRDUSGCLICK = 4;
		static const uint MITCRDUSRCLICK = 5;
		static const uint MITCRDORGCLICK = 6;
		static const uint MITCRDPRSCLICK = 7;
		static const uint MITCRDADRCLICK = 8;
		static const uint MITCRDFILCLICK = 9;
		static const uint MITCRDSTPCLICK = 10;
		static const uint MITCRDPRJCLICK = 11;
		static const uint MITCRDRUNCLICK = 12;
		static const uint MITCRDACTCLICK = 13;
		static const uint MITCRDSEPCLICK = 14;
		static const uint MITCRDSMPCLICK = 15;
		static const uint MITCRDFABCLICK = 16;
		static const uint MITCRDFUSCLICK = 17;
		static const uint MITCRDTTYCLICK = 18;
		static const uint MITCRDTOLCLICK = 19;
		static const uint MITCRDFPJCLICK = 20;
		static const uint MITCRDBILCLICK = 21;
		static const uint MITCRDARTCLICK = 22;
		static const uint MITCRDSKICLICK = 23;
		static const uint MITCRDPCOCLICK = 24;
		static const uint MITAPPLOICLICK = 25;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVFmncNavSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRFMNCABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncNav)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEHEADBAR = 5;
		static const uint INITDONEPRE = 6;
		static const uint INITDONEADMIN = 7;
		static const uint INITDONELABBOOK = 8;
		static const uint INITDONEFABMGMT = 9;
		static const uint INITDONESUPPLY = 10;

	public:
		StatApp(const uint ixFmncVReqitmode = VecFmncVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneLabbook = false, const bool initdoneFabmgmt = false, const bool initdoneSupply = false);

	public:
		uint ixFmncVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneLabbook;
		bool initdoneFabmgmt;
		bool initdoneSupply;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncNav)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGLOAINI = 1;
		static const uint SCRJREFHEADBAR = 2;
		static const uint SCRJREFPRE = 3;
		static const uint PNLPREAVAIL = 4;
		static const uint SCRJREFADMIN = 5;
		static const uint PNLADMINAVAIL = 6;
		static const uint SCRJREFLABBOOK = 7;
		static const uint PNLLABBOOKAVAIL = 8;
		static const uint SCRJREFFABMGMT = 9;
		static const uint PNLFABMGMTAVAIL = 10;
		static const uint SCRJREFSUPPLY = 11;
		static const uint PNLSUPPLYAVAIL = 12;
		static const uint MSPCRD1AVAIL = 13;
		static const uint MITCRDUSGAVAIL = 14;
		static const uint MITCRDUSRAVAIL = 15;
		static const uint MITCRDORGAVAIL = 16;
		static const uint MITCRDPRSAVAIL = 17;
		static const uint MITCRDADRAVAIL = 18;
		static const uint MITCRDFILAVAIL = 19;
		static const uint MSPCRD2AVAIL = 20;
		static const uint MITCRDSTPAVAIL = 21;
		static const uint MITCRDPRJAVAIL = 22;
		static const uint MITCRDRUNAVAIL = 23;
		static const uint MITCRDACTAVAIL = 24;
		static const uint MITCRDACTACTIVE = 25;
		static const uint MITCRDSEPAVAIL = 26;
		static const uint MITCRDSEPACTIVE = 27;
		static const uint MITCRDSMPAVAIL = 28;
		static const uint MSPCRD3AVAIL = 29;
		static const uint MITCRDFABAVAIL = 30;
		static const uint MITCRDFUSAVAIL = 31;
		static const uint MITCRDFUSACTIVE = 32;
		static const uint MITCRDTTYAVAIL = 33;
		static const uint MITCRDTOLAVAIL = 34;
		static const uint MITCRDTOLACTIVE = 35;
		static const uint MITCRDFPJAVAIL = 36;
		static const uint MITCRDFPJACTIVE = 37;
		static const uint MITCRDBILAVAIL = 38;
		static const uint MITCRDBILACTIVE = 39;
		static const uint MSPCRD4AVAIL = 40;
		static const uint MITCRDARTAVAIL = 41;
		static const uint MITCRDSKIAVAIL = 42;
		static const uint MITCRDPCOAVAIL = 43;
		static const uint MSPAPP2AVAIL = 44;
		static const uint MITAPPLOIAVAIL = 45;

	public:
		StatShr(const string& scrJrefDlgloaini = "", const string& scrJrefHeadbar = "", const string& scrJrefPre = "", const bool pnlpreAvail = false, const string& scrJrefAdmin = "", const bool pnladminAvail = false, const string& scrJrefLabbook = "", const bool pnllabbookAvail = false, const string& scrJrefFabmgmt = "", const bool pnlfabmgmtAvail = false, const string& scrJrefSupply = "", const bool pnlsupplyAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdOrgAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdAdrAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdStpAvail = true, const bool MitCrdPrjAvail = true, const bool MitCrdRunAvail = true, const bool MitCrdActAvail = true, const bool MitCrdActActive = true, const bool MitCrdSepAvail = true, const bool MitCrdSepActive = true, const bool MitCrdSmpAvail = true, const bool MspCrd3Avail = true, const bool MitCrdFabAvail = true, const bool MitCrdFusAvail = true, const bool MitCrdFusActive = true, const bool MitCrdTtyAvail = true, const bool MitCrdTolAvail = true, const bool MitCrdTolActive = true, const bool MitCrdFpjAvail = true, const bool MitCrdFpjActive = true, const bool MitCrdBilAvail = true, const bool MitCrdBilActive = true, const bool MspCrd4Avail = true, const bool MitCrdArtAvail = true, const bool MitCrdSkiAvail = true, const bool MitCrdPcoAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		string scrJrefDlgloaini;
		string scrJrefHeadbar;
		string scrJrefPre;
		bool pnlpreAvail;
		string scrJrefAdmin;
		bool pnladminAvail;
		string scrJrefLabbook;
		bool pnllabbookAvail;
		string scrJrefFabmgmt;
		bool pnlfabmgmtAvail;
		string scrJrefSupply;
		bool pnlsupplyAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdOrgAvail;
		bool MitCrdPrsAvail;
		bool MitCrdAdrAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdStpAvail;
		bool MitCrdPrjAvail;
		bool MitCrdRunAvail;
		bool MitCrdActAvail;
		bool MitCrdActActive;
		bool MitCrdSepAvail;
		bool MitCrdSepActive;
		bool MitCrdSmpAvail;
		bool MspCrd3Avail;
		bool MitCrdFabAvail;
		bool MitCrdFusAvail;
		bool MitCrdFusActive;
		bool MitCrdTtyAvail;
		bool MitCrdTolAvail;
		bool MitCrdTolActive;
		bool MitCrdFpjAvail;
		bool MitCrdFpjActive;
		bool MitCrdBilAvail;
		bool MitCrdBilActive;
		bool MspCrd4Avail;
		bool MitCrdArtAvail;
		bool MitCrdSkiAvail;
		bool MitCrdPcoAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncNav)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITSESTRM = 3;
		static const uint MITCRDUSG = 4;
		static const uint MITCRDUSR = 5;
		static const uint MITCRDORG = 6;
		static const uint MITCRDPRS = 7;
		static const uint MITCRDADR = 8;
		static const uint MITCRDFIL = 9;
		static const uint MITCRDSTP = 10;
		static const uint MITCRDPRJ = 11;
		static const uint MITCRDRUN = 12;
		static const uint MITCRDACT = 13;
		static const uint MITCRDSEP = 14;
		static const uint MITCRDSMP = 15;
		static const uint MITCRDFAB = 16;
		static const uint MITCRDFUS = 17;
		static const uint MITCRDTTY = 18;
		static const uint MITCRDTOL = 19;
		static const uint MITCRDFPJ = 20;
		static const uint MITCRDBIL = 21;
		static const uint MITCRDART = 22;
		static const uint MITCRDSKI = 23;
		static const uint MITCRDPCO = 24;
		static const uint MITAPPLOI = 25;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitSesTrm = "", const string& MitCrdUsg = "", const string& MitCrdUsr = "", const string& MitCrdOrg = "", const string& MitCrdPrs = "", const string& MitCrdAdr = "", const string& MitCrdFil = "", const string& MitCrdStp = "", const string& MitCrdPrj = "", const string& MitCrdRun = "", const string& MitCrdAct = "", const string& MitCrdSep = "", const string& MitCrdSmp = "", const string& MitCrdFab = "", const string& MitCrdFus = "", const string& MitCrdTty = "", const string& MitCrdTol = "", const string& MitCrdFpj = "", const string& MitCrdBil = "", const string& MitCrdArt = "", const string& MitCrdSki = "", const string& MitCrdPco = "", const string& MitAppLoi = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitSesTrm;
		string MitCrdUsg;
		string MitCrdUsr;
		string MitCrdOrg;
		string MitCrdPrs;
		string MitCrdAdr;
		string MitCrdFil;
		string MitCrdStp;
		string MitCrdPrj;
		string MitCrdRun;
		string MitCrdAct;
		string MitCrdSep;
		string MitCrdSmp;
		string MitCrdFab;
		string MitCrdFus;
		string MitCrdTty;
		string MitCrdTol;
		string MitCrdFpj;
		string MitCrdBil;
		string MitCrdArt;
		string MitCrdSki;
		string MitCrdPco;
		string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppFmncNavDo)
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
		* DpchEngData (full: DpchEngFmncNavData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

