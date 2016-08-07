/**
  * \file IexFmncIni.cpp
  * import/export handler for database DbsFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "IexFmncIni.h"

#include "IexFmncIni_blks.cpp"

/******************************************************************************
 class IexFmncIni
 ******************************************************************************/

IexFmncIni::IexFmncIni(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::IEXFMNCINI, jrefSup, ixFmncVLocale) {

	jref = xchg->addJob(this);
};

IexFmncIni::~IexFmncIni() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexFmncIni::reset() {
	imeiavcontrolpar.clear();
	imeiavkeylistkey1.clear();
	imeiavvaluelistval.clear();
	imeimtooltype.clear();
	imeimusergroup.clear();

	lineno = 0;
	impcnt = 0;
};

void IexFmncIni::import(
			DbsFmnc* dbsfmnc
		) {
	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMTooltype* tty = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMStep* ste = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMStepPar* steApar = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIAMPersonDetail* prsAdet = NULL;
	ImeitemIJAVKeylistKey3* kakJkey3 = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIMAddress* adr = NULL;

// IP import --- IBEGIN
	FmncRMUserMUsergroup uru;

	ImeitemIMTooltype* tty2 = NULL;

	string s;
// IP import --- IEND

// IP import.traverse --- RBEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		//ctlApar->ixFmncVControl: IXSREF
		//ctlApar->Par: TBL
		//ctlApar->Val: TBL

		dbsfmnc->tblfmncavcontrolpar->insertRec(ctlApar);
		impcnt++;
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0=0;ix0<imeiavkeylistkey1.nodes.size();ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];

		//klsAkey1->klsIxFmncVKeylist: IXSREF
		klsAkey1->klsNum = (ix0+1); // TBD
		klsAkey1->x1IxFmncVMaintable = VecFmncVMaintable::VOID;
		klsAkey1->Fixed = true;
		//klsAkey1->sref: TBL
		//klsAkey1->Avail: TBL
		//klsAkey1->Implied: TBL
		//klsAkey1->refJ: SUB

		dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey1);
		impcnt++;

		for (unsigned int ix1=0;ix1<klsAkey1->imeijavkeylistkey1.nodes.size();ix1++) {
			kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

			kakJkey1->refFmncAVKeylistKey = klsAkey1->ref;
			//kakJkey1->x1IxFmncVLocale: IXSREF
			//kakJkey1->Title: TBL
			//kakJkey1->Comment: TBL

			dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey1);
			impcnt++;
		};

		if (klsAkey1->imeijavkeylistkey1.nodes.size() > 0) {
			kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[0];

			klsAkey1->refJ = kakJkey1->ref;
			klsAkey1->Title = kakJkey1->Title;
			klsAkey1->Comment = kakJkey1->Comment;
			
			dbsfmnc->tblfmncavkeylistkey->updateRec(klsAkey1);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		//vlsAval->vlsIxFmncVValuelist: IXSREF
		//vlsAval->x1IxFmncVLocale: IXSREF
		//vlsAval->Val: TBL

		dbsfmnc->tblfmncavvaluelistval->insertRec(vlsAval);
		impcnt++;
	};

	// -- ImeIMTooltype
	for (unsigned int ix0=0;ix0<imeimtooltype.nodes.size();ix0++) {
		tty = imeimtooltype.nodes[ix0];

		//tty->supRefFmncMTooltype: PREVIMP
		for (unsigned int i=0;i<ix0;i++) {
			tty2 = imeimtooltype.nodes[i];

			s = tty2->sref;
			if (tty2->hsrefSupRefFmncMTooltype.length() > 0) s = tty2->hsrefSupRefFmncMTooltype + ";" + s;

			if (s == tty->hsrefSupRefFmncMTooltype) {
				tty->supRefFmncMTooltype = tty2->ref;
				break;
			};
		};			
		//tty->sref: TBL
		//tty->Title: TBL

		dbsfmnc->tblfmncmtooltype->insertRec(tty);
		impcnt++;

		for (unsigned int ix1=0;ix1<tty->imeiavkeylistkey2.nodes.size();ix1++) {
			klsAkey2 = tty->imeiavkeylistkey2.nodes[ix1];

			//klsAkey2->klsIxFmncVKeylist: IXSREF
      klsAkey2->klsNum = (ix1+1); // TBD
      klsAkey2->x1IxFmncVMaintable = VecFmncVMaintable::TBLFMNCMTOOLTYPE;
			klsAkey2->x1Uref = tty->ref;
			klsAkey2->Fixed = true;
			//klsAkey2->sref: TBL
			//klsAkey2->Avail: TBL
			//klsAkey2->Implied: TBL
			//klsAkey2->refJ: SUB

			dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey2);
			impcnt++;

			for (unsigned int ix2=0;ix2<klsAkey2->imeijavkeylistkey2.nodes.size();ix2++) {
				kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];

				kakJkey2->refFmncAVKeylistKey = klsAkey2->ref;
				//kakJkey2->x1IxFmncVLocale: IXSREF
				//kakJkey2->Title: TBL
				//kakJkey2->Comment: TBL

				dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey2);
				impcnt++;
			};

			if (klsAkey2->imeijavkeylistkey2.nodes.size() > 0) {
				kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[0];
				
				klsAkey2->refJ = kakJkey2->ref;
				klsAkey2->Title = kakJkey2->Title;
				klsAkey2->Comment = kakJkey2->Comment;
				
				dbsfmnc->tblfmncavkeylistkey->updateRec(klsAkey2);
			};
		};

		for (unsigned int ix1=0;ix1<tty->imeimstep.nodes.size();ix1++) {
			ste = tty->imeimstep.nodes[ix1];

			ste->rlvIxVTbl = VecFmncVMStepRlvTbl::TTY;
			ste->rlvUref = tty->ref;
			//ste->ixWFilecfg: IXSREF
			//ste->Title: TBL

			dbsfmnc->tblfmncmstep->insertRec(ste);
			impcnt++;

			for (unsigned int ix2=0;ix2<ste->imeiamsteppar.nodes.size();ix2++) {
				steApar = ste->imeiamsteppar.nodes[ix2];

				steApar->refFmncMStep = ste->ref;
				//steApar->x1OsrefFmncKSteppar: TBL
				steApar->x2IxVTbl = VecFmncVAMStepParTbl::VOID;
				//steApar->Val: TBL
				//steApar->Comment: TBL

				dbsfmnc->tblfmncamsteppar->insertRec(steApar);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<ste->imeiavkeylistkey3.nodes.size();ix2++) {
				klsAkey3 = ste->imeiavkeylistkey3.nodes[ix2];

				klsAkey3->klsIxFmncVKeylist = VecFmncVKeylist::KLSTFMNCKSTEPPAR;
				klsAkey3->klsNum = (ix2+1); // TBD
				klsAkey3->x1IxFmncVMaintable = VecFmncVMaintable::TBLFMNCMSTEP;
				klsAkey3->x1Uref = ste->ref;
				klsAkey3->Fixed = true;
				//klsAkey3->sref: TBL
				//klsAkey3->Avail: TBL
				//klsAkey3->Implied: TBL
				//klsAkey3->refJ: SUB

				dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey3);
				impcnt++;

				for (unsigned int ix3=0;ix3<klsAkey3->imeijavkeylistkey3.nodes.size();ix3++) {
					kakJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix3];

					kakJkey3->refFmncAVKeylistKey = klsAkey3->ref;
					//kakJkey3->x1IxFmncVLocale: IXSREF
					//kakJkey3->Title: TBL
					//kakJkey3->Comment: TBL

					dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey3);
					impcnt++;
				};

				if (klsAkey3->imeijavkeylistkey3.nodes.size() > 0) {
					kakJkey3 = klsAkey3->imeijavkeylistkey3.nodes[0];
					
					klsAkey3->refJ = kakJkey3->ref;
					klsAkey3->Title = kakJkey3->Title;
					klsAkey3->Comment = kakJkey3->Comment;
					
					dbsfmnc->tblfmncavkeylistkey->updateRec(klsAkey3);
				};
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		//usg->sref: TBL
		//usg->Comment: TBL

		dbsfmnc->tblfmncmusergroup->insertRec(usg);
		impcnt++;

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			usgAacc->refFmncMUsergroup = usg->ref;
			//usgAacc->x1IxFmncVCard: IXSREF
			//usgAacc->ixFmncWUiaccess: IXSREF

			dbsfmnc->tblfmncamusergroupaccess->insertRec(usgAacc);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			//usr->refRUsergroup: IMPPP
			usr->refFmncMUsergroup = usg->ref;
			//usr->refFmncMPerson: SUB
			//usr->sref: TBL
			//usr->refJState: SUB
			//usr->ixFmncVLocale: IXSREF
			//usr->ixFmncVUserlevel: IXSREF
			//usr->Password: TBL

			dbsfmnc->tblfmncmuser->insertRec(usr);
			impcnt++;

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				usrJste->refFmncMUser = usr->ref;
				//usrJste->ixVState: IXSREF

				dbsfmnc->tblfmncjmuserstate->insertRec(usrJste);
				impcnt++;
			};

			if (usr->imeijmuserstate.nodes.size() > 0) {
				usrJste = usr->imeijmuserstate.nodes[0];

				usr->refJState = usrJste->ref;
				usr->ixVState = usrJste->ixVState;
			
				dbsfmnc->tblfmncmuser->updateRec(usr);
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				prs->ixWDerivate = VecFmncWMPersonDerivate::USR;
				//prs->refFmncMAddress: SUB
				//prs->ixVSex: IXSREF
				//prs->Title: TBL
				//prs->Firstname: TBL
				//prs->refJLastname: SUB
				//prs->telRefADetail: SUB
				//prs->emlRefADetail: SUB

				dbsfmnc->tblfmncmperson->insertRec(prs);
				impcnt++;

				for (unsigned int ix3=0;ix3<prs->imeiampersondetail.nodes.size();ix3++) {
					prsAdet = prs->imeiampersondetail.nodes[ix3];

					prsAdet->refFmncMPerson = prs->ref;
					//prsAdet->x1SrefKType: TBL
					//prsAdet->Val: TBL

					dbsfmnc->tblfmncampersondetail->insertRec(prsAdet);
					impcnt++;
					
					if (prsAdet->x1SrefKType == "tel") {
						prs->telRefADetail = prsAdet->ref;
						prs->Tel = prsAdet->Val;

						dbsfmnc->tblfmncmperson->updateRec(prs);

					} else if (prsAdet->x1SrefKType == "eml") {
						prs->emlRefADetail = prsAdet->ref;
						prs->Eml = prsAdet->Val;

						dbsfmnc->tblfmncmperson->updateRec(prs);
					};
				};

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					prsJlnm->refFmncMPerson = prs->ref;
					//prsJlnm->Lastname: TBL

					dbsfmnc->tblfmncjmpersonlastname->insertRec(prsJlnm);
					impcnt++;
				};

				if (prs->imeijmpersonlastname.nodes.size() > 0) {
					prsJlnm = prs->imeijmpersonlastname.nodes[0];

					prs->refJLastname = prsJlnm->ref;
					prs->Lastname = prsJlnm->Lastname;
					
					dbsfmnc->tblfmncmperson->updateRec(prs);
				};

				for (unsigned int ix3=0;ix3<prs->imeimaddress.nodes.size();ix3++) {
					adr = prs->imeimaddress.nodes[ix3];

					adr->hkIxVTbl = VecFmncVMAddressHkTbl::PRS;
					adr->hkUref = prs->ref;
					//adr->srefKAdrtype: TBL
					//adr->Address1: TBL
					//adr->Address2: TBL
					//adr->Zipcode: TBL
					//adr->City: TBL
					//adr->State: TBL
					//adr->srefKCountry: 

					dbsfmnc->tblfmncmaddress->insertRec(adr);
					impcnt++;
				};

				if (prs->imeimaddress.nodes.size() > 0) {
					adr = prs->imeimaddress.nodes[0];

					prs->refFmncMAddress = adr->ref;
					
					dbsfmnc->tblfmncmperson->updateRec(prs);
				};
			};

			if (usr->imeimperson.nodes.size() > 0) {
				prs = usr->imeimperson.nodes[0];

				usr->refFmncMPerson = prs->ref;

				dbsfmnc->tblfmncmuser->updateRec(usr);
			};

			uru.refFmncMUser = usr->ref;
			uru.refFmncMUsergroup = usg->ref;
			uru.ixFmncVUserlevel = usr->ixFmncVUserlevel;
			dbsfmnc->tblfmncrmusermusergroup->insertRec(&uru);

			usr->refRUsergroup = uru.ref;
			dbsfmnc->tblfmncmuser->updateRec(usr);
		};
	};
// IP import.traverse --- REND

// IP import.ppr --- INSERT
};

void IexFmncIni::collect(
			DbsFmnc* dbsfmnc
			, const map<uint,uint>& icsFmncVIop
		) {
	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMTooltype* tty = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMStep* ste = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMStepPar* steApar = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIAMPersonDetail* prsAdet = NULL;
	ImeitemIJAVKeylistKey3* kakJkey3 = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIMAddress* adr = NULL;

	uint ixFmncVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

// IP collect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0=0;ix0<imeiavkeylistkey1.nodes.size();ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];

		if (klsAkey1->ref != 0) {
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY1, ixFmncVIop)) {
			dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey1->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey1->refJ) {refs[i] = refs[0]; refs[0] = klsAkey1->refJ; break;};
			for (unsigned int i=0;i<refs.size();i++) klsAkey1->imeijavkeylistkey1.nodes.push_back(new ImeitemIJAVKeylistKey1(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<klsAkey1->imeijavkeylistkey1.nodes.size();ix1++) {
			kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

			if (kakJkey1->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMTooltype
	for (unsigned int ix0=0;ix0<imeimtooltype.nodes.size();ix0++) {
		tty = imeimtooltype.nodes[ix0];

		if (tty->ref != 0) {
			tty->hsrefSupRefFmncMTooltype = StubFmnc::getStubTtyStd(dbsfmnc, tty->supRefFmncMTooltype, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAVKEYLISTKEY2, ixFmncVIop)) {
			dbsfmnc->tblfmncavkeylistkey->loadRefsByMtbUrf(VecFmncVMaintable::TBLFMNCMTOOLTYPE, tty->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tty->imeiavkeylistkey2.nodes.push_back(new ImeitemIAVKeylistKey2(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tty->imeiavkeylistkey2.nodes.size();ix1++) {
			klsAkey2 = tty->imeiavkeylistkey2.nodes[ix1];

			if (klsAkey2->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY2, ixFmncVIop)) {
				dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey2->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey2->refJ) {refs[i] = refs[0]; refs[0] = klsAkey2->refJ; break;};
				for (unsigned int i=0;i<refs.size();i++) klsAkey2->imeijavkeylistkey2.nodes.push_back(new ImeitemIJAVKeylistKey2(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<klsAkey2->imeijavkeylistkey2.nodes.size();ix2++) {
				kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];

				if (kakJkey2->ref != 0) {
				};
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMSTEP, ixFmncVIop)) {
			dbsfmnc->tblfmncmstep->loadRefsByRltRlu(VecFmncVMStepRlvTbl::TTY, tty->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) tty->imeimstep.nodes.push_back(new ImeitemIMStep(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<tty->imeimstep.nodes.size();ix1++) {
			ste = tty->imeimstep.nodes[ix1];

			if (ste->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMSTEPPAR, ixFmncVIop)) {
				dbsfmnc->tblfmncamsteppar->loadRefsBySte(ste->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) ste->imeiamsteppar.nodes.push_back(new ImeitemIAMStepPar(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<ste->imeiamsteppar.nodes.size();ix2++) {
				steApar = ste->imeiamsteppar.nodes[ix2];

				if (steApar->ref != 0) {
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAVKEYLISTKEY3, ixFmncVIop)) {
				dbsfmnc->tblfmncavkeylistkey->loadRefsByMtbUrf(VecFmncVMaintable::TBLFMNCMSTEP, ste->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) ste->imeiavkeylistkey3.nodes.push_back(new ImeitemIAVKeylistKey3(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<ste->imeiavkeylistkey3.nodes.size();ix2++) {
				klsAkey3 = ste->imeiavkeylistkey3.nodes[ix2];

				if (klsAkey3->ref != 0) {
				};

				if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY3, ixFmncVIop)) {
					dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey3->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey3->refJ) {refs[i] = refs[0]; refs[0] = klsAkey3->refJ; break;};
					for (unsigned int i=0;i<refs.size();i++) klsAkey3->imeijavkeylistkey3.nodes.push_back(new ImeitemIJAVKeylistKey3(dbsfmnc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<klsAkey3->imeijavkeylistkey3.nodes.size();ix3++) {
					kakJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix3];

					if (kakJkey3->ref != 0) {
					};
				};
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixFmncVIop)) {
			dbsfmnc->tblfmncamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMUSERSTATE, ixFmncVIop)) {
				dbsfmnc->tblfmncjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i=0;i<refs.size();i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMPERSONDETAIL, ixFmncVIop)) {
					dbsfmnc->tblfmncampersondetail->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) prs->imeiampersondetail.nodes.push_back(new ImeitemIAMPersonDetail(dbsfmnc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<prs->imeiampersondetail.nodes.size();ix3++) {
					prsAdet = prs->imeiampersondetail.nodes[ix3];

					if (prsAdet->ref != 0) {
					};
				};

				if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMPERSONLASTNAME, ixFmncVIop)) {
					dbsfmnc->tblfmncjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i=0;i<refs.size();i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbsfmnc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};

				if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMADDRESS, ixFmncVIop)) {
					dbsfmnc->tblfmncmaddress->loadRefsByHktHku(VecFmncVMAddressHkTbl::PRS, prs->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) prs->imeimaddress.nodes.push_back(new ImeitemIMAddress(dbsfmnc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<prs->imeimaddress.nodes.size();ix3++) {
					adr = prs->imeimaddress.nodes[ix3];

					if (adr->ref != 0) {
					};
				};
			};
		};
	};
// IP collect.traverse --- END

// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexFmncIni::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) {
				parseok = imeiavcontrolpar.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1) {
				parseok = imeiavkeylistkey1.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) {
				parseok = imeiavvaluelistval.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMTOOLTYPE) {
				parseok = imeimtooltype.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) {
				parseok = imeimusergroup.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexFmncIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexFmncIni");

	if (basefound) {
		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey1.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimtooltype.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);
	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey1 = ImeIAVKeylistKey1();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimtooltype = ImeIMTooltype();
		imeimusergroup = ImeIMUsergroup();
	};
};

bool IexFmncIni::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexFmncIni::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexFmncIni::writeTxt(
			fstream& outfile
		) {
	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey1.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimtooltype.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexFmncIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexFmncIni");
		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey1.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimtooltype.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexFmncIni::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexFmncIni::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexFmncIni::icsFmncVIopInsAll() {
	return {{(uint)VecVIme::IMEIAVCONTROLPAR,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY1,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecFmncVIop::INS},{(uint)VecVIme::IMEIMTOOLTYPE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY2,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY1,VecFmncVIop::INS},{(uint)VecVIme::IMEIMSTEP,VecFmncVIop::INS},{(uint)VecVIme::IMEIMUSER,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMSTEPPAR,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY3,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY2,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMPERSONDETAIL,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY3,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecFmncVIop::INS},{(uint)VecVIme::IMEIMADDRESS,VecFmncVIop::INS}};
};

uint IexFmncIni::getIxFmncVIop(
			const map<uint,uint>& icsFmncVIop
			, const uint ixVIme
			, uint& ixFmncVIop
		) {
	ixFmncVIop = 0;

	auto it = icsFmncVIop.find(ixVIme);
	if (it != icsFmncVIop.end()) ixFmncVIop = it->second;

	return ixFmncVIop;
};

void IexFmncIni::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexFmncIni::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
};


