/**
  * \file PnlFmncNavLabbook.h
  * API code for job PnlFmncNavLabbook (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVLABBOOK_H
#define PNLFMNCNAVLABBOOK_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncNavLabbook
  */
namespace PnlFmncNavLabbook {
	/**
		* VecVDo (full: VecVFmncNavLabbookDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSTPVIEWCLICK = 1;
		static const uint BUTSTPNEWCRDCLICK = 2;
		static const uint BUTPRJVIEWCLICK = 3;
		static const uint BUTPRJNEWCRDCLICK = 4;
		static const uint BUTRUNVIEWCLICK = 5;
		static const uint BUTRUNNEWCRDCLICK = 6;
		static const uint BUTACTVIEWCLICK = 7;
		static const uint BUTACTNEWCRDCLICK = 8;
		static const uint BUTSEPVIEWCLICK = 9;
		static const uint BUTSEPNEWCRDCLICK = 10;
		static const uint BUTSMPVIEWCLICK = 11;
		static const uint BUTSMPNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavLabbook)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTSTP = 1;
		static const uint NUMFLSTPRJ = 2;
		static const uint NUMFLSTRUN = 3;
		static const uint NUMFLSTACT = 4;
		static const uint NUMFLSTSEP = 5;
		static const uint NUMFLSTSMP = 6;

	public:
		ContIac(const uint numFLstStp = 1, const uint numFLstPrj = 1, const uint numFLstRun = 1, const uint numFLstAct = 1, const uint numFLstSep = 1, const uint numFLstSmp = 1);

	public:
		uint numFLstStp;
		uint numFLstPrj;
		uint numFLstRun;
		uint numFLstAct;
		uint numFLstSep;
		uint numFLstSmp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppFmncNavLabbook)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint LSTSTPALT = 2;
		static const uint LSTPRJALT = 3;
		static const uint LSTRUNALT = 4;
		static const uint LSTACTALT = 5;
		static const uint LSTSEPALT = 6;
		static const uint LSTSMPALT = 7;
		static const uint LSTSTPNUMFIRSTDISP = 8;
		static const uint LSTPRJNUMFIRSTDISP = 9;
		static const uint LSTRUNNUMFIRSTDISP = 10;
		static const uint LSTACTNUMFIRSTDISP = 11;
		static const uint LSTSEPNUMFIRSTDISP = 12;
		static const uint LSTSMPNUMFIRSTDISP = 13;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstStpAlt = true, const bool LstPrjAlt = true, const bool LstRunAlt = true, const bool LstActAlt = true, const bool LstSepAlt = true, const bool LstSmpAlt = true, const uint LstStpNumFirstdisp = 1, const uint LstPrjNumFirstdisp = 1, const uint LstRunNumFirstdisp = 1, const uint LstActNumFirstdisp = 1, const uint LstSepNumFirstdisp = 1, const uint LstSmpNumFirstdisp = 1);

	public:
		uint ixFmncVExpstate;
		bool LstStpAlt;
		bool LstPrjAlt;
		bool LstRunAlt;
		bool LstActAlt;
		bool LstSepAlt;
		bool LstSmpAlt;
		uint LstStpNumFirstdisp;
		uint LstPrjNumFirstdisp;
		uint LstRunNumFirstdisp;
		uint LstActNumFirstdisp;
		uint LstSepNumFirstdisp;
		uint LstSmpNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncNavLabbook)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTSTPAVAIL = 1;
		static const uint BUTSTPVIEWACTIVE = 2;
		static const uint LSTPRJAVAIL = 3;
		static const uint BUTPRJVIEWACTIVE = 4;
		static const uint LSTRUNAVAIL = 5;
		static const uint BUTRUNVIEWACTIVE = 6;
		static const uint LSTACTAVAIL = 7;
		static const uint BUTACTVIEWACTIVE = 8;
		static const uint BUTACTNEWCRDACTIVE = 9;
		static const uint LSTSEPAVAIL = 10;
		static const uint BUTSEPVIEWACTIVE = 11;
		static const uint BUTSEPNEWCRDACTIVE = 12;
		static const uint LSTSMPAVAIL = 13;
		static const uint BUTSMPVIEWACTIVE = 14;

	public:
		StatShr(const bool LstStpAvail = true, const bool ButStpViewActive = true, const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstRunAvail = true, const bool ButRunViewActive = true, const bool LstActAvail = true, const bool ButActViewActive = true, const bool ButActNewcrdActive = true, const bool LstSepAvail = true, const bool ButSepViewActive = true, const bool ButSepNewcrdActive = true, const bool LstSmpAvail = true, const bool ButSmpViewActive = true);

	public:
		bool LstStpAvail;
		bool ButStpViewActive;
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstRunAvail;
		bool ButRunViewActive;
		bool LstActAvail;
		bool ButActViewActive;
		bool ButActNewcrdActive;
		bool LstSepAvail;
		bool ButSepViewActive;
		bool ButSepNewcrdActive;
		bool LstSmpAvail;
		bool ButSmpViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncNavLabbook)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSTP = 2;
		static const uint CPTPRJ = 3;
		static const uint CPTRUN = 4;
		static const uint CPTACT = 5;
		static const uint CPTSEP = 6;
		static const uint CPTSMP = 7;

	public:
		Tag(const string& Cpt = "", const string& CptStp = "", const string& CptPrj = "", const string& CptRun = "", const string& CptAct = "", const string& CptSep = "", const string& CptSmp = "");

	public:
		string Cpt;
		string CptStp;
		string CptPrj;
		string CptRun;
		string CptAct;
		string CptSep;
		string CptSmp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavLabbookData)
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
		* DpchAppDo (full: DpchAppFmncNavLabbookDo)
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
		* DpchEngData (full: DpchEngFmncNavLabbookData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTACT = 3;
		static const uint FEEDFLSTPRJ = 4;
		static const uint FEEDFLSTRUN = 5;
		static const uint FEEDFLSTSEP = 6;
		static const uint FEEDFLSTSMP = 7;
		static const uint FEEDFLSTSTP = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstAct;
		Feed feedFLstPrj;
		Feed feedFLstRun;
		Feed feedFLstSep;
		Feed feedFLstSmp;
		Feed feedFLstStp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

