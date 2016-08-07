/**
  * \file FmncQFabFab1NTool.cpp
  * Dbs and XML wrapper for table TblFmncQFabFab1NTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFabFab1NTool.h"

/******************************************************************************
 class FmncQFabFab1NTool
 ******************************************************************************/

FmncQFabFab1NTool::FmncQFabFab1NTool(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const string stubsSrefFmncMPerson
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->stubsSrefFmncMPerson = stubsSrefFmncMPerson;
};

void FmncQFabFab1NTool::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFabFab1NTool";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
		writeString(wr, "sprs", stubsSrefFmncMPerson);
	} else {
		writeString(wr, "stubRef", stubRef);
		writeString(wr, "stubsSrefFmncMPerson", stubsSrefFmncMPerson);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQFabFab1NTool
 ******************************************************************************/

ListFmncQFabFab1NTool::ListFmncQFabFab1NTool() {
};

ListFmncQFabFab1NTool::ListFmncQFabFab1NTool(
			const ListFmncQFabFab1NTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFabFab1NTool(*(src.nodes[i]));
};

ListFmncQFabFab1NTool::~ListFmncQFabFab1NTool() {
	clear();
};

void ListFmncQFabFab1NTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFabFab1NTool::size() const {
	return(nodes.size());
};

void ListFmncQFabFab1NTool::append(
			FmncQFabFab1NTool* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFabFab1NTool& ListFmncQFabFab1NTool::operator=(
			const ListFmncQFabFab1NTool& src
		) {
	FmncQFabFab1NTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFabFab1NTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFabFab1NTool::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFabFab1NTool";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFabFab1NTool
 ******************************************************************************/

TblFmncQFabFab1NTool::TblFmncQFabFab1NTool() {
};

TblFmncQFabFab1NTool::~TblFmncQFabFab1NTool() {
};

bool TblFmncQFabFab1NTool::loadRecBySQL(
			const string& sqlstr
			, FmncQFabFab1NTool** rec
		) {
	return false;
};

ubigint TblFmncQFabFab1NTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	return 0;
};

void TblFmncQFabFab1NTool::insertRec(
			FmncQFabFab1NTool* rec
		) {
};

ubigint TblFmncQFabFab1NTool::insertNewRec(
			FmncQFabFab1NTool** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const string stubsSrefFmncMPerson
		) {
	ubigint retval = 0;
	FmncQFabFab1NTool* _rec = NULL;

	_rec = new FmncQFabFab1NTool(0, jref, jnum, ref, stubRef, stubsSrefFmncMPerson);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFabFab1NTool::appendNewRecToRst(
			ListFmncQFabFab1NTool& rst
			, FmncQFabFab1NTool** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const string stubsSrefFmncMPerson
		) {
	ubigint retval = 0;
	FmncQFabFab1NTool* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, stubsSrefFmncMPerson);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFabFab1NTool::insertRst(
			ListFmncQFabFab1NTool& rst
		) {
};

void TblFmncQFabFab1NTool::updateRec(
			FmncQFabFab1NTool* rec
		) {
};

void TblFmncQFabFab1NTool::updateRst(
			ListFmncQFabFab1NTool& rst
		) {
};

void TblFmncQFabFab1NTool::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFabFab1NTool::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFabFab1NTool::loadRecByQref(
			ubigint qref
			, FmncQFabFab1NTool** rec
		) {
	return false;
};

ubigint TblFmncQFabFab1NTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFabFab1NTool
 ******************************************************************************/

MyTblFmncQFabFab1NTool::MyTblFmncQFabFab1NTool() : TblFmncQFabFab1NTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFabFab1NTool::~MyTblFmncQFabFab1NTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFabFab1NTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFabFab1NTool (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFabFab1NTool SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFabFab1NTool WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFabFab1NTool WHERE jref = ?", false);
};

bool MyTblFmncQFabFab1NTool::loadRecBySQL(
			const string& sqlstr
			, FmncQFabFab1NTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFabFab1NTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFabFab1NTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFabFab1NTool();

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

ubigint MyTblFmncQFabFab1NTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFabFab1NTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFabFab1NTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFabFab1NTool();

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

void MyTblFmncQFabFab1NTool::insertRec(
			FmncQFabFab1NTool* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFabFab1NTool / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFabFab1NTool / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFabFab1NTool::insertRst(
			ListFmncQFabFab1NTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFabFab1NTool::updateRec(
			FmncQFabFab1NTool* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFabFab1NTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFabFab1NTool / stmtUpdateRec)\n");
};

void MyTblFmncQFabFab1NTool::updateRst(
			ListFmncQFabFab1NTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFabFab1NTool::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFabFab1NTool / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFabFab1NTool / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFabFab1NTool::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFabFab1NTool / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFabFab1NTool / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFabFab1NTool::loadRecByQref(
			ubigint qref
			, FmncQFabFab1NTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFabFab1NTool WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFabFab1NTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFabFab1NTool WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFabFab1NTool
 ******************************************************************************/

PgTblFmncQFabFab1NTool::PgTblFmncQFabFab1NTool() : TblFmncQFabFab1NTool(), PgTable() {
};

PgTblFmncQFabFab1NTool::~PgTblFmncQFabFab1NTool() {
};

void PgTblFmncQFabFab1NTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFabFab1NTool_insertRec", "INSERT INTO TblFmncQFabFab1NTool (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFabFab1NTool_updateRec", "UPDATE TblFmncQFabFab1NTool SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFabFab1NTool_removeRecByQref", "DELETE FROM TblFmncQFabFab1NTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFabFab1NTool_removeRstByJref", "DELETE FROM TblFmncQFabFab1NTool WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFabFab1NTool_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQFabFab1NTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFabFab1NTool_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQFabFab1NTool WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFabFab1NTool::loadRec(
			PGresult* res
			, FmncQFabFab1NTool** rec
		) {
	char* ptr;

	FmncQFabFab1NTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFabFab1NTool();

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

ubigint PgTblFmncQFabFab1NTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFabFab1NTool* rec;

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
			rec = new FmncQFabFab1NTool();

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

bool PgTblFmncQFabFab1NTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFabFab1NTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFabFab1NTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFabFab1NTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFabFab1NTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFabFab1NTool::loadRecBySQL(
			const string& sqlstr
			, FmncQFabFab1NTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFabFab1NTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFabFab1NTool::insertRec(
			FmncQFabFab1NTool* rec
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

	res = PQexecPrepared(dbs, "TblFmncQFabFab1NTool_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFabFab1NTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFabFab1NTool::insertRst(
			ListFmncQFabFab1NTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFabFab1NTool::updateRec(
			FmncQFabFab1NTool* rec
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

	res = PQexecPrepared(dbs, "TblFmncQFabFab1NTool_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFabFab1NTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFabFab1NTool::updateRst(
			ListFmncQFabFab1NTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFabFab1NTool::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFabFab1NTool_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFabFab1NTool_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFabFab1NTool::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFabFab1NTool_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFabFab1NTool_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFabFab1NTool::loadRecByQref(
			ubigint qref
			, FmncQFabFab1NTool** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFabFab1NTool_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFabFab1NTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFabFab1NTool& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFabFab1NTool_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

