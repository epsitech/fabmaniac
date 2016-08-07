/**
  * \file PnlFmncTtyDetail_evals.cpp
  * job handler for job PnlFmncTtyDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncTtyDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTtyIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncTtyDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncTtyDetail::evalButSupViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};


