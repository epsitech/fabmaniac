/**
  * \file CrdFmncSmp_evals.cpp
  * job handler for job CrdFmncSmp (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool CrdFmncSmp::evalMspCrd1Avail(
			DbsFmnc* dbsfmnc
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbsfmnc);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncSmp::evalMitCrdNewAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdFmncSmp::evalMitCrdGnrActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refSmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};


