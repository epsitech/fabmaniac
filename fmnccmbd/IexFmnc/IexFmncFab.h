/**
  * \file IexFmncFab.h
  * import/export handler for database DbsFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef IEXFMNCFAB_H
#define IEXFMNCFAB_H

/**
	* IexFmncFab
	*/
class IexFmncFab : public JobFmnc {

public:
	/**
		* VecVIme (full: VecVIexFmncFabIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIMTOOL = 1;
		static const uint IMEIAMTOOLAVL = 2;
		static const uint IMEIAMTOOLCHAR = 3;
		static const uint IMEIAVKEYLISTKEY1 = 4;
		static const uint IMEIFABSMPERSONMTOOL = 5;
		static const uint IMEIJMTOOLUNITPRICE = 6;
		static const uint IMEIMARTICLE = 7;
		static const uint IMEIMFILE1 = 8;
		static const uint IMEIMNFSMPERSONMTOOL = 9;
		static const uint IMEIMSTEP = 10;
		static const uint IMEIRMTOOLMTOOLTYPE = 11;
		static const uint IMEISVCRMORGMTOOL = 12;
		static const uint IMEIAMSTEPPAR = 13;
		static const uint IMEIAVKEYLISTKEY2 = 14;
		static const uint IMEIJAVKEYLISTKEY1 = 15;
		static const uint IMEIMFILE2 = 16;
		static const uint IMEIRMARTICLEMORG = 17;
		static const uint IMEISVCTMPERSONMTOOL = 18;
		static const uint IMEIJAVKEYLISTKEY2 = 19;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAMToolAvl (full: ImeitemIFmncFabAMToolAvl)
		*/
	class ImeitemIAMToolAvl : public FmncAMToolAvl {

	public:
		ImeitemIAMToolAvl(const uint x2IxVWkday = 0, const uint x3Startt = 0, const uint x3Stopt = 0, const string& srefKAvltype = "");
		ImeitemIAMToolAvl(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAMToolAvl (full: ImeIFmncFabAMToolAvl)
		*/
	class ImeIAMToolAvl {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabAMToolAvlIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX2IXVWKDAY = 1;
			static const uint FTMX3STARTT = 2;
			static const uint FTMX3STOPT = 4;
			static const uint SREFKAVLTYPE = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMToolAvl();
		~ImeIAMToolAvl();

	public:
		vector<ImeitemIAMToolAvl*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMToolChar (full: ImeitemIFmncFabAMToolChar)
		*/
	class ImeitemIAMToolChar : public FmncAMToolChar {

	public:
		ImeitemIAMToolChar(const string& x1OsrefFmncKToolchar = "", const string& Val = "", const string& Comment = "");
		ImeitemIAMToolChar(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAMToolChar (full: ImeIFmncFabAMToolChar)
		*/
	class ImeIAMToolChar {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabAMToolCharIel)
			*/
		class VecWIel {

		public:
			static const uint X1OSREFFMNCKTOOLCHAR = 1;
			static const uint VAL = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMToolChar();
		~ImeIAMToolChar();

	public:
		vector<ImeitemIAMToolChar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey1 (full: ImeitemIFmncFabJAVKeylistKey1)
		*/
	class ImeitemIJAVKeylistKey1 : public FmncJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey1(const uint x1IxFmncVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey1(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJAVKeylistKey1 (full: ImeIFmncFabJAVKeylistKey1)
		*/
	class ImeIJAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabJAVKeylistKey1Iel)
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
		ImeIJAVKeylistKey1();
		~ImeIJAVKeylistKey1();

	public:
		vector<ImeitemIJAVKeylistKey1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey1 (full: ImeitemIFmncFabAVKeylistKey1)
		*/
	class ImeitemIAVKeylistKey1 : public FmncAVKeylistKey {

	public:
		ImeitemIAVKeylistKey1(const uint klsIxFmncVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey1(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey1 imeijavkeylistkey1;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey1 (full: ImeIFmncFabAVKeylistKey1)
		*/
	class ImeIAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFKLSIXFMNCVKEYLIST = 1;
			static const uint SREF = 2;
			static const uint AVAIL = 4;
			static const uint IMPLIED = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey1();
		~ImeIAVKeylistKey1();

	public:
		vector<ImeitemIAVKeylistKey1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIFabSMPersonMTool (full: ImeitemIFmncFabFabSMPersonMTool)
		*/
	class ImeitemIFabSMPersonMTool : public FmncFabSMPersonMTool {

	public:
		ImeitemIFabSMPersonMTool(const string& hintRefFmncMPerson = "");
		ImeitemIFabSMPersonMTool(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintRefFmncMPerson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIFabSMPersonMTool (full: ImeIFmncFabFabSMPersonMTool)
		*/
	class ImeIFabSMPersonMTool {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabFabSMPersonMToolIel)
			*/
		class VecWIel {

		public:
			static const uint HINTREFFMNCMPERSON = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIFabSMPersonMTool();
		~ImeIFabSMPersonMTool();

	public:
		vector<ImeitemIFabSMPersonMTool*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMToolUnitprice (full: ImeitemIFmncFabJMToolUnitprice)
		*/
	class ImeitemIJMToolUnitprice : public FmncJMToolUnitprice {

	public:
		ImeitemIJMToolUnitprice(const double Unitprice = 0.0);
		ImeitemIJMToolUnitprice(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJMToolUnitprice (full: ImeIFmncFabJMToolUnitprice)
		*/
	class ImeIJMToolUnitprice {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabJMToolUnitpriceIel)
			*/
		class VecWIel {

		public:
			static const uint UNITPRICE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMToolUnitprice();
		~ImeIJMToolUnitprice();

	public:
		vector<ImeitemIJMToolUnitprice*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile2 (full: ImeitemIFmncFabMFile2)
		*/
	class ImeitemIMFile2 : public FmncMFile {

	public:
		ImeitemIMFile2(const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile2(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIMFile2 (full: ImeIFmncFabMFile2)
		*/
	class ImeIMFile2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabMFile2Iel)
			*/
		class VecWIel {

		public:
			static const uint OSREFKCONTENT = 1;
			static const uint FILENAME = 2;
			static const uint SREFKMIMETYPE = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFile2();
		~ImeIMFile2();

	public:
		vector<ImeitemIMFile2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMArticleMOrg (full: ImeitemIFmncFabRMArticleMOrg)
		*/
	class ImeitemIRMArticleMOrg : public FmncRMArticleMOrg {

	public:
		ImeitemIRMArticleMOrg(const string& hsrefRefFmncMOrg = "", const string& Itemno = "");
		ImeitemIRMArticleMOrg(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMOrg;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMArticleMOrg (full: ImeIFmncFabRMArticleMOrg)
		*/
	class ImeIRMArticleMOrg {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabRMArticleMOrgIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMORG = 1;
			static const uint ITEMNO = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMArticleMOrg();
		~ImeIRMArticleMOrg();

	public:
		vector<ImeitemIRMArticleMOrg*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMArticle (full: ImeitemIFmncFabMArticle)
		*/
	class ImeitemIMArticle : public FmncMArticle {

	public:
		ImeitemIMArticle(const string& hsrefRefFmncMOrg = "", const string& sref = "", const string& Title = "", const string& Comment = "");
		ImeitemIMArticle(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMOrg;

		ImeIMFile2 imeimfile2;
		ImeIRMArticleMOrg imeirmarticlemorg;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMArticle (full: ImeIFmncFabMArticle)
		*/
	class ImeIMArticle {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabMArticleIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMORG = 1;
			static const uint SREF = 2;
			static const uint TITLE = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMArticle();
		~ImeIMArticle();

	public:
		vector<ImeitemIMArticle*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile1 (full: ImeitemIFmncFabMFile1)
		*/
	class ImeitemIMFile1 : public FmncMFile {

	public:
		ImeitemIMFile1(const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile1(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIMFile1 (full: ImeIFmncFabMFile1)
		*/
	class ImeIMFile1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabMFile1Iel)
			*/
		class VecWIel {

		public:
			static const uint OSREFKCONTENT = 1;
			static const uint FILENAME = 2;
			static const uint SREFKMIMETYPE = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFile1();
		~ImeIMFile1();

	public:
		vector<ImeitemIMFile1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMnfSMPersonMTool (full: ImeitemIFmncFabMnfSMPersonMTool)
		*/
	class ImeitemIMnfSMPersonMTool : public FmncMnfSMPersonMTool {

	public:
		ImeitemIMnfSMPersonMTool(const string& hintRefFmncMPerson = "");
		ImeitemIMnfSMPersonMTool(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintRefFmncMPerson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMnfSMPersonMTool (full: ImeIFmncFabMnfSMPersonMTool)
		*/
	class ImeIMnfSMPersonMTool {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabMnfSMPersonMToolIel)
			*/
		class VecWIel {

		public:
			static const uint HINTREFFMNCMPERSON = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMnfSMPersonMTool();
		~ImeIMnfSMPersonMTool();

	public:
		vector<ImeitemIMnfSMPersonMTool*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMStepPar (full: ImeitemIFmncFabAMStepPar)
		*/
	class ImeitemIAMStepPar : public FmncAMStepPar {

	public:
		ImeitemIAMStepPar(const string& x1OsrefFmncKSteppar = "", const string& Val = "", const string& Comment = "");
		ImeitemIAMStepPar(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAMStepPar (full: ImeIFmncFabAMStepPar)
		*/
	class ImeIAMStepPar {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabAMStepParIel)
			*/
		class VecWIel {

		public:
			static const uint X1OSREFFMNCKSTEPPAR = 1;
			static const uint VAL = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMStepPar();
		~ImeIAMStepPar();

	public:
		vector<ImeitemIAMStepPar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey2 (full: ImeitemIFmncFabJAVKeylistKey2)
		*/
	class ImeitemIJAVKeylistKey2 : public FmncJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey2(const uint x1IxFmncVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey2(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJAVKeylistKey2 (full: ImeIFmncFabJAVKeylistKey2)
		*/
	class ImeIJAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabJAVKeylistKey2Iel)
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
		ImeIJAVKeylistKey2();
		~ImeIJAVKeylistKey2();

	public:
		vector<ImeitemIJAVKeylistKey2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey2 (full: ImeitemIFmncFabAVKeylistKey2)
		*/
	class ImeitemIAVKeylistKey2 : public FmncAVKeylistKey {

	public:
		ImeitemIAVKeylistKey2(const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey2(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey2 imeijavkeylistkey2;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey2 (full: ImeIFmncFabAVKeylistKey2)
		*/
	class ImeIAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabAVKeylistKey2Iel)
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
		ImeIAVKeylistKey2();
		~ImeIAVKeylistKey2();

	public:
		vector<ImeitemIAVKeylistKey2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMStep (full: ImeitemIFmncFabMStep)
		*/
	class ImeitemIMStep : public FmncMStep {

	public:
		ImeitemIMStep(const uint ixWFilecfg = 0, const string& Title = "");
		ImeitemIMStep(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMStepPar imeiamsteppar;
		ImeIAVKeylistKey2 imeiavkeylistkey2;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMStep (full: ImeIFmncFabMStep)
		*/
	class ImeIMStep {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabMStepIel)
			*/
		class VecWIel {

		public:
			static const uint SREFSIXWFILECFG = 1;
			static const uint TITLE = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMStep();
		~ImeIMStep();

	public:
		vector<ImeitemIMStep*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMToolMTooltype (full: ImeitemIFmncFabRMToolMTooltype)
		*/
	class ImeitemIRMToolMTooltype : public FmncRMToolMTooltype {

	public:
		ImeitemIRMToolMTooltype(const string& hsrefRefFmncMTooltype = "", const string& srefsFmncKToolchar = "", const string& defSrefsFmncKSteppar = "", const string& optSrefsFmncKSteppar = "");
		ImeitemIRMToolMTooltype(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMTooltype;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMToolMTooltype (full: ImeIFmncFabRMToolMTooltype)
		*/
	class ImeIRMToolMTooltype {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabRMToolMTooltypeIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMTOOLTYPE = 1;
			static const uint SREFSFMNCKTOOLCHAR = 2;
			static const uint DEFSREFSFMNCKSTEPPAR = 4;
			static const uint OPTSREFSFMNCKSTEPPAR = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMToolMTooltype();
		~ImeIRMToolMTooltype();

	public:
		vector<ImeitemIRMToolMTooltype*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemISvcTMPersonMTool (full: ImeitemIFmncFabSvcTMPersonMTool)
		*/
	class ImeitemISvcTMPersonMTool : public FmncSvcTMPersonMTool {

	public:
		ImeitemISvcTMPersonMTool(const string& hintRefFmncMPerson = "");
		ImeitemISvcTMPersonMTool(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintRefFmncMPerson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeISvcTMPersonMTool (full: ImeIFmncFabSvcTMPersonMTool)
		*/
	class ImeISvcTMPersonMTool {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabSvcTMPersonMToolIel)
			*/
		class VecWIel {

		public:
			static const uint HINTREFFMNCMPERSON = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeISvcTMPersonMTool();
		~ImeISvcTMPersonMTool();

	public:
		vector<ImeitemISvcTMPersonMTool*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemISvcRMOrgMTool (full: ImeitemIFmncFabSvcRMOrgMTool)
		*/
	class ImeitemISvcRMOrgMTool : public FmncSvcRMOrgMTool {

	public:
		ImeitemISvcRMOrgMTool(const string& hsrefRefFmncMOrg = "");
		ImeitemISvcRMOrgMTool(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMOrg;

		ImeISvcTMPersonMTool imeisvctmpersonmtool;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeISvcRMOrgMTool (full: ImeIFmncFabSvcRMOrgMTool)
		*/
	class ImeISvcRMOrgMTool {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabSvcRMOrgMToolIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMORG = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeISvcRMOrgMTool();
		~ImeISvcRMOrgMTool();

	public:
		vector<ImeitemISvcRMOrgMTool*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMTool (full: ImeitemIFmncFabMTool)
		*/
	class ImeitemIMTool : public FmncMTool {

	public:
		ImeitemIMTool(const string& hintFabRefFmncMFab = "", const string& hsrefMnfRefFmncMOrg = "", const string& Title = "", const string& Training = "", const string& Comment = "");
		ImeitemIMTool(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintFabRefFmncMFab;
		string hsrefMnfRefFmncMOrg;

		ImeIAMToolAvl imeiamtoolavl;
		ImeIAMToolChar imeiamtoolchar;
		ImeIAVKeylistKey1 imeiavkeylistkey1;
		ImeIFabSMPersonMTool imeifabsmpersonmtool;
		ImeIJMToolUnitprice imeijmtoolunitprice;
		ImeIMArticle imeimarticle;
		ImeIMFile1 imeimfile1;
		ImeIMnfSMPersonMTool imeimnfsmpersonmtool;
		ImeIMStep imeimstep;
		ImeIRMToolMTooltype imeirmtoolmtooltype;
		ImeISvcRMOrgMTool imeisvcrmorgmtool;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTool (full: ImeIFmncFabMTool)
		*/
	class ImeIMTool {

	public:
		/**
			* VecWIel (full: VecWImeIFmncFabMToolIel)
			*/
		class VecWIel {

		public:
			static const uint HINTFABREFFMNCMFAB = 1;
			static const uint HSREFMNFREFFMNCMORG = 2;
			static const uint TITLE = 4;
			static const uint TRAINING = 8;
			static const uint COMMENT = 16;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMTool();
		~ImeIMTool();

	public:
		vector<ImeitemIMTool*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexFmncFab(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
	~IexFmncFab();

public:
	uint lineno;
	uint impcnt;

	ImeIMTool imeimtool;

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


