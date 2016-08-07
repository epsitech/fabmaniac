/**
  * \file PnlFmncTolRec.h
  * API code for job PnlFmncTolRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCTOLREC_H
#define PNLFMNCTOLREC_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncTolRec
  */
namespace PnlFmncTolRec {
	/**
		* VecVDo (full: VecVFmncTolRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncTolRec)
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
	  * StatApp (full: StatAppFmncTolRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEKSTEPPAR = 2;
		static const uint INITDONEKTOOLCHAR = 3;
		static const uint INITDONEAAVL = 4;
		static const uint INITDONEACHAR = 5;
		static const uint INITDONEARES = 6;
		static const uint INITDONEAUTIL = 7;
		static const uint INITDONE1NARTICLE = 8;
		static const uint INITDONERLV1NSTEP = 9;
		static const uint INITDONEREF1NFILE = 10;
		static const uint INITDONEMNTOOLTYPE = 11;
		static const uint INITDONEMNFABUSER = 12;
		static const uint INITDONESVCMNORG = 13;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKSteppar = false, const bool initdoneKToolchar = false, const bool initdoneAAvl = false, const bool initdoneAChar = false, const bool initdoneARes = false, const bool initdoneAUtil = false, const bool initdone1NArticle = false, const bool initdoneRlv1NStep = false, const bool initdoneRef1NFile = false, const bool initdoneMNTooltype = false, const bool initdoneMNFabuser = false, const bool initdoneSvcMNOrg = false);

	public:
		bool initdoneDetail;
		bool initdoneKSteppar;
		bool initdoneKToolchar;
		bool initdoneAAvl;
		bool initdoneAChar;
		bool initdoneARes;
		bool initdoneAUtil;
		bool initdone1NArticle;
		bool initdoneRlv1NStep;
		bool initdoneRef1NFile;
		bool initdoneMNTooltype;
		bool initdoneMNFabuser;
		bool initdoneSvcMNOrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncTolRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFKSTEPPAR = 3;
		static const uint SCRJREFKTOOLCHAR = 4;
		static const uint SCRJREFAAVL = 5;
		static const uint SCRJREFACHAR = 6;
		static const uint SCRJREFARES = 7;
		static const uint SCRJREFAUTIL = 8;
		static const uint SCRJREF1NARTICLE = 9;
		static const uint SCRJREFRLV1NSTEP = 10;
		static const uint SCRJREFREF1NFILE = 11;
		static const uint SCRJREFMNTOOLTYPE = 12;
		static const uint SCRJREFMNFABUSER = 13;
		static const uint SCRJREFSVCMNORG = 14;
		static const uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefKSteppar = "", const string& scrJrefKToolchar = "", const string& scrJrefAAvl = "", const string& scrJrefAChar = "", const string& scrJrefARes = "", const string& scrJrefAUtil = "", const string& scrJref1NArticle = "", const string& scrJrefRlv1NStep = "", const string& scrJrefRef1NFile = "", const string& scrJrefMNTooltype = "", const string& scrJrefMNFabuser = "", const string& scrJrefSvcMNOrg = "", const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		string scrJrefDetail;
		string scrJrefKSteppar;
		string scrJrefKToolchar;
		string scrJrefAAvl;
		string scrJrefAChar;
		string scrJrefARes;
		string scrJrefAUtil;
		string scrJref1NArticle;
		string scrJrefRlv1NStep;
		string scrJrefRef1NFile;
		string scrJrefMNTooltype;
		string scrJrefMNFabuser;
		string scrJrefSvcMNOrg;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncTolRec)
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
		* DpchAppDo (full: DpchAppFmncTolRecDo)
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
		* DpchEngData (full: DpchEngFmncTolRecData)
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

