/**
  * \file VecFmncVJob.cpp
  * vector VecFmncVJob (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "VecFmncVJob.h"

/******************************************************************************
 namespace VecFmncVJob
 ******************************************************************************/

uint VecFmncVJob::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdfmncact") return CRDFMNCACT;
	else if (s == "crdfmncadr") return CRDFMNCADR;
	else if (s == "crdfmncart") return CRDFMNCART;
	else if (s == "crdfmncbil") return CRDFMNCBIL;
	else if (s == "crdfmncfab") return CRDFMNCFAB;
	else if (s == "crdfmncfil") return CRDFMNCFIL;
	else if (s == "crdfmncfpj") return CRDFMNCFPJ;
	else if (s == "crdfmncfus") return CRDFMNCFUS;
	else if (s == "crdfmncnav") return CRDFMNCNAV;
	else if (s == "crdfmncorg") return CRDFMNCORG;
	else if (s == "crdfmncpco") return CRDFMNCPCO;
	else if (s == "crdfmncprj") return CRDFMNCPRJ;
	else if (s == "crdfmncprs") return CRDFMNCPRS;
	else if (s == "crdfmncrun") return CRDFMNCRUN;
	else if (s == "crdfmncsep") return CRDFMNCSEP;
	else if (s == "crdfmncski") return CRDFMNCSKI;
	else if (s == "crdfmncsmp") return CRDFMNCSMP;
	else if (s == "crdfmncstp") return CRDFMNCSTP;
	else if (s == "crdfmnctol") return CRDFMNCTOL;
	else if (s == "crdfmnctty") return CRDFMNCTTY;
	else if (s == "crdfmncusg") return CRDFMNCUSG;
	else if (s == "crdfmncusr") return CRDFMNCUSR;
	else if (s == "dlgfmncactnew") return DLGFMNCACTNEW;
	else if (s == "dlgfmncfabexpfab") return DLGFMNCFABEXPFAB;
	else if (s == "dlgfmncfabimpfab") return DLGFMNCFABIMPFAB;
	else if (s == "dlgfmncfabnew") return DLGFMNCFABNEW;
	else if (s == "dlgfmncnavloaini") return DLGFMNCNAVLOAINI;
	else if (s == "dlgfmncorgexporg") return DLGFMNCORGEXPORG;
	else if (s == "dlgfmncorgimporg") return DLGFMNCORGIMPORG;
	else if (s == "dlgfmncorgnew") return DLGFMNCORGNEW;
	else if (s == "dlgfmncprjexpelb") return DLGFMNCPRJEXPELB;
	else if (s == "dlgfmncprjimpelb") return DLGFMNCPRJIMPELB;
	else if (s == "dlgfmncprjnew") return DLGFMNCPRJNEW;
	else if (s == "dlgfmncrungenrep") return DLGFMNCRUNGENREP;
	else if (s == "dlgfmncrunnew") return DLGFMNCRUNNEW;
	else if (s == "dlgfmncsmpgenrep") return DLGFMNCSMPGENREP;
	else if (s == "dlgfmncsmpnew") return DLGFMNCSMPNEW;
	else if (s == "iexfmncelb") return IEXFMNCELB;
	else if (s == "iexfmncfab") return IEXFMNCFAB;
	else if (s == "iexfmncini") return IEXFMNCINI;
	else if (s == "iexfmncorg") return IEXFMNCORG;
	else if (s == "pnlfmncact1nstep") return PNLFMNCACT1NSTEP;
	else if (s == "pnlfmncactdetail") return PNLFMNCACTDETAIL;
	else if (s == "pnlfmncactheadbar") return PNLFMNCACTHEADBAR;
	else if (s == "pnlfmncactlist") return PNLFMNCACTLIST;
	else if (s == "pnlfmncactrec") return PNLFMNCACTREC;
	else if (s == "pnlfmncadrdetail") return PNLFMNCADRDETAIL;
	else if (s == "pnlfmncadrheadbar") return PNLFMNCADRHEADBAR;
	else if (s == "pnlfmncadrlist") return PNLFMNCADRLIST;
	else if (s == "pnlfmncadrrec") return PNLFMNCADRREC;
	else if (s == "pnlfmncart1nsample") return PNLFMNCART1NSAMPLE;
	else if (s == "pnlfmncart1nstockitem") return PNLFMNCART1NSTOCKITEM;
	else if (s == "pnlfmncartdetail") return PNLFMNCARTDETAIL;
	else if (s == "pnlfmncartheadbar") return PNLFMNCARTHEADBAR;
	else if (s == "pnlfmncartlist") return PNLFMNCARTLIST;
	else if (s == "pnlfmncartmnorg") return PNLFMNCARTMNORG;
	else if (s == "pnlfmncartrec") return PNLFMNCARTREC;
	else if (s == "pnlfmncartref1nfile") return PNLFMNCARTREF1NFILE;
	else if (s == "pnlfmncbilapos") return PNLFMNCBILAPOS;
	else if (s == "pnlfmncbildetail") return PNLFMNCBILDETAIL;
	else if (s == "pnlfmncbilheadbar") return PNLFMNCBILHEADBAR;
	else if (s == "pnlfmncbillist") return PNLFMNCBILLIST;
	else if (s == "pnlfmncbilrec") return PNLFMNCBILREC;
	else if (s == "pnlfmncfab1nfabproject") return PNLFMNCFAB1NFABPROJECT;
	else if (s == "pnlfmncfab1nfabuser") return PNLFMNCFAB1NFABUSER;
	else if (s == "pnlfmncfabdetail") return PNLFMNCFABDETAIL;
	else if (s == "pnlfmncfabfab1ntool") return PNLFMNCFABFAB1NTOOL;
	else if (s == "pnlfmncfabheadbar") return PNLFMNCFABHEADBAR;
	else if (s == "pnlfmncfablist") return PNLFMNCFABLIST;
	else if (s == "pnlfmncfabmnrun") return PNLFMNCFABMNRUN;
	else if (s == "pnlfmncfabrec") return PNLFMNCFABREC;
	else if (s == "pnlfmncfildetail") return PNLFMNCFILDETAIL;
	else if (s == "pnlfmncfilheadbar") return PNLFMNCFILHEADBAR;
	else if (s == "pnlfmncfillist") return PNLFMNCFILLIST;
	else if (s == "pnlfmncfilmnsample") return PNLFMNCFILMNSAMPLE;
	else if (s == "pnlfmncfilmnstep") return PNLFMNCFILMNSTEP;
	else if (s == "pnlfmncfilrec") return PNLFMNCFILREC;
	else if (s == "pnlfmncfpj1nbill") return PNLFMNCFPJ1NBILL;
	else if (s == "pnlfmncfpjdetail") return PNLFMNCFPJDETAIL;
	else if (s == "pnlfmncfpjheadbar") return PNLFMNCFPJHEADBAR;
	else if (s == "pnlfmncfpjlist") return PNLFMNCFPJLIST;
	else if (s == "pnlfmncfpjmnfabuser") return PNLFMNCFPJMNFABUSER;
	else if (s == "pnlfmncfpjrec") return PNLFMNCFPJREC;
	else if (s == "pnlfmncfusdetail") return PNLFMNCFUSDETAIL;
	else if (s == "pnlfmncfusheadbar") return PNLFMNCFUSHEADBAR;
	else if (s == "pnlfmncfuslist") return PNLFMNCFUSLIST;
	else if (s == "pnlfmncfusmnfabproject") return PNLFMNCFUSMNFABPROJECT;
	else if (s == "pnlfmncfusmntool") return PNLFMNCFUSMNTOOL;
	else if (s == "pnlfmncfusrec") return PNLFMNCFUSREC;
	else if (s == "pnlfmncnavadmin") return PNLFMNCNAVADMIN;
	else if (s == "pnlfmncnavfabmgmt") return PNLFMNCNAVFABMGMT;
	else if (s == "pnlfmncnavheadbar") return PNLFMNCNAVHEADBAR;
	else if (s == "pnlfmncnavlabbook") return PNLFMNCNAVLABBOOK;
	else if (s == "pnlfmncnavpre") return PNLFMNCNAVPRE;
	else if (s == "pnlfmncnavsupply") return PNLFMNCNAVSUPPLY;
	else if (s == "pnlfmncorg1narticle") return PNLFMNCORG1NARTICLE;
	else if (s == "pnlfmncorg1nstockitem") return PNLFMNCORG1NSTOCKITEM;
	else if (s == "pnlfmncorgadetail") return PNLFMNCORGADETAIL;
	else if (s == "pnlfmncorgbio1nfabproject") return PNLFMNCORGBIO1NFABPROJECT;
	else if (s == "pnlfmncorgdetail") return PNLFMNCORGDETAIL;
	else if (s == "pnlfmncorgheadbar") return PNLFMNCORGHEADBAR;
	else if (s == "pnlfmncorghk1naddress") return PNLFMNCORGHK1NADDRESS;
	else if (s == "pnlfmncorgkstocklcn") return PNLFMNCORGKSTOCKLCN;
	else if (s == "pnlfmncorglist") return PNLFMNCORGLIST;
	else if (s == "pnlfmncorgmnarticle") return PNLFMNCORGMNARTICLE;
	else if (s == "pnlfmncorgmnf1ntool") return PNLFMNCORGMNF1NTOOL;
	else if (s == "pnlfmncorgmnperson") return PNLFMNCORGMNPERSON;
	else if (s == "pnlfmncorgpco1npurchorder") return PNLFMNCORGPCO1NPURCHORDER;
	else if (s == "pnlfmncorgrec") return PNLFMNCORGREC;
	else if (s == "pnlfmncorgspl1npurchorder") return PNLFMNCORGSPL1NPURCHORDER;
	else if (s == "pnlfmncorgsup1norg") return PNLFMNCORGSUP1NORG;
	else if (s == "pnlfmncorgsvcmntool") return PNLFMNCORGSVCMNTOOL;
	else if (s == "pnlfmncpcoapos") return PNLFMNCPCOAPOS;
	else if (s == "pnlfmncpcodetail") return PNLFMNCPCODETAIL;
	else if (s == "pnlfmncpcoheadbar") return PNLFMNCPCOHEADBAR;
	else if (s == "pnlfmncpcolist") return PNLFMNCPCOLIST;
	else if (s == "pnlfmncpcorec") return PNLFMNCPCOREC;
	else if (s == "pnlfmncprj1nrun") return PNLFMNCPRJ1NRUN;
	else if (s == "pnlfmncprjdetail") return PNLFMNCPRJDETAIL;
	else if (s == "pnlfmncprjheadbar") return PNLFMNCPRJHEADBAR;
	else if (s == "pnlfmncprjlist") return PNLFMNCPRJLIST;
	else if (s == "pnlfmncprjrec") return PNLFMNCPRJREC;
	else if (s == "pnlfmncprsadetail") return PNLFMNCPRSADETAIL;
	else if (s == "pnlfmncprsdetail") return PNLFMNCPRSDETAIL;
	else if (s == "pnlfmncprsheadbar") return PNLFMNCPRSHEADBAR;
	else if (s == "pnlfmncprshk1naddress") return PNLFMNCPRSHK1NADDRESS;
	else if (s == "pnlfmncprslist") return PNLFMNCPRSLIST;
	else if (s == "pnlfmncprsmnorg") return PNLFMNCPRSMNORG;
	else if (s == "pnlfmncprsmnrun") return PNLFMNCPRSMNRUN;
	else if (s == "pnlfmncprsrec") return PNLFMNCPRSREC;
	else if (s == "pnlfmncrundetail") return PNLFMNCRUNDETAIL;
	else if (s == "pnlfmncrunheadbar") return PNLFMNCRUNHEADBAR;
	else if (s == "pnlfmncrunlist") return PNLFMNCRUNLIST;
	else if (s == "pnlfmncrunmnfab") return PNLFMNCRUNMNFAB;
	else if (s == "pnlfmncrunmnperson") return PNLFMNCRUNMNPERSON;
	else if (s == "pnlfmncrunmnsample") return PNLFMNCRUNMNSAMPLE;
	else if (s == "pnlfmncrunrec") return PNLFMNCRUNREC;
	else if (s == "pnlfmncrunref1nfile") return PNLFMNCRUNREF1NFILE;
	else if (s == "pnlfmncrunrun1nactivity") return PNLFMNCRUNRUN1NACTIVITY;
	else if (s == "pnlfmncsepapar") return PNLFMNCSEPAPAR;
	else if (s == "pnlfmncsepdetail") return PNLFMNCSEPDETAIL;
	else if (s == "pnlfmncsepheadbar") return PNLFMNCSEPHEADBAR;
	else if (s == "pnlfmncseplist") return PNLFMNCSEPLIST;
	else if (s == "pnlfmncsepmnfile") return PNLFMNCSEPMNFILE;
	else if (s == "pnlfmncsepmnsample") return PNLFMNCSEPMNSAMPLE;
	else if (s == "pnlfmncseprec") return PNLFMNCSEPREC;
	else if (s == "pnlfmncsepref1nfile") return PNLFMNCSEPREF1NFILE;
	else if (s == "pnlfmncskidetail") return PNLFMNCSKIDETAIL;
	else if (s == "pnlfmncskiheadbar") return PNLFMNCSKIHEADBAR;
	else if (s == "pnlfmncskilist") return PNLFMNCSKILIST;
	else if (s == "pnlfmncskirec") return PNLFMNCSKIREC;
	else if (s == "pnlfmncsmpapar") return PNLFMNCSMPAPAR;
	else if (s == "pnlfmncsmpdetail") return PNLFMNCSMPDETAIL;
	else if (s == "pnlfmncsmpheadbar") return PNLFMNCSMPHEADBAR;
	else if (s == "pnlfmncsmplist") return PNLFMNCSMPLIST;
	else if (s == "pnlfmncsmpmnfile") return PNLFMNCSMPMNFILE;
	else if (s == "pnlfmncsmpmnrun") return PNLFMNCSMPMNRUN;
	else if (s == "pnlfmncsmpmnstep") return PNLFMNCSMPMNSTEP;
	else if (s == "pnlfmncsmprec") return PNLFMNCSMPREC;
	else if (s == "pnlfmncsmpref1nfile") return PNLFMNCSMPREF1NFILE;
	else if (s == "pnlfmncsmpsup1nsample") return PNLFMNCSMPSUP1NSAMPLE;
	else if (s == "pnlfmncstpapar") return PNLFMNCSTPAPAR;
	else if (s == "pnlfmncstpdetail") return PNLFMNCSTPDETAIL;
	else if (s == "pnlfmncstpheadbar") return PNLFMNCSTPHEADBAR;
	else if (s == "pnlfmncstpksteppar") return PNLFMNCSTPKSTEPPAR;
	else if (s == "pnlfmncstplist") return PNLFMNCSTPLIST;
	else if (s == "pnlfmncstpmnfile") return PNLFMNCSTPMNFILE;
	else if (s == "pnlfmncstprec") return PNLFMNCSTPREC;
	else if (s == "pnlfmncstpref1nfile") return PNLFMNCSTPREF1NFILE;
	else if (s == "pnlfmncstptpl1nstep") return PNLFMNCSTPTPL1NSTEP;
	else if (s == "pnlfmnctol1narticle") return PNLFMNCTOL1NARTICLE;
	else if (s == "pnlfmnctolaavl") return PNLFMNCTOLAAVL;
	else if (s == "pnlfmnctolachar") return PNLFMNCTOLACHAR;
	else if (s == "pnlfmnctolares") return PNLFMNCTOLARES;
	else if (s == "pnlfmnctolautil") return PNLFMNCTOLAUTIL;
	else if (s == "pnlfmnctoldetail") return PNLFMNCTOLDETAIL;
	else if (s == "pnlfmnctolheadbar") return PNLFMNCTOLHEADBAR;
	else if (s == "pnlfmnctolksteppar") return PNLFMNCTOLKSTEPPAR;
	else if (s == "pnlfmnctolktoolchar") return PNLFMNCTOLKTOOLCHAR;
	else if (s == "pnlfmnctollist") return PNLFMNCTOLLIST;
	else if (s == "pnlfmnctolmnfabuser") return PNLFMNCTOLMNFABUSER;
	else if (s == "pnlfmnctolmntooltype") return PNLFMNCTOLMNTOOLTYPE;
	else if (s == "pnlfmnctolrec") return PNLFMNCTOLREC;
	else if (s == "pnlfmnctolref1nfile") return PNLFMNCTOLREF1NFILE;
	else if (s == "pnlfmnctolrlv1nstep") return PNLFMNCTOLRLV1NSTEP;
	else if (s == "pnlfmnctolsvcmnorg") return PNLFMNCTOLSVCMNORG;
	else if (s == "pnlfmncttydetail") return PNLFMNCTTYDETAIL;
	else if (s == "pnlfmncttyheadbar") return PNLFMNCTTYHEADBAR;
	else if (s == "pnlfmncttyksteppar") return PNLFMNCTTYKSTEPPAR;
	else if (s == "pnlfmncttyktoolchar") return PNLFMNCTTYKTOOLCHAR;
	else if (s == "pnlfmncttylist") return PNLFMNCTTYLIST;
	else if (s == "pnlfmncttymntool") return PNLFMNCTTYMNTOOL;
	else if (s == "pnlfmncttyrec") return PNLFMNCTTYREC;
	else if (s == "pnlfmncttyrlv1nstep") return PNLFMNCTTYRLV1NSTEP;
	else if (s == "pnlfmncttysup1ntooltype") return PNLFMNCTTYSUP1NTOOLTYPE;
	else if (s == "pnlfmncusgaaccess") return PNLFMNCUSGAACCESS;
	else if (s == "pnlfmncusgdetail") return PNLFMNCUSGDETAIL;
	else if (s == "pnlfmncusgheadbar") return PNLFMNCUSGHEADBAR;
	else if (s == "pnlfmncusglist") return PNLFMNCUSGLIST;
	else if (s == "pnlfmncusgmnuser") return PNLFMNCUSGMNUSER;
	else if (s == "pnlfmncusgrec") return PNLFMNCUSGREC;
	else if (s == "pnlfmncusr1nsession") return PNLFMNCUSR1NSESSION;
	else if (s == "pnlfmncusraaccess") return PNLFMNCUSRAACCESS;
	else if (s == "pnlfmncusrdetail") return PNLFMNCUSRDETAIL;
	else if (s == "pnlfmncusrheadbar") return PNLFMNCUSRHEADBAR;
	else if (s == "pnlfmncusrlist") return PNLFMNCUSRLIST;
	else if (s == "pnlfmncusrmnusergroup") return PNLFMNCUSRMNUSERGROUP;
	else if (s == "pnlfmncusrrec") return PNLFMNCUSRREC;
	else if (s == "qryfmncact1nstep") return QRYFMNCACT1NSTEP;
	else if (s == "qryfmncactlist") return QRYFMNCACTLIST;
	else if (s == "qryfmncadrlist") return QRYFMNCADRLIST;
	else if (s == "qryfmncart1nsample") return QRYFMNCART1NSAMPLE;
	else if (s == "qryfmncart1nstockitem") return QRYFMNCART1NSTOCKITEM;
	else if (s == "qryfmncartlist") return QRYFMNCARTLIST;
	else if (s == "qryfmncartmnorg") return QRYFMNCARTMNORG;
	else if (s == "qryfmncartref1nfile") return QRYFMNCARTREF1NFILE;
	else if (s == "qryfmncbilapos") return QRYFMNCBILAPOS;
	else if (s == "qryfmncbillist") return QRYFMNCBILLIST;
	else if (s == "qryfmncfab1nfabproject") return QRYFMNCFAB1NFABPROJECT;
	else if (s == "qryfmncfab1nfabuser") return QRYFMNCFAB1NFABUSER;
	else if (s == "qryfmncfabfab1ntool") return QRYFMNCFABFAB1NTOOL;
	else if (s == "qryfmncfablist") return QRYFMNCFABLIST;
	else if (s == "qryfmncfabmnrun") return QRYFMNCFABMNRUN;
	else if (s == "qryfmncfillist") return QRYFMNCFILLIST;
	else if (s == "qryfmncfilmnsample") return QRYFMNCFILMNSAMPLE;
	else if (s == "qryfmncfilmnstep") return QRYFMNCFILMNSTEP;
	else if (s == "qryfmncfpj1nbill") return QRYFMNCFPJ1NBILL;
	else if (s == "qryfmncfpjlist") return QRYFMNCFPJLIST;
	else if (s == "qryfmncfpjmnfabuser") return QRYFMNCFPJMNFABUSER;
	else if (s == "qryfmncfuslist") return QRYFMNCFUSLIST;
	else if (s == "qryfmncfusmnfabproject") return QRYFMNCFUSMNFABPROJECT;
	else if (s == "qryfmncfusmntool") return QRYFMNCFUSMNTOOL;
	else if (s == "qryfmncorg1narticle") return QRYFMNCORG1NARTICLE;
	else if (s == "qryfmncorg1nstockitem") return QRYFMNCORG1NSTOCKITEM;
	else if (s == "qryfmncorgadetail") return QRYFMNCORGADETAIL;
	else if (s == "qryfmncorgbio1nfabproject") return QRYFMNCORGBIO1NFABPROJECT;
	else if (s == "qryfmncorghk1naddress") return QRYFMNCORGHK1NADDRESS;
	else if (s == "qryfmncorgkstocklcn") return QRYFMNCORGKSTOCKLCN;
	else if (s == "qryfmncorglist") return QRYFMNCORGLIST;
	else if (s == "qryfmncorgmnarticle") return QRYFMNCORGMNARTICLE;
	else if (s == "qryfmncorgmnf1ntool") return QRYFMNCORGMNF1NTOOL;
	else if (s == "qryfmncorgmnperson") return QRYFMNCORGMNPERSON;
	else if (s == "qryfmncorgpco1npurchorder") return QRYFMNCORGPCO1NPURCHORDER;
	else if (s == "qryfmncorgspl1npurchorder") return QRYFMNCORGSPL1NPURCHORDER;
	else if (s == "qryfmncorgsup1norg") return QRYFMNCORGSUP1NORG;
	else if (s == "qryfmncorgsvcmntool") return QRYFMNCORGSVCMNTOOL;
	else if (s == "qryfmncpcoapos") return QRYFMNCPCOAPOS;
	else if (s == "qryfmncpcolist") return QRYFMNCPCOLIST;
	else if (s == "qryfmncprj1nrun") return QRYFMNCPRJ1NRUN;
	else if (s == "qryfmncprjlist") return QRYFMNCPRJLIST;
	else if (s == "qryfmncprsadetail") return QRYFMNCPRSADETAIL;
	else if (s == "qryfmncprshk1naddress") return QRYFMNCPRSHK1NADDRESS;
	else if (s == "qryfmncprslist") return QRYFMNCPRSLIST;
	else if (s == "qryfmncprsmnorg") return QRYFMNCPRSMNORG;
	else if (s == "qryfmncprsmnrun") return QRYFMNCPRSMNRUN;
	else if (s == "qryfmncrunlist") return QRYFMNCRUNLIST;
	else if (s == "qryfmncrunmnfab") return QRYFMNCRUNMNFAB;
	else if (s == "qryfmncrunmnperson") return QRYFMNCRUNMNPERSON;
	else if (s == "qryfmncrunmnsample") return QRYFMNCRUNMNSAMPLE;
	else if (s == "qryfmncrunref1nfile") return QRYFMNCRUNREF1NFILE;
	else if (s == "qryfmncrunrun1nactivity") return QRYFMNCRUNRUN1NACTIVITY;
	else if (s == "qryfmncsepapar") return QRYFMNCSEPAPAR;
	else if (s == "qryfmncseplist") return QRYFMNCSEPLIST;
	else if (s == "qryfmncsepmnfile") return QRYFMNCSEPMNFILE;
	else if (s == "qryfmncsepmnsample") return QRYFMNCSEPMNSAMPLE;
	else if (s == "qryfmncsepref1nfile") return QRYFMNCSEPREF1NFILE;
	else if (s == "qryfmncskilist") return QRYFMNCSKILIST;
	else if (s == "qryfmncsmpapar") return QRYFMNCSMPAPAR;
	else if (s == "qryfmncsmplist") return QRYFMNCSMPLIST;
	else if (s == "qryfmncsmpmnfile") return QRYFMNCSMPMNFILE;
	else if (s == "qryfmncsmpmnrun") return QRYFMNCSMPMNRUN;
	else if (s == "qryfmncsmpmnstep") return QRYFMNCSMPMNSTEP;
	else if (s == "qryfmncsmpref1nfile") return QRYFMNCSMPREF1NFILE;
	else if (s == "qryfmncsmpsup1nsample") return QRYFMNCSMPSUP1NSAMPLE;
	else if (s == "qryfmncstpapar") return QRYFMNCSTPAPAR;
	else if (s == "qryfmncstpksteppar") return QRYFMNCSTPKSTEPPAR;
	else if (s == "qryfmncstplist") return QRYFMNCSTPLIST;
	else if (s == "qryfmncstpmnfile") return QRYFMNCSTPMNFILE;
	else if (s == "qryfmncstpref1nfile") return QRYFMNCSTPREF1NFILE;
	else if (s == "qryfmncstptpl1nstep") return QRYFMNCSTPTPL1NSTEP;
	else if (s == "qryfmnctol1narticle") return QRYFMNCTOL1NARTICLE;
	else if (s == "qryfmnctolaavl") return QRYFMNCTOLAAVL;
	else if (s == "qryfmnctolachar") return QRYFMNCTOLACHAR;
	else if (s == "qryfmnctolares") return QRYFMNCTOLARES;
	else if (s == "qryfmnctolautil") return QRYFMNCTOLAUTIL;
	else if (s == "qryfmnctolksteppar") return QRYFMNCTOLKSTEPPAR;
	else if (s == "qryfmnctolktoolchar") return QRYFMNCTOLKTOOLCHAR;
	else if (s == "qryfmnctollist") return QRYFMNCTOLLIST;
	else if (s == "qryfmnctolmnfabuser") return QRYFMNCTOLMNFABUSER;
	else if (s == "qryfmnctolmntooltype") return QRYFMNCTOLMNTOOLTYPE;
	else if (s == "qryfmnctolref1nfile") return QRYFMNCTOLREF1NFILE;
	else if (s == "qryfmnctolrlv1nstep") return QRYFMNCTOLRLV1NSTEP;
	else if (s == "qryfmnctolsvcmnorg") return QRYFMNCTOLSVCMNORG;
	else if (s == "qryfmncttyksteppar") return QRYFMNCTTYKSTEPPAR;
	else if (s == "qryfmncttyktoolchar") return QRYFMNCTTYKTOOLCHAR;
	else if (s == "qryfmncttylist") return QRYFMNCTTYLIST;
	else if (s == "qryfmncttymntool") return QRYFMNCTTYMNTOOL;
	else if (s == "qryfmncttyrlv1nstep") return QRYFMNCTTYRLV1NSTEP;
	else if (s == "qryfmncttysup1ntooltype") return QRYFMNCTTYSUP1NTOOLTYPE;
	else if (s == "qryfmncusgaaccess") return QRYFMNCUSGAACCESS;
	else if (s == "qryfmncusglist") return QRYFMNCUSGLIST;
	else if (s == "qryfmncusgmnuser") return QRYFMNCUSGMNUSER;
	else if (s == "qryfmncusr1nsession") return QRYFMNCUSR1NSESSION;
	else if (s == "qryfmncusraaccess") return QRYFMNCUSRAACCESS;
	else if (s == "qryfmncusrlist") return QRYFMNCUSRLIST;
	else if (s == "qryfmncusrmnusergroup") return QRYFMNCUSRMNUSERGROUP;
	else if (s == "rootfmnc") return ROOTFMNC;
	else if (s == "sessfmnc") return SESSFMNC;

	return(0);
};

string VecFmncVJob::getSref(
			const uint ix
		) {
	if (ix == CRDFMNCACT) return("CrdFmncAct");
	else if (ix == CRDFMNCADR) return("CrdFmncAdr");
	else if (ix == CRDFMNCART) return("CrdFmncArt");
	else if (ix == CRDFMNCBIL) return("CrdFmncBil");
	else if (ix == CRDFMNCFAB) return("CrdFmncFab");
	else if (ix == CRDFMNCFIL) return("CrdFmncFil");
	else if (ix == CRDFMNCFPJ) return("CrdFmncFpj");
	else if (ix == CRDFMNCFUS) return("CrdFmncFus");
	else if (ix == CRDFMNCNAV) return("CrdFmncNav");
	else if (ix == CRDFMNCORG) return("CrdFmncOrg");
	else if (ix == CRDFMNCPCO) return("CrdFmncPco");
	else if (ix == CRDFMNCPRJ) return("CrdFmncPrj");
	else if (ix == CRDFMNCPRS) return("CrdFmncPrs");
	else if (ix == CRDFMNCRUN) return("CrdFmncRun");
	else if (ix == CRDFMNCSEP) return("CrdFmncSep");
	else if (ix == CRDFMNCSKI) return("CrdFmncSki");
	else if (ix == CRDFMNCSMP) return("CrdFmncSmp");
	else if (ix == CRDFMNCSTP) return("CrdFmncStp");
	else if (ix == CRDFMNCTOL) return("CrdFmncTol");
	else if (ix == CRDFMNCTTY) return("CrdFmncTty");
	else if (ix == CRDFMNCUSG) return("CrdFmncUsg");
	else if (ix == CRDFMNCUSR) return("CrdFmncUsr");
	else if (ix == DLGFMNCACTNEW) return("DlgFmncActNew");
	else if (ix == DLGFMNCFABEXPFAB) return("DlgFmncFabExpfab");
	else if (ix == DLGFMNCFABIMPFAB) return("DlgFmncFabImpfab");
	else if (ix == DLGFMNCFABNEW) return("DlgFmncFabNew");
	else if (ix == DLGFMNCNAVLOAINI) return("DlgFmncNavLoaini");
	else if (ix == DLGFMNCORGEXPORG) return("DlgFmncOrgExporg");
	else if (ix == DLGFMNCORGIMPORG) return("DlgFmncOrgImporg");
	else if (ix == DLGFMNCORGNEW) return("DlgFmncOrgNew");
	else if (ix == DLGFMNCPRJEXPELB) return("DlgFmncPrjExpelb");
	else if (ix == DLGFMNCPRJIMPELB) return("DlgFmncPrjImpelb");
	else if (ix == DLGFMNCPRJNEW) return("DlgFmncPrjNew");
	else if (ix == DLGFMNCRUNGENREP) return("DlgFmncRunGenrep");
	else if (ix == DLGFMNCRUNNEW) return("DlgFmncRunNew");
	else if (ix == DLGFMNCSMPGENREP) return("DlgFmncSmpGenrep");
	else if (ix == DLGFMNCSMPNEW) return("DlgFmncSmpNew");
	else if (ix == IEXFMNCELB) return("IexFmncElb");
	else if (ix == IEXFMNCFAB) return("IexFmncFab");
	else if (ix == IEXFMNCINI) return("IexFmncIni");
	else if (ix == IEXFMNCORG) return("IexFmncOrg");
	else if (ix == PNLFMNCACT1NSTEP) return("PnlFmncAct1NStep");
	else if (ix == PNLFMNCACTDETAIL) return("PnlFmncActDetail");
	else if (ix == PNLFMNCACTHEADBAR) return("PnlFmncActHeadbar");
	else if (ix == PNLFMNCACTLIST) return("PnlFmncActList");
	else if (ix == PNLFMNCACTREC) return("PnlFmncActRec");
	else if (ix == PNLFMNCADRDETAIL) return("PnlFmncAdrDetail");
	else if (ix == PNLFMNCADRHEADBAR) return("PnlFmncAdrHeadbar");
	else if (ix == PNLFMNCADRLIST) return("PnlFmncAdrList");
	else if (ix == PNLFMNCADRREC) return("PnlFmncAdrRec");
	else if (ix == PNLFMNCART1NSAMPLE) return("PnlFmncArt1NSample");
	else if (ix == PNLFMNCART1NSTOCKITEM) return("PnlFmncArt1NStockitem");
	else if (ix == PNLFMNCARTDETAIL) return("PnlFmncArtDetail");
	else if (ix == PNLFMNCARTHEADBAR) return("PnlFmncArtHeadbar");
	else if (ix == PNLFMNCARTLIST) return("PnlFmncArtList");
	else if (ix == PNLFMNCARTMNORG) return("PnlFmncArtMNOrg");
	else if (ix == PNLFMNCARTREC) return("PnlFmncArtRec");
	else if (ix == PNLFMNCARTREF1NFILE) return("PnlFmncArtRef1NFile");
	else if (ix == PNLFMNCBILAPOS) return("PnlFmncBilAPos");
	else if (ix == PNLFMNCBILDETAIL) return("PnlFmncBilDetail");
	else if (ix == PNLFMNCBILHEADBAR) return("PnlFmncBilHeadbar");
	else if (ix == PNLFMNCBILLIST) return("PnlFmncBilList");
	else if (ix == PNLFMNCBILREC) return("PnlFmncBilRec");
	else if (ix == PNLFMNCFAB1NFABPROJECT) return("PnlFmncFab1NFabproject");
	else if (ix == PNLFMNCFAB1NFABUSER) return("PnlFmncFab1NFabuser");
	else if (ix == PNLFMNCFABDETAIL) return("PnlFmncFabDetail");
	else if (ix == PNLFMNCFABFAB1NTOOL) return("PnlFmncFabFab1NTool");
	else if (ix == PNLFMNCFABHEADBAR) return("PnlFmncFabHeadbar");
	else if (ix == PNLFMNCFABLIST) return("PnlFmncFabList");
	else if (ix == PNLFMNCFABMNRUN) return("PnlFmncFabMNRun");
	else if (ix == PNLFMNCFABREC) return("PnlFmncFabRec");
	else if (ix == PNLFMNCFILDETAIL) return("PnlFmncFilDetail");
	else if (ix == PNLFMNCFILHEADBAR) return("PnlFmncFilHeadbar");
	else if (ix == PNLFMNCFILLIST) return("PnlFmncFilList");
	else if (ix == PNLFMNCFILMNSAMPLE) return("PnlFmncFilMNSample");
	else if (ix == PNLFMNCFILMNSTEP) return("PnlFmncFilMNStep");
	else if (ix == PNLFMNCFILREC) return("PnlFmncFilRec");
	else if (ix == PNLFMNCFPJ1NBILL) return("PnlFmncFpj1NBill");
	else if (ix == PNLFMNCFPJDETAIL) return("PnlFmncFpjDetail");
	else if (ix == PNLFMNCFPJHEADBAR) return("PnlFmncFpjHeadbar");
	else if (ix == PNLFMNCFPJLIST) return("PnlFmncFpjList");
	else if (ix == PNLFMNCFPJMNFABUSER) return("PnlFmncFpjMNFabuser");
	else if (ix == PNLFMNCFPJREC) return("PnlFmncFpjRec");
	else if (ix == PNLFMNCFUSDETAIL) return("PnlFmncFusDetail");
	else if (ix == PNLFMNCFUSHEADBAR) return("PnlFmncFusHeadbar");
	else if (ix == PNLFMNCFUSLIST) return("PnlFmncFusList");
	else if (ix == PNLFMNCFUSMNFABPROJECT) return("PnlFmncFusMNFabproject");
	else if (ix == PNLFMNCFUSMNTOOL) return("PnlFmncFusMNTool");
	else if (ix == PNLFMNCFUSREC) return("PnlFmncFusRec");
	else if (ix == PNLFMNCNAVADMIN) return("PnlFmncNavAdmin");
	else if (ix == PNLFMNCNAVFABMGMT) return("PnlFmncNavFabmgmt");
	else if (ix == PNLFMNCNAVHEADBAR) return("PnlFmncNavHeadbar");
	else if (ix == PNLFMNCNAVLABBOOK) return("PnlFmncNavLabbook");
	else if (ix == PNLFMNCNAVPRE) return("PnlFmncNavPre");
	else if (ix == PNLFMNCNAVSUPPLY) return("PnlFmncNavSupply");
	else if (ix == PNLFMNCORG1NARTICLE) return("PnlFmncOrg1NArticle");
	else if (ix == PNLFMNCORG1NSTOCKITEM) return("PnlFmncOrg1NStockitem");
	else if (ix == PNLFMNCORGADETAIL) return("PnlFmncOrgADetail");
	else if (ix == PNLFMNCORGBIO1NFABPROJECT) return("PnlFmncOrgBio1NFabproject");
	else if (ix == PNLFMNCORGDETAIL) return("PnlFmncOrgDetail");
	else if (ix == PNLFMNCORGHEADBAR) return("PnlFmncOrgHeadbar");
	else if (ix == PNLFMNCORGHK1NADDRESS) return("PnlFmncOrgHk1NAddress");
	else if (ix == PNLFMNCORGKSTOCKLCN) return("PnlFmncOrgKStocklcn");
	else if (ix == PNLFMNCORGLIST) return("PnlFmncOrgList");
	else if (ix == PNLFMNCORGMNARTICLE) return("PnlFmncOrgMNArticle");
	else if (ix == PNLFMNCORGMNF1NTOOL) return("PnlFmncOrgMnf1NTool");
	else if (ix == PNLFMNCORGMNPERSON) return("PnlFmncOrgMNPerson");
	else if (ix == PNLFMNCORGPCO1NPURCHORDER) return("PnlFmncOrgPco1NPurchorder");
	else if (ix == PNLFMNCORGREC) return("PnlFmncOrgRec");
	else if (ix == PNLFMNCORGSPL1NPURCHORDER) return("PnlFmncOrgSpl1NPurchorder");
	else if (ix == PNLFMNCORGSUP1NORG) return("PnlFmncOrgSup1NOrg");
	else if (ix == PNLFMNCORGSVCMNTOOL) return("PnlFmncOrgSvcMNTool");
	else if (ix == PNLFMNCPCOAPOS) return("PnlFmncPcoAPos");
	else if (ix == PNLFMNCPCODETAIL) return("PnlFmncPcoDetail");
	else if (ix == PNLFMNCPCOHEADBAR) return("PnlFmncPcoHeadbar");
	else if (ix == PNLFMNCPCOLIST) return("PnlFmncPcoList");
	else if (ix == PNLFMNCPCOREC) return("PnlFmncPcoRec");
	else if (ix == PNLFMNCPRJ1NRUN) return("PnlFmncPrj1NRun");
	else if (ix == PNLFMNCPRJDETAIL) return("PnlFmncPrjDetail");
	else if (ix == PNLFMNCPRJHEADBAR) return("PnlFmncPrjHeadbar");
	else if (ix == PNLFMNCPRJLIST) return("PnlFmncPrjList");
	else if (ix == PNLFMNCPRJREC) return("PnlFmncPrjRec");
	else if (ix == PNLFMNCPRSADETAIL) return("PnlFmncPrsADetail");
	else if (ix == PNLFMNCPRSDETAIL) return("PnlFmncPrsDetail");
	else if (ix == PNLFMNCPRSHEADBAR) return("PnlFmncPrsHeadbar");
	else if (ix == PNLFMNCPRSHK1NADDRESS) return("PnlFmncPrsHk1NAddress");
	else if (ix == PNLFMNCPRSLIST) return("PnlFmncPrsList");
	else if (ix == PNLFMNCPRSMNORG) return("PnlFmncPrsMNOrg");
	else if (ix == PNLFMNCPRSMNRUN) return("PnlFmncPrsMNRun");
	else if (ix == PNLFMNCPRSREC) return("PnlFmncPrsRec");
	else if (ix == PNLFMNCRUNDETAIL) return("PnlFmncRunDetail");
	else if (ix == PNLFMNCRUNHEADBAR) return("PnlFmncRunHeadbar");
	else if (ix == PNLFMNCRUNLIST) return("PnlFmncRunList");
	else if (ix == PNLFMNCRUNMNFAB) return("PnlFmncRunMNFab");
	else if (ix == PNLFMNCRUNMNPERSON) return("PnlFmncRunMNPerson");
	else if (ix == PNLFMNCRUNMNSAMPLE) return("PnlFmncRunMNSample");
	else if (ix == PNLFMNCRUNREC) return("PnlFmncRunRec");
	else if (ix == PNLFMNCRUNREF1NFILE) return("PnlFmncRunRef1NFile");
	else if (ix == PNLFMNCRUNRUN1NACTIVITY) return("PnlFmncRunRun1NActivity");
	else if (ix == PNLFMNCSEPAPAR) return("PnlFmncSepAPar");
	else if (ix == PNLFMNCSEPDETAIL) return("PnlFmncSepDetail");
	else if (ix == PNLFMNCSEPHEADBAR) return("PnlFmncSepHeadbar");
	else if (ix == PNLFMNCSEPLIST) return("PnlFmncSepList");
	else if (ix == PNLFMNCSEPMNFILE) return("PnlFmncSepMNFile");
	else if (ix == PNLFMNCSEPMNSAMPLE) return("PnlFmncSepMNSample");
	else if (ix == PNLFMNCSEPREC) return("PnlFmncSepRec");
	else if (ix == PNLFMNCSEPREF1NFILE) return("PnlFmncSepRef1NFile");
	else if (ix == PNLFMNCSKIDETAIL) return("PnlFmncSkiDetail");
	else if (ix == PNLFMNCSKIHEADBAR) return("PnlFmncSkiHeadbar");
	else if (ix == PNLFMNCSKILIST) return("PnlFmncSkiList");
	else if (ix == PNLFMNCSKIREC) return("PnlFmncSkiRec");
	else if (ix == PNLFMNCSMPAPAR) return("PnlFmncSmpAPar");
	else if (ix == PNLFMNCSMPDETAIL) return("PnlFmncSmpDetail");
	else if (ix == PNLFMNCSMPHEADBAR) return("PnlFmncSmpHeadbar");
	else if (ix == PNLFMNCSMPLIST) return("PnlFmncSmpList");
	else if (ix == PNLFMNCSMPMNFILE) return("PnlFmncSmpMNFile");
	else if (ix == PNLFMNCSMPMNRUN) return("PnlFmncSmpMNRun");
	else if (ix == PNLFMNCSMPMNSTEP) return("PnlFmncSmpMNStep");
	else if (ix == PNLFMNCSMPREC) return("PnlFmncSmpRec");
	else if (ix == PNLFMNCSMPREF1NFILE) return("PnlFmncSmpRef1NFile");
	else if (ix == PNLFMNCSMPSUP1NSAMPLE) return("PnlFmncSmpSup1NSample");
	else if (ix == PNLFMNCSTPAPAR) return("PnlFmncStpAPar");
	else if (ix == PNLFMNCSTPDETAIL) return("PnlFmncStpDetail");
	else if (ix == PNLFMNCSTPHEADBAR) return("PnlFmncStpHeadbar");
	else if (ix == PNLFMNCSTPKSTEPPAR) return("PnlFmncStpKSteppar");
	else if (ix == PNLFMNCSTPLIST) return("PnlFmncStpList");
	else if (ix == PNLFMNCSTPMNFILE) return("PnlFmncStpMNFile");
	else if (ix == PNLFMNCSTPREC) return("PnlFmncStpRec");
	else if (ix == PNLFMNCSTPREF1NFILE) return("PnlFmncStpRef1NFile");
	else if (ix == PNLFMNCSTPTPL1NSTEP) return("PnlFmncStpTpl1NStep");
	else if (ix == PNLFMNCTOL1NARTICLE) return("PnlFmncTol1NArticle");
	else if (ix == PNLFMNCTOLAAVL) return("PnlFmncTolAAvl");
	else if (ix == PNLFMNCTOLACHAR) return("PnlFmncTolAChar");
	else if (ix == PNLFMNCTOLARES) return("PnlFmncTolARes");
	else if (ix == PNLFMNCTOLAUTIL) return("PnlFmncTolAUtil");
	else if (ix == PNLFMNCTOLDETAIL) return("PnlFmncTolDetail");
	else if (ix == PNLFMNCTOLHEADBAR) return("PnlFmncTolHeadbar");
	else if (ix == PNLFMNCTOLKSTEPPAR) return("PnlFmncTolKSteppar");
	else if (ix == PNLFMNCTOLKTOOLCHAR) return("PnlFmncTolKToolchar");
	else if (ix == PNLFMNCTOLLIST) return("PnlFmncTolList");
	else if (ix == PNLFMNCTOLMNFABUSER) return("PnlFmncTolMNFabuser");
	else if (ix == PNLFMNCTOLMNTOOLTYPE) return("PnlFmncTolMNTooltype");
	else if (ix == PNLFMNCTOLREC) return("PnlFmncTolRec");
	else if (ix == PNLFMNCTOLREF1NFILE) return("PnlFmncTolRef1NFile");
	else if (ix == PNLFMNCTOLRLV1NSTEP) return("PnlFmncTolRlv1NStep");
	else if (ix == PNLFMNCTOLSVCMNORG) return("PnlFmncTolSvcMNOrg");
	else if (ix == PNLFMNCTTYDETAIL) return("PnlFmncTtyDetail");
	else if (ix == PNLFMNCTTYHEADBAR) return("PnlFmncTtyHeadbar");
	else if (ix == PNLFMNCTTYKSTEPPAR) return("PnlFmncTtyKSteppar");
	else if (ix == PNLFMNCTTYKTOOLCHAR) return("PnlFmncTtyKToolchar");
	else if (ix == PNLFMNCTTYLIST) return("PnlFmncTtyList");
	else if (ix == PNLFMNCTTYMNTOOL) return("PnlFmncTtyMNTool");
	else if (ix == PNLFMNCTTYREC) return("PnlFmncTtyRec");
	else if (ix == PNLFMNCTTYRLV1NSTEP) return("PnlFmncTtyRlv1NStep");
	else if (ix == PNLFMNCTTYSUP1NTOOLTYPE) return("PnlFmncTtySup1NTooltype");
	else if (ix == PNLFMNCUSGAACCESS) return("PnlFmncUsgAAccess");
	else if (ix == PNLFMNCUSGDETAIL) return("PnlFmncUsgDetail");
	else if (ix == PNLFMNCUSGHEADBAR) return("PnlFmncUsgHeadbar");
	else if (ix == PNLFMNCUSGLIST) return("PnlFmncUsgList");
	else if (ix == PNLFMNCUSGMNUSER) return("PnlFmncUsgMNUser");
	else if (ix == PNLFMNCUSGREC) return("PnlFmncUsgRec");
	else if (ix == PNLFMNCUSR1NSESSION) return("PnlFmncUsr1NSession");
	else if (ix == PNLFMNCUSRAACCESS) return("PnlFmncUsrAAccess");
	else if (ix == PNLFMNCUSRDETAIL) return("PnlFmncUsrDetail");
	else if (ix == PNLFMNCUSRHEADBAR) return("PnlFmncUsrHeadbar");
	else if (ix == PNLFMNCUSRLIST) return("PnlFmncUsrList");
	else if (ix == PNLFMNCUSRMNUSERGROUP) return("PnlFmncUsrMNUsergroup");
	else if (ix == PNLFMNCUSRREC) return("PnlFmncUsrRec");
	else if (ix == QRYFMNCACT1NSTEP) return("QryFmncAct1NStep");
	else if (ix == QRYFMNCACTLIST) return("QryFmncActList");
	else if (ix == QRYFMNCADRLIST) return("QryFmncAdrList");
	else if (ix == QRYFMNCART1NSAMPLE) return("QryFmncArt1NSample");
	else if (ix == QRYFMNCART1NSTOCKITEM) return("QryFmncArt1NStockitem");
	else if (ix == QRYFMNCARTLIST) return("QryFmncArtList");
	else if (ix == QRYFMNCARTMNORG) return("QryFmncArtMNOrg");
	else if (ix == QRYFMNCARTREF1NFILE) return("QryFmncArtRef1NFile");
	else if (ix == QRYFMNCBILAPOS) return("QryFmncBilAPos");
	else if (ix == QRYFMNCBILLIST) return("QryFmncBilList");
	else if (ix == QRYFMNCFAB1NFABPROJECT) return("QryFmncFab1NFabproject");
	else if (ix == QRYFMNCFAB1NFABUSER) return("QryFmncFab1NFabuser");
	else if (ix == QRYFMNCFABFAB1NTOOL) return("QryFmncFabFab1NTool");
	else if (ix == QRYFMNCFABLIST) return("QryFmncFabList");
	else if (ix == QRYFMNCFABMNRUN) return("QryFmncFabMNRun");
	else if (ix == QRYFMNCFILLIST) return("QryFmncFilList");
	else if (ix == QRYFMNCFILMNSAMPLE) return("QryFmncFilMNSample");
	else if (ix == QRYFMNCFILMNSTEP) return("QryFmncFilMNStep");
	else if (ix == QRYFMNCFPJ1NBILL) return("QryFmncFpj1NBill");
	else if (ix == QRYFMNCFPJLIST) return("QryFmncFpjList");
	else if (ix == QRYFMNCFPJMNFABUSER) return("QryFmncFpjMNFabuser");
	else if (ix == QRYFMNCFUSLIST) return("QryFmncFusList");
	else if (ix == QRYFMNCFUSMNFABPROJECT) return("QryFmncFusMNFabproject");
	else if (ix == QRYFMNCFUSMNTOOL) return("QryFmncFusMNTool");
	else if (ix == QRYFMNCORG1NARTICLE) return("QryFmncOrg1NArticle");
	else if (ix == QRYFMNCORG1NSTOCKITEM) return("QryFmncOrg1NStockitem");
	else if (ix == QRYFMNCORGADETAIL) return("QryFmncOrgADetail");
	else if (ix == QRYFMNCORGBIO1NFABPROJECT) return("QryFmncOrgBio1NFabproject");
	else if (ix == QRYFMNCORGHK1NADDRESS) return("QryFmncOrgHk1NAddress");
	else if (ix == QRYFMNCORGKSTOCKLCN) return("QryFmncOrgKStocklcn");
	else if (ix == QRYFMNCORGLIST) return("QryFmncOrgList");
	else if (ix == QRYFMNCORGMNARTICLE) return("QryFmncOrgMNArticle");
	else if (ix == QRYFMNCORGMNF1NTOOL) return("QryFmncOrgMnf1NTool");
	else if (ix == QRYFMNCORGMNPERSON) return("QryFmncOrgMNPerson");
	else if (ix == QRYFMNCORGPCO1NPURCHORDER) return("QryFmncOrgPco1NPurchorder");
	else if (ix == QRYFMNCORGSPL1NPURCHORDER) return("QryFmncOrgSpl1NPurchorder");
	else if (ix == QRYFMNCORGSUP1NORG) return("QryFmncOrgSup1NOrg");
	else if (ix == QRYFMNCORGSVCMNTOOL) return("QryFmncOrgSvcMNTool");
	else if (ix == QRYFMNCPCOAPOS) return("QryFmncPcoAPos");
	else if (ix == QRYFMNCPCOLIST) return("QryFmncPcoList");
	else if (ix == QRYFMNCPRJ1NRUN) return("QryFmncPrj1NRun");
	else if (ix == QRYFMNCPRJLIST) return("QryFmncPrjList");
	else if (ix == QRYFMNCPRSADETAIL) return("QryFmncPrsADetail");
	else if (ix == QRYFMNCPRSHK1NADDRESS) return("QryFmncPrsHk1NAddress");
	else if (ix == QRYFMNCPRSLIST) return("QryFmncPrsList");
	else if (ix == QRYFMNCPRSMNORG) return("QryFmncPrsMNOrg");
	else if (ix == QRYFMNCPRSMNRUN) return("QryFmncPrsMNRun");
	else if (ix == QRYFMNCRUNLIST) return("QryFmncRunList");
	else if (ix == QRYFMNCRUNMNFAB) return("QryFmncRunMNFab");
	else if (ix == QRYFMNCRUNMNPERSON) return("QryFmncRunMNPerson");
	else if (ix == QRYFMNCRUNMNSAMPLE) return("QryFmncRunMNSample");
	else if (ix == QRYFMNCRUNREF1NFILE) return("QryFmncRunRef1NFile");
	else if (ix == QRYFMNCRUNRUN1NACTIVITY) return("QryFmncRunRun1NActivity");
	else if (ix == QRYFMNCSEPAPAR) return("QryFmncSepAPar");
	else if (ix == QRYFMNCSEPLIST) return("QryFmncSepList");
	else if (ix == QRYFMNCSEPMNFILE) return("QryFmncSepMNFile");
	else if (ix == QRYFMNCSEPMNSAMPLE) return("QryFmncSepMNSample");
	else if (ix == QRYFMNCSEPREF1NFILE) return("QryFmncSepRef1NFile");
	else if (ix == QRYFMNCSKILIST) return("QryFmncSkiList");
	else if (ix == QRYFMNCSMPAPAR) return("QryFmncSmpAPar");
	else if (ix == QRYFMNCSMPLIST) return("QryFmncSmpList");
	else if (ix == QRYFMNCSMPMNFILE) return("QryFmncSmpMNFile");
	else if (ix == QRYFMNCSMPMNRUN) return("QryFmncSmpMNRun");
	else if (ix == QRYFMNCSMPMNSTEP) return("QryFmncSmpMNStep");
	else if (ix == QRYFMNCSMPREF1NFILE) return("QryFmncSmpRef1NFile");
	else if (ix == QRYFMNCSMPSUP1NSAMPLE) return("QryFmncSmpSup1NSample");
	else if (ix == QRYFMNCSTPAPAR) return("QryFmncStpAPar");
	else if (ix == QRYFMNCSTPKSTEPPAR) return("QryFmncStpKSteppar");
	else if (ix == QRYFMNCSTPLIST) return("QryFmncStpList");
	else if (ix == QRYFMNCSTPMNFILE) return("QryFmncStpMNFile");
	else if (ix == QRYFMNCSTPREF1NFILE) return("QryFmncStpRef1NFile");
	else if (ix == QRYFMNCSTPTPL1NSTEP) return("QryFmncStpTpl1NStep");
	else if (ix == QRYFMNCTOL1NARTICLE) return("QryFmncTol1NArticle");
	else if (ix == QRYFMNCTOLAAVL) return("QryFmncTolAAvl");
	else if (ix == QRYFMNCTOLACHAR) return("QryFmncTolAChar");
	else if (ix == QRYFMNCTOLARES) return("QryFmncTolARes");
	else if (ix == QRYFMNCTOLAUTIL) return("QryFmncTolAUtil");
	else if (ix == QRYFMNCTOLKSTEPPAR) return("QryFmncTolKSteppar");
	else if (ix == QRYFMNCTOLKTOOLCHAR) return("QryFmncTolKToolchar");
	else if (ix == QRYFMNCTOLLIST) return("QryFmncTolList");
	else if (ix == QRYFMNCTOLMNFABUSER) return("QryFmncTolMNFabuser");
	else if (ix == QRYFMNCTOLMNTOOLTYPE) return("QryFmncTolMNTooltype");
	else if (ix == QRYFMNCTOLREF1NFILE) return("QryFmncTolRef1NFile");
	else if (ix == QRYFMNCTOLRLV1NSTEP) return("QryFmncTolRlv1NStep");
	else if (ix == QRYFMNCTOLSVCMNORG) return("QryFmncTolSvcMNOrg");
	else if (ix == QRYFMNCTTYKSTEPPAR) return("QryFmncTtyKSteppar");
	else if (ix == QRYFMNCTTYKTOOLCHAR) return("QryFmncTtyKToolchar");
	else if (ix == QRYFMNCTTYLIST) return("QryFmncTtyList");
	else if (ix == QRYFMNCTTYMNTOOL) return("QryFmncTtyMNTool");
	else if (ix == QRYFMNCTTYRLV1NSTEP) return("QryFmncTtyRlv1NStep");
	else if (ix == QRYFMNCTTYSUP1NTOOLTYPE) return("QryFmncTtySup1NTooltype");
	else if (ix == QRYFMNCUSGAACCESS) return("QryFmncUsgAAccess");
	else if (ix == QRYFMNCUSGLIST) return("QryFmncUsgList");
	else if (ix == QRYFMNCUSGMNUSER) return("QryFmncUsgMNUser");
	else if (ix == QRYFMNCUSR1NSESSION) return("QryFmncUsr1NSession");
	else if (ix == QRYFMNCUSRAACCESS) return("QryFmncUsrAAccess");
	else if (ix == QRYFMNCUSRLIST) return("QryFmncUsrList");
	else if (ix == QRYFMNCUSRMNUSERGROUP) return("QryFmncUsrMNUsergroup");
	else if (ix == ROOTFMNC) return("RootFmnc");
	else if (ix == SESSFMNC) return("SessFmnc");

	return("");
};

