/**
  * \file PnlFmncFilRec_evals.cpp
  * job handler for job PnlFmncFilRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFilRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};


