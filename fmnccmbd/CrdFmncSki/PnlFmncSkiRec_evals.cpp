/**
  * \file PnlFmncSkiRec_evals.cpp
  * job handler for job PnlFmncSkiRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncSkiRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refSki()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSKI, jref) != 0);
	args.push_back(a);

	return(args.back());
};


