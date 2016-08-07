/**
  * \file FmncQTolRlv1NStep.cpp
  * Dbs and XML wrapper for table TblFmncQTolRlv1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolRlv1NStep.h"

/******************************************************************************
 class FmncQTolRlv1NStep
 ******************************************************************************/

FmncQTolRlv1NStep::FmncQTolRlv1NStep(
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

void FmncQTolRlv1NStep::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolRlv1NStep";

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
 class ListFmncQTolRlv1NStep
 ******************************************************************************/

ListFmncQTolRlv1NStep::ListFmncQTolRlv1NStep() {
};

ListFmncQTolRlv1NStep::ListFmncQTolRlv1NStep(
			const ListFmncQTolRlv1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolRlv1NStep(*(src.nodes[i]));
};

ListFmncQTolRlv1NStep::~ListFmncQTolRlv1NStep() {
	clear();
};

void ListFmncQTolRlv1NStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolRlv1NStep::size() const {
	return(nodes.size());
};

void ListFmncQTolRlv1NStep::append(
			FmncQTolRlv1NStep* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolRlv1NStep& ListFmncQTolRlv1NStep::operator=(
			const ListFmncQTolRlv1NStep& src
		) {
	FmncQTolRlv1NStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolRlv1NStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolRlv1NStep::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolRlv1NStep";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolRlv1NStep
 ******************************************************************************/

TblFmncQTolRlv1NStep::TblFmncQTolRlv1NStep() {
};

TblFmncQTolRlv1NStep::~TblFmncQTolRlv1NStep() {
};

bool TblFmncQTolRlv1NStep::loadRecBySQL(
			const string& sqlstr
			, FmncQTolRlv1NStep** rec
		) {
	return false;
};

ubigint TblFmncQTolRlv1NStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	return 0;
};

void TblFmncQTolRlv1NStep::insertRec(
			FmncQTolRlv1NStep* rec
		) {
};

ubigint TblFmncQTolRlv1NStep::insertNewRec(
			FmncQTolRlv1NStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQTolRlv1NStep* _rec = NULL;

	_rec = new FmncQTolRlv1NStep(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolRlv1NStep::appendNewRecToRst(
			ListFmncQTolRlv1NStep& rst
			, FmncQTolRlv1NStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQTolRlv1NStep* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolRlv1NStep::insertRst(
			ListFmncQTolRlv1NStep& rst
		) {
};

void TblFmncQTolRlv1NStep::updateRec(
			FmncQTolRlv1NStep* rec
		) {
};

void TblFmncQTolRlv1NStep::updateRst(
			ListFmncQTolRlv1NStep& rst
		) {
};

void TblFmncQTolRlv1NStep::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolRlv1NStep::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolRlv1NStep::loadRecByQref(
			ubigint qref
			, FmncQTolRlv1NStep** rec
		) {
	return false;
};

ubigint TblFmncQTolRlv1NStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolRlv1NStep
 ******************************************************************************/

MyTblFmncQTolRlv1NStep::MyTblFmncQTolRlv1NStep() : TblFmncQTolRlv1NStep(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolRlv1NStep::~MyTblFmncQTolRlv1NStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolRlv1NStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolRlv1NStep (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolRlv1NStep SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolRlv1NStep WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolRlv1NStep WHERE jref = ?", false);
};

bool MyTblFmncQTolRlv1NStep::loadRecBySQL(
			const string& sqlstr
			, FmncQTolRlv1NStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolRlv1NStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolRlv1NStep / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolRlv1NStep();

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

ubigint MyTblFmncQTolRlv1NStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolRlv1NStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolRlv1NStep / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolRlv1NStep();

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

void MyTblFmncQTolRlv1NStep::insertRec(
			FmncQTolRlv1NStep* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolRlv1NStep / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolRlv1NStep / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolRlv1NStep::insertRst(
			ListFmncQTolRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolRlv1NStep::updateRec(
			FmncQTolRlv1NStep* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolRlv1NStep / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolRlv1NStep / stmtUpdateRec)\n");
};

void MyTblFmncQTolRlv1NStep::updateRst(
			ListFmncQTolRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolRlv1NStep::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolRlv1NStep / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolRlv1NStep / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolRlv1NStep::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolRlv1NStep / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolRlv1NStep / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolRlv1NStep::loadRecByQref(
			ubigint qref
			, FmncQTolRlv1NStep** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolRlv1NStep WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolRlv1NStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolRlv1NStep WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolRlv1NStep
 ******************************************************************************/

PgTblFmncQTolRlv1NStep::PgTblFmncQTolRlv1NStep() : TblFmncQTolRlv1NStep(), PgTable() {
};

PgTblFmncQTolRlv1NStep::~PgTblFmncQTolRlv1NStep() {
};

void PgTblFmncQTolRlv1NStep::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolRlv1NStep_insertRec", "INSERT INTO TblFmncQTolRlv1NStep (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolRlv1NStep_updateRec", "UPDATE TblFmncQTolRlv1NStep SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolRlv1NStep_removeRecByQref", "DELETE FROM TblFmncQTolRlv1NStep WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolRlv1NStep_removeRstByJref", "DELETE FROM TblFmncQTolRlv1NStep WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolRlv1NStep_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQTolRlv1NStep WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolRlv1NStep_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQTolRlv1NStep WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolRlv1NStep::loadRec(
			PGresult* res
			, FmncQTolRlv1NStep** rec
		) {
	char* ptr;

	FmncQTolRlv1NStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolRlv1NStep();

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

ubigint PgTblFmncQTolRlv1NStep::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolRlv1NStep* rec;

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
			rec = new FmncQTolRlv1NStep();

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

bool PgTblFmncQTolRlv1NStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolRlv1NStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolRlv1NStep / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolRlv1NStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolRlv1NStep / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolRlv1NStep::loadRecBySQL(
			const string& sqlstr
			, FmncQTolRlv1NStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolRlv1NStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolRlv1NStep::insertRec(
			FmncQTolRlv1NStep* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTolRlv1NStep_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolRlv1NStep_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolRlv1NStep::insertRst(
			ListFmncQTolRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolRlv1NStep::updateRec(
			FmncQTolRlv1NStep* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTolRlv1NStep_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolRlv1NStep_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolRlv1NStep::updateRst(
			ListFmncQTolRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolRlv1NStep::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolRlv1NStep_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolRlv1NStep_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolRlv1NStep::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolRlv1NStep_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolRlv1NStep_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolRlv1NStep::loadRecByQref(
			ubigint qref
			, FmncQTolRlv1NStep** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolRlv1NStep_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolRlv1NStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolRlv1NStep& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolRlv1NStep_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

