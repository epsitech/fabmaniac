/**
  * \file IexFmncFab_blks.cpp
  * import/export handler for database DbsFmnc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class IexFmncFab::VecVIme
 ******************************************************************************/

uint IexFmncFab::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimtool") return IMEIMTOOL;
	else if (s == "imeiamtoolavl") return IMEIAMTOOLAVL;
	else if (s == "imeiamtoolchar") return IMEIAMTOOLCHAR;
	else if (s == "imeiavkeylistkey1") return IMEIAVKEYLISTKEY1;
	else if (s == "imeifabsmpersonmtool") return IMEIFABSMPERSONMTOOL;
	else if (s == "imeijmtoolunitprice") return IMEIJMTOOLUNITPRICE;
	else if (s == "imeimarticle") return IMEIMARTICLE;
	else if (s == "imeimfile1") return IMEIMFILE1;
	else if (s == "imeimnfsmpersonmtool") return IMEIMNFSMPERSONMTOOL;
	else if (s == "imeimstep") return IMEIMSTEP;
	else if (s == "imeirmtoolmtooltype") return IMEIRMTOOLMTOOLTYPE;
	else if (s == "imeisvcrmorgmtool") return IMEISVCRMORGMTOOL;
	else if (s == "imeiamsteppar") return IMEIAMSTEPPAR;
	else if (s == "imeiavkeylistkey2") return IMEIAVKEYLISTKEY2;
	else if (s == "imeijavkeylistkey1") return IMEIJAVKEYLISTKEY1;
	else if (s == "imeimfile2") return IMEIMFILE2;
	else if (s == "imeirmarticlemorg") return IMEIRMARTICLEMORG;
	else if (s == "imeisvctmpersonmtool") return IMEISVCTMPERSONMTOOL;
	else if (s == "imeijavkeylistkey2") return IMEIJAVKEYLISTKEY2;

	return(0);
};

string IexFmncFab::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMTOOL) return("ImeIMTool");
	else if (ix == IMEIAMTOOLAVL) return("ImeIAMToolAvl");
	else if (ix == IMEIAMTOOLCHAR) return("ImeIAMToolChar");
	else if (ix == IMEIAVKEYLISTKEY1) return("ImeIAVKeylistKey1");
	else if (ix == IMEIFABSMPERSONMTOOL) return("ImeIFabSMPersonMTool");
	else if (ix == IMEIJMTOOLUNITPRICE) return("ImeIJMToolUnitprice");
	else if (ix == IMEIMARTICLE) return("ImeIMArticle");
	else if (ix == IMEIMFILE1) return("ImeIMFile1");
	else if (ix == IMEIMNFSMPERSONMTOOL) return("ImeIMnfSMPersonMTool");
	else if (ix == IMEIMSTEP) return("ImeIMStep");
	else if (ix == IMEIRMTOOLMTOOLTYPE) return("ImeIRMToolMTooltype");
	else if (ix == IMEISVCRMORGMTOOL) return("ImeISvcRMOrgMTool");
	else if (ix == IMEIAMSTEPPAR) return("ImeIAMStepPar");
	else if (ix == IMEIAVKEYLISTKEY2) return("ImeIAVKeylistKey2");
	else if (ix == IMEIJAVKEYLISTKEY1) return("ImeIJAVKeylistKey1");
	else if (ix == IMEIMFILE2) return("ImeIMFile2");
	else if (ix == IMEIRMARTICLEMORG) return("ImeIRMArticleMOrg");
	else if (ix == IMEISVCTMPERSONMTOOL) return("ImeISvcTMPersonMTool");
	else if (ix == IMEIJAVKEYLISTKEY2) return("ImeIJAVKeylistKey2");

	return("");
};

/******************************************************************************
 class IexFmncFab::ImeitemIAMToolAvl
 ******************************************************************************/

IexFmncFab::ImeitemIAMToolAvl::ImeitemIAMToolAvl(
			const uint x2IxVWkday
			, const uint x3Startt
			, const uint x3Stopt
			, const string& srefKAvltype
		) : FmncAMToolAvl() {
	lineno = 0;
	ixWIelValid = 0;

	this->x2IxVWkday = x2IxVWkday;
	this->x3Startt = x3Startt;
	this->x3Stopt = x3Stopt;
	this->srefKAvltype = srefKAvltype;
};

IexFmncFab::ImeitemIAMToolAvl::ImeitemIAMToolAvl(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMToolAvl() {
	FmncAMToolAvl* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamtoolavl->loadRecByRef(ref, &rec)) {
		refFmncMTool = rec->refFmncMTool;
		x2IxVWkday = rec->x2IxVWkday;
		x3Startt = rec->x3Startt;
		x3Stopt = rec->x3Stopt;
		srefKAvltype = rec->srefKAvltype;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIAMToolAvl::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 1) x3Startt = Ftm::invtime(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) x3Stopt = Ftm::invtime(txtrd.fields[2]);
	if (txtrd.fields.size() > 3) srefKAvltype = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIAMToolAvl::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX2IxVWkday;
	string ftmX3Startt;
	string ftmX3Stopt;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "ftmX3Startt", "sta", ftmX3Startt)) {
			x3Startt = Ftm::invtime(ftmX3Startt);
			ixWIelValid += ImeIAMToolAvl::VecWIel::FTMX3STARTT;
		};
		if (extractStringUclc(docctx, basexpath, "ftmX3Stopt", "sto", ftmX3Stopt)) {
			x3Stopt = Ftm::invtime(ftmX3Stopt);
			ixWIelValid += ImeIAMToolAvl::VecWIel::FTMX3STOPT;
		};
		if (extractStringUclc(docctx, basexpath, "srefKAvltype", "aty", srefKAvltype)) ixWIelValid += ImeIAMToolAvl::VecWIel::SREFKAVLTYPE;
	};
};

void IexFmncFab::ImeitemIAMToolAvl::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << "\t" << Ftm::time(x3Startt)
 << "\t" << Ftm::time(x3Stopt)
 << "\t" << srefKAvltype << endl;
};

void IexFmncFab::ImeitemIAMToolAvl::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","wdy","sta","sto","aty"};
	else tags = {"ImeitemIAMToolAvl","srefX2IxVWkday","ftmX3Startt","ftmX3Stopt","srefKAvltype"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[2], Ftm::time(x3Startt));
		writeString(wr, tags[3], Ftm::time(x3Stopt));
		writeString(wr, tags[4], srefKAvltype);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIAMToolAvl::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIAMToolAvl::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX2IxVWkday") ix |= SREFX2IXVWKDAY;
		else if (ss[i] == "ftmX3Startt") ix |= FTMX3STARTT;
		else if (ss[i] == "ftmX3Stopt") ix |= FTMX3STOPT;
		else if (ss[i] == "srefKAvltype") ix |= SREFKAVLTYPE;
	};

	return(ix);
};

void IexFmncFab::ImeIAMToolAvl::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFKAVLTYPE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIAMToolAvl::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX2IXVWKDAY) ss.push_back("srefX2IxVWkday");
	if (ix & FTMX3STARTT) ss.push_back("ftmX3Startt");
	if (ix & FTMX3STOPT) ss.push_back("ftmX3Stopt");
	if (ix & SREFKAVLTYPE) ss.push_back("srefKAvltype");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIAMToolAvl
 ******************************************************************************/

IexFmncFab::ImeIAMToolAvl::ImeIAMToolAvl() {
};

IexFmncFab::ImeIAMToolAvl::~ImeIAMToolAvl() {
	clear();
};

void IexFmncFab::ImeIAMToolAvl::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIAMToolAvl::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIAMToolAvl* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIAMToolAvl();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIAMToolAvl::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIAMToolAvl* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMToolAvl");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMToolAvl", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMToolAvl";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIAMToolAvl();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIAMToolAvl::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMToolAvl." << StrMod::replaceChar(ImeIAMToolAvl::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIAMToolAvl::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMToolAvl");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIAMToolChar
 ******************************************************************************/

IexFmncFab::ImeitemIAMToolChar::ImeitemIAMToolChar(
			const string& x1OsrefFmncKToolchar
			, const string& Val
			, const string& Comment
		) : FmncAMToolChar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1OsrefFmncKToolchar = x1OsrefFmncKToolchar;
	this->Val = Val;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIAMToolChar::ImeitemIAMToolChar(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMToolChar() {
	FmncAMToolChar* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamtoolchar->loadRecByRef(ref, &rec)) {
		refFmncMTool = rec->refFmncMTool;
		x1OsrefFmncKToolchar = rec->x1OsrefFmncKToolchar;
		Val = rec->Val;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIAMToolChar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1OsrefFmncKToolchar = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Val = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIAMToolChar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1OsrefFmncKToolchar", "tch", x1OsrefFmncKToolchar)) ixWIelValid += ImeIAMToolChar::VecWIel::X1OSREFFMNCKTOOLCHAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMToolChar::VecWIel::VAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMToolChar::VecWIel::COMMENT;
	};
};

void IexFmncFab::ImeitemIAMToolChar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1OsrefFmncKToolchar << "\t" << Val << "\t" << Comment << endl;
};

void IexFmncFab::ImeitemIAMToolChar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tch","val","cmt"};
	else tags = {"ImeitemIAMToolChar","x1OsrefFmncKToolchar","Val","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1OsrefFmncKToolchar);
		writeString(wr, tags[2], Val);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIAMToolChar::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIAMToolChar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x1OsrefFmncKToolchar") ix |= X1OSREFFMNCKTOOLCHAR;
		else if (ss[i] == "Val") ix |= VAL;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIAMToolChar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIAMToolChar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1OSREFFMNCKTOOLCHAR) ss.push_back("x1OsrefFmncKToolchar");
	if (ix & VAL) ss.push_back("Val");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIAMToolChar
 ******************************************************************************/

IexFmncFab::ImeIAMToolChar::ImeIAMToolChar() {
};

IexFmncFab::ImeIAMToolChar::~ImeIAMToolChar() {
	clear();
};

void IexFmncFab::ImeIAMToolChar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIAMToolChar::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIAMToolChar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIAMToolChar();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIAMToolChar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIAMToolChar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMToolChar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMToolChar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMToolChar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIAMToolChar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIAMToolChar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMToolChar." << StrMod::replaceChar(ImeIAMToolChar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIAMToolChar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMToolChar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIJAVKeylistKey1
 ******************************************************************************/

IexFmncFab::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			const uint x1IxFmncVLocale
			, const string& Title
			, const string& Comment
		) : FmncJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxFmncVLocale = x1IxFmncVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJAVKeylistKey1() {
	FmncJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjavkeylistkey->loadRecByRef(ref, &rec)) {
		refFmncAVKeylistKey = rec->refFmncAVKeylistKey;
		x1IxFmncVLocale = rec->x1IxFmncVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxFmncVLocale = VecFmncVLocale::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxFmncVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxFmncVLocale", "lcl", srefX1IxFmncVLocale)) {
			x1IxFmncVLocale = VecFmncVLocale::getIx(srefX1IxFmncVLocale);
			ixWIelValid += ImeIJAVKeylistKey1::VecWIel::SREFX1IXFMNCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::COMMENT;
	};
};

void IexFmncFab::ImeitemIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncFab::ImeitemIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey1","srefX1IxFmncVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVLocale::getSref(x1IxFmncVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIJAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIJAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxFmncVLocale") ix |= SREFX1IXFMNCVLOCALE;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIJAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIJAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXFMNCVLOCALE) ss.push_back("srefX1IxFmncVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIJAVKeylistKey1
 ******************************************************************************/

IexFmncFab::ImeIJAVKeylistKey1::ImeIJAVKeylistKey1() {
};

IexFmncFab::ImeIJAVKeylistKey1::~ImeIJAVKeylistKey1() {
	clear();
};

void IexFmncFab::ImeIJAVKeylistKey1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIJAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncFab::ImeitemIJAVKeylistKey1();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIJAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIJAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey1." << StrMod::replaceChar(ImeIJAVKeylistKey1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIAVKeylistKey1
 ******************************************************************************/

IexFmncFab::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			const uint klsIxFmncVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
		) : FmncAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxFmncVKeylist = klsIxFmncVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
};

IexFmncFab::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVKeylistKey1() {
	FmncAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxFmncVKeylist = rec->klsIxFmncVKeylist;
		x1IxFmncVMaintable = rec->x1IxFmncVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxFmncVKeylist = VecFmncVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1)) {
			if (!imeijavkeylistkey1.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefKlsIxFmncVKeylist;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxFmncVKeylist", "kls", srefKlsIxFmncVKeylist)) {
			klsIxFmncVKeylist = VecFmncVKeylist::getIx(srefKlsIxFmncVKeylist);
			ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREFKLSIXFMNCVKEYLIST;
		};
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::IMPLIED;
		imeijavkeylistkey1.readXML(docctx, basexpath);
	};
};

void IexFmncFab::ImeitemIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncVKeylist::getSref(klsIxFmncVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey1.writeTxt(outfile);
};

void IexFmncFab::ImeitemIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey1","srefKlsIxFmncVKeylist","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVKeylist::getSref(klsIxFmncVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		imeijavkeylistkey1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefKlsIxFmncVKeylist") ix |= SREFKLSIXFMNCVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Avail") ix |= AVAIL;
		else if (ss[i] == "Implied") ix |= IMPLIED;
	};

	return(ix);
};

void IexFmncFab::ImeIAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXFMNCVKEYLIST) ss.push_back("srefKlsIxFmncVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIAVKeylistKey1
 ******************************************************************************/

IexFmncFab::ImeIAVKeylistKey1::ImeIAVKeylistKey1() {
};

IexFmncFab::ImeIAVKeylistKey1::~ImeIAVKeylistKey1() {
	clear();
};

void IexFmncFab::ImeIAVKeylistKey1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIAVKeylistKey1();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey1." << StrMod::replaceChar(ImeIAVKeylistKey1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIFabSMPersonMTool
 ******************************************************************************/

IexFmncFab::ImeitemIFabSMPersonMTool::ImeitemIFabSMPersonMTool(
			const string& hintRefFmncMPerson
		) : FmncFabSMPersonMTool() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefFmncMPerson = hintRefFmncMPerson;
};

IexFmncFab::ImeitemIFabSMPersonMTool::ImeitemIFabSMPersonMTool(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIFabSMPersonMTool() {
	FmncFabSMPersonMTool* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncfabsmpersonmtool->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		refM = rec->refM;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIFabSMPersonMTool::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintRefFmncMPerson = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIFabSMPersonMTool::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRefFmncMPerson", "prs", hintRefFmncMPerson)) ixWIelValid += ImeIFabSMPersonMTool::VecWIel::HINTREFFMNCMPERSON;
	};
};

void IexFmncFab::ImeitemIFabSMPersonMTool::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hintRefFmncMPerson << endl;
};

void IexFmncFab::ImeitemIFabSMPersonMTool::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs"};
	else tags = {"ImeitemIFabSMPersonMTool","hintRefFmncMPerson"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefFmncMPerson);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIFabSMPersonMTool::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIFabSMPersonMTool::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintRefFmncMPerson") ix |= HINTREFFMNCMPERSON;
	};

	return(ix);
};

void IexFmncFab::ImeIFabSMPersonMTool::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HINTREFFMNCMPERSON);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIFabSMPersonMTool::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFFMNCMPERSON) ss.push_back("hintRefFmncMPerson");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIFabSMPersonMTool
 ******************************************************************************/

IexFmncFab::ImeIFabSMPersonMTool::ImeIFabSMPersonMTool() {
};

IexFmncFab::ImeIFabSMPersonMTool::~ImeIFabSMPersonMTool() {
	clear();
};

void IexFmncFab::ImeIFabSMPersonMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIFabSMPersonMTool::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIFabSMPersonMTool* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIFabSMPersonMTool();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIFabSMPersonMTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIFabSMPersonMTool* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIFabSMPersonMTool");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIFabSMPersonMTool", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIFabSMPersonMTool";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIFabSMPersonMTool();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIFabSMPersonMTool::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIFabSMPersonMTool." << StrMod::replaceChar(ImeIFabSMPersonMTool::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIFabSMPersonMTool::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIFabSMPersonMTool");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIJMToolUnitprice
 ******************************************************************************/

IexFmncFab::ImeitemIJMToolUnitprice::ImeitemIJMToolUnitprice(
			const double Unitprice
		) : FmncJMToolUnitprice() {
	lineno = 0;
	ixWIelValid = 0;

	this->Unitprice = Unitprice;
};

IexFmncFab::ImeitemIJMToolUnitprice::ImeitemIJMToolUnitprice(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMToolUnitprice() {
	FmncJMToolUnitprice* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmtoolunitprice->loadRecByRef(ref, &rec)) {
		refFmncMTool = rec->refFmncMTool;
		Unitprice = rec->Unitprice;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIJMToolUnitprice::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Unitprice = atof(txtrd.fields[0].c_str());

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIJMToolUnitprice::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractDoubleUclc(docctx, basexpath, "Unitprice", "upr", Unitprice)) ixWIelValid += ImeIJMToolUnitprice::VecWIel::UNITPRICE;
	};
};

void IexFmncFab::ImeitemIJMToolUnitprice::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Unitprice << endl;
};

void IexFmncFab::ImeitemIJMToolUnitprice::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","upr"};
	else tags = {"ImeitemIJMToolUnitprice","Unitprice"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeDouble(wr, tags[1], Unitprice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIJMToolUnitprice::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIJMToolUnitprice::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Unitprice") ix |= UNITPRICE;
	};

	return(ix);
};

void IexFmncFab::ImeIJMToolUnitprice::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*UNITPRICE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIJMToolUnitprice::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & UNITPRICE) ss.push_back("Unitprice");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIJMToolUnitprice
 ******************************************************************************/

IexFmncFab::ImeIJMToolUnitprice::ImeIJMToolUnitprice() {
};

IexFmncFab::ImeIJMToolUnitprice::~ImeIJMToolUnitprice() {
	clear();
};

void IexFmncFab::ImeIJMToolUnitprice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIJMToolUnitprice::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIJMToolUnitprice* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIJMToolUnitprice();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIJMToolUnitprice::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIJMToolUnitprice* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMToolUnitprice");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMToolUnitprice", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMToolUnitprice";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIJMToolUnitprice();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIJMToolUnitprice::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMToolUnitprice." << StrMod::replaceChar(ImeIJMToolUnitprice::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIJMToolUnitprice::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMToolUnitprice");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIMFile2
 ******************************************************************************/

IexFmncFab::ImeitemIMFile2::ImeitemIMFile2(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : FmncMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIMFile2::ImeitemIMFile2(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMFile2() {
	FmncMFile* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIMFile2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) osrefKContent = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Filename = txtrd.fields[1];
	if (txtrd.fields.size() > 2) srefKMimetype = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Comment = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIMFile2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile2::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile2::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile2::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile2::VecWIel::COMMENT;
	};
};

void IexFmncFab::ImeitemIMFile2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexFmncFab::ImeitemIMFile2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile2","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIMFile2::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIMFile2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "osrefKContent") ix |= OSREFKCONTENT;
		else if (ss[i] == "Filename") ix |= FILENAME;
		else if (ss[i] == "srefKMimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIMFile2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIMFile2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIMFile2
 ******************************************************************************/

IexFmncFab::ImeIMFile2::ImeIMFile2() {
};

IexFmncFab::ImeIMFile2::~ImeIMFile2() {
	clear();
};

void IexFmncFab::ImeIMFile2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIMFile2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIMFile2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncFab::ImeitemIMFile2();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIMFile2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIMFile2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIMFile2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIMFile2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMFile2." << StrMod::replaceChar(ImeIMFile2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIMFile2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIRMArticleMOrg
 ******************************************************************************/

IexFmncFab::ImeitemIRMArticleMOrg::ImeitemIRMArticleMOrg(
			const string& hsrefRefFmncMOrg
			, const string& Itemno
		) : FmncRMArticleMOrg() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMOrg = hsrefRefFmncMOrg;
	this->Itemno = Itemno;
};

IexFmncFab::ImeitemIRMArticleMOrg::ImeitemIRMArticleMOrg(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMArticleMOrg() {
	FmncRMArticleMOrg* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmarticlemorg->loadRecByRef(ref, &rec)) {
		refFmncMArticle = rec->refFmncMArticle;
		refFmncMOrg = rec->refFmncMOrg;
		Itemno = rec->Itemno;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIRMArticleMOrg::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMOrg = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Itemno = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIRMArticleMOrg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMOrg", "mnf", hsrefRefFmncMOrg)) ixWIelValid += ImeIRMArticleMOrg::VecWIel::HSREFREFFMNCMORG;
		if (extractStringUclc(docctx, basexpath, "Itemno", "itn", Itemno)) ixWIelValid += ImeIRMArticleMOrg::VecWIel::ITEMNO;
	};
};

void IexFmncFab::ImeitemIRMArticleMOrg::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hsrefRefFmncMOrg << "\t" << Itemno << endl;
};

void IexFmncFab::ImeitemIRMArticleMOrg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mnf","itn"};
	else tags = {"ImeitemIRMArticleMOrg","hsrefRefFmncMOrg","Itemno"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMOrg);
		writeString(wr, tags[2], Itemno);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIRMArticleMOrg::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIRMArticleMOrg::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMOrg") ix |= HSREFREFFMNCMORG;
		else if (ss[i] == "Itemno") ix |= ITEMNO;
	};

	return(ix);
};

void IexFmncFab::ImeIRMArticleMOrg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*ITEMNO);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIRMArticleMOrg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMORG) ss.push_back("hsrefRefFmncMOrg");
	if (ix & ITEMNO) ss.push_back("Itemno");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIRMArticleMOrg
 ******************************************************************************/

IexFmncFab::ImeIRMArticleMOrg::ImeIRMArticleMOrg() {
};

IexFmncFab::ImeIRMArticleMOrg::~ImeIRMArticleMOrg() {
	clear();
};

void IexFmncFab::ImeIRMArticleMOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIRMArticleMOrg::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIRMArticleMOrg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncFab::ImeitemIRMArticleMOrg();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIRMArticleMOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIRMArticleMOrg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMArticleMOrg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMArticleMOrg", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMArticleMOrg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIRMArticleMOrg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIRMArticleMOrg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMArticleMOrg." << StrMod::replaceChar(ImeIRMArticleMOrg::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIRMArticleMOrg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMArticleMOrg");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIMArticle
 ******************************************************************************/

IexFmncFab::ImeitemIMArticle::ImeitemIMArticle(
			const string& hsrefRefFmncMOrg
			, const string& sref
			, const string& Title
			, const string& Comment
		) : FmncMArticle() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMOrg = hsrefRefFmncMOrg;
	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIMArticle::ImeitemIMArticle(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMArticle() {
	FmncMArticle* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmarticle->loadRecByRef(ref, &rec)) {
		refFmncMOrg = rec->refFmncMOrg;
		refFmncMTool = rec->refFmncMTool;
		sref = rec->sref;
		Title = rec->Title;
		srefKType = rec->srefKType;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIMArticle::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMOrg = txtrd.fields[0];
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Title = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Comment = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMFILE2)) {
			if (!imeimfile2.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMARTICLEMORG)) {
			if (!imeirmarticlemorg.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIMArticle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMOrg", "mnf", hsrefRefFmncMOrg)) ixWIelValid += ImeIMArticle::VecWIel::HSREFREFFMNCMORG;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMArticle::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMArticle::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMArticle::VecWIel::COMMENT;
		imeimfile2.readXML(docctx, basexpath);
		imeirmarticlemorg.readXML(docctx, basexpath);
	};
};

void IexFmncFab::ImeitemIMArticle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefRefFmncMOrg << "\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeimfile2.writeTxt(outfile);
	imeirmarticlemorg.writeTxt(outfile);
};

void IexFmncFab::ImeitemIMArticle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mnf","srf","tit","cmt"};
	else tags = {"ImeitemIMArticle","hsrefRefFmncMOrg","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMOrg);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Comment);
		imeimfile2.writeXML(wr, shorttags);
		imeirmarticlemorg.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIMArticle::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIMArticle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMOrg") ix |= HSREFREFFMNCMORG;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIMArticle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIMArticle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMORG) ss.push_back("hsrefRefFmncMOrg");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIMArticle
 ******************************************************************************/

IexFmncFab::ImeIMArticle::ImeIMArticle() {
};

IexFmncFab::ImeIMArticle::~ImeIMArticle() {
	clear();
};

void IexFmncFab::ImeIMArticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIMArticle::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIMArticle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIMArticle();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIMArticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIMArticle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMArticle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMArticle", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMArticle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIMArticle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIMArticle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMArticle." << StrMod::replaceChar(ImeIMArticle::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIMArticle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMArticle");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIMFile1
 ******************************************************************************/

IexFmncFab::ImeitemIMFile1::ImeitemIMFile1(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : FmncMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIMFile1::ImeitemIMFile1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMFile1() {
	FmncMFile* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIMFile1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) osrefKContent = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Filename = txtrd.fields[1];
	if (txtrd.fields.size() > 2) srefKMimetype = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Comment = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIMFile1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile1::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile1::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile1::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile1::VecWIel::COMMENT;
	};
};

void IexFmncFab::ImeitemIMFile1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexFmncFab::ImeitemIMFile1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile1","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIMFile1::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIMFile1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "osrefKContent") ix |= OSREFKCONTENT;
		else if (ss[i] == "Filename") ix |= FILENAME;
		else if (ss[i] == "srefKMimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIMFile1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIMFile1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIMFile1
 ******************************************************************************/

IexFmncFab::ImeIMFile1::ImeIMFile1() {
};

IexFmncFab::ImeIMFile1::~ImeIMFile1() {
	clear();
};

void IexFmncFab::ImeIMFile1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIMFile1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIMFile1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIMFile1();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIMFile1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIMFile1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIMFile1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIMFile1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMFile1." << StrMod::replaceChar(ImeIMFile1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIMFile1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIMnfSMPersonMTool
 ******************************************************************************/

IexFmncFab::ImeitemIMnfSMPersonMTool::ImeitemIMnfSMPersonMTool(
			const string& hintRefFmncMPerson
		) : FmncMnfSMPersonMTool() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefFmncMPerson = hintRefFmncMPerson;
};

IexFmncFab::ImeitemIMnfSMPersonMTool::ImeitemIMnfSMPersonMTool(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMnfSMPersonMTool() {
	FmncMnfSMPersonMTool* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmnfsmpersonmtool->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		refM = rec->refM;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIMnfSMPersonMTool::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintRefFmncMPerson = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIMnfSMPersonMTool::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRefFmncMPerson", "prs", hintRefFmncMPerson)) ixWIelValid += ImeIMnfSMPersonMTool::VecWIel::HINTREFFMNCMPERSON;
	};
};

void IexFmncFab::ImeitemIMnfSMPersonMTool::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hintRefFmncMPerson << endl;
};

void IexFmncFab::ImeitemIMnfSMPersonMTool::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs"};
	else tags = {"ImeitemIMnfSMPersonMTool","hintRefFmncMPerson"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefFmncMPerson);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIMnfSMPersonMTool::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIMnfSMPersonMTool::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintRefFmncMPerson") ix |= HINTREFFMNCMPERSON;
	};

	return(ix);
};

void IexFmncFab::ImeIMnfSMPersonMTool::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HINTREFFMNCMPERSON);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIMnfSMPersonMTool::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFFMNCMPERSON) ss.push_back("hintRefFmncMPerson");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIMnfSMPersonMTool
 ******************************************************************************/

IexFmncFab::ImeIMnfSMPersonMTool::ImeIMnfSMPersonMTool() {
};

IexFmncFab::ImeIMnfSMPersonMTool::~ImeIMnfSMPersonMTool() {
	clear();
};

void IexFmncFab::ImeIMnfSMPersonMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIMnfSMPersonMTool::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIMnfSMPersonMTool* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIMnfSMPersonMTool();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIMnfSMPersonMTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIMnfSMPersonMTool* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMnfSMPersonMTool");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMnfSMPersonMTool", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMnfSMPersonMTool";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIMnfSMPersonMTool();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIMnfSMPersonMTool::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMnfSMPersonMTool." << StrMod::replaceChar(ImeIMnfSMPersonMTool::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIMnfSMPersonMTool::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMnfSMPersonMTool");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIAMStepPar
 ******************************************************************************/

IexFmncFab::ImeitemIAMStepPar::ImeitemIAMStepPar(
			const string& x1OsrefFmncKSteppar
			, const string& Val
			, const string& Comment
		) : FmncAMStepPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1OsrefFmncKSteppar = x1OsrefFmncKSteppar;
	this->Val = Val;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIAMStepPar::ImeitemIAMStepPar(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMStepPar() {
	FmncAMStepPar* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamsteppar->loadRecByRef(ref, &rec)) {
		refFmncMStep = rec->refFmncMStep;
		x1OsrefFmncKSteppar = rec->x1OsrefFmncKSteppar;
		x2IxVTbl = rec->x2IxVTbl;
		Val = rec->Val;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIAMStepPar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1OsrefFmncKSteppar = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Val = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIAMStepPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1OsrefFmncKSteppar", "spa", x1OsrefFmncKSteppar)) ixWIelValid += ImeIAMStepPar::VecWIel::X1OSREFFMNCKSTEPPAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMStepPar::VecWIel::VAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMStepPar::VecWIel::COMMENT;
	};
};

void IexFmncFab::ImeitemIAMStepPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1OsrefFmncKSteppar << "\t" << Val << "\t" << Comment << endl;
};

void IexFmncFab::ImeitemIAMStepPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","spa","val","cmt"};
	else tags = {"ImeitemIAMStepPar","x1OsrefFmncKSteppar","Val","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1OsrefFmncKSteppar);
		writeString(wr, tags[2], Val);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIAMStepPar::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIAMStepPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x1OsrefFmncKSteppar") ix |= X1OSREFFMNCKSTEPPAR;
		else if (ss[i] == "Val") ix |= VAL;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIAMStepPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIAMStepPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1OSREFFMNCKSTEPPAR) ss.push_back("x1OsrefFmncKSteppar");
	if (ix & VAL) ss.push_back("Val");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIAMStepPar
 ******************************************************************************/

IexFmncFab::ImeIAMStepPar::ImeIAMStepPar() {
};

IexFmncFab::ImeIAMStepPar::~ImeIAMStepPar() {
	clear();
};

void IexFmncFab::ImeIAMStepPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIAMStepPar::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIAMStepPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncFab::ImeitemIAMStepPar();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIAMStepPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIAMStepPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMStepPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMStepPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMStepPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIAMStepPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIAMStepPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMStepPar." << StrMod::replaceChar(ImeIAMStepPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIAMStepPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMStepPar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIJAVKeylistKey2
 ******************************************************************************/

IexFmncFab::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			const uint x1IxFmncVLocale
			, const string& Title
			, const string& Comment
		) : FmncJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxFmncVLocale = x1IxFmncVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJAVKeylistKey2() {
	FmncJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjavkeylistkey->loadRecByRef(ref, &rec)) {
		refFmncAVKeylistKey = rec->refFmncAVKeylistKey;
		x1IxFmncVLocale = rec->x1IxFmncVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxFmncVLocale = VecFmncVLocale::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxFmncVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxFmncVLocale", "lcl", srefX1IxFmncVLocale)) {
			x1IxFmncVLocale = VecFmncVLocale::getIx(srefX1IxFmncVLocale);
			ixWIelValid += ImeIJAVKeylistKey2::VecWIel::SREFX1IXFMNCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::COMMENT;
	};
};

void IexFmncFab::ImeitemIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncFab::ImeitemIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey2","srefX1IxFmncVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVLocale::getSref(x1IxFmncVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIJAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIJAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxFmncVLocale") ix |= SREFX1IXFMNCVLOCALE;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIJAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIJAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXFMNCVLOCALE) ss.push_back("srefX1IxFmncVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIJAVKeylistKey2
 ******************************************************************************/

IexFmncFab::ImeIJAVKeylistKey2::ImeIJAVKeylistKey2() {
};

IexFmncFab::ImeIJAVKeylistKey2::~ImeIJAVKeylistKey2() {
	clear();
};

void IexFmncFab::ImeIJAVKeylistKey2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIJAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexFmncFab::ImeitemIJAVKeylistKey2();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIJAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIJAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAVKeylistKey2." << StrMod::replaceChar(ImeIJAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIAVKeylistKey2
 ******************************************************************************/

IexFmncFab::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			const string& sref
			, const string& Avail
			, const string& Implied
		) : FmncAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
};

IexFmncFab::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVKeylistKey2() {
	FmncAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxFmncVKeylist = rec->klsIxFmncVKeylist;
		x1IxFmncVMaintable = rec->x1IxFmncVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Avail = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Implied = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2)) {
			if (!imeijavkeylistkey2.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::IMPLIED;
		imeijavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexFmncFab::ImeitemIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey2.writeTxt(outfile);
};

void IexFmncFab::ImeitemIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey2","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		imeijavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Avail") ix |= AVAIL;
		else if (ss[i] == "Implied") ix |= IMPLIED;
	};

	return(ix);
};

void IexFmncFab::ImeIAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIAVKeylistKey2
 ******************************************************************************/

IexFmncFab::ImeIAVKeylistKey2::ImeIAVKeylistKey2() {
};

IexFmncFab::ImeIAVKeylistKey2::~ImeIAVKeylistKey2() {
	clear();
};

void IexFmncFab::ImeIAVKeylistKey2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncFab::ImeitemIAVKeylistKey2();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAVKeylistKey2." << StrMod::replaceChar(ImeIAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIMStep
 ******************************************************************************/

IexFmncFab::ImeitemIMStep::ImeitemIMStep(
			const uint ixWFilecfg
			, const string& Title
		) : FmncMStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWFilecfg = ixWFilecfg;
	this->Title = Title;
};

IexFmncFab::ImeitemIMStep::ImeitemIMStep(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMStep() {
	FmncMStep* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmstep->loadRecByRef(ref, &rec)) {
		rlvIxVTbl = rec->rlvIxVTbl;
		rlvUref = rec->rlvUref;
		ixWFilecfg = rec->ixWFilecfg;
		Title = rec->Title;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIMStep::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixWFilecfg = VecFmncWMStepFilecfg::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMSTEPPAR)) {
			if (!imeiamsteppar.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2)) {
			if (!imeiavkeylistkey2.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIMStep::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefsIxWFilecfg;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefsIxWFilecfg", "fcf", srefsIxWFilecfg)) {
			ixWFilecfg = VecFmncWMStepFilecfg::getIx(srefsIxWFilecfg);
			ixWIelValid += ImeIMStep::VecWIel::SREFSIXWFILECFG;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMStep::VecWIel::TITLE;
		imeiamsteppar.readXML(docctx, basexpath);
		imeiavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexFmncFab::ImeitemIMStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncWMStepFilecfg::getSrefs(ixWFilecfg) << "\t" << Title << endl;
	imeiamsteppar.writeTxt(outfile);
	imeiavkeylistkey2.writeTxt(outfile);
};

void IexFmncFab::ImeitemIMStep::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fcf","tit"};
	else tags = {"ImeitemIMStep","srefsIxWFilecfg","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncWMStepFilecfg::getSrefs(ixWFilecfg));
		writeString(wr, tags[2], Title);
		imeiamsteppar.writeXML(wr, shorttags);
		imeiavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIMStep::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIMStep::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefsIxWFilecfg") ix |= SREFSIXWFILECFG;
		else if (ss[i] == "Title") ix |= TITLE;
	};

	return(ix);
};

void IexFmncFab::ImeIMStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*TITLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIMStep::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSIXWFILECFG) ss.push_back("srefsIxWFilecfg");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIMStep
 ******************************************************************************/

IexFmncFab::ImeIMStep::ImeIMStep() {
};

IexFmncFab::ImeIMStep::~ImeIMStep() {
	clear();
};

void IexFmncFab::ImeIMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIMStep::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIMStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIMStep();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIMStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIMStep* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMStep");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMStep", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMStep";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIMStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIMStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMStep." << StrMod::replaceChar(ImeIMStep::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIMStep::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMStep");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIRMToolMTooltype
 ******************************************************************************/

IexFmncFab::ImeitemIRMToolMTooltype::ImeitemIRMToolMTooltype(
			const string& hsrefRefFmncMTooltype
			, const string& srefsFmncKToolchar
			, const string& defSrefsFmncKSteppar
			, const string& optSrefsFmncKSteppar
		) : FmncRMToolMTooltype() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMTooltype = hsrefRefFmncMTooltype;
	this->srefsFmncKToolchar = srefsFmncKToolchar;
	this->defSrefsFmncKSteppar = defSrefsFmncKSteppar;
	this->optSrefsFmncKSteppar = optSrefsFmncKSteppar;
};

IexFmncFab::ImeitemIRMToolMTooltype::ImeitemIRMToolMTooltype(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMToolMTooltype() {
	FmncRMToolMTooltype* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmtoolmtooltype->loadRecByRef(ref, &rec)) {
		refFmncMTool = rec->refFmncMTool;
		refFmncMTooltype = rec->refFmncMTooltype;
		srefsFmncKToolchar = rec->srefsFmncKToolchar;
		defSrefsFmncKSteppar = rec->defSrefsFmncKSteppar;
		optSrefsFmncKSteppar = rec->optSrefsFmncKSteppar;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIRMToolMTooltype::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMTooltype = txtrd.fields[0];
	if (txtrd.fields.size() > 1) srefsFmncKToolchar = txtrd.fields[1];
	if (txtrd.fields.size() > 2) defSrefsFmncKSteppar = txtrd.fields[2];
	if (txtrd.fields.size() > 3) optSrefsFmncKSteppar = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIRMToolMTooltype::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMTooltype", "tty", hsrefRefFmncMTooltype)) ixWIelValid += ImeIRMToolMTooltype::VecWIel::HSREFREFFMNCMTOOLTYPE;
		if (extractStringUclc(docctx, basexpath, "srefsFmncKToolchar", "tch", srefsFmncKToolchar)) ixWIelValid += ImeIRMToolMTooltype::VecWIel::SREFSFMNCKTOOLCHAR;
		if (extractStringUclc(docctx, basexpath, "defSrefsFmncKSteppar", "def", defSrefsFmncKSteppar)) ixWIelValid += ImeIRMToolMTooltype::VecWIel::DEFSREFSFMNCKSTEPPAR;
		if (extractStringUclc(docctx, basexpath, "optSrefsFmncKSteppar", "opt", optSrefsFmncKSteppar)) ixWIelValid += ImeIRMToolMTooltype::VecWIel::OPTSREFSFMNCKSTEPPAR;
	};
};

void IexFmncFab::ImeitemIRMToolMTooltype::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefRefFmncMTooltype << "\t" << srefsFmncKToolchar << "\t" << defSrefsFmncKSteppar << "\t" << optSrefsFmncKSteppar << endl;
};

void IexFmncFab::ImeitemIRMToolMTooltype::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tty","tch","def","opt"};
	else tags = {"ImeitemIRMToolMTooltype","hsrefRefFmncMTooltype","srefsFmncKToolchar","defSrefsFmncKSteppar","optSrefsFmncKSteppar"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMTooltype);
		writeString(wr, tags[2], srefsFmncKToolchar);
		writeString(wr, tags[3], defSrefsFmncKSteppar);
		writeString(wr, tags[4], optSrefsFmncKSteppar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIRMToolMTooltype::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIRMToolMTooltype::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMTooltype") ix |= HSREFREFFMNCMTOOLTYPE;
		else if (ss[i] == "srefsFmncKToolchar") ix |= SREFSFMNCKTOOLCHAR;
		else if (ss[i] == "defSrefsFmncKSteppar") ix |= DEFSREFSFMNCKSTEPPAR;
		else if (ss[i] == "optSrefsFmncKSteppar") ix |= OPTSREFSFMNCKSTEPPAR;
	};

	return(ix);
};

void IexFmncFab::ImeIRMToolMTooltype::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*OPTSREFSFMNCKSTEPPAR);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIRMToolMTooltype::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMTOOLTYPE) ss.push_back("hsrefRefFmncMTooltype");
	if (ix & SREFSFMNCKTOOLCHAR) ss.push_back("srefsFmncKToolchar");
	if (ix & DEFSREFSFMNCKSTEPPAR) ss.push_back("defSrefsFmncKSteppar");
	if (ix & OPTSREFSFMNCKSTEPPAR) ss.push_back("optSrefsFmncKSteppar");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIRMToolMTooltype
 ******************************************************************************/

IexFmncFab::ImeIRMToolMTooltype::ImeIRMToolMTooltype() {
};

IexFmncFab::ImeIRMToolMTooltype::~ImeIRMToolMTooltype() {
	clear();
};

void IexFmncFab::ImeIRMToolMTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIRMToolMTooltype::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIRMToolMTooltype* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemIRMToolMTooltype();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIRMToolMTooltype::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIRMToolMTooltype* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMToolMTooltype");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMToolMTooltype", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMToolMTooltype";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIRMToolMTooltype();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIRMToolMTooltype::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMToolMTooltype." << StrMod::replaceChar(ImeIRMToolMTooltype::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIRMToolMTooltype::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMToolMTooltype");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemISvcTMPersonMTool
 ******************************************************************************/

IexFmncFab::ImeitemISvcTMPersonMTool::ImeitemISvcTMPersonMTool(
			const string& hintRefFmncMPerson
		) : FmncSvcTMPersonMTool() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefFmncMPerson = hintRefFmncMPerson;
};

IexFmncFab::ImeitemISvcTMPersonMTool::ImeitemISvcTMPersonMTool(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemISvcTMPersonMTool() {
	FmncSvcTMPersonMTool* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncsvctmpersonmtool->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		refR = rec->refR;

		delete rec;
	};
};

bool IexFmncFab::ImeitemISvcTMPersonMTool::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintRefFmncMPerson = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemISvcTMPersonMTool::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRefFmncMPerson", "prs", hintRefFmncMPerson)) ixWIelValid += ImeISvcTMPersonMTool::VecWIel::HINTREFFMNCMPERSON;
	};
};

void IexFmncFab::ImeitemISvcTMPersonMTool::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hintRefFmncMPerson << endl;
};

void IexFmncFab::ImeitemISvcTMPersonMTool::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs"};
	else tags = {"ImeitemISvcTMPersonMTool","hintRefFmncMPerson"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefFmncMPerson);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeISvcTMPersonMTool::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeISvcTMPersonMTool::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintRefFmncMPerson") ix |= HINTREFFMNCMPERSON;
	};

	return(ix);
};

void IexFmncFab::ImeISvcTMPersonMTool::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HINTREFFMNCMPERSON);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeISvcTMPersonMTool::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFFMNCMPERSON) ss.push_back("hintRefFmncMPerson");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeISvcTMPersonMTool
 ******************************************************************************/

IexFmncFab::ImeISvcTMPersonMTool::ImeISvcTMPersonMTool() {
};

IexFmncFab::ImeISvcTMPersonMTool::~ImeISvcTMPersonMTool() {
	clear();
};

void IexFmncFab::ImeISvcTMPersonMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeISvcTMPersonMTool::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemISvcTMPersonMTool* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncFab::ImeitemISvcTMPersonMTool();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeISvcTMPersonMTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemISvcTMPersonMTool* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeISvcTMPersonMTool");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemISvcTMPersonMTool", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemISvcTMPersonMTool";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemISvcTMPersonMTool();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeISvcTMPersonMTool::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeISvcTMPersonMTool." << StrMod::replaceChar(ImeISvcTMPersonMTool::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeISvcTMPersonMTool::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeISvcTMPersonMTool");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemISvcRMOrgMTool
 ******************************************************************************/

IexFmncFab::ImeitemISvcRMOrgMTool::ImeitemISvcRMOrgMTool(
			const string& hsrefRefFmncMOrg
		) : FmncSvcRMOrgMTool() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMOrg = hsrefRefFmncMOrg;
};

IexFmncFab::ImeitemISvcRMOrgMTool::ImeitemISvcRMOrgMTool(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemISvcRMOrgMTool() {
	FmncSvcRMOrgMTool* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncsvcrmorgmtool->loadRecByRef(ref, &rec)) {
		refFmncMOrg = rec->refFmncMOrg;
		refFmncMTool = rec->refFmncMTool;

		delete rec;
	};
};

bool IexFmncFab::ImeitemISvcRMOrgMTool::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMOrg = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEISVCTMPERSONMTOOL)) {
			if (!imeisvctmpersonmtool.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemISvcRMOrgMTool::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMOrg", "mnf", hsrefRefFmncMOrg)) ixWIelValid += ImeISvcRMOrgMTool::VecWIel::HSREFREFFMNCMORG;
		imeisvctmpersonmtool.readXML(docctx, basexpath);
	};
};

void IexFmncFab::ImeitemISvcRMOrgMTool::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefRefFmncMOrg << endl;
	imeisvctmpersonmtool.writeTxt(outfile);
};

void IexFmncFab::ImeitemISvcRMOrgMTool::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mnf"};
	else tags = {"ImeitemISvcRMOrgMTool","hsrefRefFmncMOrg"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMOrg);
		imeisvctmpersonmtool.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeISvcRMOrgMTool::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeISvcRMOrgMTool::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMOrg") ix |= HSREFREFFMNCMORG;
	};

	return(ix);
};

void IexFmncFab::ImeISvcRMOrgMTool::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HSREFREFFMNCMORG);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeISvcRMOrgMTool::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMORG) ss.push_back("hsrefRefFmncMOrg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeISvcRMOrgMTool
 ******************************************************************************/

IexFmncFab::ImeISvcRMOrgMTool::ImeISvcRMOrgMTool() {
};

IexFmncFab::ImeISvcRMOrgMTool::~ImeISvcRMOrgMTool() {
	clear();
};

void IexFmncFab::ImeISvcRMOrgMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeISvcRMOrgMTool::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemISvcRMOrgMTool* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncFab::ImeitemISvcRMOrgMTool();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeISvcRMOrgMTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemISvcRMOrgMTool* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeISvcRMOrgMTool");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemISvcRMOrgMTool", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemISvcRMOrgMTool";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemISvcRMOrgMTool();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeISvcRMOrgMTool::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeISvcRMOrgMTool." << StrMod::replaceChar(ImeISvcRMOrgMTool::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeISvcRMOrgMTool::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeISvcRMOrgMTool");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncFab::ImeitemIMTool
 ******************************************************************************/

IexFmncFab::ImeitemIMTool::ImeitemIMTool(
			const string& hintFabRefFmncMFab
			, const string& hsrefMnfRefFmncMOrg
			, const string& Title
			, const string& Training
			, const string& Comment
		) : FmncMTool() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintFabRefFmncMFab = hintFabRefFmncMFab;
	this->hsrefMnfRefFmncMOrg = hsrefMnfRefFmncMOrg;
	this->Title = Title;
	this->Training = Training;
	this->Comment = Comment;
};

IexFmncFab::ImeitemIMTool::ImeitemIMTool(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMTool() {
	FmncMTool* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmtool->loadRecByRef(ref, &rec)) {
		fabRefFmncMFab = rec->fabRefFmncMFab;
		mnfRefFmncMOrg = rec->mnfRefFmncMOrg;
		Title = rec->Title;
		refJUnitprice = rec->refJUnitprice;
		Training = rec->Training;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncFab::ImeitemIMTool::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintFabRefFmncMFab = txtrd.fields[0];
	if (txtrd.fields.size() > 1) hsrefMnfRefFmncMOrg = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Title = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Training = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Comment = txtrd.fields[4];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMTOOLAVL)) {
			if (!imeiamtoolavl.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMTOOLCHAR)) {
			if (!imeiamtoolchar.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1)) {
			if (!imeiavkeylistkey1.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIFABSMPERSONMTOOL)) {
			if (!imeifabsmpersonmtool.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMTOOLUNITPRICE)) {
			if (!imeijmtoolunitprice.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMARTICLE)) {
			if (!imeimarticle.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMFILE1)) {
			if (!imeimfile1.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMNFSMPERSONMTOOL)) {
			if (!imeimnfsmpersonmtool.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSTEP)) {
			if (!imeimstep.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMTOOLMTOOLTYPE)) {
			if (!imeirmtoolmtooltype.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEISVCRMORGMTOOL)) {
			if (!imeisvcrmorgmtool.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeitemIMTool::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintFabRefFmncMFab", "fab", hintFabRefFmncMFab)) ixWIelValid += ImeIMTool::VecWIel::HINTFABREFFMNCMFAB;
		if (extractStringUclc(docctx, basexpath, "hsrefMnfRefFmncMOrg", "mnf", hsrefMnfRefFmncMOrg)) ixWIelValid += ImeIMTool::VecWIel::HSREFMNFREFFMNCMORG;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMTool::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Training", "trn", Training)) ixWIelValid += ImeIMTool::VecWIel::TRAINING;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMTool::VecWIel::COMMENT;
		imeiamtoolavl.readXML(docctx, basexpath);
		imeiamtoolchar.readXML(docctx, basexpath);
		imeiavkeylistkey1.readXML(docctx, basexpath);
		imeifabsmpersonmtool.readXML(docctx, basexpath);
		imeijmtoolunitprice.readXML(docctx, basexpath);
		imeimarticle.readXML(docctx, basexpath);
		imeimfile1.readXML(docctx, basexpath);
		imeimnfsmpersonmtool.readXML(docctx, basexpath);
		imeimstep.readXML(docctx, basexpath);
		imeirmtoolmtooltype.readXML(docctx, basexpath);
		imeisvcrmorgmtool.readXML(docctx, basexpath);
	};
};

void IexFmncFab::ImeitemIMTool::writeTxt(
			fstream& outfile
		) {
	outfile << hintFabRefFmncMFab << "\t" << hsrefMnfRefFmncMOrg << "\t" << Title << "\t" << Training << "\t" << Comment << endl;
	imeiamtoolavl.writeTxt(outfile);
	imeiamtoolchar.writeTxt(outfile);
	imeiavkeylistkey1.writeTxt(outfile);
	imeifabsmpersonmtool.writeTxt(outfile);
	imeijmtoolunitprice.writeTxt(outfile);
	imeimarticle.writeTxt(outfile);
	imeimfile1.writeTxt(outfile);
	imeimnfsmpersonmtool.writeTxt(outfile);
	imeimstep.writeTxt(outfile);
	imeirmtoolmtooltype.writeTxt(outfile);
	imeisvcrmorgmtool.writeTxt(outfile);
};

void IexFmncFab::ImeitemIMTool::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fab","mnf","tit","trn","cmt"};
	else tags = {"ImeitemIMTool","hintFabRefFmncMFab","hsrefMnfRefFmncMOrg","Title","Training","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintFabRefFmncMFab);
		writeString(wr, tags[2], hsrefMnfRefFmncMOrg);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Training);
		writeString(wr, tags[5], Comment);
		imeiamtoolavl.writeXML(wr, shorttags);
		imeiamtoolchar.writeXML(wr, shorttags);
		imeiavkeylistkey1.writeXML(wr, shorttags);
		imeifabsmpersonmtool.writeXML(wr, shorttags);
		imeijmtoolunitprice.writeXML(wr, shorttags);
		imeimarticle.writeXML(wr, shorttags);
		imeimfile1.writeXML(wr, shorttags);
		imeimnfsmpersonmtool.writeXML(wr, shorttags);
		imeimstep.writeXML(wr, shorttags);
		imeirmtoolmtooltype.writeXML(wr, shorttags);
		imeisvcrmorgmtool.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncFab::ImeIMTool::VecWIel
 ******************************************************************************/

uint IexFmncFab::ImeIMTool::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintFabRefFmncMFab") ix |= HINTFABREFFMNCMFAB;
		else if (ss[i] == "hsrefMnfRefFmncMOrg") ix |= HSREFMNFREFFMNCMORG;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Training") ix |= TRAINING;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncFab::ImeIMTool::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncFab::ImeIMTool::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTFABREFFMNCMFAB) ss.push_back("hintFabRefFmncMFab");
	if (ix & HSREFMNFREFFMNCMORG) ss.push_back("hsrefMnfRefFmncMOrg");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & TRAINING) ss.push_back("Training");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncFab::ImeIMTool
 ******************************************************************************/

IexFmncFab::ImeIMTool::ImeIMTool() {
};

IexFmncFab::ImeIMTool::~ImeIMTool() {
	clear();
};

void IexFmncFab::ImeIMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncFab::ImeIMTool::readTxt(
			Txtrd& txtrd
		) {
	IexFmncFab::ImeitemIMTool* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncFab::ImeitemIMTool();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncFab::ImeIMTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncFab::ImeitemIMTool* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTool");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTool", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTool";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncFab::ImeitemIMTool();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncFab::ImeIMTool::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMTool." << StrMod::replaceChar(ImeIMTool::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncFab::ImeIMTool::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTool");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};


