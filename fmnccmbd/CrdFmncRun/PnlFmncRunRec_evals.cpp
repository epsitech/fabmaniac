/**
  * \file PnlFmncRunRec_evals.cpp
  * job handler for job PnlFmncRunRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncRunRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


