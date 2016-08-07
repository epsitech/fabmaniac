/**
  * \file VecFmncVKeylist.cpp
  * vector VecFmncVKeylist (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVKeylist.h"

/******************************************************************************
 namespace VecFmncVKeylist
 ******************************************************************************/

uint VecFmncVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstfmncksteppar") return KLSTFMNCKSTEPPAR;
	else if (s == "klstfmnckstocklcn") return KLSTFMNCKSTOCKLCN;
	else if (s == "klstfmncktoolchar") return KLSTFMNCKTOOLCHAR;
	else if (s == "klstfmnckamorgdetailtype") return KLSTFMNCKAMORGDETAILTYPE;
	else if (s == "klstfmnckampersondetailtype") return KLSTFMNCKAMPERSONDETAILTYPE;
	else if (s == "klstfmnckamsampleparkey") return KLSTFMNCKAMSAMPLEPARKEY;
	else if (s == "klstfmnckamsampleparval") return KLSTFMNCKAMSAMPLEPARVAL;
	else if (s == "klstfmnckamtoolavlavltype") return KLSTFMNCKAMTOOLAVLAVLTYPE;
	else if (s == "klstfmnckamtoolresrestype") return KLSTFMNCKAMTOOLRESRESTYPE;
	else if (s == "klstfmnckmaddresscountry") return KLSTFMNCKMADDRESSCOUNTRY;
	else if (s == "klstfmnckmarticletype") return KLSTFMNCKMARTICLETYPE;
	else if (s == "klstfmnckmfilecontent") return KLSTFMNCKMFILECONTENT;
	else if (s == "klstfmnckmfilemimetype") return KLSTFMNCKMFILEMIMETYPE;
	else if (s == "klstfmnckrmfabusermtoollvl") return KLSTFMNCKRMFABUSERMTOOLLVL;
	else if (s == "klstfmnckrmorgmpersonfunction") return KLSTFMNCKRMORGMPERSONFUNCTION;
	else if (s == "klstkmaddressadrtype") return KLSTKMADDRESSADRTYPE;

	return(0);
};

string VecFmncVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTFMNCKSTEPPAR) return("KlstFmncKSteppar");
	else if (ix == KLSTFMNCKSTOCKLCN) return("KlstFmncKStocklcn");
	else if (ix == KLSTFMNCKTOOLCHAR) return("KlstFmncKToolchar");
	else if (ix == KLSTFMNCKAMORGDETAILTYPE) return("KlstFmncKAMOrgDetailType");
	else if (ix == KLSTFMNCKAMPERSONDETAILTYPE) return("KlstFmncKAMPersonDetailType");
	else if (ix == KLSTFMNCKAMSAMPLEPARKEY) return("KlstFmncKAMSampleParKey");
	else if (ix == KLSTFMNCKAMSAMPLEPARVAL) return("KlstFmncKAMSampleParVal");
	else if (ix == KLSTFMNCKAMTOOLAVLAVLTYPE) return("KlstFmncKAMToolAvlAvltype");
	else if (ix == KLSTFMNCKAMTOOLRESRESTYPE) return("KlstFmncKAMToolResRestype");
	else if (ix == KLSTFMNCKMADDRESSCOUNTRY) return("KlstFmncKMAddressCountry");
	else if (ix == KLSTFMNCKMARTICLETYPE) return("KlstFmncKMArticleType");
	else if (ix == KLSTFMNCKMFILECONTENT) return("KlstFmncKMFileContent");
	else if (ix == KLSTFMNCKMFILEMIMETYPE) return("KlstFmncKMFileMimetype");
	else if (ix == KLSTFMNCKRMFABUSERMTOOLLVL) return("KlstFmncKRMFabuserMToolLvl");
	else if (ix == KLSTFMNCKRMORGMPERSONFUNCTION) return("KlstFmncKRMOrgMPersonFunction");
	else if (ix == KLSTKMADDRESSADRTYPE) return("KlstKMAddressAdrtype");

	return("");
};

string VecFmncVKeylist::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == KLSTFMNCKSTEPPAR) return("parameter");
		else if (ix == KLSTFMNCKSTOCKLCN) return("location");
		else if (ix == KLSTFMNCKTOOLCHAR) return("characteristic");
		else if (ix == KLSTFMNCKAMORGDETAILTYPE) return("type");
		else if (ix == KLSTFMNCKAMPERSONDETAILTYPE) return("type");
		else if (ix == KLSTFMNCKAMSAMPLEPARKEY) return("key");
		else if (ix == KLSTFMNCKAMSAMPLEPARVAL) return("value");
		else if (ix == KLSTFMNCKAMTOOLAVLAVLTYPE) return("type");
		else if (ix == KLSTFMNCKAMTOOLRESRESTYPE) return("type");
		else if (ix == KLSTFMNCKMADDRESSCOUNTRY) return("country");
		else if (ix == KLSTFMNCKMARTICLETYPE) return("type");
		else if (ix == KLSTFMNCKMFILECONTENT) return("content");
		else if (ix == KLSTFMNCKMFILEMIMETYPE) return("MIME type");
		else if (ix == KLSTFMNCKRMFABUSERMTOOLLVL) return("level");
		else if (ix == KLSTFMNCKRMORGMPERSONFUNCTION) return("function");
		else if (ix == KLSTKMADDRESSADRTYPE) return("address type");
	} else if (ixFmncVLocale == 2) {
		if (ix == KLSTFMNCKSTEPPAR) return("Parameter");
		else if (ix == KLSTFMNCKSTOCKLCN) return("Ort");
		else if (ix == KLSTFMNCKTOOLCHAR) return("Eigenschaft");
		else if (ix == KLSTFMNCKAMORGDETAILTYPE) return("Typ");
		else if (ix == KLSTFMNCKAMPERSONDETAILTYPE) return("Typ");
		else if (ix == KLSTFMNCKAMSAMPLEPARKEY) return("Schl\\u00fcssel");
		else if (ix == KLSTFMNCKAMSAMPLEPARVAL) return("Wert");
		else if (ix == KLSTFMNCKAMTOOLAVLAVLTYPE) return("Typ");
		else if (ix == KLSTFMNCKAMTOOLRESRESTYPE) return("Typ");
		else if (ix == KLSTFMNCKMADDRESSCOUNTRY) return("Land");
		else if (ix == KLSTFMNCKMARTICLETYPE) return("Typ");
		else if (ix == KLSTFMNCKMFILECONTENT) return("Inhalt");
		else if (ix == KLSTFMNCKMFILEMIMETYPE) return("MIME-Typ");
		else if (ix == KLSTFMNCKRMFABUSERMTOOLLVL) return("Niveau");
		else if (ix == KLSTFMNCKRMORGMPERSONFUNCTION) return("Funktion");
		else if (ix == KLSTKMADDRESSADRTYPE) return("Adresstyp");
	} else if (ixFmncVLocale == 3) {
		if (ix == KLSTFMNCKSTEPPAR) return("param\\u00e8tre");
		else if (ix == KLSTFMNCKSTOCKLCN) return("endroit");
		else if (ix == KLSTFMNCKTOOLCHAR) return("caract\\u00e9ristique");
		else if (ix == KLSTFMNCKAMORGDETAILTYPE) return("type");
		else if (ix == KLSTFMNCKAMPERSONDETAILTYPE) return("type");
		else if (ix == KLSTFMNCKAMSAMPLEPARKEY) return("cl\\u00e9");
		else if (ix == KLSTFMNCKAMSAMPLEPARVAL) return("valeur");
		else if (ix == KLSTFMNCKAMTOOLAVLAVLTYPE) return("type");
		else if (ix == KLSTFMNCKAMTOOLRESRESTYPE) return("type");
		else if (ix == KLSTFMNCKMADDRESSCOUNTRY) return("pays");
		else if (ix == KLSTFMNCKMARTICLETYPE) return("type");
		else if (ix == KLSTFMNCKMFILECONTENT) return("contenu");
		else if (ix == KLSTFMNCKMFILEMIMETYPE) return("type MIME");
		else if (ix == KLSTFMNCKRMFABUSERMTOOLLVL) return("niveau");
		else if (ix == KLSTFMNCKRMORGMPERSONFUNCTION) return("fonction");
		else if (ix == KLSTKMADDRESSADRTYPE) return("type d'addresse");
	};

	return("");
};

