/**
  * \file PnlFmncFusRec_evals.cpp
  * job handler for job PnlFmncFusRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFusRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFus()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFUS, jref) != 0);
	args.push_back(a);

	return(args.back());
};


