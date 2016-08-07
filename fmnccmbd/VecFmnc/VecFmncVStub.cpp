/**
  * \file VecFmncVStub.cpp
  * vector VecFmncVStub (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVStub.h"

/******************************************************************************
 namespace VecFmncVStub
 ******************************************************************************/

uint VecFmncVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubfmncactstd") return STUBFMNCACTSTD;
	else if (s == "stubfmncadrstd") return STUBFMNCADRSTD;
	else if (s == "stubfmncartstd") return STUBFMNCARTSTD;
	else if (s == "stubfmncbilstd") return STUBFMNCBILSTD;
	else if (s == "stubfmncfabsref") return STUBFMNCFABSREF;
	else if (s == "stubfmncfabstd") return STUBFMNCFABSTD;
	else if (s == "stubfmncfpjstd") return STUBFMNCFPJSTD;
	else if (s == "stubfmncfusstd") return STUBFMNCFUSSTD;
	else if (s == "stubfmncfilstd") return STUBFMNCFILSTD;
	else if (s == "stubfmncorghsref") return STUBFMNCORGHSREF;
	else if (s == "stubfmncorgsref") return STUBFMNCORGSREF;
	else if (s == "stubfmncorgstd") return STUBFMNCORGSTD;
	else if (s == "stubfmncprsstd") return STUBFMNCPRSSTD;
	else if (s == "stubfmncprsworg") return STUBFMNCPRSWORG;
	else if (s == "stubfmncprjstd") return STUBFMNCPRJSTD;
	else if (s == "stubfmncpcostd") return STUBFMNCPCOSTD;
	else if (s == "stubfmncrunstd") return STUBFMNCRUNSTD;
	else if (s == "stubfmncsmphsref") return STUBFMNCSMPHSREF;
	else if (s == "stubfmncsmpstd") return STUBFMNCSMPSTD;
	else if (s == "stubfmncsepstd") return STUBFMNCSEPSTD;
	else if (s == "stubfmncstestd") return STUBFMNCSTESTD;
	else if (s == "stubfmncskistd") return STUBFMNCSKISTD;
	else if (s == "stubfmnctolstd") return STUBFMNCTOLSTD;
	else if (s == "stubfmncttystd") return STUBFMNCTTYSTD;
	else if (s == "stubfmncsesmenu") return STUBFMNCSESMENU;
	else if (s == "stubfmncsesstd") return STUBFMNCSESSTD;
	else if (s == "stubfmncown") return STUBFMNCOWN;
	else if (s == "stubfmncusrstd") return STUBFMNCUSRSTD;
	else if (s == "stubfmncgrp") return STUBFMNCGRP;
	else if (s == "stubfmncusgstd") return STUBFMNCUSGSTD;

	return(0);
};

string VecFmncVStub::getSref(
			const uint ix
		) {
	if (ix == STUBFMNCACTSTD) return("StubFmncActStd");
	else if (ix == STUBFMNCADRSTD) return("StubFmncAdrStd");
	else if (ix == STUBFMNCARTSTD) return("StubFmncArtStd");
	else if (ix == STUBFMNCBILSTD) return("StubFmncBilStd");
	else if (ix == STUBFMNCFABSREF) return("StubFmncFabSref");
	else if (ix == STUBFMNCFABSTD) return("StubFmncFabStd");
	else if (ix == STUBFMNCFPJSTD) return("StubFmncFpjStd");
	else if (ix == STUBFMNCFUSSTD) return("StubFmncFusStd");
	else if (ix == STUBFMNCFILSTD) return("StubFmncFilStd");
	else if (ix == STUBFMNCORGHSREF) return("StubFmncOrgHsref");
	else if (ix == STUBFMNCORGSREF) return("StubFmncOrgSref");
	else if (ix == STUBFMNCORGSTD) return("StubFmncOrgStd");
	else if (ix == STUBFMNCPRSSTD) return("StubFmncPrsStd");
	else if (ix == STUBFMNCPRSWORG) return("StubFmncPrsWorg");
	else if (ix == STUBFMNCPRJSTD) return("StubFmncPrjStd");
	else if (ix == STUBFMNCPCOSTD) return("StubFmncPcoStd");
	else if (ix == STUBFMNCRUNSTD) return("StubFmncRunStd");
	else if (ix == STUBFMNCSMPHSREF) return("StubFmncSmpHsref");
	else if (ix == STUBFMNCSMPSTD) return("StubFmncSmpStd");
	else if (ix == STUBFMNCSEPSTD) return("StubFmncSepStd");
	else if (ix == STUBFMNCSTESTD) return("StubFmncSteStd");
	else if (ix == STUBFMNCSKISTD) return("StubFmncSkiStd");
	else if (ix == STUBFMNCTOLSTD) return("StubFmncTolStd");
	else if (ix == STUBFMNCTTYSTD) return("StubFmncTtyStd");
	else if (ix == STUBFMNCSESMENU) return("StubFmncSesMenu");
	else if (ix == STUBFMNCSESSTD) return("StubFmncSesStd");
	else if (ix == STUBFMNCOWN) return("StubFmncOwn");
	else if (ix == STUBFMNCUSRSTD) return("StubFmncUsrStd");
	else if (ix == STUBFMNCGRP) return("StubFmncGrp");
	else if (ix == STUBFMNCUSGSTD) return("StubFmncUsgStd");

	return("");
};


