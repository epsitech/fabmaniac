/**
  * \file PnlFmncBilRec_evals.cpp
  * job handler for job PnlFmncBilRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncBilRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refBil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFBIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};


