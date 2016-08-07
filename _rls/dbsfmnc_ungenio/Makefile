# file Makefile
# make file for Fmnc database access library, release dbsfmnc_ungenio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

SRCROOT = /Users/epsi/src
LIBROOT = /Users/epsi/lib

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

INCS = -I/opt/local/include/libxml2 -I/usr/local/mysql/include -I/opt/local/include/postgresql84
INCS += -I$(SRCROOT)
PCHS = DbsFmnc.h.gch
OBJECTS = DbsFmnc.o
OBJECTS += FmncQAct1NStep.o FmncQActList.o FmncQAdrList.o FmncQArt1NSample.o FmncQArt1NStockitem.o FmncQArtList.o FmncQArtMNOrg.o FmncQArtRef1NFile.o FmncQBilAPos.o FmncQBilList.o FmncQFab1NFabproject.o FmncQFab1NFabuser.o FmncQFabFab1NTool.o FmncQFabList.o FmncQFabMNRun.o FmncQFilList.o FmncQFilMNSample.o FmncQFilMNStep.o FmncQFpj1NBill.o FmncQFpjList.o FmncQFpjMNFabuser.o FmncQFusList.o FmncQFusMNFabproject.o FmncQFusMNTool.o FmncQOrg1NArticle.o FmncQOrg1NStockitem.o FmncQOrgADetail.o FmncQOrgBio1NFabproject.o FmncQOrgHk1NAddress.o FmncQOrgKStocklcn.o FmncQOrgList.o FmncQOrgMNArticle.o FmncQOrgMnf1NTool.o FmncQOrgMNPerson.o FmncQOrgPco1NPurchorder.o FmncQOrgSpl1NPurchorder.o FmncQOrgSup1NOrg.o FmncQOrgSvcMNTool.o FmncQPcoAPos.o FmncQPcoList.o FmncQPreselect.o FmncQPrj1NRun.o FmncQPrjList.o FmncQPrsADetail.o FmncQPrsHk1NAddress.o FmncQPrsList.o FmncQPrsMNOrg.o FmncQPrsMNRun.o FmncQRunList.o FmncQRunMNFab.o FmncQRunMNPerson.o FmncQRunMNSample.o FmncQRunRef1NFile.o FmncQRunRun1NActivity.o FmncQSelect.o FmncQSepAPar.o FmncQSepList.o FmncQSepMNFile.o FmncQSepMNSample.o FmncQSepRef1NFile.o FmncQSkiList.o FmncQSmpAPar.o FmncQSmpList.o FmncQSmpMNFile.o FmncQSmpMNRun.o FmncQSmpMNStep.o FmncQSmpRef1NFile.o FmncQSmpSup1NSample.o FmncQStpAPar.o FmncQStpKSteppar.o FmncQStpList.o FmncQStpMNFile.o FmncQStpRef1NFile.o FmncQStpTpl1NStep.o FmncQTol1NArticle.o FmncQTolAAvl.o FmncQTolAChar.o FmncQTolARes.o FmncQTolAUtil.o FmncQTolKSteppar.o FmncQTolKToolchar.o FmncQTolList.o FmncQTolMNFabuser.o FmncQTolMNTooltype.o FmncQTolRef1NFile.o FmncQTolRlv1NStep.o FmncQTolSvcMNOrg.o FmncQTtyKSteppar.o FmncQTtyKToolchar.o FmncQTtyList.o FmncQTtyMNTool.o FmncQTtyRlv1NStep.o FmncQTtySup1NTooltype.o FmncQUsgAAccess.o FmncQUsgList.o FmncQUsgMNUser.o FmncQUsr1NSession.o FmncQUsrAAccess.o FmncQUsrList.o FmncQUsrMNUsergroup.o
OBJECTS += FmncAccRMUserUniversal.o FmncAMBillPos.o FmncAMOrgDetail.o FmncAMPersonDetail.o FmncAMPurchorderPos.o FmncAMSamplePar.o FmncAMStepPar.o FmncAMToolAvl.o FmncAMToolChar.o FmncAMToolRes.o FmncAMToolUtil.o FmncAMUserAccess.o FmncAMUsergroupAccess.o FmncAVControlPar.o FmncAVKeylistKey.o FmncAVValuelistVal.o FmncCFile.o FmncFabSMPersonMTool.o FmncHistRMUserUniversal.o FmncJAVKeylistKey.o FmncJMBillState.o FmncJMFabprojectState.o FmncJMFabuserState.o FmncJMOrgTitle.o FmncJMPersonLastname.o FmncJMProjectState.o FmncJMPurchorderState.o FmncJMRunState.o FmncJMSampleState.o FmncJMStockitemQuantity.o FmncJMToolUnitprice.o FmncJMUserState.o FmncMActivity.o FmncMAddress.o FmncMArticle.o FmncMBill.o FmncMFab.o FmncMFabproject.o FmncMFabuser.o FmncMFile.o FmncMnfSMPersonMTool.o FmncMOrg.o FmncMPerson.o FmncMProject.o FmncMPurchorder.o FmncMRun.o FmncMSample.o FmncMSession.o FmncMStep.o FmncMStockitem.o FmncMTool.o FmncMTooltype.o FmncMUser.o FmncMUsergroup.o FmncRMArticleMOrg.o FmncRMFabMRun.o FmncRMFabprojectMFabuser.o FmncRMFabuserMTool.o FmncRMFileMSample.o FmncRMFileMStep.o FmncRMOrgMPerson.o FmncRMPersonMRun.o FmncRMRunMSample.o FmncRMSampleMStep.o FmncRMToolMTooltype.o FmncRMUsergroupUniversal.o FmncRMUserMUsergroup.o FmncSvcRMOrgMTool.o FmncSvcTMPersonMTool.o FmncTMFileMSample.o
OBJECTS += VecFmncVAccess.o VecFmncVCard.o VecFmncVControl.o VecFmncVKeylist.o VecFmncVLat.o VecFmncVLocale.o VecFmncVLop.o VecFmncVMaintable.o VecFmncVOolop.o VecFmncVPreset.o VecFmncVUserlevel.o VecFmncVValuelist.o VecFmncVAMStepParTbl.o VecFmncVAMToolAvlWkday.o VecFmncVMAddressHkTbl.o VecFmncVMBillState.o VecFmncVMFabprojectState.o VecFmncVMFabuserState.o VecFmncVMFileRefTbl.o VecFmncVMPersonSex.o VecFmncVMProjectState.o VecFmncVMPurchorderState.o VecFmncVMRunState.o VecFmncVMSampleState.o VecFmncVMStepRlvTbl.o VecFmncVMUserState.o VecFmncVRMFileMStepDir.o VecFmncWUiaccess.o VecFmncWMOrgDerivate.o VecFmncWMPersonDerivate.o VecFmncWMStepFilecfg.o

LIBRARY = libdbsfmnc

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

.cpp.o :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

all:	$(LIBRARY)

$(LIBRARY):	$(PCHS) $(OBJECTS)
	ar rcs $(LIBRARY).a $(OBJECTS)
	rm -f *.o

install:
	cp $(LIBRARY).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

