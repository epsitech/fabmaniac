/**
  * \file PnlFmncFilDetail_evals.cpp
  * job handler for job PnlFmncFilDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncFilDetail::evalButSaveAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFilDetail::evalButSaveActive(
			DbsFmnc* dbsfmnc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFilDetail::evalButCluViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFilDetail::evalButCluClusterAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFilIncl(edit) & fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);
	a = false; xchg->triggerRefToBoolvalCall(dbsfmnc, VecFmncVCall::CALLFMNCFIL_CLUEQ, jref, 0, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlFmncFilDetail::evalButCluUnclusterAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFilIncl(edit) & !fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFIL, jref) & VecFmncWUiaccess::EDIT);
	args.push_back(a);
	a = false; xchg->triggerRefToBoolvalCall(dbsfmnc, VecFmncVCall::CALLFMNCFIL_CLUEQ, jref, 0, a);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlFmncFilDetail::evalButCntEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlFmncFilDetail::evalButMimEditAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecFmncVPreset::PREFMNCADM, jref));
	args.push_back(a);

	return(args.back());
};


