/**
  * \file FmncQFusMNFabproject.cpp
  * Dbs and XML wrapper for table TblFmncQFusMNFabproject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFusMNFabproject.h"

/******************************************************************************
 class FmncQFusMNFabproject
 ******************************************************************************/

FmncQFusMNFabproject::FmncQFusMNFabproject(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
};

void FmncQFusMNFabproject::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFusMNFabproject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
	} else {
		writeString(wr, "stubMref", stubMref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQFusMNFabproject
 ******************************************************************************/

ListFmncQFusMNFabproject::ListFmncQFusMNFabproject() {
};

ListFmncQFusMNFabproject::ListFmncQFusMNFabproject(
			const ListFmncQFusMNFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusMNFabproject(*(src.nodes[i]));
};

ListFmncQFusMNFabproject::~ListFmncQFusMNFabproject() {
	clear();
};

void ListFmncQFusMNFabproject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFusMNFabproject::size() const {
	return(nodes.size());
};

void ListFmncQFusMNFabproject::append(
			FmncQFusMNFabproject* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFusMNFabproject& ListFmncQFusMNFabproject::operator=(
			const ListFmncQFusMNFabproject& src
		) {
	FmncQFusMNFabproject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFusMNFabproject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFusMNFabproject::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFusMNFabproject";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFusMNFabproject
 ******************************************************************************/

TblFmncQFusMNFabproject::TblFmncQFusMNFabproject() {
};

TblFmncQFusMNFabproject::~TblFmncQFusMNFabproject() {
};

bool TblFmncQFusMNFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncQFusMNFabproject** rec
		) {
	return false;
};

ubigint TblFmncQFusMNFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	return 0;
};

void TblFmncQFusMNFabproject::insertRec(
			FmncQFusMNFabproject* rec
		) {
};

ubigint TblFmncQFusMNFabproject::insertNewRec(
			FmncQFusMNFabproject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	FmncQFusMNFabproject* _rec = NULL;

	_rec = new FmncQFusMNFabproject(0, jref, jnum, mref, stubMref, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFusMNFabproject::appendNewRecToRst(
			ListFmncQFusMNFabproject& rst
			, FmncQFusMNFabproject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	FmncQFusMNFabproject* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFusMNFabproject::insertRst(
			ListFmncQFusMNFabproject& rst
		) {
};

void TblFmncQFusMNFabproject::updateRec(
			FmncQFusMNFabproject* rec
		) {
};

void TblFmncQFusMNFabproject::updateRst(
			ListFmncQFusMNFabproject& rst
		) {
};

void TblFmncQFusMNFabproject::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFusMNFabproject::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFusMNFabproject::loadRecByQref(
			ubigint qref
			, FmncQFusMNFabproject** rec
		) {
	return false;
};

ubigint TblFmncQFusMNFabproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFusMNFabproject
 ******************************************************************************/

MyTblFmncQFusMNFabproject::MyTblFmncQFusMNFabproject() : TblFmncQFusMNFabproject(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFusMNFabproject::~MyTblFmncQFusMNFabproject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFusMNFabproject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFusMNFabproject (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFusMNFabproject SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFusMNFabproject WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFusMNFabproject WHERE jref = ?", false);
};

bool MyTblFmncQFusMNFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncQFusMNFabproject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFusMNFabproject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFusMNFabproject / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFusMNFabproject();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQFusMNFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFusMNFabproject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFusMNFabproject / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFusMNFabproject();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQFusMNFabproject::insertRec(
			FmncQFusMNFabproject* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNFabproject / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNFabproject / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFusMNFabproject::insertRst(
			ListFmncQFusMNFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFusMNFabproject::updateRec(
			FmncQFusMNFabproject* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNFabproject / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNFabproject / stmtUpdateRec)\n");
};

void MyTblFmncQFusMNFabproject::updateRst(
			ListFmncQFusMNFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFusMNFabproject::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNFabproject / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNFabproject / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFusMNFabproject::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNFabproject / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNFabproject / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFusMNFabproject::loadRecByQref(
			ubigint qref
			, FmncQFusMNFabproject** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFusMNFabproject WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFusMNFabproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFusMNFabproject WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFusMNFabproject
 ******************************************************************************/

PgTblFmncQFusMNFabproject::PgTblFmncQFusMNFabproject() : TblFmncQFusMNFabproject(), PgTable() {
};

PgTblFmncQFusMNFabproject::~PgTblFmncQFusMNFabproject() {
};

void PgTblFmncQFusMNFabproject::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFusMNFabproject_insertRec", "INSERT INTO TblFmncQFusMNFabproject (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNFabproject_updateRec", "UPDATE TblFmncQFusMNFabproject SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNFabproject_removeRecByQref", "DELETE FROM TblFmncQFusMNFabproject WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNFabproject_removeRstByJref", "DELETE FROM TblFmncQFusMNFabproject WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFusMNFabproject_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblFmncQFusMNFabproject WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNFabproject_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblFmncQFusMNFabproject WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFusMNFabproject::loadRec(
			PGresult* res
			, FmncQFusMNFabproject** rec
		) {
	char* ptr;

	FmncQFusMNFabproject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFusMNFabproject();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQFusMNFabproject::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFusMNFabproject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new FmncQFusMNFabproject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQFusMNFabproject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFusMNFabproject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNFabproject / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFusMNFabproject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNFabproject / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFusMNFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncQFusMNFabproject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFusMNFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFusMNFabproject::insertRec(
			FmncQFusMNFabproject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFusMNFabproject_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNFabproject_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFusMNFabproject::insertRst(
			ListFmncQFusMNFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFusMNFabproject::updateRec(
			FmncQFusMNFabproject* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFusMNFabproject_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNFabproject_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFusMNFabproject::updateRst(
			ListFmncQFusMNFabproject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFusMNFabproject::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFusMNFabproject_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNFabproject_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFusMNFabproject::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFusMNFabproject_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNFabproject_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFusMNFabproject::loadRecByQref(
			ubigint qref
			, FmncQFusMNFabproject** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFusMNFabproject_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFusMNFabproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusMNFabproject& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFusMNFabproject_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

