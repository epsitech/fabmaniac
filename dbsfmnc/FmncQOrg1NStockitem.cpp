/**
  * \file FmncQOrg1NStockitem.cpp
  * Dbs and XML wrapper for table TblFmncQOrg1NStockitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrg1NStockitem.h"

/******************************************************************************
 class FmncQOrg1NStockitem
 ******************************************************************************/

FmncQOrg1NStockitem::FmncQOrg1NStockitem(
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

void FmncQOrg1NStockitem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrg1NStockitem";

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
 class ListFmncQOrg1NStockitem
 ******************************************************************************/

ListFmncQOrg1NStockitem::ListFmncQOrg1NStockitem() {
};

ListFmncQOrg1NStockitem::ListFmncQOrg1NStockitem(
			const ListFmncQOrg1NStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrg1NStockitem(*(src.nodes[i]));
};

ListFmncQOrg1NStockitem::~ListFmncQOrg1NStockitem() {
	clear();
};

void ListFmncQOrg1NStockitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrg1NStockitem::size() const {
	return(nodes.size());
};

void ListFmncQOrg1NStockitem::append(
			FmncQOrg1NStockitem* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrg1NStockitem& ListFmncQOrg1NStockitem::operator=(
			const ListFmncQOrg1NStockitem& src
		) {
	FmncQOrg1NStockitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrg1NStockitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrg1NStockitem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrg1NStockitem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrg1NStockitem
 ******************************************************************************/

TblFmncQOrg1NStockitem::TblFmncQOrg1NStockitem() {
};

TblFmncQOrg1NStockitem::~TblFmncQOrg1NStockitem() {
};

bool TblFmncQOrg1NStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncQOrg1NStockitem** rec
		) {
	return false;
};

ubigint TblFmncQOrg1NStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	return 0;
};

void TblFmncQOrg1NStockitem::insertRec(
			FmncQOrg1NStockitem* rec
		) {
};

ubigint TblFmncQOrg1NStockitem::insertNewRec(
			FmncQOrg1NStockitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrg1NStockitem* _rec = NULL;

	_rec = new FmncQOrg1NStockitem(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrg1NStockitem::appendNewRecToRst(
			ListFmncQOrg1NStockitem& rst
			, FmncQOrg1NStockitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrg1NStockitem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrg1NStockitem::insertRst(
			ListFmncQOrg1NStockitem& rst
		) {
};

void TblFmncQOrg1NStockitem::updateRec(
			FmncQOrg1NStockitem* rec
		) {
};

void TblFmncQOrg1NStockitem::updateRst(
			ListFmncQOrg1NStockitem& rst
		) {
};

void TblFmncQOrg1NStockitem::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrg1NStockitem::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrg1NStockitem::loadRecByQref(
			ubigint qref
			, FmncQOrg1NStockitem** rec
		) {
	return false;
};

ubigint TblFmncQOrg1NStockitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrg1NStockitem
 ******************************************************************************/

MyTblFmncQOrg1NStockitem::MyTblFmncQOrg1NStockitem() : TblFmncQOrg1NStockitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrg1NStockitem::~MyTblFmncQOrg1NStockitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrg1NStockitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrg1NStockitem (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrg1NStockitem SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrg1NStockitem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrg1NStockitem WHERE jref = ?", false);
};

bool MyTblFmncQOrg1NStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncQOrg1NStockitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrg1NStockitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrg1NStockitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrg1NStockitem();

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

ubigint MyTblFmncQOrg1NStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrg1NStockitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrg1NStockitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrg1NStockitem();

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

void MyTblFmncQOrg1NStockitem::insertRec(
			FmncQOrg1NStockitem* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NStockitem / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NStockitem / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrg1NStockitem::insertRst(
			ListFmncQOrg1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrg1NStockitem::updateRec(
			FmncQOrg1NStockitem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NStockitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NStockitem / stmtUpdateRec)\n");
};

void MyTblFmncQOrg1NStockitem::updateRst(
			ListFmncQOrg1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrg1NStockitem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NStockitem / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NStockitem / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrg1NStockitem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrg1NStockitem / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrg1NStockitem / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrg1NStockitem::loadRecByQref(
			ubigint qref
			, FmncQOrg1NStockitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrg1NStockitem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrg1NStockitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrg1NStockitem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrg1NStockitem
 ******************************************************************************/

PgTblFmncQOrg1NStockitem::PgTblFmncQOrg1NStockitem() : TblFmncQOrg1NStockitem(), PgTable() {
};

PgTblFmncQOrg1NStockitem::~PgTblFmncQOrg1NStockitem() {
};

void PgTblFmncQOrg1NStockitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrg1NStockitem_insertRec", "INSERT INTO TblFmncQOrg1NStockitem (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NStockitem_updateRec", "UPDATE TblFmncQOrg1NStockitem SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NStockitem_removeRecByQref", "DELETE FROM TblFmncQOrg1NStockitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NStockitem_removeRstByJref", "DELETE FROM TblFmncQOrg1NStockitem WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrg1NStockitem_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrg1NStockitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrg1NStockitem_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrg1NStockitem WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrg1NStockitem::loadRec(
			PGresult* res
			, FmncQOrg1NStockitem** rec
		) {
	char* ptr;

	FmncQOrg1NStockitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrg1NStockitem();

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

ubigint PgTblFmncQOrg1NStockitem::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrg1NStockitem* rec;

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
			rec = new FmncQOrg1NStockitem();

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

bool PgTblFmncQOrg1NStockitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrg1NStockitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NStockitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrg1NStockitem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NStockitem / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrg1NStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncQOrg1NStockitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrg1NStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrg1NStockitem::insertRec(
			FmncQOrg1NStockitem* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NStockitem_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NStockitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrg1NStockitem::insertRst(
			ListFmncQOrg1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrg1NStockitem::updateRec(
			FmncQOrg1NStockitem* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NStockitem_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NStockitem_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrg1NStockitem::updateRst(
			ListFmncQOrg1NStockitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrg1NStockitem::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NStockitem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NStockitem_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrg1NStockitem::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrg1NStockitem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrg1NStockitem_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrg1NStockitem::loadRecByQref(
			ubigint qref
			, FmncQOrg1NStockitem** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrg1NStockitem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrg1NStockitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrg1NStockitem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrg1NStockitem_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

