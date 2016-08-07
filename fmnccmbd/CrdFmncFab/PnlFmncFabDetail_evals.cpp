/**
  * \file PnlFmncFabDetail_evals.cpp
  * job handler for job PnlFmncFabDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFabDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFabIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFabDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFabDetail::evalButOrgViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};


