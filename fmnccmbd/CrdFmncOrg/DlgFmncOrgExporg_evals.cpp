/**
  * \file DlgFmncOrgExporg_evals.cpp
  * job handler for job DlgFmncOrgExporg (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool DlgFmncOrgExporg::evalPrpButRunActive(
			DbsFmnc* dbsfmnc
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgFmncOrgExporg::evalPrpButStoActive(
			DbsFmnc* dbsfmnc
		) {
	// !sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgFmncOrgExporg::evalFiaDldActive(
			DbsFmnc* dbsfmnc
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgFmncOrgExporg::evalButDneActive(
			DbsFmnc* dbsfmnc
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};


