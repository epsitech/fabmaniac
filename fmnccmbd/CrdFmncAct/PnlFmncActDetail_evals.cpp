/**
  * \file PnlFmncActDetail_evals.cpp
  * job handler for job PnlFmncActDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncActDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacActIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncActDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncActDetail::evalButRunViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


