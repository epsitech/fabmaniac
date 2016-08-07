/**
  * \file CrdFmncAct_evals.cpp
  * job handler for job CrdFmncAct (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncAct::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsfmnc);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncAct::evalMitCrdNewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacActIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


