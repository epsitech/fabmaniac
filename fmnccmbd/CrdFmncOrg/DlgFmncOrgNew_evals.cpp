/**
  * \file DlgFmncOrgNew_evals.cpp
  * job handler for job DlgFmncOrgNew (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool DlgFmncOrgNew::evalButCncActive(
			DbsFmnc* dbsfmnc
		) {
	// sge(!create)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CREATE);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgFmncOrgNew::evalButCreActive(
			DbsFmnc* dbsfmnc
		) {
	// sge(idle)&valid()

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = valid;
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};


