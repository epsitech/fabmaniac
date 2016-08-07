/**
  * \file FmncQPrsHk1NAddress.cpp
  * Dbs and XML wrapper for table TblFmncQPrsHk1NAddress (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrsHk1NAddress.h"

/******************************************************************************
 class FmncQPrsHk1NAddress
 ******************************************************************************/

FmncQPrsHk1NAddress::FmncQPrsHk1NAddress(
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

void FmncQPrsHk1NAddress::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQPrsHk1NAddress";

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
 class ListFmncQPrsHk1NAddress
 ******************************************************************************/

ListFmncQPrsHk1NAddress::ListFmncQPrsHk1NAddress() {
};

ListFmncQPrsHk1NAddress::ListFmncQPrsHk1NAddress(
			const ListFmncQPrsHk1NAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsHk1NAddress(*(src.nodes[i]));
};

ListFmncQPrsHk1NAddress::~ListFmncQPrsHk1NAddress() {
	clear();
};

void ListFmncQPrsHk1NAddress::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQPrsHk1NAddress::size() const {
	return(nodes.size());
};

void ListFmncQPrsHk1NAddress::append(
			FmncQPrsHk1NAddress* rec
		) {
	nodes.push_back(rec);
};

ListFmncQPrsHk1NAddress& ListFmncQPrsHk1NAddress::operator=(
			const ListFmncQPrsHk1NAddress& src
		) {
	FmncQPrsHk1NAddress* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQPrsHk1NAddress(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQPrsHk1NAddress::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQPrsHk1NAddress";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQPrsHk1NAddress
 ******************************************************************************/

TblFmncQPrsHk1NAddress::TblFmncQPrsHk1NAddress() {
};

TblFmncQPrsHk1NAddress::~TblFmncQPrsHk1NAddress() {
};

bool TblFmncQPrsHk1NAddress::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsHk1NAddress** rec
		) {
	return false;
};

ubigint TblFmncQPrsHk1NAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	return 0;
};

void TblFmncQPrsHk1NAddress::insertRec(
			FmncQPrsHk1NAddress* rec
		) {
};

ubigint TblFmncQPrsHk1NAddress::insertNewRec(
			FmncQPrsHk1NAddress** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQPrsHk1NAddress* _rec = NULL;

	_rec = new FmncQPrsHk1NAddress(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQPrsHk1NAddress::appendNewRecToRst(
			ListFmncQPrsHk1NAddress& rst
			, FmncQPrsHk1NAddress** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQPrsHk1NAddress* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQPrsHk1NAddress::insertRst(
			ListFmncQPrsHk1NAddress& rst
		) {
};

void TblFmncQPrsHk1NAddress::updateRec(
			FmncQPrsHk1NAddress* rec
		) {
};

void TblFmncQPrsHk1NAddress::updateRst(
			ListFmncQPrsHk1NAddress& rst
		) {
};

void TblFmncQPrsHk1NAddress::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQPrsHk1NAddress::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQPrsHk1NAddress::loadRecByQref(
			ubigint qref
			, FmncQPrsHk1NAddress** rec
		) {
	return false;
};

ubigint TblFmncQPrsHk1NAddress::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQPrsHk1NAddress
 ******************************************************************************/

MyTblFmncQPrsHk1NAddress::MyTblFmncQPrsHk1NAddress() : TblFmncQPrsHk1NAddress(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQPrsHk1NAddress::~MyTblFmncQPrsHk1NAddress() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQPrsHk1NAddress::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQPrsHk1NAddress (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQPrsHk1NAddress SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQPrsHk1NAddress WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQPrsHk1NAddress WHERE jref = ?", false);
};

bool MyTblFmncQPrsHk1NAddress::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsHk1NAddress** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQPrsHk1NAddress* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPrsHk1NAddress / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQPrsHk1NAddress();

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

ubigint MyTblFmncQPrsHk1NAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQPrsHk1NAddress* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPrsHk1NAddress / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQPrsHk1NAddress();

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

void MyTblFmncQPrsHk1NAddress::insertRec(
			FmncQPrsHk1NAddress* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsHk1NAddress / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsHk1NAddress / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQPrsHk1NAddress::insertRst(
			ListFmncQPrsHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQPrsHk1NAddress::updateRec(
			FmncQPrsHk1NAddress* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsHk1NAddress / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsHk1NAddress / stmtUpdateRec)\n");
};

void MyTblFmncQPrsHk1NAddress::updateRst(
			ListFmncQPrsHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQPrsHk1NAddress::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsHk1NAddress / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsHk1NAddress / stmtRemoveRecByQref)\n");
};

void MyTblFmncQPrsHk1NAddress::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsHk1NAddress / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsHk1NAddress / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQPrsHk1NAddress::loadRecByQref(
			ubigint qref
			, FmncQPrsHk1NAddress** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQPrsHk1NAddress WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQPrsHk1NAddress::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQPrsHk1NAddress WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQPrsHk1NAddress
 ******************************************************************************/

PgTblFmncQPrsHk1NAddress::PgTblFmncQPrsHk1NAddress() : TblFmncQPrsHk1NAddress(), PgTable() {
};

PgTblFmncQPrsHk1NAddress::~PgTblFmncQPrsHk1NAddress() {
};

void PgTblFmncQPrsHk1NAddress::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQPrsHk1NAddress_insertRec", "INSERT INTO TblFmncQPrsHk1NAddress (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsHk1NAddress_updateRec", "UPDATE TblFmncQPrsHk1NAddress SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsHk1NAddress_removeRecByQref", "DELETE FROM TblFmncQPrsHk1NAddress WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsHk1NAddress_removeRstByJref", "DELETE FROM TblFmncQPrsHk1NAddress WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQPrsHk1NAddress_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQPrsHk1NAddress WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsHk1NAddress_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQPrsHk1NAddress WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQPrsHk1NAddress::loadRec(
			PGresult* res
			, FmncQPrsHk1NAddress** rec
		) {
	char* ptr;

	FmncQPrsHk1NAddress* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQPrsHk1NAddress();

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

ubigint PgTblFmncQPrsHk1NAddress::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQPrsHk1NAddress* rec;

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
			rec = new FmncQPrsHk1NAddress();

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

bool PgTblFmncQPrsHk1NAddress::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQPrsHk1NAddress** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsHk1NAddress / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPrsHk1NAddress::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsHk1NAddress / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQPrsHk1NAddress::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsHk1NAddress** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPrsHk1NAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQPrsHk1NAddress::insertRec(
			FmncQPrsHk1NAddress* rec
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

	res = PQexecPrepared(dbs, "TblFmncQPrsHk1NAddress_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsHk1NAddress_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQPrsHk1NAddress::insertRst(
			ListFmncQPrsHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQPrsHk1NAddress::updateRec(
			FmncQPrsHk1NAddress* rec
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

	res = PQexecPrepared(dbs, "TblFmncQPrsHk1NAddress_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsHk1NAddress_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQPrsHk1NAddress::updateRst(
			ListFmncQPrsHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQPrsHk1NAddress::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQPrsHk1NAddress_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsHk1NAddress_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQPrsHk1NAddress::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQPrsHk1NAddress_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsHk1NAddress_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQPrsHk1NAddress::loadRecByQref(
			ubigint qref
			, FmncQPrsHk1NAddress** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQPrsHk1NAddress_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQPrsHk1NAddress::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsHk1NAddress& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQPrsHk1NAddress_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

