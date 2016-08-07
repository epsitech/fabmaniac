/**
  * \file PnlFmncTolAAvl_evals.cpp
  * job handler for job PnlFmncTolAAvl (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncTolAAvl::evalButDuplicateActive(
			DbsFmnc* dbsfmnc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncTolAAvl::evalButDeleteActive(
			DbsFmnc* dbsfmnc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


