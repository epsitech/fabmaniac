/**
  * \file PnlFmncArtRec_evals.cpp
  * job handler for job PnlFmncArtRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncArtRec::evalButRegularizeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refArt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFART, jref) != 0);
	args.push_back(a);

	return(args.back());
};


