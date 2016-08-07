/**
  * \file PnlFmncRunMNSample_evals.cpp
  * job handler for job PnlFmncRunMNSample (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncRunMNSample::evalButViewActive(
			DbsFmnc* dbsfmnc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncRunMNSample::evalButSubActive(
			DbsFmnc* dbsfmnc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


