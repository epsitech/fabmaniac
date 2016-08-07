/**
  * \file PnlFmncRunRec.h
  * API code for job PnlFmncRunRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCRUNREC_H
#define PNLFMNCRUNREC_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncRunRec
  */
namespace PnlFmncRunRec {
	/**
		* VecVDo (full: VecVFmncRunRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncRunRec)
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
	  * StatApp (full: StatAppFmncRunRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONERUN1NACTIVITY = 2;
		static const uint INITDONEREF1NFILE = 3;
		static const uint INITDONEMNSAMPLE = 4;
		static const uint INITDONEMNPERSON = 5;
		static const uint INITDONEMNFAB = 6;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneRun1NActivity = false, const bool initdoneRef1NFile = false, const bool initdoneMNSample = false, const bool initdoneMNPerson = false, const bool initdoneMNFab = false);

	public:
		bool initdoneDetail;
		bool initdoneRun1NActivity;
		bool initdoneRef1NFile;
		bool initdoneMNSample;
		bool initdoneMNPerson;
		bool initdoneMNFab;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncRunRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFRUN1NACTIVITY = 3;
		static const uint SCRJREFREF1NFILE = 4;
		static const uint SCRJREFMNSAMPLE = 5;
		static const uint SCRJREFMNPERSON = 6;
		static const uint SCRJREFMNFAB = 7;
		static const uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefRun1NActivity = "", const string& scrJrefRef1NFile = "", const string& scrJrefMNSample = "", const string& scrJrefMNPerson = "", const string& scrJrefMNFab = "", const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		string scrJrefDetail;
		string scrJrefRun1NActivity;
		string scrJrefRef1NFile;
		string scrJrefMNSample;
		string scrJrefMNPerson;
		string scrJrefMNFab;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncRunRec)
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
		* DpchAppDo (full: DpchAppFmncRunRecDo)
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
		* DpchEngData (full: DpchEngFmncRunRecData)
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

