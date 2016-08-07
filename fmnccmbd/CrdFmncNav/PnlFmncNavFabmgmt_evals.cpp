/**
  * \file PnlFmncNavFabmgmt_evals.cpp
  * job handler for job PnlFmncNavFabmgmt (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncNavFabmgmt::evalLstFabAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButFabViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstFab.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFab != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalLstFusAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFus()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFUS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButFusViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstFus.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFus != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButFusNewcrdActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalLstTtyAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButTtyViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstTty.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTty != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalLstTolAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacTol()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACTOL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButTolViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstTol.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTol != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButTolNewcrdActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalLstFpjAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacFpj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACFPJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButFpjViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstFpj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFpj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButFpjNewcrdActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalLstBilAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacBil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACBIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButBilViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstBil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstBil != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavFabmgmt::evalButBilNewcrdActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refFab()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref) != 0);
	args.push_back(a);

	return(args.back());
};


