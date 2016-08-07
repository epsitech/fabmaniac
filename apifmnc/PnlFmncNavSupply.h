/**
  * \file PnlFmncNavSupply.h
  * API code for job PnlFmncNavSupply (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVSUPPLY_H
#define PNLFMNCNAVSUPPLY_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncNavSupply
  */
namespace PnlFmncNavSupply {
	/**
		* VecVDo (full: VecVFmncNavSupplyDo)
		*/
	class VecVDo {

	public:
		static const uint BUTARTVIEWCLICK = 1;
		static const uint BUTARTNEWCRDCLICK = 2;
		static const uint BUTSKIVIEWCLICK = 3;
		static const uint BUTSKINEWCRDCLICK = 4;
		static const uint BUTPCOVIEWCLICK = 5;
		static const uint BUTPCONEWCRDCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavSupply)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTART = 1;
		static const uint NUMFLSTSKI = 2;
		static const uint NUMFLSTPCO = 3;

	public:
		ContIac(const uint numFLstArt = 1, const uint numFLstSki = 1, const uint numFLstPco = 1);

	public:
		uint numFLstArt;
		uint numFLstSki;
		uint numFLstPco;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppFmncNavSupply)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint LSTARTALT = 2;
		static const uint LSTSKIALT = 3;
		static const uint LSTPCOALT = 4;
		static const uint LSTARTNUMFIRSTDISP = 5;
		static const uint LSTSKINUMFIRSTDISP = 6;
		static const uint LSTPCONUMFIRSTDISP = 7;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstArtAlt = true, const bool LstSkiAlt = true, const bool LstPcoAlt = true, const uint LstArtNumFirstdisp = 1, const uint LstSkiNumFirstdisp = 1, const uint LstPcoNumFirstdisp = 1);

	public:
		uint ixFmncVExpstate;
		bool LstArtAlt;
		bool LstSkiAlt;
		bool LstPcoAlt;
		uint LstArtNumFirstdisp;
		uint LstSkiNumFirstdisp;
		uint LstPcoNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncNavSupply)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTARTAVAIL = 1;
		static const uint BUTARTVIEWACTIVE = 2;
		static const uint LSTSKIAVAIL = 3;
		static const uint BUTSKIVIEWACTIVE = 4;
		static const uint LSTPCOAVAIL = 5;
		static const uint BUTPCOVIEWACTIVE = 6;

	public:
		StatShr(const bool LstArtAvail = true, const bool ButArtViewActive = true, const bool LstSkiAvail = true, const bool ButSkiViewActive = true, const bool LstPcoAvail = true, const bool ButPcoViewActive = true);

	public:
		bool LstArtAvail;
		bool ButArtViewActive;
		bool LstSkiAvail;
		bool ButSkiViewActive;
		bool LstPcoAvail;
		bool ButPcoViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncNavSupply)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTART = 2;
		static const uint CPTSKI = 3;
		static const uint CPTPCO = 4;

	public:
		Tag(const string& Cpt = "", const string& CptArt = "", const string& CptSki = "", const string& CptPco = "");

	public:
		string Cpt;
		string CptArt;
		string CptSki;
		string CptPco;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavSupplyData)
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
		* DpchAppDo (full: DpchAppFmncNavSupplyDo)
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
		* DpchEngData (full: DpchEngFmncNavSupplyData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTART = 3;
		static const uint FEEDFLSTPCO = 4;
		static const uint FEEDFLSTSKI = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstArt;
		Feed feedFLstPco;
		Feed feedFLstSki;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

