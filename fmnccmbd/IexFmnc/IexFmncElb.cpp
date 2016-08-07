/**
  * \file IexFmncElb.cpp
  * import/export handler for database DbsFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "IexFmncElb.h"

#include "IexFmncElb_blks.cpp"

/******************************************************************************
 class IexFmncElb
 ******************************************************************************/

IexFmncElb::IexFmncElb(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::IEXFMNCELB, jrefSup, ixFmncVLocale) {

	jref = xchg->addJob(this);
};

IexFmncElb::~IexFmncElb() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexFmncElb::reset() {
	imeimfile1.clear();
	imeimproject.clear();
	imeimsample.clear();

	lineno = 0;
	impcnt = 0;
};

void IexFmncElb::import(
			DbsFmnc* dbsfmnc
		) {
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMProject* prj = NULL;
	ImeitemIMSample* smp = NULL;
	ImeitemIAMSamplePar* smpApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJMProjectState* prjJste = NULL;
	ImeitemIJMSampleState* smpJste = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIMRun* run = NULL;
	ImeitemIRMFileMSample* filRsmp = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIJMRunState* runJste = NULL;
	ImeitemIMActivity* act = NULL;
	ImeitemIMFile3* fil3 = NULL;
	ImeitemIRMFabMRun* fabRrun = NULL;
	ImeitemIRMPersonMRun* prsRrun = NULL;
	ImeitemIRMRunMSample* runRsmp = NULL;
	ImeitemIMStep* ste = NULL;
	ImeitemIAMStepPar* steApar = NULL;
	ImeitemIMFile4* fil4 = NULL;
	ImeitemIRMFileMStep1* filRste1 = NULL;
	ImeitemIRMFileMStep2* filRste2 = NULL;
	ImeitemIRMSampleMStep* smpRste = NULL;
	ImeitemITMFileMSample1* filTsmp1 = NULL;
	ImeitemITMFileMSample2* filTsmp2 = NULL;

// IP import --- IBEGIN
	vector<ubigint> refs;
	vector<ubigint> refs2;

	FmncMFile* fil12 = NULL;

	ImeitemIMSample* smp2 = NULL;

	vector<string> ss;
	string s;
// IP import --- IEND

// IP import.traverse --- RBEGIN

	// -- ImeIMFile1
	for (unsigned int ix0=0;ix0<imeimfile1.nodes.size();ix0++) {
		fil1 = imeimfile1.nodes[ix0];

		//fil1->ref: IDIREF
		fil1->refIxVTbl = VecFmncVMFileRefTbl::VOID;
		//fil1->osrefKContent: TBL
		//fil1->Filename: TBL
		//fil1->srefKMimetype: TBL
		//fil1->Comment: TBL
		//fil1->Archived = PP (DlgFmnc??);
		//fil1->Archivename = PP (DlgFmnc??);
		//fil1->Size = PP (DlgFmnc??);

		// retrieve
		dbsfmnc->loadUbigintBySQL("SELECT ref FROM TblFmncMFile WHERE refIxVTbl = " + to_string(VecFmncVMFileRefTbl::VOID) + " AND Filename = '" + fil1->Filename + "'", fil1->ref);

		if (fil1->ref != 0) {
			if (dbsfmnc->tblfmncmfile->loadRecByRef(fil1->ref, &fil12)) {
				fil1->osrefKContent = fil12->osrefKContent;
				fil1->srefKMimetype = fil12->srefKMimetype;
				fil1->Comment = fil12->Comment;

				delete fil12;
			};

		} else {
			dbsfmnc->tblfmncmfile->insertRec(fil1);
			impcnt++;
		};
	};

	// -- ImeIMSample
	for (unsigned int ix0=0;ix0<imeimsample.nodes.size();ix0++) {
		smp = imeimsample.nodes[ix0];

		//smp->supRefFmncMSample: PREVIMP
		for (unsigned int i=0;i<ix0;i++) {
			smp2 = imeimsample.nodes[i];

			s = smp2->sref;
			if (smp2->hsrefSupRefFmncMSample.length() > 0) s = smp2->hsrefSupRefFmncMSample + ";" + s;
			
			if (s == smp->hsrefSupRefFmncMSample) {
				smp->supRefFmncMSample = smp2->ref;
				break;
			};
		};
		//smp->sref: TBL
		//smp->Material: TBL
		//smp->refJState: SUB
		//smp->Comment: TBL

		dbsfmnc->tblfmncmsample->insertRec(smp);
		impcnt++;

		for (unsigned int ix1=0;ix1<smp->imeiamsamplepar.nodes.size();ix1++) {
			smpApar = smp->imeiamsamplepar.nodes[ix1];

			smpApar->refFmncMSample = smp->ref;
			//smpApar->x1SrefKKey: TBL
			//smpApar->osrefKVal: TBL

			dbsfmnc->tblfmncamsamplepar->insertRec(smpApar);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<smp->imeiavkeylistkey.nodes.size();ix1++) {
			klsAkey = smp->imeiavkeylistkey.nodes[ix1];

			//klsAkey->klsIxFmncVKeylist: IXSREF
			klsAkey->x1IxFmncVMaintable = VecFmncVMaintable::TBLFMNCMSAMPLE;
			klsAkey->x1Uref = smp->ref;
			klsAkey->Fixed = true;
			//klsAkey->sref: TBL
			//klsAkey->Avail: TBL
			//klsAkey->Implied: TBL
			//klsAkey->refJ: SUB

			dbsfmnc->tblfmncavkeylistkey->insertRec(klsAkey);
			impcnt++;

			for (unsigned int ix2=0;ix2<klsAkey->imeijavkeylistkey.nodes.size();ix2++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];

				kakJkey->refFmncAVKeylistKey = klsAkey->ref;
				//kakJkey->x1IxFmncVLocale: IXSREF
				//kakJkey->Title: TBL
				//kakJkey->Comment: TBL

				dbsfmnc->tblfmncjavkeylistkey->insertRec(kakJkey);
				impcnt++;
			};

			if (klsAkey->imeijavkeylistkey.nodes.size() > 0) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[0];

				klsAkey->refJ = kakJkey->ref;
				klsAkey->Title = kakJkey->Title;
				klsAkey->Comment = kakJkey->Comment;
				
				dbsfmnc->tblfmncavkeylistkey->updateRec(klsAkey);
			};
		};

		for (unsigned int ix1=0;ix1<smp->imeijmsamplestate.nodes.size();ix1++) {
			smpJste = smp->imeijmsamplestate.nodes[ix1];

			smpJste->refFmncMSample = smp->ref;
			//smpJste->x1Start: INVFTM
			//smpJste->ixVState: IXSREF

			dbsfmnc->tblfmncjmsamplestate->insertRec(smpJste);
			impcnt++;
		};

		if (smp->imeijmsamplestate.nodes.size() > 0) {
			smpJste = smp->imeijmsamplestate.nodes[0];

			smp->refJState = smpJste->ref;
			smp->ixVState = smpJste->ixVState;

			dbsfmnc->tblfmncmsample->updateRec(smp);
		};

		for (unsigned int ix1=0;ix1<smp->imeimfile2.nodes.size();ix1++) {
			fil2 = smp->imeimfile2.nodes[ix1];

			fil2->refIxVTbl = VecFmncVMFileRefTbl::SMP;
			fil2->refUref = smp->ref;
			//fil2->osrefKContent: TBL
			//fil2->Filename: TBL
			//fil2->srefKMimetype: TBL
			//fil2->Comment: TBL
			//fil2->Archived = PP (DlgFmnc??);
			//fil2->Archivename = PP (DlgFmnc??);
			//fil2->Size = PP (DlgFmnc??);

			dbsfmnc->tblfmncmfile->insertRec(fil2);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<smp->imeirmfilemsample.nodes.size();ix1++) {
			filRsmp = smp->imeirmfilemsample.nodes[ix1];

			filRsmp->refFmncMSample = smp->ref;

			dbsfmnc->tblfmncrmfilemsample->insertRec(filRsmp);
			impcnt++;
		};
	};

	// -- ImeIMProject
	for (unsigned int ix0=0;ix0<imeimproject.nodes.size();ix0++) {
		prj = imeimproject.nodes[ix0];

		//prj->Title: TBL
		//prj->refJState: SUB
		//prj->Comment: TBL

		dbsfmnc->tblfmncmproject->insertRec(prj);
		impcnt++;

		for (unsigned int ix1=0;ix1<prj->imeijmprojectstate.nodes.size();ix1++) {
			prjJste = prj->imeijmprojectstate.nodes[ix1];

			prjJste->refFmncMProject = prj->ref;
			//prjJste->x1Start: INVFTM
			//prjJste->ixVState: IXSREF

			dbsfmnc->tblfmncjmprojectstate->insertRec(prjJste);
			impcnt++;
		};

		if (prj->imeijmprojectstate.nodes.size() > 0) {
			prjJste = prj->imeijmprojectstate.nodes[0];

			prj->refJState = prjJste->ref;
			prj->ixVState = prjJste->ixVState;

			dbsfmnc->tblfmncmproject->updateRec(prj);
		};

		for (unsigned int ix1=0;ix1<prj->imeimrun.nodes.size();ix1++) {
			run = prj->imeimrun.nodes[ix1];

			run->refFmncMProject = prj->ref;
			//run->Title: TBL
			//run->refJState: SUB
			//run->Comment: TBL

			dbsfmnc->tblfmncmrun->insertRec(run);
			impcnt++;

			for (unsigned int ix2=0;ix2<run->imeijmrunstate.nodes.size();ix2++) {
				runJste = run->imeijmrunstate.nodes[ix2];

				runJste->refFmncMRun = run->ref;
				//runJste->x1Start: INVFTM
				//runJste->ixVState: IXSREF

				dbsfmnc->tblfmncjmrunstate->insertRec(runJste);
				impcnt++;
			};

			if (run->imeijmrunstate.nodes.size() > 0) {
				runJste = run->imeijmrunstate.nodes[0];

				run->refJState = runJste->ref;
				run->ixVState = runJste->ixVState;

				dbsfmnc->tblfmncmrun->updateRec(run);
			};

			for (unsigned int ix2=0;ix2<run->imeimfile3.nodes.size();ix2++) {
				fil3 = run->imeimfile3.nodes[ix2];

				fil3->refIxVTbl = VecFmncVMFileRefTbl::RUN;
				fil3->refUref = run->ref;
				//fil3->osrefKContent: TBL
				//fil3->Filename: TBL
				//fil3->srefKMimetype: TBL
				//fil3->Comment: TBL
				//fil3->Archived = PP (DlgFmnc??);
				//fil3->Archivename = PP (DlgFmnc??);
				//fil3->Size = PP (DlgFmnc??);

				dbsfmnc->tblfmncmfile->insertRec(fil3);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<run->imeirmfabmrun.nodes.size();ix2++) {
				fabRrun = run->imeirmfabmrun.nodes[ix2];

				//fabRrun->refFmncMFab: THINT ; look for sref of fab org, format: StubFmncFabSref ("pta")
				dbsfmnc->loadUbigintBySQL("SELECT TblFmncMFab.ref FROM TblFmncMFab, TblFmncMOrg WHERE TblFmncMFab.refFmncMOrg = TblFmncMOrg.ref AND TblFmncMOrg.sref = '" + fabRrun->hintRefFmncMFab + "'", fabRrun->refFmncMFab);
				fabRrun->refFmncMRun = run->ref;

				dbsfmnc->tblfmncrmfabmrun->insertRec(fabRrun);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<run->imeirmpersonmrun.nodes.size();ix2++) {
				prsRrun = run->imeirmpersonmrun.nodes[ix2];

				//prsRrun->refFmncMPerson: THINT ; look for person in org, format StubFmncPrsWorg ("(npsc) Franz Kuntz")
				StrMod::stringToVector(prsRrun->hintRefFmncMPerson, ss, ' ');
				if (ss.size() == 3) {
					if (ss[0].length() > 2) {
						ss[0] = ss[0].substr(1, ss[0].length()-2);
						dbsfmnc->loadUbigintBySQL("SELECT TblFmncMPerson.ref FROM TblFmncMOrg, TblFmncRMOrgMPerson, TblFmncMPerson WHERE TblFmncMOrg.ref = TblFmncRMOrgMPerson.refFmncMOrg AND TblFmncMOrg.sref = '" + ss[0]
									+ "' AND TblFmncMPerson.ref = TblFmncRMOrgMPerson.refFmncMPerson AND TblFmncMPerson.Lastname = '" + StrMod::esc(ss[2]) + "' AND TblFmncMPerson.Firstname = '" + StrMod::esc(ss[1]) + "'", prsRrun->refFmncMPerson);
					};
				};
				prsRrun->refFmncMRun = run->ref;

				dbsfmnc->tblfmncrmpersonmrun->insertRec(prsRrun);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<run->imeirmrunmsample.nodes.size();ix2++) {
				runRsmp = run->imeirmrunmsample.nodes[ix2];

				runRsmp->refFmncMRun = run->ref;
				//runRsmp->refFmncMSample: PREVIMP
				for (unsigned int i=0;i<imeimsample.nodes.size();i++) {
					smp = imeimsample.nodes[i];

					s = smp->sref;
					if (smp->hsrefSupRefFmncMSample.length() > 0) s = smp->hsrefSupRefFmncMSample + ";" + s;

					if (s == runRsmp->hsrefRefFmncMSample) {
						runRsmp->refFmncMSample = smp->ref;
						break;
					};
				};

				dbsfmnc->tblfmncrmrunmsample->insertRec(runRsmp);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<run->imeimactivity.nodes.size();ix2++) {
				act = run->imeimactivity.nodes[ix2];

				act->runRefFmncMRun = run->ref;
				//act->Title: TBL
				//act->Comment: TBL

				dbsfmnc->tblfmncmactivity->insertRec(act);
				impcnt++;

				for (unsigned int ix3=0;ix3<act->imeimstep.nodes.size();ix3++) {
					ste = act->imeimstep.nodes[ix3];

					ste->refFmncMActivity = act->ref;
					ste->rlvIxVTbl = VecFmncVMStepRlvTbl::TOL;
					//ste->rlvUref: THINT ; look for tool which is in any fab associated with the run, format StubFmncTolStd ("(pta) STS-ICP 80")
					ss.resize(2);
					if ((ste->hintRlvUref.find('(') == 0) && (ste->hintRlvUref.find(") ") != string::npos)) {
						ss[0] = ste->hintRlvUref.substr(1, ste->hintRlvUref.find(") ")-1);
						ss[1] = ste->hintRlvUref.substr(ss[0].length()+3);
						for (unsigned int i=0;i<run->imeirmfabmrun.nodes.size();i++) {
							fabRrun = run->imeirmfabmrun.nodes[i];
							if (ss[0] == fabRrun->hintRefFmncMFab) {
								dbsfmnc->loadUbigintBySQL("SELECT ref FROM TblFmncMTool WHERE fabRefFmncMFab = " + to_string(fabRrun->refFmncMFab) + " AND Title = '" + ss[1] + "'", ste->rlvUref);
							};
						};
					};
					//ste->tplRefFmncMStep: THINT ; look for tool template steps and template steps of all tooltypes the tool belongs to, format StubFmncStpStd ("SEM inspection")
					if (!dbsfmnc->loadUbigintBySQL("SELECT ref FROM TblFmncMStep WHERE refFmncMActivity = 0 AND rlvIxVTbl = " + to_string(VecFmncVMStepRlvTbl::TOL) + " AND rlvUref = "
								+ to_string(ste->rlvUref) + " AND Title = '" + ste->hintTplRefFmncMStep + "'", ste->tplRefFmncMStep)) {

						dbsfmnc->loadRefsBySQL("SELECT refFmncMTooltype FROM TblFmncRMToolMTooltype WHERE refFmncMTool = " + to_string(ste->rlvUref), false, refs);
						for (unsigned int i=0;i<refs.size();i++) {
							refs2.resize(0);
							dbsfmnc->tblfmncmtooltype->loadHrefsup(refs[i], refs2);

							for (unsigned int j=0;j<refs2.size();j++)
										if (dbsfmnc->loadUbigintBySQL("SELECT ref FROM TblFmncMStep WHERE refFmncMActivity = 0 AND rlvIxVTbl = " + to_string(VecFmncVMStepRlvTbl::TTY) + " AND rlvUref = "
													+ to_string(refs2[j]) + " AND Title = '" + ste->hintTplRefFmncMStep + "'", ste->tplRefFmncMStep)) break;

							if (ste->tplRefFmncMStep != 0) break;
						};
					};
					//ste->ixWFilecfg: IXSREF
					//ste->Title: TBL
					//ste->start: INVFTM
					//ste->refFmncMPerson: THINT ; look for person associated with the run, format StubFmncPrsWorg ("(npsc) Franz Kuntz")
					for (unsigned int i=0;i<run->imeirmpersonmrun.nodes.size();i++) {
						if (ste->hintRefFmncMPerson == run->imeirmpersonmrun.nodes[i]->hintRefFmncMPerson) {
							ste->refFmncMPerson = run->imeirmpersonmrun.nodes[i]->refFmncMPerson;
							break;
						};
					};

					dbsfmnc->tblfmncmstep->insertRec(ste);
					impcnt++;

					for (unsigned int ix4=0;ix4<ste->imeirmfilemstep1.nodes.size();ix4++) {
						filRste1 = ste->imeirmfilemstep1.nodes[ix4];

						//filRste1->refFmncMFile: PREVIMP
						for (unsigned int i=0;i<imeimfile1.nodes.size();i++) {
							if (filRste1->irefRefFmncMFile == imeimfile1.nodes[i]->iref) {
								filRste1->refFmncMFile = imeimfile1.nodes[i]->ref;
								break;
							};
						};
						filRste1->refFmncMStep = ste->ref;
						//filRste1->ixVDir: IXSREF

						dbsfmnc->tblfmncrmfilemstep->insertRec(filRste1);
						impcnt++;

						for (unsigned int ix5=0;ix5<filRste1->imeitmfilemsample1.nodes.size();ix5++) {
							filTsmp1 = filRste1->imeitmfilemsample1.nodes[ix5];

							filTsmp1->refR = filRste1->ref;
							//filTsmp1->refFmncMSample: PREVIMP
							for (unsigned int i=0;i<ste->imeirmsamplemstep.nodes.size();i++) {
								if (filTsmp1->hsrefRefFmncMSample == ste->imeirmsamplemstep.nodes[i]->hsrefRefFmncMSample) {
									filTsmp1->refFmncMSample = ste->imeirmsamplemstep.nodes[i]->refFmncMSample;
									break;
								};
							};

							dbsfmnc->tblfmnctmfilemsample->insertRec(filTsmp1);
							impcnt++;
						};
					};

					for (unsigned int ix4=0;ix4<ste->imeirmsamplemstep.nodes.size();ix4++) {
						smpRste = ste->imeirmsamplemstep.nodes[ix4];

						//smpRste->refFmncMSample: PREVIMP
						for (unsigned int i=0;i<imeimsample.nodes.size();i++) {
							smp = imeimsample.nodes[i];

							s = smp->sref;
							if (smp->hsrefSupRefFmncMSample.length() > 0) s = smp->hsrefSupRefFmncMSample + ";" + s;
							
							if (s == smpRste->hsrefRefFmncMSample) {
								smpRste->refFmncMSample = smp->ref;
								break;
							};
						};
						smpRste->refFmncMStep = ste->ref;

						dbsfmnc->tblfmncrmsamplemstep->insertRec(smpRste);
						impcnt++;
					};

					for (unsigned int ix4=0;ix4<ste->imeimfile4.nodes.size();ix4++) {
						fil4 = ste->imeimfile4.nodes[ix4];

						//fil4->ref: IDIREF
						fil4->refIxVTbl = VecFmncVMFileRefTbl::STE;
						fil4->refUref = ste->ref;
						//fil4->osrefKContent: TBL
						//fil4->Filename: TBL
						//fil4->srefKMimetype: TBL
						//fil4->Comment: TBL
						//fil4->Archived = PP (DlgFmnc??);
						//fil4->Archivename = PP (DlgFmnc??);
						//fil4->Size = PP (DlgFmnc??);

						dbsfmnc->tblfmncmfile->insertRec(fil4);
						impcnt++;
					};

					for (unsigned int ix4=0;ix4<ste->imeirmfilemstep2.nodes.size();ix4++) {
						filRste2 = ste->imeirmfilemstep2.nodes[ix4];

						//filRste2->refFmncMFile: PREVIMP
						for (unsigned int i=0;i<ste->imeimfile4.nodes.size();i++) {
							if (filRste2->irefRefFmncMFile == ste->imeimfile4.nodes[i]->iref) {
								filRste2->refFmncMFile = ste->imeimfile4.nodes[i]->ref;
								break;
							};
						};
						filRste2->refFmncMStep = ste->ref;
						//filRste2->ixVDir: IXSREF

						dbsfmnc->tblfmncrmfilemstep->insertRec(filRste2);
						impcnt++;

						for (unsigned int ix5=0;ix5<filRste2->imeitmfilemsample2.nodes.size();ix5++) {
							filTsmp2 = filRste2->imeitmfilemsample2.nodes[ix5];

							filTsmp2->refR = filRste2->ref;
							//filTsmp2->refFmncMSample: PREVIMP
							for (unsigned int i=0;i<ste->imeirmsamplemstep.nodes.size();i++) {
								if (filTsmp2->hsrefRefFmncMSample == ste->imeirmsamplemstep.nodes[i]->hsrefRefFmncMSample) {
									filTsmp2->refFmncMSample = ste->imeirmsamplemstep.nodes[i]->refFmncMSample;
									break;
								};
							};

							dbsfmnc->tblfmnctmfilemsample->insertRec(filTsmp2);
							impcnt++;
						};
					};

					for (unsigned int ix4=0;ix4<ste->imeiamsteppar.nodes.size();ix4++) {
						steApar = ste->imeiamsteppar.nodes[ix4];

						steApar->refFmncMStep = ste->ref;
						//steApar->x1OsrefFmncKSteppar: TBL
						//steApar->x2IxVTbl: IXSREF
						//steApar->x2Uref: THINT
						if (steApar->x2IxVTbl == VecFmncVAMStepParTbl::FIL) {
							// look for file associated with the step, format StubFmncFilStd ("Ex_prof.hdf5")
							for (unsigned int i=0;i<ste->imeimfile4.nodes.size();i++) {
								if (steApar->hintX2Uref == ste->imeimfile4.nodes[i]->Filename) {
									steApar->x2Uref = ste->imeimfile4.nodes[i]->ref;
									break;
								};
							};
						} else if (steApar->x2IxVTbl == VecFmncVAMStepParTbl::SMP) {
							// look for sample associated with the step, format StubFmncSmpHsref ("X0001;X0001-2")
							for (unsigned int i=0;i<ste->imeirmsamplemstep.nodes.size();i++) {
								if (steApar->hintX2Uref == ste->imeirmsamplemstep.nodes[i]->hsrefRefFmncMSample) {
									steApar->x2Uref = ste->imeirmsamplemstep.nodes[i]->refFmncMSample;
									break;
								};
							};
						};
						//steApar->Val: TBL
						//steApar->Comment: TBL

						dbsfmnc->tblfmncamsteppar->insertRec(steApar);
						impcnt++;
					};
				};
			};
		};
	};
// IP import.traverse --- REND

// IP import.ppr --- INSERT
};

void IexFmncElb::collect(
			DbsFmnc* dbsfmnc
			, const map<uint,uint>& icsFmncVIop
		) {
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMProject* prj = NULL;
	ImeitemIMSample* smp = NULL;
	ImeitemIAMSamplePar* smpApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJMProjectState* prjJste = NULL;
	ImeitemIJMSampleState* smpJste = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIMRun* run = NULL;
	ImeitemIRMFileMSample* filRsmp = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIJMRunState* runJste = NULL;
	ImeitemIMActivity* act = NULL;
	ImeitemIMFile3* fil3 = NULL;
	ImeitemIRMFabMRun* fabRrun = NULL;
	ImeitemIRMPersonMRun* prsRrun = NULL;
	ImeitemIRMRunMSample* runRsmp = NULL;
	ImeitemIMStep* ste = NULL;
	ImeitemIAMStepPar* steApar = NULL;
	ImeitemIMFile4* fil4 = NULL;
	ImeitemIRMFileMStep1* filRste1 = NULL;
	ImeitemIRMFileMStep2* filRste2 = NULL;
	ImeitemIRMSampleMStep* smpRste = NULL;
	ImeitemITMFileMSample1* filTsmp1 = NULL;
	ImeitemITMFileMSample2* filTsmp2 = NULL;

	uint ixFmncVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

// IP collect.traverse --- BEGIN

	// -- ImeIMFile1
	for (unsigned int ix0=0;ix0<imeimfile1.nodes.size();ix0++) {
		fil1 = imeimfile1.nodes[ix0];

		if (fil1->ref != 0) {
			fil1->iref = ix0+1;
		};
	};

	// -- ImeIMProject
	for (unsigned int ix0=0;ix0<imeimproject.nodes.size();ix0++) {
		prj = imeimproject.nodes[ix0];

		if (prj->ref != 0) {
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMPROJECTSTATE, ixFmncVIop)) {
			dbsfmnc->tblfmncjmprojectstate->loadRefsByPrj(prj->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == prj->refJState) {refs[i] = refs[0]; refs[0] = prj->refJState; break;};
			for (unsigned int i=0;i<refs.size();i++) prj->imeijmprojectstate.nodes.push_back(new ImeitemIJMProjectState(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<prj->imeijmprojectstate.nodes.size();ix1++) {
			prjJste = prj->imeijmprojectstate.nodes[ix1];

			if (prjJste->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMRUN, ixFmncVIop)) {
			dbsfmnc->tblfmncmrun->loadRefsByPrj(prj->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) prj->imeimrun.nodes.push_back(new ImeitemIMRun(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<prj->imeimrun.nodes.size();ix1++) {
			run = prj->imeimrun.nodes[ix1];

			if (run->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMRUNSTATE, ixFmncVIop)) {
				dbsfmnc->tblfmncjmrunstate->loadRefsByRun(run->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == run->refJState) {refs[i] = refs[0]; refs[0] = run->refJState; break;};
				for (unsigned int i=0;i<refs.size();i++) run->imeijmrunstate.nodes.push_back(new ImeitemIJMRunState(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<run->imeijmrunstate.nodes.size();ix2++) {
				runJste = run->imeijmrunstate.nodes[ix2];

				if (runJste->ref != 0) {
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMACTIVITY, ixFmncVIop)) {
				dbsfmnc->tblfmncmactivity->loadRefsByRun(run->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) run->imeimactivity.nodes.push_back(new ImeitemIMActivity(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<run->imeimactivity.nodes.size();ix2++) {
				act = run->imeimactivity.nodes[ix2];

				if (act->ref != 0) {
				};

				if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMSTEP, ixFmncVIop)) {
					dbsfmnc->tblfmncmstep->loadRefsByAct(act->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) act->imeimstep.nodes.push_back(new ImeitemIMStep(dbsfmnc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<act->imeimstep.nodes.size();ix3++) {
					ste = act->imeimstep.nodes[ix3];

					if (ste->ref != 0) {
						ste->hintRlvUref = StubFmnc::getStubTolStd(dbsfmnc, ste->rlvUref, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
						//ste->hintTplRefFmncMStep: STUB
						ste->hintRefFmncMPerson = StubFmnc::getStubPrsWorg(dbsfmnc, ste->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
					};

					if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMSTEPPAR, ixFmncVIop)) {
						dbsfmnc->tblfmncamsteppar->loadRefsBySte(ste->ref, false, refs);
						for (unsigned int i=0;i<refs.size();i++) ste->imeiamsteppar.nodes.push_back(new ImeitemIAMStepPar(dbsfmnc, refs[i]));
					};

					for (unsigned int ix4=0;ix4<ste->imeiamsteppar.nodes.size();ix4++) {
						steApar = ste->imeiamsteppar.nodes[ix4];

						if (steApar->ref != 0) {
							if (steApar->x2IxVTbl == VecFmncVAMStepParTbl::FIL) steApar->hintX2Uref = StubFmnc::getStubFilStd(dbsfmnc, steApar->x2Uref, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
							else if (steApar->x2IxVTbl == VecFmncVAMStepParTbl::SMP) steApar->hintX2Uref = StubFmnc::getStubSmpHsref(dbsfmnc, steApar->x2Uref, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
						};
					};

					if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMFILE4, ixFmncVIop)) {
						dbsfmnc->tblfmncmfile->loadRefsByRetReu(VecFmncVMFileRefTbl::STE, ste->ref, false, refs);
						for (unsigned int i=0;i<refs.size();i++) ste->imeimfile4.nodes.push_back(new ImeitemIMFile4(dbsfmnc, refs[i]));
					};

					for (unsigned int ix4=0;ix4<ste->imeimfile4.nodes.size();ix4++) {
						fil4 = ste->imeimfile4.nodes[ix4];

						if (fil4->ref != 0) {
							fil4->iref = ix4+1;
						};
					};

					if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMFILEMSTEP1, ixFmncVIop)) {
						dbsfmnc->tblfmncrmfilemstep->loadRefsBySte(ste->ref, false, refs);
						for (unsigned int i=0;i<refs.size();i++) ste->imeirmfilemstep1.nodes.push_back(new ImeitemIRMFileMStep1(dbsfmnc, refs[i]));
					};

					for (unsigned int ix4=0;ix4<ste->imeirmfilemstep1.nodes.size();ix4++) {
						filRste1 = ste->imeirmfilemstep1.nodes[ix4];

						if (filRste1->ref != 0) {
							//filRste1->irefRefFmncMFile: IREF
						};

						if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEITMFILEMSAMPLE1, ixFmncVIop)) {
							dbsfmnc->tblfmnctmfilemsample->loadRefsByR(filRste1->ref, false, refs);
							for (unsigned int i=0;i<refs.size();i++) filRste1->imeitmfilemsample1.nodes.push_back(new ImeitemITMFileMSample1(dbsfmnc, refs[i]));
						};

						for (unsigned int ix5=0;ix5<filRste1->imeitmfilemsample1.nodes.size();ix5++) {
							filTsmp1 = filRste1->imeitmfilemsample1.nodes[ix5];

							if (filTsmp1->ref != 0) {
								filTsmp1->hsrefRefFmncMSample = StubFmnc::getStubSmpHsref(dbsfmnc, filTsmp1->refFmncMSample, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
							};
						};
					};

					if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMFILEMSTEP2, ixFmncVIop)) {
						dbsfmnc->tblfmncrmfilemstep->loadRefsBySte(ste->ref, false, refs);
						for (unsigned int i=0;i<refs.size();i++) ste->imeirmfilemstep2.nodes.push_back(new ImeitemIRMFileMStep2(dbsfmnc, refs[i]));
					};

					for (unsigned int ix4=0;ix4<ste->imeirmfilemstep2.nodes.size();ix4++) {
						filRste2 = ste->imeirmfilemstep2.nodes[ix4];

						if (filRste2->ref != 0) {
							//filRste2->irefRefFmncMFile: IREF
						};

						if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEITMFILEMSAMPLE2, ixFmncVIop)) {
							dbsfmnc->tblfmnctmfilemsample->loadRefsByR(filRste2->ref, false, refs);
							for (unsigned int i=0;i<refs.size();i++) filRste2->imeitmfilemsample2.nodes.push_back(new ImeitemITMFileMSample2(dbsfmnc, refs[i]));
						};

						for (unsigned int ix5=0;ix5<filRste2->imeitmfilemsample2.nodes.size();ix5++) {
							filTsmp2 = filRste2->imeitmfilemsample2.nodes[ix5];

							if (filTsmp2->ref != 0) {
								filTsmp2->hsrefRefFmncMSample = StubFmnc::getStubSmpHsref(dbsfmnc, filTsmp2->refFmncMSample, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
							};
						};
					};

					if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMSAMPLEMSTEP, ixFmncVIop)) {
						dbsfmnc->tblfmncrmsamplemstep->loadRefsBySte(ste->ref, false, refs);
						for (unsigned int i=0;i<refs.size();i++) ste->imeirmsamplemstep.nodes.push_back(new ImeitemIRMSampleMStep(dbsfmnc, refs[i]));
					};

					for (unsigned int ix4=0;ix4<ste->imeirmsamplemstep.nodes.size();ix4++) {
						smpRste = ste->imeirmsamplemstep.nodes[ix4];

						if (smpRste->ref != 0) {
							smpRste->hsrefRefFmncMSample = StubFmnc::getStubSmpHsref(dbsfmnc, smpRste->refFmncMSample, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
						};
					};
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMFILE3, ixFmncVIop)) {
				dbsfmnc->tblfmncmfile->loadRefsByRetReu(VecFmncVMFileRefTbl::RUN, run->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) run->imeimfile3.nodes.push_back(new ImeitemIMFile3(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<run->imeimfile3.nodes.size();ix2++) {
				fil3 = run->imeimfile3.nodes[ix2];

				if (fil3->ref != 0) {
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMFABMRUN, ixFmncVIop)) {
				dbsfmnc->tblfmncrmfabmrun->loadRefsByRun(run->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) run->imeirmfabmrun.nodes.push_back(new ImeitemIRMFabMRun(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<run->imeirmfabmrun.nodes.size();ix2++) {
				fabRrun = run->imeirmfabmrun.nodes[ix2];

				if (fabRrun->ref != 0) {
					fabRrun->hintRefFmncMFab = StubFmnc::getStubFabSref(dbsfmnc, fabRrun->refFmncMFab, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMPERSONMRUN, ixFmncVIop)) {
				dbsfmnc->tblfmncrmpersonmrun->loadRefsByRun(run->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) run->imeirmpersonmrun.nodes.push_back(new ImeitemIRMPersonMRun(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<run->imeirmpersonmrun.nodes.size();ix2++) {
				prsRrun = run->imeirmpersonmrun.nodes[ix2];

				if (prsRrun->ref != 0) {
					prsRrun->hintRefFmncMPerson = StubFmnc::getStubPrsWorg(dbsfmnc, prsRrun->refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMRUNMSAMPLE, ixFmncVIop)) {
				dbsfmnc->tblfmncrmrunmsample->loadRefsByRun(run->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) run->imeirmrunmsample.nodes.push_back(new ImeitemIRMRunMSample(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<run->imeirmrunmsample.nodes.size();ix2++) {
				runRsmp = run->imeirmrunmsample.nodes[ix2];

				if (runRsmp->ref != 0) {
					runRsmp->hsrefRefFmncMSample = StubFmnc::getStubSmpHsref(dbsfmnc, runRsmp->refFmncMSample, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};
	};

	// -- ImeIMSample
	for (unsigned int ix0=0;ix0<imeimsample.nodes.size();ix0++) {
		smp = imeimsample.nodes[ix0];

		if (smp->ref != 0) {
			smp->hsrefSupRefFmncMSample = StubFmnc::getStubSmpHsref(dbsfmnc, smp->supRefFmncMSample, ixFmncVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAMSAMPLEPAR, ixFmncVIop)) {
			dbsfmnc->tblfmncamsamplepar->loadRefsBySmp(smp->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) smp->imeiamsamplepar.nodes.push_back(new ImeitemIAMSamplePar(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<smp->imeiamsamplepar.nodes.size();ix1++) {
			smpApar = smp->imeiamsamplepar.nodes[ix1];

			if (smpApar->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIAVKEYLISTKEY, ixFmncVIop)) {
			dbsfmnc->tblfmncavkeylistkey->loadRefsByMtbUrf(VecFmncVMaintable::TBLFMNCMSAMPLE, smp->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) smp->imeiavkeylistkey.nodes.push_back(new ImeitemIAVKeylistKey(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<smp->imeiavkeylistkey.nodes.size();ix1++) {
			klsAkey = smp->imeiavkeylistkey.nodes[ix1];

			if (klsAkey->ref != 0) {
			};

			if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJAVKEYLISTKEY, ixFmncVIop)) {
				dbsfmnc->tblfmncjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
				for (unsigned int i=0;i<refs.size();i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbsfmnc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<klsAkey->imeijavkeylistkey.nodes.size();ix2++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];

				if (kakJkey->ref != 0) {
				};
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIJMSAMPLESTATE, ixFmncVIop)) {
			dbsfmnc->tblfmncjmsamplestate->loadRefsBySmp(smp->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == smp->refJState) {refs[i] = refs[0]; refs[0] = smp->refJState; break;};
			for (unsigned int i=0;i<refs.size();i++) smp->imeijmsamplestate.nodes.push_back(new ImeitemIJMSampleState(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<smp->imeijmsamplestate.nodes.size();ix1++) {
			smpJste = smp->imeijmsamplestate.nodes[ix1];

			if (smpJste->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIMFILE2, ixFmncVIop)) {
			dbsfmnc->tblfmncmfile->loadRefsByRetReu(VecFmncVMFileRefTbl::SMP, smp->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) smp->imeimfile2.nodes.push_back(new ImeitemIMFile2(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<smp->imeimfile2.nodes.size();ix1++) {
			fil2 = smp->imeimfile2.nodes[ix1];

			if (fil2->ref != 0) {
			};
		};

		if (getIxFmncVIop(icsFmncVIop, VecVIme::IMEIRMFILEMSAMPLE, ixFmncVIop)) {
			dbsfmnc->tblfmncrmfilemsample->loadRefsBySmp(smp->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) smp->imeirmfilemsample.nodes.push_back(new ImeitemIRMFileMSample(dbsfmnc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<smp->imeirmfilemsample.nodes.size();ix1++) {
			filRsmp = smp->imeirmfilemsample.nodes[ix1];

			if (filRsmp->ref != 0) {
			};
		};
	};
// IP collect.traverse --- END

// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexFmncElb::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIMFILE1) {
				parseok = imeimfile1.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMPROJECT) {
				parseok = imeimproject.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMSAMPLE) {
				parseok = imeimsample.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexFmncElb::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexFmncElb");

	if (basefound) {
		// look for XML sub-blocks
		imeimfile1.readXML(docctx, basexpath);
		imeimproject.readXML(docctx, basexpath);
		imeimsample.readXML(docctx, basexpath);
	} else {
		imeimfile1 = ImeIMFile1();
		imeimproject = ImeIMProject();
		imeimsample = ImeIMSample();
	};
};

bool IexFmncElb::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexFmncElb::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexFmncElb::writeTxt(
			fstream& outfile
		) {
	imeimfile1.writeTxt(outfile);
	imeimproject.writeTxt(outfile);
	imeimsample.writeTxt(outfile);
};

void IexFmncElb::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexFmncElb");
		imeimfile1.writeXML(wr, shorttags);
		imeimproject.writeXML(wr, shorttags);
		imeimsample.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexFmncElb::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexFmncElb::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexFmncElb::icsFmncVIopInsAll() {
	return {{(uint)VecVIme::IMEIMFILE1,VecFmncVIop::RETRINS},{(uint)VecVIme::IMEIMPROJECT,VecFmncVIop::INS},{(uint)VecVIme::IMEIMSAMPLE,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMSAMPLEPAR,VecFmncVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMPROJECTSTATE,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMSAMPLESTATE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMFILE2,VecFmncVIop::INS},{(uint)VecVIme::IMEIMRUN,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMFILEMSAMPLE,VecFmncVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecFmncVIop::INS},{(uint)VecVIme::IMEIJMRUNSTATE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMACTIVITY,VecFmncVIop::INS},{(uint)VecVIme::IMEIMFILE3,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMFABMRUN,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMPERSONMRUN,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMRUNMSAMPLE,VecFmncVIop::INS},{(uint)VecVIme::IMEIMSTEP,VecFmncVIop::INS},{(uint)VecVIme::IMEIAMSTEPPAR,VecFmncVIop::INS},{(uint)VecVIme::IMEIMFILE4,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMFILEMSTEP1,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMFILEMSTEP2,VecFmncVIop::INS},{(uint)VecVIme::IMEIRMSAMPLEMSTEP,VecFmncVIop::INS},{(uint)VecVIme::IMEITMFILEMSAMPLE1,VecFmncVIop::INS},{(uint)VecVIme::IMEITMFILEMSAMPLE2,VecFmncVIop::INS}};
};

uint IexFmncElb::getIxFmncVIop(
			const map<uint,uint>& icsFmncVIop
			, const uint ixVIme
			, uint& ixFmncVIop
		) {
	ixFmncVIop = 0;

	auto it = icsFmncVIop.find(ixVIme);
	if (it != icsFmncVIop.end()) ixFmncVIop = it->second;

	return ixFmncVIop;
};

void IexFmncElb::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexFmncElb::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
};


