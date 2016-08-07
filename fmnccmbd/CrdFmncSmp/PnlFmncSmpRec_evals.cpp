/**
  * \file PnlFmncSmpRec_evals.cpp
  * job handler for job PnlFmncSmpRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncSmpRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refSmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};


