/**
  * \file PnlFmncNavLabbook_evals.cpp
  * job handler for job PnlFmncNavLabbook (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncNavLabbook::evalLstStpAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacStp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButStpViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstStp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstStp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalLstPrjAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButPrjViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstPrj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalLstRunAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButRunViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstRun.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRun != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalLstActAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacAct()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACACT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButActViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstAct.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstAct != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButActNewcrdActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalLstSepAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSep()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSEP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButSepViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstSep.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSep != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButSepNewcrdActive(
			DbsFmnc* dbsfmnc
		) {
	// pre.refRun()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalLstSmpAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavLabbook::evalButSmpViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstSmp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSmp != 0);
	args.push_back(a);

	return(args.back());
};


