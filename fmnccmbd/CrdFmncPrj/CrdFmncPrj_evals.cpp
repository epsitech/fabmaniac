/**
  * \file CrdFmncPrj_evals.cpp
  * job handler for job CrdFmncPrj (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncPrj::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdNewAvail()|MitCrdImeAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdNewAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdImeAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncPrj::evalMitCrdNewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncPrj::evalMitCrdImeAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncPrj::evalMitCrdExeActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};


