/**
  * \file PnlFmncStpRec.h
  * API code for job PnlFmncStpRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSTPREC_H
#define PNLFMNCSTPREC_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncStpRec
  */
namespace PnlFmncStpRec {
	/**
		* VecVDo (full: VecVFmncStpRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncStpRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppFmncStpRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEKSTEPPAR = 2;
		static const uint INITDONEAPAR = 3;
		static const uint INITDONEREF1NFILE = 4;
		static const uint INITDONETPL1NSTEP = 5;
		static const uint INITDONEMNFILE = 6;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKSteppar = false, const bool initdoneAPar = false, const bool initdoneRef1NFile = false, const bool initdoneTpl1NStep = false, const bool initdoneMNFile = false);

	public:
		bool initdoneDetail;
		bool initdoneKSteppar;
		bool initdoneAPar;
		bool initdoneRef1NFile;
		bool initdoneTpl1NStep;
		bool initdoneMNFile;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncStpRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFKSTEPPAR = 3;
		static const uint SCRJREFAPAR = 4;
		static const uint SCRJREFREF1NFILE = 5;
		static const uint SCRJREFTPL1NSTEP = 6;
		static const uint SCRJREFMNFILE = 7;
		static const uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefKSteppar = "", const string& scrJrefAPar = "", const string& scrJrefRef1NFile = "", const string& scrJrefTpl1NStep = "", const string& scrJrefMNFile = "", const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		string scrJrefDetail;
		string scrJrefKSteppar;
		string scrJrefAPar;
		string scrJrefRef1NFile;
		string scrJrefTpl1NStep;
		string scrJrefMNFile;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncStpRec)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;

	public:
		Tag(const string& Cpt = "");

	public:
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppFmncStpRecDo)
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
		* DpchEngData (full: DpchEngFmncStpRecData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

