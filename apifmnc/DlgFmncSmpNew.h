/**
  * \file DlgFmncSmpNew.h
  * API code for job DlgFmncSmpNew (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCSMPNEW_H
#define DLGFMNCSMPNEW_H

#include "ApiFmnc_blks.h"

/**
  * DlgFmncSmpNew
  */
namespace DlgFmncSmpNew {
	/**
		* VecVDo (full: VecVDlgFmncSmpNewDo)
		*/
	class VecVDo {

	public:
		static const uint BUTCNCCLICK = 1;
		static const uint BUTCRECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncSmpNewSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint DONE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgFmncSmpNew)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDETPUPSUP = 1;
		static const uint DETTXFSRF = 2;
		static const uint NUMFDETPUPART = 3;
		static const uint DETTXFMAT = 4;

	public:
		ContIac(const uint numFDetPupSup = 1, const string& DetTxfSrf = "", const uint numFDetPupArt = 1, const string& DetTxfMat = "");

	public:
		uint numFDetPupSup;
		string DetTxfSrf;
		uint numFDetPupArt;
		string DetTxfMat;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgFmncSmpNew)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgFmncSmpNew)
	  */
	class StatApp : public Block {

	public:
		static const uint SHORTMENU = 1;

	public:
		StatApp(const string& shortMenu = "");

	public:
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgFmncSmpNew)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTCNCACTIVE = 1;
		static const uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgFmncSmpNew)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint DETCPTSUP = 2;
		static const uint DETCPTSRF = 3;
		static const uint DETCPTART = 4;
		static const uint DETCPTMAT = 5;
		static const uint BUTCNC = 6;
		static const uint BUTCRE = 7;

	public:
		Tag(const string& Cpt = "", const string& DetCptSup = "", const string& DetCptSrf = "", const string& DetCptArt = "", const string& DetCptMat = "", const string& ButCnc = "", const string& ButCre = "");

	public:
		string Cpt;
		string DetCptSup;
		string DetCptSrf;
		string DetCptArt;
		string DetCptMat;
		string ButCnc;
		string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncSmpNewData)
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
		* DpchAppDo (full: DpchAppDlgFmncSmpNewDo)
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
		* DpchEngData (full: DpchEngDlgFmncSmpNewData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFDETPUPART = 4;
		static const uint FEEDFDETPUPSUP = 5;
		static const uint FEEDFSGE = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFDetPupArt;
		Feed feedFDetPupSup;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

