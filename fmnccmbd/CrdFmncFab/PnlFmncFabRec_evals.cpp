/**
  * \file PnlFmncFabRec_evals.cpp
  * job handler for job PnlFmncFabRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFabRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};


