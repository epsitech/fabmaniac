/**
  * \file PnlFmncOrgRec_evals.cpp
  * job handler for job PnlFmncOrgRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncOrgRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};


