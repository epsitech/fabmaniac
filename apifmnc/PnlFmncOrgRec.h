/**
  * \file PnlFmncOrgRec.h
  * API code for job PnlFmncOrgRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCORGREC_H
#define PNLFMNCORGREC_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncOrgRec
  */
namespace PnlFmncOrgRec {
	/**
		* VecVDo (full: VecVFmncOrgRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncOrgRec)
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
	  * StatApp (full: StatAppFmncOrgRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEKSTOCKLCN = 2;
		static const uint INITDONEADETAIL = 3;
		static const uint INITDONEBIO1NFABPROJECT = 4;
		static const uint INITDONEMNF1NTOOL = 5;
		static const uint INITDONE1NARTICLE = 6;
		static const uint INITDONEPCO1NPURCHORDER = 7;
		static const uint INITDONESPL1NPURCHORDER = 8;
		static const uint INITDONE1NSTOCKITEM = 9;
		static const uint INITDONESUP1NORG = 10;
		static const uint INITDONEHK1NADDRESS = 11;
		static const uint INITDONEMNPERSON = 12;
		static const uint INITDONESVCMNTOOL = 13;
		static const uint INITDONEMNARTICLE = 14;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKStocklcn = false, const bool initdoneADetail = false, const bool initdoneBio1NFabproject = false, const bool initdoneMnf1NTool = false, const bool initdone1NArticle = false, const bool initdonePco1NPurchorder = false, const bool initdoneSpl1NPurchorder = false, const bool initdone1NStockitem = false, const bool initdoneSup1NOrg = false, const bool initdoneHk1NAddress = false, const bool initdoneMNPerson = false, const bool initdoneSvcMNTool = false, const bool initdoneMNArticle = false);

	public:
		bool initdoneDetail;
		bool initdoneKStocklcn;
		bool initdoneADetail;
		bool initdoneBio1NFabproject;
		bool initdoneMnf1NTool;
		bool initdone1NArticle;
		bool initdonePco1NPurchorder;
		bool initdoneSpl1NPurchorder;
		bool initdone1NStockitem;
		bool initdoneSup1NOrg;
		bool initdoneHk1NAddress;
		bool initdoneMNPerson;
		bool initdoneSvcMNTool;
		bool initdoneMNArticle;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncOrgRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFKSTOCKLCN = 3;
		static const uint SCRJREFADETAIL = 4;
		static const uint SCRJREFBIO1NFABPROJECT = 5;
		static const uint SCRJREFMNF1NTOOL = 6;
		static const uint SCRJREF1NARTICLE = 7;
		static const uint SCRJREFPCO1NPURCHORDER = 8;
		static const uint SCRJREFSPL1NPURCHORDER = 9;
		static const uint SCRJREF1NSTOCKITEM = 10;
		static const uint SCRJREFSUP1NORG = 11;
		static const uint SCRJREFHK1NADDRESS = 12;
		static const uint SCRJREFMNPERSON = 13;
		static const uint SCRJREFSVCMNTOOL = 14;
		static const uint SCRJREFMNARTICLE = 15;
		static const uint BUTREGULARIZEACTIVE = 16;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefKStocklcn = "", const string& scrJrefADetail = "", const string& scrJrefBio1NFabproject = "", const string& scrJrefMnf1NTool = "", const string& scrJref1NArticle = "", const string& scrJrefPco1NPurchorder = "", const string& scrJrefSpl1NPurchorder = "", const string& scrJref1NStockitem = "", const string& scrJrefSup1NOrg = "", const string& scrJrefHk1NAddress = "", const string& scrJrefMNPerson = "", const string& scrJrefSvcMNTool = "", const string& scrJrefMNArticle = "", const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		string scrJrefDetail;
		string scrJrefKStocklcn;
		string scrJrefADetail;
		string scrJrefBio1NFabproject;
		string scrJrefMnf1NTool;
		string scrJref1NArticle;
		string scrJrefPco1NPurchorder;
		string scrJrefSpl1NPurchorder;
		string scrJref1NStockitem;
		string scrJrefSup1NOrg;
		string scrJrefHk1NAddress;
		string scrJrefMNPerson;
		string scrJrefSvcMNTool;
		string scrJrefMNArticle;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncOrgRec)
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
		* DpchAppDo (full: DpchAppFmncOrgRecDo)
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
		* DpchEngData (full: DpchEngFmncOrgRecData)
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

