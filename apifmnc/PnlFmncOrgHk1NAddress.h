/**
  * \file PnlFmncOrgHk1NAddress.h
  * API code for job PnlFmncOrgHk1NAddress (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCORGHK1NADDRESS_H
#define PNLFMNCORGHK1NADDRESS_H

#include "ApiFmnc_blks.h"

#include "FmncQOrgHk1NAddress.h"

#include "QryFmncOrgHk1NAddress.h"

/**
  * PnlFmncOrgHk1NAddress
  */
namespace PnlFmncOrgHk1NAddress {
	/**
		* VecVDo (full: VecVFmncOrgHk1NAddressDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTNEWCLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncOrgHk1NAddress)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncOrgHk1NAddress)
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
	  * StatShr (full: StatShrFmncOrgHk1NAddress)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTVIEWACTIVE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const bool ButViewActive = true, const bool ButDeleteActive = true);

	public:
		bool ButViewActive;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacFmncOrgHk1NAddress)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagFmncOrgHk1NAddress)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRef = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncOrgHk1NAddressData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryFmncOrgHk1NAddress::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryFmncOrgHk1NAddress::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppFmncOrgHk1NAddressDo)
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
		* DpchEngData (full: DpchEngFmncOrgHk1NAddressData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListFmncQOrgHk1NAddress rst;
		QryFmncOrgHk1NAddress::StatApp statappqry;
		QryFmncOrgHk1NAddress::StatShr statshrqry;
		QryFmncOrgHk1NAddress::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif
