/**
  * \file IexFmncOrg.h
  * import/export handler for database DbsFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef IEXFMNCORG_H
#define IEXFMNCORG_H

/**
	* IexFmncOrg
	*/
class IexFmncOrg : public JobFmnc {

public:
	/**
		* VecVIme (full: VecVIexFmncOrgIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIMORG = 1;
		static const uint IMEIMPERSON = 2;
		static const uint IMEIRMORGMPERSON = 3;
		static const uint IMEIAMORGDETAIL = 4;
		static const uint IMEIAMPERSONDETAIL = 5;
		static const uint IMEIAVKEYLISTKEY = 6;
		static const uint IMEIJMORGTITLE = 7;
		static const uint IMEIJMPERSONLASTNAME = 8;
		static const uint IMEIMADDRESS1 = 9;
		static const uint IMEIMADDRESS2 = 10;
		static const uint IMEIJAVKEYLISTKEY = 11;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAMOrgDetail (full: ImeitemIFmncOrgAMOrgDetail)
		*/
	class ImeitemIAMOrgDetail : public FmncAMOrgDetail {

	public:
		ImeitemIAMOrgDetail(const string& x1SrefKType = "", const string& Val = "");
		ImeitemIAMOrgDetail(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMOrgDetail (full: ImeIFmncOrgAMOrgDetail)
		*/
	class ImeIAMOrgDetail {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgAMOrgDetailIel)
			*/
		class VecWIel {

		public:
			static const uint X1SREFKTYPE = 1;
			static const uint VAL = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMOrgDetail();
		~ImeIAMOrgDetail();

	public:
		vector<ImeitemIAMOrgDetail*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIFmncOrgJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public FmncJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const uint x1IxFmncVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey (full: ImeIFmncOrgJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgJAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXFMNCVLOCALE = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIFmncOrgAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public FmncAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIFmncOrgAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint AVAIL = 2;
			static const uint IMPLIED = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMOrgTitle (full: ImeitemIFmncOrgJMOrgTitle)
		*/
	class ImeitemIJMOrgTitle : public FmncJMOrgTitle {

	public:
		ImeitemIJMOrgTitle(const string& Title = "");
		ImeitemIJMOrgTitle(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMOrgTitle (full: ImeIFmncOrgJMOrgTitle)
		*/
	class ImeIJMOrgTitle {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgJMOrgTitleIel)
			*/
		class VecWIel {

		public:
			static const uint TITLE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMOrgTitle();
		~ImeIJMOrgTitle();

	public:
		vector<ImeitemIJMOrgTitle*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMAddress1 (full: ImeitemIFmncOrgMAddress1)
		*/
	class ImeitemIMAddress1 : public FmncMAddress {

	public:
		ImeitemIMAddress1(const string& srefKAdrtype = "", const string& Address1 = "", const string& Address2 = "", const string& Zipcode = "", const string& City = "", const string& State = "", const string& srefKCountry = "");
		ImeitemIMAddress1(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMAddress1 (full: ImeIFmncOrgMAddress1)
		*/
	class ImeIMAddress1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgMAddress1Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFKADRTYPE = 1;
			static const uint ADDRESS1 = 2;
			static const uint ADDRESS2 = 4;
			static const uint ZIPCODE = 8;
			static const uint CITY = 16;
			static const uint STATE = 32;
			static const uint SREFKCOUNTRY = 64;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMAddress1();
		~ImeIMAddress1();

	public:
		vector<ImeitemIMAddress1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMOrg (full: ImeitemIFmncOrgMOrg)
		*/
	class ImeitemIMOrg : public FmncMOrg {

	public:
		ImeitemIMOrg(const uint ixWDerivate = 0, const string& hsrefSupRefFmncMOrg = "", const string& sref = "");
		ImeitemIMOrg(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefSupRefFmncMOrg;

		ImeIAMOrgDetail imeiamorgdetail;
		ImeIAVKeylistKey imeiavkeylistkey;
		ImeIJMOrgTitle imeijmorgtitle;
		ImeIMAddress1 imeimaddress1;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMOrg (full: ImeIFmncOrgMOrg)
		*/
	class ImeIMOrg {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgMOrgIel)
			*/
		class VecWIel {

		public:
			static const uint SREFSIXWDERIVATE = 1;
			static const uint HSREFSUPREFFMNCMORG = 2;
			static const uint SREF = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMOrg();
		~ImeIMOrg();

	public:
		vector<ImeitemIMOrg*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMPersonDetail (full: ImeitemIFmncOrgAMPersonDetail)
		*/
	class ImeitemIAMPersonDetail : public FmncAMPersonDetail {

	public:
		ImeitemIAMPersonDetail(const string& x1SrefKType = "", const string& Val = "");
		ImeitemIAMPersonDetail(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMPersonDetail (full: ImeIFmncOrgAMPersonDetail)
		*/
	class ImeIAMPersonDetail {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgAMPersonDetailIel)
			*/
		class VecWIel {

		public:
			static const uint X1SREFKTYPE = 1;
			static const uint VAL = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMPersonDetail();
		~ImeIAMPersonDetail();

	public:
		vector<ImeitemIAMPersonDetail*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIFmncOrgJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public FmncJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const string& Lastname = "");
		ImeitemIJMPersonLastname(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIFmncOrgJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const uint LASTNAME = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMAddress2 (full: ImeitemIFmncOrgMAddress2)
		*/
	class ImeitemIMAddress2 : public FmncMAddress {

	public:
		ImeitemIMAddress2(const string& srefKAdrtype = "", const string& Address1 = "", const string& Address2 = "", const string& Zipcode = "", const string& City = "", const string& State = "", const string& srefKCountry = "");
		ImeitemIMAddress2(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMAddress2 (full: ImeIFmncOrgMAddress2)
		*/
	class ImeIMAddress2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgMAddress2Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFKADRTYPE = 1;
			static const uint ADDRESS1 = 2;
			static const uint ADDRESS2 = 4;
			static const uint ZIPCODE = 8;
			static const uint CITY = 16;
			static const uint STATE = 32;
			static const uint SREFKCOUNTRY = 64;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMAddress2();
		~ImeIMAddress2();

	public:
		vector<ImeitemIMAddress2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIFmncOrgMPerson)
		*/
	class ImeitemIMPerson : public FmncMPerson {

	public:
		ImeitemIMPerson(const ubigint iref = 0, const uint ixVSex = 0, const string& Title = "", const string& Firstname = "");
		ImeitemIMPerson(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;

		ImeIAMPersonDetail imeiampersondetail;
		ImeIJMPersonLastname imeijmpersonlastname;
		ImeIMAddress2 imeimaddress2;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIFmncOrgMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgMPersonIel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint SREFIXVSEX = 2;
			static const uint TITLE = 4;
			static const uint FIRSTNAME = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMOrgMPerson (full: ImeitemIFmncOrgRMOrgMPerson)
		*/
	class ImeitemIRMOrgMPerson : public FmncRMOrgMPerson {

	public:
		ImeitemIRMOrgMPerson(const ubigint irefRefFmncMPerson = 0, const string& hsrefRefFmncMOrg = "", const string& srefKFunction = "");
		ImeitemIRMOrgMPerson(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint irefRefFmncMPerson;
		string hsrefRefFmncMOrg;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMOrgMPerson (full: ImeIFmncOrgRMOrgMPerson)
		*/
	class ImeIRMOrgMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIFmncOrgRMOrgMPersonIel)
			*/
		class VecWIel {

		public:
			static const uint IREFREFFMNCMPERSON = 1;
			static const uint HSREFREFFMNCMORG = 2;
			static const uint SREFKFUNCTION = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMOrgMPerson();
		~ImeIRMOrgMPerson();

	public:
		vector<ImeitemIRMOrgMPerson*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexFmncOrg(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
	~IexFmncOrg();

public:
	uint lineno;
	uint impcnt;

	ImeIMOrg imeimorg;
	ImeIMPerson imeimperson;
	ImeIRMOrgMPerson imeirmorgmperson;

public:
// IP cust --- INSERT

public:
	void reset();

	void import(DbsFmnc* dbsfmnc);

	void collect(DbsFmnc* dbsfmnc, const map<uint,uint>& icsDartVIop = icsFmncVIopInsAll());

public:
	bool readTxt(Txtrd& txtrd);
	void readXML(xmlXPathContext* docctx, string basexpath);

	bool readTxtFile(const string& fullpath);
	bool readXMLFile(const string& fullpath);

	void writeTxt(fstream& outfile);
	void writeXML(xmlTextWriter* wr, const bool shorttags);

	void writeTxtFile(const string& fullpath);
	void writeXMLFile(const string& fullpath, const bool shorttags);

	static map<uint,uint> icsFmncVIopInsAll();
	uint getIxFmncVIop(const map<uint,uint>& icsFmncVIop, const uint ixVIme, uint& ixFmncVIop);

public:
	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleCall(DbsFmnc* dbsfmnc, Call* call);
};

#endif


