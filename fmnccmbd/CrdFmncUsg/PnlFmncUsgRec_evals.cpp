/**
  * \file PnlFmncUsgRec_evals.cpp
  * job handler for job PnlFmncUsgRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncUsgRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};


