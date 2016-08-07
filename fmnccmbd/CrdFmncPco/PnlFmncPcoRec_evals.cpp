/**
  * \file PnlFmncPcoRec_evals.cpp
  * job handler for job PnlFmncPcoRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncPcoRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refPco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};


