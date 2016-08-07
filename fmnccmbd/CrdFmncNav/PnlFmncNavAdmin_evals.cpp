/**
  * \file PnlFmncNavAdmin_evals.cpp
  * job handler for job PnlFmncNavAdmin (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncNavAdmin::evalLstUsgAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalButUsgViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalLstUsrAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalButUsrViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalLstOrgAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalButOrgViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstOrg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOrg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalLstPrsAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalButPrsViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalLstAdrAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAdr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalButAdrViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstAdr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstAdr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalLstFilAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavAdmin::evalButFilViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};


