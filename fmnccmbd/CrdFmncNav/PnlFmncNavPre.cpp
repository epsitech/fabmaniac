/**
  * \file PnlFmncNavPre.cpp
  * job handler for job PnlFmncNavPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncNavPre.h"

// IP blksInclude --- BEGIN
#include "PnlFmncNavPre_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncNavPre_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncNavPre
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncNavPre::PnlFmncNavPre(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCNAVPRE, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

};

PnlFmncNavPre::~PnlFmncNavPre() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncNavPre::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncNavPre::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtFab = StubFmnc::getStubFabStd(dbsfmnc, xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref), ixFmncVLocale);
	continf.TxtRun = StubFmnc::getStubRunStd(dbsfmnc, xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref), ixFmncVLocale);

	// statshr
	statshr.TxtFabAvail = evalTxtFabAvail(dbsfmnc);
	statshr.TxtRunAvail = evalTxtRunAvail(dbsfmnc);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavPre::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsfmnc, moditems);

	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlFmncNavPre::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCINIT) {
			handleDpchAppFmncInit(dbsfmnc, (DpchAppFmncInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVPREDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTFABREMOVECLICK) {
					handleDpchAppDoButFabRemoveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRUNREMOVECLICK) {
					handleDpchAppDoButRunRemoveClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncNavPre::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncNavPre::handleDpchAppDoButFabRemoveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbsfmnc, VecFmncVCall::CALLFMNCREFPRESET, jref, VecFmncVPreset::PREFMNCREFFAB, 0);

	refresh(dbsfmnc, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncNavPre::handleDpchAppDoButRunRemoveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbsfmnc, VecFmncVCall::CALLFMNCREFPRESET, jref, VecFmncVPreset::PREFMNCREFRUN, 0);

	refresh(dbsfmnc, moditems);

	*dpcheng = getNewDpchEng(moditems);
};


