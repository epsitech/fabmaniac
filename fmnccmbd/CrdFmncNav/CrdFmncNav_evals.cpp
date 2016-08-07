/**
  * \file CrdFmncNav_evals.cpp
  * job handler for job CrdFmncNav (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncNav::evalPnlpreAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()|pre.refRun()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalPnladminAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsg()|pre.ixUacUsr()|pre.ixUacOrg()|pre.ixUacPrs()|pre.ixUacAdr()|pre.ixUacFil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalPnllabbookAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacStp()|pre.ixUacPrj()|pre.ixUacRun()|pre.ixUacAct()|pre.ixUacSep()|pre.ixUacSmp()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSTP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalPnlfabmgmtAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFab()|pre.ixUacFus()|pre.ixUacTty()|pre.ixUacTol()|pre.ixUacFpj()|pre.ixUacBil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFUS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalPnlsupplyAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArt()|pre.ixUacSki()|pre.ixUacPco()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPCO, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdOrgAvail()|MitCrdPrsAvail()|MitCrdAdrAvail()|MitCrdFilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdOrgAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdAdrAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdUsgAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdUsrAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdOrgAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdPrsAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdAdrAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAdr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdFilAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMspCrd2Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdStpAvail()|MitCrdPrjAvail()|MitCrdRunAvail()|MitCrdActAvail()|MitCrdSepAvail()|MitCrdSmpAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdStpAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdPrjAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdRunAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdActAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdSepAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdSmpAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdStpAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacStp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdPrjAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdRunAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdActAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAct()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdActActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdSepAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSep()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdSepActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdSmpAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMspCrd3Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdFabAvail()|MitCrdFusAvail()|MitCrdTtyAvail()|MitCrdTolAvail()|MitCrdFpjAvail()|MitCrdBilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdFabAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdFusAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdTtyAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdTolAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdFpjAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdBilAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdFabAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdFusAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFus()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFUS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdFusActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdTtyAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdTolAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTol()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdTolActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdFpjAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFpj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdFpjActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdBilAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacBil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdBilActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMspCrd4Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdArtAvail()|MitCrdSkiAvail()|MitCrdPcoAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdArtAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdSkiAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdPcoAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdArtAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdSkiAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSki()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitCrdPcoAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMspApp2Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbsfmnc);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncNav::evalMitAppLoiAvail(
			DbsFmnc* dbsfmnc
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {ubigint cnt = 0; dbsfmnc->loadUbigintBySQL("SELECT COUNT(ref) FROM TblFmncMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};


