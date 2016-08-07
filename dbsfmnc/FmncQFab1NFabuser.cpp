/**
  * \file FmncQFab1NFabuser.cpp
  * Dbs and XML wrapper for table TblFmncQFab1NFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFab1NFabuser.h"

/******************************************************************************
 class FmncQFab1NFabuser
 ******************************************************************************/

FmncQFab1NFabuser::FmncQFab1NFabuser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void FmncQFab1NFabuser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFab1NFabuser";

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
 class ListFmncQFab1NFabuser
 ******************************************************************************/

ListFmncQFab1NFabuser::ListFmncQFab1NFabuser() {
};

ListFmncQFab1NFabuser::ListFmncQFab1NFabuser(
			const ListFmncQFab1NFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFab1NFabuser(*(src.nodes[i]));
};

ListFmncQFab1NFabuser::~ListFmncQFab1NFabuser() {
	clear();
};

void ListFmncQFab1NFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFab1NFabuser::size() const {
	return(nodes.size());
};

void ListFmncQFab1NFabuser::append(
			FmncQFab1NFabuser* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFab1NFabuser& ListFmncQFab1NFabuser::operator=(
			const ListFmncQFab1NFabuser& src
		) {
	FmncQFab1NFabuser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFab1NFabuser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFab1NFabuser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFab1NFabuser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFab1NFabuser
 ******************************************************************************/

TblFmncQFab1NFabuser::TblFmncQFab1NFabuser() {
};

TblFmncQFab1NFabuser::~TblFmncQFab1NFabuser() {
};

bool TblFmncQFab1NFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncQFab1NFabuser** rec
		) {
	return false;
};

ubigint TblFmncQFab1NFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	return 0;
};

void TblFmncQFab1NFabuser::insertRec(
			FmncQFab1NFabuser* rec
		) {
};

ubigint TblFmncQFab1NFabuser::insertNewRec(
			FmncQFab1NFabuser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQFab1NFabuser* _rec = NULL;

	_rec = new FmncQFab1NFabuser(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFab1NFabuser::appendNewRecToRst(
			ListFmncQFab1NFabuser& rst
			, FmncQFab1NFabuser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQFab1NFabuser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFab1NFabuser::insertRst(
			ListFmncQFab1NFabuser& rst
		) {
};

void TblFmncQFab1NFabuser::updateRec(
			FmncQFab1NFabuser* rec
		) {
};

void TblFmncQFab1NFabuser::updateRst(
			ListFmncQFab1NFabuser& rst
		) {
};

void TblFmncQFab1NFabuser::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFab1NFabuser::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFab1NFabuser::loadRecByQref(
			ubigint qref
			, FmncQFab1NFabuser** rec
		) {
	return false;
};

ubigint TblFmncQFab1NFabuser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFab1NFabuser
 ******************************************************************************/

MyTblFmncQFab1NFabuser::MyTblFmncQFab1NFabuser() : TblFmncQFab1NFabuser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFab1NFabuser::~MyTblFmncQFab1NFabuser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFab1NFabuser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFab1NFabuser (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFab1NFabuser SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFab1NFabuser WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFab1NFabuser WHERE jref = ?", false);
};

bool MyTblFmncQFab1NFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncQFab1NFabuser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFab1NFabuser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFab1NFabuser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFab1NFabuser();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQFab1NFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFab1NFabuser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFab1NFabuser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFab1NFabuser();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQFab1NFabuser::insertRec(
			FmncQFab1NFabuser* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFab1NFabuser / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFab1NFabuser / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFab1NFabuser::insertRst(
			ListFmncQFab1NFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFab1NFabuser::updateRec(
			FmncQFab1NFabuser* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFab1NFabuser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFab1NFabuser / stmtUpdateRec)\n");
};

void MyTblFmncQFab1NFabuser::updateRst(
			ListFmncQFab1NFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFab1NFabuser::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFab1NFabuser / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFab1NFabuser / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFab1NFabuser::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFab1NFabuser / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFab1NFabuser / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFab1NFabuser::loadRecByQref(
			ubigint qref
			, FmncQFab1NFabuser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFab1NFabuser WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFab1NFabuser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFab1NFabuser WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFab1NFabuser
 ******************************************************************************/

PgTblFmncQFab1NFabuser::PgTblFmncQFab1NFabuser() : TblFmncQFab1NFabuser(), PgTable() {
};

PgTblFmncQFab1NFabuser::~PgTblFmncQFab1NFabuser() {
};

void PgTblFmncQFab1NFabuser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFab1NFabuser_insertRec", "INSERT INTO TblFmncQFab1NFabuser (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFab1NFabuser_updateRec", "UPDATE TblFmncQFab1NFabuser SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFab1NFabuser_removeRecByQref", "DELETE FROM TblFmncQFab1NFabuser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFab1NFabuser_removeRstByJref", "DELETE FROM TblFmncQFab1NFabuser WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFab1NFabuser_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQFab1NFabuser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFab1NFabuser_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQFab1NFabuser WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFab1NFabuser::loadRec(
			PGresult* res
			, FmncQFab1NFabuser** rec
		) {
	char* ptr;

	FmncQFab1NFabuser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFab1NFabuser();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQFab1NFabuser::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFab1NFabuser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new FmncQFab1NFabuser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQFab1NFabuser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFab1NFabuser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFab1NFabuser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFab1NFabuser::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFab1NFabuser / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFab1NFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncQFab1NFabuser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFab1NFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFab1NFabuser::insertRec(
			FmncQFab1NFabuser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFab1NFabuser_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFab1NFabuser_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFab1NFabuser::insertRst(
			ListFmncQFab1NFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFab1NFabuser::updateRec(
			FmncQFab1NFabuser* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFab1NFabuser_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFab1NFabuser_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFab1NFabuser::updateRst(
			ListFmncQFab1NFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFab1NFabuser::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFab1NFabuser_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFab1NFabuser_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFab1NFabuser::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFab1NFabuser_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFab1NFabuser_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFab1NFabuser::loadRecByQref(
			ubigint qref
			, FmncQFab1NFabuser** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFab1NFabuser_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFab1NFabuser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFab1NFabuser& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFab1NFabuser_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

