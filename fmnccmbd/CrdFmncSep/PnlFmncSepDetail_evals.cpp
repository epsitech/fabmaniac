/**
  * \file PnlFmncSepDetail_evals.cpp
  * job handler for job PnlFmncSepDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncSepDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSepIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSepDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSepDetail::evalButActViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAct()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSepDetail::evalButPrsViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};


