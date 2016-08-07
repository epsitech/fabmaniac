/**
  * \file PnlFmncSmpRec.h
  * API code for job PnlFmncSmpRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSMPREC_H
#define PNLFMNCSMPREC_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncSmpRec
  */
namespace PnlFmncSmpRec {
	/**
		* VecVDo (full: VecVFmncSmpRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncSmpRec)
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
	  * StatApp (full: StatAppFmncSmpRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEAPAR = 2;
		static const uint INITDONESUP1NSAMPLE = 3;
		static const uint INITDONEREF1NFILE = 4;
		static const uint INITDONEMNSTEP = 5;
		static const uint INITDONEMNFILE = 6;
		static const uint INITDONEMNRUN = 7;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneSup1NSample = false, const bool initdoneRef1NFile = false, const bool initdoneMNStep = false, const bool initdoneMNFile = false, const bool initdoneMNRun = false);

	public:
		bool initdoneDetail;
		bool initdoneAPar;
		bool initdoneSup1NSample;
		bool initdoneRef1NFile;
		bool initdoneMNStep;
		bool initdoneMNFile;
		bool initdoneMNRun;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncSmpRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFAPAR = 3;
		static const uint SCRJREFSUP1NSAMPLE = 4;
		static const uint SCRJREFREF1NFILE = 5;
		static const uint SCRJREFMNSTEP = 6;
		static const uint SCRJREFMNFILE = 7;
		static const uint SCRJREFMNRUN = 8;
		static const uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefAPar = "", const string& scrJrefSup1NSample = "", const string& scrJrefRef1NFile = "", const string& scrJrefMNStep = "", const string& scrJrefMNFile = "", const string& scrJrefMNRun = "", const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		string scrJrefDetail;
		string scrJrefAPar;
		string scrJrefSup1NSample;
		string scrJrefRef1NFile;
		string scrJrefMNStep;
		string scrJrefMNFile;
		string scrJrefMNRun;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncSmpRec)
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
		* DpchAppDo (full: DpchAppFmncSmpRecDo)
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
		* DpchEngData (full: DpchEngFmncSmpRecData)
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

