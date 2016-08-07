/**
  * \file FmncQOrg1NArticle.cpp
  * Dbs and XML wrapper for table TblFmncQOrg1NArticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrg1NArticle.h"

/******************************************************************************
 class FmncQOrg1NArticle
 ******************************************************************************/

FmncQOrg1NArticle::FmncQOrg1NArticle(
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

void FmncQOrg1NArticle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrg1NArticle";

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
 class ListFmncQOrg1NArticle
 ******************************************************************************/

ListFmncQOrg1NArticle::ListFmncQOrg1NArticle() {
};

ListFmncQOrg1NArticle::ListFmncQOrg1NArticle(
			const ListFmncQOrg1NArticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrg1NArticle(*(src.nodes[i]));
};

ListFmncQOrg1NArticle::~ListFmncQOrg1NArticle() {
	clear();
};

void ListFmncQOrg1NArticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrg1NArticle::size() const {
	return(nodes.size());
};

void ListFmncQOrg1NArticle::append(
			FmncQOrg1NArticle* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrg1NArticle& ListFmncQOrg1NArticle::operator=(
			const ListFmncQOrg1NArticle& src
		) {
	FmncQOrg1NArticle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrg1NArticle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrg1NArticle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrg1NArticle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrg1NArticle
 ******************************************************************************/

TblFmncQOrg1NArticle::TblFmncQOrg1NArticle() {
};

TblFmncQOrg1NArticle::~TblFmncQOrg1NArticle() {
};

bool TblFmncQOrg1NArticle::loadRecBySQL(
			const string& sqlstr
			, FmncQOrg1NArticle** rec
		) {
	return false;
};

ubigint TblFmncQOrg1NArticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	return 0;
};

void TblFmncQOrg1NArticle::insertRec(
			FmncQOrg1NArticle* rec
		) {
};

ubigint TblFmncQOrg1NArticle::insertNewRec(
			FmncQOrg1NArticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrg1NArticle* _rec = NULL;

	_rec = new FmncQOrg1NArticle(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrg1NArticle::appendNewRecToRst(
			ListFmncQOrg1NArticle& rst
			, FmncQOrg1NArticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrg1NArticle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrg1NArticle::insertRst(
			ListFmncQOrg1NArticle& rst
		) {
};

void TblFmncQOrg1NArticle::updateRec(
			FmncQOrg1NArticle* rec
		) {
};

void TblFmncQOrg1NArticle::updateRst(
			ListFmncQOrg1NArticle& rst
		) {
};

void TblFmncQOrg1NArticle::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrg1NArticle::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrg1NArticle::loadRecByQref(
			ubigint qref
			, FmncQOrg1NArticle** rec
		) {
	return false;
};

ubigint TblFmncQOrg1NArticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrg1NArticle
 ******************************************************************************/

MyTblFmncQOrg1NArticle::MyTblFmncQOrg1NArticle() : TblFmncQOrg1NArticle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrg1NArticle::~MyTblFmncQOrg1NArticle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrg1NArticle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrg1NArticle (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrg1NArticle SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrg1NArticle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrg1NArticle WHERE jref = ?", false);
};

bool MyTblFmncQOrg1NArticle::loadRecBySQL(
			const string& sqlstr
			, FmncQOrg1NArticle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrg1NArticle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrg1NArticle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrg1NArticle();

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

ubigint MyTblFmncQOrg1NArticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrg1NArticle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrg1NArticle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrg1NArticle();

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

void MyTblFmncQOrg1NArticle::insertRec(
			FmncQOrg1NArticle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NArticle / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NArticle / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrg1NArticle::insertRst(
			ListFmncQOrg1NArticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrg1NArticle::updateRec(
			FmncQOrg1NArticle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NArticle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NArticle / stmtUpdateRec)\n");
};

void MyTblFmncQOrg1NArticle::updateRst(
			ListFmncQOrg1NArticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrg1NArticle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NArticle / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NArticle / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrg1NArticle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NArticle / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NArticle / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrg1NArticle::loadRecByQref(
			ubigint qref
			, FmncQOrg1NArticle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrg1NArticle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrg1NArticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrg1NArticle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrg1NArticle
 ******************************************************************************/

PgTblFmncQOrg1NArticle::PgTblFmncQOrg1NArticle() : TblFmncQOrg1NArticle(), PgTable() {
};

PgTblFmncQOrg1NArticle::~PgTblFmncQOrg1NArticle() {
};

void PgTblFmncQOrg1NArticle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrg1NArticle_insertRec", "INSERT INTO TblFmncQOrg1NArticle (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NArticle_updateRec", "UPDATE TblFmncQOrg1NArticle SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NArticle_removeRecByQref", "DELETE FROM TblFmncQOrg1NArticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NArticle_removeRstByJref", "DELETE FROM TblFmncQOrg1NArticle WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrg1NArticle_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrg1NArticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NArticle_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrg1NArticle WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrg1NArticle::loadRec(
			PGresult* res
			, FmncQOrg1NArticle** rec
		) {
	char* ptr;

	FmncQOrg1NArticle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrg1NArticle();

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

ubigint PgTblFmncQOrg1NArticle::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrg1NArticle* rec;

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
			rec = new FmncQOrg1NArticle();

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

bool PgTblFmncQOrg1NArticle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrg1NArticle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NArticle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrg1NArticle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NArticle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrg1NArticle::loadRecBySQL(
			const string& sqlstr
			, FmncQOrg1NArticle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrg1NArticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrg1NArticle::insertRec(
			FmncQOrg1NArticle* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NArticle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NArticle_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrg1NArticle::insertRst(
			ListFmncQOrg1NArticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrg1NArticle::updateRec(
			FmncQOrg1NArticle* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NArticle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NArticle_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrg1NArticle::updateRst(
			ListFmncQOrg1NArticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrg1NArticle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NArticle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NArticle_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrg1NArticle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NArticle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NArticle_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrg1NArticle::loadRecByQref(
			ubigint qref
			, FmncQOrg1NArticle** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrg1NArticle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrg1NArticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrg1NArticle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrg1NArticle_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

