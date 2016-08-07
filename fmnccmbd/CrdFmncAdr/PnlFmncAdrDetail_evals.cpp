/**
  * \file PnlFmncAdrDetail_evals.cpp
  * job handler for job PnlFmncAdrDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncAdrDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAdrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACADR, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncAdrDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncAdrDetail::evalButAtyEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlFmncAdrDetail::evalButCryEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref));
	args.push_back(a);

	return(args.back());
};


