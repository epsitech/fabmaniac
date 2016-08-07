/**
  * \file PnlFmncStpRec_evals.cpp
  * job handler for job PnlFmncStpRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncStpRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refStp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};


