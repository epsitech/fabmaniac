/**
  * \file FmncQTtySup1NTooltype.cpp
  * Dbs and XML wrapper for table TblFmncQTtySup1NTooltype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtySup1NTooltype.h"

/******************************************************************************
 class FmncQTtySup1NTooltype
 ******************************************************************************/

FmncQTtySup1NTooltype::FmncQTtySup1NTooltype(
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

void FmncQTtySup1NTooltype::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTtySup1NTooltype";

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
 class ListFmncQTtySup1NTooltype
 ******************************************************************************/

ListFmncQTtySup1NTooltype::ListFmncQTtySup1NTooltype() {
};

ListFmncQTtySup1NTooltype::ListFmncQTtySup1NTooltype(
			const ListFmncQTtySup1NTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtySup1NTooltype(*(src.nodes[i]));
};

ListFmncQTtySup1NTooltype::~ListFmncQTtySup1NTooltype() {
	clear();
};

void ListFmncQTtySup1NTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTtySup1NTooltype::size() const {
	return(nodes.size());
};

void ListFmncQTtySup1NTooltype::append(
			FmncQTtySup1NTooltype* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTtySup1NTooltype& ListFmncQTtySup1NTooltype::operator=(
			const ListFmncQTtySup1NTooltype& src
		) {
	FmncQTtySup1NTooltype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTtySup1NTooltype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTtySup1NTooltype::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTtySup1NTooltype";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTtySup1NTooltype
 ******************************************************************************/

TblFmncQTtySup1NTooltype::TblFmncQTtySup1NTooltype() {
};

TblFmncQTtySup1NTooltype::~TblFmncQTtySup1NTooltype() {
};

bool TblFmncQTtySup1NTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncQTtySup1NTooltype** rec
		) {
	return false;
};

ubigint TblFmncQTtySup1NTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	return 0;
};

void TblFmncQTtySup1NTooltype::insertRec(
			FmncQTtySup1NTooltype* rec
		) {
};

ubigint TblFmncQTtySup1NTooltype::insertNewRec(
			FmncQTtySup1NTooltype** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQTtySup1NTooltype* _rec = NULL;

	_rec = new FmncQTtySup1NTooltype(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTtySup1NTooltype::appendNewRecToRst(
			ListFmncQTtySup1NTooltype& rst
			, FmncQTtySup1NTooltype** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQTtySup1NTooltype* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTtySup1NTooltype::insertRst(
			ListFmncQTtySup1NTooltype& rst
		) {
};

void TblFmncQTtySup1NTooltype::updateRec(
			FmncQTtySup1NTooltype* rec
		) {
};

void TblFmncQTtySup1NTooltype::updateRst(
			ListFmncQTtySup1NTooltype& rst
		) {
};

void TblFmncQTtySup1NTooltype::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTtySup1NTooltype::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTtySup1NTooltype::loadRecByQref(
			ubigint qref
			, FmncQTtySup1NTooltype** rec
		) {
	return false;
};

ubigint TblFmncQTtySup1NTooltype::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTtySup1NTooltype
 ******************************************************************************/

MyTblFmncQTtySup1NTooltype::MyTblFmncQTtySup1NTooltype() : TblFmncQTtySup1NTooltype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTtySup1NTooltype::~MyTblFmncQTtySup1NTooltype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTtySup1NTooltype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTtySup1NTooltype (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTtySup1NTooltype SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTtySup1NTooltype WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTtySup1NTooltype WHERE jref = ?", false);
};

bool MyTblFmncQTtySup1NTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncQTtySup1NTooltype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTtySup1NTooltype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtySup1NTooltype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTtySup1NTooltype();

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

ubigint MyTblFmncQTtySup1NTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTtySup1NTooltype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtySup1NTooltype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTtySup1NTooltype();

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

void MyTblFmncQTtySup1NTooltype::insertRec(
			FmncQTtySup1NTooltype* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtySup1NTooltype / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtySup1NTooltype / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTtySup1NTooltype::insertRst(
			ListFmncQTtySup1NTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTtySup1NTooltype::updateRec(
			FmncQTtySup1NTooltype* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtySup1NTooltype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtySup1NTooltype / stmtUpdateRec)\n");
};

void MyTblFmncQTtySup1NTooltype::updateRst(
			ListFmncQTtySup1NTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTtySup1NTooltype::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtySup1NTooltype / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtySup1NTooltype / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTtySup1NTooltype::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtySup1NTooltype / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtySup1NTooltype / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTtySup1NTooltype::loadRecByQref(
			ubigint qref
			, FmncQTtySup1NTooltype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTtySup1NTooltype WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTtySup1NTooltype::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTtySup1NTooltype WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTtySup1NTooltype
 ******************************************************************************/

PgTblFmncQTtySup1NTooltype::PgTblFmncQTtySup1NTooltype() : TblFmncQTtySup1NTooltype(), PgTable() {
};

PgTblFmncQTtySup1NTooltype::~PgTblFmncQTtySup1NTooltype() {
};

void PgTblFmncQTtySup1NTooltype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTtySup1NTooltype_insertRec", "INSERT INTO TblFmncQTtySup1NTooltype (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtySup1NTooltype_updateRec", "UPDATE TblFmncQTtySup1NTooltype SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtySup1NTooltype_removeRecByQref", "DELETE FROM TblFmncQTtySup1NTooltype WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtySup1NTooltype_removeRstByJref", "DELETE FROM TblFmncQTtySup1NTooltype WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTtySup1NTooltype_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQTtySup1NTooltype WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtySup1NTooltype_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQTtySup1NTooltype WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTtySup1NTooltype::loadRec(
			PGresult* res
			, FmncQTtySup1NTooltype** rec
		) {
	char* ptr;

	FmncQTtySup1NTooltype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTtySup1NTooltype();

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

ubigint PgTblFmncQTtySup1NTooltype::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTtySup1NTooltype* rec;

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
			rec = new FmncQTtySup1NTooltype();

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

bool PgTblFmncQTtySup1NTooltype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTtySup1NTooltype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtySup1NTooltype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtySup1NTooltype::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtySup1NTooltype / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTtySup1NTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncQTtySup1NTooltype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtySup1NTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTtySup1NTooltype::insertRec(
			FmncQTtySup1NTooltype* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTtySup1NTooltype_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtySup1NTooltype_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTtySup1NTooltype::insertRst(
			ListFmncQTtySup1NTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTtySup1NTooltype::updateRec(
			FmncQTtySup1NTooltype* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTtySup1NTooltype_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtySup1NTooltype_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTtySup1NTooltype::updateRst(
			ListFmncQTtySup1NTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTtySup1NTooltype::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtySup1NTooltype_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtySup1NTooltype_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTtySup1NTooltype::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtySup1NTooltype_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtySup1NTooltype_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTtySup1NTooltype::loadRecByQref(
			ubigint qref
			, FmncQTtySup1NTooltype** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTtySup1NTooltype_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTtySup1NTooltype::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtySup1NTooltype& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTtySup1NTooltype_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

