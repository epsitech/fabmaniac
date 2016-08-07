/**
  * \file PnlFmncActRec_evals.cpp
  * job handler for job PnlFmncActRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncActRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refAct()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFACT, jref) != 0);
	args.push_back(a);

	return(args.back());
};


