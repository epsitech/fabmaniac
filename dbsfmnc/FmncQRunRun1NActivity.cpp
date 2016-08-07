/**
  * \file FmncQRunRun1NActivity.cpp
  * Dbs and XML wrapper for table TblFmncQRunRun1NActivity (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQRunRun1NActivity.h"

/******************************************************************************
 class FmncQRunRun1NActivity
 ******************************************************************************/

FmncQRunRun1NActivity::FmncQRunRun1NActivity(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint runNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->runNum = runNum;
};

void FmncQRunRun1NActivity::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQRunRun1NActivity";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQRunRun1NActivity
 ******************************************************************************/

ListFmncQRunRun1NActivity::ListFmncQRunRun1NActivity() {
};

ListFmncQRunRun1NActivity::ListFmncQRunRun1NActivity(
			const ListFmncQRunRun1NActivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunRun1NActivity(*(src.nodes[i]));
};

ListFmncQRunRun1NActivity::~ListFmncQRunRun1NActivity() {
	clear();
};

void ListFmncQRunRun1NActivity::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQRunRun1NActivity::size() const {
	return(nodes.size());
};

void ListFmncQRunRun1NActivity::append(
			FmncQRunRun1NActivity* rec
		) {
	nodes.push_back(rec);
};

ListFmncQRunRun1NActivity& ListFmncQRunRun1NActivity::operator=(
			const ListFmncQRunRun1NActivity& src
		) {
	FmncQRunRun1NActivity* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQRunRun1NActivity(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQRunRun1NActivity::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQRunRun1NActivity";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQRunRun1NActivity
 ******************************************************************************/

TblFmncQRunRun1NActivity::TblFmncQRunRun1NActivity() {
};

TblFmncQRunRun1NActivity::~TblFmncQRunRun1NActivity() {
};

bool TblFmncQRunRun1NActivity::loadRecBySQL(
			const string& sqlstr
			, FmncQRunRun1NActivity** rec
		) {
	return false;
};

ubigint TblFmncQRunRun1NActivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	return 0;
};

void TblFmncQRunRun1NActivity::insertRec(
			FmncQRunRun1NActivity* rec
		) {
};

ubigint TblFmncQRunRun1NActivity::insertNewRec(
			FmncQRunRun1NActivity** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint runNum
		) {
	ubigint retval = 0;
	FmncQRunRun1NActivity* _rec = NULL;

	_rec = new FmncQRunRun1NActivity(0, jref, jnum, ref, stubRef, runNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQRunRun1NActivity::appendNewRecToRst(
			ListFmncQRunRun1NActivity& rst
			, FmncQRunRun1NActivity** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint runNum
		) {
	ubigint retval = 0;
	FmncQRunRun1NActivity* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, runNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQRunRun1NActivity::insertRst(
			ListFmncQRunRun1NActivity& rst
		) {
};

void TblFmncQRunRun1NActivity::updateRec(
			FmncQRunRun1NActivity* rec
		) {
};

void TblFmncQRunRun1NActivity::updateRst(
			ListFmncQRunRun1NActivity& rst
		) {
};

void TblFmncQRunRun1NActivity::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQRunRun1NActivity::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQRunRun1NActivity::loadRecByQref(
			ubigint qref
			, FmncQRunRun1NActivity** rec
		) {
	return false;
};

ubigint TblFmncQRunRun1NActivity::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQRunRun1NActivity
 ******************************************************************************/

MyTblFmncQRunRun1NActivity::MyTblFmncQRunRun1NActivity() : TblFmncQRunRun1NActivity(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQRunRun1NActivity::~MyTblFmncQRunRun1NActivity() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQRunRun1NActivity::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQRunRun1NActivity (jref, jnum, ref, runNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQRunRun1NActivity SET jref = ?, jnum = ?, ref = ?, runNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQRunRun1NActivity WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQRunRun1NActivity WHERE jref = ?", false);
};

bool MyTblFmncQRunRun1NActivity::loadRecBySQL(
			const string& sqlstr
			, FmncQRunRun1NActivity** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQRunRun1NActivity* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQRunRun1NActivity / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQRunRun1NActivity();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->runNum = atol((char*) dbrow[4]); else _rec->runNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQRunRun1NActivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQRunRun1NActivity* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQRunRun1NActivity / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQRunRun1NActivity();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->runNum = atol((char*) dbrow[4]); else rec->runNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQRunRun1NActivity::insertRec(
			FmncQRunRun1NActivity* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->runNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunRun1NActivity / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunRun1NActivity / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQRunRun1NActivity::insertRst(
			ListFmncQRunRun1NActivity& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQRunRun1NActivity::updateRec(
			FmncQRunRun1NActivity* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->runNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunRun1NActivity / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunRun1NActivity / stmtUpdateRec)\n");
};

void MyTblFmncQRunRun1NActivity::updateRst(
			ListFmncQRunRun1NActivity& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQRunRun1NActivity::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunRun1NActivity / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunRun1NActivity / stmtRemoveRecByQref)\n");
};

void MyTblFmncQRunRun1NActivity::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunRun1NActivity / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunRun1NActivity / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQRunRun1NActivity::loadRecByQref(
			ubigint qref
			, FmncQRunRun1NActivity** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQRunRun1NActivity WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQRunRun1NActivity::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQRunRun1NActivity WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQRunRun1NActivity
 ******************************************************************************/

PgTblFmncQRunRun1NActivity::PgTblFmncQRunRun1NActivity() : TblFmncQRunRun1NActivity(), PgTable() {
};

PgTblFmncQRunRun1NActivity::~PgTblFmncQRunRun1NActivity() {
};

void PgTblFmncQRunRun1NActivity::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQRunRun1NActivity_insertRec", "INSERT INTO TblFmncQRunRun1NActivity (jref, jnum, ref, runNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunRun1NActivity_updateRec", "UPDATE TblFmncQRunRun1NActivity SET jref = $1, jnum = $2, ref = $3, runNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunRun1NActivity_removeRecByQref", "DELETE FROM TblFmncQRunRun1NActivity WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunRun1NActivity_removeRstByJref", "DELETE FROM TblFmncQRunRun1NActivity WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQRunRun1NActivity_loadRecByQref", "SELECT qref, jref, jnum, ref, runNum FROM TblFmncQRunRun1NActivity WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunRun1NActivity_loadRstByJref", "SELECT qref, jref, jnum, ref, runNum FROM TblFmncQRunRun1NActivity WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQRunRun1NActivity::loadRec(
			PGresult* res
			, FmncQRunRun1NActivity** rec
		) {
	char* ptr;

	FmncQRunRun1NActivity* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQRunRun1NActivity();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "runnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->runNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQRunRun1NActivity::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQRunRun1NActivity* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "runnum")
		};

		while (numread < numrow) {
			rec = new FmncQRunRun1NActivity();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->runNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQRunRun1NActivity::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQRunRun1NActivity** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunRun1NActivity / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQRunRun1NActivity::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunRun1NActivity / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQRunRun1NActivity::loadRecBySQL(
			const string& sqlstr
			, FmncQRunRun1NActivity** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQRunRun1NActivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQRunRun1NActivity::insertRec(
			FmncQRunRun1NActivity* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _runNum = htonl(rec->runNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_runNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQRunRun1NActivity_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunRun1NActivity_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQRunRun1NActivity::insertRst(
			ListFmncQRunRun1NActivity& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQRunRun1NActivity::updateRec(
			FmncQRunRun1NActivity* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _runNum = htonl(rec->runNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_runNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQRunRun1NActivity_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunRun1NActivity_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQRunRun1NActivity::updateRst(
			ListFmncQRunRun1NActivity& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQRunRun1NActivity::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncQRunRun1NActivity_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunRun1NActivity_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQRunRun1NActivity::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncQRunRun1NActivity_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunRun1NActivity_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQRunRun1NActivity::loadRecByQref(
			ubigint qref
			, FmncQRunRun1NActivity** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQRunRun1NActivity_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQRunRun1NActivity::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQRunRun1NActivity& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQRunRun1NActivity_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

