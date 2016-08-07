/**
  * \file VecFmncVCall.cpp
  * vector VecFmncVCall (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVCall.h"

/******************************************************************************
 namespace VecFmncVCall
 ******************************************************************************/

uint VecFmncVCall::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "callfmncaccess") return CALLFMNCACCESS;
	else if (s == "callfmncactmod") return CALLFMNCACTMOD;
	else if (s == "callfmncactmod.runeq") return CALLFMNCACTMOD_RUNEQ;
	else if (s == "callfmncactupd.refeq") return CALLFMNCACTUPD_REFEQ;
	else if (s == "callfmncadrmod") return CALLFMNCADRMOD;
	else if (s == "callfmncadrmod.hkthkueq") return CALLFMNCADRMOD_HKTHKUEQ;
	else if (s == "callfmncadrupd.refeq") return CALLFMNCADRUPD_REFEQ;
	else if (s == "callfmncartmod") return CALLFMNCARTMOD;
	else if (s == "callfmncartmod.orgeq") return CALLFMNCARTMOD_ORGEQ;
	else if (s == "callfmncartmod.toleq") return CALLFMNCARTMOD_TOLEQ;
	else if (s == "callfmncartrorgmod.arteq") return CALLFMNCARTRORGMOD_ARTEQ;
	else if (s == "callfmncartrorgmod.orgeq") return CALLFMNCARTRORGMOD_ORGEQ;
	else if (s == "callfmncartupd.refeq") return CALLFMNCARTUPD_REFEQ;
	else if (s == "callfmncbilaposmod.bileq") return CALLFMNCBILAPOSMOD_BILEQ;
	else if (s == "callfmncbilaposmod.fuseq") return CALLFMNCBILAPOSMOD_FUSEQ;
	else if (s == "callfmncbilaposmod.toleq") return CALLFMNCBILAPOSMOD_TOLEQ;
	else if (s == "callfmncbiljstemod.bileq") return CALLFMNCBILJSTEMOD_BILEQ;
	else if (s == "callfmncbilmod") return CALLFMNCBILMOD;
	else if (s == "callfmncbilmod.prjeq") return CALLFMNCBILMOD_PRJEQ;
	else if (s == "callfmncbilupd.refeq") return CALLFMNCBILUPD_REFEQ;
	else if (s == "callfmncboolvalpreset") return CALLFMNCBOOLVALPRESET;
	else if (s == "callfmnccrdactive") return CALLFMNCCRDACTIVE;
	else if (s == "callfmnccrdclose") return CALLFMNCCRDCLOSE;
	else if (s == "callfmnccrdopen") return CALLFMNCCRDOPEN;
	else if (s == "callfmncctlaparmod.usreq") return CALLFMNCCTLAPARMOD_USREQ;
	else if (s == "callfmncdblvalpreset") return CALLFMNCDBLVALPRESET;
	else if (s == "callfmncdescr") return CALLFMNCDESCR;
	else if (s == "callfmncdlgclose") return CALLFMNCDLGCLOSE;
	else if (s == "callfmncfabmod") return CALLFMNCFABMOD;
	else if (s == "callfmncfabrrunmod.fabeq") return CALLFMNCFABRRUNMOD_FABEQ;
	else if (s == "callfmncfabrrunmod.runeq") return CALLFMNCFABRRUNMOD_RUNEQ;
	else if (s == "callfmncfabupd.refeq") return CALLFMNCFABUPD_REFEQ;
	else if (s == "callfmncfil.clueq") return CALLFMNCFIL_CLUEQ;
	else if (s == "callfmncfilmod") return CALLFMNCFILMOD;
	else if (s == "callfmncfilmod.clueq") return CALLFMNCFILMOD_CLUEQ;
	else if (s == "callfmncfilmod.retreueq") return CALLFMNCFILMOD_RETREUEQ;
	else if (s == "callfmncfilrsmpmod.fileq") return CALLFMNCFILRSMPMOD_FILEQ;
	else if (s == "callfmncfilrsmpmod.smpeq") return CALLFMNCFILRSMPMOD_SMPEQ;
	else if (s == "callfmncfilrstemod.fileq") return CALLFMNCFILRSTEMOD_FILEQ;
	else if (s == "callfmncfilrstemod.steeq") return CALLFMNCFILRSTEMOD_STEEQ;
	else if (s == "callfmncfilupd.refeq") return CALLFMNCFILUPD_REFEQ;
	else if (s == "callfmncfpjjstemod.fpjeq") return CALLFMNCFPJJSTEMOD_FPJEQ;
	else if (s == "callfmncfpjmod") return CALLFMNCFPJMOD;
	else if (s == "callfmncfpjmod.bioeq") return CALLFMNCFPJMOD_BIOEQ;
	else if (s == "callfmncfpjmod.fabeq") return CALLFMNCFPJMOD_FABEQ;
	else if (s == "callfmncfpjrfusmod.fpjeq") return CALLFMNCFPJRFUSMOD_FPJEQ;
	else if (s == "callfmncfpjrfusmod.fuseq") return CALLFMNCFPJRFUSMOD_FUSEQ;
	else if (s == "callfmncfpjupd.refeq") return CALLFMNCFPJUPD_REFEQ;
	else if (s == "callfmncfusjstemod.fuseq") return CALLFMNCFUSJSTEMOD_FUSEQ;
	else if (s == "callfmncfusmod") return CALLFMNCFUSMOD;
	else if (s == "callfmncfusmod.fabeq") return CALLFMNCFUSMOD_FABEQ;
	else if (s == "callfmncfusrtolmod.fuseq") return CALLFMNCFUSRTOLMOD_FUSEQ;
	else if (s == "callfmncfusrtolmod.toleq") return CALLFMNCFUSRTOLMOD_TOLEQ;
	else if (s == "callfmncfusupd.refeq") return CALLFMNCFUSUPD_REFEQ;
	else if (s == "callfmnchusrrunvmod.crdusreq") return CALLFMNCHUSRRUNVMOD_CRDUSREQ;
	else if (s == "callfmncintvalpreset") return CALLFMNCINTVALPRESET;
	else if (s == "callfmncixpreset") return CALLFMNCIXPRESET;
	else if (s == "callfmnckakjkeymod.klsakeyeq") return CALLFMNCKAKJKEYMOD_KLSAKEYEQ;
	else if (s == "callfmncklsakeymod.klseq") return CALLFMNCKLSAKEYMOD_KLSEQ;
	else if (s == "callfmncklsakeymod.klsmtburfeq") return CALLFMNCKLSAKEYMOD_KLSMTBURFEQ;
	else if (s == "callfmnclog") return CALLFMNCLOG;
	else if (s == "callfmnclogout") return CALLFMNCLOGOUT;
	else if (s == "callfmncmastclaim") return CALLFMNCMASTCLAIM;
	else if (s == "callfmncmastslvchg") return CALLFMNCMASTSLVCHG;
	else if (s == "callfmncorgadetmod.orgeq") return CALLFMNCORGADETMOD_ORGEQ;
	else if (s == "callfmncorgjtitmod.orgeq") return CALLFMNCORGJTITMOD_ORGEQ;
	else if (s == "callfmncorgmod") return CALLFMNCORGMOD;
	else if (s == "callfmncorgmod.supeq") return CALLFMNCORGMOD_SUPEQ;
	else if (s == "callfmncorgrprsmod.orgeq") return CALLFMNCORGRPRSMOD_ORGEQ;
	else if (s == "callfmncorgrprsmod.prseq") return CALLFMNCORGRPRSMOD_PRSEQ;
	else if (s == "callfmncorgupd.refeq") return CALLFMNCORGUPD_REFEQ;
	else if (s == "callfmncpcoaposmod.pcoeq") return CALLFMNCPCOAPOSMOD_PCOEQ;
	else if (s == "callfmncpcojstemod.pcoeq") return CALLFMNCPCOJSTEMOD_PCOEQ;
	else if (s == "callfmncpcomod") return CALLFMNCPCOMOD;
	else if (s == "callfmncpcomod.pcoeq") return CALLFMNCPCOMOD_PCOEQ;
	else if (s == "callfmncpcomod.spleq") return CALLFMNCPCOMOD_SPLEQ;
	else if (s == "callfmncpcoupd.refeq") return CALLFMNCPCOUPD_REFEQ;
	else if (s == "callfmncprjjstemod.prjeq") return CALLFMNCPRJJSTEMOD_PRJEQ;
	else if (s == "callfmncprjmod") return CALLFMNCPRJMOD;
	else if (s == "callfmncprjupd.refeq") return CALLFMNCPRJUPD_REFEQ;
	else if (s == "callfmncprsadetmod.prseq") return CALLFMNCPRSADETMOD_PRSEQ;
	else if (s == "callfmncprsjlnmmod.prseq") return CALLFMNCPRSJLNMMOD_PRSEQ;
	else if (s == "callfmncprsmod") return CALLFMNCPRSMOD;
	else if (s == "callfmncprsrrunmod.prseq") return CALLFMNCPRSRRUNMOD_PRSEQ;
	else if (s == "callfmncprsrrunmod.runeq") return CALLFMNCPRSRRUNMOD_RUNEQ;
	else if (s == "callfmncprsupd.refeq") return CALLFMNCPRSUPD_REFEQ;
	else if (s == "callfmncrefpreset") return CALLFMNCREFPRESET;
	else if (s == "callfmncrefspreset") return CALLFMNCREFSPRESET;
	else if (s == "callfmncrunjstemod.runeq") return CALLFMNCRUNJSTEMOD_RUNEQ;
	else if (s == "callfmncrunmod") return CALLFMNCRUNMOD;
	else if (s == "callfmncrunmod.prjeq") return CALLFMNCRUNMOD_PRJEQ;
	else if (s == "callfmncrunrsmpmod.runeq") return CALLFMNCRUNRSMPMOD_RUNEQ;
	else if (s == "callfmncrunrsmpmod.smpeq") return CALLFMNCRUNRSMPMOD_SMPEQ;
	else if (s == "callfmncrunupd.refeq") return CALLFMNCRUNUPD_REFEQ;
	else if (s == "callfmncscr") return CALLFMNCSCR;
	else if (s == "callfmncsesmod") return CALLFMNCSESMOD;
	else if (s == "callfmncsesmod.usreq") return CALLFMNCSESMOD_USREQ;
	else if (s == "callfmncsesupd.refeq") return CALLFMNCSESUPD_REFEQ;
	else if (s == "callfmncskijqtymod.skieq") return CALLFMNCSKIJQTYMOD_SKIEQ;
	else if (s == "callfmncskimod") return CALLFMNCSKIMOD;
	else if (s == "callfmncskimod.arteq") return CALLFMNCSKIMOD_ARTEQ;
	else if (s == "callfmncskimod.orgeq") return CALLFMNCSKIMOD_ORGEQ;
	else if (s == "callfmncskiupd.refeq") return CALLFMNCSKIUPD_REFEQ;
	else if (s == "callfmncsmpaparmod.smpeq") return CALLFMNCSMPAPARMOD_SMPEQ;
	else if (s == "callfmncsmpjstemod.smpeq") return CALLFMNCSMPJSTEMOD_SMPEQ;
	else if (s == "callfmncsmpmod") return CALLFMNCSMPMOD;
	else if (s == "callfmncsmpmod.arteq") return CALLFMNCSMPMOD_ARTEQ;
	else if (s == "callfmncsmpmod.supeq") return CALLFMNCSMPMOD_SUPEQ;
	else if (s == "callfmncsmprstemod.smpeq") return CALLFMNCSMPRSTEMOD_SMPEQ;
	else if (s == "callfmncsmprstemod.steeq") return CALLFMNCSMPRSTEMOD_STEEQ;
	else if (s == "callfmncsmpupd.refeq") return CALLFMNCSMPUPD_REFEQ;
	else if (s == "callfmncsorgrtolmod.orgeq") return CALLFMNCSORGRTOLMOD_ORGEQ;
	else if (s == "callfmncsorgrtolmod.toleq") return CALLFMNCSORGRTOLMOD_TOLEQ;
	else if (s == "callfmncsrefpreset") return CALLFMNCSREFPRESET;
	else if (s == "callfmncstatchg") return CALLFMNCSTATCHG;
	else if (s == "callfmncsteaparmod.retreueq") return CALLFMNCSTEAPARMOD_RETREUEQ;
	else if (s == "callfmncsteaparmod.steeq") return CALLFMNCSTEAPARMOD_STEEQ;
	else if (s == "callfmncstemod") return CALLFMNCSTEMOD;
	else if (s == "callfmncstemod.acteq") return CALLFMNCSTEMOD_ACTEQ;
	else if (s == "callfmncstemod.rltrlueq") return CALLFMNCSTEMOD_RLTRLUEQ;
	else if (s == "callfmncstemod.stpeq") return CALLFMNCSTEMOD_STPEQ;
	else if (s == "callfmncsteupd.refeq") return CALLFMNCSTEUPD_REFEQ;
	else if (s == "callfmncstgchg") return CALLFMNCSTGCHG;
	else if (s == "callfmncstubchg") return CALLFMNCSTUBCHG;
	else if (s == "callfmnctolaavlmod.toleq") return CALLFMNCTOLAAVLMOD_TOLEQ;
	else if (s == "callfmnctolachamod.toleq") return CALLFMNCTOLACHAMOD_TOLEQ;
	else if (s == "callfmnctolaresmod.fuseq") return CALLFMNCTOLARESMOD_FUSEQ;
	else if (s == "callfmnctolaresmod.toleq") return CALLFMNCTOLARESMOD_TOLEQ;
	else if (s == "callfmnctolautimod.fpjeq") return CALLFMNCTOLAUTIMOD_FPJEQ;
	else if (s == "callfmnctolautimod.fuseq") return CALLFMNCTOLAUTIMOD_FUSEQ;
	else if (s == "callfmnctolautimod.toleq") return CALLFMNCTOLAUTIMOD_TOLEQ;
	else if (s == "callfmnctoljuprmod.toleq") return CALLFMNCTOLJUPRMOD_TOLEQ;
	else if (s == "callfmnctolmod") return CALLFMNCTOLMOD;
	else if (s == "callfmnctolmod.fabeq") return CALLFMNCTOLMOD_FABEQ;
	else if (s == "callfmnctolmod.mnfeq") return CALLFMNCTOLMOD_MNFEQ;
	else if (s == "callfmnctolrttymod.toleq") return CALLFMNCTOLRTTYMOD_TOLEQ;
	else if (s == "callfmnctolrttymod.ttyeq") return CALLFMNCTOLRTTYMOD_TTYEQ;
	else if (s == "callfmnctolupd.refeq") return CALLFMNCTOLUPD_REFEQ;
	else if (s == "callfmncttymod") return CALLFMNCTTYMOD;
	else if (s == "callfmncttymod.supeq") return CALLFMNCTTYMOD_SUPEQ;
	else if (s == "callfmncttyupd.refeq") return CALLFMNCTTYUPD_REFEQ;
	else if (s == "callfmnctxtvalpreset") return CALLFMNCTXTVALPRESET;
	else if (s == "callfmncusgaaccmod.usgeq") return CALLFMNCUSGAACCMOD_USGEQ;
	else if (s == "callfmncusgmod") return CALLFMNCUSGMOD;
	else if (s == "callfmncusgupd.refeq") return CALLFMNCUSGUPD_REFEQ;
	else if (s == "callfmncusraaccmod.usreq") return CALLFMNCUSRAACCMOD_USREQ;
	else if (s == "callfmncusrjstemod.usreq") return CALLFMNCUSRJSTEMOD_USREQ;
	else if (s == "callfmncusrmod") return CALLFMNCUSRMOD;
	else if (s == "callfmncusrrusgmod.usgeq") return CALLFMNCUSRRUSGMOD_USGEQ;
	else if (s == "callfmncusrrusgmod.usreq") return CALLFMNCUSRRUSGMOD_USREQ;
	else if (s == "callfmncusrupd.refeq") return CALLFMNCUSRUPD_REFEQ;

	return(0);
};

string VecFmncVCall::getSref(
			const uint ix
		) {
	if (ix == CALLFMNCACCESS) return("CallFmncAccess");
	else if (ix == CALLFMNCACTMOD) return("CallFmncActMod");
	else if (ix == CALLFMNCACTMOD_RUNEQ) return("CallFmncActMod.runEq");
	else if (ix == CALLFMNCACTUPD_REFEQ) return("CallFmncActUpd.refEq");
	else if (ix == CALLFMNCADRMOD) return("CallFmncAdrMod");
	else if (ix == CALLFMNCADRMOD_HKTHKUEQ) return("CallFmncAdrMod.hktHkuEq");
	else if (ix == CALLFMNCADRUPD_REFEQ) return("CallFmncAdrUpd.refEq");
	else if (ix == CALLFMNCARTMOD) return("CallFmncArtMod");
	else if (ix == CALLFMNCARTMOD_ORGEQ) return("CallFmncArtMod.orgEq");
	else if (ix == CALLFMNCARTMOD_TOLEQ) return("CallFmncArtMod.tolEq");
	else if (ix == CALLFMNCARTRORGMOD_ARTEQ) return("CallFmncArtRorgMod.artEq");
	else if (ix == CALLFMNCARTRORGMOD_ORGEQ) return("CallFmncArtRorgMod.orgEq");
	else if (ix == CALLFMNCARTUPD_REFEQ) return("CallFmncArtUpd.refEq");
	else if (ix == CALLFMNCBILAPOSMOD_BILEQ) return("CallFmncBilAposMod.bilEq");
	else if (ix == CALLFMNCBILAPOSMOD_FUSEQ) return("CallFmncBilAposMod.fusEq");
	else if (ix == CALLFMNCBILAPOSMOD_TOLEQ) return("CallFmncBilAposMod.tolEq");
	else if (ix == CALLFMNCBILJSTEMOD_BILEQ) return("CallFmncBilJsteMod.bilEq");
	else if (ix == CALLFMNCBILMOD) return("CallFmncBilMod");
	else if (ix == CALLFMNCBILMOD_PRJEQ) return("CallFmncBilMod.prjEq");
	else if (ix == CALLFMNCBILUPD_REFEQ) return("CallFmncBilUpd.refEq");
	else if (ix == CALLFMNCBOOLVALPRESET) return("CallFmncBoolvalPreSet");
	else if (ix == CALLFMNCCRDACTIVE) return("CallFmncCrdActive");
	else if (ix == CALLFMNCCRDCLOSE) return("CallFmncCrdClose");
	else if (ix == CALLFMNCCRDOPEN) return("CallFmncCrdOpen");
	else if (ix == CALLFMNCCTLAPARMOD_USREQ) return("CallFmncCtlAparMod.usrEq");
	else if (ix == CALLFMNCDBLVALPRESET) return("CallFmncDblvalPreSet");
	else if (ix == CALLFMNCDESCR) return("CallFmncDescr");
	else if (ix == CALLFMNCDLGCLOSE) return("CallFmncDlgClose");
	else if (ix == CALLFMNCFABMOD) return("CallFmncFabMod");
	else if (ix == CALLFMNCFABRRUNMOD_FABEQ) return("CallFmncFabRrunMod.fabEq");
	else if (ix == CALLFMNCFABRRUNMOD_RUNEQ) return("CallFmncFabRrunMod.runEq");
	else if (ix == CALLFMNCFABUPD_REFEQ) return("CallFmncFabUpd.refEq");
	else if (ix == CALLFMNCFIL_CLUEQ) return("CallFmncFil.cluEq");
	else if (ix == CALLFMNCFILMOD) return("CallFmncFilMod");
	else if (ix == CALLFMNCFILMOD_CLUEQ) return("CallFmncFilMod.cluEq");
	else if (ix == CALLFMNCFILMOD_RETREUEQ) return("CallFmncFilMod.retReuEq");
	else if (ix == CALLFMNCFILRSMPMOD_FILEQ) return("CallFmncFilRsmpMod.filEq");
	else if (ix == CALLFMNCFILRSMPMOD_SMPEQ) return("CallFmncFilRsmpMod.smpEq");
	else if (ix == CALLFMNCFILRSTEMOD_FILEQ) return("CallFmncFilRsteMod.filEq");
	else if (ix == CALLFMNCFILRSTEMOD_STEEQ) return("CallFmncFilRsteMod.steEq");
	else if (ix == CALLFMNCFILUPD_REFEQ) return("CallFmncFilUpd.refEq");
	else if (ix == CALLFMNCFPJJSTEMOD_FPJEQ) return("CallFmncFpjJsteMod.fpjEq");
	else if (ix == CALLFMNCFPJMOD) return("CallFmncFpjMod");
	else if (ix == CALLFMNCFPJMOD_BIOEQ) return("CallFmncFpjMod.bioEq");
	else if (ix == CALLFMNCFPJMOD_FABEQ) return("CallFmncFpjMod.fabEq");
	else if (ix == CALLFMNCFPJRFUSMOD_FPJEQ) return("CallFmncFpjRfusMod.fpjEq");
	else if (ix == CALLFMNCFPJRFUSMOD_FUSEQ) return("CallFmncFpjRfusMod.fusEq");
	else if (ix == CALLFMNCFPJUPD_REFEQ) return("CallFmncFpjUpd.refEq");
	else if (ix == CALLFMNCFUSJSTEMOD_FUSEQ) return("CallFmncFusJsteMod.fusEq");
	else if (ix == CALLFMNCFUSMOD) return("CallFmncFusMod");
	else if (ix == CALLFMNCFUSMOD_FABEQ) return("CallFmncFusMod.fabEq");
	else if (ix == CALLFMNCFUSRTOLMOD_FUSEQ) return("CallFmncFusRtolMod.fusEq");
	else if (ix == CALLFMNCFUSRTOLMOD_TOLEQ) return("CallFmncFusRtolMod.tolEq");
	else if (ix == CALLFMNCFUSUPD_REFEQ) return("CallFmncFusUpd.refEq");
	else if (ix == CALLFMNCHUSRRUNVMOD_CRDUSREQ) return("CallFmncHusrRunvMod.crdUsrEq");
	else if (ix == CALLFMNCINTVALPRESET) return("CallFmncIntvalPreSet");
	else if (ix == CALLFMNCIXPRESET) return("CallFmncIxPreSet");
	else if (ix == CALLFMNCKAKJKEYMOD_KLSAKEYEQ) return("CallFmncKakJkeyMod.klsAkeyEq");
	else if (ix == CALLFMNCKLSAKEYMOD_KLSEQ) return("CallFmncKlsAkeyMod.klsEq");
	else if (ix == CALLFMNCKLSAKEYMOD_KLSMTBURFEQ) return("CallFmncKlsAkeyMod.klsMtbUrfEq");
	else if (ix == CALLFMNCLOG) return("CallFmncLog");
	else if (ix == CALLFMNCLOGOUT) return("CallFmncLogout");
	else if (ix == CALLFMNCMASTCLAIM) return("CallFmncMastClaim");
	else if (ix == CALLFMNCMASTSLVCHG) return("CallFmncMastslvChg");
	else if (ix == CALLFMNCORGADETMOD_ORGEQ) return("CallFmncOrgAdetMod.orgEq");
	else if (ix == CALLFMNCORGJTITMOD_ORGEQ) return("CallFmncOrgJtitMod.orgEq");
	else if (ix == CALLFMNCORGMOD) return("CallFmncOrgMod");
	else if (ix == CALLFMNCORGMOD_SUPEQ) return("CallFmncOrgMod.supEq");
	else if (ix == CALLFMNCORGRPRSMOD_ORGEQ) return("CallFmncOrgRprsMod.orgEq");
	else if (ix == CALLFMNCORGRPRSMOD_PRSEQ) return("CallFmncOrgRprsMod.prsEq");
	else if (ix == CALLFMNCORGUPD_REFEQ) return("CallFmncOrgUpd.refEq");
	else if (ix == CALLFMNCPCOAPOSMOD_PCOEQ) return("CallFmncPcoAposMod.pcoEq");
	else if (ix == CALLFMNCPCOJSTEMOD_PCOEQ) return("CallFmncPcoJsteMod.pcoEq");
	else if (ix == CALLFMNCPCOMOD) return("CallFmncPcoMod");
	else if (ix == CALLFMNCPCOMOD_PCOEQ) return("CallFmncPcoMod.pcoEq");
	else if (ix == CALLFMNCPCOMOD_SPLEQ) return("CallFmncPcoMod.splEq");
	else if (ix == CALLFMNCPCOUPD_REFEQ) return("CallFmncPcoUpd.refEq");
	else if (ix == CALLFMNCPRJJSTEMOD_PRJEQ) return("CallFmncPrjJsteMod.prjEq");
	else if (ix == CALLFMNCPRJMOD) return("CallFmncPrjMod");
	else if (ix == CALLFMNCPRJUPD_REFEQ) return("CallFmncPrjUpd.refEq");
	else if (ix == CALLFMNCPRSADETMOD_PRSEQ) return("CallFmncPrsAdetMod.prsEq");
	else if (ix == CALLFMNCPRSJLNMMOD_PRSEQ) return("CallFmncPrsJlnmMod.prsEq");
	else if (ix == CALLFMNCPRSMOD) return("CallFmncPrsMod");
	else if (ix == CALLFMNCPRSRRUNMOD_PRSEQ) return("CallFmncPrsRrunMod.prsEq");
	else if (ix == CALLFMNCPRSRRUNMOD_RUNEQ) return("CallFmncPrsRrunMod.runEq");
	else if (ix == CALLFMNCPRSUPD_REFEQ) return("CallFmncPrsUpd.refEq");
	else if (ix == CALLFMNCREFPRESET) return("CallFmncRefPreSet");
	else if (ix == CALLFMNCREFSPRESET) return("CallFmncRefsPreSet");
	else if (ix == CALLFMNCRUNJSTEMOD_RUNEQ) return("CallFmncRunJsteMod.runEq");
	else if (ix == CALLFMNCRUNMOD) return("CallFmncRunMod");
	else if (ix == CALLFMNCRUNMOD_PRJEQ) return("CallFmncRunMod.prjEq");
	else if (ix == CALLFMNCRUNRSMPMOD_RUNEQ) return("CallFmncRunRsmpMod.runEq");
	else if (ix == CALLFMNCRUNRSMPMOD_SMPEQ) return("CallFmncRunRsmpMod.smpEq");
	else if (ix == CALLFMNCRUNUPD_REFEQ) return("CallFmncRunUpd.refEq");
	else if (ix == CALLFMNCSCR) return("CallFmncScr");
	else if (ix == CALLFMNCSESMOD) return("CallFmncSesMod");
	else if (ix == CALLFMNCSESMOD_USREQ) return("CallFmncSesMod.usrEq");
	else if (ix == CALLFMNCSESUPD_REFEQ) return("CallFmncSesUpd.refEq");
	else if (ix == CALLFMNCSKIJQTYMOD_SKIEQ) return("CallFmncSkiJqtyMod.skiEq");
	else if (ix == CALLFMNCSKIMOD) return("CallFmncSkiMod");
	else if (ix == CALLFMNCSKIMOD_ARTEQ) return("CallFmncSkiMod.artEq");
	else if (ix == CALLFMNCSKIMOD_ORGEQ) return("CallFmncSkiMod.orgEq");
	else if (ix == CALLFMNCSKIUPD_REFEQ) return("CallFmncSkiUpd.refEq");
	else if (ix == CALLFMNCSMPAPARMOD_SMPEQ) return("CallFmncSmpAparMod.smpEq");
	else if (ix == CALLFMNCSMPJSTEMOD_SMPEQ) return("CallFmncSmpJsteMod.smpEq");
	else if (ix == CALLFMNCSMPMOD) return("CallFmncSmpMod");
	else if (ix == CALLFMNCSMPMOD_ARTEQ) return("CallFmncSmpMod.artEq");
	else if (ix == CALLFMNCSMPMOD_SUPEQ) return("CallFmncSmpMod.supEq");
	else if (ix == CALLFMNCSMPRSTEMOD_SMPEQ) return("CallFmncSmpRsteMod.smpEq");
	else if (ix == CALLFMNCSMPRSTEMOD_STEEQ) return("CallFmncSmpRsteMod.steEq");
	else if (ix == CALLFMNCSMPUPD_REFEQ) return("CallFmncSmpUpd.refEq");
	else if (ix == CALLFMNCSORGRTOLMOD_ORGEQ) return("CallFmncSorgRtolMod.orgEq");
	else if (ix == CALLFMNCSORGRTOLMOD_TOLEQ) return("CallFmncSorgRtolMod.tolEq");
	else if (ix == CALLFMNCSREFPRESET) return("CallFmncSrefPreSet");
	else if (ix == CALLFMNCSTATCHG) return("CallFmncStatChg");
	else if (ix == CALLFMNCSTEAPARMOD_RETREUEQ) return("CallFmncSteAparMod.retReuEq");
	else if (ix == CALLFMNCSTEAPARMOD_STEEQ) return("CallFmncSteAparMod.steEq");
	else if (ix == CALLFMNCSTEMOD) return("CallFmncSteMod");
	else if (ix == CALLFMNCSTEMOD_ACTEQ) return("CallFmncSteMod.actEq");
	else if (ix == CALLFMNCSTEMOD_RLTRLUEQ) return("CallFmncSteMod.rltRluEq");
	else if (ix == CALLFMNCSTEMOD_STPEQ) return("CallFmncSteMod.stpEq");
	else if (ix == CALLFMNCSTEUPD_REFEQ) return("CallFmncSteUpd.refEq");
	else if (ix == CALLFMNCSTGCHG) return("CallFmncStgChg");
	else if (ix == CALLFMNCSTUBCHG) return("CallFmncStubChg");
	else if (ix == CALLFMNCTOLAAVLMOD_TOLEQ) return("CallFmncTolAavlMod.tolEq");
	else if (ix == CALLFMNCTOLACHAMOD_TOLEQ) return("CallFmncTolAchaMod.tolEq");
	else if (ix == CALLFMNCTOLARESMOD_FUSEQ) return("CallFmncTolAresMod.fusEq");
	else if (ix == CALLFMNCTOLARESMOD_TOLEQ) return("CallFmncTolAresMod.tolEq");
	else if (ix == CALLFMNCTOLAUTIMOD_FPJEQ) return("CallFmncTolAutiMod.fpjEq");
	else if (ix == CALLFMNCTOLAUTIMOD_FUSEQ) return("CallFmncTolAutiMod.fusEq");
	else if (ix == CALLFMNCTOLAUTIMOD_TOLEQ) return("CallFmncTolAutiMod.tolEq");
	else if (ix == CALLFMNCTOLJUPRMOD_TOLEQ) return("CallFmncTolJuprMod.tolEq");
	else if (ix == CALLFMNCTOLMOD) return("CallFmncTolMod");
	else if (ix == CALLFMNCTOLMOD_FABEQ) return("CallFmncTolMod.fabEq");
	else if (ix == CALLFMNCTOLMOD_MNFEQ) return("CallFmncTolMod.mnfEq");
	else if (ix == CALLFMNCTOLRTTYMOD_TOLEQ) return("CallFmncTolRttyMod.tolEq");
	else if (ix == CALLFMNCTOLRTTYMOD_TTYEQ) return("CallFmncTolRttyMod.ttyEq");
	else if (ix == CALLFMNCTOLUPD_REFEQ) return("CallFmncTolUpd.refEq");
	else if (ix == CALLFMNCTTYMOD) return("CallFmncTtyMod");
	else if (ix == CALLFMNCTTYMOD_SUPEQ) return("CallFmncTtyMod.supEq");
	else if (ix == CALLFMNCTTYUPD_REFEQ) return("CallFmncTtyUpd.refEq");
	else if (ix == CALLFMNCTXTVALPRESET) return("CallFmncTxtvalPreSet");
	else if (ix == CALLFMNCUSGAACCMOD_USGEQ) return("CallFmncUsgAaccMod.usgEq");
	else if (ix == CALLFMNCUSGMOD) return("CallFmncUsgMod");
	else if (ix == CALLFMNCUSGUPD_REFEQ) return("CallFmncUsgUpd.refEq");
	else if (ix == CALLFMNCUSRAACCMOD_USREQ) return("CallFmncUsrAaccMod.usrEq");
	else if (ix == CALLFMNCUSRJSTEMOD_USREQ) return("CallFmncUsrJsteMod.usrEq");
	else if (ix == CALLFMNCUSRMOD) return("CallFmncUsrMod");
	else if (ix == CALLFMNCUSRRUSGMOD_USGEQ) return("CallFmncUsrRusgMod.usgEq");
	else if (ix == CALLFMNCUSRRUSGMOD_USREQ) return("CallFmncUsrRusgMod.usrEq");
	else if (ix == CALLFMNCUSRUPD_REFEQ) return("CallFmncUsrUpd.refEq");

	return("");
};


