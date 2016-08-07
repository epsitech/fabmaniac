/**
  * \file PnlFmncNavAdmin.h
  * API code for job PnlFmncNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVADMIN_H
#define PNLFMNCNAVADMIN_H

#include "ApiFmnc_blks.h"

/**
  * PnlFmncNavAdmin
  */
namespace PnlFmncNavAdmin {
	/**
		* VecVDo (full: VecVFmncNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTORGVIEWCLICK = 5;
		static const uint BUTORGNEWCRDCLICK = 6;
		static const uint BUTPRSVIEWCLICK = 7;
		static const uint BUTPRSNEWCRDCLICK = 8;
		static const uint BUTADRVIEWCLICK = 9;
		static const uint BUTADRNEWCRDCLICK = 10;
		static const uint BUTFILVIEWCLICK = 11;
		static const uint BUTFILNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTORG = 3;
		static const uint NUMFLSTPRS = 4;
		static const uint NUMFLSTADR = 5;
		static const uint NUMFLSTFIL = 6;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstOrg = 1, const uint numFLstPrs = 1, const uint numFLstAdr = 1, const uint numFLstFil = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstOrg;
		uint numFLstPrs;
		uint numFLstAdr;
		uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppFmncNavAdmin)
	  */
	class StatApp : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint LSTUSGALT = 2;
		static const uint LSTUSRALT = 3;
		static const uint LSTORGALT = 4;
		static const uint LSTPRSALT = 5;
		static const uint LSTADRALT = 6;
		static const uint LSTFILALT = 7;
		static const uint LSTUSGNUMFIRSTDISP = 8;
		static const uint LSTUSRNUMFIRSTDISP = 9;
		static const uint LSTORGNUMFIRSTDISP = 10;
		static const uint LSTPRSNUMFIRSTDISP = 11;
		static const uint LSTADRNUMFIRSTDISP = 12;
		static const uint LSTFILNUMFIRSTDISP = 13;

	public:
		StatApp(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstOrgAlt = true, const bool LstPrsAlt = true, const bool LstAdrAlt = true, const bool LstFilAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstOrgNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1, const uint LstAdrNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1);

	public:
		uint ixFmncVExpstate;
		bool LstUsgAlt;
		bool LstUsrAlt;
		bool LstOrgAlt;
		bool LstPrsAlt;
		bool LstAdrAlt;
		bool LstFilAlt;
		uint LstUsgNumFirstdisp;
		uint LstUsrNumFirstdisp;
		uint LstOrgNumFirstdisp;
		uint LstPrsNumFirstdisp;
		uint LstAdrNumFirstdisp;
		uint LstFilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrFmncNavAdmin)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTORGAVAIL = 5;
		static const uint BUTORGVIEWACTIVE = 6;
		static const uint LSTPRSAVAIL = 7;
		static const uint BUTPRSVIEWACTIVE = 8;
		static const uint LSTADRAVAIL = 9;
		static const uint BUTADRVIEWACTIVE = 10;
		static const uint LSTFILAVAIL = 11;
		static const uint BUTFILVIEWACTIVE = 12;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstOrgAvail = true, const bool ButOrgViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstAdrAvail = true, const bool ButAdrViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstOrgAvail;
		bool ButOrgViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstAdrAvail;
		bool ButAdrViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagFmncNavAdmin)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTUSG = 2;
		static const uint CPTUSR = 3;
		static const uint CPTORG = 4;
		static const uint CPTPRS = 5;
		static const uint CPTADR = 6;
		static const uint CPTFIL = 7;

	public:
		Tag(const string& Cpt = "", const string& CptUsg = "", const string& CptUsr = "", const string& CptOrg = "", const string& CptPrs = "", const string& CptAdr = "", const string& CptFil = "");

	public:
		string Cpt;
		string CptUsg;
		string CptUsr;
		string CptOrg;
		string CptPrs;
		string CptAdr;
		string CptFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavAdminData)
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
		* DpchAppDo (full: DpchAppFmncNavAdminDo)
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
		* DpchEngData (full: DpchEngFmncNavAdminData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTADR = 3;
		static const uint FEEDFLSTFIL = 4;
		static const uint FEEDFLSTORG = 5;
		static const uint FEEDFLSTPRS = 6;
		static const uint FEEDFLSTUSG = 7;
		static const uint FEEDFLSTUSR = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstAdr;
		Feed feedFLstFil;
		Feed feedFLstOrg;
		Feed feedFLstPrs;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

