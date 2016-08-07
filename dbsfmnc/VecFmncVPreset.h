/**
  * \file VecFmncVPreset.h
  * vector VecFmncVPreset (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVPRESET_H
#define VECFMNCVPRESET_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVPreset
	*/
namespace VecFmncVPreset {
	const uint VOID = 1;
	const uint PREFMNCACTLIST_RUN = 2;
	const uint PREFMNCADM = 3;
	const uint PREFMNCADRLIST_ATY = 4;
	const uint PREFMNCADRLIST_CRY = 5;
	const uint PREFMNCADRLIST_CTY = 6;
	const uint PREFMNCADRLIST_HKT = 7;
	const uint PREFMNCADRLIST_HKU = 8;
	const uint PREFMNCARTLIST_ORG = 9;
	const uint PREFMNCARTLIST_SRF = 10;
	const uint PREFMNCARTLIST_TOL = 11;
	const uint PREFMNCBILAPOS_X1 = 12;
	const uint PREFMNCBILAPOS_X2 = 13;
	const uint PREFMNCBILLIST_DAT = 14;
	const uint PREFMNCBILLIST_FIL = 15;
	const uint PREFMNCBILLIST_PRJ = 16;
	const uint PREFMNCBILLIST_SRF = 17;
	const uint PREFMNCBILLIST_STE = 18;
	const uint PREFMNCFABLIST_ORG = 19;
	const uint PREFMNCFILLIST_FNM = 20;
	const uint PREFMNCFILLIST_RET = 21;
	const uint PREFMNCFILLIST_REU = 22;
	const uint PREFMNCFPJLIST_BIO = 23;
	const uint PREFMNCFPJLIST_FAB = 24;
	const uint PREFMNCFPJLIST_SRF = 25;
	const uint PREFMNCFPJLIST_STE = 26;
	const uint PREFMNCFUSLIST_FAB = 27;
	const uint PREFMNCFUSLIST_FPJ = 28;
	const uint PREFMNCFUSLIST_PRS = 29;
	const uint PREFMNCFUSLIST_SRF = 30;
	const uint PREFMNCFUSLIST_STE = 31;
	const uint PREFMNCGRP = 32;
	const uint PREFMNCIP = 33;
	const uint PREFMNCIXACC = 34;
	const uint PREFMNCIXLCL = 35;
	const uint PREFMNCIXORD = 36;
	const uint PREFMNCIXPRE = 37;
	const uint PREFMNCIXUACACT = 38;
	const uint PREFMNCIXUACADR = 39;
	const uint PREFMNCIXUACART = 40;
	const uint PREFMNCIXUACBIL = 41;
	const uint PREFMNCIXUACFAB = 42;
	const uint PREFMNCIXUACFIL = 43;
	const uint PREFMNCIXUACFPJ = 44;
	const uint PREFMNCIXUACFUS = 45;
	const uint PREFMNCIXUACORG = 46;
	const uint PREFMNCIXUACPCO = 47;
	const uint PREFMNCIXUACPRJ = 48;
	const uint PREFMNCIXUACPRS = 49;
	const uint PREFMNCIXUACRUN = 50;
	const uint PREFMNCIXUACSEP = 51;
	const uint PREFMNCIXUACSKI = 52;
	const uint PREFMNCIXUACSMP = 53;
	const uint PREFMNCIXUACSTP = 54;
	const uint PREFMNCIXUACTOL = 55;
	const uint PREFMNCIXUACTTY = 56;
	const uint PREFMNCIXUACUSG = 57;
	const uint PREFMNCIXUACUSR = 58;
	const uint PREFMNCJREFNOTIFY = 59;
	const uint PREFMNCJREFSESS = 60;
	const uint PREFMNCORGADETAIL_X1 = 61;
	const uint PREFMNCORGLIST_ADR = 62;
	const uint PREFMNCORGLIST_DRV = 63;
	const uint PREFMNCORGLIST_SRF = 64;
	const uint PREFMNCORGLIST_SUP = 65;
	const uint PREFMNCORGLIST_TIT = 66;
	const uint PREFMNCORGMNPERSON_X1 = 67;
	const uint PREFMNCOWN = 68;
	const uint PREFMNCPCOLIST_DAT = 69;
	const uint PREFMNCPCOLIST_FIL = 70;
	const uint PREFMNCPCOLIST_PCO = 71;
	const uint PREFMNCPCOLIST_SPL = 72;
	const uint PREFMNCPCOLIST_SRF = 73;
	const uint PREFMNCPCOLIST_STE = 74;
	const uint PREFMNCPRJLIST_STE = 75;
	const uint PREFMNCPRJLIST_TIT = 76;
	const uint PREFMNCPRSADETAIL_X1 = 77;
	const uint PREFMNCPRSLIST_ADR = 78;
	const uint PREFMNCPRSLIST_GRP = 79;
	const uint PREFMNCPRSLIST_LNM = 80;
	const uint PREFMNCPRSLIST_ORG = 81;
	const uint PREFMNCPRSLIST_OWN = 82;
	const uint PREFMNCPRSMNORG_X1 = 83;
	const uint PREFMNCREFACT = 84;
	const uint PREFMNCREFADR = 85;
	const uint PREFMNCREFART = 86;
	const uint PREFMNCREFBIL = 87;
	const uint PREFMNCREFFAB = 88;
	const uint PREFMNCREFFIL = 89;
	const uint PREFMNCREFFPJ = 90;
	const uint PREFMNCREFFUS = 91;
	const uint PREFMNCREFORG = 92;
	const uint PREFMNCREFPCO = 93;
	const uint PREFMNCREFPRJ = 94;
	const uint PREFMNCREFPRS = 95;
	const uint PREFMNCREFRUN = 96;
	const uint PREFMNCREFSEL = 97;
	const uint PREFMNCREFSEP = 98;
	const uint PREFMNCREFSES = 99;
	const uint PREFMNCREFSKI = 100;
	const uint PREFMNCREFSMP = 101;
	const uint PREFMNCREFSTE = 102;
	const uint PREFMNCREFSTP = 103;
	const uint PREFMNCREFTOL = 104;
	const uint PREFMNCREFTTY = 105;
	const uint PREFMNCREFUSG = 106;
	const uint PREFMNCREFUSR = 107;
	const uint PREFMNCRUNLIST_PRJ = 108;
	const uint PREFMNCRUNLIST_STE = 109;
	const uint PREFMNCRUNLIST_TIT = 110;
	const uint PREFMNCSEPAPAR_X1 = 111;
	const uint PREFMNCSEPAPAR_X2 = 112;
	const uint PREFMNCSEPLIST_ACT = 113;
	const uint PREFMNCSEPLIST_RLT = 114;
	const uint PREFMNCSEPLIST_RLU = 115;
	const uint PREFMNCSEPLIST_STA = 116;
	const uint PREFMNCSEPLIST_STP = 117;
	const uint PREFMNCSESS = 118;
	const uint PREFMNCSKILIST_ART = 119;
	const uint PREFMNCSKILIST_ORG = 120;
	const uint PREFMNCSMPAPAR_X1 = 121;
	const uint PREFMNCSMPLIST_ART = 122;
	const uint PREFMNCSMPLIST_SRF = 123;
	const uint PREFMNCSMPLIST_STE = 124;
	const uint PREFMNCSMPLIST_SUP = 125;
	const uint PREFMNCSTPAPAR_X1 = 126;
	const uint PREFMNCSTPAPAR_X2 = 127;
	const uint PREFMNCSTPLIST_ACT = 128;
	const uint PREFMNCSTPLIST_RLT = 129;
	const uint PREFMNCSTPLIST_RLU = 130;
	const uint PREFMNCSTPLIST_STA = 131;
	const uint PREFMNCSTPLIST_STP = 132;
	const uint PREFMNCSYSDATE = 133;
	const uint PREFMNCSYSSTAMP = 134;
	const uint PREFMNCSYSTIME = 135;
	const uint PREFMNCTOLAAVL_X1 = 136;
	const uint PREFMNCTOLAAVL_X2 = 137;
	const uint PREFMNCTOLAAVL_X3 = 138;
	const uint PREFMNCTOLACHAR_X1 = 139;
	const uint PREFMNCTOLARES_X1 = 140;
	const uint PREFMNCTOLAUTIL_X1 = 141;
	const uint PREFMNCTOLAUTIL_X2 = 142;
	const uint PREFMNCTOLLIST_FAB = 143;
	const uint PREFMNCTOLLIST_MNF = 144;
	const uint PREFMNCTOLLIST_TIT = 145;
	const uint PREFMNCTTYLIST_SRF = 146;
	const uint PREFMNCTTYLIST_SUP = 147;
	const uint PREFMNCTTYLIST_TIT = 148;
	const uint PREFMNCUSGAACCESS_X1 = 149;
	const uint PREFMNCUSGLIST_SRF = 150;
	const uint PREFMNCUSRAACCESS_X1 = 151;
	const uint PREFMNCUSRLIST_PRS = 152;
	const uint PREFMNCUSRLIST_SRF = 153;
	const uint PREFMNCUSRLIST_STE = 154;
	const uint PREFMNCUSRLIST_USG = 155;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixFmncVLocale);
};

#endif

