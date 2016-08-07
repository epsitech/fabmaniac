/**
  * \file PnlFmncFilMNStep.h
  * API code for job PnlFmncFilMNStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCFILMNSTEP_H
#define PNLFMNCFILMNSTEP_H

#include "ApiFmnc_blks.h"

#include "FmncQFilMNStep.h"

#include "QryFmncFilMNStep.h"

/**
  * PnlFmncFilMNStep
  */
namespace PnlFmncFilMNStep {
	/**
		* VecVDo (full: VecVFmncFilMNStepDo)
		*/
	class VecVDo {

	public:
		static const uint BUTADDCLICK = 1;
		static const uint BUTSUBCLICK = 2;
		static const uint BUTREFRESHCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncFilMNStep)
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
	  * StatApp (full: StatAppFmncFilMNStep)
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
	  * StatShr (full: StatShrFmncFilMNStep)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSUBACTIVE = 1;

	public:
		StatShr(const bool ButSubActive = true);

	public:
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacFmncFilMNStep)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOTSMPWIDTH = 2;
		static const uint TCODIRWIDTH = 3;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoTsmpWidth = 100, const uint TcoDirWidth = 100);

	public:
		uint TcoMrefWidth;
		uint TcoTsmpWidth;
		uint TcoDirWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagFmncFilMNStep)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOMREF = 5;
		static const uint TCOTSMP = 6;
		static const uint TCODIR = 7;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "", const string& TcoTsmp = "", const string& TcoDir = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;
		string TcoTsmp;
		string TcoDir;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncFilMNStepData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryFmncFilMNStep::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryFmncFilMNStep::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppFmncFilMNStepDo)
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
		* DpchEngData (full: DpchEngFmncFilMNStepData)
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
		ListFmncQFilMNStep rst;
		QryFmncFilMNStep::StatApp statappqry;
		QryFmncFilMNStep::StatShr statshrqry;
		QryFmncFilMNStep::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

