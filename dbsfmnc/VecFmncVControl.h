/**
  * \file VecFmncVControl.h
  * vector VecFmncVControl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVCONTROL_H
#define VECFMNCVCONTROL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVControl
	*/
namespace VecFmncVControl {
	const uint PNLFMNCUSGLIST_TCOSRF = 1;
	const uint PNLFMNCUSGAACCESS_TCOCRD = 2;
	const uint PNLFMNCUSGAACCESS_TCOUAC = 3;
	const uint PNLFMNCUSGMNUSER_TCOMREF = 4;
	const uint PNLFMNCUSGMNUSER_TCOULV = 5;
	const uint PNLFMNCUSRLIST_TCOPRS = 6;
	const uint PNLFMNCUSRLIST_TCOSRF = 7;
	const uint PNLFMNCUSRLIST_TCOUSG = 8;
	const uint PNLFMNCUSRLIST_TCOSTE = 9;
	const uint PNLFMNCUSRLIST_TCOLCL = 10;
	const uint PNLFMNCUSRLIST_TCOULV = 11;
	const uint PNLFMNCUSRAACCESS_TCOCRD = 12;
	const uint PNLFMNCUSRAACCESS_TCOUAC = 13;
	const uint PNLFMNCUSR1NSESSION_TCOREF = 14;
	const uint PNLFMNCUSRMNUSERGROUP_TCOMREF = 15;
	const uint PNLFMNCUSRMNUSERGROUP_TCOULV = 16;
	const uint PNLFMNCORGLIST_TCOSRF = 17;
	const uint PNLFMNCORGLIST_TCOTIT = 18;
	const uint PNLFMNCORGLIST_TCODRV = 19;
	const uint PNLFMNCORGLIST_TCOADR = 20;
	const uint PNLFMNCORGLIST_TCOSUP = 21;
	const uint PNLFMNCORGLIST_TCOTEL = 22;
	const uint PNLFMNCORGLIST_TCOEML = 23;
	const uint PNLFMNCORGKSTOCKLCN_TCOFIX = 24;
	const uint PNLFMNCORGKSTOCKLCN_TCOSRF = 25;
	const uint PNLFMNCORGKSTOCKLCN_TCOAVL = 26;
	const uint PNLFMNCORGKSTOCKLCN_TCOIMP = 27;
	const uint PNLFMNCORGKSTOCKLCN_TCOTIT = 28;
	const uint PNLFMNCORGKSTOCKLCN_TCOCMT = 29;
	const uint PNLFMNCORGADETAIL_TCOTYP = 30;
	const uint PNLFMNCORGADETAIL_TCOVAL = 31;
	const uint PNLFMNCORGBIO1NFABPROJECT_TCOREF = 32;
	const uint PNLFMNCORGMNF1NTOOL_TCOREF = 33;
	const uint PNLFMNCORGMNF1NTOOL_TCOSPRS = 34;
	const uint PNLFMNCORG1NARTICLE_TCOREF = 35;
	const uint PNLFMNCORGPCO1NPURCHORDER_TCOREF = 36;
	const uint PNLFMNCORGSPL1NPURCHORDER_TCOREF = 37;
	const uint PNLFMNCORG1NSTOCKITEM_TCOREF = 38;
	const uint PNLFMNCORGSUP1NORG_TCOREF = 39;
	const uint PNLFMNCORGHK1NADDRESS_TCOREF = 40;
	const uint PNLFMNCORGMNPERSON_TCOMREF = 41;
	const uint PNLFMNCORGMNPERSON_TCOSTA = 42;
	const uint PNLFMNCORGMNPERSON_TCOSTO = 43;
	const uint PNLFMNCORGMNPERSON_TCOFCT = 44;
	const uint PNLFMNCORGSVCMNTOOL_TCOMREF = 45;
	const uint PNLFMNCORGSVCMNTOOL_TCOTPRS = 46;
	const uint PNLFMNCORGMNARTICLE_TCOMREF = 47;
	const uint PNLFMNCORGMNARTICLE_TCOITN = 48;
	const uint PNLFMNCPRSLIST_TCOTIT = 49;
	const uint PNLFMNCPRSLIST_TCOFNM = 50;
	const uint PNLFMNCPRSLIST_TCOLNM = 51;
	const uint PNLFMNCPRSLIST_TCOGRP = 52;
	const uint PNLFMNCPRSLIST_TCOOWN = 53;
	const uint PNLFMNCPRSLIST_TCOORG = 54;
	const uint PNLFMNCPRSLIST_TCOADR = 55;
	const uint PNLFMNCPRSLIST_TCOSEX = 56;
	const uint PNLFMNCPRSLIST_TCOTEL = 57;
	const uint PNLFMNCPRSLIST_TCOEML = 58;
	const uint PNLFMNCPRSADETAIL_TCOTYP = 59;
	const uint PNLFMNCPRSADETAIL_TCOVAL = 60;
	const uint PNLFMNCPRSHK1NADDRESS_TCOREF = 61;
	const uint PNLFMNCPRSMNRUN_TCOMREF = 62;
	const uint PNLFMNCPRSMNORG_TCOMREF = 63;
	const uint PNLFMNCPRSMNORG_TCOSTA = 64;
	const uint PNLFMNCPRSMNORG_TCOSTO = 65;
	const uint PNLFMNCPRSMNORG_TCOFCT = 66;
	const uint PNLFMNCADRLIST_TCOAD1 = 67;
	const uint PNLFMNCADRLIST_TCOCTY = 68;
	const uint PNLFMNCADRLIST_TCOHKT = 69;
	const uint PNLFMNCADRLIST_TCOHKU = 70;
	const uint PNLFMNCADRLIST_TCOATY = 71;
	const uint PNLFMNCADRLIST_TCOZIP = 72;
	const uint PNLFMNCADRLIST_TCOCRY = 73;
	const uint PNLFMNCFILLIST_TCOFNM = 74;
	const uint PNLFMNCFILLIST_TCORET = 75;
	const uint PNLFMNCFILLIST_TCOREU = 76;
	const uint PNLFMNCFILLIST_TCOCNT = 77;
	const uint PNLFMNCFILLIST_TCOMIM = 78;
	const uint PNLFMNCFILLIST_TCOSIZ = 79;
	const uint PNLFMNCFILMNSAMPLE_TCOMREF = 80;
	const uint PNLFMNCFILMNSTEP_TCOMREF = 81;
	const uint PNLFMNCFILMNSTEP_TCOTSMP = 82;
	const uint PNLFMNCFILMNSTEP_TCODIR = 83;
	const uint PNLFMNCSTPLIST_TCOTIT = 84;
	const uint PNLFMNCSTPLIST_TCOACT = 85;
	const uint PNLFMNCSTPLIST_TCORLT = 86;
	const uint PNLFMNCSTPLIST_TCORLU = 87;
	const uint PNLFMNCSTPLIST_TCOSTP = 88;
	const uint PNLFMNCSTPLIST_TCOSTA = 89;
	const uint PNLFMNCSTPKSTEPPAR_TCOFIX = 90;
	const uint PNLFMNCSTPKSTEPPAR_TCOSRF = 91;
	const uint PNLFMNCSTPKSTEPPAR_TCOAVL = 92;
	const uint PNLFMNCSTPKSTEPPAR_TCOIMP = 93;
	const uint PNLFMNCSTPKSTEPPAR_TCOTIT = 94;
	const uint PNLFMNCSTPKSTEPPAR_TCOCMT = 95;
	const uint PNLFMNCSTPAPAR_TCOSPA = 96;
	const uint PNLFMNCSTPAPAR_TCOREU = 97;
	const uint PNLFMNCSTPAPAR_TCOVAL = 98;
	const uint PNLFMNCSTPAPAR_TCOCMT = 99;
	const uint PNLFMNCSTPREF1NFILE_TCOREF = 100;
	const uint PNLFMNCSTPTPL1NSTEP_TCOREF = 101;
	const uint PNLFMNCSTPMNFILE_TCOMREF = 102;
	const uint PNLFMNCSTPMNFILE_TCOTSMP = 103;
	const uint PNLFMNCSTPMNFILE_TCODIR = 104;
	const uint PNLFMNCPRJLIST_TCOTIT = 105;
	const uint PNLFMNCPRJLIST_TCOSTE = 106;
	const uint PNLFMNCPRJ1NRUN_TCOREF = 107;
	const uint PNLFMNCRUNLIST_TCOTIT = 108;
	const uint PNLFMNCRUNLIST_TCOPRJ = 109;
	const uint PNLFMNCRUNLIST_TCOSTE = 110;
	const uint PNLFMNCRUNRUN1NACTIVITY_TCOREF = 111;
	const uint PNLFMNCRUNREF1NFILE_TCOREF = 112;
	const uint PNLFMNCRUNMNSAMPLE_TCOMREF = 113;
	const uint PNLFMNCRUNMNPERSON_TCOMREF = 114;
	const uint PNLFMNCRUNMNFAB_TCOMREF = 115;
	const uint PNLFMNCACTLIST_TCOTIT = 116;
	const uint PNLFMNCACTLIST_TCORUN = 117;
	const uint PNLFMNCACT1NSTEP_TCOREF = 118;
	const uint PNLFMNCSEPLIST_TCOTIT = 119;
	const uint PNLFMNCSEPLIST_TCOACT = 120;
	const uint PNLFMNCSEPLIST_TCORLT = 121;
	const uint PNLFMNCSEPLIST_TCORLU = 122;
	const uint PNLFMNCSEPLIST_TCOSTP = 123;
	const uint PNLFMNCSEPLIST_TCOSTA = 124;
	const uint PNLFMNCSEPAPAR_TCOSPA = 125;
	const uint PNLFMNCSEPAPAR_TCOREU = 126;
	const uint PNLFMNCSEPAPAR_TCOVAL = 127;
	const uint PNLFMNCSEPAPAR_TCOCMT = 128;
	const uint PNLFMNCSEPREF1NFILE_TCOREF = 129;
	const uint PNLFMNCSEPMNFILE_TCOMREF = 130;
	const uint PNLFMNCSEPMNFILE_TCOTSMP = 131;
	const uint PNLFMNCSEPMNFILE_TCODIR = 132;
	const uint PNLFMNCSEPMNSAMPLE_TCOMREF = 133;
	const uint PNLFMNCSMPLIST_TCOSRF = 134;
	const uint PNLFMNCSMPLIST_TCOSUP = 135;
	const uint PNLFMNCSMPLIST_TCOART = 136;
	const uint PNLFMNCSMPLIST_TCOMAT = 137;
	const uint PNLFMNCSMPLIST_TCOSTE = 138;
	const uint PNLFMNCSMPAPAR_TCOKEY = 139;
	const uint PNLFMNCSMPAPAR_TCOVAL = 140;
	const uint PNLFMNCSMPSUP1NSAMPLE_TCOREF = 141;
	const uint PNLFMNCSMPREF1NFILE_TCOREF = 142;
	const uint PNLFMNCSMPMNSTEP_TCOMREF = 143;
	const uint PNLFMNCSMPMNFILE_TCOMREF = 144;
	const uint PNLFMNCSMPMNRUN_TCOMREF = 145;
	const uint PNLFMNCFABLIST_TCOORG = 146;
	const uint PNLFMNCFAB1NFABPROJECT_TCOREF = 147;
	const uint PNLFMNCFAB1NFABUSER_TCOREF = 148;
	const uint PNLFMNCFABFAB1NTOOL_TCOREF = 149;
	const uint PNLFMNCFABFAB1NTOOL_TCOSPRS = 150;
	const uint PNLFMNCFABMNRUN_TCOMREF = 151;
	const uint PNLFMNCFUSLIST_TCOPRS = 152;
	const uint PNLFMNCFUSLIST_TCOSRF = 153;
	const uint PNLFMNCFUSLIST_TCOFAB = 154;
	const uint PNLFMNCFUSLIST_TCOFPJ = 155;
	const uint PNLFMNCFUSLIST_TCOSTE = 156;
	const uint PNLFMNCFUSMNTOOL_TCOMREF = 157;
	const uint PNLFMNCFUSMNTOOL_TCOTRN = 158;
	const uint PNLFMNCFUSMNTOOL_TCOLVL = 159;
	const uint PNLFMNCFUSMNFABPROJECT_TCOMREF = 160;
	const uint PNLFMNCTTYLIST_TCOSRF = 161;
	const uint PNLFMNCTTYLIST_TCOTIT = 162;
	const uint PNLFMNCTTYLIST_TCOSUP = 163;
	const uint PNLFMNCTTYKSTEPPAR_TCOFIX = 164;
	const uint PNLFMNCTTYKSTEPPAR_TCOSRF = 165;
	const uint PNLFMNCTTYKSTEPPAR_TCOAVL = 166;
	const uint PNLFMNCTTYKSTEPPAR_TCOIMP = 167;
	const uint PNLFMNCTTYKSTEPPAR_TCOTIT = 168;
	const uint PNLFMNCTTYKSTEPPAR_TCOCMT = 169;
	const uint PNLFMNCTTYKTOOLCHAR_TCOFIX = 170;
	const uint PNLFMNCTTYKTOOLCHAR_TCOSRF = 171;
	const uint PNLFMNCTTYKTOOLCHAR_TCOAVL = 172;
	const uint PNLFMNCTTYKTOOLCHAR_TCOIMP = 173;
	const uint PNLFMNCTTYKTOOLCHAR_TCOTIT = 174;
	const uint PNLFMNCTTYKTOOLCHAR_TCOCMT = 175;
	const uint PNLFMNCTTYSUP1NTOOLTYPE_TCOREF = 176;
	const uint PNLFMNCTTYRLV1NSTEP_TCOREF = 177;
	const uint PNLFMNCTTYMNTOOL_TCOMREF = 178;
	const uint PNLFMNCTTYMNTOOL_TCOTCH = 179;
	const uint PNLFMNCTTYMNTOOL_TCODEF = 180;
	const uint PNLFMNCTTYMNTOOL_TCOOPT = 181;
	const uint PNLFMNCTOLLIST_TCOTIT = 182;
	const uint PNLFMNCTOLLIST_TCOFAB = 183;
	const uint PNLFMNCTOLLIST_TCOMNF = 184;
	const uint PNLFMNCTOLLIST_TCOUPR = 185;
	const uint PNLFMNCTOLLIST_TCOTRN = 186;
	const uint PNLFMNCTOLKSTEPPAR_TCOFIX = 187;
	const uint PNLFMNCTOLKSTEPPAR_TCOSRF = 188;
	const uint PNLFMNCTOLKSTEPPAR_TCOAVL = 189;
	const uint PNLFMNCTOLKSTEPPAR_TCOIMP = 190;
	const uint PNLFMNCTOLKSTEPPAR_TCOTIT = 191;
	const uint PNLFMNCTOLKSTEPPAR_TCOCMT = 192;
	const uint PNLFMNCTOLKTOOLCHAR_TCOFIX = 193;
	const uint PNLFMNCTOLKTOOLCHAR_TCOSRF = 194;
	const uint PNLFMNCTOLKTOOLCHAR_TCOAVL = 195;
	const uint PNLFMNCTOLKTOOLCHAR_TCOIMP = 196;
	const uint PNLFMNCTOLKTOOLCHAR_TCOTIT = 197;
	const uint PNLFMNCTOLKTOOLCHAR_TCOCMT = 198;
	const uint PNLFMNCTOLAAVL_TCODAT = 199;
	const uint PNLFMNCTOLAAVL_TCOWDY = 200;
	const uint PNLFMNCTOLAAVL_TCOSTA = 201;
	const uint PNLFMNCTOLAAVL_TCOSTO = 202;
	const uint PNLFMNCTOLAAVL_TCOATY = 203;
	const uint PNLFMNCTOLACHAR_TCOTCH = 204;
	const uint PNLFMNCTOLACHAR_TCOVAL = 205;
	const uint PNLFMNCTOLACHAR_TCOCMT = 206;
	const uint PNLFMNCTOLARES_TCOFUS = 207;
	const uint PNLFMNCTOLARES_TCODAT = 208;
	const uint PNLFMNCTOLARES_TCOSTA = 209;
	const uint PNLFMNCTOLARES_TCOSTO = 210;
	const uint PNLFMNCTOLARES_TCORTY = 211;
	const uint PNLFMNCTOLARES_TCOCMT = 212;
	const uint PNLFMNCTOLAUTIL_TCOFPJ = 213;
	const uint PNLFMNCTOLAUTIL_TCOFUS = 214;
	const uint PNLFMNCTOLAUTIL_TCODAT = 215;
	const uint PNLFMNCTOLAUTIL_TCOSTA = 216;
	const uint PNLFMNCTOLAUTIL_TCOSTO = 217;
	const uint PNLFMNCTOLAUTIL_TCOUPR = 218;
	const uint PNLFMNCTOLAUTIL_TCOCMT = 219;
	const uint PNLFMNCTOL1NARTICLE_TCOREF = 220;
	const uint PNLFMNCTOLRLV1NSTEP_TCOREF = 221;
	const uint PNLFMNCTOLREF1NFILE_TCOREF = 222;
	const uint PNLFMNCTOLMNTOOLTYPE_TCOMREF = 223;
	const uint PNLFMNCTOLMNTOOLTYPE_TCOTCH = 224;
	const uint PNLFMNCTOLMNTOOLTYPE_TCODEF = 225;
	const uint PNLFMNCTOLMNTOOLTYPE_TCOOPT = 226;
	const uint PNLFMNCTOLMNFABUSER_TCOMREF = 227;
	const uint PNLFMNCTOLMNFABUSER_TCOTRN = 228;
	const uint PNLFMNCTOLMNFABUSER_TCOLVL = 229;
	const uint PNLFMNCTOLSVCMNORG_TCOMREF = 230;
	const uint PNLFMNCTOLSVCMNORG_TCOTPRS = 231;
	const uint PNLFMNCFPJLIST_TCOSRF = 232;
	const uint PNLFMNCFPJLIST_TCOTIT = 233;
	const uint PNLFMNCFPJLIST_TCOFAB = 234;
	const uint PNLFMNCFPJLIST_TCOBIO = 235;
	const uint PNLFMNCFPJLIST_TCOSTE = 236;
	const uint PNLFMNCFPJ1NBILL_TCOREF = 237;
	const uint PNLFMNCFPJMNFABUSER_TCOMREF = 238;
	const uint PNLFMNCBILLIST_TCOSRF = 239;
	const uint PNLFMNCBILLIST_TCODAT = 240;
	const uint PNLFMNCBILLIST_TCOPRJ = 241;
	const uint PNLFMNCBILLIST_TCOFIL = 242;
	const uint PNLFMNCBILLIST_TCOSTE = 243;
	const uint PNLFMNCBILLIST_TCOPRA = 244;
	const uint PNLFMNCBILLIST_TCOPRO = 245;
	const uint PNLFMNCBILLIST_TCOAMT = 246;
	const uint PNLFMNCBILAPOS_TCOFUS = 247;
	const uint PNLFMNCBILAPOS_TCOTOL = 248;
	const uint PNLFMNCBILAPOS_TCOQTY = 249;
	const uint PNLFMNCBILAPOS_TCOART = 250;
	const uint PNLFMNCBILAPOS_TCOUPR = 251;
	const uint PNLFMNCBILAPOS_TCOPRC = 252;
	const uint PNLFMNCARTLIST_TCOSRF = 253;
	const uint PNLFMNCARTLIST_TCOTIT = 254;
	const uint PNLFMNCARTLIST_TCOORG = 255;
	const uint PNLFMNCARTLIST_TCOTOL = 256;
	const uint PNLFMNCARTLIST_TCOTYP = 257;
	const uint PNLFMNCART1NSAMPLE_TCOREF = 258;
	const uint PNLFMNCART1NSTOCKITEM_TCOREF = 259;
	const uint PNLFMNCARTREF1NFILE_TCOREF = 260;
	const uint PNLFMNCARTMNORG_TCOMREF = 261;
	const uint PNLFMNCARTMNORG_TCOITN = 262;
	const uint PNLFMNCSKILIST_TCOORG = 263;
	const uint PNLFMNCSKILIST_TCOART = 264;
	const uint PNLFMNCSKILIST_TCOQTY = 265;
	const uint PNLFMNCSKILIST_TCOLCN = 266;
	const uint PNLFMNCSKILIST_TCOEXD = 267;
	const uint PNLFMNCPCOLIST_TCOSRF = 268;
	const uint PNLFMNCPCOLIST_TCODAT = 269;
	const uint PNLFMNCPCOLIST_TCOPCO = 270;
	const uint PNLFMNCPCOLIST_TCOSPL = 271;
	const uint PNLFMNCPCOLIST_TCOFIL = 272;
	const uint PNLFMNCPCOLIST_TCOSTE = 273;
	const uint PNLFMNCPCOLIST_TCOAMT = 274;
	const uint PNLFMNCPCOAPOS_TCOQTY = 275;
	const uint PNLFMNCPCOAPOS_TCOITN = 276;
	const uint PNLFMNCPCOAPOS_TCOART = 277;
	const uint PNLFMNCPCOAPOS_TCOUPR = 278;
	const uint PNLFMNCPCOAPOS_TCOPRC = 279;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

