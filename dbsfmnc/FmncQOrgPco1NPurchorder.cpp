/**
  * \file FmncQOrgPco1NPurchorder.cpp
  * Dbs and XML wrapper for table TblFmncQOrgPco1NPurchorder (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgPco1NPurchorder.h"

/******************************************************************************
 class FmncQOrgPco1NPurchorder
 ******************************************************************************/

FmncQOrgPco1NPurchorder::FmncQOrgPco1NPurchorder(
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

void FmncQOrgPco1NPurchorder::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrgPco1NPurchorder";

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
 class ListFmncQOrgPco1NPurchorder
 ******************************************************************************/

ListFmncQOrgPco1NPurchorder::ListFmncQOrgPco1NPurchorder() {
};

ListFmncQOrgPco1NPurchorder::ListFmncQOrgPco1NPurchorder(
			const ListFmncQOrgPco1NPurchorder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgPco1NPurchorder(*(src.nodes[i]));
};

ListFmncQOrgPco1NPurchorder::~ListFmncQOrgPco1NPurchorder() {
	clear();
};

void ListFmncQOrgPco1NPurchorder::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrgPco1NPurchorder::size() const {
	return(nodes.size());
};

void ListFmncQOrgPco1NPurchorder::append(
			FmncQOrgPco1NPurchorder* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrgPco1NPurchorder& ListFmncQOrgPco1NPurchorder::operator=(
			const ListFmncQOrgPco1NPurchorder& src
		) {
	FmncQOrgPco1NPurchorder* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrgPco1NPurchorder(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrgPco1NPurchorder::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrgPco1NPurchorder";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrgPco1NPurchorder
 ******************************************************************************/

TblFmncQOrgPco1NPurchorder::TblFmncQOrgPco1NPurchorder() {
};

TblFmncQOrgPco1NPurchorder::~TblFmncQOrgPco1NPurchorder() {
};

bool TblFmncQOrgPco1NPurchorder::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgPco1NPurchorder** rec
		) {
	return false;
};

ubigint TblFmncQOrgPco1NPurchorder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	return 0;
};

void TblFmncQOrgPco1NPurchorder::insertRec(
			FmncQOrgPco1NPurchorder* rec
		) {
};

ubigint TblFmncQOrgPco1NPurchorder::insertNewRec(
			FmncQOrgPco1NPurchorder** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgPco1NPurchorder* _rec = NULL;

	_rec = new FmncQOrgPco1NPurchorder(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrgPco1NPurchorder::appendNewRecToRst(
			ListFmncQOrgPco1NPurchorder& rst
			, FmncQOrgPco1NPurchorder** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgPco1NPurchorder* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrgPco1NPurchorder::insertRst(
			ListFmncQOrgPco1NPurchorder& rst
		) {
};

void TblFmncQOrgPco1NPurchorder::updateRec(
			FmncQOrgPco1NPurchorder* rec
		) {
};

void TblFmncQOrgPco1NPurchorder::updateRst(
			ListFmncQOrgPco1NPurchorder& rst
		) {
};

void TblFmncQOrgPco1NPurchorder::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrgPco1NPurchorder::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrgPco1NPurchorder::loadRecByQref(
			ubigint qref
			, FmncQOrgPco1NPurchorder** rec
		) {
	return false;
};

ubigint TblFmncQOrgPco1NPurchorder::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrgPco1NPurchorder
 ******************************************************************************/

MyTblFmncQOrgPco1NPurchorder::MyTblFmncQOrgPco1NPurchorder() : TblFmncQOrgPco1NPurchorder(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrgPco1NPurchorder::~MyTblFmncQOrgPco1NPurchorder() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrgPco1NPurchorder::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrgPco1NPurchorder (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrgPco1NPurchorder SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrgPco1NPurchorder WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrgPco1NPurchorder WHERE jref = ?", false);
};

bool MyTblFmncQOrgPco1NPurchorder::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgPco1NPurchorder** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrgPco1NPurchorder* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgPco1NPurchorder / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrgPco1NPurchorder();

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

ubigint MyTblFmncQOrgPco1NPurchorder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrgPco1NPurchorder* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgPco1NPurchorder / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrgPco1NPurchorder();

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

void MyTblFmncQOrgPco1NPurchorder::insertRec(
			FmncQOrgPco1NPurchorder* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgPco1NPurchorder / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgPco1NPurchorder / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrgPco1NPurchorder::insertRst(
			ListFmncQOrgPco1NPurchorder& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrgPco1NPurchorder::updateRec(
			FmncQOrgPco1NPurchorder* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgPco1NPurchorder / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgPco1NPurchorder / stmtUpdateRec)\n");
};

void MyTblFmncQOrgPco1NPurchorder::updateRst(
			ListFmncQOrgPco1NPurchorder& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrgPco1NPurchorder::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgPco1NPurchorder / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgPco1NPurchorder / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrgPco1NPurchorder::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgPco1NPurchorder / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgPco1NPurchorder / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrgPco1NPurchorder::loadRecByQref(
			ubigint qref
			, FmncQOrgPco1NPurchorder** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrgPco1NPurchorder WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrgPco1NPurchorder::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrgPco1NPurchorder WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrgPco1NPurchorder
 ******************************************************************************/

PgTblFmncQOrgPco1NPurchorder::PgTblFmncQOrgPco1NPurchorder() : TblFmncQOrgPco1NPurchorder(), PgTable() {
};

PgTblFmncQOrgPco1NPurchorder::~PgTblFmncQOrgPco1NPurchorder() {
};

void PgTblFmncQOrgPco1NPurchorder::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrgPco1NPurchorder_insertRec", "INSERT INTO TblFmncQOrgPco1NPurchorder (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgPco1NPurchorder_updateRec", "UPDATE TblFmncQOrgPco1NPurchorder SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgPco1NPurchorder_removeRecByQref", "DELETE FROM TblFmncQOrgPco1NPurchorder WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgPco1NPurchorder_removeRstByJref", "DELETE FROM TblFmncQOrgPco1NPurchorder WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrgPco1NPurchorder_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgPco1NPurchorder WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgPco1NPurchorder_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgPco1NPurchorder WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrgPco1NPurchorder::loadRec(
			PGresult* res
			, FmncQOrgPco1NPurchorder** rec
		) {
	char* ptr;

	FmncQOrgPco1NPurchorder* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrgPco1NPurchorder();

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

ubigint PgTblFmncQOrgPco1NPurchorder::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrgPco1NPurchorder* rec;

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
			rec = new FmncQOrgPco1NPurchorder();

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

bool PgTblFmncQOrgPco1NPurchorder::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrgPco1NPurchorder** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgPco1NPurchorder / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgPco1NPurchorder::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgPco1NPurchorder / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrgPco1NPurchorder::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgPco1NPurchorder** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgPco1NPurchorder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrgPco1NPurchorder::insertRec(
			FmncQOrgPco1NPurchorder* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgPco1NPurchorder_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgPco1NPurchorder_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrgPco1NPurchorder::insertRst(
			ListFmncQOrgPco1NPurchorder& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrgPco1NPurchorder::updateRec(
			FmncQOrgPco1NPurchorder* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgPco1NPurchorder_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgPco1NPurchorder_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrgPco1NPurchorder::updateRst(
			ListFmncQOrgPco1NPurchorder& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrgPco1NPurchorder::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgPco1NPurchorder_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgPco1NPurchorder_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrgPco1NPurchorder::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgPco1NPurchorder_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgPco1NPurchorder_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrgPco1NPurchorder::loadRecByQref(
			ubigint qref
			, FmncQOrgPco1NPurchorder** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrgPco1NPurchorder_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrgPco1NPurchorder::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgPco1NPurchorder& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrgPco1NPurchorder_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

