/**
  * \file PnlFmncPrsDetail_evals.cpp
  * job handler for job PnlFmncPrsDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncPrsDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncPrsDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncPrsDetail::evalButJEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRS, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncPrsDetail::evalButOrgViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncPrsDetail::evalButAdrViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAdr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


