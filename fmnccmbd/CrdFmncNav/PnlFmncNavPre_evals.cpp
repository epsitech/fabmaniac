/**
  * \file PnlFmncNavPre_evals.cpp
  * job handler for job PnlFmncNavPre (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncNavPre::evalTxtFabAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavPre::evalTxtRunAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


