/**
  * \file PnlFmncUsrRec_evals.cpp
  * job handler for job PnlFmncUsrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncUsrRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


