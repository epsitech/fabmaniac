/**
  * \file PnlFmncPrjRec_evals.cpp
  * job handler for job PnlFmncPrjRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncPrjRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};


