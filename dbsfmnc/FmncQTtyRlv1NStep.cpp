/**
  * \file FmncQTtyRlv1NStep.cpp
  * Dbs and XML wrapper for table TblFmncQTtyRlv1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtyRlv1NStep.h"

/******************************************************************************
 class FmncQTtyRlv1NStep
 ******************************************************************************/

FmncQTtyRlv1NStep::FmncQTtyRlv1NStep(
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

void FmncQTtyRlv1NStep::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTtyRlv1NStep";

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
 class ListFmncQTtyRlv1NStep
 ******************************************************************************/

ListFmncQTtyRlv1NStep::ListFmncQTtyRlv1NStep() {
};

ListFmncQTtyRlv1NStep::ListFmncQTtyRlv1NStep(
			const ListFmncQTtyRlv1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyRlv1NStep(*(src.nodes[i]));
};

ListFmncQTtyRlv1NStep::~ListFmncQTtyRlv1NStep() {
	clear();
};

void ListFmncQTtyRlv1NStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTtyRlv1NStep::size() const {
	return(nodes.size());
};

void ListFmncQTtyRlv1NStep::append(
			FmncQTtyRlv1NStep* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTtyRlv1NStep& ListFmncQTtyRlv1NStep::operator=(
			const ListFmncQTtyRlv1NStep& src
		) {
	FmncQTtyRlv1NStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTtyRlv1NStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTtyRlv1NStep::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTtyRlv1NStep";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTtyRlv1NStep
 ******************************************************************************/

TblFmncQTtyRlv1NStep::TblFmncQTtyRlv1NStep() {
};

TblFmncQTtyRlv1NStep::~TblFmncQTtyRlv1NStep() {
};

bool TblFmncQTtyRlv1NStep::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyRlv1NStep** rec
		) {
	return false;
};

ubigint TblFmncQTtyRlv1NStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	return 0;
};

void TblFmncQTtyRlv1NStep::insertRec(
			FmncQTtyRlv1NStep* rec
		) {
};

ubigint TblFmncQTtyRlv1NStep::insertNewRec(
			FmncQTtyRlv1NStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQTtyRlv1NStep* _rec = NULL;

	_rec = new FmncQTtyRlv1NStep(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTtyRlv1NStep::appendNewRecToRst(
			ListFmncQTtyRlv1NStep& rst
			, FmncQTtyRlv1NStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQTtyRlv1NStep* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTtyRlv1NStep::insertRst(
			ListFmncQTtyRlv1NStep& rst
		) {
};

void TblFmncQTtyRlv1NStep::updateRec(
			FmncQTtyRlv1NStep* rec
		) {
};

void TblFmncQTtyRlv1NStep::updateRst(
			ListFmncQTtyRlv1NStep& rst
		) {
};

void TblFmncQTtyRlv1NStep::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTtyRlv1NStep::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTtyRlv1NStep::loadRecByQref(
			ubigint qref
			, FmncQTtyRlv1NStep** rec
		) {
	return false;
};

ubigint TblFmncQTtyRlv1NStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTtyRlv1NStep
 ******************************************************************************/

MyTblFmncQTtyRlv1NStep::MyTblFmncQTtyRlv1NStep() : TblFmncQTtyRlv1NStep(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTtyRlv1NStep::~MyTblFmncQTtyRlv1NStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTtyRlv1NStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTtyRlv1NStep (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTtyRlv1NStep SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTtyRlv1NStep WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTtyRlv1NStep WHERE jref = ?", false);
};

bool MyTblFmncQTtyRlv1NStep::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyRlv1NStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTtyRlv1NStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtyRlv1NStep / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTtyRlv1NStep();

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

ubigint MyTblFmncQTtyRlv1NStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTtyRlv1NStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtyRlv1NStep / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTtyRlv1NStep();

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

void MyTblFmncQTtyRlv1NStep::insertRec(
			FmncQTtyRlv1NStep* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyRlv1NStep / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyRlv1NStep / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTtyRlv1NStep::insertRst(
			ListFmncQTtyRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTtyRlv1NStep::updateRec(
			FmncQTtyRlv1NStep* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyRlv1NStep / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyRlv1NStep / stmtUpdateRec)\n");
};

void MyTblFmncQTtyRlv1NStep::updateRst(
			ListFmncQTtyRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTtyRlv1NStep::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyRlv1NStep / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyRlv1NStep / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTtyRlv1NStep::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyRlv1NStep / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyRlv1NStep / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTtyRlv1NStep::loadRecByQref(
			ubigint qref
			, FmncQTtyRlv1NStep** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTtyRlv1NStep WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTtyRlv1NStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTtyRlv1NStep WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTtyRlv1NStep
 ******************************************************************************/

PgTblFmncQTtyRlv1NStep::PgTblFmncQTtyRlv1NStep() : TblFmncQTtyRlv1NStep(), PgTable() {
};

PgTblFmncQTtyRlv1NStep::~PgTblFmncQTtyRlv1NStep() {
};

void PgTblFmncQTtyRlv1NStep::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTtyRlv1NStep_insertRec", "INSERT INTO TblFmncQTtyRlv1NStep (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyRlv1NStep_updateRec", "UPDATE TblFmncQTtyRlv1NStep SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyRlv1NStep_removeRecByQref", "DELETE FROM TblFmncQTtyRlv1NStep WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyRlv1NStep_removeRstByJref", "DELETE FROM TblFmncQTtyRlv1NStep WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTtyRlv1NStep_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQTtyRlv1NStep WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyRlv1NStep_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQTtyRlv1NStep WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTtyRlv1NStep::loadRec(
			PGresult* res
			, FmncQTtyRlv1NStep** rec
		) {
	char* ptr;

	FmncQTtyRlv1NStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTtyRlv1NStep();

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

ubigint PgTblFmncQTtyRlv1NStep::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTtyRlv1NStep* rec;

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
			rec = new FmncQTtyRlv1NStep();

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

bool PgTblFmncQTtyRlv1NStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTtyRlv1NStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyRlv1NStep / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtyRlv1NStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyRlv1NStep / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTtyRlv1NStep::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyRlv1NStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtyRlv1NStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTtyRlv1NStep::insertRec(
			FmncQTtyRlv1NStep* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTtyRlv1NStep_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyRlv1NStep_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTtyRlv1NStep::insertRst(
			ListFmncQTtyRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTtyRlv1NStep::updateRec(
			FmncQTtyRlv1NStep* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTtyRlv1NStep_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyRlv1NStep_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTtyRlv1NStep::updateRst(
			ListFmncQTtyRlv1NStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTtyRlv1NStep::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtyRlv1NStep_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyRlv1NStep_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTtyRlv1NStep::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtyRlv1NStep_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyRlv1NStep_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTtyRlv1NStep::loadRecByQref(
			ubigint qref
			, FmncQTtyRlv1NStep** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTtyRlv1NStep_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTtyRlv1NStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyRlv1NStep& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTtyRlv1NStep_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

