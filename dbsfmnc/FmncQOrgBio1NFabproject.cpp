/**
  * \file FmncQOrgBio1NFabproject.cpp
  * Dbs and XML wrapper for table TblFmncQOrgBio1NFabproject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgBio1NFabproject.h"

/******************************************************************************
 class FmncQOrgBio1NFabproject
 ******************************************************************************/

FmncQOrgBio1NFabproject::FmncQOrgBio1NFabproject(
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

void FmncQOrgBio1NFabproject::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrgBio1NFabproject";

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
 class ListFmncQOrgBio1NFabproject
 ******************************************************************************/

ListFmncQOrgBio1NFabproject::ListFmncQOrgBio1NFabproject() {
};

ListFmncQOrgBio1NFabproject::ListFmncQOrgBio1NFabproject(
			const ListFmncQOrgBio1NFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgBio1NFabproject(*(src.nodes[i]));
};

ListFmncQOrgBio1NFabproject::~ListFmncQOrgBio1NFabproject() {
	clear();
};

void ListFmncQOrgBio1NFabproject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrgBio1NFabproject::size() const {
	return(nodes.size());
};

void ListFmncQOrgBio1NFabproject::append(
			FmncQOrgBio1NFabproject* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrgBio1NFabproject& ListFmncQOrgBio1NFabproject::operator=(
			const ListFmncQOrgBio1NFabproject& src
		) {
	FmncQOrgBio1NFabproject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrgBio1NFabproject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrgBio1NFabproject::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrgBio1NFabproject";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrgBio1NFabproject
 ******************************************************************************/

TblFmncQOrgBio1NFabproject::TblFmncQOrgBio1NFabproject() {
};

TblFmncQOrgBio1NFabproject::~TblFmncQOrgBio1NFabproject() {
};

bool TblFmncQOrgBio1NFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgBio1NFabproject** rec
		) {
	return false;
};

ubigint TblFmncQOrgBio1NFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	return 0;
};

void TblFmncQOrgBio1NFabproject::insertRec(
			FmncQOrgBio1NFabproject* rec
		) {
};

ubigint TblFmncQOrgBio1NFabproject::insertNewRec(
			FmncQOrgBio1NFabproject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgBio1NFabproject* _rec = NULL;

	_rec = new FmncQOrgBio1NFabproject(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrgBio1NFabproject::appendNewRecToRst(
			ListFmncQOrgBio1NFabproject& rst
			, FmncQOrgBio1NFabproject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgBio1NFabproject* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrgBio1NFabproject::insertRst(
			ListFmncQOrgBio1NFabproject& rst
		) {
};

void TblFmncQOrgBio1NFabproject::updateRec(
			FmncQOrgBio1NFabproject* rec
		) {
};

void TblFmncQOrgBio1NFabproject::updateRst(
			ListFmncQOrgBio1NFabproject& rst
		) {
};

void TblFmncQOrgBio1NFabproject::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrgBio1NFabproject::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrgBio1NFabproject::loadRecByQref(
			ubigint qref
			, FmncQOrgBio1NFabproject** rec
		) {
	return false;
};

ubigint TblFmncQOrgBio1NFabproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrgBio1NFabproject
 ******************************************************************************/

MyTblFmncQOrgBio1NFabproject::MyTblFmncQOrgBio1NFabproject() : TblFmncQOrgBio1NFabproject(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrgBio1NFabproject::~MyTblFmncQOrgBio1NFabproject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrgBio1NFabproject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrgBio1NFabproject (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrgBio1NFabproject SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrgBio1NFabproject WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrgBio1NFabproject WHERE jref = ?", false);
};

bool MyTblFmncQOrgBio1NFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgBio1NFabproject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrgBio1NFabproject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgBio1NFabproject / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrgBio1NFabproject();

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

ubigint MyTblFmncQOrgBio1NFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrgBio1NFabproject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgBio1NFabproject / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrgBio1NFabproject();

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

void MyTblFmncQOrgBio1NFabproject::insertRec(
			FmncQOrgBio1NFabproject* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgBio1NFabproject / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgBio1NFabproject / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrgBio1NFabproject::insertRst(
			ListFmncQOrgBio1NFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrgBio1NFabproject::updateRec(
			FmncQOrgBio1NFabproject* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgBio1NFabproject / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgBio1NFabproject / stmtUpdateRec)\n");
};

void MyTblFmncQOrgBio1NFabproject::updateRst(
			ListFmncQOrgBio1NFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrgBio1NFabproject::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgBio1NFabproject / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgBio1NFabproject / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrgBio1NFabproject::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgBio1NFabproject / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgBio1NFabproject / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrgBio1NFabproject::loadRecByQref(
			ubigint qref
			, FmncQOrgBio1NFabproject** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrgBio1NFabproject WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrgBio1NFabproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrgBio1NFabproject WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrgBio1NFabproject
 ******************************************************************************/

PgTblFmncQOrgBio1NFabproject::PgTblFmncQOrgBio1NFabproject() : TblFmncQOrgBio1NFabproject(), PgTable() {
};

PgTblFmncQOrgBio1NFabproject::~PgTblFmncQOrgBio1NFabproject() {
};

void PgTblFmncQOrgBio1NFabproject::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrgBio1NFabproject_insertRec", "INSERT INTO TblFmncQOrgBio1NFabproject (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgBio1NFabproject_updateRec", "UPDATE TblFmncQOrgBio1NFabproject SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgBio1NFabproject_removeRecByQref", "DELETE FROM TblFmncQOrgBio1NFabproject WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgBio1NFabproject_removeRstByJref", "DELETE FROM TblFmncQOrgBio1NFabproject WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrgBio1NFabproject_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgBio1NFabproject WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgBio1NFabproject_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgBio1NFabproject WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrgBio1NFabproject::loadRec(
			PGresult* res
			, FmncQOrgBio1NFabproject** rec
		) {
	char* ptr;

	FmncQOrgBio1NFabproject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrgBio1NFabproject();

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

ubigint PgTblFmncQOrgBio1NFabproject::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrgBio1NFabproject* rec;

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
			rec = new FmncQOrgBio1NFabproject();

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

bool PgTblFmncQOrgBio1NFabproject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrgBio1NFabproject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgBio1NFabproject / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgBio1NFabproject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgBio1NFabproject / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrgBio1NFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgBio1NFabproject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgBio1NFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrgBio1NFabproject::insertRec(
			FmncQOrgBio1NFabproject* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgBio1NFabproject_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgBio1NFabproject_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrgBio1NFabproject::insertRst(
			ListFmncQOrgBio1NFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrgBio1NFabproject::updateRec(
			FmncQOrgBio1NFabproject* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgBio1NFabproject_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgBio1NFabproject_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrgBio1NFabproject::updateRst(
			ListFmncQOrgBio1NFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrgBio1NFabproject::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgBio1NFabproject_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgBio1NFabproject_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrgBio1NFabproject::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgBio1NFabproject_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgBio1NFabproject_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrgBio1NFabproject::loadRecByQref(
			ubigint qref
			, FmncQOrgBio1NFabproject** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrgBio1NFabproject_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrgBio1NFabproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgBio1NFabproject& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrgBio1NFabproject_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

