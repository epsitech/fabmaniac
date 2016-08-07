/**
  * \file PnlFmncAdrRec_evals.cpp
  * job handler for job PnlFmncAdrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncAdrRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refAdr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFADR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


