/**
  * \file IexFmncOrg_blks.cpp
  * import/export handler for database DbsFmnc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class IexFmncOrg::VecVIme
 ******************************************************************************/

uint IexFmncOrg::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimorg") return IMEIMORG;
	else if (s == "imeimperson") return IMEIMPERSON;
	else if (s == "imeirmorgmperson") return IMEIRMORGMPERSON;
	else if (s == "imeiamorgdetail") return IMEIAMORGDETAIL;
	else if (s == "imeiampersondetail") return IMEIAMPERSONDETAIL;
	else if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	else if (s == "imeijmorgtitle") return IMEIJMORGTITLE;
	else if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	else if (s == "imeimaddress1") return IMEIMADDRESS1;
	else if (s == "imeimaddress2") return IMEIMADDRESS2;
	else if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;

	return(0);
};

string IexFmncOrg::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMORG) return("ImeIMOrg");
	else if (ix == IMEIMPERSON) return("ImeIMPerson");
	else if (ix == IMEIRMORGMPERSON) return("ImeIRMOrgMPerson");
	else if (ix == IMEIAMORGDETAIL) return("ImeIAMOrgDetail");
	else if (ix == IMEIAMPERSONDETAIL) return("ImeIAMPersonDetail");
	else if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	else if (ix == IMEIJMORGTITLE) return("ImeIJMOrgTitle");
	else if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	else if (ix == IMEIMADDRESS1) return("ImeIMAddress1");
	else if (ix == IMEIMADDRESS2) return("ImeIMAddress2");
	else if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");

	return("");
};

/******************************************************************************
 class IexFmncOrg::ImeitemIAMOrgDetail
 ******************************************************************************/

IexFmncOrg::ImeitemIAMOrgDetail::ImeitemIAMOrgDetail(
			const string& x1SrefKType
			, const string& Val
		) : FmncAMOrgDetail() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

IexFmncOrg::ImeitemIAMOrgDetail::ImeitemIAMOrgDetail(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMOrgDetail() {
	FmncAMOrgDetail* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamorgdetail->loadRecByRef(ref, &rec)) {
		refFmncMOrg = rec->refFmncMOrg;
		x1SrefKType = rec->x1SrefKType;
		Val = rec->Val;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIAMOrgDetail::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1SrefKType = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Val = txtrd.fields[1];

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

void IexFmncOrg::ImeitemIAMOrgDetail::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType)) ixWIelValid += ImeIAMOrgDetail::VecWIel::X1SREFKTYPE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMOrgDetail::VecWIel::VAL;
	};
};

void IexFmncOrg::ImeitemIAMOrgDetail::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKType << "\t" << Val << endl;
};

void IexFmncOrg::ImeitemIAMOrgDetail::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","val"};
	else tags = {"ImeitemIAMOrgDetail","x1SrefKType","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKType);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIAMOrgDetail::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIAMOrgDetail::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x1SrefKType") ix |= X1SREFKTYPE;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexFmncOrg::ImeIAMOrgDetail::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIAMOrgDetail::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKTYPE) ss.push_back("x1SrefKType");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIAMOrgDetail
 ******************************************************************************/

IexFmncOrg::ImeIAMOrgDetail::ImeIAMOrgDetail() {
};

IexFmncOrg::ImeIAMOrgDetail::~ImeIAMOrgDetail() {
	clear();
};

void IexFmncOrg::ImeIAMOrgDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIAMOrgDetail::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIAMOrgDetail* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIAMOrgDetail();

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

void IexFmncOrg::ImeIAMOrgDetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIAMOrgDetail* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMOrgDetail");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMOrgDetail", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMOrgDetail";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIAMOrgDetail();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIAMOrgDetail::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMOrgDetail." << StrMod::replaceChar(ImeIAMOrgDetail::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIAMOrgDetail::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMOrgDetail");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexFmncOrg::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
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

IexFmncOrg::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
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

bool IexFmncOrg::ImeitemIJAVKeylistKey::readTxt(
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

void IexFmncOrg::ImeitemIJAVKeylistKey::readXML(
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

void IexFmncOrg::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncOrg::ImeitemIJAVKeylistKey::writeXML(
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
 class IexFmncOrg::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIJAVKeylistKey::VecWIel::getIx(
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

void IexFmncOrg::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIJAVKeylistKey::VecWIel::getSrefs(
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
 class IexFmncOrg::ImeIJAVKeylistKey
 ******************************************************************************/

IexFmncOrg::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexFmncOrg::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexFmncOrg::ImeIJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncOrg::ImeitemIJAVKeylistKey();

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

void IexFmncOrg::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIJAVKeylistKey* ii = NULL;

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

			ii = new IexFmncOrg::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIJAVKeylistKey::writeXML(
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
 class IexFmncOrg::ImeitemIAVKeylistKey
 ******************************************************************************/

IexFmncOrg::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

IexFmncOrg::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

bool IexFmncOrg::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Avail = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Implied = txtrd.fields[2];

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

void IexFmncOrg::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexFmncOrg::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexFmncOrg::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIAVKeylistKey::VecWIel::getIx(
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

void IexFmncOrg::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIAVKeylistKey::VecWIel::getSrefs(
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
 class IexFmncOrg::ImeIAVKeylistKey
 ******************************************************************************/

IexFmncOrg::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexFmncOrg::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexFmncOrg::ImeIAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIAVKeylistKey();

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

void IexFmncOrg::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIAVKeylistKey* ii = NULL;

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

			ii = new IexFmncOrg::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIAVKeylistKey::writeXML(
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
 class IexFmncOrg::ImeitemIJMOrgTitle
 ******************************************************************************/

IexFmncOrg::ImeitemIJMOrgTitle::ImeitemIJMOrgTitle(
			const string& Title
		) : FmncJMOrgTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
};

IexFmncOrg::ImeitemIJMOrgTitle::ImeitemIJMOrgTitle(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMOrgTitle() {
	FmncJMOrgTitle* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmorgtitle->loadRecByRef(ref, &rec)) {
		refFmncMOrg = rec->refFmncMOrg;
		Title = rec->Title;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIJMOrgTitle::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Title = txtrd.fields[0];

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

void IexFmncOrg::ImeitemIJMOrgTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMOrgTitle::VecWIel::TITLE;
	};
};

void IexFmncOrg::ImeitemIJMOrgTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Title << endl;
};

void IexFmncOrg::ImeitemIJMOrgTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit"};
	else tags = {"ImeitemIJMOrgTitle","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIJMOrgTitle::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIJMOrgTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Title") ix |= TITLE;
	};

	return(ix);
};

void IexFmncOrg::ImeIJMOrgTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*TITLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIJMOrgTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIJMOrgTitle
 ******************************************************************************/

IexFmncOrg::ImeIJMOrgTitle::ImeIJMOrgTitle() {
};

IexFmncOrg::ImeIJMOrgTitle::~ImeIJMOrgTitle() {
	clear();
};

void IexFmncOrg::ImeIJMOrgTitle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIJMOrgTitle::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIJMOrgTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIJMOrgTitle();

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

void IexFmncOrg::ImeIJMOrgTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIJMOrgTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMOrgTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMOrgTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMOrgTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIJMOrgTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIJMOrgTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMOrgTitle." << StrMod::replaceChar(ImeIJMOrgTitle::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIJMOrgTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMOrgTitle");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIMAddress1
 ******************************************************************************/

IexFmncOrg::ImeitemIMAddress1::ImeitemIMAddress1(
			const string& srefKAdrtype
			, const string& Address1
			, const string& Address2
			, const string& Zipcode
			, const string& City
			, const string& State
			, const string& srefKCountry
		) : FmncMAddress() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefKAdrtype = srefKAdrtype;
	this->Address1 = Address1;
	this->Address2 = Address2;
	this->Zipcode = Zipcode;
	this->City = City;
	this->State = State;
	this->srefKCountry = srefKCountry;
};

IexFmncOrg::ImeitemIMAddress1::ImeitemIMAddress1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMAddress1() {
	FmncMAddress* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmaddress->loadRecByRef(ref, &rec)) {
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		srefKAdrtype = rec->srefKAdrtype;
		Address1 = rec->Address1;
		Address2 = rec->Address2;
		Zipcode = rec->Zipcode;
		City = rec->City;
		State = rec->State;
		srefKCountry = rec->srefKCountry;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIMAddress1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) srefKAdrtype = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Address1 = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Address2 = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Zipcode = txtrd.fields[3];
	if (txtrd.fields.size() > 4) City = txtrd.fields[4];
	if (txtrd.fields.size() > 5) State = txtrd.fields[5];
	if (txtrd.fields.size() > 6) srefKCountry = txtrd.fields[6];

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

void IexFmncOrg::ImeitemIMAddress1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKAdrtype", "aty", srefKAdrtype)) ixWIelValid += ImeIMAddress1::VecWIel::SREFKADRTYPE;
		if (extractStringUclc(docctx, basexpath, "Address1", "ad1", Address1)) ixWIelValid += ImeIMAddress1::VecWIel::ADDRESS1;
		if (extractStringUclc(docctx, basexpath, "Address2", "ad2", Address2)) ixWIelValid += ImeIMAddress1::VecWIel::ADDRESS2;
		if (extractStringUclc(docctx, basexpath, "Zipcode", "zip", Zipcode)) ixWIelValid += ImeIMAddress1::VecWIel::ZIPCODE;
		if (extractStringUclc(docctx, basexpath, "City", "cty", City)) ixWIelValid += ImeIMAddress1::VecWIel::CITY;
		if (extractStringUclc(docctx, basexpath, "State", "ste", State)) ixWIelValid += ImeIMAddress1::VecWIel::STATE;
		if (extractStringUclc(docctx, basexpath, "srefKCountry", "cry", srefKCountry)) ixWIelValid += ImeIMAddress1::VecWIel::SREFKCOUNTRY;
	};
};

void IexFmncOrg::ImeitemIMAddress1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefKAdrtype << "\t" << Address1 << "\t" << Address2 << "\t" << Zipcode << "\t" << City << "\t" << State << "\t" << srefKCountry << endl;
};

void IexFmncOrg::ImeitemIMAddress1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","aty","ad1","ad2","zip","cty","ste","cry"};
	else tags = {"ImeitemIMAddress1","srefKAdrtype","Address1","Address2","Zipcode","City","State","srefKCountry"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefKAdrtype);
		writeString(wr, tags[2], Address1);
		writeString(wr, tags[3], Address2);
		writeString(wr, tags[4], Zipcode);
		writeString(wr, tags[5], City);
		writeString(wr, tags[6], State);
		writeString(wr, tags[7], srefKCountry);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIMAddress1::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIMAddress1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefKAdrtype") ix |= SREFKADRTYPE;
		else if (ss[i] == "Address1") ix |= ADDRESS1;
		else if (ss[i] == "Address2") ix |= ADDRESS2;
		else if (ss[i] == "Zipcode") ix |= ZIPCODE;
		else if (ss[i] == "City") ix |= CITY;
		else if (ss[i] == "State") ix |= STATE;
		else if (ss[i] == "srefKCountry") ix |= SREFKCOUNTRY;
	};

	return(ix);
};

void IexFmncOrg::ImeIMAddress1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFKCOUNTRY);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIMAddress1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKADRTYPE) ss.push_back("srefKAdrtype");
	if (ix & ADDRESS1) ss.push_back("Address1");
	if (ix & ADDRESS2) ss.push_back("Address2");
	if (ix & ZIPCODE) ss.push_back("Zipcode");
	if (ix & CITY) ss.push_back("City");
	if (ix & STATE) ss.push_back("State");
	if (ix & SREFKCOUNTRY) ss.push_back("srefKCountry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIMAddress1
 ******************************************************************************/

IexFmncOrg::ImeIMAddress1::ImeIMAddress1() {
};

IexFmncOrg::ImeIMAddress1::~ImeIMAddress1() {
	clear();
};

void IexFmncOrg::ImeIMAddress1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIMAddress1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIMAddress1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIMAddress1();

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

void IexFmncOrg::ImeIMAddress1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIMAddress1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMAddress1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMAddress1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMAddress1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIMAddress1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIMAddress1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMAddress1." << StrMod::replaceChar(ImeIMAddress1::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIMAddress1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMAddress1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIMOrg
 ******************************************************************************/

IexFmncOrg::ImeitemIMOrg::ImeitemIMOrg(
			const uint ixWDerivate
			, const string& hsrefSupRefFmncMOrg
			, const string& sref
		) : FmncMOrg() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWDerivate = ixWDerivate;
	this->hsrefSupRefFmncMOrg = hsrefSupRefFmncMOrg;
	this->sref = sref;
};

IexFmncOrg::ImeitemIMOrg::ImeitemIMOrg(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMOrg() {
	FmncMOrg* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmorg->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		refFmncMAddress = rec->refFmncMAddress;
		supRefFmncMOrg = rec->supRefFmncMOrg;
		sref = rec->sref;
		refJTitle = rec->refJTitle;
		telRefADetail = rec->telRefADetail;
		emlRefADetail = rec->emlRefADetail;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIMOrg::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixWDerivate = VecFmncWMOrgDerivate::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) hsrefSupRefFmncMOrg = txtrd.fields[1];
	if (txtrd.fields.size() > 2) sref = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMORGDETAIL)) {
			if (!imeiamorgdetail.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) {
			if (!imeiavkeylistkey.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMORGTITLE)) {
			if (!imeijmorgtitle.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMADDRESS1)) {
			if (!imeimaddress1.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncOrg::ImeitemIMOrg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefsIxWDerivate;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefsIxWDerivate", "drv", srefsIxWDerivate)) {
			ixWDerivate = VecFmncWMOrgDerivate::getIx(srefsIxWDerivate);
			ixWIelValid += ImeIMOrg::VecWIel::SREFSIXWDERIVATE;
		};
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefFmncMOrg", "sup", hsrefSupRefFmncMOrg)) ixWIelValid += ImeIMOrg::VecWIel::HSREFSUPREFFMNCMORG;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMOrg::VecWIel::SREF;
		imeiamorgdetail.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeijmorgtitle.readXML(docctx, basexpath);
		imeimaddress1.readXML(docctx, basexpath);
	};
};

void IexFmncOrg::ImeitemIMOrg::writeTxt(
			fstream& outfile
		) {
	outfile << VecFmncWMOrgDerivate::getSrefs(ixWDerivate) << "\t" << hsrefSupRefFmncMOrg << "\t" << sref << endl;
	imeiamorgdetail.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeijmorgtitle.writeTxt(outfile);
	imeimaddress1.writeTxt(outfile);
};

void IexFmncOrg::ImeitemIMOrg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","drv","sup","srf"};
	else tags = {"ImeitemIMOrg","srefsIxWDerivate","hsrefSupRefFmncMOrg","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncWMOrgDerivate::getSrefs(ixWDerivate));
		writeString(wr, tags[2], hsrefSupRefFmncMOrg);
		writeString(wr, tags[3], sref);
		imeiamorgdetail.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeijmorgtitle.writeXML(wr, shorttags);
		imeimaddress1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIMOrg::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIMOrg::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefsIxWDerivate") ix |= SREFSIXWDERIVATE;
		else if (ss[i] == "hsrefSupRefFmncMOrg") ix |= HSREFSUPREFFMNCMORG;
		else if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexFmncOrg::ImeIMOrg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREF);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIMOrg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSIXWDERIVATE) ss.push_back("srefsIxWDerivate");
	if (ix & HSREFSUPREFFMNCMORG) ss.push_back("hsrefSupRefFmncMOrg");
	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIMOrg
 ******************************************************************************/

IexFmncOrg::ImeIMOrg::ImeIMOrg() {
};

IexFmncOrg::ImeIMOrg::~ImeIMOrg() {
	clear();
};

void IexFmncOrg::ImeIMOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIMOrg::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIMOrg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncOrg::ImeitemIMOrg();

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

void IexFmncOrg::ImeIMOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIMOrg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMOrg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMOrg", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMOrg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIMOrg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIMOrg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMOrg." << StrMod::replaceChar(ImeIMOrg::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIMOrg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMOrg");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIAMPersonDetail
 ******************************************************************************/

IexFmncOrg::ImeitemIAMPersonDetail::ImeitemIAMPersonDetail(
			const string& x1SrefKType
			, const string& Val
		) : FmncAMPersonDetail() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

IexFmncOrg::ImeitemIAMPersonDetail::ImeitemIAMPersonDetail(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMPersonDetail() {
	FmncAMPersonDetail* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncampersondetail->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		x1SrefKType = rec->x1SrefKType;
		Val = rec->Val;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIAMPersonDetail::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1SrefKType = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Val = txtrd.fields[1];

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

void IexFmncOrg::ImeitemIAMPersonDetail::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType)) ixWIelValid += ImeIAMPersonDetail::VecWIel::X1SREFKTYPE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMPersonDetail::VecWIel::VAL;
	};
};

void IexFmncOrg::ImeitemIAMPersonDetail::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKType << "\t" << Val << endl;
};

void IexFmncOrg::ImeitemIAMPersonDetail::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","val"};
	else tags = {"ImeitemIAMPersonDetail","x1SrefKType","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKType);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIAMPersonDetail::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIAMPersonDetail::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x1SrefKType") ix |= X1SREFKTYPE;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexFmncOrg::ImeIAMPersonDetail::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIAMPersonDetail::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKTYPE) ss.push_back("x1SrefKType");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIAMPersonDetail
 ******************************************************************************/

IexFmncOrg::ImeIAMPersonDetail::ImeIAMPersonDetail() {
};

IexFmncOrg::ImeIAMPersonDetail::~ImeIAMPersonDetail() {
	clear();
};

void IexFmncOrg::ImeIAMPersonDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIAMPersonDetail::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIAMPersonDetail* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIAMPersonDetail();

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

void IexFmncOrg::ImeIAMPersonDetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIAMPersonDetail* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMPersonDetail");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMPersonDetail", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMPersonDetail";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIAMPersonDetail();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIAMPersonDetail::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMPersonDetail." << StrMod::replaceChar(ImeIAMPersonDetail::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIAMPersonDetail::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMPersonDetail");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIJMPersonLastname
 ******************************************************************************/

IexFmncOrg::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : FmncJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexFmncOrg::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMPersonLastname() {
	FmncJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmpersonlastname->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		Lastname = rec->Lastname;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Lastname = txtrd.fields[0];

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

void IexFmncOrg::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexFmncOrg::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Lastname << endl;
};

void IexFmncOrg::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexFmncOrg::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*LASTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIJMPersonLastname
 ******************************************************************************/

IexFmncOrg::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexFmncOrg::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexFmncOrg::ImeIJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIJMPersonLastname();

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

void IexFmncOrg::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIMAddress2
 ******************************************************************************/

IexFmncOrg::ImeitemIMAddress2::ImeitemIMAddress2(
			const string& srefKAdrtype
			, const string& Address1
			, const string& Address2
			, const string& Zipcode
			, const string& City
			, const string& State
			, const string& srefKCountry
		) : FmncMAddress() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefKAdrtype = srefKAdrtype;
	this->Address1 = Address1;
	this->Address2 = Address2;
	this->Zipcode = Zipcode;
	this->City = City;
	this->State = State;
	this->srefKCountry = srefKCountry;
};

IexFmncOrg::ImeitemIMAddress2::ImeitemIMAddress2(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMAddress2() {
	FmncMAddress* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmaddress->loadRecByRef(ref, &rec)) {
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		srefKAdrtype = rec->srefKAdrtype;
		Address1 = rec->Address1;
		Address2 = rec->Address2;
		Zipcode = rec->Zipcode;
		City = rec->City;
		State = rec->State;
		srefKCountry = rec->srefKCountry;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIMAddress2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) srefKAdrtype = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Address1 = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Address2 = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Zipcode = txtrd.fields[3];
	if (txtrd.fields.size() > 4) City = txtrd.fields[4];
	if (txtrd.fields.size() > 5) State = txtrd.fields[5];
	if (txtrd.fields.size() > 6) srefKCountry = txtrd.fields[6];

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

void IexFmncOrg::ImeitemIMAddress2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKAdrtype", "aty", srefKAdrtype)) ixWIelValid += ImeIMAddress2::VecWIel::SREFKADRTYPE;
		if (extractStringUclc(docctx, basexpath, "Address1", "ad1", Address1)) ixWIelValid += ImeIMAddress2::VecWIel::ADDRESS1;
		if (extractStringUclc(docctx, basexpath, "Address2", "ad2", Address2)) ixWIelValid += ImeIMAddress2::VecWIel::ADDRESS2;
		if (extractStringUclc(docctx, basexpath, "Zipcode", "zip", Zipcode)) ixWIelValid += ImeIMAddress2::VecWIel::ZIPCODE;
		if (extractStringUclc(docctx, basexpath, "City", "cty", City)) ixWIelValid += ImeIMAddress2::VecWIel::CITY;
		if (extractStringUclc(docctx, basexpath, "State", "ste", State)) ixWIelValid += ImeIMAddress2::VecWIel::STATE;
		if (extractStringUclc(docctx, basexpath, "srefKCountry", "cry", srefKCountry)) ixWIelValid += ImeIMAddress2::VecWIel::SREFKCOUNTRY;
	};
};

void IexFmncOrg::ImeitemIMAddress2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefKAdrtype << "\t" << Address1 << "\t" << Address2 << "\t" << Zipcode << "\t" << City << "\t" << State << "\t" << srefKCountry << endl;
};

void IexFmncOrg::ImeitemIMAddress2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","aty","ad1","ad2","zip","cty","ste","cry"};
	else tags = {"ImeitemIMAddress2","srefKAdrtype","Address1","Address2","Zipcode","City","State","srefKCountry"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefKAdrtype);
		writeString(wr, tags[2], Address1);
		writeString(wr, tags[3], Address2);
		writeString(wr, tags[4], Zipcode);
		writeString(wr, tags[5], City);
		writeString(wr, tags[6], State);
		writeString(wr, tags[7], srefKCountry);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIMAddress2::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIMAddress2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefKAdrtype") ix |= SREFKADRTYPE;
		else if (ss[i] == "Address1") ix |= ADDRESS1;
		else if (ss[i] == "Address2") ix |= ADDRESS2;
		else if (ss[i] == "Zipcode") ix |= ZIPCODE;
		else if (ss[i] == "City") ix |= CITY;
		else if (ss[i] == "State") ix |= STATE;
		else if (ss[i] == "srefKCountry") ix |= SREFKCOUNTRY;
	};

	return(ix);
};

void IexFmncOrg::ImeIMAddress2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFKCOUNTRY);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIMAddress2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKADRTYPE) ss.push_back("srefKAdrtype");
	if (ix & ADDRESS1) ss.push_back("Address1");
	if (ix & ADDRESS2) ss.push_back("Address2");
	if (ix & ZIPCODE) ss.push_back("Zipcode");
	if (ix & CITY) ss.push_back("City");
	if (ix & STATE) ss.push_back("State");
	if (ix & SREFKCOUNTRY) ss.push_back("srefKCountry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIMAddress2
 ******************************************************************************/

IexFmncOrg::ImeIMAddress2::ImeIMAddress2() {
};

IexFmncOrg::ImeIMAddress2::~ImeIMAddress2() {
	clear();
};

void IexFmncOrg::ImeIMAddress2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIMAddress2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIMAddress2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncOrg::ImeitemIMAddress2();

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

void IexFmncOrg::ImeIMAddress2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIMAddress2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMAddress2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMAddress2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMAddress2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIMAddress2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIMAddress2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMAddress2." << StrMod::replaceChar(ImeIMAddress2::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIMAddress2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMAddress2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIMPerson
 ******************************************************************************/

IexFmncOrg::ImeitemIMPerson::ImeitemIMPerson(
			const ubigint iref
			, const uint ixVSex
			, const string& Title
			, const string& Firstname
		) : FmncMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
};

IexFmncOrg::ImeitemIMPerson::ImeitemIMPerson(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMPerson() {
	FmncMPerson* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmperson->loadRecByRef(ref, &rec)) {
		refFmncMAddress = rec->refFmncMAddress;
		refROrg = rec->refROrg;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		telRefADetail = rec->telRefADetail;
		emlRefADetail = rec->emlRefADetail;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) ixVSex = VecFmncVMPersonSex::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) Title = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Firstname = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMPERSONDETAIL)) {
			if (!imeiampersondetail.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
			if (!imeijmpersonlastname.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMADDRESS2)) {
			if (!imeimaddress2.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncOrg::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVSex;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMPerson::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) {
			ixVSex = VecFmncVMPersonSex::getIx(srefIxVSex);
			ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		imeiampersondetail.readXML(docctx, basexpath);
		imeijmpersonlastname.readXML(docctx, basexpath);
		imeimaddress2.readXML(docctx, basexpath);
	};
};

void IexFmncOrg::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << VecFmncVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << endl;
	imeiampersondetail.writeTxt(outfile);
	imeijmpersonlastname.writeTxt(outfile);
	imeimaddress2.writeTxt(outfile);
};

void IexFmncOrg::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","sex","tit","fnm"};
	else tags = {"ImeitemIMPerson","iref","srefIxVSex","Title","Firstname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], VecFmncVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Firstname);
		imeiampersondetail.writeXML(wr, shorttags);
		imeijmpersonlastname.writeXML(wr, shorttags);
		imeimaddress2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefIxVSex") ix |= SREFIXVSEX;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Firstname") ix |= FIRSTNAME;
	};

	return(ix);
};

void IexFmncOrg::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*FIRSTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIMPerson
 ******************************************************************************/

IexFmncOrg::ImeIMPerson::ImeIMPerson() {
};

IexFmncOrg::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexFmncOrg::ImeIMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncOrg::ImeitemIMPerson();

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

void IexFmncOrg::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncOrg::ImeitemIRMOrgMPerson
 ******************************************************************************/

IexFmncOrg::ImeitemIRMOrgMPerson::ImeitemIRMOrgMPerson(
			const ubigint irefRefFmncMPerson
			, const string& hsrefRefFmncMOrg
			, const string& srefKFunction
		) : FmncRMOrgMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefFmncMPerson = irefRefFmncMPerson;
	this->hsrefRefFmncMOrg = hsrefRefFmncMOrg;
	this->srefKFunction = srefKFunction;
};

IexFmncOrg::ImeitemIRMOrgMPerson::ImeitemIRMOrgMPerson(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIRMOrgMPerson() {
	FmncRMOrgMPerson* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncrmorgmperson->loadRecByRef(ref, &rec)) {
		refFmncMPerson = rec->refFmncMPerson;
		refFmncMOrg = rec->refFmncMOrg;
		srefKFunction = rec->srefKFunction;

		delete rec;
	};
};

bool IexFmncOrg::ImeitemIRMOrgMPerson::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) irefRefFmncMPerson = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) hsrefRefFmncMOrg = txtrd.fields[1];
	if (txtrd.fields.size() > 2) srefKFunction = txtrd.fields[2];

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

void IexFmncOrg::ImeitemIRMOrgMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefFmncMPerson", "prs", irefRefFmncMPerson)) ixWIelValid += ImeIRMOrgMPerson::VecWIel::IREFREFFMNCMPERSON;
		if (extractStringUclc(docctx, basexpath, "hsrefRefFmncMOrg", "org", hsrefRefFmncMOrg)) ixWIelValid += ImeIRMOrgMPerson::VecWIel::HSREFREFFMNCMORG;
		if (extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction)) ixWIelValid += ImeIRMOrgMPerson::VecWIel::SREFKFUNCTION;
	};
};

void IexFmncOrg::ImeitemIRMOrgMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << irefRefFmncMPerson << "\t" << hsrefRefFmncMOrg << "\t" << srefKFunction << endl;
};

void IexFmncOrg::ImeitemIRMOrgMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs","org","fct"};
	else tags = {"ImeitemIRMOrgMPerson","irefRefFmncMPerson","hsrefRefFmncMOrg","srefKFunction"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefFmncMPerson);
		writeString(wr, tags[2], hsrefRefFmncMOrg);
		writeString(wr, tags[3], srefKFunction);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncOrg::ImeIRMOrgMPerson::VecWIel
 ******************************************************************************/

uint IexFmncOrg::ImeIRMOrgMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "irefRefFmncMPerson") ix |= IREFREFFMNCMPERSON;
		else if (ss[i] == "hsrefRefFmncMOrg") ix |= HSREFREFFMNCMORG;
		else if (ss[i] == "srefKFunction") ix |= SREFKFUNCTION;
	};

	return(ix);
};

void IexFmncOrg::ImeIRMOrgMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFKFUNCTION);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncOrg::ImeIRMOrgMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFFMNCMPERSON) ss.push_back("irefRefFmncMPerson");
	if (ix & HSREFREFFMNCMORG) ss.push_back("hsrefRefFmncMOrg");
	if (ix & SREFKFUNCTION) ss.push_back("srefKFunction");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncOrg::ImeIRMOrgMPerson
 ******************************************************************************/

IexFmncOrg::ImeIRMOrgMPerson::ImeIRMOrgMPerson() {
};

IexFmncOrg::ImeIRMOrgMPerson::~ImeIRMOrgMPerson() {
	clear();
};

void IexFmncOrg::ImeIRMOrgMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncOrg::ImeIRMOrgMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexFmncOrg::ImeitemIRMOrgMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncOrg::ImeitemIRMOrgMPerson();

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

void IexFmncOrg::ImeIRMOrgMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncOrg::ImeitemIRMOrgMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMOrgMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMOrgMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMOrgMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncOrg::ImeitemIRMOrgMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncOrg::ImeIRMOrgMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIRMOrgMPerson." << StrMod::replaceChar(ImeIRMOrgMPerson::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncOrg::ImeIRMOrgMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMOrgMPerson");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};


