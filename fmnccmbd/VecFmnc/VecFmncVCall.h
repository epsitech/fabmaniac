/**
  * \file VecFmncVCall.h
  * vector VecFmncVCall (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef VECFMNCVCALL_H
#define VECFMNCVCALL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecFmncVCall
	*/
namespace VecFmncVCall {
	const uint CALLFMNCACCESS = 1;
	const uint CALLFMNCACTMOD = 2;
	const uint CALLFMNCACTMOD_RUNEQ = 3;
	const uint CALLFMNCACTUPD_REFEQ = 4;
	const uint CALLFMNCADRMOD = 5;
	const uint CALLFMNCADRMOD_HKTHKUEQ = 6;
	const uint CALLFMNCADRUPD_REFEQ = 7;
	const uint CALLFMNCARTMOD = 8;
	const uint CALLFMNCARTMOD_ORGEQ = 9;
	const uint CALLFMNCARTMOD_TOLEQ = 10;
	const uint CALLFMNCARTRORGMOD_ARTEQ = 11;
	const uint CALLFMNCARTRORGMOD_ORGEQ = 12;
	const uint CALLFMNCARTUPD_REFEQ = 13;
	const uint CALLFMNCBILAPOSMOD_BILEQ = 14;
	const uint CALLFMNCBILAPOSMOD_FUSEQ = 15;
	const uint CALLFMNCBILAPOSMOD_TOLEQ = 16;
	const uint CALLFMNCBILJSTEMOD_BILEQ = 17;
	const uint CALLFMNCBILMOD = 18;
	const uint CALLFMNCBILMOD_PRJEQ = 19;
	const uint CALLFMNCBILUPD_REFEQ = 20;
	const uint CALLFMNCBOOLVALPRESET = 21;
	const uint CALLFMNCCRDACTIVE = 22;
	const uint CALLFMNCCRDCLOSE = 23;
	const uint CALLFMNCCRDOPEN = 24;
	const uint CALLFMNCCTLAPARMOD_USREQ = 25;
	const uint CALLFMNCDBLVALPRESET = 26;
	const uint CALLFMNCDESCR = 27;
	const uint CALLFMNCDLGCLOSE = 28;
	const uint CALLFMNCFABMOD = 29;
	const uint CALLFMNCFABRRUNMOD_FABEQ = 30;
	const uint CALLFMNCFABRRUNMOD_RUNEQ = 31;
	const uint CALLFMNCFABUPD_REFEQ = 32;
	const uint CALLFMNCFIL_CLUEQ = 33;
	const uint CALLFMNCFILMOD = 34;
	const uint CALLFMNCFILMOD_CLUEQ = 35;
	const uint CALLFMNCFILMOD_RETREUEQ = 36;
	const uint CALLFMNCFILRSMPMOD_FILEQ = 37;
	const uint CALLFMNCFILRSMPMOD_SMPEQ = 38;
	const uint CALLFMNCFILRSTEMOD_FILEQ = 39;
	const uint CALLFMNCFILRSTEMOD_STEEQ = 40;
	const uint CALLFMNCFILUPD_REFEQ = 41;
	const uint CALLFMNCFPJJSTEMOD_FPJEQ = 42;
	const uint CALLFMNCFPJMOD = 43;
	const uint CALLFMNCFPJMOD_BIOEQ = 44;
	const uint CALLFMNCFPJMOD_FABEQ = 45;
	const uint CALLFMNCFPJRFUSMOD_FPJEQ = 46;
	const uint CALLFMNCFPJRFUSMOD_FUSEQ = 47;
	const uint CALLFMNCFPJUPD_REFEQ = 48;
	const uint CALLFMNCFUSJSTEMOD_FUSEQ = 49;
	const uint CALLFMNCFUSMOD = 50;
	const uint CALLFMNCFUSMOD_FABEQ = 51;
	const uint CALLFMNCFUSRTOLMOD_FUSEQ = 52;
	const uint CALLFMNCFUSRTOLMOD_TOLEQ = 53;
	const uint CALLFMNCFUSUPD_REFEQ = 54;
	const uint CALLFMNCHUSRRUNVMOD_CRDUSREQ = 55;
	const uint CALLFMNCINTVALPRESET = 56;
	const uint CALLFMNCIXPRESET = 57;
	const uint CALLFMNCKAKJKEYMOD_KLSAKEYEQ = 58;
	const uint CALLFMNCKLSAKEYMOD_KLSEQ = 59;
	const uint CALLFMNCKLSAKEYMOD_KLSMTBURFEQ = 60;
	const uint CALLFMNCLOG = 61;
	const uint CALLFMNCLOGOUT = 62;
	const uint CALLFMNCMASTCLAIM = 63;
	const uint CALLFMNCMASTSLVCHG = 64;
	const uint CALLFMNCORGADETMOD_ORGEQ = 65;
	const uint CALLFMNCORGJTITMOD_ORGEQ = 66;
	const uint CALLFMNCORGMOD = 67;
	const uint CALLFMNCORGMOD_SUPEQ = 68;
	const uint CALLFMNCORGRPRSMOD_ORGEQ = 69;
	const uint CALLFMNCORGRPRSMOD_PRSEQ = 70;
	const uint CALLFMNCORGUPD_REFEQ = 71;
	const uint CALLFMNCPCOAPOSMOD_PCOEQ = 72;
	const uint CALLFMNCPCOJSTEMOD_PCOEQ = 73;
	const uint CALLFMNCPCOMOD = 74;
	const uint CALLFMNCPCOMOD_PCOEQ = 75;
	const uint CALLFMNCPCOMOD_SPLEQ = 76;
	const uint CALLFMNCPCOUPD_REFEQ = 77;
	const uint CALLFMNCPRJJSTEMOD_PRJEQ = 78;
	const uint CALLFMNCPRJMOD = 79;
	const uint CALLFMNCPRJUPD_REFEQ = 80;
	const uint CALLFMNCPRSADETMOD_PRSEQ = 81;
	const uint CALLFMNCPRSJLNMMOD_PRSEQ = 82;
	const uint CALLFMNCPRSMOD = 83;
	const uint CALLFMNCPRSRRUNMOD_PRSEQ = 84;
	const uint CALLFMNCPRSRRUNMOD_RUNEQ = 85;
	const uint CALLFMNCPRSUPD_REFEQ = 86;
	const uint CALLFMNCREFPRESET = 87;
	const uint CALLFMNCREFSPRESET = 88;
	const uint CALLFMNCRUNJSTEMOD_RUNEQ = 89;
	const uint CALLFMNCRUNMOD = 90;
	const uint CALLFMNCRUNMOD_PRJEQ = 91;
	const uint CALLFMNCRUNRSMPMOD_RUNEQ = 92;
	const uint CALLFMNCRUNRSMPMOD_SMPEQ = 93;
	const uint CALLFMNCRUNUPD_REFEQ = 94;
	const uint CALLFMNCSCR = 95;
	const uint CALLFMNCSESMOD = 96;
	const uint CALLFMNCSESMOD_USREQ = 97;
	const uint CALLFMNCSESUPD_REFEQ = 98;
	const uint CALLFMNCSKIJQTYMOD_SKIEQ = 99;
	const uint CALLFMNCSKIMOD = 100;
	const uint CALLFMNCSKIMOD_ARTEQ = 101;
	const uint CALLFMNCSKIMOD_ORGEQ = 102;
	const uint CALLFMNCSKIUPD_REFEQ = 103;
	const uint CALLFMNCSMPAPARMOD_SMPEQ = 104;
	const uint CALLFMNCSMPJSTEMOD_SMPEQ = 105;
	const uint CALLFMNCSMPMOD = 106;
	const uint CALLFMNCSMPMOD_ARTEQ = 107;
	const uint CALLFMNCSMPMOD_SUPEQ = 108;
	const uint CALLFMNCSMPRSTEMOD_SMPEQ = 109;
	const uint CALLFMNCSMPRSTEMOD_STEEQ = 110;
	const uint CALLFMNCSMPUPD_REFEQ = 111;
	const uint CALLFMNCSORGRTOLMOD_ORGEQ = 112;
	const uint CALLFMNCSORGRTOLMOD_TOLEQ = 113;
	const uint CALLFMNCSREFPRESET = 114;
	const uint CALLFMNCSTATCHG = 115;
	const uint CALLFMNCSTEAPARMOD_RETREUEQ = 116;
	const uint CALLFMNCSTEAPARMOD_STEEQ = 117;
	const uint CALLFMNCSTEMOD = 118;
	const uint CALLFMNCSTEMOD_ACTEQ = 119;
	const uint CALLFMNCSTEMOD_RLTRLUEQ = 120;
	const uint CALLFMNCSTEMOD_STPEQ = 121;
	const uint CALLFMNCSTEUPD_REFEQ = 122;
	const uint CALLFMNCSTGCHG = 123;
	const uint CALLFMNCSTUBCHG = 124;
	const uint CALLFMNCTOLAAVLMOD_TOLEQ = 125;
	const uint CALLFMNCTOLACHAMOD_TOLEQ = 126;
	const uint CALLFMNCTOLARESMOD_FUSEQ = 127;
	const uint CALLFMNCTOLARESMOD_TOLEQ = 128;
	const uint CALLFMNCTOLAUTIMOD_FPJEQ = 129;
	const uint CALLFMNCTOLAUTIMOD_FUSEQ = 130;
	const uint CALLFMNCTOLAUTIMOD_TOLEQ = 131;
	const uint CALLFMNCTOLJUPRMOD_TOLEQ = 132;
	const uint CALLFMNCTOLMOD = 133;
	const uint CALLFMNCTOLMOD_FABEQ = 134;
	const uint CALLFMNCTOLMOD_MNFEQ = 135;
	const uint CALLFMNCTOLRTTYMOD_TOLEQ = 136;
	const uint CALLFMNCTOLRTTYMOD_TTYEQ = 137;
	const uint CALLFMNCTOLUPD_REFEQ = 138;
	const uint CALLFMNCTTYMOD = 139;
	const uint CALLFMNCTTYMOD_SUPEQ = 140;
	const uint CALLFMNCTTYUPD_REFEQ = 141;
	const uint CALLFMNCTXTVALPRESET = 142;
	const uint CALLFMNCUSGAACCMOD_USGEQ = 143;
	const uint CALLFMNCUSGMOD = 144;
	const uint CALLFMNCUSGUPD_REFEQ = 145;
	const uint CALLFMNCUSRAACCMOD_USREQ = 146;
	const uint CALLFMNCUSRJSTEMOD_USREQ = 147;
	const uint CALLFMNCUSRMOD = 148;
	const uint CALLFMNCUSRRUSGMOD_USGEQ = 149;
	const uint CALLFMNCUSRRUSGMOD_USREQ = 150;
	const uint CALLFMNCUSRUPD_REFEQ = 151;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


