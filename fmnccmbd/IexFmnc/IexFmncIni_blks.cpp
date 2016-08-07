/**
  * \file IexFmncIni_blks.cpp
  * import/export handler for database DbsFmnc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class IexFmncIni::VecVIme
 ******************************************************************************/

uint IexFmncIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	else if (s == "imeiavkeylistkey1") return IMEIAVKEYLISTKEY1;
	else if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	else if (s == "imeimtooltype") return IMEIMTOOLTYPE;
	else if (s == "imeimusergroup") return IMEIMUSERGROUP;
	else if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	else if (s == "imeiavkeylistkey2") return IMEIAVKEYLISTKEY2;
	else if (s == "imeijavkeylistkey1") return IMEIJAVKEYLISTKEY1;
	else if (s == "imeimstep") return IMEIMSTEP;
	else if (s == "imeimuser") return IMEIMUSER;
	else if (s == "imeiamsteppar") return IMEIAMSTEPPAR;
	else if (s == "imeiavkeylistkey3") return IMEIAVKEYLISTKEY3;
	else if (s == "imeijavkeylistkey2") return IMEIJAVKEYLISTKEY2;
	else if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	else if (s == "imeimperson") return IMEIMPERSON;
	else if (s == "imeiampersondetail") return IMEIAMPERSONDETAIL;
	else if (s == "imeijavkeylistkey3") return IMEIJAVKEYLISTKEY3;
	else if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	else if (s == "imeimaddress") return IMEIMADDRESS;

	return(0);
};

string IexFmncIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	else if (ix == IMEIAVKEYLISTKEY1) return("ImeIAVKeylistKey1");
	else if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	else if (ix == IMEIMTOOLTYPE) return("ImeIMTooltype");
	else if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");
	else if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	else if (ix == IMEIAVKEYLISTKEY2) return("ImeIAVKeylistKey2");
	else if (ix == IMEIJAVKEYLISTKEY1) return("ImeIJAVKeylistKey1");
	else if (ix == IMEIMSTEP) return("ImeIMStep");
	else if (ix == IMEIMUSER) return("ImeIMUser");
	else if (ix == IMEIAMSTEPPAR) return("ImeIAMStepPar");
	else if (ix == IMEIAVKEYLISTKEY3) return("ImeIAVKeylistKey3");
	else if (ix == IMEIJAVKEYLISTKEY2) return("ImeIJAVKeylistKey2");
	else if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	else if (ix == IMEIMPERSON) return("ImeIMPerson");
	else if (ix == IMEIAMPERSONDETAIL) return("ImeIAMPersonDetail");
	else if (ix == IMEIJAVKEYLISTKEY3) return("ImeIJAVKeylistKey3");
	else if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	else if (ix == IMEIMADDRESS) return("ImeIMAddress");

	return("");
};

/******************************************************************************
 class IexFmncIni::ImeitemIAVControlPar
 ******************************************************************************/

IexFmncIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixFmncVControl
			, const string& Par
			, const string& Val
		) : FmncAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixFmncVControl = ixFmncVControl;
	this->Par = Par;
	this->Val = Val;
};

IexFmncIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVControlPar() {
	FmncAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncavcontrolpar->loadRecByRef(ref, &rec)) {
		ixFmncVControl = rec->ixFmncVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixFmncVControl = VecFmncVControl::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Par = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

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

void IexFmncIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxFmncVControl;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxFmncVControl", "ctl", srefIxFmncVControl)) {
			ixFmncVControl = VecFmncVControl::getIx(srefIxFmncVControl);
			ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXFMNCVCONTROL;
		};
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexFmncIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecFmncVControl::getSref(ixFmncVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexFmncIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxFmncVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVControl::getSref(ixFmncVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxFmncVControl") ix |= SREFIXFMNCVCONTROL;
		else if (ss[i] == "Par") ix |= PAR;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexFmncIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXFMNCVCONTROL) ss.push_back("srefIxFmncVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIAVControlPar
 ******************************************************************************/

IexFmncIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexFmncIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexFmncIni::ImeIAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncIni::ImeitemIAVControlPar();

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

void IexFmncIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIJAVKeylistKey1
 ******************************************************************************/

IexFmncIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
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

IexFmncIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
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

bool IexFmncIni::ImeitemIJAVKeylistKey1::readTxt(
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

void IexFmncIni::ImeitemIJAVKeylistKey1::readXML(
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

void IexFmncIni::ImeitemIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncIni::ImeitemIJAVKeylistKey1::writeXML(
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
 class IexFmncIni::ImeIJAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIJAVKeylistKey1::VecWIel::getIx(
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

void IexFmncIni::ImeIJAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIJAVKeylistKey1::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIJAVKeylistKey1
 ******************************************************************************/

IexFmncIni::ImeIJAVKeylistKey1::ImeIJAVKeylistKey1() {
};

IexFmncIni::ImeIJAVKeylistKey1::~ImeIJAVKeylistKey1() {
	clear();
};

void IexFmncIni::ImeIJAVKeylistKey1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIJAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncIni::ImeitemIJAVKeylistKey1();

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

void IexFmncIni::ImeIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIJAVKeylistKey1* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIJAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey1." << StrMod::replaceChar(ImeIJAVKeylistKey1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIJAVKeylistKey1::writeXML(
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
 class IexFmncIni::ImeitemIAVKeylistKey1
 ******************************************************************************/

IexFmncIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
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

IexFmncIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVKeylistKey1() {
	FmncAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxFmncVKeylist = rec->klsIxFmncVKeylist;
		x1IxFmncVMaintable = rec->x1IxFmncVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxFmncVKeylist = VecFmncVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1)) {
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

void IexFmncIni::ImeitemIAVKeylistKey1::readXML(
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

void IexFmncIni::ImeitemIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << VecFmncVKeylist::getSref(klsIxFmncVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey1.writeTxt(outfile);
};

void IexFmncIni::ImeitemIAVKeylistKey1::writeXML(
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
 class IexFmncIni::ImeIAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAVKeylistKey1::VecWIel::getIx(
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

void IexFmncIni::ImeIAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAVKeylistKey1::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIAVKeylistKey1
 ******************************************************************************/

IexFmncIni::ImeIAVKeylistKey1::ImeIAVKeylistKey1() {
};

IexFmncIni::ImeIAVKeylistKey1::~ImeIAVKeylistKey1() {
	clear();
};

void IexFmncIni::ImeIAVKeylistKey1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncIni::ImeitemIAVKeylistKey1();

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

void IexFmncIni::ImeIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAVKeylistKey1* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey1." << StrMod::replaceChar(ImeIAVKeylistKey1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAVKeylistKey1::writeXML(
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
 class IexFmncIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexFmncIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxFmncVValuelist
			, const uint x1IxFmncVLocale
			, const string& Val
		) : FmncAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxFmncVValuelist = vlsIxFmncVValuelist;
	this->x1IxFmncVLocale = x1IxFmncVLocale;
	this->Val = Val;
};

IexFmncIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVValuelistVal() {
	FmncAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxFmncVValuelist = rec->vlsIxFmncVValuelist;
		x1IxFmncVLocale = rec->x1IxFmncVLocale;
		Val = rec->Val;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) vlsIxFmncVValuelist = VecFmncVValuelist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) x1IxFmncVLocale = VecFmncVLocale::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

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

void IexFmncIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefVlsIxFmncVValuelist;
	string srefX1IxFmncVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxFmncVValuelist", "vls", srefVlsIxFmncVValuelist)) {
			vlsIxFmncVValuelist = VecFmncVValuelist::getIx(srefVlsIxFmncVValuelist);
			ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXFMNCVVALUELIST;
		};
		if (extractStringUclc(docctx, basexpath, "srefX1IxFmncVLocale", "lcl", srefX1IxFmncVLocale)) {
			x1IxFmncVLocale = VecFmncVLocale::getIx(srefX1IxFmncVLocale);
			ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXFMNCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexFmncIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecFmncVValuelist::getSref(vlsIxFmncVValuelist) << "\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Val << endl;
};

void IexFmncIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxFmncVValuelist","srefX1IxFmncVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVValuelist::getSref(vlsIxFmncVValuelist));
		writeString(wr, tags[2], VecFmncVLocale::getSref(x1IxFmncVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefVlsIxFmncVValuelist") ix |= SREFVLSIXFMNCVVALUELIST;
		else if (ss[i] == "srefX1IxFmncVLocale") ix |= SREFX1IXFMNCVLOCALE;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexFmncIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXFMNCVVALUELIST) ss.push_back("srefVlsIxFmncVValuelist");
	if (ix & SREFX1IXFMNCVLOCALE) ss.push_back("srefX1IxFmncVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIAVValuelistVal
 ******************************************************************************/

IexFmncIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexFmncIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexFmncIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncIni::ImeitemIAVValuelistVal();

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

void IexFmncIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIJAVKeylistKey2
 ******************************************************************************/

IexFmncIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
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

IexFmncIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
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

bool IexFmncIni::ImeitemIJAVKeylistKey2::readTxt(
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

void IexFmncIni::ImeitemIJAVKeylistKey2::readXML(
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

void IexFmncIni::ImeitemIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncIni::ImeitemIJAVKeylistKey2::writeXML(
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
 class IexFmncIni::ImeIJAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIJAVKeylistKey2::VecWIel::getIx(
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

void IexFmncIni::ImeIJAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIJAVKeylistKey2::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIJAVKeylistKey2
 ******************************************************************************/

IexFmncIni::ImeIJAVKeylistKey2::ImeIJAVKeylistKey2() {
};

IexFmncIni::ImeIJAVKeylistKey2::~ImeIJAVKeylistKey2() {
	clear();
};

void IexFmncIni::ImeIJAVKeylistKey2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIJAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncIni::ImeitemIJAVKeylistKey2();

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

void IexFmncIni::ImeIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIJAVKeylistKey2* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIJAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey2." << StrMod::replaceChar(ImeIJAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIJAVKeylistKey2::writeXML(
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
 class IexFmncIni::ImeitemIAVKeylistKey2
 ******************************************************************************/

IexFmncIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
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

IexFmncIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
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

bool IexFmncIni::ImeitemIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxFmncVKeylist = VecFmncVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2)) {
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

void IexFmncIni::ImeitemIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefKlsIxFmncVKeylist;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxFmncVKeylist", "kls", srefKlsIxFmncVKeylist)) {
			klsIxFmncVKeylist = VecFmncVKeylist::getIx(srefKlsIxFmncVKeylist);
			ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREFKLSIXFMNCVKEYLIST;
		};
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::IMPLIED;
		imeijavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncVKeylist::getSref(klsIxFmncVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey2.writeTxt(outfile);
};

void IexFmncIni::ImeitemIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey2","srefKlsIxFmncVKeylist","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVKeylist::getSref(klsIxFmncVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		imeijavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAVKeylistKey2::VecWIel::getIx(
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

void IexFmncIni::ImeIAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAVKeylistKey2::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIAVKeylistKey2
 ******************************************************************************/

IexFmncIni::ImeIAVKeylistKey2::ImeIAVKeylistKey2() {
};

IexFmncIni::ImeIAVKeylistKey2::~ImeIAVKeylistKey2() {
	clear();
};

void IexFmncIni::ImeIAVKeylistKey2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncIni::ImeitemIAVKeylistKey2();

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

void IexFmncIni::ImeIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAVKeylistKey2* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey2." << StrMod::replaceChar(ImeIAVKeylistKey2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAVKeylistKey2::writeXML(
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
 class IexFmncIni::ImeitemIAMStepPar
 ******************************************************************************/

IexFmncIni::ImeitemIAMStepPar::ImeitemIAMStepPar(
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

IexFmncIni::ImeitemIAMStepPar::ImeitemIAMStepPar(
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

bool IexFmncIni::ImeitemIAMStepPar::readTxt(
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

void IexFmncIni::ImeitemIAMStepPar::readXML(
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

void IexFmncIni::ImeitemIAMStepPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1OsrefFmncKSteppar << "\t" << Val << "\t" << Comment << endl;
};

void IexFmncIni::ImeitemIAMStepPar::writeXML(
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
 class IexFmncIni::ImeIAMStepPar::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAMStepPar::VecWIel::getIx(
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

void IexFmncIni::ImeIAMStepPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAMStepPar::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIAMStepPar
 ******************************************************************************/

IexFmncIni::ImeIAMStepPar::ImeIAMStepPar() {
};

IexFmncIni::ImeIAMStepPar::~ImeIAMStepPar() {
	clear();
};

void IexFmncIni::ImeIAMStepPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAMStepPar::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAMStepPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncIni::ImeitemIAMStepPar();

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

void IexFmncIni::ImeIAMStepPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAMStepPar* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIAMStepPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAMStepPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMStepPar." << StrMod::replaceChar(ImeIAMStepPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAMStepPar::writeXML(
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
 class IexFmncIni::ImeitemIJAVKeylistKey3
 ******************************************************************************/

IexFmncIni::ImeitemIJAVKeylistKey3::ImeitemIJAVKeylistKey3(
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

IexFmncIni::ImeitemIJAVKeylistKey3::ImeitemIJAVKeylistKey3(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJAVKeylistKey3() {
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

bool IexFmncIni::ImeitemIJAVKeylistKey3::readTxt(
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

void IexFmncIni::ImeitemIJAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxFmncVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxFmncVLocale", "lcl", srefX1IxFmncVLocale)) {
			x1IxFmncVLocale = VecFmncVLocale::getIx(srefX1IxFmncVLocale);
			ixWIelValid += ImeIJAVKeylistKey3::VecWIel::SREFX1IXFMNCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey3::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey3::VecWIel::COMMENT;
	};
};

void IexFmncIni::ImeitemIJAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecFmncVLocale::getSref(x1IxFmncVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexFmncIni::ImeitemIJAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey3","srefX1IxFmncVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVLocale::getSref(x1IxFmncVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIJAVKeylistKey3::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIJAVKeylistKey3::VecWIel::getIx(
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

void IexFmncIni::ImeIJAVKeylistKey3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIJAVKeylistKey3::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIJAVKeylistKey3
 ******************************************************************************/

IexFmncIni::ImeIJAVKeylistKey3::ImeIJAVKeylistKey3() {
};

IexFmncIni::ImeIJAVKeylistKey3::~ImeIJAVKeylistKey3() {
	clear();
};

void IexFmncIni::ImeIJAVKeylistKey3::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIJAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIJAVKeylistKey3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexFmncIni::ImeitemIJAVKeylistKey3();

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

void IexFmncIni::ImeIJAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIJAVKeylistKey3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey3", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIJAVKeylistKey3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIJAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAVKeylistKey3." << StrMod::replaceChar(ImeIJAVKeylistKey3::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIJAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey3");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIAVKeylistKey3
 ******************************************************************************/

IexFmncIni::ImeitemIAVKeylistKey3::ImeitemIAVKeylistKey3(
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

IexFmncIni::ImeitemIAVKeylistKey3::ImeitemIAVKeylistKey3(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAVKeylistKey3() {
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

bool IexFmncIni::ImeitemIAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Avail = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Implied = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY3)) {
			if (!imeijavkeylistkey3.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncIni::ImeitemIAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::IMPLIED;
		imeijavkeylistkey3.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey3.writeTxt(outfile);
};

void IexFmncIni::ImeitemIAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey3","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		imeijavkeylistkey3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIAVKeylistKey3::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAVKeylistKey3::VecWIel::getIx(
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

void IexFmncIni::ImeIAVKeylistKey3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAVKeylistKey3::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIAVKeylistKey3
 ******************************************************************************/

IexFmncIni::ImeIAVKeylistKey3::ImeIAVKeylistKey3() {
};

IexFmncIni::ImeIAVKeylistKey3::~ImeIAVKeylistKey3() {
	clear();
};

void IexFmncIni::ImeIAVKeylistKey3::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAVKeylistKey3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncIni::ImeitemIAVKeylistKey3();

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

void IexFmncIni::ImeIAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAVKeylistKey3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey3", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIAVKeylistKey3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAVKeylistKey3." << StrMod::replaceChar(ImeIAVKeylistKey3::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey3");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIMStep
 ******************************************************************************/

IexFmncIni::ImeitemIMStep::ImeitemIMStep(
			const uint ixWFilecfg
			, const string& Title
		) : FmncMStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWFilecfg = ixWFilecfg;
	this->Title = Title;
};

IexFmncIni::ImeitemIMStep::ImeitemIMStep(
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

bool IexFmncIni::ImeitemIMStep::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixWFilecfg = VecFmncWMStepFilecfg::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMSTEPPAR)) {
			if (!imeiamsteppar.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY3)) {
			if (!imeiavkeylistkey3.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncIni::ImeitemIMStep::readXML(
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
		imeiavkeylistkey3.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIMStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncWMStepFilecfg::getSrefs(ixWFilecfg) << "\t" << Title << endl;
	imeiamsteppar.writeTxt(outfile);
	imeiavkeylistkey3.writeTxt(outfile);
};

void IexFmncIni::ImeitemIMStep::writeXML(
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
		imeiavkeylistkey3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIMStep::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIMStep::VecWIel::getIx(
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

void IexFmncIni::ImeIMStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*TITLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIMStep::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIMStep
 ******************************************************************************/

IexFmncIni::ImeIMStep::ImeIMStep() {
};

IexFmncIni::ImeIMStep::~ImeIMStep() {
	clear();
};

void IexFmncIni::ImeIMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIMStep::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIMStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncIni::ImeitemIMStep();

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

void IexFmncIni::ImeIMStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIMStep* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIMStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIMStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMStep." << StrMod::replaceChar(ImeIMStep::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIMStep::writeXML(
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
 class IexFmncIni::ImeitemIMTooltype
 ******************************************************************************/

IexFmncIni::ImeitemIMTooltype::ImeitemIMTooltype(
			const string& hsrefSupRefFmncMTooltype
			, const string& sref
			, const string& Title
		) : FmncMTooltype() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefFmncMTooltype = hsrefSupRefFmncMTooltype;
	this->sref = sref;
	this->Title = Title;
};

IexFmncIni::ImeitemIMTooltype::ImeitemIMTooltype(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMTooltype() {
	FmncMTooltype* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmtooltype->loadRecByRef(ref, &rec)) {
		supRefFmncMTooltype = rec->supRefFmncMTooltype;
		sref = rec->sref;
		Title = rec->Title;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIMTooltype::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hsrefSupRefFmncMTooltype = txtrd.fields[0];
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Title = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2)) {
			if (!imeiavkeylistkey2.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSTEP)) {
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

void IexFmncIni::ImeitemIMTooltype::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefFmncMTooltype", "sup", hsrefSupRefFmncMTooltype)) ixWIelValid += ImeIMTooltype::VecWIel::HSREFSUPREFFMNCMTOOLTYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMTooltype::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMTooltype::VecWIel::TITLE;
		imeiavkeylistkey2.readXML(docctx, basexpath);
		imeimstep.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIMTooltype::writeTxt(
			fstream& outfile
		) {
	outfile << hsrefSupRefFmncMTooltype << "\t" << sref << "\t" << Title << endl;
	imeiavkeylistkey2.writeTxt(outfile);
	imeimstep.writeTxt(outfile);
};

void IexFmncIni::ImeitemIMTooltype::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sup","srf","tit"};
	else tags = {"ImeitemIMTooltype","hsrefSupRefFmncMTooltype","sref","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefSupRefFmncMTooltype);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		imeiavkeylistkey2.writeXML(wr, shorttags);
		imeimstep.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIMTooltype::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIMTooltype::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hsrefSupRefFmncMTooltype") ix |= HSREFSUPREFFMNCMTOOLTYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Title") ix |= TITLE;
	};

	return(ix);
};

void IexFmncIni::ImeIMTooltype::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*TITLE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIMTooltype::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFSUPREFFMNCMTOOLTYPE) ss.push_back("hsrefSupRefFmncMTooltype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIMTooltype
 ******************************************************************************/

IexFmncIni::ImeIMTooltype::ImeIMTooltype() {
};

IexFmncIni::ImeIMTooltype::~ImeIMTooltype() {
	clear();
};

void IexFmncIni::ImeIMTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIMTooltype::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIMTooltype* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncIni::ImeitemIMTooltype();

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

void IexFmncIni::ImeIMTooltype::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIMTooltype* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTooltype");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTooltype", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTooltype";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIMTooltype();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIMTooltype::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMTooltype." << StrMod::replaceChar(ImeIMTooltype::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIMTooltype::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTooltype");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexFmncIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) : FmncAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxFmncVCard = x1IxFmncVCard;
	this->ixFmncWUiaccess = ixFmncWUiaccess;
};

IexFmncIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIAMUsergroupAccess() {
	FmncAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncamusergroupaccess->loadRecByRef(ref, &rec)) {
		refFmncMUsergroup = rec->refFmncMUsergroup;
		x1IxFmncVCard = rec->x1IxFmncVCard;
		ixFmncWUiaccess = rec->ixFmncWUiaccess;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxFmncVCard = VecFmncVCard::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) ixFmncWUiaccess = VecFmncWUiaccess::getIx(txtrd.fields[1]);

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

void IexFmncIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxFmncVCard;
	string srefsIxFmncWUiaccess;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxFmncVCard", "crd", srefX1IxFmncVCard)) {
			x1IxFmncVCard = VecFmncVCard::getIx(srefX1IxFmncVCard);
			ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXFMNCVCARD;
		};
		if (extractStringUclc(docctx, basexpath, "srefsIxFmncWUiaccess", "uac", srefsIxFmncWUiaccess)) {
			ixFmncWUiaccess = VecFmncWUiaccess::getIx(srefsIxFmncWUiaccess);
			ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXFMNCWUIACCESS;
		};
	};
};

void IexFmncIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecFmncVCard::getSref(x1IxFmncVCard) << "\t" << VecFmncWUiaccess::getSrefs(ixFmncWUiaccess) << endl;
};

void IexFmncIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","crd","uac"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxFmncVCard","srefsIxFmncWUiaccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVCard::getSref(x1IxFmncVCard));
		writeString(wr, tags[2], VecFmncWUiaccess::getSrefs(ixFmncWUiaccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxFmncVCard") ix |= SREFX1IXFMNCVCARD;
		else if (ss[i] == "srefsIxFmncWUiaccess") ix |= SREFSIXFMNCWUIACCESS;
	};

	return(ix);
};

void IexFmncIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFSIXFMNCWUIACCESS);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXFMNCVCARD) ss.push_back("srefX1IxFmncVCard");
	if (ix & SREFSIXFMNCWUIACCESS) ss.push_back("srefsIxFmncWUiaccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexFmncIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexFmncIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexFmncIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncIni::ImeitemIAMUsergroupAccess();

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

void IexFmncIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIJMUserState
 ******************************************************************************/

IexFmncIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : FmncJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexFmncIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIJMUserState() {
	FmncJMUserState* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncjmuserstate->loadRecByRef(ref, &rec)) {
		refFmncMUser = rec->refFmncMUser;
		ixVState = rec->ixVState;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVState = VecFmncVMUserState::getIx(txtrd.fields[0]);

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

void IexFmncIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVState;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) {
			ixVState = VecFmncVMUserState::getIx(srefIxVState);
			ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
		};
	};
};

void IexFmncIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecFmncVMUserState::getSref(ixVState) << endl;
};

void IexFmncIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxVState") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexFmncIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVSTATE);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIJMUserState
 ******************************************************************************/

IexFmncIni::ImeIJMUserState::ImeIJMUserState() {
};

IexFmncIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexFmncIni::ImeIJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncIni::ImeitemIJMUserState();

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

void IexFmncIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIAMPersonDetail
 ******************************************************************************/

IexFmncIni::ImeitemIAMPersonDetail::ImeitemIAMPersonDetail(
			const string& x1SrefKType
			, const string& Val
		) : FmncAMPersonDetail() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

IexFmncIni::ImeitemIAMPersonDetail::ImeitemIAMPersonDetail(
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

bool IexFmncIni::ImeitemIAMPersonDetail::readTxt(
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

void IexFmncIni::ImeitemIAMPersonDetail::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType)) ixWIelValid += ImeIAMPersonDetail::VecWIel::X1SREFKTYPE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMPersonDetail::VecWIel::VAL;
	};
};

void IexFmncIni::ImeitemIAMPersonDetail::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << x1SrefKType << "\t" << Val << endl;
};

void IexFmncIni::ImeitemIAMPersonDetail::writeXML(
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
 class IexFmncIni::ImeIAMPersonDetail::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIAMPersonDetail::VecWIel::getIx(
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

void IexFmncIni::ImeIAMPersonDetail::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIAMPersonDetail::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIAMPersonDetail
 ******************************************************************************/

IexFmncIni::ImeIAMPersonDetail::ImeIAMPersonDetail() {
};

IexFmncIni::ImeIAMPersonDetail::~ImeIAMPersonDetail() {
	clear();
};

void IexFmncIni::ImeIAMPersonDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIAMPersonDetail::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIAMPersonDetail* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexFmncIni::ImeitemIAMPersonDetail();

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

void IexFmncIni::ImeIAMPersonDetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIAMPersonDetail* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIAMPersonDetail();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIAMPersonDetail::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMPersonDetail." << StrMod::replaceChar(ImeIAMPersonDetail::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIAMPersonDetail::writeXML(
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
 class IexFmncIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexFmncIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : FmncJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexFmncIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
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

bool IexFmncIni::ImeitemIJMPersonLastname::readTxt(
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

void IexFmncIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexFmncIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexFmncIni::ImeitemIJMPersonLastname::writeXML(
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
 class IexFmncIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIJMPersonLastname::VecWIel::getIx(
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

void IexFmncIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*LASTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIJMPersonLastname
 ******************************************************************************/

IexFmncIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexFmncIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexFmncIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexFmncIni::ImeitemIJMPersonLastname();

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

void IexFmncIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIJMPersonLastname* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIJMPersonLastname::writeXML(
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
 class IexFmncIni::ImeitemIMAddress
 ******************************************************************************/

IexFmncIni::ImeitemIMAddress::ImeitemIMAddress(
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

IexFmncIni::ImeitemIMAddress::ImeitemIMAddress(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMAddress() {
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

bool IexFmncIni::ImeitemIMAddress::readTxt(
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

void IexFmncIni::ImeitemIMAddress::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKAdrtype", "aty", srefKAdrtype)) ixWIelValid += ImeIMAddress::VecWIel::SREFKADRTYPE;
		if (extractStringUclc(docctx, basexpath, "Address1", "ad1", Address1)) ixWIelValid += ImeIMAddress::VecWIel::ADDRESS1;
		if (extractStringUclc(docctx, basexpath, "Address2", "ad2", Address2)) ixWIelValid += ImeIMAddress::VecWIel::ADDRESS2;
		if (extractStringUclc(docctx, basexpath, "Zipcode", "zip", Zipcode)) ixWIelValid += ImeIMAddress::VecWIel::ZIPCODE;
		if (extractStringUclc(docctx, basexpath, "City", "cty", City)) ixWIelValid += ImeIMAddress::VecWIel::CITY;
		if (extractStringUclc(docctx, basexpath, "State", "ste", State)) ixWIelValid += ImeIMAddress::VecWIel::STATE;
		if (extractStringUclc(docctx, basexpath, "srefKCountry", "cry", srefKCountry)) ixWIelValid += ImeIMAddress::VecWIel::SREFKCOUNTRY;
	};
};

void IexFmncIni::ImeitemIMAddress::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefKAdrtype << "\t" << Address1 << "\t" << Address2 << "\t" << Zipcode << "\t" << City << "\t" << State << "\t" << srefKCountry << endl;
};

void IexFmncIni::ImeitemIMAddress::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","aty","ad1","ad2","zip","cty","ste","cry"};
	else tags = {"ImeitemIMAddress","srefKAdrtype","Address1","Address2","Zipcode","City","State","srefKCountry"};

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
 class IexFmncIni::ImeIMAddress::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIMAddress::VecWIel::getIx(
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

void IexFmncIni::ImeIMAddress::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFKCOUNTRY);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIMAddress::VecWIel::getSrefs(
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
 class IexFmncIni::ImeIMAddress
 ******************************************************************************/

IexFmncIni::ImeIMAddress::ImeIMAddress() {
};

IexFmncIni::ImeIMAddress::~ImeIMAddress() {
	clear();
};

void IexFmncIni::ImeIMAddress::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIMAddress::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIMAddress* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexFmncIni::ImeitemIMAddress();

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

void IexFmncIni::ImeIMAddress::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIMAddress* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMAddress");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMAddress", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMAddress";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIMAddress();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIMAddress::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMAddress." << StrMod::replaceChar(ImeIMAddress::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIMAddress::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMAddress");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIMPerson
 ******************************************************************************/

IexFmncIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
		) : FmncMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
};

IexFmncIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMPerson() {
	FmncMPerson* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		refFmncMAddress = rec->refFmncMAddress;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		telRefADetail = rec->telRefADetail;
		emlRefADetail = rec->emlRefADetail;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVSex = VecFmncVMPersonSex::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Firstname = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMPERSONDETAIL)) {
			if (!imeiampersondetail.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
			if (!imeijmpersonlastname.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMADDRESS)) {
			if (!imeimaddress.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVSex;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) {
			ixVSex = VecFmncVMPersonSex::getIx(srefIxVSex);
			ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		imeiampersondetail.readXML(docctx, basexpath);
		imeijmpersonlastname.readXML(docctx, basexpath);
		imeimaddress.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecFmncVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << endl;
	imeiampersondetail.writeTxt(outfile);
	imeijmpersonlastname.writeTxt(outfile);
	imeimaddress.writeTxt(outfile);
};

void IexFmncIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecFmncVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		imeiampersondetail.writeXML(wr, shorttags);
		imeijmpersonlastname.writeXML(wr, shorttags);
		imeimaddress.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxVSex") ix |= SREFIXVSEX;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Firstname") ix |= FIRSTNAME;
	};

	return(ix);
};

void IexFmncIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*FIRSTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIMPerson
 ******************************************************************************/

IexFmncIni::ImeIMPerson::ImeIMPerson() {
};

IexFmncIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexFmncIni::ImeIMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexFmncIni::ImeitemIMPerson();

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

void IexFmncIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIMPerson* ii = NULL;

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

			ii = new IexFmncIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIMPerson::writeXML(
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
 class IexFmncIni::ImeitemIMUser
 ******************************************************************************/

IexFmncIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixFmncVLocale
			, const uint ixFmncVUserlevel
			, const string& Password
		) : FmncMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixFmncVLocale = ixFmncVLocale;
	this->ixFmncVUserlevel = ixFmncVUserlevel;
	this->Password = Password;
};

IexFmncIni::ImeitemIMUser::ImeitemIMUser(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMUser() {
	FmncMUser* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refFmncMPerson = rec->refFmncMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixFmncVLocale = rec->ixFmncVLocale;
		ixFmncVUserlevel = rec->ixFmncVUserlevel;
		Password = rec->Password;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) ixFmncVLocale = VecFmncVLocale::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) ixFmncVUserlevel = VecFmncVUserlevel::getIx(txtrd.fields[2]);
	if (txtrd.fields.size() > 3) Password = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
			if (!imeijmuserstate.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
			if (!imeimperson.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxFmncVLocale;
	string srefIxFmncVUserlevel;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxFmncVLocale", "lcl", srefIxFmncVLocale)) {
			ixFmncVLocale = VecFmncVLocale::getIx(srefIxFmncVLocale);
			ixWIelValid += ImeIMUser::VecWIel::SREFIXFMNCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "srefIxFmncVUserlevel", "ulv", srefIxFmncVUserlevel)) {
			ixFmncVUserlevel = VecFmncVUserlevel::getIx(srefIxFmncVUserlevel);
			ixWIelValid += ImeIMUser::VecWIel::SREFIXFMNCVUSERLEVEL;
		};
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecFmncVLocale::getSref(ixFmncVLocale) << "\t" << VecFmncVUserlevel::getSref(ixFmncVUserlevel) << "\t" << Password << endl;
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexFmncIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","lcl","ulv","pwd"};
	else tags = {"ImeitemIMUser","sref","srefIxFmncVLocale","srefIxFmncVUserlevel","Password"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecFmncVLocale::getSref(ixFmncVLocale));
		writeString(wr, tags[3], VecFmncVUserlevel::getSref(ixFmncVUserlevel));
		writeString(wr, tags[4], Password);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefIxFmncVLocale") ix |= SREFIXFMNCVLOCALE;
		else if (ss[i] == "srefIxFmncVUserlevel") ix |= SREFIXFMNCVUSERLEVEL;
		else if (ss[i] == "Password") ix |= PASSWORD;
	};

	return(ix);
};

void IexFmncIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*PASSWORD);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXFMNCVLOCALE) ss.push_back("srefIxFmncVLocale");
	if (ix & SREFIXFMNCVUSERLEVEL) ss.push_back("srefIxFmncVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIMUser
 ******************************************************************************/

IexFmncIni::ImeIMUser::ImeIMUser() {
};

IexFmncIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexFmncIni::ImeIMUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexFmncIni::ImeitemIMUser();

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

void IexFmncIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexFmncIni::ImeitemIMUsergroup
 ******************************************************************************/

IexFmncIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : FmncMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexFmncIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsFmnc* dbsfmnc
			, const ubigint ref
		) : ImeitemIMUsergroup() {
	FmncMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbsfmnc->tblfmncmusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexFmncIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Comment = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
			if (!imeiamusergroupaccess.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
			if (!imeimuser.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexFmncIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexFmncIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexFmncIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexFmncIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexFmncIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexFmncIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexFmncIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexFmncIni::ImeIMUsergroup
 ******************************************************************************/

IexFmncIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexFmncIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexFmncIni::ImeIMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexFmncIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexFmncIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexFmncIni::ImeitemIMUsergroup();

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

void IexFmncIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexFmncIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexFmncIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexFmncIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexFmncIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};


