/**
  * \file Fmnc.cpp
  * Fmnc global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "Fmnc.h"

// IP acv --- BEGIN
/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsFmnc* dbsfmnc
			, const string& acvpath
			, const string& path
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	FmncMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	fil = new FmncMFile(0, 0, 0, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	dbsfmnc->tblfmncmfile->insertRec(fil);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbsfmnc->tblfmncmfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	// copy file
	s = "cp " + path + " " + str.str() + "/" + fil->Archivename;
	system(s.c_str());

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsFmnc* dbsfmnc
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	FmncMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbsfmnc->tblfmncmfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbsfmnc->tblfmncmfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

		// copy file
		s = "cp " + path + " " + str.str() + "/" + fil->Archivename;
		system(s.c_str());

		delete fil;
	};
};

string Acv::getfile(
			DbsFmnc* dbsfmnc
			, const ubigint refFmncMFile
		) {
	FmncMFile* fil = NULL;

	ostringstream str;

	dbsfmnc->tblfmncmfile->loadRecByRef(refFmncMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};
// IP acv --- END

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixFmncVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixFmncVLop == VecFmncVLop::INS) insert(refsList, refsPool, ref);
	else if (ixFmncVLop == VecFmncVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsPool.size();i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixFmncVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixFmncVOolop == VecFmncVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixFmncVOolop == VecFmncVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixFmncVOolop == VecFmncVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixFmncVOolop == VecFmncVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixFmncVOolop == VecFmncVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixFmncVOolop == VecFmncVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k=i+1;k<j;k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k=i+1;k<j;k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref1) {
			for (auto itList2=refsList.begin();itList2!=refsList.end();itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename + "." + ext;

		// check if present, create otherwise
		if (access(filename.c_str(), R_OK | W_OK) == -1) {
			tmpfile.open(filename.c_str(), ios::out);
			tmpfile.close();

			valid = true;
		};
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// check if present, create otherwise
		if (access(foldername.c_str(), R_OK | W_OK) == -1) {
#ifdef _WIN32
			mkdir(foldername.c_str());
#else
			mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

			valid = true;
		};
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i=0;i<8;i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- INSERT

/******************************************************************************
 namespace Fmnc
 ******************************************************************************/

// IP gbl --- INSERT

/******************************************************************************
 namespace StubFmnc
 ******************************************************************************/

string StubFmnc::getStub(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVStub
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	if (ixFmncVStub == VecFmncVStub::STUBFMNCACTSTD) return getStubActStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCADRSTD) return getStubAdrStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCARTSTD) return getStubArtStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCBILSTD) return getStubBilStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCFABSREF) return getStubFabSref(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCFABSTD) return getStubFabStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCFILSTD) return getStubFilStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCFPJSTD) return getStubFpjStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCFUSSTD) return getStubFusStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCGRP) return getStubGrp(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCORGHSREF) return getStubOrgHsref(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCORGSREF) return getStubOrgSref(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCORGSTD) return getStubOrgStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCOWN) return getStubOwn(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCPCOSTD) return getStubPcoStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCPRJSTD) return getStubPrjStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCPRSSTD) return getStubPrsStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCPRSWORG) return getStubPrsWorg(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCRUNSTD) return getStubRunStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSEPSTD) return getStubSepStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSESMENU) return getStubSesMenu(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSESSTD) return getStubSesStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSKISTD) return getStubSkiStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSMPHSREF) return getStubSmpHsref(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSMPSTD) return getStubSmpStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCSTESTD) return getStubSteStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCTOLSTD) return getStubTolStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCTTYSTD) return getStubTtyStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCUSGSTD) return getStubUsgStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixFmncVStub == VecFmncVStub::STUBFMNCUSRSTD) return getStubUsrStd(dbsfmnc, ref, ixFmncVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubFmnc::getStubActStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'FOx mask'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCACTSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no activity)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Aktivit\\u00e4t)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne activit\\u00e9)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmactivity->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubAdrStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Avenue de Bellevaux 51, 2000 Neuchatel, Switzerland'
	string stub;

	FmncMAddress* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCADRSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no address)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Adresse)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne adresse)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmaddress->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFmncAdrStd --- BEGIN
			stub = dbsfmnc->getKlstTitleBySref(VecFmncVKeylist::KLSTFMNCKMADDRESSCOUNTRY, rec->srefKCountry, ixFmncVLocale);
			if (stub.length() > 0) stub = ", " + stub;
			stub = rec->City + stub;
			if (rec->Zipcode.length() > 0) stub = rec->Zipcode + " " + stub;
			if (rec->Address1.length() > 0) stub = rec->Address1 + ", " + stub;
// IP getStubFmncAdrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubArtStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: '4 inch p-Si 100'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCARTSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no article)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Artikel)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun article)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmarticle->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubBilStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'FAC2010-6784 (cea55390)'
	string stub;

	FmncMBill* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCBILSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no bill)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Rechnung)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne facture)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmbill->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubBilStd --- IBEGIN
			stub = rec->sref + " (" + getStubFpjStd(dbsfmnc, rec->refFmncMFabproject, ixFmncVLocale, ixVNonetype, stcch, &stref) + ")";
// IP getStubBilStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubFabSref(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'pta'
	string stub;

	FmncMFab* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCFABSREF, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no fab)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Reinraum)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne salle blanche)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmfab->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFabSref --- IBEGIN
			stub = getStubOrgSref(dbsfmnc, rec->refFmncMOrg, ixFmncVLocale, ixVNonetype, stcch, &stref);
// IP getStubFabSref --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubFabStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'PTA Grenoble'
	string stub;

	FmncMFab* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCFABSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no fab)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Reinraum)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne salle blanche)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmfab->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFabStd --- IBEGIN
			stub = getStubOrgStd(dbsfmnc, rec->refFmncMOrg, ixFmncVLocale, ixVNonetype, stcch, &stref);
// IP getStubFabStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubFilStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Ex_prof.hdf5'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCFILSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no file)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Datei)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun fichier)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmfile->loadFnmByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubFpjStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'cea55390'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCFPJSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keines)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no fab project)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Reinraumprojekt)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun projet salle blanche)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmfabproject->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubFusStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Michael Meyer (bad77590)'
	string stub;

	FmncMFabuser* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCFUSSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no fab user)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Reinraumnutzer)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun utilisateur salle blanche)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmfabuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFusStd --- IBEGIN
			stub = getStubPrsStd(dbsfmnc, rec->refFmncMPerson, ixFmncVLocale, ixVNonetype, stcch, &stref) + " (" + rec->sref + ")";
// IP getStubFusStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubGrp(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'agroup'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCGRP, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no user group)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Benutzergruppe)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne groupe d'utilisateurs)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubOrgHsref(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'cea;inac;sp2m;npsc'
	string stub;

	FmncMOrg* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCORGHSREF, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no organization)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Organisation)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun organisme)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmorg->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefFmncMOrg != 0) stub = getStubOrgHsref(dbsfmnc, rec->supRefFmncMOrg, ixFmncVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubOrgSref(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'npsc'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCORGSREF, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no organization)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Organisation)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun organisme)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmorg->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubOrgStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'University of Neuchatel'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCORGSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no organization)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Organisation)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun organisme)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmorg->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubOwn(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'auser'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCOWN, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no user)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Benutzer)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun utilisateur)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubPcoStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'LTF13123 NovaGaN'
	string stub;

	FmncMPurchorder* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCPCOSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no purchase order)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Bestellung)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne commande)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmpurchorder->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubPcoStd --- IBEGIN
			stub = rec->sref + " " + getStubOrgStd(dbsfmnc, rec->splRefFmncMOrg, ixFmncVLocale, ixVNonetype, stcch, &stref);
// IP getStubPcoStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubPrjStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'development of III-nitride nanotechnology'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCPRJSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keines)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no project)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Projekt)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun projet)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmproject->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubPrsStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Franz Kuntz'
	string stub;

	FmncMPerson* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCPRSSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no person)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Person)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun individu)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFmncPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
// IP getStubFmncPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubPrsWorg(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: '(npsc) Franz Kuntz'
	string stub;

	FmncMPerson* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCPRSWORG, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no person)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Person)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun individu)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubPrsWorg --- IBEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			stub = "(" + getStubOrgStd(dbsfmnc, rec->refFmncMOrg, ixFmncVLocale, ixVNonetype, stcch, &stref) + ") " + stub;
// IP getStubPrsWorg --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubRunStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'lithography for hard mask definition'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCRUNSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no run)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Lauf)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun d\\u00e9roulement)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmrun->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubSepStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'FOx mask, SEM inspection'
	string stub;

	FmncMStep* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCSEPSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no step)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Schritt)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne \\u00e9tape)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmstep->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubSepStd --- IBEGIN
			stub = getStubActStd(dbsfmnc, rec->refFmncMActivity, ixFmncVLocale, ixVNonetype, stcch, &stref) + ", " + rec->Title;
// IP getStubSepStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubSesMenu(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'user Franz Kuntz (fkuntz) logged in from 127.0.0.1 since 01-01-2010 10:34'
	string stub;

	FmncMSession* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCSESMENU, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no session)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Sitzung)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne s\\u00e9ance)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFmncSesMenu --- BEGIN
			if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "user " + getStubUsrStd(dbsfmnc, rec->refFmncMUser, ixFmncVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "Benutzer " + getStubUsrStd(dbsfmnc, rec->refFmncMUser, ixFmncVLocale, ixVNonetype, stcch, &stref) + ";eingeloggt von " + rec->Ip + ";seit " + Ftm::stamp(rec->start);
			else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "utilisateur " + getStubUsrStd(dbsfmnc, rec->refFmncMUser, ixFmncVLocale, ixVNonetype, stcch, &stref) + ";connect\u00e9 de " + rec->Ip + ";depuis " + Ftm::stamp(rec->start);
// IP getStubFmncSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubSesStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: '01-01-2010 10:34 from 127.0.0.1'
	string stub;

	FmncMSession* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCSESSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no session)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Sitzung)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne s\\u00e9ance)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFmncSesStd --- BEGIN
			if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = Ftm::stamp(rec->start) + " von " + rec->Ip;
			else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = Ftm::stamp(rec->start) + " de " + rec->Ip;
// IP getStubFmncSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubSkiStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: '13x 4 inch p-Si 100'
	string stub;

	FmncMStockitem* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCSKISTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no stock item)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Lagerposten)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun poste du stock)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmstockitem->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubSkiStd --- IBEGIN
			stub = rec->Quantity + "x " + getStubArtStd(dbsfmnc, rec->refFmncMArticle, ixFmncVLocale, ixVNonetype, stcch, &stref);
// IP getStubSkiStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubSmpHsref(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'X0001;X0001-2'
	string stub;

	FmncMSample* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCSMPHSREF, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keines)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no sample)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Sample)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun \\u00e9chantillon)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmsample->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefFmncMSample != 0) stub = getStubSmpHsref(dbsfmnc, rec->supRefFmncMSample, ixFmncVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubSmpStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'X0001'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCSMPSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keines)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no sample)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Sample)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun \\u00e9chantillon)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmsample->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubSteStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'SEM inspection'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCSTESTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no step)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Schritt)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne \\u00e9tape)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmstep->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubTolStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: '(pta) STS-ICP 80'
	string stub;

	FmncMTool* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCTOLSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keines)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no tool)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Ger\\u00e4t)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun \\u00e9quipement)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmtool->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubTolStd --- IBEGIN
			stub = "(" + getStubFabSref(dbsfmnc, rec->fabRefFmncMFab, ixFmncVLocale, ixVNonetype, stcch, &stref) + ") " + rec->Title;
// IP getStubTolStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubTtyStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'rie;icp;cl'
	string stub;

	FmncMTooltype* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCTTYSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no tool type)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Ger\\u00e4tetyp)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun type d'\\u00e9quipement)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmtooltype->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefFmncMTooltype != 0) stub = getStubTtyStd(dbsfmnc, rec->supRefFmncMTooltype, ixFmncVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubFmnc::getStubUsgStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'super'
	string stub;

	stref_t stref(VecFmncVStub::STUBFMNCUSGSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no user group)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keine Benutzergruppe)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucunne groupe d'utilisateurs)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubFmnc::getStubUsrStd(
			DbsFmnc* dbsfmnc
			, const ubigint ref
			, const uint ixFmncVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Franz Kuntz (fkuntz)'
	string stub;

	FmncMUser* rec = NULL;

	stref_t stref(VecFmncVStub::STUBFMNCUSRSTD, ref, ixFmncVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(none)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(keiner)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) stub = "(no user)";
		else if (ixFmncVLocale == VecFmncVLocale::DECH) stub = "(kein Benutzer)";
		else if (ixFmncVLocale == VecFmncVLocale::FRCH) stub = "(aucun utilisateur)";
	};

	if (ref != 0) {
		if (dbsfmnc->tblfmncmuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFmncUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbsfmnc, rec->refFmncMPerson, ixFmncVLocale, ixVNonetype, stcch, &stref);
// IP getStubFmncUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class ContInfFmncAlert
 ******************************************************************************/

ContInfFmncAlert::ContInfFmncAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
		) : Block() {
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10};
};

bool ContInfFmncAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;

	return true;
};

void ContInfFmncAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfFmncAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfFmncAlert::compare(
			const ContInfFmncAlert* comp
		) {
	set<uint> items;

	if (TxtCpt.compare(comp->TxtCpt) == 0) insert(items, TXTCPT);
	if (TxtMsg1.compare(comp->TxtMsg1) == 0) insert(items, TXTMSG1);
	if (TxtMsg2.compare(comp->TxtMsg2) == 0) insert(items, TXTMSG2);
	if (TxtMsg3.compare(comp->TxtMsg3) == 0) insert(items, TXTMSG3);
	if (TxtMsg4.compare(comp->TxtMsg4) == 0) insert(items, TXTMSG4);
	if (TxtMsg5.compare(comp->TxtMsg5) == 0) insert(items, TXTMSG5);
	if (TxtMsg6.compare(comp->TxtMsg6) == 0) insert(items, TXTMSG6);
	if (TxtMsg7.compare(comp->TxtMsg7) == 0) insert(items, TXTMSG7);
	if (TxtMsg8.compare(comp->TxtMsg8) == 0) insert(items, TXTMSG8);
	if (TxtMsg9.compare(comp->TxtMsg9) == 0) insert(items, TXTMSG9);
	if (TxtMsg10.compare(comp->TxtMsg10) == 0) insert(items, TXTMSG10);

	return(items);
};

/******************************************************************************
 class DpchFmnc
 ******************************************************************************/

DpchFmnc::DpchFmnc(
			const uint ixFmncVDpch
		) {
	this->ixFmncVDpch = ixFmncVDpch;
};

DpchFmnc::~DpchFmnc() {
};

/******************************************************************************
 class DpchInvFmnc
 ******************************************************************************/

DpchInvFmnc::DpchInvFmnc(
			const uint ixFmncVDpch
			, const ubigint oref
			, const ubigint jref
			, const set<uint>& mask
		) : DpchFmnc(ixFmncVDpch) {
	this->oref = oref;
	this->jref = jref;

	if (find(mask, ALL)) this->mask = {OREF, JREF};
	else this->mask = mask;
};

DpchInvFmnc::~DpchInvFmnc() {
};

bool DpchInvFmnc::all(
			const set<uint>& items
		) {
	if (!find(items, OREF)) return false;
	if (!find(items, JREF)) return false;

	return true;
};

void DpchInvFmnc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvFmnc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvFmnc::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetFmnc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(OREF)) writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetFmnc
 ******************************************************************************/

DpchRetFmnc::DpchRetFmnc(
			const uint ixFmncVDpch
			, const string& scrOref
			, const string& scrJref
			, const bool success
			, const set<uint>& mask
		) : DpchFmnc(ixFmncVDpch) {
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->success = success;

	if (find(mask, ALL)) this->mask = {SCROREF, SCRJREF, SUCCESS};
	else this->mask = mask;
};

DpchRetFmnc::~DpchRetFmnc() {
};

bool DpchRetFmnc::all(
			const set<uint>& items
		) {
	if (!find(items, OREF)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SUCCESS)) return false;

	return true;
};

void DpchRetFmnc::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetFmnc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
	};
};

void DpchRetFmnc::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetFmnc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCROREF)) writeString(wr, "scrOref", scrOref);
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(SUCCESS)) writeBool(wr, "success", success);
	xmlTextWriterEndElement(wr);
};


