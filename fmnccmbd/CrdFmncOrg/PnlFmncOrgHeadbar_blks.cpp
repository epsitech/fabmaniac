/**
  * \file PnlFmncOrgHeadbar_blks.cpp
  * job handler for job PnlFmncOrgHeadbar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncOrgHeadbar::StgInf
 ******************************************************************************/

void PnlFmncOrgHeadbar::StgInf::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfFmncOrgHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfFmncOrgHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "176");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "118");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "176");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "118");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "218");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "91");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgHeadbar::Tag
 ******************************************************************************/

void PnlFmncOrgHeadbar::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncOrgHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncOrgHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "FabManiac");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Organization");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "FabManiac");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Organisation");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "FabManiac");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Organisme");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgHeadbar::DpchEngData
 ******************************************************************************/

PnlFmncOrgHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCORGHEADBARDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlFmncOrgHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgHeadbar::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlFmncOrgHeadbar::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncOrgHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(STGINF)) StgInf::writeXML(ixFmncVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


