/**
  * \file PnlFmncFpjDetail_evals.cpp
  * job handler for job PnlFmncFpjDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFpjDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFpjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFpjDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFpjDetail::evalButFabViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFpjDetail::evalButBioViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFpjDetail::evalButJEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFpjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFpjDetail::evalButBipViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};


