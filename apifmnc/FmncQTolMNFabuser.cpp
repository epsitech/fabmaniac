/**
  * \file FmncQTolMNFabuser.cpp
  * API code for table TblFmncQTolMNFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolMNFabuser.h"

/******************************************************************************
 class FmncQTolMNFabuser
 ******************************************************************************/

FmncQTolMNFabuser::FmncQTolMNFabuser(
			const uint jnum
			, const string stubMref
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubTrnRefFmncMPerson = stubTrnRefFmncMPerson;
	this->srefKLvl = srefKLvl;
	this->titSrefKLvl = titSrefKLvl;
};

bool FmncQTolMNFabuser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolMNFabuser");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubTrnRefFmncMPerson", "trn", stubTrnRefFmncMPerson);
		extractStringUclc(docctx, basexpath, "srefKLvl", "lvl", srefKLvl);
		extractStringUclc(docctx, basexpath, "titSrefKLvl", "lvl2", titSrefKLvl);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolMNFabuser
 ******************************************************************************/

ListFmncQTolMNFabuser::ListFmncQTolMNFabuser() {
};

ListFmncQTolMNFabuser::ListFmncQTolMNFabuser(
			const ListFmncQTolMNFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolMNFabuser(*(src.nodes[i]));
};

ListFmncQTolMNFabuser& ListFmncQTolMNFabuser::operator=(
			const ListFmncQTolMNFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolMNFabuser(*(src.nodes[i]));

	return *this;
};

ListFmncQTolMNFabuser::~ListFmncQTolMNFabuser() {
	clear();
};

void ListFmncQTolMNFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolMNFabuser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolMNFabuser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolMNFabuser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolMNFabuser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolMNFabuser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolMNFabuser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

