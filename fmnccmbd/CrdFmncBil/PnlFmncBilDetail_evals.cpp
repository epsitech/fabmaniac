/**
  * \file PnlFmncBilDetail_evals.cpp
  * job handler for job PnlFmncBilDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncBilDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacBilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncBilDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncBilDetail::evalButPrjViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFpj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncBilDetail::evalButFilViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncBilDetail::evalButJEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacBilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


