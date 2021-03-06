/**
  * \file FmncQArt1NStockitem.cpp
  * Dbs and XML wrapper for table TblFmncQArt1NStockitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQArt1NStockitem.h"

/******************************************************************************
 class FmncQArt1NStockitem
 ******************************************************************************/

FmncQArt1NStockitem::FmncQArt1NStockitem(
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

void FmncQArt1NStockitem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQArt1NStockitem";

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
 class ListFmncQArt1NStockitem
 ******************************************************************************/

ListFmncQArt1NStockitem::ListFmncQArt1NStockitem() {
};

ListFmncQArt1NStockitem::ListFmncQArt1NStockitem(
			const ListFmncQArt1NStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArt1NStockitem(*(src.nodes[i]));
};

ListFmncQArt1NStockitem::~ListFmncQArt1NStockitem() {
	clear();
};

void ListFmncQArt1NStockitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQArt1NStockitem::size() const {
	return(nodes.size());
};

void ListFmncQArt1NStockitem::append(
			FmncQArt1NStockitem* rec
		) {
	nodes.push_back(rec);
};

ListFmncQArt1NStockitem& ListFmncQArt1NStockitem::operator=(
			const ListFmncQArt1NStockitem& src
		) {
	FmncQArt1NStockitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQArt1NStockitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQArt1NStockitem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQArt1NStockitem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQArt1NStockitem
 ******************************************************************************/

TblFmncQArt1NStockitem::TblFmncQArt1NStockitem() {
};

TblFmncQArt1NStockitem::~TblFmncQArt1NStockitem() {
};

bool TblFmncQArt1NStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncQArt1NStockitem** rec
		) {
	return false;
};

ubigint TblFmncQArt1NStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	return 0;
};

void TblFmncQArt1NStockitem::insertRec(
			FmncQArt1NStockitem* rec
		) {
};

ubigint TblFmncQArt1NStockitem::insertNewRec(
			FmncQArt1NStockitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQArt1NStockitem* _rec = NULL;

	_rec = new FmncQArt1NStockitem(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQArt1NStockitem::appendNewRecToRst(
			ListFmncQArt1NStockitem& rst
			, FmncQArt1NStockitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQArt1NStockitem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQArt1NStockitem::insertRst(
			ListFmncQArt1NStockitem& rst
		) {
};

void TblFmncQArt1NStockitem::updateRec(
			FmncQArt1NStockitem* rec
		) {
};

void TblFmncQArt1NStockitem::updateRst(
			ListFmncQArt1NStockitem& rst
		) {
};

void TblFmncQArt1NStockitem::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQArt1NStockitem::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQArt1NStockitem::loadRecByQref(
			ubigint qref
			, FmncQArt1NStockitem** rec
		) {
	return false;
};

ubigint TblFmncQArt1NStockitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQArt1NStockitem
 ******************************************************************************/

MyTblFmncQArt1NStockitem::MyTblFmncQArt1NStockitem() : TblFmncQArt1NStockitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQArt1NStockitem::~MyTblFmncQArt1NStockitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQArt1NStockitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQArt1NStockitem (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQArt1NStockitem SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQArt1NStockitem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQArt1NStockitem WHERE jref = ?", false);
};

bool MyTblFmncQArt1NStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncQArt1NStockitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQArt1NStockitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQArt1NStockitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQArt1NStockitem();

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

ubigint MyTblFmncQArt1NStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQArt1NStockitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQArt1NStockitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQArt1NStockitem();

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

void MyTblFmncQArt1NStockitem::insertRec(
			FmncQArt1NStockitem* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArt1NStockitem / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArt1NStockitem / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQArt1NStockitem::insertRst(
			ListFmncQArt1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQArt1NStockitem::updateRec(
			FmncQArt1NStockitem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArt1NStockitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArt1NStockitem / stmtUpdateRec)\n");
};

void MyTblFmncQArt1NStockitem::updateRst(
			ListFmncQArt1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQArt1NStockitem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArt1NStockitem / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArt1NStockitem / stmtRemoveRecByQref)\n");
};

void MyTblFmncQArt1NStockitem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArt1NStockitem / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArt1NStockitem / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQArt1NStockitem::loadRecByQref(
			ubigint qref
			, FmncQArt1NStockitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQArt1NStockitem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQArt1NStockitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQArt1NStockitem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQArt1NStockitem
 ******************************************************************************/

PgTblFmncQArt1NStockitem::PgTblFmncQArt1NStockitem() : TblFmncQArt1NStockitem(), PgTable() {
};

PgTblFmncQArt1NStockitem::~PgTblFmncQArt1NStockitem() {
};

void PgTblFmncQArt1NStockitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQArt1NStockitem_insertRec", "INSERT INTO TblFmncQArt1NStockitem (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArt1NStockitem_updateRec", "UPDATE TblFmncQArt1NStockitem SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArt1NStockitem_removeRecByQref", "DELETE FROM TblFmncQArt1NStockitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArt1NStockitem_removeRstByJref", "DELETE FROM TblFmncQArt1NStockitem WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQArt1NStockitem_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQArt1NStockitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArt1NStockitem_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQArt1NStockitem WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQArt1NStockitem::loadRec(
			PGresult* res
			, FmncQArt1NStockitem** rec
		) {
	char* ptr;

	FmncQArt1NStockitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQArt1NStockitem();

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

ubigint PgTblFmncQArt1NStockitem::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQArt1NStockitem* rec;

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
			rec = new FmncQArt1NStockitem();

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

bool PgTblFmncQArt1NStockitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQArt1NStockitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArt1NStockitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQArt1NStockitem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArt1NStockitem / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQArt1NStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncQArt1NStockitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQArt1NStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQArt1NStockitem::insertRec(
			FmncQArt1NStockitem* rec
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

	res = PQexecPrepared(dbs, "TblFmncQArt1NStockitem_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArt1NStockitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQArt1NStockitem::insertRst(
			ListFmncQArt1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQArt1NStockitem::updateRec(
			FmncQArt1NStockitem* rec
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

	res = PQexecPrepared(dbs, "TblFmncQArt1NStockitem_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArt1NStockitem_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQArt1NStockitem::updateRst(
			ListFmncQArt1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQArt1NStockitem::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQArt1NStockitem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArt1NStockitem_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQArt1NStockitem::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQArt1NStockitem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArt1NStockitem_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQArt1NStockitem::loadRecByQref(
			ubigint qref
			, FmncQArt1NStockitem** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQArt1NStockitem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQArt1NStockitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArt1NStockitem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQArt1NStockitem_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

