/**
  * \file PnlFmncFpjRec_evals.cpp
  * job handler for job PnlFmncFpjRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFpjRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFpj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFPJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};


