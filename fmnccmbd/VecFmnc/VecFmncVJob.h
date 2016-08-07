/**
  * \file VecFmncVJob.h
  * vector VecFmncVJob (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVJOB_H
#define VECFMNCVJOB_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVJob
	*/
namespace VecFmncVJob {
	const uint CRDFMNCACT = 1;
	const uint CRDFMNCADR = 2;
	const uint CRDFMNCART = 3;
	const uint CRDFMNCBIL = 4;
	const uint CRDFMNCFAB = 5;
	const uint CRDFMNCFIL = 6;
	const uint CRDFMNCFPJ = 7;
	const uint CRDFMNCFUS = 8;
	const uint CRDFMNCNAV = 9;
	const uint CRDFMNCORG = 10;
	const uint CRDFMNCPCO = 11;
	const uint CRDFMNCPRJ = 12;
	const uint CRDFMNCPRS = 13;
	const uint CRDFMNCRUN = 14;
	const uint CRDFMNCSEP = 15;
	const uint CRDFMNCSKI = 16;
	const uint CRDFMNCSMP = 17;
	const uint CRDFMNCSTP = 18;
	const uint CRDFMNCTOL = 19;
	const uint CRDFMNCTTY = 20;
	const uint CRDFMNCUSG = 21;
	const uint CRDFMNCUSR = 22;
	const uint DLGFMNCACTNEW = 23;
	const uint DLGFMNCFABEXPFAB = 24;
	const uint DLGFMNCFABIMPFAB = 25;
	const uint DLGFMNCFABNEW = 26;
	const uint DLGFMNCNAVLOAINI = 27;
	const uint DLGFMNCORGEXPORG = 28;
	const uint DLGFMNCORGIMPORG = 29;
	const uint DLGFMNCORGNEW = 30;
	const uint DLGFMNCPRJEXPELB = 31;
	const uint DLGFMNCPRJIMPELB = 32;
	const uint DLGFMNCPRJNEW = 33;
	const uint DLGFMNCRUNGENREP = 34;
	const uint DLGFMNCRUNNEW = 35;
	const uint DLGFMNCSMPGENREP = 36;
	const uint DLGFMNCSMPNEW = 37;
	const uint IEXFMNCELB = 38;
	const uint IEXFMNCFAB = 39;
	const uint IEXFMNCINI = 40;
	const uint IEXFMNCORG = 41;
	const uint PNLFMNCACT1NSTEP = 42;
	const uint PNLFMNCACTDETAIL = 43;
	const uint PNLFMNCACTHEADBAR = 44;
	const uint PNLFMNCACTLIST = 45;
	const uint PNLFMNCACTREC = 46;
	const uint PNLFMNCADRDETAIL = 47;
	const uint PNLFMNCADRHEADBAR = 48;
	const uint PNLFMNCADRLIST = 49;
	const uint PNLFMNCADRREC = 50;
	const uint PNLFMNCART1NSAMPLE = 51;
	const uint PNLFMNCART1NSTOCKITEM = 52;
	const uint PNLFMNCARTDETAIL = 53;
	const uint PNLFMNCARTHEADBAR = 54;
	const uint PNLFMNCARTLIST = 55;
	const uint PNLFMNCARTMNORG = 56;
	const uint PNLFMNCARTREC = 57;
	const uint PNLFMNCARTREF1NFILE = 58;
	const uint PNLFMNCBILAPOS = 59;
	const uint PNLFMNCBILDETAIL = 60;
	const uint PNLFMNCBILHEADBAR = 61;
	const uint PNLFMNCBILLIST = 62;
	const uint PNLFMNCBILREC = 63;
	const uint PNLFMNCFAB1NFABPROJECT = 64;
	const uint PNLFMNCFAB1NFABUSER = 65;
	const uint PNLFMNCFABDETAIL = 66;
	const uint PNLFMNCFABFAB1NTOOL = 67;
	const uint PNLFMNCFABHEADBAR = 68;
	const uint PNLFMNCFABLIST = 69;
	const uint PNLFMNCFABMNRUN = 70;
	const uint PNLFMNCFABREC = 71;
	const uint PNLFMNCFILDETAIL = 72;
	const uint PNLFMNCFILHEADBAR = 73;
	const uint PNLFMNCFILLIST = 74;
	const uint PNLFMNCFILMNSAMPLE = 75;
	const uint PNLFMNCFILMNSTEP = 76;
	const uint PNLFMNCFILREC = 77;
	const uint PNLFMNCFPJ1NBILL = 78;
	const uint PNLFMNCFPJDETAIL = 79;
	const uint PNLFMNCFPJHEADBAR = 80;
	const uint PNLFMNCFPJLIST = 81;
	const uint PNLFMNCFPJMNFABUSER = 82;
	const uint PNLFMNCFPJREC = 83;
	const uint PNLFMNCFUSDETAIL = 84;
	const uint PNLFMNCFUSHEADBAR = 85;
	const uint PNLFMNCFUSLIST = 86;
	const uint PNLFMNCFUSMNFABPROJECT = 87;
	const uint PNLFMNCFUSMNTOOL = 88;
	const uint PNLFMNCFUSREC = 89;
	const uint PNLFMNCNAVADMIN = 90;
	const uint PNLFMNCNAVFABMGMT = 91;
	const uint PNLFMNCNAVHEADBAR = 92;
	const uint PNLFMNCNAVLABBOOK = 93;
	const uint PNLFMNCNAVPRE = 94;
	const uint PNLFMNCNAVSUPPLY = 95;
	const uint PNLFMNCORG1NARTICLE = 96;
	const uint PNLFMNCORG1NSTOCKITEM = 97;
	const uint PNLFMNCORGADETAIL = 98;
	const uint PNLFMNCORGBIO1NFABPROJECT = 99;
	const uint PNLFMNCORGDETAIL = 100;
	const uint PNLFMNCORGHEADBAR = 101;
	const uint PNLFMNCORGHK1NADDRESS = 102;
	const uint PNLFMNCORGKSTOCKLCN = 103;
	const uint PNLFMNCORGLIST = 104;
	const uint PNLFMNCORGMNARTICLE = 105;
	const uint PNLFMNCORGMNF1NTOOL = 106;
	const uint PNLFMNCORGMNPERSON = 107;
	const uint PNLFMNCORGPCO1NPURCHORDER = 108;
	const uint PNLFMNCORGREC = 109;
	const uint PNLFMNCORGSPL1NPURCHORDER = 110;
	const uint PNLFMNCORGSUP1NORG = 111;
	const uint PNLFMNCORGSVCMNTOOL = 112;
	const uint PNLFMNCPCOAPOS = 113;
	const uint PNLFMNCPCODETAIL = 114;
	const uint PNLFMNCPCOHEADBAR = 115;
	const uint PNLFMNCPCOLIST = 116;
	const uint PNLFMNCPCOREC = 117;
	const uint PNLFMNCPRJ1NRUN = 118;
	const uint PNLFMNCPRJDETAIL = 119;
	const uint PNLFMNCPRJHEADBAR = 120;
	const uint PNLFMNCPRJLIST = 121;
	const uint PNLFMNCPRJREC = 122;
	const uint PNLFMNCPRSADETAIL = 123;
	const uint PNLFMNCPRSDETAIL = 124;
	const uint PNLFMNCPRSHEADBAR = 125;
	const uint PNLFMNCPRSHK1NADDRESS = 126;
	const uint PNLFMNCPRSLIST = 127;
	const uint PNLFMNCPRSMNORG = 128;
	const uint PNLFMNCPRSMNRUN = 129;
	const uint PNLFMNCPRSREC = 130;
	const uint PNLFMNCRUNDETAIL = 131;
	const uint PNLFMNCRUNHEADBAR = 132;
	const uint PNLFMNCRUNLIST = 133;
	const uint PNLFMNCRUNMNFAB = 134;
	const uint PNLFMNCRUNMNPERSON = 135;
	const uint PNLFMNCRUNMNSAMPLE = 136;
	const uint PNLFMNCRUNREC = 137;
	const uint PNLFMNCRUNREF1NFILE = 138;
	const uint PNLFMNCRUNRUN1NACTIVITY = 139;
	const uint PNLFMNCSEPAPAR = 140;
	const uint PNLFMNCSEPDETAIL = 141;
	const uint PNLFMNCSEPHEADBAR = 142;
	const uint PNLFMNCSEPLIST = 143;
	const uint PNLFMNCSEPMNFILE = 144;
	const uint PNLFMNCSEPMNSAMPLE = 145;
	const uint PNLFMNCSEPREC = 146;
	const uint PNLFMNCSEPREF1NFILE = 147;
	const uint PNLFMNCSKIDETAIL = 148;
	const uint PNLFMNCSKIHEADBAR = 149;
	const uint PNLFMNCSKILIST = 150;
	const uint PNLFMNCSKIREC = 151;
	const uint PNLFMNCSMPAPAR = 152;
	const uint PNLFMNCSMPDETAIL = 153;
	const uint PNLFMNCSMPHEADBAR = 154;
	const uint PNLFMNCSMPLIST = 155;
	const uint PNLFMNCSMPMNFILE = 156;
	const uint PNLFMNCSMPMNRUN = 157;
	const uint PNLFMNCSMPMNSTEP = 158;
	const uint PNLFMNCSMPREC = 159;
	const uint PNLFMNCSMPREF1NFILE = 160;
	const uint PNLFMNCSMPSUP1NSAMPLE = 161;
	const uint PNLFMNCSTPAPAR = 162;
	const uint PNLFMNCSTPDETAIL = 163;
	const uint PNLFMNCSTPHEADBAR = 164;
	const uint PNLFMNCSTPKSTEPPAR = 165;
	const uint PNLFMNCSTPLIST = 166;
	const uint PNLFMNCSTPMNFILE = 167;
	const uint PNLFMNCSTPREC = 168;
	const uint PNLFMNCSTPREF1NFILE = 169;
	const uint PNLFMNCSTPTPL1NSTEP = 170;
	const uint PNLFMNCTOL1NARTICLE = 171;
	const uint PNLFMNCTOLAAVL = 172;
	const uint PNLFMNCTOLACHAR = 173;
	const uint PNLFMNCTOLARES = 174;
	const uint PNLFMNCTOLAUTIL = 175;
	const uint PNLFMNCTOLDETAIL = 176;
	const uint PNLFMNCTOLHEADBAR = 177;
	const uint PNLFMNCTOLKSTEPPAR = 178;
	const uint PNLFMNCTOLKTOOLCHAR = 179;
	const uint PNLFMNCTOLLIST = 180;
	const uint PNLFMNCTOLMNFABUSER = 181;
	const uint PNLFMNCTOLMNTOOLTYPE = 182;
	const uint PNLFMNCTOLREC = 183;
	const uint PNLFMNCTOLREF1NFILE = 184;
	const uint PNLFMNCTOLRLV1NSTEP = 185;
	const uint PNLFMNCTOLSVCMNORG = 186;
	const uint PNLFMNCTTYDETAIL = 187;
	const uint PNLFMNCTTYHEADBAR = 188;
	const uint PNLFMNCTTYKSTEPPAR = 189;
	const uint PNLFMNCTTYKTOOLCHAR = 190;
	const uint PNLFMNCTTYLIST = 191;
	const uint PNLFMNCTTYMNTOOL = 192;
	const uint PNLFMNCTTYREC = 193;
	const uint PNLFMNCTTYRLV1NSTEP = 194;
	const uint PNLFMNCTTYSUP1NTOOLTYPE = 195;
	const uint PNLFMNCUSGAACCESS = 196;
	const uint PNLFMNCUSGDETAIL = 197;
	const uint PNLFMNCUSGHEADBAR = 198;
	const uint PNLFMNCUSGLIST = 199;
	const uint PNLFMNCUSGMNUSER = 200;
	const uint PNLFMNCUSGREC = 201;
	const uint PNLFMNCUSR1NSESSION = 202;
	const uint PNLFMNCUSRAACCESS = 203;
	const uint PNLFMNCUSRDETAIL = 204;
	const uint PNLFMNCUSRHEADBAR = 205;
	const uint PNLFMNCUSRLIST = 206;
	const uint PNLFMNCUSRMNUSERGROUP = 207;
	const uint PNLFMNCUSRREC = 208;
	const uint QRYFMNCACT1NSTEP = 209;
	const uint QRYFMNCACTLIST = 210;
	const uint QRYFMNCADRLIST = 211;
	const uint QRYFMNCART1NSAMPLE = 212;
	const uint QRYFMNCART1NSTOCKITEM = 213;
	const uint QRYFMNCARTLIST = 214;
	const uint QRYFMNCARTMNORG = 215;
	const uint QRYFMNCARTREF1NFILE = 216;
	const uint QRYFMNCBILAPOS = 217;
	const uint QRYFMNCBILLIST = 218;
	const uint QRYFMNCFAB1NFABPROJECT = 219;
	const uint QRYFMNCFAB1NFABUSER = 220;
	const uint QRYFMNCFABFAB1NTOOL = 221;
	const uint QRYFMNCFABLIST = 222;
	const uint QRYFMNCFABMNRUN = 223;
	const uint QRYFMNCFILLIST = 224;
	const uint QRYFMNCFILMNSAMPLE = 225;
	const uint QRYFMNCFILMNSTEP = 226;
	const uint QRYFMNCFPJ1NBILL = 227;
	const uint QRYFMNCFPJLIST = 228;
	const uint QRYFMNCFPJMNFABUSER = 229;
	const uint QRYFMNCFUSLIST = 230;
	const uint QRYFMNCFUSMNFABPROJECT = 231;
	const uint QRYFMNCFUSMNTOOL = 232;
	const uint QRYFMNCORG1NARTICLE = 233;
	const uint QRYFMNCORG1NSTOCKITEM = 234;
	const uint QRYFMNCORGADETAIL = 235;
	const uint QRYFMNCORGBIO1NFABPROJECT = 236;
	const uint QRYFMNCORGHK1NADDRESS = 237;
	const uint QRYFMNCORGKSTOCKLCN = 238;
	const uint QRYFMNCORGLIST = 239;
	const uint QRYFMNCORGMNARTICLE = 240;
	const uint QRYFMNCORGMNF1NTOOL = 241;
	const uint QRYFMNCORGMNPERSON = 242;
	const uint QRYFMNCORGPCO1NPURCHORDER = 243;
	const uint QRYFMNCORGSPL1NPURCHORDER = 244;
	const uint QRYFMNCORGSUP1NORG = 245;
	const uint QRYFMNCORGSVCMNTOOL = 246;
	const uint QRYFMNCPCOAPOS = 247;
	const uint QRYFMNCPCOLIST = 248;
	const uint QRYFMNCPRJ1NRUN = 249;
	const uint QRYFMNCPRJLIST = 250;
	const uint QRYFMNCPRSADETAIL = 251;
	const uint QRYFMNCPRSHK1NADDRESS = 252;
	const uint QRYFMNCPRSLIST = 253;
	const uint QRYFMNCPRSMNORG = 254;
	const uint QRYFMNCPRSMNRUN = 255;
	const uint QRYFMNCRUNLIST = 256;
	const uint QRYFMNCRUNMNFAB = 257;
	const uint QRYFMNCRUNMNPERSON = 258;
	const uint QRYFMNCRUNMNSAMPLE = 259;
	const uint QRYFMNCRUNREF1NFILE = 260;
	const uint QRYFMNCRUNRUN1NACTIVITY = 261;
	const uint QRYFMNCSEPAPAR = 262;
	const uint QRYFMNCSEPLIST = 263;
	const uint QRYFMNCSEPMNFILE = 264;
	const uint QRYFMNCSEPMNSAMPLE = 265;
	const uint QRYFMNCSEPREF1NFILE = 266;
	const uint QRYFMNCSKILIST = 267;
	const uint QRYFMNCSMPAPAR = 268;
	const uint QRYFMNCSMPLIST = 269;
	const uint QRYFMNCSMPMNFILE = 270;
	const uint QRYFMNCSMPMNRUN = 271;
	const uint QRYFMNCSMPMNSTEP = 272;
	const uint QRYFMNCSMPREF1NFILE = 273;
	const uint QRYFMNCSMPSUP1NSAMPLE = 274;
	const uint QRYFMNCSTPAPAR = 275;
	const uint QRYFMNCSTPKSTEPPAR = 276;
	const uint QRYFMNCSTPLIST = 277;
	const uint QRYFMNCSTPMNFILE = 278;
	const uint QRYFMNCSTPREF1NFILE = 279;
	const uint QRYFMNCSTPTPL1NSTEP = 280;
	const uint QRYFMNCTOL1NARTICLE = 281;
	const uint QRYFMNCTOLAAVL = 282;
	const uint QRYFMNCTOLACHAR = 283;
	const uint QRYFMNCTOLARES = 284;
	const uint QRYFMNCTOLAUTIL = 285;
	const uint QRYFMNCTOLKSTEPPAR = 286;
	const uint QRYFMNCTOLKTOOLCHAR = 287;
	const uint QRYFMNCTOLLIST = 288;
	const uint QRYFMNCTOLMNFABUSER = 289;
	const uint QRYFMNCTOLMNTOOLTYPE = 290;
	const uint QRYFMNCTOLREF1NFILE = 291;
	const uint QRYFMNCTOLRLV1NSTEP = 292;
	const uint QRYFMNCTOLSVCMNORG = 293;
	const uint QRYFMNCTTYKSTEPPAR = 294;
	const uint QRYFMNCTTYKTOOLCHAR = 295;
	const uint QRYFMNCTTYLIST = 296;
	const uint QRYFMNCTTYMNTOOL = 297;
	const uint QRYFMNCTTYRLV1NSTEP = 298;
	const uint QRYFMNCTTYSUP1NTOOLTYPE = 299;
	const uint QRYFMNCUSGAACCESS = 300;
	const uint QRYFMNCUSGLIST = 301;
	const uint QRYFMNCUSGMNUSER = 302;
	const uint QRYFMNCUSR1NSESSION = 303;
	const uint QRYFMNCUSRAACCESS = 304;
	const uint QRYFMNCUSRLIST = 305;
	const uint QRYFMNCUSRMNUSERGROUP = 306;
	const uint ROOTFMNC = 307;
	const uint SESSFMNC = 308;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


