/**
  * \file PnlFmncNavHeadbar_evals.cpp
  * job handler for job PnlFmncNavHeadbar (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncNavHeadbar::evalMenCrdAvail(
			DbsFmnc* dbsfmnc
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()|MspCrd4Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMspCrd4Avail(dbsfmnc);
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

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMspCrd1Avail(
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

bool PnlFmncNavHeadbar::evalMitCrdUsgAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdUsrAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdOrgAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdPrsAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdAdrAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAdr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdFilAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMspCrd2Avail(
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

bool PnlFmncNavHeadbar::evalMitCrdStpAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacStp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdPrjAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdRunAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdActAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAct()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdSepAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSep()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdSmpAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMspCrd3Avail(
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

bool PnlFmncNavHeadbar::evalMitCrdFabAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdFusAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFus()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFUS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdTtyAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdTolAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTol()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdFpjAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFpj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdBilAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacBil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMspCrd4Avail(
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

bool PnlFmncNavHeadbar::evalMitCrdArtAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdSkiAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSki()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavHeadbar::evalMitCrdPcoAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};


