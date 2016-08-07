/**
  * \file PnlFmncTtyRec.h
  * API code for job PnlFmncTtyRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCTTYREC_H
#define PNLFMNCTTYREC_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncTtyRec
  */
namespace PnlFmncTtyRec {
	/**
		* VecVDo (full: VecVFmncTtyRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncTtyRec)
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
	  * StatApp (full: StatAppFmncTtyRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEKSTEPPAR = 2;
		static const uint INITDONEKTOOLCHAR = 3;
		static const uint INITDONESUP1NTOOLTYPE = 4;
		static const uint INITDONERLV1NSTEP = 5;
		static const uint INITDONEMNTOOL = 6;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKSteppar = false, const bool initdoneKToolchar = false, const bool initdoneSup1NTooltype = false, const bool initdoneRlv1NStep = false, const bool initdoneMNTool = false);

	public:
		bool initdoneDetail;
		bool initdoneKSteppar;
		bool initdoneKToolchar;
		bool initdoneSup1NTooltype;
		bool initdoneRlv1NStep;
		bool initdoneMNTool;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncTtyRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFKSTEPPAR = 3;
		static const uint SCRJREFKTOOLCHAR = 4;
		static const uint SCRJREFSUP1NTOOLTYPE = 5;
		static const uint SCRJREFRLV1NSTEP = 6;
		static const uint SCRJREFMNTOOL = 7;
		static const uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefKSteppar = "", const string& scrJrefKToolchar = "", const string& scrJrefSup1NTooltype = "", const string& scrJrefRlv1NStep = "", const string& scrJrefMNTool = "", const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		string scrJrefDetail;
		string scrJrefKSteppar;
		string scrJrefKToolchar;
		string scrJrefSup1NTooltype;
		string scrJrefRlv1NStep;
		string scrJrefMNTool;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncTtyRec)
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
		* DpchAppDo (full: DpchAppFmncTtyRecDo)
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
		* DpchEngData (full: DpchEngFmncTtyRecData)
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

