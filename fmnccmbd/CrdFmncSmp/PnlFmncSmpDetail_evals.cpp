/**
  * \file PnlFmncSmpDetail_evals.cpp
  * job handler for job PnlFmncSmpDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncSmpDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSmpDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSmpDetail::evalButSupViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSmpDetail::evalButArtViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSmpDetail::evalButJEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


