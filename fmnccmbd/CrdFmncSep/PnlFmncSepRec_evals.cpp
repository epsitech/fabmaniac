/**
  * \file PnlFmncSepRec_evals.cpp
  * job handler for job PnlFmncSepRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncSepRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refSep()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEP, jref) != 0);
	args.push_back(a);

	return(args.back());
};


