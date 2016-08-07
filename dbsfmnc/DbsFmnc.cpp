/**
  * \file DbsFmnc.cpp
  * C++ wrapper for database DbsFmnc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "DbsFmnc.h"

/******************************************************************************
 class DbsFmnc
 ******************************************************************************/

DbsFmnc::DbsFmnc() {
	initdone = false;

	dbsMy = NULL;
	dbsPg = NULL;
};

DbsFmnc::~DbsFmnc() {
	term();
};

void DbsFmnc::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

	if (ixDbsVDbstype == VecDbsVDbstype::MY) initMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) initPg();

	initdone = true;
};

void DbsFmnc::term() {
	if (initdone) {
		if (ixDbsVDbstype == VecDbsVDbstype::MY) termMy();
		else if (ixDbsVDbstype == VecDbsVDbstype::PG) termPg();

		initdone = false;
	};
};

// IP inittermMy --- BEGIN
void DbsFmnc::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), 0, NULL, 0)) throw DbsException("DbsException / MySQL: connection failure");

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblfmncaccrmuseruniversal = new MyTblFmncAccRMUserUniversal();
	((MyTblFmncAccRMUserUniversal*) tblfmncaccrmuseruniversal)->init(dbsMy);
	tblfmncambillpos = new MyTblFmncAMBillPos();
	((MyTblFmncAMBillPos*) tblfmncambillpos)->init(dbsMy);
	tblfmncamorgdetail = new MyTblFmncAMOrgDetail();
	((MyTblFmncAMOrgDetail*) tblfmncamorgdetail)->init(dbsMy);
	tblfmncampersondetail = new MyTblFmncAMPersonDetail();
	((MyTblFmncAMPersonDetail*) tblfmncampersondetail)->init(dbsMy);
	tblfmncampurchorderpos = new MyTblFmncAMPurchorderPos();
	((MyTblFmncAMPurchorderPos*) tblfmncampurchorderpos)->init(dbsMy);
	tblfmncamsamplepar = new MyTblFmncAMSamplePar();
	((MyTblFmncAMSamplePar*) tblfmncamsamplepar)->init(dbsMy);
	tblfmncamsteppar = new MyTblFmncAMStepPar();
	((MyTblFmncAMStepPar*) tblfmncamsteppar)->init(dbsMy);
	tblfmncamtoolavl = new MyTblFmncAMToolAvl();
	((MyTblFmncAMToolAvl*) tblfmncamtoolavl)->init(dbsMy);
	tblfmncamtoolchar = new MyTblFmncAMToolChar();
	((MyTblFmncAMToolChar*) tblfmncamtoolchar)->init(dbsMy);
	tblfmncamtoolres = new MyTblFmncAMToolRes();
	((MyTblFmncAMToolRes*) tblfmncamtoolres)->init(dbsMy);
	tblfmncamtoolutil = new MyTblFmncAMToolUtil();
	((MyTblFmncAMToolUtil*) tblfmncamtoolutil)->init(dbsMy);
	tblfmncamuseraccess = new MyTblFmncAMUserAccess();
	((MyTblFmncAMUserAccess*) tblfmncamuseraccess)->init(dbsMy);
	tblfmncamusergroupaccess = new MyTblFmncAMUsergroupAccess();
	((MyTblFmncAMUsergroupAccess*) tblfmncamusergroupaccess)->init(dbsMy);
	tblfmncavcontrolpar = new MyTblFmncAVControlPar();
	((MyTblFmncAVControlPar*) tblfmncavcontrolpar)->init(dbsMy);
	tblfmncavkeylistkey = new MyTblFmncAVKeylistKey();
	((MyTblFmncAVKeylistKey*) tblfmncavkeylistkey)->init(dbsMy);
	tblfmncavvaluelistval = new MyTblFmncAVValuelistVal();
	((MyTblFmncAVValuelistVal*) tblfmncavvaluelistval)->init(dbsMy);
	tblfmnccfile = new MyTblFmncCFile();
	((MyTblFmncCFile*) tblfmnccfile)->init(dbsMy);
	tblfmncfabsmpersonmtool = new MyTblFmncFabSMPersonMTool();
	((MyTblFmncFabSMPersonMTool*) tblfmncfabsmpersonmtool)->init(dbsMy);
	tblfmnchistrmuseruniversal = new MyTblFmncHistRMUserUniversal();
	((MyTblFmncHistRMUserUniversal*) tblfmnchistrmuseruniversal)->init(dbsMy);
	tblfmncjavkeylistkey = new MyTblFmncJAVKeylistKey();
	((MyTblFmncJAVKeylistKey*) tblfmncjavkeylistkey)->init(dbsMy);
	tblfmncjmbillstate = new MyTblFmncJMBillState();
	((MyTblFmncJMBillState*) tblfmncjmbillstate)->init(dbsMy);
	tblfmncjmfabprojectstate = new MyTblFmncJMFabprojectState();
	((MyTblFmncJMFabprojectState*) tblfmncjmfabprojectstate)->init(dbsMy);
	tblfmncjmfabuserstate = new MyTblFmncJMFabuserState();
	((MyTblFmncJMFabuserState*) tblfmncjmfabuserstate)->init(dbsMy);
	tblfmncjmorgtitle = new MyTblFmncJMOrgTitle();
	((MyTblFmncJMOrgTitle*) tblfmncjmorgtitle)->init(dbsMy);
	tblfmncjmpersonlastname = new MyTblFmncJMPersonLastname();
	((MyTblFmncJMPersonLastname*) tblfmncjmpersonlastname)->init(dbsMy);
	tblfmncjmprojectstate = new MyTblFmncJMProjectState();
	((MyTblFmncJMProjectState*) tblfmncjmprojectstate)->init(dbsMy);
	tblfmncjmpurchorderstate = new MyTblFmncJMPurchorderState();
	((MyTblFmncJMPurchorderState*) tblfmncjmpurchorderstate)->init(dbsMy);
	tblfmncjmrunstate = new MyTblFmncJMRunState();
	((MyTblFmncJMRunState*) tblfmncjmrunstate)->init(dbsMy);
	tblfmncjmsamplestate = new MyTblFmncJMSampleState();
	((MyTblFmncJMSampleState*) tblfmncjmsamplestate)->init(dbsMy);
	tblfmncjmstockitemquantity = new MyTblFmncJMStockitemQuantity();
	((MyTblFmncJMStockitemQuantity*) tblfmncjmstockitemquantity)->init(dbsMy);
	tblfmncjmtoolunitprice = new MyTblFmncJMToolUnitprice();
	((MyTblFmncJMToolUnitprice*) tblfmncjmtoolunitprice)->init(dbsMy);
	tblfmncjmuserstate = new MyTblFmncJMUserState();
	((MyTblFmncJMUserState*) tblfmncjmuserstate)->init(dbsMy);
	tblfmncmactivity = new MyTblFmncMActivity();
	((MyTblFmncMActivity*) tblfmncmactivity)->init(dbsMy);
	tblfmncmaddress = new MyTblFmncMAddress();
	((MyTblFmncMAddress*) tblfmncmaddress)->init(dbsMy);
	tblfmncmarticle = new MyTblFmncMArticle();
	((MyTblFmncMArticle*) tblfmncmarticle)->init(dbsMy);
	tblfmncmbill = new MyTblFmncMBill();
	((MyTblFmncMBill*) tblfmncmbill)->init(dbsMy);
	tblfmncmfab = new MyTblFmncMFab();
	((MyTblFmncMFab*) tblfmncmfab)->init(dbsMy);
	tblfmncmfabproject = new MyTblFmncMFabproject();
	((MyTblFmncMFabproject*) tblfmncmfabproject)->init(dbsMy);
	tblfmncmfabuser = new MyTblFmncMFabuser();
	((MyTblFmncMFabuser*) tblfmncmfabuser)->init(dbsMy);
	tblfmncmfile = new MyTblFmncMFile();
	((MyTblFmncMFile*) tblfmncmfile)->init(dbsMy);
	tblfmncmnfsmpersonmtool = new MyTblFmncMnfSMPersonMTool();
	((MyTblFmncMnfSMPersonMTool*) tblfmncmnfsmpersonmtool)->init(dbsMy);
	tblfmncmorg = new MyTblFmncMOrg();
	((MyTblFmncMOrg*) tblfmncmorg)->init(dbsMy);
	tblfmncmperson = new MyTblFmncMPerson();
	((MyTblFmncMPerson*) tblfmncmperson)->init(dbsMy);
	tblfmncmproject = new MyTblFmncMProject();
	((MyTblFmncMProject*) tblfmncmproject)->init(dbsMy);
	tblfmncmpurchorder = new MyTblFmncMPurchorder();
	((MyTblFmncMPurchorder*) tblfmncmpurchorder)->init(dbsMy);
	tblfmncmrun = new MyTblFmncMRun();
	((MyTblFmncMRun*) tblfmncmrun)->init(dbsMy);
	tblfmncmsample = new MyTblFmncMSample();
	((MyTblFmncMSample*) tblfmncmsample)->init(dbsMy);
	tblfmncmsession = new MyTblFmncMSession();
	((MyTblFmncMSession*) tblfmncmsession)->init(dbsMy);
	tblfmncmstep = new MyTblFmncMStep();
	((MyTblFmncMStep*) tblfmncmstep)->init(dbsMy);
	tblfmncmstockitem = new MyTblFmncMStockitem();
	((MyTblFmncMStockitem*) tblfmncmstockitem)->init(dbsMy);
	tblfmncmtool = new MyTblFmncMTool();
	((MyTblFmncMTool*) tblfmncmtool)->init(dbsMy);
	tblfmncmtooltype = new MyTblFmncMTooltype();
	((MyTblFmncMTooltype*) tblfmncmtooltype)->init(dbsMy);
	tblfmncmuser = new MyTblFmncMUser();
	((MyTblFmncMUser*) tblfmncmuser)->init(dbsMy);
	tblfmncmusergroup = new MyTblFmncMUsergroup();
	((MyTblFmncMUsergroup*) tblfmncmusergroup)->init(dbsMy);
	tblfmncrmarticlemorg = new MyTblFmncRMArticleMOrg();
	((MyTblFmncRMArticleMOrg*) tblfmncrmarticlemorg)->init(dbsMy);
	tblfmncrmfabmrun = new MyTblFmncRMFabMRun();
	((MyTblFmncRMFabMRun*) tblfmncrmfabmrun)->init(dbsMy);
	tblfmncrmfabprojectmfabuser = new MyTblFmncRMFabprojectMFabuser();
	((MyTblFmncRMFabprojectMFabuser*) tblfmncrmfabprojectmfabuser)->init(dbsMy);
	tblfmncrmfabusermtool = new MyTblFmncRMFabuserMTool();
	((MyTblFmncRMFabuserMTool*) tblfmncrmfabusermtool)->init(dbsMy);
	tblfmncrmfilemsample = new MyTblFmncRMFileMSample();
	((MyTblFmncRMFileMSample*) tblfmncrmfilemsample)->init(dbsMy);
	tblfmncrmfilemstep = new MyTblFmncRMFileMStep();
	((MyTblFmncRMFileMStep*) tblfmncrmfilemstep)->init(dbsMy);
	tblfmncrmorgmperson = new MyTblFmncRMOrgMPerson();
	((MyTblFmncRMOrgMPerson*) tblfmncrmorgmperson)->init(dbsMy);
	tblfmncrmpersonmrun = new MyTblFmncRMPersonMRun();
	((MyTblFmncRMPersonMRun*) tblfmncrmpersonmrun)->init(dbsMy);
	tblfmncrmrunmsample = new MyTblFmncRMRunMSample();
	((MyTblFmncRMRunMSample*) tblfmncrmrunmsample)->init(dbsMy);
	tblfmncrmsamplemstep = new MyTblFmncRMSampleMStep();
	((MyTblFmncRMSampleMStep*) tblfmncrmsamplemstep)->init(dbsMy);
	tblfmncrmtoolmtooltype = new MyTblFmncRMToolMTooltype();
	((MyTblFmncRMToolMTooltype*) tblfmncrmtoolmtooltype)->init(dbsMy);
	tblfmncrmusergroupuniversal = new MyTblFmncRMUsergroupUniversal();
	((MyTblFmncRMUsergroupUniversal*) tblfmncrmusergroupuniversal)->init(dbsMy);
	tblfmncrmusermusergroup = new MyTblFmncRMUserMUsergroup();
	((MyTblFmncRMUserMUsergroup*) tblfmncrmusermusergroup)->init(dbsMy);
	tblfmncsvcrmorgmtool = new MyTblFmncSvcRMOrgMTool();
	((MyTblFmncSvcRMOrgMTool*) tblfmncsvcrmorgmtool)->init(dbsMy);
	tblfmncsvctmpersonmtool = new MyTblFmncSvcTMPersonMTool();
	((MyTblFmncSvcTMPersonMTool*) tblfmncsvctmpersonmtool)->init(dbsMy);
	tblfmnctmfilemsample = new MyTblFmncTMFileMSample();
	((MyTblFmncTMFileMSample*) tblfmnctmfilemsample)->init(dbsMy);

	tblfmncqact1nstep = new MyTblFmncQAct1NStep();
	((MyTblFmncQAct1NStep*) tblfmncqact1nstep)->init(dbsMy);
	tblfmncqactlist = new MyTblFmncQActList();
	((MyTblFmncQActList*) tblfmncqactlist)->init(dbsMy);
	tblfmncqadrlist = new MyTblFmncQAdrList();
	((MyTblFmncQAdrList*) tblfmncqadrlist)->init(dbsMy);
	tblfmncqart1nsample = new MyTblFmncQArt1NSample();
	((MyTblFmncQArt1NSample*) tblfmncqart1nsample)->init(dbsMy);
	tblfmncqart1nstockitem = new MyTblFmncQArt1NStockitem();
	((MyTblFmncQArt1NStockitem*) tblfmncqart1nstockitem)->init(dbsMy);
	tblfmncqartlist = new MyTblFmncQArtList();
	((MyTblFmncQArtList*) tblfmncqartlist)->init(dbsMy);
	tblfmncqartmnorg = new MyTblFmncQArtMNOrg();
	((MyTblFmncQArtMNOrg*) tblfmncqartmnorg)->init(dbsMy);
	tblfmncqartref1nfile = new MyTblFmncQArtRef1NFile();
	((MyTblFmncQArtRef1NFile*) tblfmncqartref1nfile)->init(dbsMy);
	tblfmncqbilapos = new MyTblFmncQBilAPos();
	((MyTblFmncQBilAPos*) tblfmncqbilapos)->init(dbsMy);
	tblfmncqbillist = new MyTblFmncQBilList();
	((MyTblFmncQBilList*) tblfmncqbillist)->init(dbsMy);
	tblfmncqfab1nfabproject = new MyTblFmncQFab1NFabproject();
	((MyTblFmncQFab1NFabproject*) tblfmncqfab1nfabproject)->init(dbsMy);
	tblfmncqfab1nfabuser = new MyTblFmncQFab1NFabuser();
	((MyTblFmncQFab1NFabuser*) tblfmncqfab1nfabuser)->init(dbsMy);
	tblfmncqfabfab1ntool = new MyTblFmncQFabFab1NTool();
	((MyTblFmncQFabFab1NTool*) tblfmncqfabfab1ntool)->init(dbsMy);
	tblfmncqfablist = new MyTblFmncQFabList();
	((MyTblFmncQFabList*) tblfmncqfablist)->init(dbsMy);
	tblfmncqfabmnrun = new MyTblFmncQFabMNRun();
	((MyTblFmncQFabMNRun*) tblfmncqfabmnrun)->init(dbsMy);
	tblfmncqfillist = new MyTblFmncQFilList();
	((MyTblFmncQFilList*) tblfmncqfillist)->init(dbsMy);
	tblfmncqfilmnsample = new MyTblFmncQFilMNSample();
	((MyTblFmncQFilMNSample*) tblfmncqfilmnsample)->init(dbsMy);
	tblfmncqfilmnstep = new MyTblFmncQFilMNStep();
	((MyTblFmncQFilMNStep*) tblfmncqfilmnstep)->init(dbsMy);
	tblfmncqfpj1nbill = new MyTblFmncQFpj1NBill();
	((MyTblFmncQFpj1NBill*) tblfmncqfpj1nbill)->init(dbsMy);
	tblfmncqfpjlist = new MyTblFmncQFpjList();
	((MyTblFmncQFpjList*) tblfmncqfpjlist)->init(dbsMy);
	tblfmncqfpjmnfabuser = new MyTblFmncQFpjMNFabuser();
	((MyTblFmncQFpjMNFabuser*) tblfmncqfpjmnfabuser)->init(dbsMy);
	tblfmncqfuslist = new MyTblFmncQFusList();
	((MyTblFmncQFusList*) tblfmncqfuslist)->init(dbsMy);
	tblfmncqfusmnfabproject = new MyTblFmncQFusMNFabproject();
	((MyTblFmncQFusMNFabproject*) tblfmncqfusmnfabproject)->init(dbsMy);
	tblfmncqfusmntool = new MyTblFmncQFusMNTool();
	((MyTblFmncQFusMNTool*) tblfmncqfusmntool)->init(dbsMy);
	tblfmncqorg1narticle = new MyTblFmncQOrg1NArticle();
	((MyTblFmncQOrg1NArticle*) tblfmncqorg1narticle)->init(dbsMy);
	tblfmncqorg1nstockitem = new MyTblFmncQOrg1NStockitem();
	((MyTblFmncQOrg1NStockitem*) tblfmncqorg1nstockitem)->init(dbsMy);
	tblfmncqorgadetail = new MyTblFmncQOrgADetail();
	((MyTblFmncQOrgADetail*) tblfmncqorgadetail)->init(dbsMy);
	tblfmncqorgbio1nfabproject = new MyTblFmncQOrgBio1NFabproject();
	((MyTblFmncQOrgBio1NFabproject*) tblfmncqorgbio1nfabproject)->init(dbsMy);
	tblfmncqorghk1naddress = new MyTblFmncQOrgHk1NAddress();
	((MyTblFmncQOrgHk1NAddress*) tblfmncqorghk1naddress)->init(dbsMy);
	tblfmncqorgkstocklcn = new MyTblFmncQOrgKStocklcn();
	((MyTblFmncQOrgKStocklcn*) tblfmncqorgkstocklcn)->init(dbsMy);
	tblfmncqorglist = new MyTblFmncQOrgList();
	((MyTblFmncQOrgList*) tblfmncqorglist)->init(dbsMy);
	tblfmncqorgmnarticle = new MyTblFmncQOrgMNArticle();
	((MyTblFmncQOrgMNArticle*) tblfmncqorgmnarticle)->init(dbsMy);
	tblfmncqorgmnf1ntool = new MyTblFmncQOrgMnf1NTool();
	((MyTblFmncQOrgMnf1NTool*) tblfmncqorgmnf1ntool)->init(dbsMy);
	tblfmncqorgmnperson = new MyTblFmncQOrgMNPerson();
	((MyTblFmncQOrgMNPerson*) tblfmncqorgmnperson)->init(dbsMy);
	tblfmncqorgpco1npurchorder = new MyTblFmncQOrgPco1NPurchorder();
	((MyTblFmncQOrgPco1NPurchorder*) tblfmncqorgpco1npurchorder)->init(dbsMy);
	tblfmncqorgspl1npurchorder = new MyTblFmncQOrgSpl1NPurchorder();
	((MyTblFmncQOrgSpl1NPurchorder*) tblfmncqorgspl1npurchorder)->init(dbsMy);
	tblfmncqorgsup1norg = new MyTblFmncQOrgSup1NOrg();
	((MyTblFmncQOrgSup1NOrg*) tblfmncqorgsup1norg)->init(dbsMy);
	tblfmncqorgsvcmntool = new MyTblFmncQOrgSvcMNTool();
	((MyTblFmncQOrgSvcMNTool*) tblfmncqorgsvcmntool)->init(dbsMy);
	tblfmncqpcoapos = new MyTblFmncQPcoAPos();
	((MyTblFmncQPcoAPos*) tblfmncqpcoapos)->init(dbsMy);
	tblfmncqpcolist = new MyTblFmncQPcoList();
	((MyTblFmncQPcoList*) tblfmncqpcolist)->init(dbsMy);
	tblfmncqpreselect = new MyTblFmncQPreselect();
	((MyTblFmncQPreselect*) tblfmncqpreselect)->init(dbsMy);
	tblfmncqprj1nrun = new MyTblFmncQPrj1NRun();
	((MyTblFmncQPrj1NRun*) tblfmncqprj1nrun)->init(dbsMy);
	tblfmncqprjlist = new MyTblFmncQPrjList();
	((MyTblFmncQPrjList*) tblfmncqprjlist)->init(dbsMy);
	tblfmncqprsadetail = new MyTblFmncQPrsADetail();
	((MyTblFmncQPrsADetail*) tblfmncqprsadetail)->init(dbsMy);
	tblfmncqprshk1naddress = new MyTblFmncQPrsHk1NAddress();
	((MyTblFmncQPrsHk1NAddress*) tblfmncqprshk1naddress)->init(dbsMy);
	tblfmncqprslist = new MyTblFmncQPrsList();
	((MyTblFmncQPrsList*) tblfmncqprslist)->init(dbsMy);
	tblfmncqprsmnorg = new MyTblFmncQPrsMNOrg();
	((MyTblFmncQPrsMNOrg*) tblfmncqprsmnorg)->init(dbsMy);
	tblfmncqprsmnrun = new MyTblFmncQPrsMNRun();
	((MyTblFmncQPrsMNRun*) tblfmncqprsmnrun)->init(dbsMy);
	tblfmncqrunlist = new MyTblFmncQRunList();
	((MyTblFmncQRunList*) tblfmncqrunlist)->init(dbsMy);
	tblfmncqrunmnfab = new MyTblFmncQRunMNFab();
	((MyTblFmncQRunMNFab*) tblfmncqrunmnfab)->init(dbsMy);
	tblfmncqrunmnperson = new MyTblFmncQRunMNPerson();
	((MyTblFmncQRunMNPerson*) tblfmncqrunmnperson)->init(dbsMy);
	tblfmncqrunmnsample = new MyTblFmncQRunMNSample();
	((MyTblFmncQRunMNSample*) tblfmncqrunmnsample)->init(dbsMy);
	tblfmncqrunref1nfile = new MyTblFmncQRunRef1NFile();
	((MyTblFmncQRunRef1NFile*) tblfmncqrunref1nfile)->init(dbsMy);
	tblfmncqrunrun1nactivity = new MyTblFmncQRunRun1NActivity();
	((MyTblFmncQRunRun1NActivity*) tblfmncqrunrun1nactivity)->init(dbsMy);
	tblfmncqselect = new MyTblFmncQSelect();
	((MyTblFmncQSelect*) tblfmncqselect)->init(dbsMy);
	tblfmncqsepapar = new MyTblFmncQSepAPar();
	((MyTblFmncQSepAPar*) tblfmncqsepapar)->init(dbsMy);
	tblfmncqseplist = new MyTblFmncQSepList();
	((MyTblFmncQSepList*) tblfmncqseplist)->init(dbsMy);
	tblfmncqsepmnfile = new MyTblFmncQSepMNFile();
	((MyTblFmncQSepMNFile*) tblfmncqsepmnfile)->init(dbsMy);
	tblfmncqsepmnsample = new MyTblFmncQSepMNSample();
	((MyTblFmncQSepMNSample*) tblfmncqsepmnsample)->init(dbsMy);
	tblfmncqsepref1nfile = new MyTblFmncQSepRef1NFile();
	((MyTblFmncQSepRef1NFile*) tblfmncqsepref1nfile)->init(dbsMy);
	tblfmncqskilist = new MyTblFmncQSkiList();
	((MyTblFmncQSkiList*) tblfmncqskilist)->init(dbsMy);
	tblfmncqsmpapar = new MyTblFmncQSmpAPar();
	((MyTblFmncQSmpAPar*) tblfmncqsmpapar)->init(dbsMy);
	tblfmncqsmplist = new MyTblFmncQSmpList();
	((MyTblFmncQSmpList*) tblfmncqsmplist)->init(dbsMy);
	tblfmncqsmpmnfile = new MyTblFmncQSmpMNFile();
	((MyTblFmncQSmpMNFile*) tblfmncqsmpmnfile)->init(dbsMy);
	tblfmncqsmpmnrun = new MyTblFmncQSmpMNRun();
	((MyTblFmncQSmpMNRun*) tblfmncqsmpmnrun)->init(dbsMy);
	tblfmncqsmpmnstep = new MyTblFmncQSmpMNStep();
	((MyTblFmncQSmpMNStep*) tblfmncqsmpmnstep)->init(dbsMy);
	tblfmncqsmpref1nfile = new MyTblFmncQSmpRef1NFile();
	((MyTblFmncQSmpRef1NFile*) tblfmncqsmpref1nfile)->init(dbsMy);
	tblfmncqsmpsup1nsample = new MyTblFmncQSmpSup1NSample();
	((MyTblFmncQSmpSup1NSample*) tblfmncqsmpsup1nsample)->init(dbsMy);
	tblfmncqstpapar = new MyTblFmncQStpAPar();
	((MyTblFmncQStpAPar*) tblfmncqstpapar)->init(dbsMy);
	tblfmncqstpksteppar = new MyTblFmncQStpKSteppar();
	((MyTblFmncQStpKSteppar*) tblfmncqstpksteppar)->init(dbsMy);
	tblfmncqstplist = new MyTblFmncQStpList();
	((MyTblFmncQStpList*) tblfmncqstplist)->init(dbsMy);
	tblfmncqstpmnfile = new MyTblFmncQStpMNFile();
	((MyTblFmncQStpMNFile*) tblfmncqstpmnfile)->init(dbsMy);
	tblfmncqstpref1nfile = new MyTblFmncQStpRef1NFile();
	((MyTblFmncQStpRef1NFile*) tblfmncqstpref1nfile)->init(dbsMy);
	tblfmncqstptpl1nstep = new MyTblFmncQStpTpl1NStep();
	((MyTblFmncQStpTpl1NStep*) tblfmncqstptpl1nstep)->init(dbsMy);
	tblfmncqtol1narticle = new MyTblFmncQTol1NArticle();
	((MyTblFmncQTol1NArticle*) tblfmncqtol1narticle)->init(dbsMy);
	tblfmncqtolaavl = new MyTblFmncQTolAAvl();
	((MyTblFmncQTolAAvl*) tblfmncqtolaavl)->init(dbsMy);
	tblfmncqtolachar = new MyTblFmncQTolAChar();
	((MyTblFmncQTolAChar*) tblfmncqtolachar)->init(dbsMy);
	tblfmncqtolares = new MyTblFmncQTolARes();
	((MyTblFmncQTolARes*) tblfmncqtolares)->init(dbsMy);
	tblfmncqtolautil = new MyTblFmncQTolAUtil();
	((MyTblFmncQTolAUtil*) tblfmncqtolautil)->init(dbsMy);
	tblfmncqtolksteppar = new MyTblFmncQTolKSteppar();
	((MyTblFmncQTolKSteppar*) tblfmncqtolksteppar)->init(dbsMy);
	tblfmncqtolktoolchar = new MyTblFmncQTolKToolchar();
	((MyTblFmncQTolKToolchar*) tblfmncqtolktoolchar)->init(dbsMy);
	tblfmncqtollist = new MyTblFmncQTolList();
	((MyTblFmncQTolList*) tblfmncqtollist)->init(dbsMy);
	tblfmncqtolmnfabuser = new MyTblFmncQTolMNFabuser();
	((MyTblFmncQTolMNFabuser*) tblfmncqtolmnfabuser)->init(dbsMy);
	tblfmncqtolmntooltype = new MyTblFmncQTolMNTooltype();
	((MyTblFmncQTolMNTooltype*) tblfmncqtolmntooltype)->init(dbsMy);
	tblfmncqtolref1nfile = new MyTblFmncQTolRef1NFile();
	((MyTblFmncQTolRef1NFile*) tblfmncqtolref1nfile)->init(dbsMy);
	tblfmncqtolrlv1nstep = new MyTblFmncQTolRlv1NStep();
	((MyTblFmncQTolRlv1NStep*) tblfmncqtolrlv1nstep)->init(dbsMy);
	tblfmncqtolsvcmnorg = new MyTblFmncQTolSvcMNOrg();
	((MyTblFmncQTolSvcMNOrg*) tblfmncqtolsvcmnorg)->init(dbsMy);
	tblfmncqttyksteppar = new MyTblFmncQTtyKSteppar();
	((MyTblFmncQTtyKSteppar*) tblfmncqttyksteppar)->init(dbsMy);
	tblfmncqttyktoolchar = new MyTblFmncQTtyKToolchar();
	((MyTblFmncQTtyKToolchar*) tblfmncqttyktoolchar)->init(dbsMy);
	tblfmncqttylist = new MyTblFmncQTtyList();
	((MyTblFmncQTtyList*) tblfmncqttylist)->init(dbsMy);
	tblfmncqttymntool = new MyTblFmncQTtyMNTool();
	((MyTblFmncQTtyMNTool*) tblfmncqttymntool)->init(dbsMy);
	tblfmncqttyrlv1nstep = new MyTblFmncQTtyRlv1NStep();
	((MyTblFmncQTtyRlv1NStep*) tblfmncqttyrlv1nstep)->init(dbsMy);
	tblfmncqttysup1ntooltype = new MyTblFmncQTtySup1NTooltype();
	((MyTblFmncQTtySup1NTooltype*) tblfmncqttysup1ntooltype)->init(dbsMy);
	tblfmncqusgaaccess = new MyTblFmncQUsgAAccess();
	((MyTblFmncQUsgAAccess*) tblfmncqusgaaccess)->init(dbsMy);
	tblfmncqusglist = new MyTblFmncQUsgList();
	((MyTblFmncQUsgList*) tblfmncqusglist)->init(dbsMy);
	tblfmncqusgmnuser = new MyTblFmncQUsgMNUser();
	((MyTblFmncQUsgMNUser*) tblfmncqusgmnuser)->init(dbsMy);
	tblfmncqusr1nsession = new MyTblFmncQUsr1NSession();
	((MyTblFmncQUsr1NSession*) tblfmncqusr1nsession)->init(dbsMy);
	tblfmncqusraaccess = new MyTblFmncQUsrAAccess();
	((MyTblFmncQUsrAAccess*) tblfmncqusraaccess)->init(dbsMy);
	tblfmncqusrlist = new MyTblFmncQUsrList();
	((MyTblFmncQUsrList*) tblfmncqusrlist)->init(dbsMy);
	tblfmncqusrmnusergroup = new MyTblFmncQUsrMNUsergroup();
	((MyTblFmncQUsrMNUsergroup*) tblfmncqusrmnusergroup)->init(dbsMy);
};

void DbsFmnc::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};
// IP inittermMy --- END

// IP inittermPg --- BEGIN
void DbsFmnc::initPg() {
	// connect to PostgreSQL database
	dbsPg = PQsetdbLogin(ip.c_str(), to_string(port).c_str(), NULL, NULL, dbsname.c_str(), username.c_str(), password.c_str());

	if (PQstatus(dbsPg) == CONNECTION_BAD) throw DbsException("DbsException / PgSQL: connection failure");

	tblfmncaccrmuseruniversal = new PgTblFmncAccRMUserUniversal();
	((PgTblFmncAccRMUserUniversal*) tblfmncaccrmuseruniversal)->init(dbsPg);
	tblfmncambillpos = new PgTblFmncAMBillPos();
	((PgTblFmncAMBillPos*) tblfmncambillpos)->init(dbsPg);
	tblfmncamorgdetail = new PgTblFmncAMOrgDetail();
	((PgTblFmncAMOrgDetail*) tblfmncamorgdetail)->init(dbsPg);
	tblfmncampersondetail = new PgTblFmncAMPersonDetail();
	((PgTblFmncAMPersonDetail*) tblfmncampersondetail)->init(dbsPg);
	tblfmncampurchorderpos = new PgTblFmncAMPurchorderPos();
	((PgTblFmncAMPurchorderPos*) tblfmncampurchorderpos)->init(dbsPg);
	tblfmncamsamplepar = new PgTblFmncAMSamplePar();
	((PgTblFmncAMSamplePar*) tblfmncamsamplepar)->init(dbsPg);
	tblfmncamsteppar = new PgTblFmncAMStepPar();
	((PgTblFmncAMStepPar*) tblfmncamsteppar)->init(dbsPg);
	tblfmncamtoolavl = new PgTblFmncAMToolAvl();
	((PgTblFmncAMToolAvl*) tblfmncamtoolavl)->init(dbsPg);
	tblfmncamtoolchar = new PgTblFmncAMToolChar();
	((PgTblFmncAMToolChar*) tblfmncamtoolchar)->init(dbsPg);
	tblfmncamtoolres = new PgTblFmncAMToolRes();
	((PgTblFmncAMToolRes*) tblfmncamtoolres)->init(dbsPg);
	tblfmncamtoolutil = new PgTblFmncAMToolUtil();
	((PgTblFmncAMToolUtil*) tblfmncamtoolutil)->init(dbsPg);
	tblfmncamuseraccess = new PgTblFmncAMUserAccess();
	((PgTblFmncAMUserAccess*) tblfmncamuseraccess)->init(dbsPg);
	tblfmncamusergroupaccess = new PgTblFmncAMUsergroupAccess();
	((PgTblFmncAMUsergroupAccess*) tblfmncamusergroupaccess)->init(dbsPg);
	tblfmncavcontrolpar = new PgTblFmncAVControlPar();
	((PgTblFmncAVControlPar*) tblfmncavcontrolpar)->init(dbsPg);
	tblfmncavkeylistkey = new PgTblFmncAVKeylistKey();
	((PgTblFmncAVKeylistKey*) tblfmncavkeylistkey)->init(dbsPg);
	tblfmncavvaluelistval = new PgTblFmncAVValuelistVal();
	((PgTblFmncAVValuelistVal*) tblfmncavvaluelistval)->init(dbsPg);
	tblfmnccfile = new PgTblFmncCFile();
	((PgTblFmncCFile*) tblfmnccfile)->init(dbsPg);
	tblfmncfabsmpersonmtool = new PgTblFmncFabSMPersonMTool();
	((PgTblFmncFabSMPersonMTool*) tblfmncfabsmpersonmtool)->init(dbsPg);
	tblfmnchistrmuseruniversal = new PgTblFmncHistRMUserUniversal();
	((PgTblFmncHistRMUserUniversal*) tblfmnchistrmuseruniversal)->init(dbsPg);
	tblfmncjavkeylistkey = new PgTblFmncJAVKeylistKey();
	((PgTblFmncJAVKeylistKey*) tblfmncjavkeylistkey)->init(dbsPg);
	tblfmncjmbillstate = new PgTblFmncJMBillState();
	((PgTblFmncJMBillState*) tblfmncjmbillstate)->init(dbsPg);
	tblfmncjmfabprojectstate = new PgTblFmncJMFabprojectState();
	((PgTblFmncJMFabprojectState*) tblfmncjmfabprojectstate)->init(dbsPg);
	tblfmncjmfabuserstate = new PgTblFmncJMFabuserState();
	((PgTblFmncJMFabuserState*) tblfmncjmfabuserstate)->init(dbsPg);
	tblfmncjmorgtitle = new PgTblFmncJMOrgTitle();
	((PgTblFmncJMOrgTitle*) tblfmncjmorgtitle)->init(dbsPg);
	tblfmncjmpersonlastname = new PgTblFmncJMPersonLastname();
	((PgTblFmncJMPersonLastname*) tblfmncjmpersonlastname)->init(dbsPg);
	tblfmncjmprojectstate = new PgTblFmncJMProjectState();
	((PgTblFmncJMProjectState*) tblfmncjmprojectstate)->init(dbsPg);
	tblfmncjmpurchorderstate = new PgTblFmncJMPurchorderState();
	((PgTblFmncJMPurchorderState*) tblfmncjmpurchorderstate)->init(dbsPg);
	tblfmncjmrunstate = new PgTblFmncJMRunState();
	((PgTblFmncJMRunState*) tblfmncjmrunstate)->init(dbsPg);
	tblfmncjmsamplestate = new PgTblFmncJMSampleState();
	((PgTblFmncJMSampleState*) tblfmncjmsamplestate)->init(dbsPg);
	tblfmncjmstockitemquantity = new PgTblFmncJMStockitemQuantity();
	((PgTblFmncJMStockitemQuantity*) tblfmncjmstockitemquantity)->init(dbsPg);
	tblfmncjmtoolunitprice = new PgTblFmncJMToolUnitprice();
	((PgTblFmncJMToolUnitprice*) tblfmncjmtoolunitprice)->init(dbsPg);
	tblfmncjmuserstate = new PgTblFmncJMUserState();
	((PgTblFmncJMUserState*) tblfmncjmuserstate)->init(dbsPg);
	tblfmncmactivity = new PgTblFmncMActivity();
	((PgTblFmncMActivity*) tblfmncmactivity)->init(dbsPg);
	tblfmncmaddress = new PgTblFmncMAddress();
	((PgTblFmncMAddress*) tblfmncmaddress)->init(dbsPg);
	tblfmncmarticle = new PgTblFmncMArticle();
	((PgTblFmncMArticle*) tblfmncmarticle)->init(dbsPg);
	tblfmncmbill = new PgTblFmncMBill();
	((PgTblFmncMBill*) tblfmncmbill)->init(dbsPg);
	tblfmncmfab = new PgTblFmncMFab();
	((PgTblFmncMFab*) tblfmncmfab)->init(dbsPg);
	tblfmncmfabproject = new PgTblFmncMFabproject();
	((PgTblFmncMFabproject*) tblfmncmfabproject)->init(dbsPg);
	tblfmncmfabuser = new PgTblFmncMFabuser();
	((PgTblFmncMFabuser*) tblfmncmfabuser)->init(dbsPg);
	tblfmncmfile = new PgTblFmncMFile();
	((PgTblFmncMFile*) tblfmncmfile)->init(dbsPg);
	tblfmncmnfsmpersonmtool = new PgTblFmncMnfSMPersonMTool();
	((PgTblFmncMnfSMPersonMTool*) tblfmncmnfsmpersonmtool)->init(dbsPg);
	tblfmncmorg = new PgTblFmncMOrg();
	((PgTblFmncMOrg*) tblfmncmorg)->init(dbsPg);
	tblfmncmperson = new PgTblFmncMPerson();
	((PgTblFmncMPerson*) tblfmncmperson)->init(dbsPg);
	tblfmncmproject = new PgTblFmncMProject();
	((PgTblFmncMProject*) tblfmncmproject)->init(dbsPg);
	tblfmncmpurchorder = new PgTblFmncMPurchorder();
	((PgTblFmncMPurchorder*) tblfmncmpurchorder)->init(dbsPg);
	tblfmncmrun = new PgTblFmncMRun();
	((PgTblFmncMRun*) tblfmncmrun)->init(dbsPg);
	tblfmncmsample = new PgTblFmncMSample();
	((PgTblFmncMSample*) tblfmncmsample)->init(dbsPg);
	tblfmncmsession = new PgTblFmncMSession();
	((PgTblFmncMSession*) tblfmncmsession)->init(dbsPg);
	tblfmncmstep = new PgTblFmncMStep();
	((PgTblFmncMStep*) tblfmncmstep)->init(dbsPg);
	tblfmncmstockitem = new PgTblFmncMStockitem();
	((PgTblFmncMStockitem*) tblfmncmstockitem)->init(dbsPg);
	tblfmncmtool = new PgTblFmncMTool();
	((PgTblFmncMTool*) tblfmncmtool)->init(dbsPg);
	tblfmncmtooltype = new PgTblFmncMTooltype();
	((PgTblFmncMTooltype*) tblfmncmtooltype)->init(dbsPg);
	tblfmncmuser = new PgTblFmncMUser();
	((PgTblFmncMUser*) tblfmncmuser)->init(dbsPg);
	tblfmncmusergroup = new PgTblFmncMUsergroup();
	((PgTblFmncMUsergroup*) tblfmncmusergroup)->init(dbsPg);
	tblfmncrmarticlemorg = new PgTblFmncRMArticleMOrg();
	((PgTblFmncRMArticleMOrg*) tblfmncrmarticlemorg)->init(dbsPg);
	tblfmncrmfabmrun = new PgTblFmncRMFabMRun();
	((PgTblFmncRMFabMRun*) tblfmncrmfabmrun)->init(dbsPg);
	tblfmncrmfabprojectmfabuser = new PgTblFmncRMFabprojectMFabuser();
	((PgTblFmncRMFabprojectMFabuser*) tblfmncrmfabprojectmfabuser)->init(dbsPg);
	tblfmncrmfabusermtool = new PgTblFmncRMFabuserMTool();
	((PgTblFmncRMFabuserMTool*) tblfmncrmfabusermtool)->init(dbsPg);
	tblfmncrmfilemsample = new PgTblFmncRMFileMSample();
	((PgTblFmncRMFileMSample*) tblfmncrmfilemsample)->init(dbsPg);
	tblfmncrmfilemstep = new PgTblFmncRMFileMStep();
	((PgTblFmncRMFileMStep*) tblfmncrmfilemstep)->init(dbsPg);
	tblfmncrmorgmperson = new PgTblFmncRMOrgMPerson();
	((PgTblFmncRMOrgMPerson*) tblfmncrmorgmperson)->init(dbsPg);
	tblfmncrmpersonmrun = new PgTblFmncRMPersonMRun();
	((PgTblFmncRMPersonMRun*) tblfmncrmpersonmrun)->init(dbsPg);
	tblfmncrmrunmsample = new PgTblFmncRMRunMSample();
	((PgTblFmncRMRunMSample*) tblfmncrmrunmsample)->init(dbsPg);
	tblfmncrmsamplemstep = new PgTblFmncRMSampleMStep();
	((PgTblFmncRMSampleMStep*) tblfmncrmsamplemstep)->init(dbsPg);
	tblfmncrmtoolmtooltype = new PgTblFmncRMToolMTooltype();
	((PgTblFmncRMToolMTooltype*) tblfmncrmtoolmtooltype)->init(dbsPg);
	tblfmncrmusergroupuniversal = new PgTblFmncRMUsergroupUniversal();
	((PgTblFmncRMUsergroupUniversal*) tblfmncrmusergroupuniversal)->init(dbsPg);
	tblfmncrmusermusergroup = new PgTblFmncRMUserMUsergroup();
	((PgTblFmncRMUserMUsergroup*) tblfmncrmusermusergroup)->init(dbsPg);
	tblfmncsvcrmorgmtool = new PgTblFmncSvcRMOrgMTool();
	((PgTblFmncSvcRMOrgMTool*) tblfmncsvcrmorgmtool)->init(dbsPg);
	tblfmncsvctmpersonmtool = new PgTblFmncSvcTMPersonMTool();
	((PgTblFmncSvcTMPersonMTool*) tblfmncsvctmpersonmtool)->init(dbsPg);
	tblfmnctmfilemsample = new PgTblFmncTMFileMSample();
	((PgTblFmncTMFileMSample*) tblfmnctmfilemsample)->init(dbsPg);

	tblfmncqact1nstep = new PgTblFmncQAct1NStep();
	((PgTblFmncQAct1NStep*) tblfmncqact1nstep)->init(dbsPg);
	tblfmncqactlist = new PgTblFmncQActList();
	((PgTblFmncQActList*) tblfmncqactlist)->init(dbsPg);
	tblfmncqadrlist = new PgTblFmncQAdrList();
	((PgTblFmncQAdrList*) tblfmncqadrlist)->init(dbsPg);
	tblfmncqart1nsample = new PgTblFmncQArt1NSample();
	((PgTblFmncQArt1NSample*) tblfmncqart1nsample)->init(dbsPg);
	tblfmncqart1nstockitem = new PgTblFmncQArt1NStockitem();
	((PgTblFmncQArt1NStockitem*) tblfmncqart1nstockitem)->init(dbsPg);
	tblfmncqartlist = new PgTblFmncQArtList();
	((PgTblFmncQArtList*) tblfmncqartlist)->init(dbsPg);
	tblfmncqartmnorg = new PgTblFmncQArtMNOrg();
	((PgTblFmncQArtMNOrg*) tblfmncqartmnorg)->init(dbsPg);
	tblfmncqartref1nfile = new PgTblFmncQArtRef1NFile();
	((PgTblFmncQArtRef1NFile*) tblfmncqartref1nfile)->init(dbsPg);
	tblfmncqbilapos = new PgTblFmncQBilAPos();
	((PgTblFmncQBilAPos*) tblfmncqbilapos)->init(dbsPg);
	tblfmncqbillist = new PgTblFmncQBilList();
	((PgTblFmncQBilList*) tblfmncqbillist)->init(dbsPg);
	tblfmncqfab1nfabproject = new PgTblFmncQFab1NFabproject();
	((PgTblFmncQFab1NFabproject*) tblfmncqfab1nfabproject)->init(dbsPg);
	tblfmncqfab1nfabuser = new PgTblFmncQFab1NFabuser();
	((PgTblFmncQFab1NFabuser*) tblfmncqfab1nfabuser)->init(dbsPg);
	tblfmncqfabfab1ntool = new PgTblFmncQFabFab1NTool();
	((PgTblFmncQFabFab1NTool*) tblfmncqfabfab1ntool)->init(dbsPg);
	tblfmncqfablist = new PgTblFmncQFabList();
	((PgTblFmncQFabList*) tblfmncqfablist)->init(dbsPg);
	tblfmncqfabmnrun = new PgTblFmncQFabMNRun();
	((PgTblFmncQFabMNRun*) tblfmncqfabmnrun)->init(dbsPg);
	tblfmncqfillist = new PgTblFmncQFilList();
	((PgTblFmncQFilList*) tblfmncqfillist)->init(dbsPg);
	tblfmncqfilmnsample = new PgTblFmncQFilMNSample();
	((PgTblFmncQFilMNSample*) tblfmncqfilmnsample)->init(dbsPg);
	tblfmncqfilmnstep = new PgTblFmncQFilMNStep();
	((PgTblFmncQFilMNStep*) tblfmncqfilmnstep)->init(dbsPg);
	tblfmncqfpj1nbill = new PgTblFmncQFpj1NBill();
	((PgTblFmncQFpj1NBill*) tblfmncqfpj1nbill)->init(dbsPg);
	tblfmncqfpjlist = new PgTblFmncQFpjList();
	((PgTblFmncQFpjList*) tblfmncqfpjlist)->init(dbsPg);
	tblfmncqfpjmnfabuser = new PgTblFmncQFpjMNFabuser();
	((PgTblFmncQFpjMNFabuser*) tblfmncqfpjmnfabuser)->init(dbsPg);
	tblfmncqfuslist = new PgTblFmncQFusList();
	((PgTblFmncQFusList*) tblfmncqfuslist)->init(dbsPg);
	tblfmncqfusmnfabproject = new PgTblFmncQFusMNFabproject();
	((PgTblFmncQFusMNFabproject*) tblfmncqfusmnfabproject)->init(dbsPg);
	tblfmncqfusmntool = new PgTblFmncQFusMNTool();
	((PgTblFmncQFusMNTool*) tblfmncqfusmntool)->init(dbsPg);
	tblfmncqorg1narticle = new PgTblFmncQOrg1NArticle();
	((PgTblFmncQOrg1NArticle*) tblfmncqorg1narticle)->init(dbsPg);
	tblfmncqorg1nstockitem = new PgTblFmncQOrg1NStockitem();
	((PgTblFmncQOrg1NStockitem*) tblfmncqorg1nstockitem)->init(dbsPg);
	tblfmncqorgadetail = new PgTblFmncQOrgADetail();
	((PgTblFmncQOrgADetail*) tblfmncqorgadetail)->init(dbsPg);
	tblfmncqorgbio1nfabproject = new PgTblFmncQOrgBio1NFabproject();
	((PgTblFmncQOrgBio1NFabproject*) tblfmncqorgbio1nfabproject)->init(dbsPg);
	tblfmncqorghk1naddress = new PgTblFmncQOrgHk1NAddress();
	((PgTblFmncQOrgHk1NAddress*) tblfmncqorghk1naddress)->init(dbsPg);
	tblfmncqorgkstocklcn = new PgTblFmncQOrgKStocklcn();
	((PgTblFmncQOrgKStocklcn*) tblfmncqorgkstocklcn)->init(dbsPg);
	tblfmncqorglist = new PgTblFmncQOrgList();
	((PgTblFmncQOrgList*) tblfmncqorglist)->init(dbsPg);
	tblfmncqorgmnarticle = new PgTblFmncQOrgMNArticle();
	((PgTblFmncQOrgMNArticle*) tblfmncqorgmnarticle)->init(dbsPg);
	tblfmncqorgmnf1ntool = new PgTblFmncQOrgMnf1NTool();
	((PgTblFmncQOrgMnf1NTool*) tblfmncqorgmnf1ntool)->init(dbsPg);
	tblfmncqorgmnperson = new PgTblFmncQOrgMNPerson();
	((PgTblFmncQOrgMNPerson*) tblfmncqorgmnperson)->init(dbsPg);
	tblfmncqorgpco1npurchorder = new PgTblFmncQOrgPco1NPurchorder();
	((PgTblFmncQOrgPco1NPurchorder*) tblfmncqorgpco1npurchorder)->init(dbsPg);
	tblfmncqorgspl1npurchorder = new PgTblFmncQOrgSpl1NPurchorder();
	((PgTblFmncQOrgSpl1NPurchorder*) tblfmncqorgspl1npurchorder)->init(dbsPg);
	tblfmncqorgsup1norg = new PgTblFmncQOrgSup1NOrg();
	((PgTblFmncQOrgSup1NOrg*) tblfmncqorgsup1norg)->init(dbsPg);
	tblfmncqorgsvcmntool = new PgTblFmncQOrgSvcMNTool();
	((PgTblFmncQOrgSvcMNTool*) tblfmncqorgsvcmntool)->init(dbsPg);
	tblfmncqpcoapos = new PgTblFmncQPcoAPos();
	((PgTblFmncQPcoAPos*) tblfmncqpcoapos)->init(dbsPg);
	tblfmncqpcolist = new PgTblFmncQPcoList();
	((PgTblFmncQPcoList*) tblfmncqpcolist)->init(dbsPg);
	tblfmncqpreselect = new PgTblFmncQPreselect();
	((PgTblFmncQPreselect*) tblfmncqpreselect)->init(dbsPg);
	tblfmncqprj1nrun = new PgTblFmncQPrj1NRun();
	((PgTblFmncQPrj1NRun*) tblfmncqprj1nrun)->init(dbsPg);
	tblfmncqprjlist = new PgTblFmncQPrjList();
	((PgTblFmncQPrjList*) tblfmncqprjlist)->init(dbsPg);
	tblfmncqprsadetail = new PgTblFmncQPrsADetail();
	((PgTblFmncQPrsADetail*) tblfmncqprsadetail)->init(dbsPg);
	tblfmncqprshk1naddress = new PgTblFmncQPrsHk1NAddress();
	((PgTblFmncQPrsHk1NAddress*) tblfmncqprshk1naddress)->init(dbsPg);
	tblfmncqprslist = new PgTblFmncQPrsList();
	((PgTblFmncQPrsList*) tblfmncqprslist)->init(dbsPg);
	tblfmncqprsmnorg = new PgTblFmncQPrsMNOrg();
	((PgTblFmncQPrsMNOrg*) tblfmncqprsmnorg)->init(dbsPg);
	tblfmncqprsmnrun = new PgTblFmncQPrsMNRun();
	((PgTblFmncQPrsMNRun*) tblfmncqprsmnrun)->init(dbsPg);
	tblfmncqrunlist = new PgTblFmncQRunList();
	((PgTblFmncQRunList*) tblfmncqrunlist)->init(dbsPg);
	tblfmncqrunmnfab = new PgTblFmncQRunMNFab();
	((PgTblFmncQRunMNFab*) tblfmncqrunmnfab)->init(dbsPg);
	tblfmncqrunmnperson = new PgTblFmncQRunMNPerson();
	((PgTblFmncQRunMNPerson*) tblfmncqrunmnperson)->init(dbsPg);
	tblfmncqrunmnsample = new PgTblFmncQRunMNSample();
	((PgTblFmncQRunMNSample*) tblfmncqrunmnsample)->init(dbsPg);
	tblfmncqrunref1nfile = new PgTblFmncQRunRef1NFile();
	((PgTblFmncQRunRef1NFile*) tblfmncqrunref1nfile)->init(dbsPg);
	tblfmncqrunrun1nactivity = new PgTblFmncQRunRun1NActivity();
	((PgTblFmncQRunRun1NActivity*) tblfmncqrunrun1nactivity)->init(dbsPg);
	tblfmncqselect = new PgTblFmncQSelect();
	((PgTblFmncQSelect*) tblfmncqselect)->init(dbsPg);
	tblfmncqsepapar = new PgTblFmncQSepAPar();
	((PgTblFmncQSepAPar*) tblfmncqsepapar)->init(dbsPg);
	tblfmncqseplist = new PgTblFmncQSepList();
	((PgTblFmncQSepList*) tblfmncqseplist)->init(dbsPg);
	tblfmncqsepmnfile = new PgTblFmncQSepMNFile();
	((PgTblFmncQSepMNFile*) tblfmncqsepmnfile)->init(dbsPg);
	tblfmncqsepmnsample = new PgTblFmncQSepMNSample();
	((PgTblFmncQSepMNSample*) tblfmncqsepmnsample)->init(dbsPg);
	tblfmncqsepref1nfile = new PgTblFmncQSepRef1NFile();
	((PgTblFmncQSepRef1NFile*) tblfmncqsepref1nfile)->init(dbsPg);
	tblfmncqskilist = new PgTblFmncQSkiList();
	((PgTblFmncQSkiList*) tblfmncqskilist)->init(dbsPg);
	tblfmncqsmpapar = new PgTblFmncQSmpAPar();
	((PgTblFmncQSmpAPar*) tblfmncqsmpapar)->init(dbsPg);
	tblfmncqsmplist = new PgTblFmncQSmpList();
	((PgTblFmncQSmpList*) tblfmncqsmplist)->init(dbsPg);
	tblfmncqsmpmnfile = new PgTblFmncQSmpMNFile();
	((PgTblFmncQSmpMNFile*) tblfmncqsmpmnfile)->init(dbsPg);
	tblfmncqsmpmnrun = new PgTblFmncQSmpMNRun();
	((PgTblFmncQSmpMNRun*) tblfmncqsmpmnrun)->init(dbsPg);
	tblfmncqsmpmnstep = new PgTblFmncQSmpMNStep();
	((PgTblFmncQSmpMNStep*) tblfmncqsmpmnstep)->init(dbsPg);
	tblfmncqsmpref1nfile = new PgTblFmncQSmpRef1NFile();
	((PgTblFmncQSmpRef1NFile*) tblfmncqsmpref1nfile)->init(dbsPg);
	tblfmncqsmpsup1nsample = new PgTblFmncQSmpSup1NSample();
	((PgTblFmncQSmpSup1NSample*) tblfmncqsmpsup1nsample)->init(dbsPg);
	tblfmncqstpapar = new PgTblFmncQStpAPar();
	((PgTblFmncQStpAPar*) tblfmncqstpapar)->init(dbsPg);
	tblfmncqstpksteppar = new PgTblFmncQStpKSteppar();
	((PgTblFmncQStpKSteppar*) tblfmncqstpksteppar)->init(dbsPg);
	tblfmncqstplist = new PgTblFmncQStpList();
	((PgTblFmncQStpList*) tblfmncqstplist)->init(dbsPg);
	tblfmncqstpmnfile = new PgTblFmncQStpMNFile();
	((PgTblFmncQStpMNFile*) tblfmncqstpmnfile)->init(dbsPg);
	tblfmncqstpref1nfile = new PgTblFmncQStpRef1NFile();
	((PgTblFmncQStpRef1NFile*) tblfmncqstpref1nfile)->init(dbsPg);
	tblfmncqstptpl1nstep = new PgTblFmncQStpTpl1NStep();
	((PgTblFmncQStpTpl1NStep*) tblfmncqstptpl1nstep)->init(dbsPg);
	tblfmncqtol1narticle = new PgTblFmncQTol1NArticle();
	((PgTblFmncQTol1NArticle*) tblfmncqtol1narticle)->init(dbsPg);
	tblfmncqtolaavl = new PgTblFmncQTolAAvl();
	((PgTblFmncQTolAAvl*) tblfmncqtolaavl)->init(dbsPg);
	tblfmncqtolachar = new PgTblFmncQTolAChar();
	((PgTblFmncQTolAChar*) tblfmncqtolachar)->init(dbsPg);
	tblfmncqtolares = new PgTblFmncQTolARes();
	((PgTblFmncQTolARes*) tblfmncqtolares)->init(dbsPg);
	tblfmncqtolautil = new PgTblFmncQTolAUtil();
	((PgTblFmncQTolAUtil*) tblfmncqtolautil)->init(dbsPg);
	tblfmncqtolksteppar = new PgTblFmncQTolKSteppar();
	((PgTblFmncQTolKSteppar*) tblfmncqtolksteppar)->init(dbsPg);
	tblfmncqtolktoolchar = new PgTblFmncQTolKToolchar();
	((PgTblFmncQTolKToolchar*) tblfmncqtolktoolchar)->init(dbsPg);
	tblfmncqtollist = new PgTblFmncQTolList();
	((PgTblFmncQTolList*) tblfmncqtollist)->init(dbsPg);
	tblfmncqtolmnfabuser = new PgTblFmncQTolMNFabuser();
	((PgTblFmncQTolMNFabuser*) tblfmncqtolmnfabuser)->init(dbsPg);
	tblfmncqtolmntooltype = new PgTblFmncQTolMNTooltype();
	((PgTblFmncQTolMNTooltype*) tblfmncqtolmntooltype)->init(dbsPg);
	tblfmncqtolref1nfile = new PgTblFmncQTolRef1NFile();
	((PgTblFmncQTolRef1NFile*) tblfmncqtolref1nfile)->init(dbsPg);
	tblfmncqtolrlv1nstep = new PgTblFmncQTolRlv1NStep();
	((PgTblFmncQTolRlv1NStep*) tblfmncqtolrlv1nstep)->init(dbsPg);
	tblfmncqtolsvcmnorg = new PgTblFmncQTolSvcMNOrg();
	((PgTblFmncQTolSvcMNOrg*) tblfmncqtolsvcmnorg)->init(dbsPg);
	tblfmncqttyksteppar = new PgTblFmncQTtyKSteppar();
	((PgTblFmncQTtyKSteppar*) tblfmncqttyksteppar)->init(dbsPg);
	tblfmncqttyktoolchar = new PgTblFmncQTtyKToolchar();
	((PgTblFmncQTtyKToolchar*) tblfmncqttyktoolchar)->init(dbsPg);
	tblfmncqttylist = new PgTblFmncQTtyList();
	((PgTblFmncQTtyList*) tblfmncqttylist)->init(dbsPg);
	tblfmncqttymntool = new PgTblFmncQTtyMNTool();
	((PgTblFmncQTtyMNTool*) tblfmncqttymntool)->init(dbsPg);
	tblfmncqttyrlv1nstep = new PgTblFmncQTtyRlv1NStep();
	((PgTblFmncQTtyRlv1NStep*) tblfmncqttyrlv1nstep)->init(dbsPg);
	tblfmncqttysup1ntooltype = new PgTblFmncQTtySup1NTooltype();
	((PgTblFmncQTtySup1NTooltype*) tblfmncqttysup1ntooltype)->init(dbsPg);
	tblfmncqusgaaccess = new PgTblFmncQUsgAAccess();
	((PgTblFmncQUsgAAccess*) tblfmncqusgaaccess)->init(dbsPg);
	tblfmncqusglist = new PgTblFmncQUsgList();
	((PgTblFmncQUsgList*) tblfmncqusglist)->init(dbsPg);
	tblfmncqusgmnuser = new PgTblFmncQUsgMNUser();
	((PgTblFmncQUsgMNUser*) tblfmncqusgmnuser)->init(dbsPg);
	tblfmncqusr1nsession = new PgTblFmncQUsr1NSession();
	((PgTblFmncQUsr1NSession*) tblfmncqusr1nsession)->init(dbsPg);
	tblfmncqusraaccess = new PgTblFmncQUsrAAccess();
	((PgTblFmncQUsrAAccess*) tblfmncqusraaccess)->init(dbsPg);
	tblfmncqusrlist = new PgTblFmncQUsrList();
	((PgTblFmncQUsrList*) tblfmncqusrlist)->init(dbsPg);
	tblfmncqusrmnusergroup = new PgTblFmncQUsrMNUsergroup();
	((PgTblFmncQUsrMNUsergroup*) tblfmncqusrmnusergroup)->init(dbsPg);
};

void DbsFmnc::termPg() {
	PQfinish(dbsPg);
};
// IP inittermPg --- END

void DbsFmnc::begin() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) beginPg();
};

bool DbsFmnc::commit() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return commitPg();

	return false;
};

void DbsFmnc::rollback() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) rollbackPg();
};

// IP transactMy --- BEGIN
void DbsFmnc::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) throw DbsException("DbsException / MySQL: failed to begin transaction\n");
};

bool DbsFmnc::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsFmnc::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) throw DbsException("DbsException / MySQL: failed to roll back transaction\n");
};
// IP transactMy --- END

// IP transactPg --- BEGIN
void DbsFmnc::beginPg() {
	PGresult* res;

	res = PQexec(dbsPg, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: failed to begin transaction\n");

	PQclear(res);
};

bool DbsFmnc::commitPg() {
	PGresult* res;

	res = PQexec(dbsPg, "COMMIT");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		rollbackPg();

		PQclear(res);
		return false;
	};

	PQclear(res);
	return true;
};

void DbsFmnc::rollbackPg() {
	PGresult* res;

	res = PQexec(dbsPg, "ROLLBACK");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: failed to roll back transaction\n");

	PQclear(res);
};
// IP transactPg --- END

bool DbsFmnc::loadUbigintBySQL(
			const string& sqlstr
			, ubigint& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUbigintBySQLMy(sqlstr, val);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadUbigintBySQLPg(sqlstr, val);

	return false;
};

bool DbsFmnc::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadStringBySQLPg(sqlstr, val);

	return false;
};

ubigint DbsFmnc::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefsBySQLPg(sqlstr, append, refs);

	return 0;
};

// IP loadfctsMy --- BEGIN
bool DbsFmnc::loadUbigintBySQLMy(
			const string& sqlstr
			, ubigint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadUbigintBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsFmnc::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadStringBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsFmnc::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadRefsBySQL)\n");

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};
// IP loadfctsMy --- END

// IP loadfctsPg --- BEGIN
bool DbsFmnc::loadUbigintBySQLPg(
			const string& sqlstr
			, ubigint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsFmnc::loadStringBySQLPg(
			const string& sqlstr
			, string& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;

	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val.assign(ptr, PQgetlength(res, 0, 0));

		retval = true;
	};

	PQclear(res);

	return retval;
};

ubigint DbsFmnc::loadRefsBySQLPg(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	PGresult* res; ubigint numrow; ubigint numread = 0; char* ptr;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	numrow = PQntuples(res);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		ptr = PQgetvalue(res, numread, 0); refs.push_back(atoll(ptr));
		numread++;
	};

	PQclear(res);

	return(numread);
};
// IP loadfctsPg --- END

void DbsFmnc::executeQuery(
			const string& sqlstr
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str())))
			throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	} else if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		PGresult* res;

		res = PQexec(dbsPg, sqlstr.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
			throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	};
};

void DbsFmnc::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrpg
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) executeQuery(sqlstrpg);
};

void DbsFmnc::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

void DbsFmnc::fillFeedFromKlst(
			const uint klsIxFmncVKeylist
			, const uint ixFmncVLocale
			, Feed& feed
		) {
	ListFmncAVKeylistKey klsAkeys;
	FmncAVKeylistKey* klsAkey = NULL;

	tblfmncavkeylistkey->loadRstByKls(klsIxFmncVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblfmncjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixFmncVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsFmnc::fillFeedFromKlstByMtbUref(
			const uint klsIxFmncVKeylist
			, const uint x1IxFmncVMaintable
			, const ubigint x1Uref
			, const uint ixFmncVLocale
			, Feed& feed
		) {
	ListFmncAVKeylistKey klsAkeys;
	FmncAVKeylistKey* klsAkey = NULL;

	tblfmncavkeylistkey->loadRstByKlsMtbUrf(klsIxFmncVKeylist, x1IxFmncVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblfmncjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixFmncVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsFmnc::getKlstTitleBySref(
			const uint klsIxFmncVKeylist
			, const string& sref
			, const uint ixFmncVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblfmncavkeylistkey->loadRefByKlsSrf(klsIxFmncVKeylist, sref, refKlk))
		if (!tblfmncjavkeylistkey->loadTitByKlkLcl(refKlk, ixFmncVLocale, retval))
			tblfmncavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsFmnc::getKlstTitleByMtbUrefSref(
			const uint klsIxFmncVKeylist
			, const uint x1IxFmncVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixFmncVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblfmncavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxFmncVKeylist, x1IxFmncVMaintable, x1Uref, sref, refKlk))
		if (!tblfmncjavkeylistkey->loadTitByKlkLcl(refKlk, ixFmncVLocale, retval))
			tblfmncavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsFmnc::fillFeedFromVlst(
			const uint vlsIxFmncVValuelist
			, const uint x1IxFmncVLocale
			, Feed& feed
		) {
	ListFmncAVValuelistVal vlsAvals;
	FmncAVValuelistVal* vlsAval = NULL;

	tblfmncavvaluelistval->loadRstByVlsLcl(vlsIxFmncVValuelist, x1IxFmncVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i=0;i<vlsAvals.nodes.size();i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};

