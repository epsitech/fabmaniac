/**
  * \file CrdFmncRun_evals.cpp
  * job handler for job CrdFmncRun (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncRun::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsfmnc);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncRun::evalMitCrdNewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacRunIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncRun::evalMitCrdGnrActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


