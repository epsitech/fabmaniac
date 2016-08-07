/**
  * \file PnlFmncTolRec_evals.cpp
  * job handler for job PnlFmncTolRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncTolRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refTol()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref) != 0);
	args.push_back(a);

	return(args.back());
};


