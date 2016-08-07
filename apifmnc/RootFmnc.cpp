/**
  * \file RootFmnc.cpp
  * API code for job RootFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "RootFmnc.h"

/******************************************************************************
 class RootFmnc::DpchAppLogin
 ******************************************************************************/

RootFmnc::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& password
			, const string& username
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPROOTFMNCLOGIN, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, PASSWORD, USERNAME};
	else this->mask = mask;

	this->password = password;
	this->username = username;
};

string RootFmnc::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(USERNAME)) ss.push_back("username");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootFmnc::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootFmncLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(USERNAME)) writeString(wr, "username", username);
	xmlTextWriterEndElement(wr);
};

