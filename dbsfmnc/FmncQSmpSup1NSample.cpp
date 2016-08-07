/**
  * \file FmncQSmpSup1NSample.cpp
  * Dbs and XML wrapper for table TblFmncQSmpSup1NSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpSup1NSample.h"

/******************************************************************************
 class FmncQSmpSup1NSample
 ******************************************************************************/

FmncQSmpSup1NSample::FmncQSmpSup1NSample(
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

void FmncQSmpSup1NSample::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSmpSup1NSample";

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
 class ListFmncQSmpSup1NSample
 ******************************************************************************/

ListFmncQSmpSup1NSample::ListFmncQSmpSup1NSample() {
};

ListFmncQSmpSup1NSample::ListFmncQSmpSup1NSample(
			const ListFmncQSmpSup1NSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpSup1NSample(*(src.nodes[i]));
};

ListFmncQSmpSup1NSample::~ListFmncQSmpSup1NSample() {
	clear();
};

void ListFmncQSmpSup1NSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSmpSup1NSample::size() const {
	return(nodes.size());
};

void ListFmncQSmpSup1NSample::append(
			FmncQSmpSup1NSample* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSmpSup1NSample& ListFmncQSmpSup1NSample::operator=(
			const ListFmncQSmpSup1NSample& src
		) {
	FmncQSmpSup1NSample* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSmpSup1NSample(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSmpSup1NSample::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSmpSup1NSample";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSmpSup1NSample
 ******************************************************************************/

TblFmncQSmpSup1NSample::TblFmncQSmpSup1NSample() {
};

TblFmncQSmpSup1NSample::~TblFmncQSmpSup1NSample() {
};

bool TblFmncQSmpSup1NSample::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpSup1NSample** rec
		) {
	return false;
};

ubigint TblFmncQSmpSup1NSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	return 0;
};

void TblFmncQSmpSup1NSample::insertRec(
			FmncQSmpSup1NSample* rec
		) {
};

ubigint TblFmncQSmpSup1NSample::insertNewRec(
			FmncQSmpSup1NSample** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQSmpSup1NSample* _rec = NULL;

	_rec = new FmncQSmpSup1NSample(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSmpSup1NSample::appendNewRecToRst(
			ListFmncQSmpSup1NSample& rst
			, FmncQSmpSup1NSample** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQSmpSup1NSample* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSmpSup1NSample::insertRst(
			ListFmncQSmpSup1NSample& rst
		) {
};

void TblFmncQSmpSup1NSample::updateRec(
			FmncQSmpSup1NSample* rec
		) {
};

void TblFmncQSmpSup1NSample::updateRst(
			ListFmncQSmpSup1NSample& rst
		) {
};

void TblFmncQSmpSup1NSample::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSmpSup1NSample::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSmpSup1NSample::loadRecByQref(
			ubigint qref
			, FmncQSmpSup1NSample** rec
		) {
	return false;
};

ubigint TblFmncQSmpSup1NSample::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSmpSup1NSample
 ******************************************************************************/

MyTblFmncQSmpSup1NSample::MyTblFmncQSmpSup1NSample() : TblFmncQSmpSup1NSample(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSmpSup1NSample::~MyTblFmncQSmpSup1NSample() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSmpSup1NSample::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSmpSup1NSample (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSmpSup1NSample SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSmpSup1NSample WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSmpSup1NSample WHERE jref = ?", false);
};

bool MyTblFmncQSmpSup1NSample::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpSup1NSample** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSmpSup1NSample* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSmpSup1NSample / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSmpSup1NSample();

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

ubigint MyTblFmncQSmpSup1NSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSmpSup1NSample* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSmpSup1NSample / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSmpSup1NSample();

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

void MyTblFmncQSmpSup1NSample::insertRec(
			FmncQSmpSup1NSample* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpSup1NSample / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpSup1NSample / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSmpSup1NSample::insertRst(
			ListFmncQSmpSup1NSample& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSmpSup1NSample::updateRec(
			FmncQSmpSup1NSample* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpSup1NSample / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpSup1NSample / stmtUpdateRec)\n");
};

void MyTblFmncQSmpSup1NSample::updateRst(
			ListFmncQSmpSup1NSample& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSmpSup1NSample::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpSup1NSample / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpSup1NSample / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSmpSup1NSample::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpSup1NSample / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpSup1NSample / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSmpSup1NSample::loadRecByQref(
			ubigint qref
			, FmncQSmpSup1NSample** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSmpSup1NSample WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSmpSup1NSample::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSmpSup1NSample WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSmpSup1NSample
 ******************************************************************************/

PgTblFmncQSmpSup1NSample::PgTblFmncQSmpSup1NSample() : TblFmncQSmpSup1NSample(), PgTable() {
};

PgTblFmncQSmpSup1NSample::~PgTblFmncQSmpSup1NSample() {
};

void PgTblFmncQSmpSup1NSample::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSmpSup1NSample_insertRec", "INSERT INTO TblFmncQSmpSup1NSample (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpSup1NSample_updateRec", "UPDATE TblFmncQSmpSup1NSample SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpSup1NSample_removeRecByQref", "DELETE FROM TblFmncQSmpSup1NSample WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpSup1NSample_removeRstByJref", "DELETE FROM TblFmncQSmpSup1NSample WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSmpSup1NSample_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQSmpSup1NSample WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpSup1NSample_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQSmpSup1NSample WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSmpSup1NSample::loadRec(
			PGresult* res
			, FmncQSmpSup1NSample** rec
		) {
	char* ptr;

	FmncQSmpSup1NSample* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSmpSup1NSample();

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

ubigint PgTblFmncQSmpSup1NSample::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSmpSup1NSample* rec;

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
			rec = new FmncQSmpSup1NSample();

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

bool PgTblFmncQSmpSup1NSample::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSmpSup1NSample** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpSup1NSample / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSmpSup1NSample::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpSup1NSample / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSmpSup1NSample::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpSup1NSample** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSmpSup1NSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSmpSup1NSample::insertRec(
			FmncQSmpSup1NSample* rec
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

	res = PQexecPrepared(dbs, "TblFmncQSmpSup1NSample_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpSup1NSample_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSmpSup1NSample::insertRst(
			ListFmncQSmpSup1NSample& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSmpSup1NSample::updateRec(
			FmncQSmpSup1NSample* rec
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

	res = PQexecPrepared(dbs, "TblFmncQSmpSup1NSample_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpSup1NSample_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSmpSup1NSample::updateRst(
			ListFmncQSmpSup1NSample& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSmpSup1NSample::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSmpSup1NSample_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpSup1NSample_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSmpSup1NSample::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSmpSup1NSample_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpSup1NSample_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSmpSup1NSample::loadRecByQref(
			ubigint qref
			, FmncQSmpSup1NSample** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSmpSup1NSample_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSmpSup1NSample::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpSup1NSample& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSmpSup1NSample_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

