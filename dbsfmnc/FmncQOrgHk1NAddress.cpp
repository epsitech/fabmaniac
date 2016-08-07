/**
  * \file FmncQOrgHk1NAddress.cpp
  * Dbs and XML wrapper for table TblFmncQOrgHk1NAddress (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgHk1NAddress.h"

/******************************************************************************
 class FmncQOrgHk1NAddress
 ******************************************************************************/

FmncQOrgHk1NAddress::FmncQOrgHk1NAddress(
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

void FmncQOrgHk1NAddress::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrgHk1NAddress";

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
 class ListFmncQOrgHk1NAddress
 ******************************************************************************/

ListFmncQOrgHk1NAddress::ListFmncQOrgHk1NAddress() {
};

ListFmncQOrgHk1NAddress::ListFmncQOrgHk1NAddress(
			const ListFmncQOrgHk1NAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgHk1NAddress(*(src.nodes[i]));
};

ListFmncQOrgHk1NAddress::~ListFmncQOrgHk1NAddress() {
	clear();
};

void ListFmncQOrgHk1NAddress::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrgHk1NAddress::size() const {
	return(nodes.size());
};

void ListFmncQOrgHk1NAddress::append(
			FmncQOrgHk1NAddress* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrgHk1NAddress& ListFmncQOrgHk1NAddress::operator=(
			const ListFmncQOrgHk1NAddress& src
		) {
	FmncQOrgHk1NAddress* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrgHk1NAddress(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrgHk1NAddress::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrgHk1NAddress";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrgHk1NAddress
 ******************************************************************************/

TblFmncQOrgHk1NAddress::TblFmncQOrgHk1NAddress() {
};

TblFmncQOrgHk1NAddress::~TblFmncQOrgHk1NAddress() {
};

bool TblFmncQOrgHk1NAddress::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgHk1NAddress** rec
		) {
	return false;
};

ubigint TblFmncQOrgHk1NAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	return 0;
};

void TblFmncQOrgHk1NAddress::insertRec(
			FmncQOrgHk1NAddress* rec
		) {
};

ubigint TblFmncQOrgHk1NAddress::insertNewRec(
			FmncQOrgHk1NAddress** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgHk1NAddress* _rec = NULL;

	_rec = new FmncQOrgHk1NAddress(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrgHk1NAddress::appendNewRecToRst(
			ListFmncQOrgHk1NAddress& rst
			, FmncQOrgHk1NAddress** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgHk1NAddress* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrgHk1NAddress::insertRst(
			ListFmncQOrgHk1NAddress& rst
		) {
};

void TblFmncQOrgHk1NAddress::updateRec(
			FmncQOrgHk1NAddress* rec
		) {
};

void TblFmncQOrgHk1NAddress::updateRst(
			ListFmncQOrgHk1NAddress& rst
		) {
};

void TblFmncQOrgHk1NAddress::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrgHk1NAddress::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrgHk1NAddress::loadRecByQref(
			ubigint qref
			, FmncQOrgHk1NAddress** rec
		) {
	return false;
};

ubigint TblFmncQOrgHk1NAddress::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrgHk1NAddress
 ******************************************************************************/

MyTblFmncQOrgHk1NAddress::MyTblFmncQOrgHk1NAddress() : TblFmncQOrgHk1NAddress(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrgHk1NAddress::~MyTblFmncQOrgHk1NAddress() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrgHk1NAddress::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrgHk1NAddress (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrgHk1NAddress SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrgHk1NAddress WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrgHk1NAddress WHERE jref = ?", false);
};

bool MyTblFmncQOrgHk1NAddress::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgHk1NAddress** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrgHk1NAddress* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgHk1NAddress / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrgHk1NAddress();

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

ubigint MyTblFmncQOrgHk1NAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrgHk1NAddress* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgHk1NAddress / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrgHk1NAddress();

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

void MyTblFmncQOrgHk1NAddress::insertRec(
			FmncQOrgHk1NAddress* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgHk1NAddress / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgHk1NAddress / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrgHk1NAddress::insertRst(
			ListFmncQOrgHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrgHk1NAddress::updateRec(
			FmncQOrgHk1NAddress* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgHk1NAddress / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgHk1NAddress / stmtUpdateRec)\n");
};

void MyTblFmncQOrgHk1NAddress::updateRst(
			ListFmncQOrgHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrgHk1NAddress::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgHk1NAddress / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgHk1NAddress / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrgHk1NAddress::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgHk1NAddress / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgHk1NAddress / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrgHk1NAddress::loadRecByQref(
			ubigint qref
			, FmncQOrgHk1NAddress** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrgHk1NAddress WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrgHk1NAddress::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrgHk1NAddress WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrgHk1NAddress
 ******************************************************************************/

PgTblFmncQOrgHk1NAddress::PgTblFmncQOrgHk1NAddress() : TblFmncQOrgHk1NAddress(), PgTable() {
};

PgTblFmncQOrgHk1NAddress::~PgTblFmncQOrgHk1NAddress() {
};

void PgTblFmncQOrgHk1NAddress::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrgHk1NAddress_insertRec", "INSERT INTO TblFmncQOrgHk1NAddress (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgHk1NAddress_updateRec", "UPDATE TblFmncQOrgHk1NAddress SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgHk1NAddress_removeRecByQref", "DELETE FROM TblFmncQOrgHk1NAddress WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgHk1NAddress_removeRstByJref", "DELETE FROM TblFmncQOrgHk1NAddress WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrgHk1NAddress_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgHk1NAddress WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgHk1NAddress_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgHk1NAddress WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrgHk1NAddress::loadRec(
			PGresult* res
			, FmncQOrgHk1NAddress** rec
		) {
	char* ptr;

	FmncQOrgHk1NAddress* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrgHk1NAddress();

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

ubigint PgTblFmncQOrgHk1NAddress::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrgHk1NAddress* rec;

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
			rec = new FmncQOrgHk1NAddress();

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

bool PgTblFmncQOrgHk1NAddress::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrgHk1NAddress** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgHk1NAddress / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgHk1NAddress::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgHk1NAddress / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrgHk1NAddress::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgHk1NAddress** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgHk1NAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrgHk1NAddress::insertRec(
			FmncQOrgHk1NAddress* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgHk1NAddress_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgHk1NAddress_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrgHk1NAddress::insertRst(
			ListFmncQOrgHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrgHk1NAddress::updateRec(
			FmncQOrgHk1NAddress* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgHk1NAddress_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgHk1NAddress_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrgHk1NAddress::updateRst(
			ListFmncQOrgHk1NAddress& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrgHk1NAddress::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgHk1NAddress_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgHk1NAddress_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrgHk1NAddress::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgHk1NAddress_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgHk1NAddress_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrgHk1NAddress::loadRecByQref(
			ubigint qref
			, FmncQOrgHk1NAddress** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrgHk1NAddress_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrgHk1NAddress::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgHk1NAddress& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrgHk1NAddress_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

