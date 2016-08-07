/**
  * \file PnlFmncSkiDetail_evals.cpp
  * job handler for job PnlFmncSkiDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncSkiDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSkiIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSkiDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSkiDetail::evalButOrgViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSkiDetail::evalButArtViewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSkiDetail::evalButJEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSkiIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncSkiDetail::evalButLcnEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref));
	args.push_back(a);

	return(args.back());
};


