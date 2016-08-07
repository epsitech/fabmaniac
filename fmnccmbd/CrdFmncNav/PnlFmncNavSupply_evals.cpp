/**
  * \file PnlFmncNavSupply_evals.cpp
  * job handler for job PnlFmncNavSupply (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

bool PnlFmncNavSupply::evalLstArtAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacArt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACART, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavSupply::evalButArtViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstArt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstArt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavSupply::evalLstSkiAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacSki()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACSKI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavSupply::evalButSkiViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstSki.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSki != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavSupply::evalLstPcoAvail(
			DbsFmnc* dbsfmnc
		) {
	// pre.ixUacPco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecFmncVPreset::PREFMNCIXUACPCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlFmncNavSupply::evalButPcoViewActive(
			DbsFmnc* dbsfmnc
		) {
	// LstPco.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPco != 0);
	args.push_back(a);

	return(args.back());
};


