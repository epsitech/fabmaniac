/**
  * \file PnlFmncTtyRec_evals.cpp
  * job handler for job PnlFmncTtyRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncTtyRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refTty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};


