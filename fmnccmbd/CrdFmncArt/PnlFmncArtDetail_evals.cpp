/**
  * \file PnlFmncArtDetail_evals.cpp
  * job handler for job PnlFmncArtDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncArtDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncArtDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncArtDetail::evalButOrgViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncArtDetail::evalButTolViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTol()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncArtDetail::evalButTypEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref));
	args.push_back(a);

	return(args.back());
};


