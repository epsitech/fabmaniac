/**
  * \file CrdFmncFab_evals.cpp
  * job handler for job CrdFmncFab (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncFab::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdNewAvail()|MitCrdImfAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdNewAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdImfAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncFab::evalMitCrdNewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFabIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncFab::evalMitCrdImfAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFabIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncFab::evalMitCrdExfActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};


