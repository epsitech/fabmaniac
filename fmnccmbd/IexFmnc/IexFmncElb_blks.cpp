/**
  * \file IexFmncElb_blks.cpp
  * import/export handler for database DbsFmnc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class IexFmncElb::VecVIme
 ******************************************************************************/

uint IexFmncElb::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimfile1") return IMEIMFILE1;
	else if (s == "imeimproject") return IMEIMPROJECT;
	else if (s == "imeimsample") return IMEIMSAMPLE;
	else if (s == "imeiamsamplepar") return IMEIAMSAMPLEPAR;
	else if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	else if (s == "imeijmprojectstate") return IMEIJMPROJECTSTATE;
	else if (s == "imeijmsamplestate") return IMEIJMSAMPLESTATE;
	else if (s == "imeimfile2") return IMEIMFILE2;
	else if (s == "imeimrun") return IMEIMRUN;
	else if (s == "imeirmfilemsample") return IMEIRMFILEMSAMPLE;
	else if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	else if (s == "imeijmrunstate") return IMEIJMRUNSTATE;
	else if (s == "imeimactivity") return IMEIMACTIVITY;
	else if (s == "imeimfile3") return IMEIMFILE3;
	else if (s == "imeirmfabmrun") return IMEIRMFABMRUN;
	else if (s == "imeirmpersonmrun") return IMEIRMPERSONMRUN;
	else if (s == "imeirmrunmsample") return IMEIRMRUNMSAMPLE;
	else if (s == "imeimstep") return IMEIMSTEP;
	else if (s == "imeiamsteppar") return IMEIAMSTEPPAR;
	else if (s == "imeimfile4") return IMEIMFILE4;
	else if (s == "imeirmfilemstep1") return IMEIRMFILEMSTEP1;
	else if (s == "imeirmfilemstep2") return IMEIRMFILEMSTEP2;
	else if (s == "imeirmsamplemstep") return IMEIRMSAMPLEMSTEP;
	else if (s == "imeitmfilemsample1") return IMEITMFILEMSAMPLE1;
	else if (s == "imeitmfilemsample2") return IMEITMFILEMSAMPLE2;

	return(0);
};

string IexFmncElb::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMFILE1) return("ImeIMFile1");
	else if (ix == IMEIMPROJECT) return("ImeIMProject");
	else if (ix == IMEIMSAMPLE) return("ImeIMSample");
	else if (ix == IMEIAMSAMPLEPAR) return("ImeIAMSamplePar");
	else if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	else if (ix == IMEIJMPROJECTSTATE) return("ImeIJMProjectState");
	else if (ix == IMEIJMSAMPLESTATE) return("ImeIJMSampleState");
	else if (ix == IMEIMFILE2) return("ImeIMFile2");
	else if (ix == IMEIMRUN) return("ImeIMRun");
	else if (ix == IMEIRMFILEMSAMPLE) return("ImeIRMFileMSample");
	else if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	else if (ix == IMEIJMRUNSTATE) return("ImeIJMRunState");
	else if (ix == IMEIMACTIVITY) return("ImeIMActivity");
	else if (ix == IMEIMFILE3) return("ImeIMFile3");
	else if (ix == IMEIRMFABMRUN) return("ImeIRMFabMRun");
	else if (ix == IMEIRMPERSONMRUN) return("ImeIRMPersonMRun");
	else if (ix == IMEIRMRUNMSAMPLE) return("ImeIRMRunMSample");
	else if (ix == IMEIMSTEP) return("ImeIMStep");
	else if (ix == IMEIAMSTEPPAR) return("ImeIAMStepPar");
	else if (ix == IMEIMFILE4) return("ImeIMFile4");
	else if (ix == IMEIRMFILEMSTEP1) return("ImeIRMFileMStep1");
	else if (ix == IMEIRMFILEMSTEP2) return("ImeIRMFileMStep2");
	else if (ix == IMEIRMSAMPLEMSTEP) return("ImeIRMSampleMStep");
	else if (ix == IMEITMFILEMSAMPLE1) return("ImeITMFileMSample1");
	else if (ix == IMEITMFILEMSAMPLE2) return("ImeITMFileMSample2");

	return("");
};

/******************************************************************************
 class IexFmncElb::ImeitemIMFile1
 ******************************************************************************/

IexFmncElb::ImeitemIMFile1::ImeitemIMFile1(
			const ubigint iref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : FmncMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIMFile1::ImeitemIMFile1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMFile1() {
	FmncMFile* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIMFile1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) osrefKContent = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Filename = txtrd.fields[2];
	if (txtrd.fields.size() > 3) srefKMimetype = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Comment = txtrd.fields[4];

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

void IexFmncElb::ImeitemIMFile1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMFile1::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile1::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile1::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile1::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile1::VecWIel::COMMENT;
	};
};

void IexFmncElb::ImeitemIMFile1::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexFmncElb::ImeitemIMFile1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile1","iref","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], osrefKContent);
		writeString(wr, tags[3], Filename);
		writeString(wr, tags[4], srefKMimetype);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMFile1::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMFile1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "osrefKContent") ix |= OSREFKCONTENT;
		else if (ss[i] == "Filename") ix |= FILENAME;
		else if (ss[i] == "srefKMimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIMFile1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMFile1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMFile1
 ******************************************************************************/

IexFmncElb::ImeIMFile1::ImeIMFile1() {
};

IexFmncElb::ImeIMFile1::~ImeIMFile1() {
	clear();
};

void IexFmncElb::ImeIMFile1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMFile1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMFile1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncElb::ImeitemIMFile1();

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

void IexFmncElb::ImeIMFile1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMFile1* ii = NULL;

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

			ii = new IexFmncElb::ImeitemIMFile1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMFile1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile1." << StrMod::replaceChar(ImeIMFile1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMFile1::writeXML(
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
 class IexFmncElb::ImeitemIJMProjectState
 ******************************************************************************/

IexFmncElb::ImeitemIJMProjectState::ImeitemIJMProjectState(
			const uint x1Start
			, const uint ixVState
		) : FmncJMProjectState() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

IexFmncElb::ImeitemIJMProjectState::ImeitemIJMProjectState(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMProjectState() {
	FmncJMProjectState* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmprojectstate->loadRecByRef(ref, &rec)) {
		refFmncMProject = rec->refFmncMProject;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIJMProjectState::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1Start = Ftm::invstamp(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) ixVState = VecFmncVMProjectState::getIx(txtrd.fields[1]);

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

void IexFmncElb::ImeitemIJMProjectState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string ftmX1Start;
	string srefIxVState;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start)) {
			x1Start = Ftm::invstamp(ftmX1Start);
			ixWIelValid += ImeIJMProjectState::VecWIel::FTMX1START;
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) {
			ixVState = VecFmncVMProjectState::getIx(srefIxVState);
			ixWIelValid += ImeIJMProjectState::VecWIel::SREFIXVSTATE;
		};
	};
};

void IexFmncElb::ImeitemIJMProjectState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Ftm::stamp(x1Start)
 << "\t" << VecFmncVMProjectState::getSref(ixVState) << endl;
};

void IexFmncElb::ImeitemIJMProjectState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sta","ste"};
	else tags = {"ImeitemIJMProjectState","ftmX1Start","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Ftm::stamp(x1Start));
		writeString(wr, tags[2], VecFmncVMProjectState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIJMProjectState::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIJMProjectState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "ftmX1Start") ix |= FTMX1START;
		else if (ss[i] == "srefIxVState") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexFmncElb::ImeIJMProjectState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVSTATE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIJMProjectState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FTMX1START) ss.push_back("ftmX1Start");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIJMProjectState
 ******************************************************************************/

IexFmncElb::ImeIJMProjectState::ImeIJMProjectState() {
};

IexFmncElb::ImeIJMProjectState::~ImeIJMProjectState() {
	clear();
};

void IexFmncElb::ImeIJMProjectState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIJMProjectState::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIJMProjectState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIJMProjectState();

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

void IexFmncElb::ImeIJMProjectState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIJMProjectState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMProjectState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMProjectState", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMProjectState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIJMProjectState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIJMProjectState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMProjectState." << StrMod::replaceChar(ImeIJMProjectState::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIJMProjectState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMProjectState");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIJMRunState
 ******************************************************************************/

IexFmncElb::ImeitemIJMRunState::ImeitemIJMRunState(
			const uint x1Start
			, const uint ixVState
		) : FmncJMRunState() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

IexFmncElb::ImeitemIJMRunState::ImeitemIJMRunState(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMRunState() {
	FmncJMRunState* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmrunstate->loadRecByRef(ref, &rec)) {
		refFmncMRun = rec->refFmncMRun;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIJMRunState::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1Start = Ftm::invstamp(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) ixVState = VecFmncVMRunState::getIx(txtrd.fields[1]);

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

void IexFmncElb::ImeitemIJMRunState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string ftmX1Start;
	string srefIxVState;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start)) {
			x1Start = Ftm::invstamp(ftmX1Start);
			ixWIelValid += ImeIJMRunState::VecWIel::FTMX1START;
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) {
			ixVState = VecFmncVMRunState::getIx(srefIxVState);
			ixWIelValid += ImeIJMRunState::VecWIel::SREFIXVSTATE;
		};
	};
};

void IexFmncElb::ImeitemIJMRunState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Ftm::stamp(x1Start)
 << "\t" << VecFmncVMRunState::getSref(ixVState) << endl;
};

void IexFmncElb::ImeitemIJMRunState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sta","ste"};
	else tags = {"ImeitemIJMRunState","ftmX1Start","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Ftm::stamp(x1Start));
		writeString(wr, tags[2], VecFmncVMRunState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIJMRunState::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIJMRunState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "ftmX1Start") ix |= FTMX1START;
		else if (ss[i] == "srefIxVState") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexFmncElb::ImeIJMRunState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVSTATE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIJMRunState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FTMX1START) ss.push_back("ftmX1Start");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIJMRunState
 ******************************************************************************/

IexFmncElb::ImeIJMRunState::ImeIJMRunState() {
};

IexFmncElb::ImeIJMRunState::~ImeIJMRunState() {
	clear();
};

void IexFmncElb::ImeIJMRunState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIJMRunState::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIJMRunState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIJMRunState();

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

void IexFmncElb::ImeIJMRunState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIJMRunState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMRunState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMRunState", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMRunState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIJMRunState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIJMRunState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMRunState." << StrMod::replaceChar(ImeIJMRunState::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIJMRunState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMRunState");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIAMStepPar
 ******************************************************************************/

IexFmncElb::ImeitemIAMStepPar::ImeitemIAMStepPar(
			const string& x1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const string& hintX2Uref
			, const string& Val
			, const string& Comment
		) : FmncAMStepPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1OsrefFmncKSteppar = x1OsrefFmncKSteppar;
	this->x2IxVTbl = x2IxVTbl;
	this->hintX2Uref = hintX2Uref;
	this->Val = Val;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIAMStepPar::ImeitemIAMStepPar(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMStepPar() {
	FmncAMStepPar* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamsteppar->loadRecByRef(ref, &rec)) {
		refFmncMStep = rec->refFmncMStep;
		x1OsrefFmncKSteppar = rec->x1OsrefFmncKSteppar;
		x2IxVTbl = rec->x2IxVTbl;
		x2Uref = rec->x2Uref;
		Val = rec->Val;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIAMStepPar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1OsrefFmncKSteppar = txtrd.fields[0];
	if (txtrd.fields.size() > 1) x2IxVTbl = VecFmncVAMStepParTbl::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) hintX2Uref = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Val = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Comment = txtrd.fields[4];

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

void IexFmncElb::ImeitemIAMStepPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX2IxVTbl;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1OsrefFmncKSteppar", "spa", x1OsrefFmncKSteppar)) ixWIelValid += ImeIAMStepPar::VecWIel::X1OSREFFMNCKSTEPPAR;
		if (extractStringUclc(docctx, basexpath, "srefX2IxVTbl", "ret", srefX2IxVTbl)) {
			x2IxVTbl = VecFmncVAMStepParTbl::getIx(srefX2IxVTbl);
			ixWIelValid += ImeIAMStepPar::VecWIel::SREFX2IXVTBL;
		};
		if (extractStringUclc(docctx, basexpath, "hintX2Uref", "reu", hintX2Uref)) ixWIelValid += ImeIAMStepPar::VecWIel::HINTX2UREF;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMStepPar::VecWIel::VAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMStepPar::VecWIel::COMMENT;
	};
};

void IexFmncElb::ImeitemIAMStepPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << x1OsrefFmncKSteppar << "\t" << VecFmncVAMStepParTbl::getSref(x2IxVTbl) << "\t" << hintX2Uref << "\t" << Val << "\t" << Comment << endl;
};

void IexFmncElb::ImeitemIAMStepPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","spa","ret","reu","val","cmt"};
	else tags = {"ImeitemIAMStepPar","x1OsrefFmncKSteppar","srefX2IxVTbl","hintX2Uref","Val","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1OsrefFmncKSteppar);
		writeString(wr, tags[2], VecFmncVAMStepParTbl::getSref(x2IxVTbl));
		writeString(wr, tags[3], hintX2Uref);
		writeString(wr, tags[4], Val);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIAMStepPar::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIAMStepPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x1OsrefFmncKSteppar") ix |= X1OSREFFMNCKSTEPPAR;
		else if (ss[i] == "srefX2IxVTbl") ix |= SREFX2IXVTBL;
		else if (ss[i] == "hintX2Uref") ix |= HINTX2UREF;
		else if (ss[i] == "Val") ix |= VAL;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIAMStepPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIAMStepPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1OSREFFMNCKSTEPPAR) ss.push_back("x1OsrefFmncKSteppar");
	if (ix & SREFX2IXVTBL) ss.push_back("srefX2IxVTbl");
	if (ix & HINTX2UREF) ss.push_back("hintX2Uref");
	if (ix & VAL) ss.push_back("Val");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIAMStepPar
 ******************************************************************************/

IexFmncElb::ImeIAMStepPar::ImeIAMStepPar() {
};

IexFmncElb::ImeIAMStepPar::~ImeIAMStepPar() {
	clear();
};

void IexFmncElb::ImeIAMStepPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIAMStepPar::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIAMStepPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 4)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 4)) {
			ii = new IexFmncElb::ImeitemIAMStepPar();

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

void IexFmncElb::ImeIAMStepPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIAMStepPar* ii = NULL;

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

			ii = new IexFmncElb::ImeitemIAMStepPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIAMStepPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMStepPar." << StrMod::replaceChar(ImeIAMStepPar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIAMStepPar::writeXML(
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
 class IexFmncElb::ImeitemIMFile4
 ******************************************************************************/

IexFmncElb::ImeitemIMFile4::ImeitemIMFile4(
			const ubigint iref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : FmncMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIMFile4::ImeitemIMFile4(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMFile4() {
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

bool IexFmncElb::ImeitemIMFile4::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) osrefKContent = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Filename = txtrd.fields[2];
	if (txtrd.fields.size() > 3) srefKMimetype = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Comment = txtrd.fields[4];

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

void IexFmncElb::ImeitemIMFile4::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMFile4::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile4::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile4::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile4::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile4::VecWIel::COMMENT;
	};
};

void IexFmncElb::ImeitemIMFile4::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << iref << "\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexFmncElb::ImeitemIMFile4::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile4","iref","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], osrefKContent);
		writeString(wr, tags[3], Filename);
		writeString(wr, tags[4], srefKMimetype);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMFile4::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMFile4::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "osrefKContent") ix |= OSREFKCONTENT;
		else if (ss[i] == "Filename") ix |= FILENAME;
		else if (ss[i] == "srefKMimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIMFile4::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMFile4::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMFile4
 ******************************************************************************/

IexFmncElb::ImeIMFile4::ImeIMFile4() {
};

IexFmncElb::ImeIMFile4::~ImeIMFile4() {
	clear();
};

void IexFmncElb::ImeIMFile4::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMFile4::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMFile4* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 4)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 4)) {
			ii = new IexFmncElb::ImeitemIMFile4();

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

void IexFmncElb::ImeIMFile4::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMFile4* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile4");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile4", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile4";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIMFile4();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMFile4::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMFile4." << StrMod::replaceChar(ImeIMFile4::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMFile4::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile4");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemITMFileMSample1
 ******************************************************************************/

IexFmncElb::ImeitemITMFileMSample1::ImeitemITMFileMSample1(
			const string& hsrefRefFmncMSample
		) : FmncTMFileMSample() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMSample = hsrefRefFmncMSample;
};

IexFmncElb::ImeitemITMFileMSample1::ImeitemITMFileMSample1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemITMFileMSample1() {
	FmncTMFileMSample* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmnctmfilemsample->loadRecByRef(ref, &rec)) {
		refR = rec->refR;
		refFmncMSample = rec->refFmncMSample;

		delete rec;
	};
};

bool IexFmncElb::ImeitemITMFileMSample1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMSample = txtrd.fields[0];

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

void IexFmncElb::ImeitemITMFileMSample1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMSample", "smp", hsrefRefFmncMSample)) ixWIelValid += ImeITMFileMSample1::VecWIel::HSREFREFFMNCMSAMPLE;
	};
};

void IexFmncElb::ImeitemITMFileMSample1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t\t" << hsrefRefFmncMSample << endl;
};

void IexFmncElb::ImeitemITMFileMSample1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","smp"};
	else tags = {"ImeitemITMFileMSample1","hsrefRefFmncMSample"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMSample);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeITMFileMSample1::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeITMFileMSample1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMSample") ix |= HSREFREFFMNCMSAMPLE;
	};

	return(ix);
};

void IexFmncElb::ImeITMFileMSample1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HSREFREFFMNCMSAMPLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeITMFileMSample1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMSAMPLE) ss.push_back("hsrefRefFmncMSample");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeITMFileMSample1
 ******************************************************************************/

IexFmncElb::ImeITMFileMSample1::ImeITMFileMSample1() {
};

IexFmncElb::ImeITMFileMSample1::~ImeITMFileMSample1() {
	clear();
};

void IexFmncElb::ImeITMFileMSample1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeITMFileMSample1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemITMFileMSample1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 5)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 5)) {
			ii = new IexFmncElb::ImeitemITMFileMSample1();

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

void IexFmncElb::ImeITMFileMSample1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemITMFileMSample1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeITMFileMSample1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemITMFileMSample1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemITMFileMSample1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemITMFileMSample1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeITMFileMSample1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\t\tImeITMFileMSample1." << StrMod::replaceChar(ImeITMFileMSample1::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeITMFileMSample1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeITMFileMSample1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIRMFileMStep1
 ******************************************************************************/

IexFmncElb::ImeitemIRMFileMStep1::ImeitemIRMFileMStep1(
			const ubigint irefRefFmncMFile
			, const uint ixVDir
		) : FmncRMFileMStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefFmncMFile = irefRefFmncMFile;
	this->ixVDir = ixVDir;
};

IexFmncElb::ImeitemIRMFileMStep1::ImeitemIRMFileMStep1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMFileMStep1() {
	FmncRMFileMStep* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmfilemstep->loadRecByRef(ref, &rec)) {
		refFmncMFile = rec->refFmncMFile;
		refFmncMStep = rec->refFmncMStep;
		ixVDir = rec->ixVDir;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMFileMStep1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) irefRefFmncMFile = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) ixVDir = VecFmncVRMFileMStepDir::getIx(txtrd.fields[1]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 5) && (txtrd.ixVToken == VecVIme::IMEITMFILEMSAMPLE1)) {
			if (!imeitmfilemsample1.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIRMFileMStep1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVDir;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefFmncMFile", "fil", irefRefFmncMFile)) ixWIelValid += ImeIRMFileMStep1::VecWIel::IREFREFFMNCMFILE;
		if (extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir)) {
			ixVDir = VecFmncVRMFileMStepDir::getIx(srefIxVDir);
			ixWIelValid += ImeIRMFileMStep1::VecWIel::SREFIXVDIR;
		};
		imeitmfilemsample1.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIRMFileMStep1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << irefRefFmncMFile << "\t" << VecFmncVRMFileMStepDir::getSref(ixVDir) << endl;
	imeitmfilemsample1.writeTxt(outfile);
};

void IexFmncElb::ImeitemIRMFileMStep1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fil","dir"};
	else tags = {"ImeitemIRMFileMStep1","irefRefFmncMFile","srefIxVDir"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefFmncMFile);
		writeString(wr, tags[2], VecFmncVRMFileMStepDir::getSref(ixVDir));
		imeitmfilemsample1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFileMStep1::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMFileMStep1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "irefRefFmncMFile") ix |= IREFREFFMNCMFILE;
		else if (ss[i] == "srefIxVDir") ix |= SREFIXVDIR;
	};

	return(ix);
};

void IexFmncElb::ImeIRMFileMStep1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVDIR);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMFileMStep1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFFMNCMFILE) ss.push_back("irefRefFmncMFile");
	if (ix & SREFIXVDIR) ss.push_back("srefIxVDir");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFileMStep1
 ******************************************************************************/

IexFmncElb::ImeIRMFileMStep1::ImeIRMFileMStep1() {
};

IexFmncElb::ImeIRMFileMStep1::~ImeIRMFileMStep1() {
	clear();
};

void IexFmncElb::ImeIRMFileMStep1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMFileMStep1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMFileMStep1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 4)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 4)) {
			ii = new IexFmncElb::ImeitemIRMFileMStep1();

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

void IexFmncElb::ImeIRMFileMStep1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMFileMStep1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMFileMStep1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMFileMStep1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMFileMStep1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMFileMStep1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMFileMStep1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIRMFileMStep1." << StrMod::replaceChar(ImeIRMFileMStep1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMFileMStep1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMFileMStep1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemITMFileMSample2
 ******************************************************************************/

IexFmncElb::ImeitemITMFileMSample2::ImeitemITMFileMSample2(
			const string& hsrefRefFmncMSample
		) : FmncTMFileMSample() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMSample = hsrefRefFmncMSample;
};

IexFmncElb::ImeitemITMFileMSample2::ImeitemITMFileMSample2(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemITMFileMSample2() {
	FmncTMFileMSample* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmnctmfilemsample->loadRecByRef(ref, &rec)) {
		refR = rec->refR;
		refFmncMSample = rec->refFmncMSample;

		delete rec;
	};
};

bool IexFmncElb::ImeitemITMFileMSample2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMSample = txtrd.fields[0];

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

void IexFmncElb::ImeitemITMFileMSample2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMSample", "smp", hsrefRefFmncMSample)) ixWIelValid += ImeITMFileMSample2::VecWIel::HSREFREFFMNCMSAMPLE;
	};
};

void IexFmncElb::ImeitemITMFileMSample2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t\t" << hsrefRefFmncMSample << endl;
};

void IexFmncElb::ImeitemITMFileMSample2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","smp"};
	else tags = {"ImeitemITMFileMSample2","hsrefRefFmncMSample"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMSample);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeITMFileMSample2::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeITMFileMSample2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMSample") ix |= HSREFREFFMNCMSAMPLE;
	};

	return(ix);
};

void IexFmncElb::ImeITMFileMSample2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HSREFREFFMNCMSAMPLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeITMFileMSample2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMSAMPLE) ss.push_back("hsrefRefFmncMSample");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeITMFileMSample2
 ******************************************************************************/

IexFmncElb::ImeITMFileMSample2::ImeITMFileMSample2() {
};

IexFmncElb::ImeITMFileMSample2::~ImeITMFileMSample2() {
	clear();
};

void IexFmncElb::ImeITMFileMSample2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeITMFileMSample2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemITMFileMSample2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 5)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 5)) {
			ii = new IexFmncElb::ImeitemITMFileMSample2();

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

void IexFmncElb::ImeITMFileMSample2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemITMFileMSample2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeITMFileMSample2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemITMFileMSample2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemITMFileMSample2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemITMFileMSample2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeITMFileMSample2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\t\tImeITMFileMSample2." << StrMod::replaceChar(ImeITMFileMSample2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeITMFileMSample2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeITMFileMSample2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIRMFileMStep2
 ******************************************************************************/

IexFmncElb::ImeitemIRMFileMStep2::ImeitemIRMFileMStep2(
			const ubigint irefRefFmncMFile
			, const uint ixVDir
		) : FmncRMFileMStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefFmncMFile = irefRefFmncMFile;
	this->ixVDir = ixVDir;
};

IexFmncElb::ImeitemIRMFileMStep2::ImeitemIRMFileMStep2(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMFileMStep2() {
	FmncRMFileMStep* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmfilemstep->loadRecByRef(ref, &rec)) {
		refFmncMFile = rec->refFmncMFile;
		refFmncMStep = rec->refFmncMStep;
		ixVDir = rec->ixVDir;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMFileMStep2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) irefRefFmncMFile = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) ixVDir = VecFmncVRMFileMStepDir::getIx(txtrd.fields[1]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 5) && (txtrd.ixVToken == VecVIme::IMEITMFILEMSAMPLE2)) {
			if (!imeitmfilemsample2.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIRMFileMStep2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVDir;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefFmncMFile", "fil", irefRefFmncMFile)) ixWIelValid += ImeIRMFileMStep2::VecWIel::IREFREFFMNCMFILE;
		if (extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir)) {
			ixVDir = VecFmncVRMFileMStepDir::getIx(srefIxVDir);
			ixWIelValid += ImeIRMFileMStep2::VecWIel::SREFIXVDIR;
		};
		imeitmfilemsample2.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIRMFileMStep2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << irefRefFmncMFile << "\t" << VecFmncVRMFileMStepDir::getSref(ixVDir) << endl;
	imeitmfilemsample2.writeTxt(outfile);
};

void IexFmncElb::ImeitemIRMFileMStep2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fil","dir"};
	else tags = {"ImeitemIRMFileMStep2","irefRefFmncMFile","srefIxVDir"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefFmncMFile);
		writeString(wr, tags[2], VecFmncVRMFileMStepDir::getSref(ixVDir));
		imeitmfilemsample2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFileMStep2::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMFileMStep2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "irefRefFmncMFile") ix |= IREFREFFMNCMFILE;
		else if (ss[i] == "srefIxVDir") ix |= SREFIXVDIR;
	};

	return(ix);
};

void IexFmncElb::ImeIRMFileMStep2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVDIR);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMFileMStep2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFFMNCMFILE) ss.push_back("irefRefFmncMFile");
	if (ix & SREFIXVDIR) ss.push_back("srefIxVDir");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFileMStep2
 ******************************************************************************/

IexFmncElb::ImeIRMFileMStep2::ImeIRMFileMStep2() {
};

IexFmncElb::ImeIRMFileMStep2::~ImeIRMFileMStep2() {
	clear();
};

void IexFmncElb::ImeIRMFileMStep2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMFileMStep2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMFileMStep2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 4)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 4)) {
			ii = new IexFmncElb::ImeitemIRMFileMStep2();

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

void IexFmncElb::ImeIRMFileMStep2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMFileMStep2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMFileMStep2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMFileMStep2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMFileMStep2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMFileMStep2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMFileMStep2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIRMFileMStep2." << StrMod::replaceChar(ImeIRMFileMStep2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMFileMStep2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMFileMStep2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIRMSampleMStep
 ******************************************************************************/

IexFmncElb::ImeitemIRMSampleMStep::ImeitemIRMSampleMStep(
			const string& hsrefRefFmncMSample
		) : FmncRMSampleMStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMSample = hsrefRefFmncMSample;
};

IexFmncElb::ImeitemIRMSampleMStep::ImeitemIRMSampleMStep(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMSampleMStep() {
	FmncRMSampleMStep* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmsamplemstep->loadRecByRef(ref, &rec)) {
		refFmncMSample = rec->refFmncMSample;
		refFmncMStep = rec->refFmncMStep;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMSampleMStep::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMSample = txtrd.fields[0];

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

void IexFmncElb::ImeitemIRMSampleMStep::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMSample", "smp", hsrefRefFmncMSample)) ixWIelValid += ImeIRMSampleMStep::VecWIel::HSREFREFFMNCMSAMPLE;
	};
};

void IexFmncElb::ImeitemIRMSampleMStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << hsrefRefFmncMSample << endl;
};

void IexFmncElb::ImeitemIRMSampleMStep::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","smp"};
	else tags = {"ImeitemIRMSampleMStep","hsrefRefFmncMSample"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMSample);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMSampleMStep::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMSampleMStep::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMSample") ix |= HSREFREFFMNCMSAMPLE;
	};

	return(ix);
};

void IexFmncElb::ImeIRMSampleMStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HSREFREFFMNCMSAMPLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMSampleMStep::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMSAMPLE) ss.push_back("hsrefRefFmncMSample");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMSampleMStep
 ******************************************************************************/

IexFmncElb::ImeIRMSampleMStep::ImeIRMSampleMStep() {
};

IexFmncElb::ImeIRMSampleMStep::~ImeIRMSampleMStep() {
	clear();
};

void IexFmncElb::ImeIRMSampleMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMSampleMStep::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMSampleMStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 4)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 4)) {
			ii = new IexFmncElb::ImeitemIRMSampleMStep();

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

void IexFmncElb::ImeIRMSampleMStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMSampleMStep* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMSampleMStep");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMSampleMStep", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMSampleMStep";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMSampleMStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMSampleMStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIRMSampleMStep." << StrMod::replaceChar(ImeIRMSampleMStep::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMSampleMStep::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMSampleMStep");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIMStep
 ******************************************************************************/

IexFmncElb::ImeitemIMStep::ImeitemIMStep(
			const string& hintRlvUref
			, const string& hintTplRefFmncMStep
			, const uint ixWFilecfg
			, const string& Title
			, const uint start
			, const string& hintRefFmncMPerson
		) : FmncMStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRlvUref = hintRlvUref;
	this->hintTplRefFmncMStep = hintTplRefFmncMStep;
	this->ixWFilecfg = ixWFilecfg;
	this->Title = Title;
	this->start = start;
	this->hintRefFmncMPerson = hintRefFmncMPerson;
};

IexFmncElb::ImeitemIMStep::ImeitemIMStep(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMStep() {
	FmncMStep* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmstep->loadRecByRef(ref, &rec)) {
		refFmncMActivity = rec->refFmncMActivity;
		rlvIxVTbl = rec->rlvIxVTbl;
		rlvUref = rec->rlvUref;
		tplRefFmncMStep = rec->tplRefFmncMStep;
		ixWFilecfg = rec->ixWFilecfg;
		Title = rec->Title;
		start = rec->start;
		refFmncMPerson = rec->refFmncMPerson;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIMStep::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintRlvUref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) hintTplRefFmncMStep = txtrd.fields[1];
	if (txtrd.fields.size() > 2) ixWFilecfg = VecFmncWMStepFilecfg::getIx(txtrd.fields[2]);
	if (txtrd.fields.size() > 3) Title = txtrd.fields[3];
	if (txtrd.fields.size() > 4) start = Ftm::invstamp(txtrd.fields[4]);
	if (txtrd.fields.size() > 5) hintRefFmncMPerson = txtrd.fields[5];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIAMSTEPPAR)) {
			if (!imeiamsteppar.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIMFILE4)) {
			if (!imeimfile4.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIRMFILEMSTEP1)) {
			if (!imeirmfilemstep1.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIRMFILEMSTEP2)) {
			if (!imeirmfilemstep2.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIRMSAMPLEMSTEP)) {
			if (!imeirmsamplemstep.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIMStep::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefsIxWFilecfg;
	string ftmStart;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRlvUref", "rlu", hintRlvUref)) ixWIelValid += ImeIMStep::VecWIel::HINTRLVUREF;
		if (extractStringUclc(docctx, basexpath, "hintTplRefFmncMStep", "tpl", hintTplRefFmncMStep)) ixWIelValid += ImeIMStep::VecWIel::HINTTPLREFFMNCMSTEP;
		if (extractStringUclc(docctx, basexpath, "srefsIxWFilecfg", "fcf", srefsIxWFilecfg)) {
			ixWFilecfg = VecFmncWMStepFilecfg::getIx(srefsIxWFilecfg);
			ixWIelValid += ImeIMStep::VecWIel::SREFSIXWFILECFG;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMStep::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart)) {
			start = Ftm::invstamp(ftmStart);
			ixWIelValid += ImeIMStep::VecWIel::FTMSTART;
		};
		if (extractStringUclc(docctx, basexpath, "hintRefFmncMPerson", "prs", hintRefFmncMPerson)) ixWIelValid += ImeIMStep::VecWIel::HINTREFFMNCMPERSON;
		imeiamsteppar.readXML(docctx, basexpath);
		imeimfile4.readXML(docctx, basexpath);
		imeirmfilemstep1.readXML(docctx, basexpath);
		imeirmfilemstep2.readXML(docctx, basexpath);
		imeirmsamplemstep.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIMStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << hintRlvUref << "\t" << hintTplRefFmncMStep << "\t" << VecFmncWMStepFilecfg::getSrefs(ixWFilecfg) << "\t" << Title << "\t" << Ftm::stamp(start)
 << "\t" << hintRefFmncMPerson << endl;
	imeiamsteppar.writeTxt(outfile);
	imeimfile4.writeTxt(outfile);
	imeirmfilemstep1.writeTxt(outfile);
	imeirmfilemstep2.writeTxt(outfile);
	imeirmsamplemstep.writeTxt(outfile);
};

void IexFmncElb::ImeitemIMStep::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","rlu","tpl","fcf","tit","sta","prs"};
	else tags = {"ImeitemIMStep","hintRlvUref","hintTplRefFmncMStep","srefsIxWFilecfg","Title","ftmStart","hintRefFmncMPerson"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRlvUref);
		writeString(wr, tags[2], hintTplRefFmncMStep);
		writeString(wr, tags[3], VecFmncWMStepFilecfg::getSrefs(ixWFilecfg));
		writeString(wr, tags[4], Title);
		writeString(wr, tags[5], Ftm::stamp(start));
		writeString(wr, tags[6], hintRefFmncMPerson);
		imeiamsteppar.writeXML(wr, shorttags);
		imeimfile4.writeXML(wr, shorttags);
		imeirmfilemstep1.writeXML(wr, shorttags);
		imeirmfilemstep2.writeXML(wr, shorttags);
		imeirmsamplemstep.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMStep::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMStep::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintRlvUref") ix |= HINTRLVUREF;
		else if (ss[i] == "hintTplRefFmncMStep") ix |= HINTTPLREFFMNCMSTEP;
		else if (ss[i] == "srefsIxWFilecfg") ix |= SREFSIXWFILECFG;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "ftmStart") ix |= FTMSTART;
		else if (ss[i] == "hintRefFmncMPerson") ix |= HINTREFFMNCMPERSON;
	};

	return(ix);
};

void IexFmncElb::ImeIMStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HINTREFFMNCMPERSON);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMStep::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTRLVUREF) ss.push_back("hintRlvUref");
	if (ix & HINTTPLREFFMNCMSTEP) ss.push_back("hintTplRefFmncMStep");
	if (ix & SREFSIXWFILECFG) ss.push_back("srefsIxWFilecfg");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FTMSTART) ss.push_back("ftmStart");
	if (ix & HINTREFFMNCMPERSON) ss.push_back("hintRefFmncMPerson");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMStep
 ******************************************************************************/

IexFmncElb::ImeIMStep::ImeIMStep() {
};

IexFmncElb::ImeIMStep::~ImeIMStep() {
	clear();
};

void IexFmncElb::ImeIMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMStep::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexFmncElb::ImeitemIMStep();

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

void IexFmncElb::ImeIMStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMStep* ii = NULL;

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

			ii = new IexFmncElb::ImeitemIMStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMStep." << StrMod::replaceChar(ImeIMStep::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMStep::writeXML(
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
 class IexFmncElb::ImeitemIMActivity
 ******************************************************************************/

IexFmncElb::ImeitemIMActivity::ImeitemIMActivity(
			const string& Title
			, const string& Comment
		) : FmncMActivity() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIMActivity::ImeitemIMActivity(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMActivity() {
	FmncMActivity* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmactivity->loadRecByRef(ref, &rec)) {
		runRefFmncMRun = rec->runRefFmncMRun;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIMActivity::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Title = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Comment = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMSTEP)) {
			if (!imeimstep.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIMActivity::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMActivity::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMActivity::VecWIel::COMMENT;
		imeimstep.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIMActivity::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Title << "\t" << Comment << endl;
	imeimstep.writeTxt(outfile);
};

void IexFmncElb::ImeitemIMActivity::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","cmt"};
	else tags = {"ImeitemIMActivity","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Comment);
		imeimstep.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMActivity::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMActivity::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIMActivity::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMActivity::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMActivity
 ******************************************************************************/

IexFmncElb::ImeIMActivity::ImeIMActivity() {
};

IexFmncElb::ImeIMActivity::~ImeIMActivity() {
	clear();
};

void IexFmncElb::ImeIMActivity::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMActivity::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMActivity* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIMActivity();

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

void IexFmncElb::ImeIMActivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMActivity* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMActivity");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMActivity", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMActivity";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIMActivity();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMActivity::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMActivity." << StrMod::replaceChar(ImeIMActivity::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMActivity::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMActivity");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIMFile3
 ******************************************************************************/

IexFmncElb::ImeitemIMFile3::ImeitemIMFile3(
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

IexFmncElb::ImeitemIMFile3::ImeitemIMFile3(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMFile3() {
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

bool IexFmncElb::ImeitemIMFile3::readTxt(
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

void IexFmncElb::ImeitemIMFile3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile3::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile3::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile3::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile3::VecWIel::COMMENT;
	};
};

void IexFmncElb::ImeitemIMFile3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexFmncElb::ImeitemIMFile3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile3","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMFile3::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMFile3::VecWIel::getIx(
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

void IexFmncElb::ImeIMFile3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMFile3::VecWIel::getSrefs(
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
 class IexFmncElb::ImeIMFile3
 ******************************************************************************/

IexFmncElb::ImeIMFile3::ImeIMFile3() {
};

IexFmncElb::ImeIMFile3::~ImeIMFile3() {
	clear();
};

void IexFmncElb::ImeIMFile3::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMFile3::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMFile3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIMFile3();

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

void IexFmncElb::ImeIMFile3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMFile3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile3", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIMFile3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMFile3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMFile3." << StrMod::replaceChar(ImeIMFile3::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMFile3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile3");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIRMFabMRun
 ******************************************************************************/

IexFmncElb::ImeitemIRMFabMRun::ImeitemIRMFabMRun(
			const string& hintRefFmncMFab
		) : FmncRMFabMRun() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefFmncMFab = hintRefFmncMFab;
};

IexFmncElb::ImeitemIRMFabMRun::ImeitemIRMFabMRun(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMFabMRun() {
	FmncRMFabMRun* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmfabmrun->loadRecByRef(ref, &rec)) {
		refFmncMFab = rec->refFmncMFab;
		refFmncMRun = rec->refFmncMRun;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMFabMRun::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintRefFmncMFab = txtrd.fields[0];

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

void IexFmncElb::ImeitemIRMFabMRun::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRefFmncMFab", "fab", hintRefFmncMFab)) ixWIelValid += ImeIRMFabMRun::VecWIel::HINTREFFMNCMFAB;
	};
};

void IexFmncElb::ImeitemIRMFabMRun::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hintRefFmncMFab << endl;
};

void IexFmncElb::ImeitemIRMFabMRun::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fab"};
	else tags = {"ImeitemIRMFabMRun","hintRefFmncMFab"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefFmncMFab);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFabMRun::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMFabMRun::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintRefFmncMFab") ix |= HINTREFFMNCMFAB;
	};

	return(ix);
};

void IexFmncElb::ImeIRMFabMRun::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HINTREFFMNCMFAB);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMFabMRun::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFFMNCMFAB) ss.push_back("hintRefFmncMFab");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFabMRun
 ******************************************************************************/

IexFmncElb::ImeIRMFabMRun::ImeIRMFabMRun() {
};

IexFmncElb::ImeIRMFabMRun::~ImeIRMFabMRun() {
	clear();
};

void IexFmncElb::ImeIRMFabMRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMFabMRun::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMFabMRun* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIRMFabMRun();

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

void IexFmncElb::ImeIRMFabMRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMFabMRun* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMFabMRun");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMFabMRun", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMFabMRun";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMFabMRun();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMFabMRun::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMFabMRun." << StrMod::replaceChar(ImeIRMFabMRun::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMFabMRun::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMFabMRun");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIRMPersonMRun
 ******************************************************************************/

IexFmncElb::ImeitemIRMPersonMRun::ImeitemIRMPersonMRun(
			const string& hintRefFmncMPerson
		) : FmncRMPersonMRun() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefFmncMPerson = hintRefFmncMPerson;
};

IexFmncElb::ImeitemIRMPersonMRun::ImeitemIRMPersonMRun(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMPersonMRun() {
	FmncRMPersonMRun* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmpersonmrun->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		refFmncMRun = rec->refFmncMRun;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMPersonMRun::readTxt(
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

void IexFmncElb::ImeitemIRMPersonMRun::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRefFmncMPerson", "prs", hintRefFmncMPerson)) ixWIelValid += ImeIRMPersonMRun::VecWIel::HINTREFFMNCMPERSON;
	};
};

void IexFmncElb::ImeitemIRMPersonMRun::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hintRefFmncMPerson << endl;
};

void IexFmncElb::ImeitemIRMPersonMRun::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs"};
	else tags = {"ImeitemIRMPersonMRun","hintRefFmncMPerson"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefFmncMPerson);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMPersonMRun::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMPersonMRun::VecWIel::getIx(
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

void IexFmncElb::ImeIRMPersonMRun::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HINTREFFMNCMPERSON);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMPersonMRun::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFFMNCMPERSON) ss.push_back("hintRefFmncMPerson");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMPersonMRun
 ******************************************************************************/

IexFmncElb::ImeIRMPersonMRun::ImeIRMPersonMRun() {
};

IexFmncElb::ImeIRMPersonMRun::~ImeIRMPersonMRun() {
	clear();
};

void IexFmncElb::ImeIRMPersonMRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMPersonMRun::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMPersonMRun* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIRMPersonMRun();

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

void IexFmncElb::ImeIRMPersonMRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMPersonMRun* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMPersonMRun");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMPersonMRun", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMPersonMRun";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMPersonMRun();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMPersonMRun::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMPersonMRun." << StrMod::replaceChar(ImeIRMPersonMRun::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMPersonMRun::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMPersonMRun");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIRMRunMSample
 ******************************************************************************/

IexFmncElb::ImeitemIRMRunMSample::ImeitemIRMRunMSample(
			const string& hsrefRefFmncMSample
		) : FmncRMRunMSample() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefFmncMSample = hsrefRefFmncMSample;
};

IexFmncElb::ImeitemIRMRunMSample::ImeitemIRMRunMSample(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMRunMSample() {
	FmncRMRunMSample* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmrunmsample->loadRecByRef(ref, &rec)) {
		refFmncMRun = rec->refFmncMRun;
		refFmncMSample = rec->refFmncMSample;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMRunMSample::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefRefFmncMSample = txtrd.fields[0];

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

void IexFmncElb::ImeitemIRMRunMSample::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMSample", "smp", hsrefRefFmncMSample)) ixWIelValid += ImeIRMRunMSample::VecWIel::HSREFREFFMNCMSAMPLE;
	};
};

void IexFmncElb::ImeitemIRMRunMSample::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hsrefRefFmncMSample << endl;
};

void IexFmncElb::ImeitemIRMRunMSample::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","smp"};
	else tags = {"ImeitemIRMRunMSample","hsrefRefFmncMSample"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefFmncMSample);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMRunMSample::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMRunMSample::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefRefFmncMSample") ix |= HSREFREFFMNCMSAMPLE;
	};

	return(ix);
};

void IexFmncElb::ImeIRMRunMSample::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*HSREFREFFMNCMSAMPLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMRunMSample::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFFMNCMSAMPLE) ss.push_back("hsrefRefFmncMSample");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMRunMSample
 ******************************************************************************/

IexFmncElb::ImeIRMRunMSample::ImeIRMRunMSample() {
};

IexFmncElb::ImeIRMRunMSample::~ImeIRMRunMSample() {
	clear();
};

void IexFmncElb::ImeIRMRunMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMRunMSample::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMRunMSample* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIRMRunMSample();

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

void IexFmncElb::ImeIRMRunMSample::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMRunMSample* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMRunMSample");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMRunMSample", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMRunMSample";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMRunMSample();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMRunMSample::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMRunMSample." << StrMod::replaceChar(ImeIRMRunMSample::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMRunMSample::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMRunMSample");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIMRun
 ******************************************************************************/

IexFmncElb::ImeitemIMRun::ImeitemIMRun(
			const string& Title
			, const string& Comment
		) : FmncMRun() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIMRun::ImeitemIMRun(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMRun() {
	FmncMRun* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmrun->loadRecByRef(ref, &rec)) {
		refFmncMProject = rec->refFmncMProject;
		Title = rec->Title;
		refJState = rec->refJState;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIMRun::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Title = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Comment = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMRUNSTATE)) {
			if (!imeijmrunstate.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMACTIVITY)) {
			if (!imeimactivity.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMFILE3)) {
			if (!imeimfile3.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMFABMRUN)) {
			if (!imeirmfabmrun.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMPERSONMRUN)) {
			if (!imeirmpersonmrun.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMRUNMSAMPLE)) {
			if (!imeirmrunmsample.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIMRun::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMRun::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMRun::VecWIel::COMMENT;
		imeijmrunstate.readXML(docctx, basexpath);
		imeimactivity.readXML(docctx, basexpath);
		imeimfile3.readXML(docctx, basexpath);
		imeirmfabmrun.readXML(docctx, basexpath);
		imeirmpersonmrun.readXML(docctx, basexpath);
		imeirmrunmsample.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIMRun::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Title << "\t" << Comment << endl;
	imeijmrunstate.writeTxt(outfile);
	imeimactivity.writeTxt(outfile);
	imeimfile3.writeTxt(outfile);
	imeirmfabmrun.writeTxt(outfile);
	imeirmpersonmrun.writeTxt(outfile);
	imeirmrunmsample.writeTxt(outfile);
};

void IexFmncElb::ImeitemIMRun::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","cmt"};
	else tags = {"ImeitemIMRun","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Comment);
		imeijmrunstate.writeXML(wr, shorttags);
		imeimactivity.writeXML(wr, shorttags);
		imeimfile3.writeXML(wr, shorttags);
		imeirmfabmrun.writeXML(wr, shorttags);
		imeirmpersonmrun.writeXML(wr, shorttags);
		imeirmrunmsample.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMRun::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMRun::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIMRun::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMRun::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMRun
 ******************************************************************************/

IexFmncElb::ImeIMRun::ImeIMRun() {
};

IexFmncElb::ImeIMRun::~ImeIMRun() {
	clear();
};

void IexFmncElb::ImeIMRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMRun::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMRun* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIMRun();

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

void IexFmncElb::ImeIMRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMRun* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRun");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRun", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRun";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIMRun();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMRun::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMRun." << StrMod::replaceChar(ImeIMRun::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMRun::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRun");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIMProject
 ******************************************************************************/

IexFmncElb::ImeitemIMProject::ImeitemIMProject(
			const string& Title
			, const string& Comment
		) : FmncMProject() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIMProject::ImeitemIMProject(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMProject() {
	FmncMProject* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmproject->loadRecByRef(ref, &rec)) {
		Title = rec->Title;
		refJState = rec->refJState;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIMProject::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Title = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Comment = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMPROJECTSTATE)) {
			if (!imeijmprojectstate.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMRUN)) {
			if (!imeimrun.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIMProject::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMProject::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMProject::VecWIel::COMMENT;
		imeijmprojectstate.readXML(docctx, basexpath);
		imeimrun.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIMProject::writeTxt(
			fstream& outfile
		) {
	outfile << Title << "\t" << Comment << endl;
	imeijmprojectstate.writeTxt(outfile);
	imeimrun.writeTxt(outfile);
};

void IexFmncElb::ImeitemIMProject::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","cmt"};
	else tags = {"ImeitemIMProject","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Comment);
		imeijmprojectstate.writeXML(wr, shorttags);
		imeimrun.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMProject::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMProject::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIMProject::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMProject::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMProject
 ******************************************************************************/

IexFmncElb::ImeIMProject::ImeIMProject() {
};

IexFmncElb::ImeIMProject::~ImeIMProject() {
	clear();
};

void IexFmncElb::ImeIMProject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMProject::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMProject* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncElb::ImeitemIMProject();

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

void IexFmncElb::ImeIMProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMProject* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMProject");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMProject", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMProject";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIMProject();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMProject::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMProject." << StrMod::replaceChar(ImeIMProject::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMProject::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMProject");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIAMSamplePar
 ******************************************************************************/

IexFmncElb::ImeitemIAMSamplePar::ImeitemIAMSamplePar(
			const string& x1SrefKKey
			, const string& osrefKVal
		) : FmncAMSamplePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->osrefKVal = osrefKVal;
};

IexFmncElb::ImeitemIAMSamplePar::ImeitemIAMSamplePar(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMSamplePar() {
	FmncAMSamplePar* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamsamplepar->loadRecByRef(ref, &rec)) {
		refFmncMSample = rec->refFmncMSample;
		x1SrefKKey = rec->x1SrefKKey;
		osrefKVal = rec->osrefKVal;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIAMSamplePar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1SrefKKey = txtrd.fields[0];
	if (txtrd.fields.size() > 1) osrefKVal = txtrd.fields[1];

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

void IexFmncElb::ImeitemIAMSamplePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMSamplePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "osrefKVal", "val", osrefKVal)) ixWIelValid += ImeIAMSamplePar::VecWIel::OSREFKVAL;
	};
};

void IexFmncElb::ImeitemIAMSamplePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << osrefKVal << endl;
};

void IexFmncElb::ImeitemIAMSamplePar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMSamplePar","x1SrefKKey","osrefKVal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], osrefKVal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIAMSamplePar::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIAMSamplePar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x1SrefKKey") ix |= X1SREFKKEY;
		else if (ss[i] == "osrefKVal") ix |= OSREFKVAL;
	};

	return(ix);
};

void IexFmncElb::ImeIAMSamplePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*OSREFKVAL);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIAMSamplePar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & OSREFKVAL) ss.push_back("osrefKVal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIAMSamplePar
 ******************************************************************************/

IexFmncElb::ImeIAMSamplePar::ImeIAMSamplePar() {
};

IexFmncElb::ImeIAMSamplePar::~ImeIAMSamplePar() {
	clear();
};

void IexFmncElb::ImeIAMSamplePar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIAMSamplePar::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIAMSamplePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIAMSamplePar();

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

void IexFmncElb::ImeIAMSamplePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIAMSamplePar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMSamplePar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMSamplePar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMSamplePar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIAMSamplePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIAMSamplePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMSamplePar." << StrMod::replaceChar(ImeIAMSamplePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIAMSamplePar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMSamplePar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexFmncElb::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
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

IexFmncElb::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJAVKeylistKey() {
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

bool IexFmncElb::ImeitemIJAVKeylistKey::readTxt(
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

void IexFmncElb::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxFmncVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxFmncVLocale", "lcl", srefX1IxFmncVLocale)) {
			x1IxFmncVLocale = VecFmncVLocale::getIx(srefX1IxFmncVLocale);
			ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXFMNCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexFmncElb::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncElb::ImeitemIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey","srefX1IxFmncVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVLocale::getSref(x1IxFmncVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIJAVKeylistKey::VecWIel::getIx(
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

void IexFmncElb::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIJAVKeylistKey::VecWIel::getSrefs(
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
 class IexFmncElb::ImeIJAVKeylistKey
 ******************************************************************************/

IexFmncElb::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexFmncElb::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexFmncElb::ImeIJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncElb::ImeitemIJAVKeylistKey();

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

void IexFmncElb::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIJAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIAVKeylistKey
 ******************************************************************************/

IexFmncElb::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

IexFmncElb::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVKeylistKey() {
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

bool IexFmncElb::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxFmncVKeylist = VecFmncVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
			if (!imeijavkeylistkey.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefKlsIxFmncVKeylist;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxFmncVKeylist", "kls", srefKlsIxFmncVKeylist)) {
			klsIxFmncVKeylist = VecFmncVKeylist::getIx(srefKlsIxFmncVKeylist);
			ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXFMNCVKEYLIST;
		};
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncVKeylist::getSref(klsIxFmncVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexFmncElb::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey","srefKlsIxFmncVKeylist","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVKeylist::getSref(klsIxFmncVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIAVKeylistKey::VecWIel::getIx(
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

void IexFmncElb::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIAVKeylistKey::VecWIel::getSrefs(
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
 class IexFmncElb::ImeIAVKeylistKey
 ******************************************************************************/

IexFmncElb::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexFmncElb::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexFmncElb::ImeIAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIAVKeylistKey();

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

void IexFmncElb::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIJMSampleState
 ******************************************************************************/

IexFmncElb::ImeitemIJMSampleState::ImeitemIJMSampleState(
			const uint x1Start
			, const uint ixVState
		) : FmncJMSampleState() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

IexFmncElb::ImeitemIJMSampleState::ImeitemIJMSampleState(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMSampleState() {
	FmncJMSampleState* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmsamplestate->loadRecByRef(ref, &rec)) {
		refFmncMSample = rec->refFmncMSample;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIJMSampleState::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1Start = Ftm::invstamp(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) ixVState = VecFmncVMSampleState::getIx(txtrd.fields[1]);

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

void IexFmncElb::ImeitemIJMSampleState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string ftmX1Start;
	string srefIxVState;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start)) {
			x1Start = Ftm::invstamp(ftmX1Start);
			ixWIelValid += ImeIJMSampleState::VecWIel::FTMX1START;
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) {
			ixVState = VecFmncVMSampleState::getIx(srefIxVState);
			ixWIelValid += ImeIJMSampleState::VecWIel::SREFIXVSTATE;
		};
	};
};

void IexFmncElb::ImeitemIJMSampleState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Ftm::stamp(x1Start)
 << "\t" << VecFmncVMSampleState::getSref(ixVState) << endl;
};

void IexFmncElb::ImeitemIJMSampleState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sta","ste"};
	else tags = {"ImeitemIJMSampleState","ftmX1Start","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Ftm::stamp(x1Start));
		writeString(wr, tags[2], VecFmncVMSampleState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIJMSampleState::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIJMSampleState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "ftmX1Start") ix |= FTMX1START;
		else if (ss[i] == "srefIxVState") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexFmncElb::ImeIJMSampleState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVSTATE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIJMSampleState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FTMX1START) ss.push_back("ftmX1Start");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIJMSampleState
 ******************************************************************************/

IexFmncElb::ImeIJMSampleState::ImeIJMSampleState() {
};

IexFmncElb::ImeIJMSampleState::~ImeIJMSampleState() {
	clear();
};

void IexFmncElb::ImeIJMSampleState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIJMSampleState::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIJMSampleState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIJMSampleState();

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

void IexFmncElb::ImeIJMSampleState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIJMSampleState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMSampleState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMSampleState", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMSampleState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIJMSampleState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIJMSampleState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMSampleState." << StrMod::replaceChar(ImeIJMSampleState::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIJMSampleState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMSampleState");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIMFile2
 ******************************************************************************/

IexFmncElb::ImeitemIMFile2::ImeitemIMFile2(
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

IexFmncElb::ImeitemIMFile2::ImeitemIMFile2(
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

bool IexFmncElb::ImeitemIMFile2::readTxt(
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

void IexFmncElb::ImeitemIMFile2::readXML(
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

void IexFmncElb::ImeitemIMFile2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexFmncElb::ImeitemIMFile2::writeXML(
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
 class IexFmncElb::ImeIMFile2::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMFile2::VecWIel::getIx(
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

void IexFmncElb::ImeIMFile2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMFile2::VecWIel::getSrefs(
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
 class IexFmncElb::ImeIMFile2
 ******************************************************************************/

IexFmncElb::ImeIMFile2::ImeIMFile2() {
};

IexFmncElb::ImeIMFile2::~ImeIMFile2() {
	clear();
};

void IexFmncElb::ImeIMFile2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMFile2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMFile2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIMFile2();

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

void IexFmncElb::ImeIMFile2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMFile2* ii = NULL;

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

			ii = new IexFmncElb::ImeitemIMFile2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMFile2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMFile2." << StrMod::replaceChar(ImeIMFile2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMFile2::writeXML(
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
 class IexFmncElb::ImeitemIRMFileMSample
 ******************************************************************************/

IexFmncElb::ImeitemIRMFileMSample::ImeitemIRMFileMSample(
		) : FmncRMFileMSample() {
	lineno = 0;
	ixWIelValid = 0;

};

IexFmncElb::ImeitemIRMFileMSample::ImeitemIRMFileMSample(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMFileMSample() {
	FmncRMFileMSample* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmfilemsample->loadRecByRef(ref, &rec)) {
		refFmncMSample = rec->refFmncMSample;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIRMFileMSample::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

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

void IexFmncElb::ImeitemIRMFileMSample::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
	};
};

void IexFmncElb::ImeitemIRMFileMSample::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << endl;
};

void IexFmncElb::ImeitemIRMFileMSample::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii"};
	else tags = {"ImeitemIRMFileMSample"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFileMSample::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIRMFileMSample::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
	};

	return(ix);
};

void IexFmncElb::ImeIRMFileMSample::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;false;) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIRMFileMSample::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIRMFileMSample
 ******************************************************************************/

IexFmncElb::ImeIRMFileMSample::ImeIRMFileMSample() {
};

IexFmncElb::ImeIRMFileMSample::~ImeIRMFileMSample() {
	clear();
};

void IexFmncElb::ImeIRMFileMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIRMFileMSample::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIRMFileMSample* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncElb::ImeitemIRMFileMSample();

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

void IexFmncElb::ImeIRMFileMSample::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIRMFileMSample* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMFileMSample");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMFileMSample", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMFileMSample";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIRMFileMSample();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIRMFileMSample::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMFileMSample." << StrMod::replaceChar(ImeIRMFileMSample::VecWIel::getSrefs(0), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIRMFileMSample::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMFileMSample");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncElb::ImeitemIMSample
 ******************************************************************************/

IexFmncElb::ImeitemIMSample::ImeitemIMSample(
			const string& hsrefSupRefFmncMSample
			, const string& sref
			, const string& Material
			, const string& Comment
		) : FmncMSample() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefFmncMSample = hsrefSupRefFmncMSample;
	this->sref = sref;
	this->Material = Material;
	this->Comment = Comment;
};

IexFmncElb::ImeitemIMSample::ImeitemIMSample(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMSample() {
	FmncMSample* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmsample->loadRecByRef(ref, &rec)) {
		supRefFmncMSample = rec->supRefFmncMSample;
		sref = rec->sref;
		Material = rec->Material;
		refJState = rec->refJState;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncElb::ImeitemIMSample::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefSupRefFmncMSample = txtrd.fields[0];
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Material = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Comment = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMSAMPLEPAR)) {
			if (!imeiamsamplepar.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) {
			if (!imeiavkeylistkey.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMSAMPLESTATE)) {
			if (!imeijmsamplestate.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMFILE2)) {
			if (!imeimfile2.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMFILEMSAMPLE)) {
			if (!imeirmfilemsample.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncElb::ImeitemIMSample::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefFmncMSample", "sup", hsrefSupRefFmncMSample)) ixWIelValid += ImeIMSample::VecWIel::HSREFSUPREFFMNCMSAMPLE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSample::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Material", "mat", Material)) ixWIelValid += ImeIMSample::VecWIel::MATERIAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSample::VecWIel::COMMENT;
		imeiamsamplepar.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeijmsamplestate.readXML(docctx, basexpath);
		imeimfile2.readXML(docctx, basexpath);
		imeirmfilemsample.readXML(docctx, basexpath);
	};
};

void IexFmncElb::ImeitemIMSample::writeTxt(
			fstream& outfile
		) {
	outfile << hsrefSupRefFmncMSample << "\t" << sref << "\t" << Material << "\t" << Comment << endl;
	imeiamsamplepar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeijmsamplestate.writeTxt(outfile);
	imeimfile2.writeTxt(outfile);
	imeirmfilemsample.writeTxt(outfile);
};

void IexFmncElb::ImeitemIMSample::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sup","srf","mat","cmt"};
	else tags = {"ImeitemIMSample","hsrefSupRefFmncMSample","sref","Material","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefSupRefFmncMSample);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Material);
		writeString(wr, tags[4], Comment);
		imeiamsamplepar.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeijmsamplestate.writeXML(wr, shorttags);
		imeimfile2.writeXML(wr, shorttags);
		imeirmfilemsample.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncElb::ImeIMSample::VecWIel
 ******************************************************************************/

uint IexFmncElb::ImeIMSample::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefSupRefFmncMSample") ix |= HSREFSUPREFFMNCMSAMPLE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Material") ix |= MATERIAL;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncElb::ImeIMSample::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncElb::ImeIMSample::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFSUPREFFMNCMSAMPLE) ss.push_back("hsrefSupRefFmncMSample");
	if (ix & SREF) ss.push_back("sref");
	if (ix & MATERIAL) ss.push_back("Material");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncElb::ImeIMSample
 ******************************************************************************/

IexFmncElb::ImeIMSample::ImeIMSample() {
};

IexFmncElb::ImeIMSample::~ImeIMSample() {
	clear();
};

void IexFmncElb::ImeIMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncElb::ImeIMSample::readTxt(
			Txtrd& txtrd
		) {
	IexFmncElb::ImeitemIMSample* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncElb::ImeitemIMSample();

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

void IexFmncElb::ImeIMSample::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncElb::ImeitemIMSample* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSample");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSample", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSample";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncElb::ImeitemIMSample();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncElb::ImeIMSample::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMSample." << StrMod::replaceChar(ImeIMSample::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncElb::ImeIMSample::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSample");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};


