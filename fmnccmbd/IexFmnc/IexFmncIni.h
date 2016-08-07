/**
  * \file IexFmncIni.h
  * import/export handler for database DbsFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef IEXFMNCINI_H
#define IEXFMNCINI_H

/**
	* IexFmncIni
	*/
class IexFmncIni : public JobFmnc {

public:
	/**
		* VecVIme (full: VecVIexFmncIniIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIAVCONTROLPAR = 1;
		static const uint IMEIAVKEYLISTKEY1 = 2;
		static const uint IMEIAVVALUELISTVAL = 3;
		static const uint IMEIMTOOLTYPE = 4;
		static const uint IMEIMUSERGROUP = 5;
		static const uint IMEIAMUSERGROUPACCESS = 6;
		static const uint IMEIAVKEYLISTKEY2 = 7;
		static const uint IMEIJAVKEYLISTKEY1 = 8;
		static const uint IMEIMSTEP = 9;
		static const uint IMEIMUSER = 10;
		static const uint IMEIAMSTEPPAR = 11;
		static const uint IMEIAVKEYLISTKEY3 = 12;
		static const uint IMEIJAVKEYLISTKEY2 = 13;
		static const uint IMEIJMUSERSTATE = 14;
		static const uint IMEIMPERSON = 15;
		static const uint IMEIAMPERSONDETAIL = 16;
		static const uint IMEIJAVKEYLISTKEY3 = 17;
		static const uint IMEIJMPERSONLASTNAME = 18;
		static const uint IMEIMADDRESS = 19;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAVControlPar (full: ImeitemIFmncIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public FmncAVControlPar {

	public:
		ImeitemIAVControlPar(const uint ixFmncVControl = 0, const string& Par = "", const string& Val = "");
		ImeitemIAVControlPar(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAVControlPar (full: ImeIFmncIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXFMNCVCONTROL = 1;
			static const uint PAR = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey1 (full: ImeitemIFmncIniJAVKeylistKey1)
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
		* ImeIJAVKeylistKey1 (full: ImeIFmncIniJAVKeylistKey1)
		*/
	class ImeIJAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniJAVKeylistKey1Iel)
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
		* ImeitemIAVKeylistKey1 (full: ImeitemIFmncIniAVKeylistKey1)
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
		* ImeIAVKeylistKey1 (full: ImeIFmncIniAVKeylistKey1)
		*/
	class ImeIAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAVKeylistKey1Iel)
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
		* ImeitemIAVValuelistVal (full: ImeitemIFmncIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public FmncAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const uint vlsIxFmncVValuelist = 0, const uint x1IxFmncVLocale = 0, const string& Val = "");
		ImeitemIAVValuelistVal(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAVValuelistVal (full: ImeIFmncIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const uint SREFVLSIXFMNCVVALUELIST = 1;
			static const uint SREFX1IXFMNCVLOCALE = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey2 (full: ImeitemIFmncIniJAVKeylistKey2)
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
		* ImeIJAVKeylistKey2 (full: ImeIFmncIniJAVKeylistKey2)
		*/
	class ImeIJAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniJAVKeylistKey2Iel)
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
		* ImeitemIAVKeylistKey2 (full: ImeitemIFmncIniAVKeylistKey2)
		*/
	class ImeitemIAVKeylistKey2 : public FmncAVKeylistKey {

	public:
		ImeitemIAVKeylistKey2(const uint klsIxFmncVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
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
		* ImeIAVKeylistKey2 (full: ImeIFmncIniAVKeylistKey2)
		*/
	class ImeIAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAVKeylistKey2Iel)
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
		* ImeitemIAMStepPar (full: ImeitemIFmncIniAMStepPar)
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
		* ImeIAMStepPar (full: ImeIFmncIniAMStepPar)
		*/
	class ImeIAMStepPar {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAMStepParIel)
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
		* ImeitemIJAVKeylistKey3 (full: ImeitemIFmncIniJAVKeylistKey3)
		*/
	class ImeitemIJAVKeylistKey3 : public FmncJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey3(const uint x1IxFmncVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey3(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJAVKeylistKey3 (full: ImeIFmncIniJAVKeylistKey3)
		*/
	class ImeIJAVKeylistKey3 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniJAVKeylistKey3Iel)
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
		ImeIJAVKeylistKey3();
		~ImeIJAVKeylistKey3();

	public:
		vector<ImeitemIJAVKeylistKey3*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey3 (full: ImeitemIFmncIniAVKeylistKey3)
		*/
	class ImeitemIAVKeylistKey3 : public FmncAVKeylistKey {

	public:
		ImeitemIAVKeylistKey3(const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey3(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey3 imeijavkeylistkey3;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey3 (full: ImeIFmncIniAVKeylistKey3)
		*/
	class ImeIAVKeylistKey3 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAVKeylistKey3Iel)
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
		ImeIAVKeylistKey3();
		~ImeIAVKeylistKey3();

	public:
		vector<ImeitemIAVKeylistKey3*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMStep (full: ImeitemIFmncIniMStep)
		*/
	class ImeitemIMStep : public FmncMStep {

	public:
		ImeitemIMStep(const uint ixWFilecfg = 0, const string& Title = "");
		ImeitemIMStep(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMStepPar imeiamsteppar;
		ImeIAVKeylistKey3 imeiavkeylistkey3;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMStep (full: ImeIFmncIniMStep)
		*/
	class ImeIMStep {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniMStepIel)
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
		* ImeitemIMTooltype (full: ImeitemIFmncIniMTooltype)
		*/
	class ImeitemIMTooltype : public FmncMTooltype {

	public:
		ImeitemIMTooltype(const string& hsrefSupRefFmncMTooltype = "", const string& sref = "", const string& Title = "");
		ImeitemIMTooltype(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefSupRefFmncMTooltype;

		ImeIAVKeylistKey2 imeiavkeylistkey2;
		ImeIMStep imeimstep;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTooltype (full: ImeIFmncIniMTooltype)
		*/
	class ImeIMTooltype {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniMTooltypeIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFSUPREFFMNCMTOOLTYPE = 1;
			static const uint SREF = 2;
			static const uint TITLE = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMTooltype();
		~ImeIMTooltype();

	public:
		vector<ImeitemIMTooltype*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIFmncIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public FmncAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);
		ImeitemIAMUsergroupAccess(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAMUsergroupAccess (full: ImeIFmncIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXFMNCVCARD = 1;
			static const uint SREFSIXFMNCWUIACCESS = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIFmncIniJMUserState)
		*/
	class ImeitemIJMUserState : public FmncJMUserState {

	public:
		ImeitemIJMUserState(const uint ixVState = 0);
		ImeitemIJMUserState(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJMUserState (full: ImeIFmncIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSTATE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMPersonDetail (full: ImeitemIFmncIniAMPersonDetail)
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
		* ImeIAMPersonDetail (full: ImeIFmncIniAMPersonDetail)
		*/
	class ImeIAMPersonDetail {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniAMPersonDetailIel)
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
		* ImeitemIJMPersonLastname (full: ImeitemIFmncIniJMPersonLastname)
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
		* ImeIJMPersonLastname (full: ImeIFmncIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniJMPersonLastnameIel)
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
		* ImeitemIMAddress (full: ImeitemIFmncIniMAddress)
		*/
	class ImeitemIMAddress : public FmncMAddress {

	public:
		ImeitemIMAddress(const string& srefKAdrtype = "", const string& Address1 = "", const string& Address2 = "", const string& Zipcode = "", const string& City = "", const string& State = "", const string& srefKCountry = "");
		ImeitemIMAddress(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIMAddress (full: ImeIFmncIniMAddress)
		*/
	class ImeIMAddress {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniMAddressIel)
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
		ImeIMAddress();
		~ImeIMAddress();

	public:
		vector<ImeitemIMAddress*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIFmncIniMPerson)
		*/
	class ImeitemIMPerson : public FmncMPerson {

	public:
		ImeitemIMPerson(const uint ixVSex = 0, const string& Title = "", const string& Firstname = "");
		ImeitemIMPerson(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMPersonDetail imeiampersondetail;
		ImeIJMPersonLastname imeijmpersonlastname;
		ImeIMAddress imeimaddress;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIFmncIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSEX = 1;
			static const uint TITLE = 2;
			static const uint FIRSTNAME = 4;

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
		* ImeitemIMUser (full: ImeitemIFmncIniMUser)
		*/
	class ImeitemIMUser : public FmncMUser {

	public:
		ImeitemIMUser(const string& sref = "", const uint ixFmncVLocale = 0, const uint ixFmncVUserlevel = 0, const string& Password = "");
		ImeitemIMUser(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIFmncIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniMUserIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint SREFIXFMNCVLOCALE = 2;
			static const uint SREFIXFMNCVUSERLEVEL = 4;
			static const uint PASSWORD = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIFmncIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public FmncMUsergroup {

	public:
		ImeitemIMUsergroup(const string& sref = "", const string& Comment = "");
		ImeitemIMUsergroup(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIFmncIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIFmncIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexFmncIni(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
	~IexFmncIni();

public:
	uint lineno;
	uint impcnt;

	ImeIAVControlPar imeiavcontrolpar;
	ImeIAVKeylistKey1 imeiavkeylistkey1;
	ImeIAVValuelistVal imeiavvaluelistval;
	ImeIMTooltype imeimtooltype;
	ImeIMUsergroup imeimusergroup;

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


