/**
  * \file DbsFmnc.h
  * C++ wrapper for database DbsFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DBSFMNC_H
#define DBSFMNC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include "VecFmncVAccess.h"
#include "VecFmncVCard.h"
#include "VecFmncVControl.h"
#include "VecFmncVKeylist.h"
#include "VecFmncVLat.h"
#include "VecFmncVLocale.h"
#include "VecFmncVLop.h"
#include "VecFmncVMaintable.h"
#include "VecFmncVOolop.h"
#include "VecFmncVPreset.h"
#include "VecFmncVUserlevel.h"
#include "VecFmncVValuelist.h"
#include "VecFmncWUiaccess.h"
#include "VecFmncVAMStepParTbl.h"
#include "VecFmncVAMToolAvlWkday.h"
#include "VecFmncVMAddressHkTbl.h"
#include "VecFmncVMBillState.h"
#include "VecFmncVMFabprojectState.h"
#include "VecFmncVMFabuserState.h"
#include "VecFmncVMFileRefTbl.h"
#include "VecFmncVMPersonSex.h"
#include "VecFmncVMProjectState.h"
#include "VecFmncVMPurchorderState.h"
#include "VecFmncVMRunState.h"
#include "VecFmncVMSampleState.h"
#include "VecFmncVMStepRlvTbl.h"
#include "VecFmncVMUserState.h"
#include "VecFmncVRMFileMStepDir.h"
#include "VecFmncWMOrgDerivate.h"
#include "VecFmncWMPersonDerivate.h"
#include "VecFmncWMStepFilecfg.h"

#include "FmncAccRMUserUniversal.h"
#include "FmncAMBillPos.h"
#include "FmncAMOrgDetail.h"
#include "FmncAMPersonDetail.h"
#include "FmncAMPurchorderPos.h"
#include "FmncAMSamplePar.h"
#include "FmncAMStepPar.h"
#include "FmncAMToolAvl.h"
#include "FmncAMToolChar.h"
#include "FmncAMToolRes.h"
#include "FmncAMToolUtil.h"
#include "FmncAMUserAccess.h"
#include "FmncAMUsergroupAccess.h"
#include "FmncAVControlPar.h"
#include "FmncAVKeylistKey.h"
#include "FmncAVValuelistVal.h"
#include "FmncCFile.h"
#include "FmncFabSMPersonMTool.h"
#include "FmncHistRMUserUniversal.h"
#include "FmncJAVKeylistKey.h"
#include "FmncJMBillState.h"
#include "FmncJMFabprojectState.h"
#include "FmncJMFabuserState.h"
#include "FmncJMOrgTitle.h"
#include "FmncJMPersonLastname.h"
#include "FmncJMProjectState.h"
#include "FmncJMPurchorderState.h"
#include "FmncJMRunState.h"
#include "FmncJMSampleState.h"
#include "FmncJMStockitemQuantity.h"
#include "FmncJMToolUnitprice.h"
#include "FmncJMUserState.h"
#include "FmncMActivity.h"
#include "FmncMAddress.h"
#include "FmncMArticle.h"
#include "FmncMBill.h"
#include "FmncMFab.h"
#include "FmncMFabproject.h"
#include "FmncMFabuser.h"
#include "FmncMFile.h"
#include "FmncMnfSMPersonMTool.h"
#include "FmncMOrg.h"
#include "FmncMPerson.h"
#include "FmncMProject.h"
#include "FmncMPurchorder.h"
#include "FmncMRun.h"
#include "FmncMSample.h"
#include "FmncMSession.h"
#include "FmncMStep.h"
#include "FmncMStockitem.h"
#include "FmncMTool.h"
#include "FmncMTooltype.h"
#include "FmncMUser.h"
#include "FmncMUsergroup.h"
#include "FmncRMArticleMOrg.h"
#include "FmncRMFabMRun.h"
#include "FmncRMFabprojectMFabuser.h"
#include "FmncRMFabuserMTool.h"
#include "FmncRMFileMSample.h"
#include "FmncRMFileMStep.h"
#include "FmncRMOrgMPerson.h"
#include "FmncRMPersonMRun.h"
#include "FmncRMRunMSample.h"
#include "FmncRMSampleMStep.h"
#include "FmncRMToolMTooltype.h"
#include "FmncRMUsergroupUniversal.h"
#include "FmncRMUserMUsergroup.h"
#include "FmncSvcRMOrgMTool.h"
#include "FmncSvcTMPersonMTool.h"
#include "FmncTMFileMSample.h"

#include "FmncQAct1NStep.h"
#include "FmncQActList.h"
#include "FmncQAdrList.h"
#include "FmncQArt1NSample.h"
#include "FmncQArt1NStockitem.h"
#include "FmncQArtList.h"
#include "FmncQArtMNOrg.h"
#include "FmncQArtRef1NFile.h"
#include "FmncQBilAPos.h"
#include "FmncQBilList.h"
#include "FmncQFab1NFabproject.h"
#include "FmncQFab1NFabuser.h"
#include "FmncQFabFab1NTool.h"
#include "FmncQFabList.h"
#include "FmncQFabMNRun.h"
#include "FmncQFilList.h"
#include "FmncQFilMNSample.h"
#include "FmncQFilMNStep.h"
#include "FmncQFpj1NBill.h"
#include "FmncQFpjList.h"
#include "FmncQFpjMNFabuser.h"
#include "FmncQFusList.h"
#include "FmncQFusMNFabproject.h"
#include "FmncQFusMNTool.h"
#include "FmncQOrg1NArticle.h"
#include "FmncQOrg1NStockitem.h"
#include "FmncQOrgADetail.h"
#include "FmncQOrgBio1NFabproject.h"
#include "FmncQOrgHk1NAddress.h"
#include "FmncQOrgKStocklcn.h"
#include "FmncQOrgList.h"
#include "FmncQOrgMNArticle.h"
#include "FmncQOrgMnf1NTool.h"
#include "FmncQOrgMNPerson.h"
#include "FmncQOrgPco1NPurchorder.h"
#include "FmncQOrgSpl1NPurchorder.h"
#include "FmncQOrgSup1NOrg.h"
#include "FmncQOrgSvcMNTool.h"
#include "FmncQPcoAPos.h"
#include "FmncQPcoList.h"
#include "FmncQPreselect.h"
#include "FmncQPrj1NRun.h"
#include "FmncQPrjList.h"
#include "FmncQPrsADetail.h"
#include "FmncQPrsHk1NAddress.h"
#include "FmncQPrsList.h"
#include "FmncQPrsMNOrg.h"
#include "FmncQPrsMNRun.h"
#include "FmncQRunList.h"
#include "FmncQRunMNFab.h"
#include "FmncQRunMNPerson.h"
#include "FmncQRunMNSample.h"
#include "FmncQRunRef1NFile.h"
#include "FmncQRunRun1NActivity.h"
#include "FmncQSelect.h"
#include "FmncQSepAPar.h"
#include "FmncQSepList.h"
#include "FmncQSepMNFile.h"
#include "FmncQSepMNSample.h"
#include "FmncQSepRef1NFile.h"
#include "FmncQSkiList.h"
#include "FmncQSmpAPar.h"
#include "FmncQSmpList.h"
#include "FmncQSmpMNFile.h"
#include "FmncQSmpMNRun.h"
#include "FmncQSmpMNStep.h"
#include "FmncQSmpRef1NFile.h"
#include "FmncQSmpSup1NSample.h"
#include "FmncQStpAPar.h"
#include "FmncQStpKSteppar.h"
#include "FmncQStpList.h"
#include "FmncQStpMNFile.h"
#include "FmncQStpRef1NFile.h"
#include "FmncQStpTpl1NStep.h"
#include "FmncQTol1NArticle.h"
#include "FmncQTolAAvl.h"
#include "FmncQTolAChar.h"
#include "FmncQTolARes.h"
#include "FmncQTolAUtil.h"
#include "FmncQTolKSteppar.h"
#include "FmncQTolKToolchar.h"
#include "FmncQTolList.h"
#include "FmncQTolMNFabuser.h"
#include "FmncQTolMNTooltype.h"
#include "FmncQTolRef1NFile.h"
#include "FmncQTolRlv1NStep.h"
#include "FmncQTolSvcMNOrg.h"
#include "FmncQTtyKSteppar.h"
#include "FmncQTtyKToolchar.h"
#include "FmncQTtyList.h"
#include "FmncQTtyMNTool.h"
#include "FmncQTtyRlv1NStep.h"
#include "FmncQTtySup1NTooltype.h"
#include "FmncQUsgAAccess.h"
#include "FmncQUsgList.h"
#include "FmncQUsgMNUser.h"
#include "FmncQUsr1NSession.h"
#include "FmncQUsrAAccess.h"
#include "FmncQUsrList.h"
#include "FmncQUsrMNUsergroup.h"

/**
  * DbsFmnc
  */
class DbsFmnc {

public:
	DbsFmnc();
	~DbsFmnc();

	void init(const uint _ixDbsVDbstype, const string& _dbspath, const string& _dbsname, const string& _ip, const uint _port, const string& _username, const string& _password);
	void term();

// IP inittermMy --- BEGIN
	void initMy();
	void termMy();
// IP inittermMy --- END
// IP inittermPg --- BEGIN
	void initPg();
	void termPg();
// IP inittermPg --- END

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	int port;

	bool initdone;

// IP dbsMy --- BEGIN
	MYSQL* dbsMy;
// IP dbsMy --- END
// IP dbsPg --- BEGIN
	PGconn* dbsPg;
// IP dbsPg --- END

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

// IP transactMy --- BEGIN
	void beginMy();
	bool commitMy();
	void rollbackMy();
// IP transactMy --- END
// IP transactPg --- BEGIN
	void beginPg();
	bool commitPg();
	void rollbackPg();
// IP transactPg --- END

																													//! execute a SQL query returning a single ubigint (arbitrary tables)
	bool loadUbigintBySQL(const string& sqlstr, ubigint& val);
	bool loadStringBySQL(const string& sqlstr, string& val);//!< execute a SQL query returning a single string (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	ubigint loadRefsBySQL(const string& sqlstr, const bool append, vector<ubigint>& refs);

// IP loadfctsMy --- BEGIN
	bool loadUbigintBySQLMy(const string& sqlstr, ubigint& val);
	bool loadStringBySQLMy(const string& sqlstr, string& val);
	ubigint loadRefsBySQLMy(const string& sqlstr, const bool append, vector<ubigint>& refs);
// IP loadfctsMy --- END
// IP loadfctsPg --- BEGIN
	bool loadUbigintBySQLPg(const string& sqlstr, ubigint& val);
	bool loadStringBySQLPg(const string& sqlstr, string& val);
	ubigint loadRefsBySQLPg(const string& sqlstr, const bool append, vector<ubigint>& refs);
// IP loadfctsPg --- END

	void executeQuery(const string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const string& sqlstrmy, const string& sqlstrpg);
	void executeFile(const string& fullpath);								//!< SQL file batch execution

public:
	void fillFeedFromKlst(const uint klsIxFmncVKeylist, const uint ixFmncVLocale, Feed& feed);
	void fillFeedFromKlstByMtbUref(const uint klsIxFmncVKeylist, const uint x1IxFmncVMaintable, const ubigint x1Uref, const uint ixFmncVLocale, Feed& feed);

	string getKlstTitleBySref(const uint klsIxFmncVKeylist, const string& sref, const uint ixFmncVLocale = 0);
	string getKlstTitleByMtbUrefSref(const uint klsIxFmncVKeylist, const uint x1IxFmncVMaintable, const ubigint x1Uref, const string& sref, const uint ixFmncVLocale = 0);

	void fillFeedFromVlst(const uint vlsIxFmncVValuelist, const uint x1IxFmncVLocale, Feed& feed);

public:
	TblFmncAccRMUserUniversal* tblfmncaccrmuseruniversal;
	TblFmncAMBillPos* tblfmncambillpos;
	TblFmncAMOrgDetail* tblfmncamorgdetail;
	TblFmncAMPersonDetail* tblfmncampersondetail;
	TblFmncAMPurchorderPos* tblfmncampurchorderpos;
	TblFmncAMSamplePar* tblfmncamsamplepar;
	TblFmncAMStepPar* tblfmncamsteppar;
	TblFmncAMToolAvl* tblfmncamtoolavl;
	TblFmncAMToolChar* tblfmncamtoolchar;
	TblFmncAMToolRes* tblfmncamtoolres;
	TblFmncAMToolUtil* tblfmncamtoolutil;
	TblFmncAMUserAccess* tblfmncamuseraccess;
	TblFmncAMUsergroupAccess* tblfmncamusergroupaccess;
	TblFmncAVControlPar* tblfmncavcontrolpar;
	TblFmncAVKeylistKey* tblfmncavkeylistkey;
	TblFmncAVValuelistVal* tblfmncavvaluelistval;
	TblFmncCFile* tblfmnccfile;
	TblFmncFabSMPersonMTool* tblfmncfabsmpersonmtool;
	TblFmncHistRMUserUniversal* tblfmnchistrmuseruniversal;
	TblFmncJAVKeylistKey* tblfmncjavkeylistkey;
	TblFmncJMBillState* tblfmncjmbillstate;
	TblFmncJMFabprojectState* tblfmncjmfabprojectstate;
	TblFmncJMFabuserState* tblfmncjmfabuserstate;
	TblFmncJMOrgTitle* tblfmncjmorgtitle;
	TblFmncJMPersonLastname* tblfmncjmpersonlastname;
	TblFmncJMProjectState* tblfmncjmprojectstate;
	TblFmncJMPurchorderState* tblfmncjmpurchorderstate;
	TblFmncJMRunState* tblfmncjmrunstate;
	TblFmncJMSampleState* tblfmncjmsamplestate;
	TblFmncJMStockitemQuantity* tblfmncjmstockitemquantity;
	TblFmncJMToolUnitprice* tblfmncjmtoolunitprice;
	TblFmncJMUserState* tblfmncjmuserstate;
	TblFmncMActivity* tblfmncmactivity;
	TblFmncMAddress* tblfmncmaddress;
	TblFmncMArticle* tblfmncmarticle;
	TblFmncMBill* tblfmncmbill;
	TblFmncMFab* tblfmncmfab;
	TblFmncMFabproject* tblfmncmfabproject;
	TblFmncMFabuser* tblfmncmfabuser;
	TblFmncMFile* tblfmncmfile;
	TblFmncMnfSMPersonMTool* tblfmncmnfsmpersonmtool;
	TblFmncMOrg* tblfmncmorg;
	TblFmncMPerson* tblfmncmperson;
	TblFmncMProject* tblfmncmproject;
	TblFmncMPurchorder* tblfmncmpurchorder;
	TblFmncMRun* tblfmncmrun;
	TblFmncMSample* tblfmncmsample;
	TblFmncMSession* tblfmncmsession;
	TblFmncMStep* tblfmncmstep;
	TblFmncMStockitem* tblfmncmstockitem;
	TblFmncMTool* tblfmncmtool;
	TblFmncMTooltype* tblfmncmtooltype;
	TblFmncMUser* tblfmncmuser;
	TblFmncMUsergroup* tblfmncmusergroup;
	TblFmncRMArticleMOrg* tblfmncrmarticlemorg;
	TblFmncRMFabMRun* tblfmncrmfabmrun;
	TblFmncRMFabprojectMFabuser* tblfmncrmfabprojectmfabuser;
	TblFmncRMFabuserMTool* tblfmncrmfabusermtool;
	TblFmncRMFileMSample* tblfmncrmfilemsample;
	TblFmncRMFileMStep* tblfmncrmfilemstep;
	TblFmncRMOrgMPerson* tblfmncrmorgmperson;
	TblFmncRMPersonMRun* tblfmncrmpersonmrun;
	TblFmncRMRunMSample* tblfmncrmrunmsample;
	TblFmncRMSampleMStep* tblfmncrmsamplemstep;
	TblFmncRMToolMTooltype* tblfmncrmtoolmtooltype;
	TblFmncRMUsergroupUniversal* tblfmncrmusergroupuniversal;
	TblFmncRMUserMUsergroup* tblfmncrmusermusergroup;
	TblFmncSvcRMOrgMTool* tblfmncsvcrmorgmtool;
	TblFmncSvcTMPersonMTool* tblfmncsvctmpersonmtool;
	TblFmncTMFileMSample* tblfmnctmfilemsample;

	TblFmncQAct1NStep* tblfmncqact1nstep;
	TblFmncQActList* tblfmncqactlist;
	TblFmncQAdrList* tblfmncqadrlist;
	TblFmncQArt1NSample* tblfmncqart1nsample;
	TblFmncQArt1NStockitem* tblfmncqart1nstockitem;
	TblFmncQArtList* tblfmncqartlist;
	TblFmncQArtMNOrg* tblfmncqartmnorg;
	TblFmncQArtRef1NFile* tblfmncqartref1nfile;
	TblFmncQBilAPos* tblfmncqbilapos;
	TblFmncQBilList* tblfmncqbillist;
	TblFmncQFab1NFabproject* tblfmncqfab1nfabproject;
	TblFmncQFab1NFabuser* tblfmncqfab1nfabuser;
	TblFmncQFabFab1NTool* tblfmncqfabfab1ntool;
	TblFmncQFabList* tblfmncqfablist;
	TblFmncQFabMNRun* tblfmncqfabmnrun;
	TblFmncQFilList* tblfmncqfillist;
	TblFmncQFilMNSample* tblfmncqfilmnsample;
	TblFmncQFilMNStep* tblfmncqfilmnstep;
	TblFmncQFpj1NBill* tblfmncqfpj1nbill;
	TblFmncQFpjList* tblfmncqfpjlist;
	TblFmncQFpjMNFabuser* tblfmncqfpjmnfabuser;
	TblFmncQFusList* tblfmncqfuslist;
	TblFmncQFusMNFabproject* tblfmncqfusmnfabproject;
	TblFmncQFusMNTool* tblfmncqfusmntool;
	TblFmncQOrg1NArticle* tblfmncqorg1narticle;
	TblFmncQOrg1NStockitem* tblfmncqorg1nstockitem;
	TblFmncQOrgADetail* tblfmncqorgadetail;
	TblFmncQOrgBio1NFabproject* tblfmncqorgbio1nfabproject;
	TblFmncQOrgHk1NAddress* tblfmncqorghk1naddress;
	TblFmncQOrgKStocklcn* tblfmncqorgkstocklcn;
	TblFmncQOrgList* tblfmncqorglist;
	TblFmncQOrgMNArticle* tblfmncqorgmnarticle;
	TblFmncQOrgMnf1NTool* tblfmncqorgmnf1ntool;
	TblFmncQOrgMNPerson* tblfmncqorgmnperson;
	TblFmncQOrgPco1NPurchorder* tblfmncqorgpco1npurchorder;
	TblFmncQOrgSpl1NPurchorder* tblfmncqorgspl1npurchorder;
	TblFmncQOrgSup1NOrg* tblfmncqorgsup1norg;
	TblFmncQOrgSvcMNTool* tblfmncqorgsvcmntool;
	TblFmncQPcoAPos* tblfmncqpcoapos;
	TblFmncQPcoList* tblfmncqpcolist;
	TblFmncQPreselect* tblfmncqpreselect;
	TblFmncQPrj1NRun* tblfmncqprj1nrun;
	TblFmncQPrjList* tblfmncqprjlist;
	TblFmncQPrsADetail* tblfmncqprsadetail;
	TblFmncQPrsHk1NAddress* tblfmncqprshk1naddress;
	TblFmncQPrsList* tblfmncqprslist;
	TblFmncQPrsMNOrg* tblfmncqprsmnorg;
	TblFmncQPrsMNRun* tblfmncqprsmnrun;
	TblFmncQRunList* tblfmncqrunlist;
	TblFmncQRunMNFab* tblfmncqrunmnfab;
	TblFmncQRunMNPerson* tblfmncqrunmnperson;
	TblFmncQRunMNSample* tblfmncqrunmnsample;
	TblFmncQRunRef1NFile* tblfmncqrunref1nfile;
	TblFmncQRunRun1NActivity* tblfmncqrunrun1nactivity;
	TblFmncQSelect* tblfmncqselect;
	TblFmncQSepAPar* tblfmncqsepapar;
	TblFmncQSepList* tblfmncqseplist;
	TblFmncQSepMNFile* tblfmncqsepmnfile;
	TblFmncQSepMNSample* tblfmncqsepmnsample;
	TblFmncQSepRef1NFile* tblfmncqsepref1nfile;
	TblFmncQSkiList* tblfmncqskilist;
	TblFmncQSmpAPar* tblfmncqsmpapar;
	TblFmncQSmpList* tblfmncqsmplist;
	TblFmncQSmpMNFile* tblfmncqsmpmnfile;
	TblFmncQSmpMNRun* tblfmncqsmpmnrun;
	TblFmncQSmpMNStep* tblfmncqsmpmnstep;
	TblFmncQSmpRef1NFile* tblfmncqsmpref1nfile;
	TblFmncQSmpSup1NSample* tblfmncqsmpsup1nsample;
	TblFmncQStpAPar* tblfmncqstpapar;
	TblFmncQStpKSteppar* tblfmncqstpksteppar;
	TblFmncQStpList* tblfmncqstplist;
	TblFmncQStpMNFile* tblfmncqstpmnfile;
	TblFmncQStpRef1NFile* tblfmncqstpref1nfile;
	TblFmncQStpTpl1NStep* tblfmncqstptpl1nstep;
	TblFmncQTol1NArticle* tblfmncqtol1narticle;
	TblFmncQTolAAvl* tblfmncqtolaavl;
	TblFmncQTolAChar* tblfmncqtolachar;
	TblFmncQTolARes* tblfmncqtolares;
	TblFmncQTolAUtil* tblfmncqtolautil;
	TblFmncQTolKSteppar* tblfmncqtolksteppar;
	TblFmncQTolKToolchar* tblfmncqtolktoolchar;
	TblFmncQTolList* tblfmncqtollist;
	TblFmncQTolMNFabuser* tblfmncqtolmnfabuser;
	TblFmncQTolMNTooltype* tblfmncqtolmntooltype;
	TblFmncQTolRef1NFile* tblfmncqtolref1nfile;
	TblFmncQTolRlv1NStep* tblfmncqtolrlv1nstep;
	TblFmncQTolSvcMNOrg* tblfmncqtolsvcmnorg;
	TblFmncQTtyKSteppar* tblfmncqttyksteppar;
	TblFmncQTtyKToolchar* tblfmncqttyktoolchar;
	TblFmncQTtyList* tblfmncqttylist;
	TblFmncQTtyMNTool* tblfmncqttymntool;
	TblFmncQTtyRlv1NStep* tblfmncqttyrlv1nstep;
	TblFmncQTtySup1NTooltype* tblfmncqttysup1ntooltype;
	TblFmncQUsgAAccess* tblfmncqusgaaccess;
	TblFmncQUsgList* tblfmncqusglist;
	TblFmncQUsgMNUser* tblfmncqusgmnuser;
	TblFmncQUsr1NSession* tblfmncqusr1nsession;
	TblFmncQUsrAAccess* tblfmncqusraaccess;
	TblFmncQUsrList* tblfmncqusrlist;
	TblFmncQUsrMNUsergroup* tblfmncqusrmnusergroup;
};
#endif

