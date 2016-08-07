/**
  * \file IexFmncElb.h
  * import/export handler for database DbsFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef IEXFMNCELB_H
#define IEXFMNCELB_H

/**
	* IexFmncElb
	*/
class IexFmncElb : public JobFmnc {

public:
	/**
		* VecVIme (full: VecVIexFmncElbIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIMFILE1 = 1;
		static const uint IMEIMPROJECT = 2;
		static const uint IMEIMSAMPLE = 3;
		static const uint IMEIAMSAMPLEPAR = 4;
		static const uint IMEIAVKEYLISTKEY = 5;
		static const uint IMEIJMPROJECTSTATE = 6;
		static const uint IMEIJMSAMPLESTATE = 7;
		static const uint IMEIMFILE2 = 8;
		static const uint IMEIMRUN = 9;
		static const uint IMEIRMFILEMSAMPLE = 10;
		static const uint IMEIJAVKEYLISTKEY = 11;
		static const uint IMEIJMRUNSTATE = 12;
		static const uint IMEIMACTIVITY = 13;
		static const uint IMEIMFILE3 = 14;
		static const uint IMEIRMFABMRUN = 15;
		static const uint IMEIRMPERSONMRUN = 16;
		static const uint IMEIRMRUNMSAMPLE = 17;
		static const uint IMEIMSTEP = 18;
		static const uint IMEIAMSTEPPAR = 19;
		static const uint IMEIMFILE4 = 20;
		static const uint IMEIRMFILEMSTEP1 = 21;
		static const uint IMEIRMFILEMSTEP2 = 22;
		static const uint IMEIRMSAMPLEMSTEP = 23;
		static const uint IMEITMFILEMSAMPLE1 = 24;
		static const uint IMEITMFILEMSAMPLE2 = 25;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIMFile1 (full: ImeitemIFmncElbMFile1)
		*/
	class ImeitemIMFile1 : public FmncMFile {

	public:
		ImeitemIMFile1(const ubigint iref = 0, const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile1(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile1 (full: ImeIFmncElbMFile1)
		*/
	class ImeIMFile1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMFile1Iel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint OSREFKCONTENT = 2;
			static const uint FILENAME = 4;
			static const uint SREFKMIMETYPE = 8;
			static const uint COMMENT = 16;

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
		* ImeitemIJMProjectState (full: ImeitemIFmncElbJMProjectState)
		*/
	class ImeitemIJMProjectState : public FmncJMProjectState {

	public:
		ImeitemIJMProjectState(const uint x1Start = 0, const uint ixVState = 0);
		ImeitemIJMProjectState(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJMProjectState (full: ImeIFmncElbJMProjectState)
		*/
	class ImeIJMProjectState {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbJMProjectStateIel)
			*/
		class VecWIel {

		public:
			static const uint FTMX1START = 1;
			static const uint SREFIXVSTATE = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMProjectState();
		~ImeIJMProjectState();

	public:
		vector<ImeitemIJMProjectState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMRunState (full: ImeitemIFmncElbJMRunState)
		*/
	class ImeitemIJMRunState : public FmncJMRunState {

	public:
		ImeitemIJMRunState(const uint x1Start = 0, const uint ixVState = 0);
		ImeitemIJMRunState(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJMRunState (full: ImeIFmncElbJMRunState)
		*/
	class ImeIJMRunState {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbJMRunStateIel)
			*/
		class VecWIel {

		public:
			static const uint FTMX1START = 1;
			static const uint SREFIXVSTATE = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMRunState();
		~ImeIJMRunState();

	public:
		vector<ImeitemIJMRunState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMStepPar (full: ImeitemIFmncElbAMStepPar)
		*/
	class ImeitemIAMStepPar : public FmncAMStepPar {

	public:
		ImeitemIAMStepPar(const string& x1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string& hintX2Uref = "", const string& Val = "", const string& Comment = "");
		ImeitemIAMStepPar(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintX2Uref;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMStepPar (full: ImeIFmncElbAMStepPar)
		*/
	class ImeIAMStepPar {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbAMStepParIel)
			*/
		class VecWIel {

		public:
			static const uint X1OSREFFMNCKSTEPPAR = 1;
			static const uint SREFX2IXVTBL = 2;
			static const uint HINTX2UREF = 4;
			static const uint VAL = 8;
			static const uint COMMENT = 16;

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
		* ImeitemIMFile4 (full: ImeitemIFmncElbMFile4)
		*/
	class ImeitemIMFile4 : public FmncMFile {

	public:
		ImeitemIMFile4(const ubigint iref = 0, const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile4(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile4 (full: ImeIFmncElbMFile4)
		*/
	class ImeIMFile4 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMFile4Iel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint OSREFKCONTENT = 2;
			static const uint FILENAME = 4;
			static const uint SREFKMIMETYPE = 8;
			static const uint COMMENT = 16;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFile4();
		~ImeIMFile4();

	public:
		vector<ImeitemIMFile4*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemITMFileMSample1 (full: ImeitemIFmncElbTMFileMSample1)
		*/
	class ImeitemITMFileMSample1 : public FmncTMFileMSample {

	public:
		ImeitemITMFileMSample1(const string& hsrefRefFmncMSample = "");
		ImeitemITMFileMSample1(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMSample;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeITMFileMSample1 (full: ImeIFmncElbTMFileMSample1)
		*/
	class ImeITMFileMSample1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbTMFileMSample1Iel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMSAMPLE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeITMFileMSample1();
		~ImeITMFileMSample1();

	public:
		vector<ImeitemITMFileMSample1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMFileMStep1 (full: ImeitemIFmncElbRMFileMStep1)
		*/
	class ImeitemIRMFileMStep1 : public FmncRMFileMStep {

	public:
		ImeitemIRMFileMStep1(const ubigint irefRefFmncMFile = 0, const uint ixVDir = 0);
		ImeitemIRMFileMStep1(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint irefRefFmncMFile;

		ImeITMFileMSample1 imeitmfilemsample1;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMFileMStep1 (full: ImeIFmncElbRMFileMStep1)
		*/
	class ImeIRMFileMStep1 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMFileMStep1Iel)
			*/
		class VecWIel {

		public:
			static const uint IREFREFFMNCMFILE = 1;
			static const uint SREFIXVDIR = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMFileMStep1();
		~ImeIRMFileMStep1();

	public:
		vector<ImeitemIRMFileMStep1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemITMFileMSample2 (full: ImeitemIFmncElbTMFileMSample2)
		*/
	class ImeitemITMFileMSample2 : public FmncTMFileMSample {

	public:
		ImeitemITMFileMSample2(const string& hsrefRefFmncMSample = "");
		ImeitemITMFileMSample2(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMSample;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeITMFileMSample2 (full: ImeIFmncElbTMFileMSample2)
		*/
	class ImeITMFileMSample2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbTMFileMSample2Iel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMSAMPLE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeITMFileMSample2();
		~ImeITMFileMSample2();

	public:
		vector<ImeitemITMFileMSample2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMFileMStep2 (full: ImeitemIFmncElbRMFileMStep2)
		*/
	class ImeitemIRMFileMStep2 : public FmncRMFileMStep {

	public:
		ImeitemIRMFileMStep2(const ubigint irefRefFmncMFile = 0, const uint ixVDir = 0);
		ImeitemIRMFileMStep2(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint irefRefFmncMFile;

		ImeITMFileMSample2 imeitmfilemsample2;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMFileMStep2 (full: ImeIFmncElbRMFileMStep2)
		*/
	class ImeIRMFileMStep2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMFileMStep2Iel)
			*/
		class VecWIel {

		public:
			static const uint IREFREFFMNCMFILE = 1;
			static const uint SREFIXVDIR = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMFileMStep2();
		~ImeIRMFileMStep2();

	public:
		vector<ImeitemIRMFileMStep2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMSampleMStep (full: ImeitemIFmncElbRMSampleMStep)
		*/
	class ImeitemIRMSampleMStep : public FmncRMSampleMStep {

	public:
		ImeitemIRMSampleMStep(const string& hsrefRefFmncMSample = "");
		ImeitemIRMSampleMStep(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMSample;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMSampleMStep (full: ImeIFmncElbRMSampleMStep)
		*/
	class ImeIRMSampleMStep {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMSampleMStepIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMSAMPLE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMSampleMStep();
		~ImeIRMSampleMStep();

	public:
		vector<ImeitemIRMSampleMStep*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMStep (full: ImeitemIFmncElbMStep)
		*/
	class ImeitemIMStep : public FmncMStep {

	public:
		ImeitemIMStep(const string& hintRlvUref = "", const string& hintTplRefFmncMStep = "", const uint ixWFilecfg = 0, const string& Title = "", const uint start = 0, const string& hintRefFmncMPerson = "");
		ImeitemIMStep(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintRlvUref;
		string hintTplRefFmncMStep;
		string hintRefFmncMPerson;

		ImeIAMStepPar imeiamsteppar;
		ImeIMFile4 imeimfile4;
		ImeIRMFileMStep1 imeirmfilemstep1;
		ImeIRMFileMStep2 imeirmfilemstep2;
		ImeIRMSampleMStep imeirmsamplemstep;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMStep (full: ImeIFmncElbMStep)
		*/
	class ImeIMStep {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMStepIel)
			*/
		class VecWIel {

		public:
			static const uint HINTRLVUREF = 1;
			static const uint HINTTPLREFFMNCMSTEP = 2;
			static const uint SREFSIXWFILECFG = 4;
			static const uint TITLE = 8;
			static const uint FTMSTART = 16;
			static const uint HINTREFFMNCMPERSON = 32;

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
		* ImeitemIMActivity (full: ImeitemIFmncElbMActivity)
		*/
	class ImeitemIMActivity : public FmncMActivity {

	public:
		ImeitemIMActivity(const string& Title = "", const string& Comment = "");
		ImeitemIMActivity(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIMStep imeimstep;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMActivity (full: ImeIFmncElbMActivity)
		*/
	class ImeIMActivity {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMActivityIel)
			*/
		class VecWIel {

		public:
			static const uint TITLE = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMActivity();
		~ImeIMActivity();

	public:
		vector<ImeitemIMActivity*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile3 (full: ImeitemIFmncElbMFile3)
		*/
	class ImeitemIMFile3 : public FmncMFile {

	public:
		ImeitemIMFile3(const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile3(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIMFile3 (full: ImeIFmncElbMFile3)
		*/
	class ImeIMFile3 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMFile3Iel)
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
		ImeIMFile3();
		~ImeIMFile3();

	public:
		vector<ImeitemIMFile3*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMFabMRun (full: ImeitemIFmncElbRMFabMRun)
		*/
	class ImeitemIRMFabMRun : public FmncRMFabMRun {

	public:
		ImeitemIRMFabMRun(const string& hintRefFmncMFab = "");
		ImeitemIRMFabMRun(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hintRefFmncMFab;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMFabMRun (full: ImeIFmncElbRMFabMRun)
		*/
	class ImeIRMFabMRun {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMFabMRunIel)
			*/
		class VecWIel {

		public:
			static const uint HINTREFFMNCMFAB = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMFabMRun();
		~ImeIRMFabMRun();

	public:
		vector<ImeitemIRMFabMRun*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMPersonMRun (full: ImeitemIFmncElbRMPersonMRun)
		*/
	class ImeitemIRMPersonMRun : public FmncRMPersonMRun {

	public:
		ImeitemIRMPersonMRun(const string& hintRefFmncMPerson = "");
		ImeitemIRMPersonMRun(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIRMPersonMRun (full: ImeIFmncElbRMPersonMRun)
		*/
	class ImeIRMPersonMRun {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMPersonMRunIel)
			*/
		class VecWIel {

		public:
			static const uint HINTREFFMNCMPERSON = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMPersonMRun();
		~ImeIRMPersonMRun();

	public:
		vector<ImeitemIRMPersonMRun*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMRunMSample (full: ImeitemIFmncElbRMRunMSample)
		*/
	class ImeitemIRMRunMSample : public FmncRMRunMSample {

	public:
		ImeitemIRMRunMSample(const string& hsrefRefFmncMSample = "");
		ImeitemIRMRunMSample(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefFmncMSample;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMRunMSample (full: ImeIFmncElbRMRunMSample)
		*/
	class ImeIRMRunMSample {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMRunMSampleIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFREFFMNCMSAMPLE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMRunMSample();
		~ImeIRMRunMSample();

	public:
		vector<ImeitemIRMRunMSample*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRun (full: ImeitemIFmncElbMRun)
		*/
	class ImeitemIMRun : public FmncMRun {

	public:
		ImeitemIMRun(const string& Title = "", const string& Comment = "");
		ImeitemIMRun(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMRunState imeijmrunstate;
		ImeIMActivity imeimactivity;
		ImeIMFile3 imeimfile3;
		ImeIRMFabMRun imeirmfabmrun;
		ImeIRMPersonMRun imeirmpersonmrun;
		ImeIRMRunMSample imeirmrunmsample;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRun (full: ImeIFmncElbMRun)
		*/
	class ImeIMRun {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMRunIel)
			*/
		class VecWIel {

		public:
			static const uint TITLE = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMRun();
		~ImeIMRun();

	public:
		vector<ImeitemIMRun*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMProject (full: ImeitemIFmncElbMProject)
		*/
	class ImeitemIMProject : public FmncMProject {

	public:
		ImeitemIMProject(const string& Title = "", const string& Comment = "");
		ImeitemIMProject(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMProjectState imeijmprojectstate;
		ImeIMRun imeimrun;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMProject (full: ImeIFmncElbMProject)
		*/
	class ImeIMProject {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMProjectIel)
			*/
		class VecWIel {

		public:
			static const uint TITLE = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMProject();
		~ImeIMProject();

	public:
		vector<ImeitemIMProject*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMSamplePar (full: ImeitemIFmncElbAMSamplePar)
		*/
	class ImeitemIAMSamplePar : public FmncAMSamplePar {

	public:
		ImeitemIAMSamplePar(const string& x1SrefKKey = "", const string& osrefKVal = "");
		ImeitemIAMSamplePar(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIAMSamplePar (full: ImeIFmncElbAMSamplePar)
		*/
	class ImeIAMSamplePar {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbAMSampleParIel)
			*/
		class VecWIel {

		public:
			static const uint X1SREFKKEY = 1;
			static const uint OSREFKVAL = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMSamplePar();
		~ImeIAMSamplePar();

	public:
		vector<ImeitemIAMSamplePar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIFmncElbJAVKeylistKey)
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
		* ImeIJAVKeylistKey (full: ImeIFmncElbJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbJAVKeylistKeyIel)
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
		* ImeitemIAVKeylistKey (full: ImeitemIFmncElbAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public FmncAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const uint klsIxFmncVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
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
		* ImeIAVKeylistKey (full: ImeIFmncElbAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbAVKeylistKeyIel)
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
		* ImeitemIJMSampleState (full: ImeitemIFmncElbJMSampleState)
		*/
	class ImeitemIJMSampleState : public FmncJMSampleState {

	public:
		ImeitemIJMSampleState(const uint x1Start = 0, const uint ixVState = 0);
		ImeitemIJMSampleState(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIJMSampleState (full: ImeIFmncElbJMSampleState)
		*/
	class ImeIJMSampleState {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbJMSampleStateIel)
			*/
		class VecWIel {

		public:
			static const uint FTMX1START = 1;
			static const uint SREFIXVSTATE = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMSampleState();
		~ImeIJMSampleState();

	public:
		vector<ImeitemIJMSampleState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile2 (full: ImeitemIFmncElbMFile2)
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
		* ImeIMFile2 (full: ImeIFmncElbMFile2)
		*/
	class ImeIMFile2 {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMFile2Iel)
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
		* ImeitemIRMFileMSample (full: ImeitemIFmncElbRMFileMSample)
		*/
	class ImeitemIRMFileMSample : public FmncRMFileMSample {

	public:
		ImeitemIRMFileMSample();
		ImeitemIRMFileMSample(DbsFmnc* dbsfmnc, const ubigint ref);

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
		* ImeIRMFileMSample (full: ImeIFmncElbRMFileMSample)
		*/
	class ImeIRMFileMSample {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbRMFileMSampleIel)
			*/
		class VecWIel {

		public:

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIRMFileMSample();
		~ImeIRMFileMSample();

	public:
		vector<ImeitemIRMFileMSample*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSample (full: ImeitemIFmncElbMSample)
		*/
	class ImeitemIMSample : public FmncMSample {

	public:
		ImeitemIMSample(const string& hsrefSupRefFmncMSample = "", const string& sref = "", const string& Material = "", const string& Comment = "");
		ImeitemIMSample(DbsFmnc* dbsfmnc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefSupRefFmncMSample;

		ImeIAMSamplePar imeiamsamplepar;
		ImeIAVKeylistKey imeiavkeylistkey;
		ImeIJMSampleState imeijmsamplestate;
		ImeIMFile2 imeimfile2;
		ImeIRMFileMSample imeirmfilemsample;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSample (full: ImeIFmncElbMSample)
		*/
	class ImeIMSample {

	public:
		/**
			* VecWIel (full: VecWImeIFmncElbMSampleIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFSUPREFFMNCMSAMPLE = 1;
			static const uint SREF = 2;
			static const uint MATERIAL = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMSample();
		~ImeIMSample();

	public:
		vector<ImeitemIMSample*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexFmncElb(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
	~IexFmncElb();

public:
	uint lineno;
	uint impcnt;

	ImeIMFile1 imeimfile1;
	ImeIMProject imeimproject;
	ImeIMSample imeimsample;

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


