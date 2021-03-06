/**
  * \file PnlFmncPrsRec_evals.cpp
  * job handler for job PnlFmncPrsRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncPrsRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};


