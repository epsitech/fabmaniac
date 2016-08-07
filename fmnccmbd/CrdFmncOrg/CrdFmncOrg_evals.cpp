/**
  * \file CrdFmncOrg_evals.cpp
  * job handler for job CrdFmncOrg (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncOrg::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdNewAvail()|MitCrdImoAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdNewAvail(dbsfmnc);
	args.push_back(a);
	a = false; a = evalMitCrdImoAvail(dbsfmnc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdFmncOrg::evalMitCrdNewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncOrg::evalMitCrdImoAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacOrgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACORG, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncOrg::evalMitCrdExoActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refOrg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref) != 0);
	args.push_back(a);

	return(args.back());
};


