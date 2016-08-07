-- CREATE ROLE epsi LOGIN
-- 	ENCRYPTED PASSWORD 'md5f0bc6f83ba77933c9206cfbf7a4a8e2c'
-- 	NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE;
-- COMMENT ON ROLE epsi IS 'Epsi Software Universal Account';

CREATE DATABASE "DbsFmnc"
	WITH ENCODING='UTF8'
	OWNER = epsi
	CONNECTION LIMIT = -1;

DROP TABLE IF EXISTS TblFmncAccRMUserUniversal;
DROP TABLE IF EXISTS TblFmncAMBillPos;
DROP TABLE IF EXISTS TblFmncAMOrgDetail;
DROP TABLE IF EXISTS TblFmncAMPersonDetail;
DROP TABLE IF EXISTS TblFmncAMPurchorderPos;
DROP TABLE IF EXISTS TblFmncAMSamplePar;
DROP TABLE IF EXISTS TblFmncAMStepPar;
DROP TABLE IF EXISTS TblFmncAMToolAvl;
DROP TABLE IF EXISTS TblFmncAMToolChar;
DROP TABLE IF EXISTS TblFmncAMToolRes;
DROP TABLE IF EXISTS TblFmncAMToolUtil;
DROP TABLE IF EXISTS TblFmncAMUserAccess;
DROP TABLE IF EXISTS TblFmncAMUsergroupAccess;
DROP TABLE IF EXISTS TblFmncAVControlPar;
DROP TABLE IF EXISTS TblFmncAVKeylistKey;
DROP TABLE IF EXISTS TblFmncAVValuelistVal;
DROP SEQUENCE IF EXISTS TblFmncCFile;
DROP TABLE IF EXISTS TblFmncFabSMPersonMTool;
DROP TABLE IF EXISTS TblFmncHistRMUserUniversal;
DROP TABLE IF EXISTS TblFmncJAVKeylistKey;
DROP TABLE IF EXISTS TblFmncJMBillState;
DROP TABLE IF EXISTS TblFmncJMFabprojectState;
DROP TABLE IF EXISTS TblFmncJMFabuserState;
DROP TABLE IF EXISTS TblFmncJMOrgTitle;
DROP TABLE IF EXISTS TblFmncJMPersonLastname;
DROP TABLE IF EXISTS TblFmncJMProjectState;
DROP TABLE IF EXISTS TblFmncJMPurchorderState;
DROP TABLE IF EXISTS TblFmncJMRunState;
DROP TABLE IF EXISTS TblFmncJMSampleState;
DROP TABLE IF EXISTS TblFmncJMStockitemQuantity;
DROP TABLE IF EXISTS TblFmncJMToolUnitprice;
DROP TABLE IF EXISTS TblFmncJMUserState;
DROP TABLE IF EXISTS TblFmncMActivity;
DROP TABLE IF EXISTS TblFmncMAddress;
DROP TABLE IF EXISTS TblFmncMArticle;
DROP TABLE IF EXISTS TblFmncMBill;
DROP TABLE IF EXISTS TblFmncMFab;
DROP TABLE IF EXISTS TblFmncMFabproject;
DROP TABLE IF EXISTS TblFmncMFabuser;
DROP TABLE IF EXISTS TblFmncMFile;
DROP TABLE IF EXISTS TblFmncMnfSMPersonMTool;
DROP TABLE IF EXISTS TblFmncMOrg;
DROP TABLE IF EXISTS TblFmncMPerson;
DROP TABLE IF EXISTS TblFmncMProject;
DROP TABLE IF EXISTS TblFmncMPurchorder;
DROP TABLE IF EXISTS TblFmncMRun;
DROP TABLE IF EXISTS TblFmncMSample;
DROP TABLE IF EXISTS TblFmncMSession;
DROP TABLE IF EXISTS TblFmncMStep;
DROP TABLE IF EXISTS TblFmncMStockitem;
DROP TABLE IF EXISTS TblFmncMTool;
DROP TABLE IF EXISTS TblFmncMTooltype;
DROP TABLE IF EXISTS TblFmncMUser;
DROP TABLE IF EXISTS TblFmncMUsergroup;
DROP TABLE IF EXISTS TblFmncRMArticleMOrg;
DROP TABLE IF EXISTS TblFmncRMFabMRun;
DROP TABLE IF EXISTS TblFmncRMFabprojectMFabuser;
DROP TABLE IF EXISTS TblFmncRMFabuserMTool;
DROP TABLE IF EXISTS TblFmncRMFileMSample;
DROP TABLE IF EXISTS TblFmncRMFileMStep;
DROP TABLE IF EXISTS TblFmncRMOrgMPerson;
DROP TABLE IF EXISTS TblFmncRMPersonMRun;
DROP TABLE IF EXISTS TblFmncRMRunMSample;
DROP TABLE IF EXISTS TblFmncRMSampleMStep;
DROP TABLE IF EXISTS TblFmncRMToolMTooltype;
DROP TABLE IF EXISTS TblFmncRMUsergroupUniversal;
DROP TABLE IF EXISTS TblFmncRMUserMUsergroup;
DROP TABLE IF EXISTS TblFmncSvcRMOrgMTool;
DROP TABLE IF EXISTS TblFmncSvcTMPersonMTool;
DROP TABLE IF EXISTS TblFmncTMFileMSample;

DROP TABLE IF EXISTS TblFmncQAct1NStep;
DROP TABLE IF EXISTS TblFmncQActList;
DROP TABLE IF EXISTS TblFmncQAdrList;
DROP TABLE IF EXISTS TblFmncQArt1NSample;
DROP TABLE IF EXISTS TblFmncQArt1NStockitem;
DROP TABLE IF EXISTS TblFmncQArtList;
DROP TABLE IF EXISTS TblFmncQArtMNOrg;
DROP TABLE IF EXISTS TblFmncQArtRef1NFile;
DROP TABLE IF EXISTS TblFmncQBilAPos;
DROP TABLE IF EXISTS TblFmncQBilList;
DROP TABLE IF EXISTS TblFmncQFab1NFabproject;
DROP TABLE IF EXISTS TblFmncQFab1NFabuser;
DROP TABLE IF EXISTS TblFmncQFabFab1NTool;
DROP TABLE IF EXISTS TblFmncQFabList;
DROP TABLE IF EXISTS TblFmncQFabMNRun;
DROP TABLE IF EXISTS TblFmncQFilList;
DROP TABLE IF EXISTS TblFmncQFilMNSample;
DROP TABLE IF EXISTS TblFmncQFilMNStep;
DROP TABLE IF EXISTS TblFmncQFpj1NBill;
DROP TABLE IF EXISTS TblFmncQFpjList;
DROP TABLE IF EXISTS TblFmncQFpjMNFabuser;
DROP TABLE IF EXISTS TblFmncQFusList;
DROP TABLE IF EXISTS TblFmncQFusMNFabproject;
DROP TABLE IF EXISTS TblFmncQFusMNTool;
DROP TABLE IF EXISTS TblFmncQOrg1NArticle;
DROP TABLE IF EXISTS TblFmncQOrg1NStockitem;
DROP TABLE IF EXISTS TblFmncQOrgADetail;
DROP TABLE IF EXISTS TblFmncQOrgBio1NFabproject;
DROP TABLE IF EXISTS TblFmncQOrgHk1NAddress;
DROP TABLE IF EXISTS TblFmncQOrgKStocklcn;
DROP TABLE IF EXISTS TblFmncQOrgList;
DROP TABLE IF EXISTS TblFmncQOrgMNArticle;
DROP TABLE IF EXISTS TblFmncQOrgMnf1NTool;
DROP TABLE IF EXISTS TblFmncQOrgMNPerson;
DROP TABLE IF EXISTS TblFmncQOrgPco1NPurchorder;
DROP TABLE IF EXISTS TblFmncQOrgSpl1NPurchorder;
DROP TABLE IF EXISTS TblFmncQOrgSup1NOrg;
DROP TABLE IF EXISTS TblFmncQOrgSvcMNTool;
DROP TABLE IF EXISTS TblFmncQPcoAPos;
DROP TABLE IF EXISTS TblFmncQPcoList;
DROP TABLE IF EXISTS TblFmncQPreselect;
DROP TABLE IF EXISTS TblFmncQPrj1NRun;
DROP TABLE IF EXISTS TblFmncQPrjList;
DROP TABLE IF EXISTS TblFmncQPrsADetail;
DROP TABLE IF EXISTS TblFmncQPrsHk1NAddress;
DROP TABLE IF EXISTS TblFmncQPrsList;
DROP TABLE IF EXISTS TblFmncQPrsMNOrg;
DROP TABLE IF EXISTS TblFmncQPrsMNRun;
DROP TABLE IF EXISTS TblFmncQRunList;
DROP TABLE IF EXISTS TblFmncQRunMNFab;
DROP TABLE IF EXISTS TblFmncQRunMNPerson;
DROP TABLE IF EXISTS TblFmncQRunMNSample;
DROP TABLE IF EXISTS TblFmncQRunRef1NFile;
DROP TABLE IF EXISTS TblFmncQRunRun1NActivity;
DROP TABLE IF EXISTS TblFmncQSelect;
DROP TABLE IF EXISTS TblFmncQSepAPar;
DROP TABLE IF EXISTS TblFmncQSepList;
DROP TABLE IF EXISTS TblFmncQSepMNFile;
DROP TABLE IF EXISTS TblFmncQSepMNSample;
DROP TABLE IF EXISTS TblFmncQSepRef1NFile;
DROP TABLE IF EXISTS TblFmncQSkiList;
DROP TABLE IF EXISTS TblFmncQSmpAPar;
DROP TABLE IF EXISTS TblFmncQSmpList;
DROP TABLE IF EXISTS TblFmncQSmpMNFile;
DROP TABLE IF EXISTS TblFmncQSmpMNRun;
DROP TABLE IF EXISTS TblFmncQSmpMNStep;
DROP TABLE IF EXISTS TblFmncQSmpRef1NFile;
DROP TABLE IF EXISTS TblFmncQSmpSup1NSample;
DROP TABLE IF EXISTS TblFmncQStpAPar;
DROP TABLE IF EXISTS TblFmncQStpKSteppar;
DROP TABLE IF EXISTS TblFmncQStpList;
DROP TABLE IF EXISTS TblFmncQStpMNFile;
DROP TABLE IF EXISTS TblFmncQStpRef1NFile;
DROP TABLE IF EXISTS TblFmncQStpTpl1NStep;
DROP TABLE IF EXISTS TblFmncQTol1NArticle;
DROP TABLE IF EXISTS TblFmncQTolAAvl;
DROP TABLE IF EXISTS TblFmncQTolAChar;
DROP TABLE IF EXISTS TblFmncQTolARes;
DROP TABLE IF EXISTS TblFmncQTolAUtil;
DROP TABLE IF EXISTS TblFmncQTolKSteppar;
DROP TABLE IF EXISTS TblFmncQTolKToolchar;
DROP TABLE IF EXISTS TblFmncQTolList;
DROP TABLE IF EXISTS TblFmncQTolMNFabuser;
DROP TABLE IF EXISTS TblFmncQTolMNTooltype;
DROP TABLE IF EXISTS TblFmncQTolRef1NFile;
DROP TABLE IF EXISTS TblFmncQTolRlv1NStep;
DROP TABLE IF EXISTS TblFmncQTolSvcMNOrg;
DROP TABLE IF EXISTS TblFmncQTtyKSteppar;
DROP TABLE IF EXISTS TblFmncQTtyKToolchar;
DROP TABLE IF EXISTS TblFmncQTtyList;
DROP TABLE IF EXISTS TblFmncQTtyMNTool;
DROP TABLE IF EXISTS TblFmncQTtyRlv1NStep;
DROP TABLE IF EXISTS TblFmncQTtySup1NTooltype;
DROP TABLE IF EXISTS TblFmncQUsgAAccess;
DROP TABLE IF EXISTS TblFmncQUsgList;
DROP TABLE IF EXISTS TblFmncQUsgMNUser;
DROP TABLE IF EXISTS TblFmncQUsr1NSession;
DROP TABLE IF EXISTS TblFmncQUsrAAccess;
DROP TABLE IF EXISTS TblFmncQUsrList;
DROP TABLE IF EXISTS TblFmncQUsrMNUsergroup;

CREATE TABLE TblFmncAccRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUser BIGINT,
	unvIxFmncVMaintable INT,
	unvUref BIGINT,
	ixFmncVAccess INT
);
ALTER TABLE TblFmncAccRMUserUniversal OWNER TO epsi;
CREATE INDEX TblFmncAccRMUserUniversal_refFmncMUser ON TblFmncAccRMUserUniversal (refFmncMUser);
CREATE INDEX TblFmncAccRMUserUniversal_unvIxFmncVMaintable ON TblFmncAccRMUserUniversal (unvIxFmncVMaintable);
CREATE INDEX TblFmncAccRMUserUniversal_unvUref ON TblFmncAccRMUserUniversal (unvUref);

CREATE TABLE TblFmncAMBillPos(
	ref BIGSERIAL PRIMARY KEY,
	bilRefFmncMBill BIGINT,
	bilNum INT,
	x1RefFmncMFabuser BIGINT,
	x2RefFmncMTool BIGINT,
	Quantity DOUBLE PRECISION,
	Article VARCHAR(255),
	Unitprice DOUBLE PRECISION,
	Price DOUBLE PRECISION
);
ALTER TABLE TblFmncAMBillPos OWNER TO epsi;
CREATE INDEX TblFmncAMBillPos_bilRefFmncMBill ON TblFmncAMBillPos (bilRefFmncMBill);
CREATE INDEX TblFmncAMBillPos_bilNum ON TblFmncAMBillPos (bilNum);
CREATE INDEX TblFmncAMBillPos_x1RefFmncMFabuser ON TblFmncAMBillPos (x1RefFmncMFabuser);
CREATE INDEX TblFmncAMBillPos_x2RefFmncMTool ON TblFmncAMBillPos (x2RefFmncMTool);

CREATE TABLE TblFmncAMOrgDetail(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMOrg BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblFmncAMOrgDetail OWNER TO epsi;
CREATE INDEX TblFmncAMOrgDetail_refFmncMOrg ON TblFmncAMOrgDetail (refFmncMOrg);

CREATE TABLE TblFmncAMPersonDetail(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblFmncAMPersonDetail OWNER TO epsi;
CREATE INDEX TblFmncAMPersonDetail_refFmncMPerson ON TblFmncAMPersonDetail (refFmncMPerson);

CREATE TABLE TblFmncAMPurchorderPos(
	ref BIGSERIAL PRIMARY KEY,
	pcoRefFmncMPurchorder BIGINT,
	pcoNum INT,
	Quantity DOUBLE PRECISION,
	Itemno VARCHAR(30),
	refFmncMArticle BIGINT,
	Unitprice DOUBLE PRECISION,
	Price DOUBLE PRECISION
);
ALTER TABLE TblFmncAMPurchorderPos OWNER TO epsi;
CREATE INDEX TblFmncAMPurchorderPos_pcoRefFmncMPurchorder ON TblFmncAMPurchorderPos (pcoRefFmncMPurchorder);
CREATE INDEX TblFmncAMPurchorderPos_pcoNum ON TblFmncAMPurchorderPos (pcoNum);

CREATE TABLE TblFmncAMSamplePar(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMSample BIGINT,
	x1SrefKKey VARCHAR(50),
	osrefKVal VARCHAR(50)
);
ALTER TABLE TblFmncAMSamplePar OWNER TO epsi;
CREATE INDEX TblFmncAMSamplePar_refFmncMSample ON TblFmncAMSamplePar (refFmncMSample);

CREATE TABLE TblFmncAMStepPar(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMStep BIGINT,
	x1OsrefFmncKSteppar VARCHAR(50),
	x2IxVTbl INT,
	x2Uref BIGINT,
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncAMStepPar OWNER TO epsi;
CREATE INDEX TblFmncAMStepPar_refFmncMStep ON TblFmncAMStepPar (refFmncMStep);
CREATE INDEX TblFmncAMStepPar_x2IxVTbl ON TblFmncAMStepPar (x2IxVTbl);
CREATE INDEX TblFmncAMStepPar_x2Uref ON TblFmncAMStepPar (x2Uref);

CREATE TABLE TblFmncAMToolAvl(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMTool BIGINT,
	x1Startd INT,
	x2IxVWkday INT,
	x3Startt INT,
	x3Stopt INT,
	srefKAvltype VARCHAR(50)
);
ALTER TABLE TblFmncAMToolAvl OWNER TO epsi;
CREATE INDEX TblFmncAMToolAvl_refFmncMTool ON TblFmncAMToolAvl (refFmncMTool);
CREATE INDEX TblFmncAMToolAvl_x1Startd ON TblFmncAMToolAvl (x1Startd);
CREATE INDEX TblFmncAMToolAvl_x2IxVWkday ON TblFmncAMToolAvl (x2IxVWkday);
CREATE INDEX TblFmncAMToolAvl_x3Startt ON TblFmncAMToolAvl (x3Startt);
CREATE INDEX TblFmncAMToolAvl_x3Stopt ON TblFmncAMToolAvl (x3Stopt);

CREATE TABLE TblFmncAMToolChar(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMTool BIGINT,
	x1OsrefFmncKToolchar VARCHAR(50),
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncAMToolChar OWNER TO epsi;
CREATE INDEX TblFmncAMToolChar_refFmncMTool ON TblFmncAMToolChar (refFmncMTool);

CREATE TABLE TblFmncAMToolRes(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMTool BIGINT,
	x1RefFmncMFabuser BIGINT,
	startd INT,
	startt INT,
	stopt INT,
	srefKRestype VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblFmncAMToolRes OWNER TO epsi;
CREATE INDEX TblFmncAMToolRes_refFmncMTool ON TblFmncAMToolRes (refFmncMTool);
CREATE INDEX TblFmncAMToolRes_x1RefFmncMFabuser ON TblFmncAMToolRes (x1RefFmncMFabuser);
CREATE INDEX TblFmncAMToolRes_startd ON TblFmncAMToolRes (startd);
CREATE INDEX TblFmncAMToolRes_startt ON TblFmncAMToolRes (startt);

CREATE TABLE TblFmncAMToolUtil(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMTool BIGINT,
	x1RefFmncMFabproject BIGINT,
	x2RefFmncMFabuser BIGINT,
	startd INT,
	startt INT,
	stopt INT,
	Unitprice DOUBLE PRECISION,
	Comment TEXT
);
ALTER TABLE TblFmncAMToolUtil OWNER TO epsi;
CREATE INDEX TblFmncAMToolUtil_refFmncMTool ON TblFmncAMToolUtil (refFmncMTool);
CREATE INDEX TblFmncAMToolUtil_x1RefFmncMFabproject ON TblFmncAMToolUtil (x1RefFmncMFabproject);
CREATE INDEX TblFmncAMToolUtil_x2RefFmncMFabuser ON TblFmncAMToolUtil (x2RefFmncMFabuser);
CREATE INDEX TblFmncAMToolUtil_startd ON TblFmncAMToolUtil (startd);
CREATE INDEX TblFmncAMToolUtil_startt ON TblFmncAMToolUtil (startt);

CREATE TABLE TblFmncAMUserAccess(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUser BIGINT,
	x1IxFmncVCard INT,
	ixFmncWUiaccess INT
);
ALTER TABLE TblFmncAMUserAccess OWNER TO epsi;
CREATE INDEX TblFmncAMUserAccess_refFmncMUser ON TblFmncAMUserAccess (refFmncMUser);
CREATE INDEX TblFmncAMUserAccess_x1IxFmncVCard ON TblFmncAMUserAccess (x1IxFmncVCard);

CREATE TABLE TblFmncAMUsergroupAccess(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUsergroup BIGINT,
	x1IxFmncVCard INT,
	ixFmncWUiaccess INT
);
ALTER TABLE TblFmncAMUsergroupAccess OWNER TO epsi;
CREATE INDEX TblFmncAMUsergroupAccess_refFmncMUsergroup ON TblFmncAMUsergroupAccess (refFmncMUsergroup);
CREATE INDEX TblFmncAMUsergroupAccess_x1IxFmncVCard ON TblFmncAMUsergroupAccess (x1IxFmncVCard);

CREATE TABLE TblFmncAVControlPar(
	ref BIGSERIAL PRIMARY KEY,
	ixFmncVControl INT,
	x1RefFmncMUser BIGINT,
	x2IxFmncVLocale INT,
	Par VARCHAR(255),
	Val VARCHAR(255)
);
ALTER TABLE TblFmncAVControlPar OWNER TO epsi;
CREATE INDEX TblFmncAVControlPar_ixFmncVControl ON TblFmncAVControlPar (ixFmncVControl);
CREATE INDEX TblFmncAVControlPar_x1RefFmncMUser ON TblFmncAVControlPar (x1RefFmncMUser);
CREATE INDEX TblFmncAVControlPar_x2IxFmncVLocale ON TblFmncAVControlPar (x2IxFmncVLocale);
CREATE INDEX TblFmncAVControlPar_Par ON TblFmncAVControlPar (Par);

CREATE TABLE TblFmncAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	klsIxFmncVKeylist INT,
	klsNum INT,
	x1IxFmncVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncAVKeylistKey OWNER TO epsi;
CREATE INDEX TblFmncAVKeylistKey_klsIxFmncVKeylist ON TblFmncAVKeylistKey (klsIxFmncVKeylist);
CREATE INDEX TblFmncAVKeylistKey_klsNum ON TblFmncAVKeylistKey (klsNum);
CREATE INDEX TblFmncAVKeylistKey_x1IxFmncVMaintable ON TblFmncAVKeylistKey (x1IxFmncVMaintable);
CREATE INDEX TblFmncAVKeylistKey_x1Uref ON TblFmncAVKeylistKey (x1Uref);
CREATE INDEX TblFmncAVKeylistKey_sref ON TblFmncAVKeylistKey (sref);

CREATE TABLE TblFmncAVValuelistVal(
	ref BIGSERIAL PRIMARY KEY,
	vlsIxFmncVValuelist INT,
	vlsNum INT,
	x1IxFmncVLocale INT,
	Val VARCHAR(255)
);
ALTER TABLE TblFmncAVValuelistVal OWNER TO epsi;
CREATE INDEX TblFmncAVValuelistVal_vlsIxFmncVValuelist ON TblFmncAVValuelistVal (vlsIxFmncVValuelist);
CREATE INDEX TblFmncAVValuelistVal_vlsNum ON TblFmncAVValuelistVal (vlsNum);
CREATE INDEX TblFmncAVValuelistVal_x1IxFmncVLocale ON TblFmncAVValuelistVal (x1IxFmncVLocale);

CREATE SEQUENCE TblFmncCFile INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblFmncCFile OWNER TO epsi;

CREATE TABLE TblFmncFabSMPersonMTool(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPerson BIGINT,
	refM BIGINT,
	numM INT
);
ALTER TABLE TblFmncFabSMPersonMTool OWNER TO epsi;
CREATE INDEX TblFmncFabSMPersonMTool_refFmncMPerson ON TblFmncFabSMPersonMTool (refFmncMPerson);
CREATE INDEX TblFmncFabSMPersonMTool_refM ON TblFmncFabSMPersonMTool (refM);
CREATE INDEX TblFmncFabSMPersonMTool_numM ON TblFmncFabSMPersonMTool (numM);

CREATE TABLE TblFmncHistRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUser BIGINT,
	unvIxFmncVMaintable INT,
	unvUref BIGINT,
	ixFmncVCard INT,
	ixFmncVPreset INT,
	preIxFmncVMaintable INT,
	preUref BIGINT,
	start INT
);
ALTER TABLE TblFmncHistRMUserUniversal OWNER TO epsi;
CREATE INDEX TblFmncHistRMUserUniversal_refFmncMUser ON TblFmncHistRMUserUniversal (refFmncMUser);
CREATE INDEX TblFmncHistRMUserUniversal_unvIxFmncVMaintable ON TblFmncHistRMUserUniversal (unvIxFmncVMaintable);
CREATE INDEX TblFmncHistRMUserUniversal_unvUref ON TblFmncHistRMUserUniversal (unvUref);
CREATE INDEX TblFmncHistRMUserUniversal_ixFmncVCard ON TblFmncHistRMUserUniversal (ixFmncVCard);
CREATE INDEX TblFmncHistRMUserUniversal_ixFmncVPreset ON TblFmncHistRMUserUniversal (ixFmncVPreset);
CREATE INDEX TblFmncHistRMUserUniversal_preIxFmncVMaintable ON TblFmncHistRMUserUniversal (preIxFmncVMaintable);
CREATE INDEX TblFmncHistRMUserUniversal_preUref ON TblFmncHistRMUserUniversal (preUref);

CREATE TABLE TblFmncJAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	refFmncAVKeylistKey BIGINT,
	x1IxFmncVLocale INT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncJAVKeylistKey OWNER TO epsi;
CREATE INDEX TblFmncJAVKeylistKey_refFmncAVKeylistKey ON TblFmncJAVKeylistKey (refFmncAVKeylistKey);
CREATE INDEX TblFmncJAVKeylistKey_x1IxFmncVLocale ON TblFmncJAVKeylistKey (x1IxFmncVLocale);

CREATE TABLE TblFmncJMBillState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMBill BIGINT,
	x1Startd INT,
	ixVState INT
);
ALTER TABLE TblFmncJMBillState OWNER TO epsi;
CREATE INDEX TblFmncJMBillState_refFmncMBill ON TblFmncJMBillState (refFmncMBill);
CREATE INDEX TblFmncJMBillState_x1Startd ON TblFmncJMBillState (x1Startd);

CREATE TABLE TblFmncJMFabprojectState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFabproject BIGINT,
	x1Startd INT,
	ixVState INT
);
ALTER TABLE TblFmncJMFabprojectState OWNER TO epsi;
CREATE INDEX TblFmncJMFabprojectState_refFmncMFabproject ON TblFmncJMFabprojectState (refFmncMFabproject);
CREATE INDEX TblFmncJMFabprojectState_x1Startd ON TblFmncJMFabprojectState (x1Startd);

CREATE TABLE TblFmncJMFabuserState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFabuser BIGINT,
	x1Startd INT,
	ixVState INT
);
ALTER TABLE TblFmncJMFabuserState OWNER TO epsi;
CREATE INDEX TblFmncJMFabuserState_refFmncMFabuser ON TblFmncJMFabuserState (refFmncMFabuser);
CREATE INDEX TblFmncJMFabuserState_x1Startd ON TblFmncJMFabuserState (x1Startd);

CREATE TABLE TblFmncJMOrgTitle(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMOrg BIGINT,
	x1Startd INT,
	Title VARCHAR(50)
);
ALTER TABLE TblFmncJMOrgTitle OWNER TO epsi;
CREATE INDEX TblFmncJMOrgTitle_refFmncMOrg ON TblFmncJMOrgTitle (refFmncMOrg);
CREATE INDEX TblFmncJMOrgTitle_x1Startd ON TblFmncJMOrgTitle (x1Startd);
CREATE INDEX TblFmncJMOrgTitle_Title ON TblFmncJMOrgTitle (Title);

CREATE TABLE TblFmncJMPersonLastname(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
ALTER TABLE TblFmncJMPersonLastname OWNER TO epsi;
CREATE INDEX TblFmncJMPersonLastname_refFmncMPerson ON TblFmncJMPersonLastname (refFmncMPerson);
CREATE INDEX TblFmncJMPersonLastname_x1Startd ON TblFmncJMPersonLastname (x1Startd);
CREATE INDEX TblFmncJMPersonLastname_Lastname ON TblFmncJMPersonLastname (Lastname);

CREATE TABLE TblFmncJMProjectState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMProject BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblFmncJMProjectState OWNER TO epsi;
CREATE INDEX TblFmncJMProjectState_refFmncMProject ON TblFmncJMProjectState (refFmncMProject);
CREATE INDEX TblFmncJMProjectState_x1Start ON TblFmncJMProjectState (x1Start);

CREATE TABLE TblFmncJMPurchorderState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPurchorder BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblFmncJMPurchorderState OWNER TO epsi;
CREATE INDEX TblFmncJMPurchorderState_refFmncMPurchorder ON TblFmncJMPurchorderState (refFmncMPurchorder);
CREATE INDEX TblFmncJMPurchorderState_x1Start ON TblFmncJMPurchorderState (x1Start);

CREATE TABLE TblFmncJMRunState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMRun BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblFmncJMRunState OWNER TO epsi;
CREATE INDEX TblFmncJMRunState_refFmncMRun ON TblFmncJMRunState (refFmncMRun);
CREATE INDEX TblFmncJMRunState_x1Start ON TblFmncJMRunState (x1Start);

CREATE TABLE TblFmncJMSampleState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMSample BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblFmncJMSampleState OWNER TO epsi;
CREATE INDEX TblFmncJMSampleState_refFmncMSample ON TblFmncJMSampleState (refFmncMSample);
CREATE INDEX TblFmncJMSampleState_x1Start ON TblFmncJMSampleState (x1Start);

CREATE TABLE TblFmncJMStockitemQuantity(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMStockitem BIGINT,
	x1Startd INT,
	Quantity VARCHAR(10)
);
ALTER TABLE TblFmncJMStockitemQuantity OWNER TO epsi;
CREATE INDEX TblFmncJMStockitemQuantity_refFmncMStockitem ON TblFmncJMStockitemQuantity (refFmncMStockitem);
CREATE INDEX TblFmncJMStockitemQuantity_x1Startd ON TblFmncJMStockitemQuantity (x1Startd);

CREATE TABLE TblFmncJMToolUnitprice(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMTool BIGINT,
	x1Startd INT,
	Unitprice DOUBLE PRECISION
);
ALTER TABLE TblFmncJMToolUnitprice OWNER TO epsi;
CREATE INDEX TblFmncJMToolUnitprice_refFmncMTool ON TblFmncJMToolUnitprice (refFmncMTool);
CREATE INDEX TblFmncJMToolUnitprice_x1Startd ON TblFmncJMToolUnitprice (x1Startd);

CREATE TABLE TblFmncJMUserState(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUser BIGINT,
	x1Startd INT,
	ixVState INT
);
ALTER TABLE TblFmncJMUserState OWNER TO epsi;
CREATE INDEX TblFmncJMUserState_refFmncMUser ON TblFmncJMUserState (refFmncMUser);
CREATE INDEX TblFmncJMUserState_x1Startd ON TblFmncJMUserState (x1Startd);

CREATE TABLE TblFmncMActivity(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	runRefFmncMRun BIGINT,
	runNum INT,
	Title VARCHAR(100),
	Comment TEXT
);
ALTER TABLE TblFmncMActivity OWNER TO epsi;
CREATE INDEX TblFmncMActivity_grp ON TblFmncMActivity (grp);
CREATE INDEX TblFmncMActivity_own ON TblFmncMActivity (own);
CREATE INDEX TblFmncMActivity_runRefFmncMRun ON TblFmncMActivity (runRefFmncMRun);
CREATE INDEX TblFmncMActivity_runNum ON TblFmncMActivity (runNum);

CREATE TABLE TblFmncMAddress(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	x1Startd INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	srefKAdrtype VARCHAR(50),
	Address1 VARCHAR(100),
	Address2 VARCHAR(100),
	Zipcode VARCHAR(10),
	City VARCHAR(50),
	State VARCHAR(50),
	srefKCountry VARCHAR(50)
);
ALTER TABLE TblFmncMAddress OWNER TO epsi;
CREATE INDEX TblFmncMAddress_grp ON TblFmncMAddress (grp);
CREATE INDEX TblFmncMAddress_own ON TblFmncMAddress (own);
CREATE INDEX TblFmncMAddress_x1Startd ON TblFmncMAddress (x1Startd);
CREATE INDEX TblFmncMAddress_hkIxVTbl ON TblFmncMAddress (hkIxVTbl);
CREATE INDEX TblFmncMAddress_hkUref ON TblFmncMAddress (hkUref);
CREATE INDEX TblFmncMAddress_srefKAdrtype ON TblFmncMAddress (srefKAdrtype);
CREATE INDEX TblFmncMAddress_City ON TblFmncMAddress (City);
CREATE INDEX TblFmncMAddress_srefKCountry ON TblFmncMAddress (srefKCountry);

CREATE TABLE TblFmncMArticle(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMOrg BIGINT,
	refFmncMTool BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(100),
	srefKType VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblFmncMArticle OWNER TO epsi;
CREATE INDEX TblFmncMArticle_grp ON TblFmncMArticle (grp);
CREATE INDEX TblFmncMArticle_own ON TblFmncMArticle (own);
CREATE INDEX TblFmncMArticle_refFmncMOrg ON TblFmncMArticle (refFmncMOrg);
CREATE INDEX TblFmncMArticle_refFmncMTool ON TblFmncMArticle (refFmncMTool);
CREATE INDEX TblFmncMArticle_sref ON TblFmncMArticle (sref);

CREATE TABLE TblFmncMBill(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMFabproject BIGINT,
	refFmncMFile BIGINT,
	sref VARCHAR(50),
	Date INT,
	refJState BIGINT,
	ixVState INT,
	Prdstart INT,
	Prdstop INT,
	Amount DOUBLE PRECISION,
	Comment TEXT
);
ALTER TABLE TblFmncMBill OWNER TO epsi;
CREATE INDEX TblFmncMBill_grp ON TblFmncMBill (grp);
CREATE INDEX TblFmncMBill_own ON TblFmncMBill (own);
CREATE INDEX TblFmncMBill_refFmncMFabproject ON TblFmncMBill (refFmncMFabproject);
CREATE INDEX TblFmncMBill_refFmncMFile ON TblFmncMBill (refFmncMFile);
CREATE INDEX TblFmncMBill_sref ON TblFmncMBill (sref);
CREATE INDEX TblFmncMBill_Date ON TblFmncMBill (Date);
CREATE INDEX TblFmncMBill_ixVState ON TblFmncMBill (ixVState);

CREATE TABLE TblFmncMFab(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMOrg BIGINT
);
ALTER TABLE TblFmncMFab OWNER TO epsi;
CREATE INDEX TblFmncMFab_grp ON TblFmncMFab (grp);
CREATE INDEX TblFmncMFab_own ON TblFmncMFab (own);
CREATE INDEX TblFmncMFab_refFmncMOrg ON TblFmncMFab (refFmncMOrg);

CREATE TABLE TblFmncMFabproject(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMFab BIGINT,
	bioRefFmncMOrg BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(100),
	refJState BIGINT,
	ixVState INT,
	bipRefFmncMPerson BIGINT,
	Comment TEXT
);
ALTER TABLE TblFmncMFabproject OWNER TO epsi;
CREATE INDEX TblFmncMFabproject_grp ON TblFmncMFabproject (grp);
CREATE INDEX TblFmncMFabproject_own ON TblFmncMFabproject (own);
CREATE INDEX TblFmncMFabproject_refFmncMFab ON TblFmncMFabproject (refFmncMFab);
CREATE INDEX TblFmncMFabproject_bioRefFmncMOrg ON TblFmncMFabproject (bioRefFmncMOrg);
CREATE INDEX TblFmncMFabproject_sref ON TblFmncMFabproject (sref);
CREATE INDEX TblFmncMFabproject_ixVState ON TblFmncMFabproject (ixVState);

CREATE TABLE TblFmncMFabuser(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMFab BIGINT,
	refFmncMPerson BIGINT,
	refRFabproject BIGINT,
	refFmncMFabproject BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT
);
ALTER TABLE TblFmncMFabuser OWNER TO epsi;
CREATE INDEX TblFmncMFabuser_grp ON TblFmncMFabuser (grp);
CREATE INDEX TblFmncMFabuser_own ON TblFmncMFabuser (own);
CREATE INDEX TblFmncMFabuser_refFmncMFab ON TblFmncMFabuser (refFmncMFab);
CREATE INDEX TblFmncMFabuser_refFmncMPerson ON TblFmncMFabuser (refFmncMPerson);
CREATE INDEX TblFmncMFabuser_refFmncMFabproject ON TblFmncMFabuser (refFmncMFabproject);
CREATE INDEX TblFmncMFabuser_sref ON TblFmncMFabuser (sref);
CREATE INDEX TblFmncMFabuser_ixVState ON TblFmncMFabuser (ixVState);

CREATE TABLE TblFmncMFile(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size SMALLINT,
	Comment TEXT
);
ALTER TABLE TblFmncMFile OWNER TO epsi;
CREATE INDEX TblFmncMFile_grp ON TblFmncMFile (grp);
CREATE INDEX TblFmncMFile_own ON TblFmncMFile (own);
CREATE INDEX TblFmncMFile_refFmncCFile ON TblFmncMFile (refFmncCFile);
CREATE INDEX TblFmncMFile_refIxVTbl ON TblFmncMFile (refIxVTbl);
CREATE INDEX TblFmncMFile_refUref ON TblFmncMFile (refUref);
CREATE INDEX TblFmncMFile_Filename ON TblFmncMFile (Filename);

CREATE TABLE TblFmncMnfSMPersonMTool(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPerson BIGINT,
	refM BIGINT
);
ALTER TABLE TblFmncMnfSMPersonMTool OWNER TO epsi;
CREATE INDEX TblFmncMnfSMPersonMTool_refFmncMPerson ON TblFmncMnfSMPersonMTool (refFmncMPerson);
CREATE INDEX TblFmncMnfSMPersonMTool_refM ON TblFmncMnfSMPersonMTool (refM);

CREATE TABLE TblFmncMOrg(
	ref BIGSERIAL PRIMARY KEY,
	ixWDerivate INT,
	refFmncMAddress BIGINT,
	supRefFmncMOrg BIGINT,
	supLvl SMALLINT,
	sref VARCHAR(50),
	refJTitle BIGINT,
	Title VARCHAR(50),
	telRefADetail BIGINT,
	Tel VARCHAR(255),
	emlRefADetail BIGINT,
	Eml VARCHAR(255)
);
ALTER TABLE TblFmncMOrg OWNER TO epsi;
CREATE INDEX TblFmncMOrg_ixWDerivate ON TblFmncMOrg (ixWDerivate);
CREATE INDEX TblFmncMOrg_refFmncMAddress ON TblFmncMOrg (refFmncMAddress);
CREATE INDEX TblFmncMOrg_supRefFmncMOrg ON TblFmncMOrg (supRefFmncMOrg);
CREATE INDEX TblFmncMOrg_supLvl ON TblFmncMOrg (supLvl);
CREATE INDEX TblFmncMOrg_sref ON TblFmncMOrg (sref);
CREATE INDEX TblFmncMOrg_Title ON TblFmncMOrg (Title);

CREATE TABLE TblFmncMPerson(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	refROrg BIGINT,
	refFmncMOrg BIGINT,
	refFmncMAddress BIGINT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	Tel VARCHAR(255),
	emlRefADetail BIGINT,
	Eml VARCHAR(255),
	Salutation VARCHAR(100)
);
ALTER TABLE TblFmncMPerson OWNER TO epsi;
CREATE INDEX TblFmncMPerson_grp ON TblFmncMPerson (grp);
CREATE INDEX TblFmncMPerson_own ON TblFmncMPerson (own);
CREATE INDEX TblFmncMPerson_ixWDerivate ON TblFmncMPerson (ixWDerivate);
CREATE INDEX TblFmncMPerson_refFmncMOrg ON TblFmncMPerson (refFmncMOrg);
CREATE INDEX TblFmncMPerson_refFmncMAddress ON TblFmncMPerson (refFmncMAddress);
CREATE INDEX TblFmncMPerson_Lastname ON TblFmncMPerson (Lastname);

CREATE TABLE TblFmncMProject(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	Title VARCHAR(100),
	refJState BIGINT,
	ixVState INT,
	Comment TEXT
);
ALTER TABLE TblFmncMProject OWNER TO epsi;
CREATE INDEX TblFmncMProject_grp ON TblFmncMProject (grp);
CREATE INDEX TblFmncMProject_own ON TblFmncMProject (own);
CREATE INDEX TblFmncMProject_Title ON TblFmncMProject (Title);
CREATE INDEX TblFmncMProject_ixVState ON TblFmncMProject (ixVState);

CREATE TABLE TblFmncMPurchorder(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	pcoRefFmncMOrg BIGINT,
	splRefFmncMOrg BIGINT,
	refFmncMFile BIGINT,
	sref VARCHAR(50),
	Date INT,
	refJState BIGINT,
	ixVState INT,
	Amount DOUBLE PRECISION,
	pcpRefFmncMPerson BIGINT,
	Comment TEXT
);
ALTER TABLE TblFmncMPurchorder OWNER TO epsi;
CREATE INDEX TblFmncMPurchorder_grp ON TblFmncMPurchorder (grp);
CREATE INDEX TblFmncMPurchorder_own ON TblFmncMPurchorder (own);
CREATE INDEX TblFmncMPurchorder_pcoRefFmncMOrg ON TblFmncMPurchorder (pcoRefFmncMOrg);
CREATE INDEX TblFmncMPurchorder_splRefFmncMOrg ON TblFmncMPurchorder (splRefFmncMOrg);
CREATE INDEX TblFmncMPurchorder_refFmncMFile ON TblFmncMPurchorder (refFmncMFile);
CREATE INDEX TblFmncMPurchorder_sref ON TblFmncMPurchorder (sref);
CREATE INDEX TblFmncMPurchorder_Date ON TblFmncMPurchorder (Date);
CREATE INDEX TblFmncMPurchorder_ixVState ON TblFmncMPurchorder (ixVState);

CREATE TABLE TblFmncMRun(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMProject BIGINT,
	Title VARCHAR(100),
	refJState BIGINT,
	ixVState INT,
	Comment TEXT
);
ALTER TABLE TblFmncMRun OWNER TO epsi;
CREATE INDEX TblFmncMRun_grp ON TblFmncMRun (grp);
CREATE INDEX TblFmncMRun_own ON TblFmncMRun (own);
CREATE INDEX TblFmncMRun_refFmncMProject ON TblFmncMRun (refFmncMProject);
CREATE INDEX TblFmncMRun_Title ON TblFmncMRun (Title);
CREATE INDEX TblFmncMRun_ixVState ON TblFmncMRun (ixVState);

CREATE TABLE TblFmncMSample(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	supRefFmncMSample BIGINT,
	supLvl SMALLINT,
	refFmncMArticle BIGINT,
	sref VARCHAR(50),
	Material VARCHAR(100),
	refJState BIGINT,
	ixVState INT,
	Comment TEXT
);
ALTER TABLE TblFmncMSample OWNER TO epsi;
CREATE INDEX TblFmncMSample_grp ON TblFmncMSample (grp);
CREATE INDEX TblFmncMSample_own ON TblFmncMSample (own);
CREATE INDEX TblFmncMSample_supRefFmncMSample ON TblFmncMSample (supRefFmncMSample);
CREATE INDEX TblFmncMSample_supLvl ON TblFmncMSample (supLvl);
CREATE INDEX TblFmncMSample_refFmncMArticle ON TblFmncMSample (refFmncMArticle);
CREATE INDEX TblFmncMSample_sref ON TblFmncMSample (sref);
CREATE INDEX TblFmncMSample_ixVState ON TblFmncMSample (ixVState);

CREATE TABLE TblFmncMSession(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
ALTER TABLE TblFmncMSession OWNER TO epsi;
CREATE INDEX TblFmncMSession_refFmncMUser ON TblFmncMSession (refFmncMUser);
CREATE INDEX TblFmncMSession_start ON TblFmncMSession (start);

CREATE TABLE TblFmncMStep(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMActivity BIGINT,
	rlvIxVTbl INT,
	rlvUref BIGINT,
	tplRefFmncMStep BIGINT,
	ixWFilecfg INT,
	Title VARCHAR(100),
	start INT,
	refFmncMPerson BIGINT
);
ALTER TABLE TblFmncMStep OWNER TO epsi;
CREATE INDEX TblFmncMStep_grp ON TblFmncMStep (grp);
CREATE INDEX TblFmncMStep_own ON TblFmncMStep (own);
CREATE INDEX TblFmncMStep_refFmncMActivity ON TblFmncMStep (refFmncMActivity);
CREATE INDEX TblFmncMStep_rlvIxVTbl ON TblFmncMStep (rlvIxVTbl);
CREATE INDEX TblFmncMStep_rlvUref ON TblFmncMStep (rlvUref);
CREATE INDEX TblFmncMStep_tplRefFmncMStep ON TblFmncMStep (tplRefFmncMStep);
CREATE INDEX TblFmncMStep_ixWFilecfg ON TblFmncMStep (ixWFilecfg);
CREATE INDEX TblFmncMStep_start ON TblFmncMStep (start);

CREATE TABLE TblFmncMStockitem(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refFmncMOrg BIGINT,
	refFmncMArticle BIGINT,
	refJQuantity BIGINT,
	Quantity VARCHAR(10),
	osrefFmncKStocklcn VARCHAR(50),
	Expdate INT,
	Comment TEXT
);
ALTER TABLE TblFmncMStockitem OWNER TO epsi;
CREATE INDEX TblFmncMStockitem_grp ON TblFmncMStockitem (grp);
CREATE INDEX TblFmncMStockitem_own ON TblFmncMStockitem (own);
CREATE INDEX TblFmncMStockitem_refFmncMOrg ON TblFmncMStockitem (refFmncMOrg);
CREATE INDEX TblFmncMStockitem_refFmncMArticle ON TblFmncMStockitem (refFmncMArticle);

CREATE TABLE TblFmncMTool(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	fabRefFmncMFab BIGINT,
	mnfRefFmncMOrg BIGINT,
	Title VARCHAR(50),
	refJUnitprice BIGINT,
	Unitprice DOUBLE PRECISION,
	Training VARCHAR(100),
	Comment TEXT
);
ALTER TABLE TblFmncMTool OWNER TO epsi;
CREATE INDEX TblFmncMTool_grp ON TblFmncMTool (grp);
CREATE INDEX TblFmncMTool_own ON TblFmncMTool (own);
CREATE INDEX TblFmncMTool_fabRefFmncMFab ON TblFmncMTool (fabRefFmncMFab);
CREATE INDEX TblFmncMTool_mnfRefFmncMOrg ON TblFmncMTool (mnfRefFmncMOrg);
CREATE INDEX TblFmncMTool_Title ON TblFmncMTool (Title);

CREATE TABLE TblFmncMTooltype(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	supRefFmncMTooltype BIGINT,
	supLvl SMALLINT,
	sref VARCHAR(50),
	Title VARCHAR(50)
);
ALTER TABLE TblFmncMTooltype OWNER TO epsi;
CREATE INDEX TblFmncMTooltype_grp ON TblFmncMTooltype (grp);
CREATE INDEX TblFmncMTooltype_own ON TblFmncMTooltype (own);
CREATE INDEX TblFmncMTooltype_supRefFmncMTooltype ON TblFmncMTooltype (supRefFmncMTooltype);
CREATE INDEX TblFmncMTooltype_supLvl ON TblFmncMTooltype (supLvl);
CREATE INDEX TblFmncMTooltype_sref ON TblFmncMTooltype (sref);
CREATE INDEX TblFmncMTooltype_Title ON TblFmncMTooltype (Title);

CREATE TABLE TblFmncMUser(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refFmncMUsergroup BIGINT,
	refFmncMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixFmncVLocale INT,
	ixFmncVUserlevel INT,
	Password VARCHAR(30)
);
ALTER TABLE TblFmncMUser OWNER TO epsi;
CREATE INDEX TblFmncMUser_grp ON TblFmncMUser (grp);
CREATE INDEX TblFmncMUser_own ON TblFmncMUser (own);
CREATE INDEX TblFmncMUser_refFmncMUsergroup ON TblFmncMUser (refFmncMUsergroup);
CREATE INDEX TblFmncMUser_refFmncMPerson ON TblFmncMUser (refFmncMPerson);
CREATE INDEX TblFmncMUser_sref ON TblFmncMUser (sref);
CREATE INDEX TblFmncMUser_ixVState ON TblFmncMUser (ixVState);

CREATE TABLE TblFmncMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblFmncMUsergroup OWNER TO epsi;
CREATE INDEX TblFmncMUsergroup_grp ON TblFmncMUsergroup (grp);
CREATE INDEX TblFmncMUsergroup_own ON TblFmncMUsergroup (own);
CREATE INDEX TblFmncMUsergroup_sref ON TblFmncMUsergroup (sref);

CREATE TABLE TblFmncRMArticleMOrg(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMArticle BIGINT,
	refFmncMOrg BIGINT,
	Itemno VARCHAR(30)
);
ALTER TABLE TblFmncRMArticleMOrg OWNER TO epsi;
CREATE INDEX TblFmncRMArticleMOrg_refFmncMArticle ON TblFmncRMArticleMOrg (refFmncMArticle);
CREATE INDEX TblFmncRMArticleMOrg_refFmncMOrg ON TblFmncRMArticleMOrg (refFmncMOrg);

CREATE TABLE TblFmncRMFabMRun(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFab BIGINT,
	refFmncMRun BIGINT
);
ALTER TABLE TblFmncRMFabMRun OWNER TO epsi;
CREATE INDEX TblFmncRMFabMRun_refFmncMFab ON TblFmncRMFabMRun (refFmncMFab);
CREATE INDEX TblFmncRMFabMRun_refFmncMRun ON TblFmncRMFabMRun (refFmncMRun);

CREATE TABLE TblFmncRMFabprojectMFabuser(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFabproject BIGINT,
	refFmncMFabuser BIGINT
);
ALTER TABLE TblFmncRMFabprojectMFabuser OWNER TO epsi;
CREATE INDEX TblFmncRMFabprojectMFabuser_refFmncMFabproject ON TblFmncRMFabprojectMFabuser (refFmncMFabproject);
CREATE INDEX TblFmncRMFabprojectMFabuser_refFmncMFabuser ON TblFmncRMFabprojectMFabuser (refFmncMFabuser);

CREATE TABLE TblFmncRMFabuserMTool(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFabuser BIGINT,
	refFmncMTool BIGINT,
	trnRefFmncMPerson BIGINT,
	srefKLvl VARCHAR(50)
);
ALTER TABLE TblFmncRMFabuserMTool OWNER TO epsi;
CREATE INDEX TblFmncRMFabuserMTool_refFmncMFabuser ON TblFmncRMFabuserMTool (refFmncMFabuser);
CREATE INDEX TblFmncRMFabuserMTool_refFmncMTool ON TblFmncRMFabuserMTool (refFmncMTool);

CREATE TABLE TblFmncRMFileMSample(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFile BIGINT,
	refFmncMSample BIGINT
);
ALTER TABLE TblFmncRMFileMSample OWNER TO epsi;
CREATE INDEX TblFmncRMFileMSample_refFmncMFile ON TblFmncRMFileMSample (refFmncMFile);
CREATE INDEX TblFmncRMFileMSample_refFmncMSample ON TblFmncRMFileMSample (refFmncMSample);

CREATE TABLE TblFmncRMFileMStep(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMFile BIGINT,
	refFmncMStep BIGINT,
	ixVDir INT
);
ALTER TABLE TblFmncRMFileMStep OWNER TO epsi;
CREATE INDEX TblFmncRMFileMStep_refFmncMFile ON TblFmncRMFileMStep (refFmncMFile);
CREATE INDEX TblFmncRMFileMStep_refFmncMStep ON TblFmncRMFileMStep (refFmncMStep);

CREATE TABLE TblFmncRMOrgMPerson(
	ref BIGSERIAL PRIMARY KEY,
	x1Startd INT,
	x1Stopd INT,
	refFmncMOrg BIGINT,
	refFmncMPerson BIGINT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblFmncRMOrgMPerson OWNER TO epsi;
CREATE INDEX TblFmncRMOrgMPerson_x1Startd ON TblFmncRMOrgMPerson (x1Startd);
CREATE INDEX TblFmncRMOrgMPerson_x1Stopd ON TblFmncRMOrgMPerson (x1Stopd);
CREATE INDEX TblFmncRMOrgMPerson_refFmncMOrg ON TblFmncRMOrgMPerson (refFmncMOrg);
CREATE INDEX TblFmncRMOrgMPerson_refFmncMPerson ON TblFmncRMOrgMPerson (refFmncMPerson);
CREATE INDEX TblFmncRMOrgMPerson_srefKFunction ON TblFmncRMOrgMPerson (srefKFunction);

CREATE TABLE TblFmncRMPersonMRun(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPerson BIGINT,
	refFmncMRun BIGINT
);
ALTER TABLE TblFmncRMPersonMRun OWNER TO epsi;
CREATE INDEX TblFmncRMPersonMRun_refFmncMPerson ON TblFmncRMPersonMRun (refFmncMPerson);
CREATE INDEX TblFmncRMPersonMRun_refFmncMRun ON TblFmncRMPersonMRun (refFmncMRun);

CREATE TABLE TblFmncRMRunMSample(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMRun BIGINT,
	refFmncMSample BIGINT
);
ALTER TABLE TblFmncRMRunMSample OWNER TO epsi;
CREATE INDEX TblFmncRMRunMSample_refFmncMRun ON TblFmncRMRunMSample (refFmncMRun);
CREATE INDEX TblFmncRMRunMSample_refFmncMSample ON TblFmncRMRunMSample (refFmncMSample);

CREATE TABLE TblFmncRMSampleMStep(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMSample BIGINT,
	refFmncMStep BIGINT
);
ALTER TABLE TblFmncRMSampleMStep OWNER TO epsi;
CREATE INDEX TblFmncRMSampleMStep_refFmncMSample ON TblFmncRMSampleMStep (refFmncMSample);
CREATE INDEX TblFmncRMSampleMStep_refFmncMStep ON TblFmncRMSampleMStep (refFmncMStep);

CREATE TABLE TblFmncRMToolMTooltype(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMTool BIGINT,
	refFmncMTooltype BIGINT,
	srefsFmncKToolchar VARCHAR(255),
	defSrefsFmncKSteppar VARCHAR(255),
	optSrefsFmncKSteppar VARCHAR(255)
);
ALTER TABLE TblFmncRMToolMTooltype OWNER TO epsi;
CREATE INDEX TblFmncRMToolMTooltype_refFmncMTool ON TblFmncRMToolMTooltype (refFmncMTool);
CREATE INDEX TblFmncRMToolMTooltype_refFmncMTooltype ON TblFmncRMToolMTooltype (refFmncMTooltype);

CREATE TABLE TblFmncRMUsergroupUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUsergroup BIGINT,
	unvIxFmncVMaintable INT,
	unvUref BIGINT,
	ixFmncVAccess INT
);
ALTER TABLE TblFmncRMUsergroupUniversal OWNER TO epsi;
CREATE INDEX TblFmncRMUsergroupUniversal_refFmncMUsergroup ON TblFmncRMUsergroupUniversal (refFmncMUsergroup);
CREATE INDEX TblFmncRMUsergroupUniversal_unvIxFmncVMaintable ON TblFmncRMUsergroupUniversal (unvIxFmncVMaintable);
CREATE INDEX TblFmncRMUsergroupUniversal_unvUref ON TblFmncRMUsergroupUniversal (unvUref);

CREATE TABLE TblFmncRMUserMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMUser BIGINT,
	refFmncMUsergroup BIGINT,
	ixFmncVUserlevel INT
);
ALTER TABLE TblFmncRMUserMUsergroup OWNER TO epsi;
CREATE INDEX TblFmncRMUserMUsergroup_refFmncMUser ON TblFmncRMUserMUsergroup (refFmncMUser);
CREATE INDEX TblFmncRMUserMUsergroup_refFmncMUsergroup ON TblFmncRMUserMUsergroup (refFmncMUsergroup);

CREATE TABLE TblFmncSvcRMOrgMTool(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMOrg BIGINT,
	refFmncMTool BIGINT
);
ALTER TABLE TblFmncSvcRMOrgMTool OWNER TO epsi;
CREATE INDEX TblFmncSvcRMOrgMTool_refFmncMOrg ON TblFmncSvcRMOrgMTool (refFmncMOrg);
CREATE INDEX TblFmncSvcRMOrgMTool_refFmncMTool ON TblFmncSvcRMOrgMTool (refFmncMTool);

CREATE TABLE TblFmncSvcTMPersonMTool(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMPerson BIGINT,
	refR BIGINT
);
ALTER TABLE TblFmncSvcTMPersonMTool OWNER TO epsi;
CREATE INDEX TblFmncSvcTMPersonMTool_refFmncMPerson ON TblFmncSvcTMPersonMTool (refFmncMPerson);
CREATE INDEX TblFmncSvcTMPersonMTool_refR ON TblFmncSvcTMPersonMTool (refR);

CREATE TABLE TblFmncTMFileMSample(
	ref BIGSERIAL PRIMARY KEY,
	refFmncMSample BIGINT,
	refR BIGINT
);
ALTER TABLE TblFmncTMFileMSample OWNER TO epsi;
CREATE INDEX TblFmncTMFileMSample_refFmncMSample ON TblFmncTMFileMSample (refFmncMSample);
CREATE INDEX TblFmncTMFileMSample_refR ON TblFmncTMFileMSample (refR);

CREATE TABLE TblFmncQAct1NStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQAct1NStep OWNER TO epsi;
CREATE INDEX TblFmncQAct1NStep_jref ON TblFmncQAct1NStep (jref);
CREATE INDEX TblFmncQAct1NStep_jnum ON TblFmncQAct1NStep (jnum);

CREATE TABLE TblFmncQActList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(100),
	runRefFmncMRun BIGINT
);
ALTER TABLE TblFmncQActList OWNER TO epsi;
CREATE INDEX TblFmncQActList_jref ON TblFmncQActList (jref);
CREATE INDEX TblFmncQActList_jnum ON TblFmncQActList (jnum);

CREATE TABLE TblFmncQAdrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Address1 VARCHAR(100),
	City VARCHAR(50),
	hkIxVTbl INT,
	hkUref BIGINT,
	srefKAdrtype VARCHAR(50),
	Zipcode VARCHAR(10),
	srefKCountry VARCHAR(50)
);
ALTER TABLE TblFmncQAdrList OWNER TO epsi;
CREATE INDEX TblFmncQAdrList_jref ON TblFmncQAdrList (jref);
CREATE INDEX TblFmncQAdrList_jnum ON TblFmncQAdrList (jnum);

CREATE TABLE TblFmncQArt1NSample(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQArt1NSample OWNER TO epsi;
CREATE INDEX TblFmncQArt1NSample_jref ON TblFmncQArt1NSample (jref);
CREATE INDEX TblFmncQArt1NSample_jnum ON TblFmncQArt1NSample (jnum);

CREATE TABLE TblFmncQArt1NStockitem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQArt1NStockitem OWNER TO epsi;
CREATE INDEX TblFmncQArt1NStockitem_jref ON TblFmncQArt1NStockitem (jref);
CREATE INDEX TblFmncQArt1NStockitem_jnum ON TblFmncQArt1NStockitem (jnum);

CREATE TABLE TblFmncQArtList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(100),
	refFmncMOrg BIGINT,
	refFmncMTool BIGINT,
	srefKType VARCHAR(50)
);
ALTER TABLE TblFmncQArtList OWNER TO epsi;
CREATE INDEX TblFmncQArtList_jref ON TblFmncQArtList (jref);
CREATE INDEX TblFmncQArtList_jnum ON TblFmncQArtList (jnum);

CREATE TABLE TblFmncQArtMNOrg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	Itemno VARCHAR(30)
);
ALTER TABLE TblFmncQArtMNOrg OWNER TO epsi;
CREATE INDEX TblFmncQArtMNOrg_jref ON TblFmncQArtMNOrg (jref);
CREATE INDEX TblFmncQArtMNOrg_jnum ON TblFmncQArtMNOrg (jnum);

CREATE TABLE TblFmncQArtRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQArtRef1NFile OWNER TO epsi;
CREATE INDEX TblFmncQArtRef1NFile_jref ON TblFmncQArtRef1NFile (jref);
CREATE INDEX TblFmncQArtRef1NFile_jnum ON TblFmncQArtRef1NFile (jnum);

CREATE TABLE TblFmncQBilAPos(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	bilNum INT,
	x1RefFmncMFabuser BIGINT,
	x2RefFmncMTool BIGINT,
	Quantity DOUBLE PRECISION,
	Article VARCHAR(255),
	Unitprice DOUBLE PRECISION,
	Price DOUBLE PRECISION
);
ALTER TABLE TblFmncQBilAPos OWNER TO epsi;
CREATE INDEX TblFmncQBilAPos_jref ON TblFmncQBilAPos (jref);
CREATE INDEX TblFmncQBilAPos_jnum ON TblFmncQBilAPos (jnum);

CREATE TABLE TblFmncQBilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Date INT,
	refFmncMFabproject BIGINT,
	refFmncMFile BIGINT,
	ixVState INT,
	Prdstart INT,
	Prdstop INT,
	Amount DOUBLE PRECISION
);
ALTER TABLE TblFmncQBilList OWNER TO epsi;
CREATE INDEX TblFmncQBilList_jref ON TblFmncQBilList (jref);
CREATE INDEX TblFmncQBilList_jnum ON TblFmncQBilList (jnum);

CREATE TABLE TblFmncQFab1NFabproject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQFab1NFabproject OWNER TO epsi;
CREATE INDEX TblFmncQFab1NFabproject_jref ON TblFmncQFab1NFabproject (jref);
CREATE INDEX TblFmncQFab1NFabproject_jnum ON TblFmncQFab1NFabproject (jnum);

CREATE TABLE TblFmncQFab1NFabuser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQFab1NFabuser OWNER TO epsi;
CREATE INDEX TblFmncQFab1NFabuser_jref ON TblFmncQFab1NFabuser (jref);
CREATE INDEX TblFmncQFab1NFabuser_jnum ON TblFmncQFab1NFabuser (jnum);

CREATE TABLE TblFmncQFabFab1NTool(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQFabFab1NTool OWNER TO epsi;
CREATE INDEX TblFmncQFabFab1NTool_jref ON TblFmncQFabFab1NTool (jref);
CREATE INDEX TblFmncQFabFab1NTool_jnum ON TblFmncQFabFab1NTool (jnum);

CREATE TABLE TblFmncQFabList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refFmncMOrg BIGINT
);
ALTER TABLE TblFmncQFabList OWNER TO epsi;
CREATE INDEX TblFmncQFabList_jref ON TblFmncQFabList (jref);
CREATE INDEX TblFmncQFabList_jnum ON TblFmncQFabList (jnum);

CREATE TABLE TblFmncQFabMNRun(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQFabMNRun OWNER TO epsi;
CREATE INDEX TblFmncQFabMNRun_jref ON TblFmncQFabMNRun (jref);
CREATE INDEX TblFmncQFabMNRun_jnum ON TblFmncQFabMNRun (jnum);

CREATE TABLE TblFmncQFilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size SMALLINT
);
ALTER TABLE TblFmncQFilList OWNER TO epsi;
CREATE INDEX TblFmncQFilList_jref ON TblFmncQFilList (jref);
CREATE INDEX TblFmncQFilList_jnum ON TblFmncQFilList (jnum);

CREATE TABLE TblFmncQFilMNSample(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQFilMNSample OWNER TO epsi;
CREATE INDEX TblFmncQFilMNSample_jref ON TblFmncQFilMNSample (jref);
CREATE INDEX TblFmncQFilMNSample_jnum ON TblFmncQFilMNSample (jnum);

CREATE TABLE TblFmncQFilMNStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixVDir INT
);
ALTER TABLE TblFmncQFilMNStep OWNER TO epsi;
CREATE INDEX TblFmncQFilMNStep_jref ON TblFmncQFilMNStep (jref);
CREATE INDEX TblFmncQFilMNStep_jnum ON TblFmncQFilMNStep (jnum);

CREATE TABLE TblFmncQFpj1NBill(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQFpj1NBill OWNER TO epsi;
CREATE INDEX TblFmncQFpj1NBill_jref ON TblFmncQFpj1NBill (jref);
CREATE INDEX TblFmncQFpj1NBill_jnum ON TblFmncQFpj1NBill (jnum);

CREATE TABLE TblFmncQFpjList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(100),
	refFmncMFab BIGINT,
	bioRefFmncMOrg BIGINT,
	ixVState INT
);
ALTER TABLE TblFmncQFpjList OWNER TO epsi;
CREATE INDEX TblFmncQFpjList_jref ON TblFmncQFpjList (jref);
CREATE INDEX TblFmncQFpjList_jnum ON TblFmncQFpjList (jnum);

CREATE TABLE TblFmncQFpjMNFabuser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQFpjMNFabuser OWNER TO epsi;
CREATE INDEX TblFmncQFpjMNFabuser_jref ON TblFmncQFpjMNFabuser (jref);
CREATE INDEX TblFmncQFpjMNFabuser_jnum ON TblFmncQFpjMNFabuser (jnum);

CREATE TABLE TblFmncQFusList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refFmncMPerson BIGINT,
	sref VARCHAR(50),
	refFmncMFab BIGINT,
	refFmncMFabproject BIGINT,
	ixVState INT
);
ALTER TABLE TblFmncQFusList OWNER TO epsi;
CREATE INDEX TblFmncQFusList_jref ON TblFmncQFusList (jref);
CREATE INDEX TblFmncQFusList_jnum ON TblFmncQFusList (jnum);

CREATE TABLE TblFmncQFusMNFabproject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQFusMNFabproject OWNER TO epsi;
CREATE INDEX TblFmncQFusMNFabproject_jref ON TblFmncQFusMNFabproject (jref);
CREATE INDEX TblFmncQFusMNFabproject_jnum ON TblFmncQFusMNFabproject (jnum);

CREATE TABLE TblFmncQFusMNTool(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	trnRefFmncMPerson BIGINT,
	srefKLvl VARCHAR(50)
);
ALTER TABLE TblFmncQFusMNTool OWNER TO epsi;
CREATE INDEX TblFmncQFusMNTool_jref ON TblFmncQFusMNTool (jref);
CREATE INDEX TblFmncQFusMNTool_jnum ON TblFmncQFusMNTool (jnum);

CREATE TABLE TblFmncQOrg1NArticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrg1NArticle OWNER TO epsi;
CREATE INDEX TblFmncQOrg1NArticle_jref ON TblFmncQOrg1NArticle (jref);
CREATE INDEX TblFmncQOrg1NArticle_jnum ON TblFmncQOrg1NArticle (jnum);

CREATE TABLE TblFmncQOrg1NStockitem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrg1NStockitem OWNER TO epsi;
CREATE INDEX TblFmncQOrg1NStockitem_jref ON TblFmncQOrg1NStockitem (jref);
CREATE INDEX TblFmncQOrg1NStockitem_jnum ON TblFmncQOrg1NStockitem (jnum);

CREATE TABLE TblFmncQOrgADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblFmncQOrgADetail OWNER TO epsi;
CREATE INDEX TblFmncQOrgADetail_jref ON TblFmncQOrgADetail (jref);
CREATE INDEX TblFmncQOrgADetail_jnum ON TblFmncQOrgADetail (jnum);

CREATE TABLE TblFmncQOrgBio1NFabproject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgBio1NFabproject OWNER TO epsi;
CREATE INDEX TblFmncQOrgBio1NFabproject_jref ON TblFmncQOrgBio1NFabproject (jref);
CREATE INDEX TblFmncQOrgBio1NFabproject_jnum ON TblFmncQOrgBio1NFabproject (jnum);

CREATE TABLE TblFmncQOrgHk1NAddress(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgHk1NAddress OWNER TO epsi;
CREATE INDEX TblFmncQOrgHk1NAddress_jref ON TblFmncQOrgHk1NAddress (jref);
CREATE INDEX TblFmncQOrgHk1NAddress_jnum ON TblFmncQOrgHk1NAddress (jnum);

CREATE TABLE TblFmncQOrgKStocklcn(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQOrgKStocklcn OWNER TO epsi;
CREATE INDEX TblFmncQOrgKStocklcn_jref ON TblFmncQOrgKStocklcn (jref);
CREATE INDEX TblFmncQOrgKStocklcn_jnum ON TblFmncQOrgKStocklcn (jnum);

CREATE TABLE TblFmncQOrgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	ixWDerivate INT,
	refFmncMAddress BIGINT,
	supRefFmncMOrg BIGINT,
	Tel VARCHAR(255),
	Eml VARCHAR(255)
);
ALTER TABLE TblFmncQOrgList OWNER TO epsi;
CREATE INDEX TblFmncQOrgList_jref ON TblFmncQOrgList (jref);
CREATE INDEX TblFmncQOrgList_jnum ON TblFmncQOrgList (jnum);

CREATE TABLE TblFmncQOrgMNArticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	Itemno VARCHAR(30)
);
ALTER TABLE TblFmncQOrgMNArticle OWNER TO epsi;
CREATE INDEX TblFmncQOrgMNArticle_jref ON TblFmncQOrgMNArticle (jref);
CREATE INDEX TblFmncQOrgMNArticle_jnum ON TblFmncQOrgMNArticle (jnum);

CREATE TABLE TblFmncQOrgMnf1NTool(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgMnf1NTool OWNER TO epsi;
CREATE INDEX TblFmncQOrgMnf1NTool_jref ON TblFmncQOrgMnf1NTool (jref);
CREATE INDEX TblFmncQOrgMnf1NTool_jnum ON TblFmncQOrgMnf1NTool (jnum);

CREATE TABLE TblFmncQOrgMNPerson(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblFmncQOrgMNPerson OWNER TO epsi;
CREATE INDEX TblFmncQOrgMNPerson_jref ON TblFmncQOrgMNPerson (jref);
CREATE INDEX TblFmncQOrgMNPerson_jnum ON TblFmncQOrgMNPerson (jnum);

CREATE TABLE TblFmncQOrgPco1NPurchorder(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgPco1NPurchorder OWNER TO epsi;
CREATE INDEX TblFmncQOrgPco1NPurchorder_jref ON TblFmncQOrgPco1NPurchorder (jref);
CREATE INDEX TblFmncQOrgPco1NPurchorder_jnum ON TblFmncQOrgPco1NPurchorder (jnum);

CREATE TABLE TblFmncQOrgSpl1NPurchorder(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgSpl1NPurchorder OWNER TO epsi;
CREATE INDEX TblFmncQOrgSpl1NPurchorder_jref ON TblFmncQOrgSpl1NPurchorder (jref);
CREATE INDEX TblFmncQOrgSpl1NPurchorder_jnum ON TblFmncQOrgSpl1NPurchorder (jnum);

CREATE TABLE TblFmncQOrgSup1NOrg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgSup1NOrg OWNER TO epsi;
CREATE INDEX TblFmncQOrgSup1NOrg_jref ON TblFmncQOrgSup1NOrg (jref);
CREATE INDEX TblFmncQOrgSup1NOrg_jnum ON TblFmncQOrgSup1NOrg (jnum);

CREATE TABLE TblFmncQOrgSvcMNTool(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQOrgSvcMNTool OWNER TO epsi;
CREATE INDEX TblFmncQOrgSvcMNTool_jref ON TblFmncQOrgSvcMNTool (jref);
CREATE INDEX TblFmncQOrgSvcMNTool_jnum ON TblFmncQOrgSvcMNTool (jnum);

CREATE TABLE TblFmncQPcoAPos(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	pcoNum INT,
	Quantity DOUBLE PRECISION,
	Itemno VARCHAR(30),
	refFmncMArticle BIGINT,
	Unitprice DOUBLE PRECISION,
	Price DOUBLE PRECISION
);
ALTER TABLE TblFmncQPcoAPos OWNER TO epsi;
CREATE INDEX TblFmncQPcoAPos_jref ON TblFmncQPcoAPos (jref);
CREATE INDEX TblFmncQPcoAPos_jnum ON TblFmncQPcoAPos (jnum);

CREATE TABLE TblFmncQPcoList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Date INT,
	pcoRefFmncMOrg BIGINT,
	splRefFmncMOrg BIGINT,
	refFmncMFile BIGINT,
	ixVState INT,
	Amount DOUBLE PRECISION
);
ALTER TABLE TblFmncQPcoList OWNER TO epsi;
CREATE INDEX TblFmncQPcoList_jref ON TblFmncQPcoList (jref);
CREATE INDEX TblFmncQPcoList_jnum ON TblFmncQPcoList (jnum);

CREATE TABLE TblFmncQPreselect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQPreselect OWNER TO epsi;
CREATE INDEX TblFmncQPreselect_jref ON TblFmncQPreselect (jref);

CREATE TABLE TblFmncQPrj1NRun(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQPrj1NRun OWNER TO epsi;
CREATE INDEX TblFmncQPrj1NRun_jref ON TblFmncQPrj1NRun (jref);
CREATE INDEX TblFmncQPrj1NRun_jnum ON TblFmncQPrj1NRun (jnum);

CREATE TABLE TblFmncQPrjList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(100),
	ixVState INT
);
ALTER TABLE TblFmncQPrjList OWNER TO epsi;
CREATE INDEX TblFmncQPrjList_jref ON TblFmncQPrjList (jref);
CREATE INDEX TblFmncQPrjList_jnum ON TblFmncQPrjList (jnum);

CREATE TABLE TblFmncQPrsADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblFmncQPrsADetail OWNER TO epsi;
CREATE INDEX TblFmncQPrsADetail_jref ON TblFmncQPrsADetail (jref);
CREATE INDEX TblFmncQPrsADetail_jnum ON TblFmncQPrsADetail (jnum);

CREATE TABLE TblFmncQPrsHk1NAddress(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQPrsHk1NAddress OWNER TO epsi;
CREATE INDEX TblFmncQPrsHk1NAddress_jref ON TblFmncQPrsHk1NAddress (jref);
CREATE INDEX TblFmncQPrsHk1NAddress_jnum ON TblFmncQPrsHk1NAddress (jnum);

CREATE TABLE TblFmncQPrsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	grp BIGINT,
	own BIGINT,
	refFmncMOrg BIGINT,
	refFmncMAddress BIGINT,
	ixVSex INT,
	Tel VARCHAR(255),
	Eml VARCHAR(255)
);
ALTER TABLE TblFmncQPrsList OWNER TO epsi;
CREATE INDEX TblFmncQPrsList_jref ON TblFmncQPrsList (jref);
CREATE INDEX TblFmncQPrsList_jnum ON TblFmncQPrsList (jnum);

CREATE TABLE TblFmncQPrsMNOrg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblFmncQPrsMNOrg OWNER TO epsi;
CREATE INDEX TblFmncQPrsMNOrg_jref ON TblFmncQPrsMNOrg (jref);
CREATE INDEX TblFmncQPrsMNOrg_jnum ON TblFmncQPrsMNOrg (jnum);

CREATE TABLE TblFmncQPrsMNRun(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQPrsMNRun OWNER TO epsi;
CREATE INDEX TblFmncQPrsMNRun_jref ON TblFmncQPrsMNRun (jref);
CREATE INDEX TblFmncQPrsMNRun_jnum ON TblFmncQPrsMNRun (jnum);

CREATE TABLE TblFmncQRunList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(100),
	refFmncMProject BIGINT,
	ixVState INT
);
ALTER TABLE TblFmncQRunList OWNER TO epsi;
CREATE INDEX TblFmncQRunList_jref ON TblFmncQRunList (jref);
CREATE INDEX TblFmncQRunList_jnum ON TblFmncQRunList (jnum);

CREATE TABLE TblFmncQRunMNFab(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQRunMNFab OWNER TO epsi;
CREATE INDEX TblFmncQRunMNFab_jref ON TblFmncQRunMNFab (jref);
CREATE INDEX TblFmncQRunMNFab_jnum ON TblFmncQRunMNFab (jnum);

CREATE TABLE TblFmncQRunMNPerson(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQRunMNPerson OWNER TO epsi;
CREATE INDEX TblFmncQRunMNPerson_jref ON TblFmncQRunMNPerson (jref);
CREATE INDEX TblFmncQRunMNPerson_jnum ON TblFmncQRunMNPerson (jnum);

CREATE TABLE TblFmncQRunMNSample(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQRunMNSample OWNER TO epsi;
CREATE INDEX TblFmncQRunMNSample_jref ON TblFmncQRunMNSample (jref);
CREATE INDEX TblFmncQRunMNSample_jnum ON TblFmncQRunMNSample (jnum);

CREATE TABLE TblFmncQRunRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQRunRef1NFile OWNER TO epsi;
CREATE INDEX TblFmncQRunRef1NFile_jref ON TblFmncQRunRef1NFile (jref);
CREATE INDEX TblFmncQRunRef1NFile_jnum ON TblFmncQRunRef1NFile (jnum);

CREATE TABLE TblFmncQRunRun1NActivity(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	runNum INT
);
ALTER TABLE TblFmncQRunRun1NActivity OWNER TO epsi;
CREATE INDEX TblFmncQRunRun1NActivity_jref ON TblFmncQRunRun1NActivity (jref);
CREATE INDEX TblFmncQRunRun1NActivity_jnum ON TblFmncQRunRun1NActivity (jnum);

CREATE TABLE TblFmncQSelect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
ALTER TABLE TblFmncQSelect OWNER TO epsi;
CREATE INDEX TblFmncQSelect_jref ON TblFmncQSelect (jref);
CREATE INDEX TblFmncQSelect_ix ON TblFmncQSelect (ix);

CREATE TABLE TblFmncQSepAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1OsrefFmncKSteppar VARCHAR(50),
	x2IxVTbl INT,
	x2Uref BIGINT,
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQSepAPar OWNER TO epsi;
CREATE INDEX TblFmncQSepAPar_jref ON TblFmncQSepAPar (jref);
CREATE INDEX TblFmncQSepAPar_jnum ON TblFmncQSepAPar (jnum);

CREATE TABLE TblFmncQSepList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(100),
	refFmncMActivity BIGINT,
	rlvIxVTbl INT,
	rlvUref BIGINT,
	tplRefFmncMStep BIGINT,
	start INT
);
ALTER TABLE TblFmncQSepList OWNER TO epsi;
CREATE INDEX TblFmncQSepList_jref ON TblFmncQSepList (jref);
CREATE INDEX TblFmncQSepList_jnum ON TblFmncQSepList (jnum);

CREATE TABLE TblFmncQSepMNFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixVDir INT
);
ALTER TABLE TblFmncQSepMNFile OWNER TO epsi;
CREATE INDEX TblFmncQSepMNFile_jref ON TblFmncQSepMNFile (jref);
CREATE INDEX TblFmncQSepMNFile_jnum ON TblFmncQSepMNFile (jnum);

CREATE TABLE TblFmncQSepMNSample(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQSepMNSample OWNER TO epsi;
CREATE INDEX TblFmncQSepMNSample_jref ON TblFmncQSepMNSample (jref);
CREATE INDEX TblFmncQSepMNSample_jnum ON TblFmncQSepMNSample (jnum);

CREATE TABLE TblFmncQSepRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQSepRef1NFile OWNER TO epsi;
CREATE INDEX TblFmncQSepRef1NFile_jref ON TblFmncQSepRef1NFile (jref);
CREATE INDEX TblFmncQSepRef1NFile_jnum ON TblFmncQSepRef1NFile (jnum);

CREATE TABLE TblFmncQSkiList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refFmncMOrg BIGINT,
	refFmncMArticle BIGINT,
	Quantity VARCHAR(10),
	osrefFmncKStocklcn VARCHAR(50),
	Expdate INT
);
ALTER TABLE TblFmncQSkiList OWNER TO epsi;
CREATE INDEX TblFmncQSkiList_jref ON TblFmncQSkiList (jref);
CREATE INDEX TblFmncQSkiList_jnum ON TblFmncQSkiList (jnum);

CREATE TABLE TblFmncQSmpAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKKey VARCHAR(50),
	osrefKVal VARCHAR(50)
);
ALTER TABLE TblFmncQSmpAPar OWNER TO epsi;
CREATE INDEX TblFmncQSmpAPar_jref ON TblFmncQSmpAPar (jref);
CREATE INDEX TblFmncQSmpAPar_jnum ON TblFmncQSmpAPar (jnum);

CREATE TABLE TblFmncQSmpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	supRefFmncMSample BIGINT,
	refFmncMArticle BIGINT,
	Material VARCHAR(100),
	ixVState INT
);
ALTER TABLE TblFmncQSmpList OWNER TO epsi;
CREATE INDEX TblFmncQSmpList_jref ON TblFmncQSmpList (jref);
CREATE INDEX TblFmncQSmpList_jnum ON TblFmncQSmpList (jnum);

CREATE TABLE TblFmncQSmpMNFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQSmpMNFile OWNER TO epsi;
CREATE INDEX TblFmncQSmpMNFile_jref ON TblFmncQSmpMNFile (jref);
CREATE INDEX TblFmncQSmpMNFile_jnum ON TblFmncQSmpMNFile (jnum);

CREATE TABLE TblFmncQSmpMNRun(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQSmpMNRun OWNER TO epsi;
CREATE INDEX TblFmncQSmpMNRun_jref ON TblFmncQSmpMNRun (jref);
CREATE INDEX TblFmncQSmpMNRun_jnum ON TblFmncQSmpMNRun (jnum);

CREATE TABLE TblFmncQSmpMNStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQSmpMNStep OWNER TO epsi;
CREATE INDEX TblFmncQSmpMNStep_jref ON TblFmncQSmpMNStep (jref);
CREATE INDEX TblFmncQSmpMNStep_jnum ON TblFmncQSmpMNStep (jnum);

CREATE TABLE TblFmncQSmpRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQSmpRef1NFile OWNER TO epsi;
CREATE INDEX TblFmncQSmpRef1NFile_jref ON TblFmncQSmpRef1NFile (jref);
CREATE INDEX TblFmncQSmpRef1NFile_jnum ON TblFmncQSmpRef1NFile (jnum);

CREATE TABLE TblFmncQSmpSup1NSample(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQSmpSup1NSample OWNER TO epsi;
CREATE INDEX TblFmncQSmpSup1NSample_jref ON TblFmncQSmpSup1NSample (jref);
CREATE INDEX TblFmncQSmpSup1NSample_jnum ON TblFmncQSmpSup1NSample (jnum);

CREATE TABLE TblFmncQStpAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1OsrefFmncKSteppar VARCHAR(50),
	x2IxVTbl INT,
	x2Uref BIGINT,
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQStpAPar OWNER TO epsi;
CREATE INDEX TblFmncQStpAPar_jref ON TblFmncQStpAPar (jref);
CREATE INDEX TblFmncQStpAPar_jnum ON TblFmncQStpAPar (jnum);

CREATE TABLE TblFmncQStpKSteppar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQStpKSteppar OWNER TO epsi;
CREATE INDEX TblFmncQStpKSteppar_jref ON TblFmncQStpKSteppar (jref);
CREATE INDEX TblFmncQStpKSteppar_jnum ON TblFmncQStpKSteppar (jnum);

CREATE TABLE TblFmncQStpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(100),
	refFmncMActivity BIGINT,
	rlvIxVTbl INT,
	rlvUref BIGINT,
	tplRefFmncMStep BIGINT,
	start INT
);
ALTER TABLE TblFmncQStpList OWNER TO epsi;
CREATE INDEX TblFmncQStpList_jref ON TblFmncQStpList (jref);
CREATE INDEX TblFmncQStpList_jnum ON TblFmncQStpList (jnum);

CREATE TABLE TblFmncQStpMNFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixVDir INT
);
ALTER TABLE TblFmncQStpMNFile OWNER TO epsi;
CREATE INDEX TblFmncQStpMNFile_jref ON TblFmncQStpMNFile (jref);
CREATE INDEX TblFmncQStpMNFile_jnum ON TblFmncQStpMNFile (jnum);

CREATE TABLE TblFmncQStpRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQStpRef1NFile OWNER TO epsi;
CREATE INDEX TblFmncQStpRef1NFile_jref ON TblFmncQStpRef1NFile (jref);
CREATE INDEX TblFmncQStpRef1NFile_jnum ON TblFmncQStpRef1NFile (jnum);

CREATE TABLE TblFmncQStpTpl1NStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQStpTpl1NStep OWNER TO epsi;
CREATE INDEX TblFmncQStpTpl1NStep_jref ON TblFmncQStpTpl1NStep (jref);
CREATE INDEX TblFmncQStpTpl1NStep_jnum ON TblFmncQStpTpl1NStep (jnum);

CREATE TABLE TblFmncQTol1NArticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQTol1NArticle OWNER TO epsi;
CREATE INDEX TblFmncQTol1NArticle_jref ON TblFmncQTol1NArticle (jref);
CREATE INDEX TblFmncQTol1NArticle_jnum ON TblFmncQTol1NArticle (jnum);

CREATE TABLE TblFmncQTolAAvl(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1Startd INT,
	x2IxVWkday INT,
	x3Startt INT,
	x3Stopt INT,
	srefKAvltype VARCHAR(50)
);
ALTER TABLE TblFmncQTolAAvl OWNER TO epsi;
CREATE INDEX TblFmncQTolAAvl_jref ON TblFmncQTolAAvl (jref);
CREATE INDEX TblFmncQTolAAvl_jnum ON TblFmncQTolAAvl (jnum);

CREATE TABLE TblFmncQTolAChar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1OsrefFmncKToolchar VARCHAR(50),
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQTolAChar OWNER TO epsi;
CREATE INDEX TblFmncQTolAChar_jref ON TblFmncQTolAChar (jref);
CREATE INDEX TblFmncQTolAChar_jnum ON TblFmncQTolAChar (jnum);

CREATE TABLE TblFmncQTolARes(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefFmncMFabuser BIGINT,
	startd INT,
	startt INT,
	stopt INT,
	srefKRestype VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblFmncQTolARes OWNER TO epsi;
CREATE INDEX TblFmncQTolARes_jref ON TblFmncQTolARes (jref);
CREATE INDEX TblFmncQTolARes_jnum ON TblFmncQTolARes (jnum);

CREATE TABLE TblFmncQTolAUtil(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefFmncMFabproject BIGINT,
	x2RefFmncMFabuser BIGINT,
	startd INT,
	startt INT,
	stopt INT,
	Unitprice DOUBLE PRECISION,
	Comment TEXT
);
ALTER TABLE TblFmncQTolAUtil OWNER TO epsi;
CREATE INDEX TblFmncQTolAUtil_jref ON TblFmncQTolAUtil (jref);
CREATE INDEX TblFmncQTolAUtil_jnum ON TblFmncQTolAUtil (jnum);

CREATE TABLE TblFmncQTolKSteppar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQTolKSteppar OWNER TO epsi;
CREATE INDEX TblFmncQTolKSteppar_jref ON TblFmncQTolKSteppar (jref);
CREATE INDEX TblFmncQTolKSteppar_jnum ON TblFmncQTolKSteppar (jnum);

CREATE TABLE TblFmncQTolKToolchar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQTolKToolchar OWNER TO epsi;
CREATE INDEX TblFmncQTolKToolchar_jref ON TblFmncQTolKToolchar (jref);
CREATE INDEX TblFmncQTolKToolchar_jnum ON TblFmncQTolKToolchar (jnum);

CREATE TABLE TblFmncQTolList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	fabRefFmncMFab BIGINT,
	mnfRefFmncMOrg BIGINT,
	Unitprice DOUBLE PRECISION,
	Training VARCHAR(100)
);
ALTER TABLE TblFmncQTolList OWNER TO epsi;
CREATE INDEX TblFmncQTolList_jref ON TblFmncQTolList (jref);
CREATE INDEX TblFmncQTolList_jnum ON TblFmncQTolList (jnum);

CREATE TABLE TblFmncQTolMNFabuser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	trnRefFmncMPerson BIGINT,
	srefKLvl VARCHAR(50)
);
ALTER TABLE TblFmncQTolMNFabuser OWNER TO epsi;
CREATE INDEX TblFmncQTolMNFabuser_jref ON TblFmncQTolMNFabuser (jref);
CREATE INDEX TblFmncQTolMNFabuser_jnum ON TblFmncQTolMNFabuser (jnum);

CREATE TABLE TblFmncQTolMNTooltype(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	srefsFmncKToolchar VARCHAR(255),
	defSrefsFmncKSteppar VARCHAR(255),
	optSrefsFmncKSteppar VARCHAR(255)
);
ALTER TABLE TblFmncQTolMNTooltype OWNER TO epsi;
CREATE INDEX TblFmncQTolMNTooltype_jref ON TblFmncQTolMNTooltype (jref);
CREATE INDEX TblFmncQTolMNTooltype_jnum ON TblFmncQTolMNTooltype (jnum);

CREATE TABLE TblFmncQTolRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQTolRef1NFile OWNER TO epsi;
CREATE INDEX TblFmncQTolRef1NFile_jref ON TblFmncQTolRef1NFile (jref);
CREATE INDEX TblFmncQTolRef1NFile_jnum ON TblFmncQTolRef1NFile (jnum);

CREATE TABLE TblFmncQTolRlv1NStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQTolRlv1NStep OWNER TO epsi;
CREATE INDEX TblFmncQTolRlv1NStep_jref ON TblFmncQTolRlv1NStep (jref);
CREATE INDEX TblFmncQTolRlv1NStep_jnum ON TblFmncQTolRlv1NStep (jnum);

CREATE TABLE TblFmncQTolSvcMNOrg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblFmncQTolSvcMNOrg OWNER TO epsi;
CREATE INDEX TblFmncQTolSvcMNOrg_jref ON TblFmncQTolSvcMNOrg (jref);
CREATE INDEX TblFmncQTolSvcMNOrg_jnum ON TblFmncQTolSvcMNOrg (jnum);

CREATE TABLE TblFmncQTtyKSteppar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQTtyKSteppar OWNER TO epsi;
CREATE INDEX TblFmncQTtyKSteppar_jref ON TblFmncQTtyKSteppar (jref);
CREATE INDEX TblFmncQTtyKSteppar_jnum ON TblFmncQTtyKSteppar (jnum);

CREATE TABLE TblFmncQTtyKToolchar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblFmncQTtyKToolchar OWNER TO epsi;
CREATE INDEX TblFmncQTtyKToolchar_jref ON TblFmncQTtyKToolchar (jref);
CREATE INDEX TblFmncQTtyKToolchar_jnum ON TblFmncQTtyKToolchar (jnum);

CREATE TABLE TblFmncQTtyList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	supRefFmncMTooltype BIGINT
);
ALTER TABLE TblFmncQTtyList OWNER TO epsi;
CREATE INDEX TblFmncQTtyList_jref ON TblFmncQTtyList (jref);
CREATE INDEX TblFmncQTtyList_jnum ON TblFmncQTtyList (jnum);

CREATE TABLE TblFmncQTtyMNTool(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	srefsFmncKToolchar VARCHAR(255),
	defSrefsFmncKSteppar VARCHAR(255),
	optSrefsFmncKSteppar VARCHAR(255)
);
ALTER TABLE TblFmncQTtyMNTool OWNER TO epsi;
CREATE INDEX TblFmncQTtyMNTool_jref ON TblFmncQTtyMNTool (jref);
CREATE INDEX TblFmncQTtyMNTool_jnum ON TblFmncQTtyMNTool (jnum);

CREATE TABLE TblFmncQTtyRlv1NStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQTtyRlv1NStep OWNER TO epsi;
CREATE INDEX TblFmncQTtyRlv1NStep_jref ON TblFmncQTtyRlv1NStep (jref);
CREATE INDEX TblFmncQTtyRlv1NStep_jnum ON TblFmncQTtyRlv1NStep (jnum);

CREATE TABLE TblFmncQTtySup1NTooltype(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQTtySup1NTooltype OWNER TO epsi;
CREATE INDEX TblFmncQTtySup1NTooltype_jref ON TblFmncQTtySup1NTooltype (jref);
CREATE INDEX TblFmncQTtySup1NTooltype_jnum ON TblFmncQTtySup1NTooltype (jnum);

CREATE TABLE TblFmncQUsgAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxFmncVCard INT,
	ixFmncWUiaccess INT
);
ALTER TABLE TblFmncQUsgAAccess OWNER TO epsi;
CREATE INDEX TblFmncQUsgAAccess_jref ON TblFmncQUsgAAccess (jref);
CREATE INDEX TblFmncQUsgAAccess_jnum ON TblFmncQUsgAAccess (jnum);

CREATE TABLE TblFmncQUsgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblFmncQUsgList OWNER TO epsi;
CREATE INDEX TblFmncQUsgList_jref ON TblFmncQUsgList (jref);
CREATE INDEX TblFmncQUsgList_jnum ON TblFmncQUsgList (jnum);

CREATE TABLE TblFmncQUsgMNUser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixFmncVUserlevel INT
);
ALTER TABLE TblFmncQUsgMNUser OWNER TO epsi;
CREATE INDEX TblFmncQUsgMNUser_jref ON TblFmncQUsgMNUser (jref);
CREATE INDEX TblFmncQUsgMNUser_jnum ON TblFmncQUsgMNUser (jnum);

CREATE TABLE TblFmncQUsr1NSession(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblFmncQUsr1NSession OWNER TO epsi;
CREATE INDEX TblFmncQUsr1NSession_jref ON TblFmncQUsr1NSession (jref);
CREATE INDEX TblFmncQUsr1NSession_jnum ON TblFmncQUsr1NSession (jnum);

CREATE TABLE TblFmncQUsrAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxFmncVCard INT,
	ixFmncWUiaccess INT
);
ALTER TABLE TblFmncQUsrAAccess OWNER TO epsi;
CREATE INDEX TblFmncQUsrAAccess_jref ON TblFmncQUsrAAccess (jref);
CREATE INDEX TblFmncQUsrAAccess_jnum ON TblFmncQUsrAAccess (jnum);

CREATE TABLE TblFmncQUsrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refFmncMPerson BIGINT,
	sref VARCHAR(50),
	refFmncMUsergroup BIGINT,
	ixVState INT,
	ixFmncVLocale INT,
	ixFmncVUserlevel INT
);
ALTER TABLE TblFmncQUsrList OWNER TO epsi;
CREATE INDEX TblFmncQUsrList_jref ON TblFmncQUsrList (jref);
CREATE INDEX TblFmncQUsrList_jnum ON TblFmncQUsrList (jnum);

CREATE TABLE TblFmncQUsrMNUsergroup(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixFmncVUserlevel INT
);
ALTER TABLE TblFmncQUsrMNUsergroup OWNER TO epsi;
CREATE INDEX TblFmncQUsrMNUsergroup_jref ON TblFmncQUsrMNUsergroup (jref);
CREATE INDEX TblFmncQUsrMNUsergroup_jnum ON TblFmncQUsrMNUsergroup (jnum);

