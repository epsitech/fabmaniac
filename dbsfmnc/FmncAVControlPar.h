/**
  * \file FmncAVControlPar.h
  * database access for table TblFmncAVControlPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAVCONTROLPAR_H
#define FMNCAVCONTROLPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAVControlPar: record of TblFmncAVControlPar
  */
class FmncAVControlPar {

public:
	FmncAVControlPar(const ubigint ref = 0, const uint ixFmncVControl = 0, const ubigint x1RefFmncMUser = 0, const uint x2IxFmncVLocale = 0, const string Par = "", const string Val = "");

public:
	ubigint ref;
	uint ixFmncVControl;
	ubigint x1RefFmncMUser;
	uint x2IxFmncVLocale;
	string Par;
	string Val;

public:
	bool operator==(const FmncAVControlPar& comp);
	bool operator!=(const FmncAVControlPar& comp);
};

/**
  * ListFmncAVControlPar: recordset of TblFmncAVControlPar
  */
class ListFmncAVControlPar {

public:
	ListFmncAVControlPar();
	ListFmncAVControlPar(const ListFmncAVControlPar& src);
	~ListFmncAVControlPar();

	void clear();
	unsigned int size() const;
	void append(FmncAVControlPar* rec);

	FmncAVControlPar* operator[](const uint ix);
	ListFmncAVControlPar& operator=(const ListFmncAVControlPar& src);
	bool operator==(const ListFmncAVControlPar& comp);
	bool operator!=(const ListFmncAVControlPar& comp);

public:
	vector<FmncAVControlPar*> nodes;
};

/**
  * TblFmncAVControlPar: C++ wrapper for table TblFmncAVControlPar
  */
class TblFmncAVControlPar {

public:
	TblFmncAVControlPar();
	virtual ~TblFmncAVControlPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAVControlPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVControlPar& rst);

	virtual void insertRec(FmncAVControlPar* rec);
	ubigint insertNewRec(FmncAVControlPar** rec = NULL, const uint ixFmncVControl = 0, const ubigint x1RefFmncMUser = 0, const uint x2IxFmncVLocale = 0, const string Par = "", const string Val = "");
	ubigint appendNewRecToRst(ListFmncAVControlPar& rst, FmncAVControlPar** rec = NULL, const uint ixFmncVControl = 0, const ubigint x1RefFmncMUser = 0, const uint x2IxFmncVLocale = 0, const string Par = "", const string Val = "");
	virtual void insertRst(ListFmncAVControlPar& rst, bool transact = false);
	virtual void updateRec(FmncAVControlPar* rec);
	virtual void updateRst(ListFmncAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(uint ixFmncVControl, ubigint x1RefFmncMUser, string Par, ubigint& ref);
	virtual bool loadValByCtlUsrPar(uint ixFmncVControl, ubigint x1RefFmncMUser, string Par, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAVControlPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAVControlPar: C++ wrapper for table TblFmncAVControlPar (MySQL database)
  */
class MyTblFmncAVControlPar : public TblFmncAVControlPar, public MyTable {

public:
	MyTblFmncAVControlPar();
	~MyTblFmncAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVControlPar& rst);

	void insertRec(FmncAVControlPar* rec);
	void insertRst(ListFmncAVControlPar& rst, bool transact = false);
	void updateRec(FmncAVControlPar* rec);
	void updateRst(ListFmncAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAVControlPar** rec);
	bool loadRefByCtlUsrPar(uint ixFmncVControl, ubigint x1RefFmncMUser, string Par, ubigint& ref);
	bool loadValByCtlUsrPar(uint ixFmncVControl, ubigint x1RefFmncMUser, string Par, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAVControlPar: C++ wrapper for table TblFmncAVControlPar (PgSQL database)
  */
class PgTblFmncAVControlPar : public TblFmncAVControlPar, public PgTable {

public:
	PgTblFmncAVControlPar();
	~PgTblFmncAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAVControlPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAVControlPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAVControlPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVControlPar& rst);

	void insertRec(FmncAVControlPar* rec);
	void insertRst(ListFmncAVControlPar& rst, bool transact = false);
	void updateRec(FmncAVControlPar* rec);
	void updateRst(ListFmncAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAVControlPar** rec);
	bool loadRefByCtlUsrPar(uint ixFmncVControl, ubigint x1RefFmncMUser, string Par, ubigint& ref);
	bool loadValByCtlUsrPar(uint ixFmncVControl, ubigint x1RefFmncMUser, string Par, string& val);
};
// IP pgTbl --- END

#endif

