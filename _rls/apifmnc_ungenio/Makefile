# file Makefile
# make file for Fmnc API library, release apifmnc_ungenio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

SRCROOT = /Users/epsi/src
LIBROOT = /Users/epsi/lib

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

INCS = -I/opt/local/include/libxml2
INCS += -I$(SRCROOT)
PCHS = ApiFmnc.h.gch
OBJECTS = ApiFmnc_blks.o ApiFmnc.o
OBJECTS += FmncQAct1NStep.o FmncQActList.o FmncQAdrList.o FmncQArt1NSample.o FmncQArt1NStockitem.o FmncQArtList.o FmncQArtMNOrg.o FmncQArtRef1NFile.o FmncQBilAPos.o FmncQBilList.o FmncQFab1NFabproject.o FmncQFab1NFabuser.o FmncQFabFab1NTool.o FmncQFabList.o FmncQFabMNRun.o FmncQFilList.o FmncQFilMNSample.o FmncQFilMNStep.o FmncQFpj1NBill.o FmncQFpjList.o FmncQFpjMNFabuser.o FmncQFusList.o FmncQFusMNFabproject.o FmncQFusMNTool.o FmncQOrg1NArticle.o FmncQOrg1NStockitem.o FmncQOrgADetail.o FmncQOrgBio1NFabproject.o FmncQOrgHk1NAddress.o FmncQOrgKStocklcn.o FmncQOrgList.o FmncQOrgMNArticle.o FmncQOrgMnf1NTool.o FmncQOrgMNPerson.o FmncQOrgPco1NPurchorder.o FmncQOrgSpl1NPurchorder.o FmncQOrgSup1NOrg.o FmncQOrgSvcMNTool.o FmncQPcoAPos.o FmncQPcoList.o FmncQPrj1NRun.o FmncQPrjList.o FmncQPrsADetail.o FmncQPrsHk1NAddress.o FmncQPrsList.o FmncQPrsMNOrg.o FmncQPrsMNRun.o FmncQRunList.o FmncQRunMNFab.o FmncQRunMNPerson.o FmncQRunMNSample.o FmncQRunRef1NFile.o FmncQRunRun1NActivity.o FmncQSepAPar.o FmncQSepList.o FmncQSepMNFile.o FmncQSepMNSample.o FmncQSepRef1NFile.o FmncQSkiList.o FmncQSmpAPar.o FmncQSmpList.o FmncQSmpMNFile.o FmncQSmpMNRun.o FmncQSmpMNStep.o FmncQSmpRef1NFile.o FmncQSmpSup1NSample.o FmncQStpAPar.o FmncQStpKSteppar.o FmncQStpList.o FmncQStpMNFile.o FmncQStpRef1NFile.o FmncQStpTpl1NStep.o FmncQTol1NArticle.o FmncQTolAAvl.o FmncQTolAChar.o FmncQTolARes.o FmncQTolAUtil.o FmncQTolKSteppar.o FmncQTolKToolchar.o FmncQTolList.o FmncQTolMNFabuser.o FmncQTolMNTooltype.o FmncQTolRef1NFile.o FmncQTolRlv1NStep.o FmncQTolSvcMNOrg.o FmncQTtyKSteppar.o FmncQTtyKToolchar.o FmncQTtyList.o FmncQTtyMNTool.o FmncQTtyRlv1NStep.o FmncQTtySup1NTooltype.o FmncQUsgAAccess.o FmncQUsgList.o FmncQUsgMNUser.o FmncQUsr1NSession.o FmncQUsrAAccess.o FmncQUsrList.o FmncQUsrMNUsergroup.o
OBJECTS += CrdFmncAct.o CrdFmncAdr.o CrdFmncArt.o CrdFmncBil.o CrdFmncFab.o CrdFmncFil.o CrdFmncFpj.o CrdFmncFus.o CrdFmncNav.o CrdFmncOrg.o CrdFmncPco.o CrdFmncPrj.o CrdFmncPrs.o CrdFmncRun.o CrdFmncSep.o CrdFmncSki.o CrdFmncSmp.o CrdFmncStp.o CrdFmncTol.o CrdFmncTty.o CrdFmncUsg.o CrdFmncUsr.o DlgFmncActNew.o DlgFmncFabExpfab.o DlgFmncFabImpfab.o DlgFmncFabNew.o DlgFmncNavLoaini.o DlgFmncOrgExporg.o DlgFmncOrgImporg.o DlgFmncOrgNew.o DlgFmncPrjExpelb.o DlgFmncPrjImpelb.o DlgFmncPrjNew.o DlgFmncRunGenrep.o DlgFmncRunNew.o DlgFmncSmpGenrep.o DlgFmncSmpNew.o PnlFmncAct1NStep.o PnlFmncActDetail.o PnlFmncActHeadbar.o PnlFmncActList.o PnlFmncActRec.o PnlFmncAdrDetail.o PnlFmncAdrHeadbar.o PnlFmncAdrList.o PnlFmncAdrRec.o PnlFmncArt1NSample.o PnlFmncArt1NStockitem.o PnlFmncArtDetail.o PnlFmncArtHeadbar.o PnlFmncArtList.o PnlFmncArtMNOrg.o PnlFmncArtRec.o PnlFmncArtRef1NFile.o PnlFmncBilAPos.o PnlFmncBilDetail.o PnlFmncBilHeadbar.o PnlFmncBilList.o PnlFmncBilRec.o PnlFmncFab1NFabproject.o PnlFmncFab1NFabuser.o PnlFmncFabDetail.o PnlFmncFabFab1NTool.o PnlFmncFabHeadbar.o PnlFmncFabList.o PnlFmncFabMNRun.o PnlFmncFabRec.o PnlFmncFilDetail.o PnlFmncFilHeadbar.o PnlFmncFilList.o PnlFmncFilMNSample.o PnlFmncFilMNStep.o PnlFmncFilRec.o PnlFmncFpj1NBill.o PnlFmncFpjDetail.o PnlFmncFpjHeadbar.o PnlFmncFpjList.o PnlFmncFpjMNFabuser.o PnlFmncFpjRec.o PnlFmncFusDetail.o PnlFmncFusHeadbar.o PnlFmncFusList.o PnlFmncFusMNFabproject.o PnlFmncFusMNTool.o PnlFmncFusRec.o PnlFmncNavAdmin.o PnlFmncNavFabmgmt.o PnlFmncNavHeadbar.o PnlFmncNavLabbook.o PnlFmncNavPre.o PnlFmncNavSupply.o PnlFmncOrg1NArticle.o PnlFmncOrg1NStockitem.o PnlFmncOrgADetail.o PnlFmncOrgBio1NFabproject.o PnlFmncOrgDetail.o PnlFmncOrgHeadbar.o PnlFmncOrgHk1NAddress.o PnlFmncOrgKStocklcn.o PnlFmncOrgList.o PnlFmncOrgMNArticle.o PnlFmncOrgMnf1NTool.o PnlFmncOrgMNPerson.o PnlFmncOrgPco1NPurchorder.o PnlFmncOrgRec.o PnlFmncOrgSpl1NPurchorder.o PnlFmncOrgSup1NOrg.o PnlFmncOrgSvcMNTool.o PnlFmncPcoAPos.o PnlFmncPcoDetail.o PnlFmncPcoHeadbar.o PnlFmncPcoList.o PnlFmncPcoRec.o PnlFmncPrj1NRun.o PnlFmncPrjDetail.o PnlFmncPrjHeadbar.o PnlFmncPrjList.o PnlFmncPrjRec.o PnlFmncPrsADetail.o PnlFmncPrsDetail.o PnlFmncPrsHeadbar.o PnlFmncPrsHk1NAddress.o PnlFmncPrsList.o PnlFmncPrsMNOrg.o PnlFmncPrsMNRun.o PnlFmncPrsRec.o PnlFmncRunDetail.o PnlFmncRunHeadbar.o PnlFmncRunList.o PnlFmncRunMNFab.o PnlFmncRunMNPerson.o PnlFmncRunMNSample.o PnlFmncRunRec.o PnlFmncRunRef1NFile.o PnlFmncRunRun1NActivity.o PnlFmncSepAPar.o PnlFmncSepDetail.o PnlFmncSepHeadbar.o PnlFmncSepList.o PnlFmncSepMNFile.o PnlFmncSepMNSample.o PnlFmncSepRec.o PnlFmncSepRef1NFile.o PnlFmncSkiDetail.o PnlFmncSkiHeadbar.o PnlFmncSkiList.o PnlFmncSkiRec.o PnlFmncSmpAPar.o PnlFmncSmpDetail.o PnlFmncSmpHeadbar.o PnlFmncSmpList.o PnlFmncSmpMNFile.o PnlFmncSmpMNRun.o PnlFmncSmpMNStep.o PnlFmncSmpRec.o PnlFmncSmpRef1NFile.o PnlFmncSmpSup1NSample.o PnlFmncStpAPar.o PnlFmncStpDetail.o PnlFmncStpHeadbar.o PnlFmncStpKSteppar.o PnlFmncStpList.o PnlFmncStpMNFile.o PnlFmncStpRec.o PnlFmncStpRef1NFile.o PnlFmncStpTpl1NStep.o PnlFmncTol1NArticle.o PnlFmncTolAAvl.o PnlFmncTolAChar.o PnlFmncTolARes.o PnlFmncTolAUtil.o PnlFmncTolDetail.o PnlFmncTolHeadbar.o PnlFmncTolKSteppar.o PnlFmncTolKToolchar.o PnlFmncTolList.o PnlFmncTolMNFabuser.o PnlFmncTolMNTooltype.o PnlFmncTolRec.o PnlFmncTolRef1NFile.o PnlFmncTolRlv1NStep.o PnlFmncTolSvcMNOrg.o PnlFmncTtyDetail.o PnlFmncTtyHeadbar.o PnlFmncTtyKSteppar.o PnlFmncTtyKToolchar.o PnlFmncTtyList.o PnlFmncTtyMNTool.o PnlFmncTtyRec.o PnlFmncTtyRlv1NStep.o PnlFmncTtySup1NTooltype.o PnlFmncUsgAAccess.o PnlFmncUsgDetail.o PnlFmncUsgHeadbar.o PnlFmncUsgList.o PnlFmncUsgMNUser.o PnlFmncUsgRec.o PnlFmncUsr1NSession.o PnlFmncUsrAAccess.o PnlFmncUsrDetail.o PnlFmncUsrHeadbar.o PnlFmncUsrList.o PnlFmncUsrMNUsergroup.o PnlFmncUsrRec.o QryFmncAct1NStep.o QryFmncActList.o QryFmncAdrList.o QryFmncArt1NSample.o QryFmncArt1NStockitem.o QryFmncArtList.o QryFmncArtMNOrg.o QryFmncArtRef1NFile.o QryFmncBilAPos.o QryFmncBilList.o QryFmncFab1NFabproject.o QryFmncFab1NFabuser.o QryFmncFabFab1NTool.o QryFmncFabList.o QryFmncFabMNRun.o QryFmncFilList.o QryFmncFilMNSample.o QryFmncFilMNStep.o QryFmncFpj1NBill.o QryFmncFpjList.o QryFmncFpjMNFabuser.o QryFmncFusList.o QryFmncFusMNFabproject.o QryFmncFusMNTool.o QryFmncOrg1NArticle.o QryFmncOrg1NStockitem.o QryFmncOrgADetail.o QryFmncOrgBio1NFabproject.o QryFmncOrgHk1NAddress.o QryFmncOrgKStocklcn.o QryFmncOrgList.o QryFmncOrgMNArticle.o QryFmncOrgMnf1NTool.o QryFmncOrgMNPerson.o QryFmncOrgPco1NPurchorder.o QryFmncOrgSpl1NPurchorder.o QryFmncOrgSup1NOrg.o QryFmncOrgSvcMNTool.o QryFmncPcoAPos.o QryFmncPcoList.o QryFmncPrj1NRun.o QryFmncPrjList.o QryFmncPrsADetail.o QryFmncPrsHk1NAddress.o QryFmncPrsList.o QryFmncPrsMNOrg.o QryFmncPrsMNRun.o QryFmncRunList.o QryFmncRunMNFab.o QryFmncRunMNPerson.o QryFmncRunMNSample.o QryFmncRunRef1NFile.o QryFmncRunRun1NActivity.o QryFmncSepAPar.o QryFmncSepList.o QryFmncSepMNFile.o QryFmncSepMNSample.o QryFmncSepRef1NFile.o QryFmncSkiList.o QryFmncSmpAPar.o QryFmncSmpList.o QryFmncSmpMNFile.o QryFmncSmpMNRun.o QryFmncSmpMNStep.o QryFmncSmpRef1NFile.o QryFmncSmpSup1NSample.o QryFmncStpAPar.o QryFmncStpKSteppar.o QryFmncStpList.o QryFmncStpMNFile.o QryFmncStpRef1NFile.o QryFmncStpTpl1NStep.o QryFmncTol1NArticle.o QryFmncTolAAvl.o QryFmncTolAChar.o QryFmncTolARes.o QryFmncTolAUtil.o QryFmncTolKSteppar.o QryFmncTolKToolchar.o QryFmncTolList.o QryFmncTolMNFabuser.o QryFmncTolMNTooltype.o QryFmncTolRef1NFile.o QryFmncTolRlv1NStep.o QryFmncTolSvcMNOrg.o QryFmncTtyKSteppar.o QryFmncTtyKToolchar.o QryFmncTtyList.o QryFmncTtyMNTool.o QryFmncTtyRlv1NStep.o QryFmncTtySup1NTooltype.o QryFmncUsgAAccess.o QryFmncUsgList.o QryFmncUsgMNUser.o QryFmncUsr1NSession.o QryFmncUsrAAccess.o QryFmncUsrList.o QryFmncUsrMNUsergroup.o RootFmnc.o SessFmnc.o
OBJECTS += VecFmncVDpch.o VecFmncVExpstate.o VecFmncVQrystate.o VecFmncVReqitmode.o

LIBRARY = libapifmnc

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

