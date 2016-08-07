/**
  * \file SessFmnc.cpp
  * job handler for job SessFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "SessFmnc.h"

// IP blksInclude --- BEGIN
#include "SessFmnc_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class SessFmnc
 ******************************************************************************/

SessFmnc::SessFmnc(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const ubigint refFmncMUser
			, const string& ip
		) : JobFmnc(xchg, VecFmncVJob::SESSFMNC, jrefSup) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	crdnav = NULL;

// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	FmncMUser* usr = NULL;

	bool adm;

	ListFmncRMUserMUsergroup urus;
	FmncRMUserMUsergroup* uru = NULL;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbsfmnc->tblfmncmsession->insertNewRec(NULL, refFmncMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecFmncVPreset::PREFMNCSESS, jref, refSes);
	xchg->addTxtvalPreset(VecFmncVPreset::PREFMNCIP, jref, ip);

	// set locale and presetings corresponding to user
	dbsfmnc->tblfmncmuser->loadRecByRef(refFmncMUser, &usr);

	ixFmncVLocale = usr->ixFmncVLocale;
	adm = (usr->ixFmncVUserlevel == VecFmncVUserlevel::ADM);

	xchg->addBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref, adm);

	xchg->addRefPreset(VecFmncVPreset::PREFMNCGRP, jref, usr->refFmncMUsergroup);
	xchg->addRefPreset(VecFmncVPreset::PREFMNCOWN, jref, refFmncMUser);

	delete usr;

	// set jrefSess locale (for access to FmncQSelect from rst-type panel queries)
	xchg->addRefPreset(VecFmncVPreset::PREFMNCJREFSESS, jref, jref);

	// fill query in FmncQSelect with all applicable user groups
	dbsfmnc->tblfmncqselect->insertNewRec(NULL, jref, 1, 0, 0);

	if (usr->ixFmncVUserlevel == VecFmncVUserlevel::ADM) {
		dbsfmnc->loadRefsBySQL("SELECT ref FROM TblFmncMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i=0;i<refs.size();i++) dbsfmnc->tblfmncqselect->insertNewRec(NULL, jref, i+2, 0, refs[i]);

	} else {
		dbsfmnc->tblfmncrmusermusergroup->loadRstByUsr(refFmncMUser, false, urus);

		for (unsigned int i=0;i<urus.nodes.size();i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refFmncMUsergroup] = uru->ixFmncVUserlevel;
			dbsfmnc->tblfmncqselect->insertNewRec(NULL, jref, i+2, 0, uru->refFmncMUsergroup);
		};
	};

	// determine UI access rights for each card
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACUSG, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCUSG, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACUSR, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCUSR, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCORG, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCPRS, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCADR, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCFIL, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACSTP, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCSTP, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCPRJ, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCRUN, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCACT, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCSEP, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCSMP, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCFAB, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACFUS, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCFUS, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCTTY, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCTOL, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCFPJ, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCBIL, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCART, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCSKI, adm, urus, refFmncMUser));
	xchg->addIxPreset(VecFmncVPreset::PREFMNCIXUACPCO, jref, getIxUac(dbsfmnc, VecFmncVCard::CRDFMNCPCO, adm, urus, refFmncMUser));

	crdnav = new CrdFmncNav(xchg, dbsfmnc, jref, ixFmncVLocale);

// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecFmncVCall::CALLFMNCACCESS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCDESCR, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCLOG, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCSCR, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

SessFmnc::~SessFmnc() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
uint SessFmnc::checkCrdActive(
			const uint ixFmncVCard
		) {
	if (ixFmncVCard == VecFmncVCard::CRDFMNCACT) return evalCrdactActive();
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSEP) return evalCrdsepActive();
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFUS) return evalCrdfusActive();
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCTOL) return evalCrdtolActive();
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFPJ) return evalCrdfpjActive();
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCBIL) return evalCrdbilActive();

	return 0;
};

uint SessFmnc::evalCrdactActive() {
	// pre.refRun()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref)) ? VecFmncVPreset::PREFMNCREFRUN : 0);

	return(args.back());
};

uint SessFmnc::evalCrdsepActive() {
	// pre.refRun()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref)) ? VecFmncVPreset::PREFMNCREFRUN : 0);

	return(args.back());
};

uint SessFmnc::evalCrdfusActive() {
	// pre.refFab()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref)) ? VecFmncVPreset::PREFMNCREFFAB : 0);

	return(args.back());
};

uint SessFmnc::evalCrdtolActive() {
	// pre.refFab()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref)) ? VecFmncVPreset::PREFMNCREFFAB : 0);

	return(args.back());
};

uint SessFmnc::evalCrdfpjActive() {
	// pre.refFab()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref)) ? VecFmncVPreset::PREFMNCREFFAB : 0);

	return(args.back());
};

uint SessFmnc::evalCrdbilActive() {
	// pre.refFab()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref)) ? VecFmncVPreset::PREFMNCREFFAB : 0);

	return(args.back());
};

uint SessFmnc::checkUiaccess(
			const uint ixFmncVCard
		) {
	if (ixFmncVCard == VecFmncVCard::CRDFMNCUSG) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSG, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCUSR) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSR, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCORG) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCPRS) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCADR) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFIL) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSTP) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSTP, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCPRJ) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCRUN) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCACT) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSEP) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSMP) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFAB) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFUS) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFUS, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCTTY) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCTOL) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFPJ) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCBIL) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCART) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSKI) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref);
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCPCO) return xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPCO, jref);

	return 0;
};

uint SessFmnc::getIxUac(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCard
			, const bool adm
			, ListFmncRMUserMUsergroup& urus
			, const ubigint refFmncMUser
		) {
	uint retval = 0;

	FmncRMUserMUsergroup* uru = NULL;
	FmncAMUsergroupAccess* usgAacc = NULL;
	FmncAMUserAccess* usrAacc = NULL;

	if (adm) {
		retval = VecFmncWUiaccess::EDIT + VecFmncWUiaccess::EXEC + VecFmncWUiaccess::VIEW;

	} else {
		for (unsigned int i=0;i<urus.nodes.size();i++) {
			uru = urus.nodes[i];

			if (dbsfmnc->tblfmncamusergroupaccess->loadRecBySQL("SELECT * FROM TblFmncAMUsergroupAccess WHERE refFmncMUsergroup = " + to_string(uru->refFmncMUsergroup) + " AND x1IxFmncVCard = " + to_string(ixFmncVCard), &usgAacc)) {
				retval |= usgAacc->ixFmncWUiaccess;
				delete usgAacc;
			};
		};

		if (dbsfmnc->tblfmncamuseraccess->loadRecBySQL("SELECT * FROM TblFmncAMUserAccess WHERE refFmncMUser = " + to_string(refFmncMUser) + " AND x1IxFmncVCard = " + to_string(ixFmncVCard), &usrAacc)) {
			retval = usrAacc->ixFmncWUiaccess;
			delete usrAacc;
		};
	};

	return retval;
};

uint SessFmnc::checkAccess(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCard
			, const ubigint ref
		) {
	uint retval = VecFmncVAccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refFmncMUser;
	uint ixFmncVMaintable;

	FmncAccRMUserUniversal* ausrRunv = NULL;
	FmncRMUsergroupUniversal* usgRunv = NULL;

	ixFmncVMaintable = crdToMtb(ixFmncVCard);

	if (ixFmncVMaintable == VecFmncVMaintable::VOID) {
		retval = VecFmncVAccess::FULL;

	} else if (hasGrpown(ixFmncVMaintable)) {
		// find record's group and owner
		dbsfmnc->loadUbigintBySQL("SELECT grp FROM " + VecFmncVMaintable::getSref(ixFmncVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbsfmnc->loadUbigintBySQL("SELECT own FROM " + VecFmncVMaintable::getSref(ixFmncVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref)) retval = VecFmncVAccess::FULL;

		// all non-administrators can view user group non-specific records but not edit them
		if (retval == VecFmncVAccess::NONE) {
			if (grp == 0) retval = VecFmncVAccess::VIEW;
		};

		if (retval == VecFmncVAccess::NONE) {
			refFmncMUser = xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref);

			// a record's owner has full rights on his records
			if (refFmncMUser == own) retval = VecFmncVAccess::FULL;

			if (retval == VecFmncVAccess::NONE) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecFmncVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecFmncVAccess::FULL;
					} else {
						// other group members have view access only
						retval = VecFmncVAccess::VIEW;
					};
				};
			};

			if (retval != VecFmncVAccess::FULL) {
				// individual record access right
				if (dbsfmnc->tblfmncaccrmuseruniversal->loadRecByUsrMtbUnv(refFmncMUser, ixFmncVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixFmncVAccess;
					delete ausrRunv;
				};
			};

			if (retval != VecFmncVAccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin() ; it != usgaccs.end() ; it++) {

					if (dbsfmnc->tblfmncrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixFmncVMaintable, ref, &usgRunv)) {
						if (retval == VecFmncVAccess::VIEW) {
							if (usgRunv->ixFmncVAccess == VecFmncVAccess::FULL) retval = VecFmncVAccess::FULL;
						} else {
							retval = usgRunv->ixFmncVAccess;
						};

						delete usgRunv;
					};

					if (retval == VecFmncVAccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref)) retval = VecFmncVAccess::FULL;
		else retval = VecFmncVAccess::VIEW;
	};

	return retval;
};

void SessFmnc::logAccess(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint preUref
			, const uint ixFmncVCard
			, const ubigint unvUref
		) {
	ubigint refFmncMUser;
	uint unvIxFmncVMaintable;
	uint preIxFmncVMaintable;

	FmncHistRMUserUniversal* husrRunv = NULL;

	refFmncMUser = xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref);
	unvIxFmncVMaintable = crdToMtb(ixFmncVCard);
	preIxFmncVMaintable = preToMtb(ixFmncVPreset);

	if (!dbsfmnc->tblfmnchistrmuseruniversal->loadRecBySQL("SELECT * FROM TblFmncHistRMUserUniversal WHERE refFmncMUser = " + to_string(refFmncMUser)
				+ " AND unvIxFmncVMaintable = " + to_string(unvIxFmncVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixFmncVCard = " + to_string(ixFmncVCard), &husrRunv)) {
		husrRunv = new FmncHistRMUserUniversal(0, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, 0);
	};

	husrRunv->start = time(NULL);

	if (husrRunv->ref == 0) dbsfmnc->tblfmnchistrmuseruniversal->insertRec(husrRunv);
	else dbsfmnc->tblfmnchistrmuseruniversal->updateRec(husrRunv);

	xchg->triggerIxRefCall(dbsfmnc, VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, ixFmncVCard, refFmncMUser);

	delete husrRunv;
};

uint SessFmnc::crdToMtb(
			const uint ixFmncVCard
		) {
	if (ixFmncVCard == VecFmncVCard::CRDFMNCUSG) return VecFmncVMaintable::TBLFMNCMUSERGROUP;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCUSR) return VecFmncVMaintable::TBLFMNCMUSER;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCORG) return VecFmncVMaintable::TBLFMNCMORG;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCPRS) return VecFmncVMaintable::TBLFMNCMPERSON;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCADR) return VecFmncVMaintable::TBLFMNCMADDRESS;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFIL) return VecFmncVMaintable::TBLFMNCMFILE;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSTP) return VecFmncVMaintable::TBLFMNCMSTEP;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCPRJ) return VecFmncVMaintable::TBLFMNCMPROJECT;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCRUN) return VecFmncVMaintable::TBLFMNCMRUN;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCACT) return VecFmncVMaintable::TBLFMNCMACTIVITY;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSEP) return VecFmncVMaintable::TBLFMNCMSTEP;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSMP) return VecFmncVMaintable::TBLFMNCMSAMPLE;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFAB) return VecFmncVMaintable::TBLFMNCMFAB;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFUS) return VecFmncVMaintable::TBLFMNCMFABUSER;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCTTY) return VecFmncVMaintable::TBLFMNCMTOOLTYPE;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCTOL) return VecFmncVMaintable::TBLFMNCMTOOL;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCFPJ) return VecFmncVMaintable::TBLFMNCMFABPROJECT;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCBIL) return VecFmncVMaintable::TBLFMNCMBILL;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCART) return VecFmncVMaintable::TBLFMNCMARTICLE;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCSKI) return VecFmncVMaintable::TBLFMNCMSTOCKITEM;
	else if (ixFmncVCard == VecFmncVCard::CRDFMNCPCO) return VecFmncVMaintable::TBLFMNCMPURCHORDER;

	return VecFmncVMaintable::VOID;
};

uint SessFmnc::preToMtb(
			const uint ixFmncVPreset
		) {
	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFACT) return VecFmncVMaintable::TBLFMNCMACTIVITY;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFADR) return VecFmncVMaintable::TBLFMNCMADDRESS;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFART) return VecFmncVMaintable::TBLFMNCMARTICLE;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFBIL) return VecFmncVMaintable::TBLFMNCMBILL;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFAB) return VecFmncVMaintable::TBLFMNCMFAB;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFIL) return VecFmncVMaintable::TBLFMNCMFILE;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFPJ) return VecFmncVMaintable::TBLFMNCMFABPROJECT;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFUS) return VecFmncVMaintable::TBLFMNCMFABUSER;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFORG) return VecFmncVMaintable::TBLFMNCMORG;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFPCO) return VecFmncVMaintable::TBLFMNCMPURCHORDER;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFPRJ) return VecFmncVMaintable::TBLFMNCMPROJECT;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFPRS) return VecFmncVMaintable::TBLFMNCMPERSON;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFRUN) return VecFmncVMaintable::TBLFMNCMRUN;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSEP) return VecFmncVMaintable::TBLFMNCMSTEP;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSES) return VecFmncVMaintable::TBLFMNCMSESSION;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSKI) return VecFmncVMaintable::TBLFMNCMSTOCKITEM;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSMP) return VecFmncVMaintable::TBLFMNCMSAMPLE;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSTE) return VecFmncVMaintable::TBLFMNCMSTEP;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSTP) return VecFmncVMaintable::TBLFMNCMSTEP;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFTOL) return VecFmncVMaintable::TBLFMNCMTOOL;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFTTY) return VecFmncVMaintable::TBLFMNCMTOOLTYPE;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFUSG) return VecFmncVMaintable::TBLFMNCMUSERGROUP;
	else if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFUSR) return VecFmncVMaintable::TBLFMNCMUSER;

	return VecFmncVMaintable::VOID;
};

bool SessFmnc::hasActive(
			const uint ixFmncVCard
		) {
	return((ixFmncVCard == VecFmncVCard::CRDFMNCACT) || (ixFmncVCard == VecFmncVCard::CRDFMNCSEP) || (ixFmncVCard == VecFmncVCard::CRDFMNCFUS) || (ixFmncVCard == VecFmncVCard::CRDFMNCTOL) || (ixFmncVCard == VecFmncVCard::CRDFMNCFPJ) || (ixFmncVCard == VecFmncVCard::CRDFMNCBIL));
};

bool SessFmnc::hasGrpown(
			const uint ixFmncVMaintable
		) {
	return((ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMACTIVITY) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMADDRESS) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMARTICLE) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMBILL) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMFAB) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMFABPROJECT) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMFABUSER) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMFILE) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMPERSON) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMPROJECT) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMPURCHORDER) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMRUN) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMSAMPLE) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMSTEP) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMSTOCKITEM) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMTOOL) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMTOOLTYPE) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMUSER) || (ixFmncVMaintable == VecFmncVMaintable::TBLFMNCMUSERGROUP));
};

void SessFmnc::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\tcreateCrdact" << endl;
			cout << "\tcreateCrdadr" << endl;
			cout << "\tcreateCrdart" << endl;
			cout << "\tcreateCrdbil" << endl;
			cout << "\tcreateCrdfab" << endl;
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdfpj" << endl;
			cout << "\tcreateCrdfus" << endl;
			cout << "\tcreateCrdorg" << endl;
			cout << "\tcreateCrdpco" << endl;
			cout << "\tcreateCrdprj" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdrun" << endl;
			cout << "\tcreateCrdsep" << endl;
			cout << "\tcreateCrdski" << endl;
			cout << "\tcreateCrdsmp" << endl;
			cout << "\tcreateCrdstp" << endl;
			cout << "\tcreateCrdtol" << endl;
			cout << "\tcreateCrdtty" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\teraseCrdact" << endl;
			cout << "\teraseCrdadr" << endl;
			cout << "\teraseCrdart" << endl;
			cout << "\teraseCrdbil" << endl;
			cout << "\teraseCrdfab" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdfpj" << endl;
			cout << "\teraseCrdfus" << endl;
			cout << "\teraseCrdorg" << endl;
			cout << "\teraseCrdpco" << endl;
			cout << "\teraseCrdprj" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdrun" << endl;
			cout << "\teraseCrdsep" << endl;
			cout << "\teraseCrdski" << endl;
			cout << "\teraseCrdsmp" << endl;
			cout << "\teraseCrdstp" << endl;
			cout << "\teraseCrdtol" << endl;
			cout << "\teraseCrdtty" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
		} else if (req->cmd == "createCrdact") {
			req->retain = handleCreateCrdact(dbsfmnc);

		} else if (req->cmd == "createCrdadr") {
			req->retain = handleCreateCrdadr(dbsfmnc);

		} else if (req->cmd == "createCrdart") {
			req->retain = handleCreateCrdart(dbsfmnc);

		} else if (req->cmd == "createCrdbil") {
			req->retain = handleCreateCrdbil(dbsfmnc);

		} else if (req->cmd == "createCrdfab") {
			req->retain = handleCreateCrdfab(dbsfmnc);

		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbsfmnc);

		} else if (req->cmd == "createCrdfpj") {
			req->retain = handleCreateCrdfpj(dbsfmnc);

		} else if (req->cmd == "createCrdfus") {
			req->retain = handleCreateCrdfus(dbsfmnc);

		} else if (req->cmd == "createCrdorg") {
			req->retain = handleCreateCrdorg(dbsfmnc);

		} else if (req->cmd == "createCrdpco") {
			req->retain = handleCreateCrdpco(dbsfmnc);

		} else if (req->cmd == "createCrdprj") {
			req->retain = handleCreateCrdprj(dbsfmnc);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbsfmnc);

		} else if (req->cmd == "createCrdrun") {
			req->retain = handleCreateCrdrun(dbsfmnc);

		} else if (req->cmd == "createCrdsep") {
			req->retain = handleCreateCrdsep(dbsfmnc);

		} else if (req->cmd == "createCrdski") {
			req->retain = handleCreateCrdski(dbsfmnc);

		} else if (req->cmd == "createCrdsmp") {
			req->retain = handleCreateCrdsmp(dbsfmnc);

		} else if (req->cmd == "createCrdstp") {
			req->retain = handleCreateCrdstp(dbsfmnc);

		} else if (req->cmd == "createCrdtol") {
			req->retain = handleCreateCrdtol(dbsfmnc);

		} else if (req->cmd == "createCrdtty") {
			req->retain = handleCreateCrdtty(dbsfmnc);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbsfmnc);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbsfmnc);

		} else if (req->cmd == "eraseCrdact") {
			req->retain = handleEraseCrdact(dbsfmnc);

		} else if (req->cmd == "eraseCrdadr") {
			req->retain = handleEraseCrdadr(dbsfmnc);

		} else if (req->cmd == "eraseCrdart") {
			req->retain = handleEraseCrdart(dbsfmnc);

		} else if (req->cmd == "eraseCrdbil") {
			req->retain = handleEraseCrdbil(dbsfmnc);

		} else if (req->cmd == "eraseCrdfab") {
			req->retain = handleEraseCrdfab(dbsfmnc);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbsfmnc);

		} else if (req->cmd == "eraseCrdfpj") {
			req->retain = handleEraseCrdfpj(dbsfmnc);

		} else if (req->cmd == "eraseCrdfus") {
			req->retain = handleEraseCrdfus(dbsfmnc);

		} else if (req->cmd == "eraseCrdorg") {
			req->retain = handleEraseCrdorg(dbsfmnc);

		} else if (req->cmd == "eraseCrdpco") {
			req->retain = handleEraseCrdpco(dbsfmnc);

		} else if (req->cmd == "eraseCrdprj") {
			req->retain = handleEraseCrdprj(dbsfmnc);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbsfmnc);

		} else if (req->cmd == "eraseCrdrun") {
			req->retain = handleEraseCrdrun(dbsfmnc);

		} else if (req->cmd == "eraseCrdsep") {
			req->retain = handleEraseCrdsep(dbsfmnc);

		} else if (req->cmd == "eraseCrdski") {
			req->retain = handleEraseCrdski(dbsfmnc);

		} else if (req->cmd == "eraseCrdsmp") {
			req->retain = handleEraseCrdsmp(dbsfmnc);

		} else if (req->cmd == "eraseCrdstp") {
			req->retain = handleEraseCrdstp(dbsfmnc);

		} else if (req->cmd == "eraseCrdtol") {
			req->retain = handleEraseCrdtol(dbsfmnc);

		} else if (req->cmd == "eraseCrdtty") {
			req->retain = handleEraseCrdtty(dbsfmnc);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbsfmnc);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbsfmnc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCINIT) {
			handleDpchAppFmncInit(dbsfmnc, (DpchAppFmncInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessFmnc::handleCreateCrdact(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncAct* crdact = NULL;

	uint ixFmncVPreset = evalCrdactActive();

	if (ixFmncVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdact = new CrdFmncAct(xchg, dbsfmnc, jref, ixFmncVLocale, 0, ixFmncVPreset, xchg->getRefPreset(ixFmncVPreset, jref));
		crdacts.push_back(crdact);
		cout << "\tjob reference: " << crdact->jref << endl;
		xchg->jrefCmd = crdact->jref;
	};

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdadr(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncAdr* crdadr = NULL;

	crdadr = new CrdFmncAdr(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdadrs.push_back(crdadr);
	cout << "\tjob reference: " << crdadr->jref << endl;
	xchg->jrefCmd = crdadr->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdart(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncArt* crdart = NULL;

	crdart = new CrdFmncArt(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdarts.push_back(crdart);
	cout << "\tjob reference: " << crdart->jref << endl;
	xchg->jrefCmd = crdart->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdbil(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncBil* crdbil = NULL;

	uint ixFmncVPreset = evalCrdbilActive();

	if (ixFmncVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdbil = new CrdFmncBil(xchg, dbsfmnc, jref, ixFmncVLocale, 0, ixFmncVPreset, xchg->getRefPreset(ixFmncVPreset, jref));
		crdbils.push_back(crdbil);
		cout << "\tjob reference: " << crdbil->jref << endl;
		xchg->jrefCmd = crdbil->jref;
	};

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdfab(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncFab* crdfab = NULL;

	crdfab = new CrdFmncFab(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdfabs.push_back(crdfab);
	cout << "\tjob reference: " << crdfab->jref << endl;
	xchg->jrefCmd = crdfab->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdfil(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncFil* crdfil = NULL;

	crdfil = new CrdFmncFil(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdfils.push_back(crdfil);
	cout << "\tjob reference: " << crdfil->jref << endl;
	xchg->jrefCmd = crdfil->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdfpj(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncFpj* crdfpj = NULL;

	uint ixFmncVPreset = evalCrdfpjActive();

	if (ixFmncVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdfpj = new CrdFmncFpj(xchg, dbsfmnc, jref, ixFmncVLocale, 0, ixFmncVPreset, xchg->getRefPreset(ixFmncVPreset, jref));
		crdfpjs.push_back(crdfpj);
		cout << "\tjob reference: " << crdfpj->jref << endl;
		xchg->jrefCmd = crdfpj->jref;
	};

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdfus(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncFus* crdfus = NULL;

	uint ixFmncVPreset = evalCrdfusActive();

	if (ixFmncVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdfus = new CrdFmncFus(xchg, dbsfmnc, jref, ixFmncVLocale, 0, ixFmncVPreset, xchg->getRefPreset(ixFmncVPreset, jref));
		crdfuss.push_back(crdfus);
		cout << "\tjob reference: " << crdfus->jref << endl;
		xchg->jrefCmd = crdfus->jref;
	};

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdorg(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncOrg* crdorg = NULL;

	crdorg = new CrdFmncOrg(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdorgs.push_back(crdorg);
	cout << "\tjob reference: " << crdorg->jref << endl;
	xchg->jrefCmd = crdorg->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdpco(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncPco* crdpco = NULL;

	crdpco = new CrdFmncPco(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdpcos.push_back(crdpco);
	cout << "\tjob reference: " << crdpco->jref << endl;
	xchg->jrefCmd = crdpco->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdprj(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncPrj* crdprj = NULL;

	crdprj = new CrdFmncPrj(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdprjs.push_back(crdprj);
	cout << "\tjob reference: " << crdprj->jref << endl;
	xchg->jrefCmd = crdprj->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdprs(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncPrs* crdprs = NULL;

	crdprs = new CrdFmncPrs(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdprss.push_back(crdprs);
	cout << "\tjob reference: " << crdprs->jref << endl;
	xchg->jrefCmd = crdprs->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdrun(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncRun* crdrun = NULL;

	crdrun = new CrdFmncRun(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdruns.push_back(crdrun);
	cout << "\tjob reference: " << crdrun->jref << endl;
	xchg->jrefCmd = crdrun->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdsep(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncSep* crdsep = NULL;

	uint ixFmncVPreset = evalCrdsepActive();

	if (ixFmncVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdsep = new CrdFmncSep(xchg, dbsfmnc, jref, ixFmncVLocale, 0, ixFmncVPreset, xchg->getRefPreset(ixFmncVPreset, jref));
		crdseps.push_back(crdsep);
		cout << "\tjob reference: " << crdsep->jref << endl;
		xchg->jrefCmd = crdsep->jref;
	};

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdski(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncSki* crdski = NULL;

	crdski = new CrdFmncSki(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdskis.push_back(crdski);
	cout << "\tjob reference: " << crdski->jref << endl;
	xchg->jrefCmd = crdski->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdsmp(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncSmp* crdsmp = NULL;

	crdsmp = new CrdFmncSmp(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdsmps.push_back(crdsmp);
	cout << "\tjob reference: " << crdsmp->jref << endl;
	xchg->jrefCmd = crdsmp->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdstp(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncStp* crdstp = NULL;

	crdstp = new CrdFmncStp(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdstps.push_back(crdstp);
	cout << "\tjob reference: " << crdstp->jref << endl;
	xchg->jrefCmd = crdstp->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdtol(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncTol* crdtol = NULL;

	uint ixFmncVPreset = evalCrdtolActive();

	if (ixFmncVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdtol = new CrdFmncTol(xchg, dbsfmnc, jref, ixFmncVLocale, 0, ixFmncVPreset, xchg->getRefPreset(ixFmncVPreset, jref));
		crdtols.push_back(crdtol);
		cout << "\tjob reference: " << crdtol->jref << endl;
		xchg->jrefCmd = crdtol->jref;
	};

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdtty(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncTty* crdtty = NULL;

	crdtty = new CrdFmncTty(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdttys.push_back(crdtty);
	cout << "\tjob reference: " << crdtty->jref << endl;
	xchg->jrefCmd = crdtty->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdusg(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncUsg* crdusg = NULL;

	crdusg = new CrdFmncUsg(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdusgs.push_back(crdusg);
	cout << "\tjob reference: " << crdusg->jref << endl;
	xchg->jrefCmd = crdusg->jref;

	return false;
	return retval;
};

bool SessFmnc::handleCreateCrdusr(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	CrdFmncUsr* crdusr = NULL;

	crdusr = new CrdFmncUsr(xchg, dbsfmnc, jref, ixFmncVLocale, 0);
	crdusrs.push_back(crdusr);
	cout << "\tjob reference: " << crdusr->jref << endl;
	xchg->jrefCmd = crdusr->jref;

	return false;
	return retval;
};

bool SessFmnc::handleEraseCrdact(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncAct* crdact = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdacts.begin();it!=crdacts.end();) {
		crdact = *it;
		if (crdact->jref == iinput) {
			it = crdacts.erase(it);
			delete crdact;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdadr(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncAdr* crdadr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdadrs.begin();it!=crdadrs.end();) {
		crdadr = *it;
		if (crdadr->jref == iinput) {
			it = crdadrs.erase(it);
			delete crdadr;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdart(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncArt* crdart = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdarts.begin();it!=crdarts.end();) {
		crdart = *it;
		if (crdart->jref == iinput) {
			it = crdarts.erase(it);
			delete crdart;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdbil(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncBil* crdbil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdbils.begin();it!=crdbils.end();) {
		crdbil = *it;
		if (crdbil->jref == iinput) {
			it = crdbils.erase(it);
			delete crdbil;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdfab(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncFab* crdfab = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdfabs.begin();it!=crdfabs.end();) {
		crdfab = *it;
		if (crdfab->jref == iinput) {
			it = crdfabs.erase(it);
			delete crdfab;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdfil(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncFil* crdfil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdfils.begin();it!=crdfils.end();) {
		crdfil = *it;
		if (crdfil->jref == iinput) {
			it = crdfils.erase(it);
			delete crdfil;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdfpj(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncFpj* crdfpj = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdfpjs.begin();it!=crdfpjs.end();) {
		crdfpj = *it;
		if (crdfpj->jref == iinput) {
			it = crdfpjs.erase(it);
			delete crdfpj;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdfus(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncFus* crdfus = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdfuss.begin();it!=crdfuss.end();) {
		crdfus = *it;
		if (crdfus->jref == iinput) {
			it = crdfuss.erase(it);
			delete crdfus;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdorg(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncOrg* crdorg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdorgs.begin();it!=crdorgs.end();) {
		crdorg = *it;
		if (crdorg->jref == iinput) {
			it = crdorgs.erase(it);
			delete crdorg;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdpco(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncPco* crdpco = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdpcos.begin();it!=crdpcos.end();) {
		crdpco = *it;
		if (crdpco->jref == iinput) {
			it = crdpcos.erase(it);
			delete crdpco;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdprj(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncPrj* crdprj = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdprjs.begin();it!=crdprjs.end();) {
		crdprj = *it;
		if (crdprj->jref == iinput) {
			it = crdprjs.erase(it);
			delete crdprj;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdprs(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncPrs* crdprs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdprss.begin();it!=crdprss.end();) {
		crdprs = *it;
		if (crdprs->jref == iinput) {
			it = crdprss.erase(it);
			delete crdprs;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdrun(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncRun* crdrun = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdruns.begin();it!=crdruns.end();) {
		crdrun = *it;
		if (crdrun->jref == iinput) {
			it = crdruns.erase(it);
			delete crdrun;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdsep(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncSep* crdsep = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdseps.begin();it!=crdseps.end();) {
		crdsep = *it;
		if (crdsep->jref == iinput) {
			it = crdseps.erase(it);
			delete crdsep;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdski(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncSki* crdski = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdskis.begin();it!=crdskis.end();) {
		crdski = *it;
		if (crdski->jref == iinput) {
			it = crdskis.erase(it);
			delete crdski;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdsmp(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncSmp* crdsmp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdsmps.begin();it!=crdsmps.end();) {
		crdsmp = *it;
		if (crdsmp->jref == iinput) {
			it = crdsmps.erase(it);
			delete crdsmp;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdstp(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncStp* crdstp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdstps.begin();it!=crdstps.end();) {
		crdstp = *it;
		if (crdstp->jref == iinput) {
			it = crdstps.erase(it);
			delete crdstp;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdtol(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncTol* crdtol = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdtols.begin();it!=crdtols.end();) {
		crdtol = *it;
		if (crdtol->jref == iinput) {
			it = crdtols.erase(it);
			delete crdtol;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdtty(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncTty* crdtty = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdttys.begin();it!=crdttys.end();) {
		crdtty = *it;
		if (crdtty->jref == iinput) {
			it = crdttys.erase(it);
			delete crdtty;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdusg(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncUsg* crdusg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdusgs.begin();it!=crdusgs.end();) {
		crdusg = *it;
		if (crdusg->jref == iinput) {
			it = crdusgs.erase(it);
			delete crdusg;
			break;
		} else it++;
	};

	return retval;
};

bool SessFmnc::handleEraseCrdusr(
			DbsFmnc* dbsfmnc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdFmncUsr* crdusr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdusrs.begin();it!=crdusrs.end();) {
		crdusr = *it;
		if (crdusr->jref == iinput) {
			it = crdusrs.erase(it);
			delete crdusr;
			break;
		} else it++;
	};

	return retval;
};

void SessFmnc::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = new DpchEngData(jref, &statshr, {DpchEngData::ALL});
};

void SessFmnc::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCACCESS) {
		call->abort = handleCallFmncAccess(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCCRDACTIVE) {
		call->abort = handleCallFmncCrdActive(dbsfmnc, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCCRDCLOSE) {
		call->abort = handleCallFmncCrdClose(dbsfmnc, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCCRDOPEN) {
		call->abort = handleCallFmncCrdOpen(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCDESCR) {
		call->abort = handleCallFmncDescr(dbsfmnc, call->jref, call->argInv.sref, call->argRet.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCLOG) {
		call->abort = handleCallFmncLog(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSCR) {
		call->abort = handleCallFmncScr(dbsfmnc, call->jref, call->argInv.ref, call->argRet.sref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCREFPRESET) {
		call->abort = handleCallFmncRefPreSet(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool SessFmnc::handleCallFmncAccess(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkAccess(dbsfmnc, ixInv, refInv);
	return retval;
};

bool SessFmnc::handleCallFmncCrdActive(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessFmnc::handleCallFmncCrdClose(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	ubigint jrefNotif = xchg->getRefPreset(VecFmncVPreset::PREFMNCJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecFmncVPreset::PREFMNCJREFNOTIFY, jref);

	if (ixInv == VecFmncVCard::CRDFMNCNAV) {
		FmncMSession* ses = NULL;

		time_t rawtime;

		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

		// update session with stop time
		time(&rawtime);

		dbsfmnc->tblfmncmsession->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCSESS, jref), &ses);
		ses->stop = rawtime;
		dbsfmnc->tblfmncmsession->updateRec(ses);

		delete ses;

		// notify root
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCLOGOUT, jref);
	} else if (ixInv == VecFmncVCard::CRDFMNCUSG) {
		CrdFmncUsg* crdusg = NULL;

		for (auto it=crdusgs.begin();it!=crdusgs.end();) {
			crdusg = *it;
			if (crdusg->jref == jrefTrig) {
				it = crdusgs.erase(it);
				delete crdusg;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCUSR) {
		CrdFmncUsr* crdusr = NULL;

		for (auto it=crdusrs.begin();it!=crdusrs.end();) {
			crdusr = *it;
			if (crdusr->jref == jrefTrig) {
				it = crdusrs.erase(it);
				delete crdusr;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCORG) {
		CrdFmncOrg* crdorg = NULL;

		for (auto it=crdorgs.begin();it!=crdorgs.end();) {
			crdorg = *it;
			if (crdorg->jref == jrefTrig) {
				it = crdorgs.erase(it);
				delete crdorg;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCPRS) {
		CrdFmncPrs* crdprs = NULL;

		for (auto it=crdprss.begin();it!=crdprss.end();) {
			crdprs = *it;
			if (crdprs->jref == jrefTrig) {
				it = crdprss.erase(it);
				delete crdprs;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCADR) {
		CrdFmncAdr* crdadr = NULL;

		for (auto it=crdadrs.begin();it!=crdadrs.end();) {
			crdadr = *it;
			if (crdadr->jref == jrefTrig) {
				it = crdadrs.erase(it);
				delete crdadr;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCFIL) {
		CrdFmncFil* crdfil = NULL;

		for (auto it=crdfils.begin();it!=crdfils.end();) {
			crdfil = *it;
			if (crdfil->jref == jrefTrig) {
				it = crdfils.erase(it);
				delete crdfil;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCSTP) {
		CrdFmncStp* crdstp = NULL;

		for (auto it=crdstps.begin();it!=crdstps.end();) {
			crdstp = *it;
			if (crdstp->jref == jrefTrig) {
				it = crdstps.erase(it);
				delete crdstp;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCPRJ) {
		CrdFmncPrj* crdprj = NULL;

		for (auto it=crdprjs.begin();it!=crdprjs.end();) {
			crdprj = *it;
			if (crdprj->jref == jrefTrig) {
				it = crdprjs.erase(it);
				delete crdprj;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCRUN) {
		CrdFmncRun* crdrun = NULL;

		for (auto it=crdruns.begin();it!=crdruns.end();) {
			crdrun = *it;
			if (crdrun->jref == jrefTrig) {
				it = crdruns.erase(it);
				delete crdrun;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCACT) {
		CrdFmncAct* crdact = NULL;

		for (auto it=crdacts.begin();it!=crdacts.end();) {
			crdact = *it;
			if (crdact->jref == jrefTrig) {
				it = crdacts.erase(it);
				delete crdact;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCSEP) {
		CrdFmncSep* crdsep = NULL;

		for (auto it=crdseps.begin();it!=crdseps.end();) {
			crdsep = *it;
			if (crdsep->jref == jrefTrig) {
				it = crdseps.erase(it);
				delete crdsep;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCSMP) {
		CrdFmncSmp* crdsmp = NULL;

		for (auto it=crdsmps.begin();it!=crdsmps.end();) {
			crdsmp = *it;
			if (crdsmp->jref == jrefTrig) {
				it = crdsmps.erase(it);
				delete crdsmp;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCFAB) {
		CrdFmncFab* crdfab = NULL;

		for (auto it=crdfabs.begin();it!=crdfabs.end();) {
			crdfab = *it;
			if (crdfab->jref == jrefTrig) {
				it = crdfabs.erase(it);
				delete crdfab;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCFUS) {
		CrdFmncFus* crdfus = NULL;

		for (auto it=crdfuss.begin();it!=crdfuss.end();) {
			crdfus = *it;
			if (crdfus->jref == jrefTrig) {
				it = crdfuss.erase(it);
				delete crdfus;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCTTY) {
		CrdFmncTty* crdtty = NULL;

		for (auto it=crdttys.begin();it!=crdttys.end();) {
			crdtty = *it;
			if (crdtty->jref == jrefTrig) {
				it = crdttys.erase(it);
				delete crdtty;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCTOL) {
		CrdFmncTol* crdtol = NULL;

		for (auto it=crdtols.begin();it!=crdtols.end();) {
			crdtol = *it;
			if (crdtol->jref == jrefTrig) {
				it = crdtols.erase(it);
				delete crdtol;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCFPJ) {
		CrdFmncFpj* crdfpj = NULL;

		for (auto it=crdfpjs.begin();it!=crdfpjs.end();) {
			crdfpj = *it;
			if (crdfpj->jref == jrefTrig) {
				it = crdfpjs.erase(it);
				delete crdfpj;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCBIL) {
		CrdFmncBil* crdbil = NULL;

		for (auto it=crdbils.begin();it!=crdbils.end();) {
			crdbil = *it;
			if (crdbil->jref == jrefTrig) {
				it = crdbils.erase(it);
				delete crdbil;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCART) {
		CrdFmncArt* crdart = NULL;

		for (auto it=crdarts.begin();it!=crdarts.end();) {
			crdart = *it;
			if (crdart->jref == jrefTrig) {
				it = crdarts.erase(it);
				delete crdart;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCSKI) {
		CrdFmncSki* crdski = NULL;

		for (auto it=crdskis.begin();it!=crdskis.end();) {
			crdski = *it;
			if (crdski->jref == jrefTrig) {
				it = crdskis.erase(it);
				delete crdski;
				break;
			} else it++;
		};
	} else if (ixInv == VecFmncVCard::CRDFMNCPCO) {
		CrdFmncPco* crdpco = NULL;

		for (auto it=crdpcos.begin();it!=crdpcos.end();) {
			crdpco = *it;
			if (crdpco->jref == jrefTrig) {
				it = crdpcos.erase(it);
				delete crdpco;
				break;
			} else it++;
		};
	};
	return retval;
};

bool SessFmnc::handleCallFmncCrdOpen(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixFmncVCard = VecFmncVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixFmncVPreset;
	ubigint preUref;

	uint ixFmncWUiaccess;
	uint ixFmncVAccess;

	if (hasActive(ixFmncVCard)) {
		if (ixInv == 0) {
			ixFmncVPreset = checkCrdActive(ixFmncVCard);
			if (ixFmncVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixFmncVPreset, jref);
			};

		} else {
			ixFmncVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixFmncWUiaccess = checkUiaccess(ixFmncVCard);
		denied = (ixFmncWUiaccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixFmncWUiaccess & VecFmncWUiaccess::EDIT) == 0) || ((ixFmncWUiaccess & VecFmncWUiaccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixFmncVAccess = checkAccess(dbsfmnc, ixFmncVCard, intvalInv);
			denied = (ixFmncVAccess == VecFmncVAccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixFmncVCard == VecFmncVCard::CRDFMNCNAV) {
		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCUSG) {
			CrdFmncUsg* crdusg = NULL;

			crdusg = new CrdFmncUsg(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdusgs.push_back(crdusg);

			refRet = crdusg->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCUSR) {
			CrdFmncUsr* crdusr = NULL;

			crdusr = new CrdFmncUsr(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdusrs.push_back(crdusr);

			refRet = crdusr->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCORG) {
			CrdFmncOrg* crdorg = NULL;

			crdorg = new CrdFmncOrg(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdorgs.push_back(crdorg);

			refRet = crdorg->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCPRS) {
			CrdFmncPrs* crdprs = NULL;

			crdprs = new CrdFmncPrs(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdprss.push_back(crdprs);

			refRet = crdprs->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCADR) {
			CrdFmncAdr* crdadr = NULL;

			crdadr = new CrdFmncAdr(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdadrs.push_back(crdadr);

			refRet = crdadr->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCFIL) {
			CrdFmncFil* crdfil = NULL;

			crdfil = new CrdFmncFil(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdfils.push_back(crdfil);

			refRet = crdfil->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCSTP) {
			CrdFmncStp* crdstp = NULL;

			crdstp = new CrdFmncStp(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdstps.push_back(crdstp);

			refRet = crdstp->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCPRJ) {
			CrdFmncPrj* crdprj = NULL;

			crdprj = new CrdFmncPrj(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdprjs.push_back(crdprj);

			refRet = crdprj->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCRUN) {
			CrdFmncRun* crdrun = NULL;

			crdrun = new CrdFmncRun(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdruns.push_back(crdrun);

			refRet = crdrun->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCACT) {
			CrdFmncAct* crdact = NULL;

			crdact = new CrdFmncAct(xchg, dbsfmnc, jref, ixFmncVLocale, ref, ixFmncVPreset, preUref);
			crdacts.push_back(crdact);

			refRet = crdact->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCSEP) {
			CrdFmncSep* crdsep = NULL;

			crdsep = new CrdFmncSep(xchg, dbsfmnc, jref, ixFmncVLocale, ref, ixFmncVPreset, preUref);
			crdseps.push_back(crdsep);

			refRet = crdsep->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCSMP) {
			CrdFmncSmp* crdsmp = NULL;

			crdsmp = new CrdFmncSmp(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdsmps.push_back(crdsmp);

			refRet = crdsmp->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCFAB) {
			CrdFmncFab* crdfab = NULL;

			crdfab = new CrdFmncFab(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdfabs.push_back(crdfab);

			refRet = crdfab->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCFUS) {
			CrdFmncFus* crdfus = NULL;

			crdfus = new CrdFmncFus(xchg, dbsfmnc, jref, ixFmncVLocale, ref, ixFmncVPreset, preUref);
			crdfuss.push_back(crdfus);

			refRet = crdfus->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCTTY) {
			CrdFmncTty* crdtty = NULL;

			crdtty = new CrdFmncTty(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdttys.push_back(crdtty);

			refRet = crdtty->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCTOL) {
			CrdFmncTol* crdtol = NULL;

			crdtol = new CrdFmncTol(xchg, dbsfmnc, jref, ixFmncVLocale, ref, ixFmncVPreset, preUref);
			crdtols.push_back(crdtol);

			refRet = crdtol->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCFPJ) {
			CrdFmncFpj* crdfpj = NULL;

			crdfpj = new CrdFmncFpj(xchg, dbsfmnc, jref, ixFmncVLocale, ref, ixFmncVPreset, preUref);
			crdfpjs.push_back(crdfpj);

			refRet = crdfpj->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCBIL) {
			CrdFmncBil* crdbil = NULL;

			crdbil = new CrdFmncBil(xchg, dbsfmnc, jref, ixFmncVLocale, ref, ixFmncVPreset, preUref);
			crdbils.push_back(crdbil);

			refRet = crdbil->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCART) {
			CrdFmncArt* crdart = NULL;

			crdart = new CrdFmncArt(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdarts.push_back(crdart);

			refRet = crdart->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCSKI) {
			CrdFmncSki* crdski = NULL;

			crdski = new CrdFmncSki(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdskis.push_back(crdski);

			refRet = crdski->jref;

		} else if (ixFmncVCard == VecFmncVCard::CRDFMNCPCO) {
			CrdFmncPco* crdpco = NULL;

			crdpco = new CrdFmncPco(xchg, dbsfmnc, jref, ixFmncVLocale, ref);
			crdpcos.push_back(crdpco);

			refRet = crdpco->jref;

		};
	};

	return retval;
};

bool SessFmnc::handleCallFmncDescr(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval = false;
	refRet = Scr::descramble(&mAccess, descr, srefInv);
	return retval;
};

bool SessFmnc::handleCallFmncLog(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logAccess(dbsfmnc, ixInv, refInv, VecFmncVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessFmnc::handleCallFmncScr(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval = false;
	srefRet = Scr::scramble(&mAccess, scr, descr, refInv);
	return retval;
};

bool SessFmnc::handleCallFmncRefPreSet(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	if (ixInv == VecFmncVPreset::PREFMNCJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecFmncVPreset::PREFMNCJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngFmncSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if ((ixInv == VecFmncVPreset::PREFMNCREFFAB) || (ixInv == VecFmncVPreset::PREFMNCREFRUN)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbsfmnc, ixInv, jrefTrig, true);
	};
	return retval;
};


