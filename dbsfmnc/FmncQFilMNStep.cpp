/**
  * \file FmncQFilMNStep.cpp
  * Dbs and XML wrapper for table TblFmncQFilMNStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFilMNStep.h"

/******************************************************************************
 class FmncQFilMNStep
 ******************************************************************************/

FmncQFilMNStep::FmncQFilMNStep(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const ubigint ref
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->stubsTrefFmncMSample = stubsTrefFmncMSample;
	this->ref = ref;
	this->ixVDir = ixVDir;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
};

void FmncQFilMNStep::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFilMNStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "tsmp", stubsTrefFmncMSample);
		writeString(wr, "dir", srefIxVDir);
		writeString(wr, "dir2", titIxVDir);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubsTrefFmncMSample", stubsTrefFmncMSample);
		writeString(wr, "srefIxVDir", srefIxVDir);
		writeString(wr, "titIxVDir", titIxVDir);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQFilMNStep
 ******************************************************************************/

ListFmncQFilMNStep::ListFmncQFilMNStep() {
};

ListFmncQFilMNStep::ListFmncQFilMNStep(
			const ListFmncQFilMNStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFilMNStep(*(src.nodes[i]));
};

ListFmncQFilMNStep::~ListFmncQFilMNStep() {
	clear();
};

void ListFmncQFilMNStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFilMNStep::size() const {
	return(nodes.size());
};

void ListFmncQFilMNStep::append(
			FmncQFilMNStep* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFilMNStep& ListFmncQFilMNStep::operator=(
			const ListFmncQFilMNStep& src
		) {
	FmncQFilMNStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFilMNStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFilMNStep::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFilMNStep";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFilMNStep
 ******************************************************************************/

TblFmncQFilMNStep::TblFmncQFilMNStep() {
};

TblFmncQFilMNStep::~TblFmncQFilMNStep() {
};

bool TblFmncQFilMNStep::loadRecBySQL(
			const string& sqlstr
			, FmncQFilMNStep** rec
		) {
	return false;
};

ubigint TblFmncQFilMNStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	return 0;
};

void TblFmncQFilMNStep::insertRec(
			FmncQFilMNStep* rec
		) {
};

ubigint TblFmncQFilMNStep::insertNewRec(
			FmncQFilMNStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const ubigint ref
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
		) {
	ubigint retval = 0;
	FmncQFilMNStep* _rec = NULL;

	_rec = new FmncQFilMNStep(0, jref, jnum, mref, stubMref, stubsTrefFmncMSample, ref, ixVDir, srefIxVDir, titIxVDir);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFilMNStep::appendNewRecToRst(
			ListFmncQFilMNStep& rst
			, FmncQFilMNStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const ubigint ref
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
		) {
	ubigint retval = 0;
	FmncQFilMNStep* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, stubsTrefFmncMSample, ref, ixVDir, srefIxVDir, titIxVDir);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFilMNStep::insertRst(
			ListFmncQFilMNStep& rst
		) {
};

void TblFmncQFilMNStep::updateRec(
			FmncQFilMNStep* rec
		) {
};

void TblFmncQFilMNStep::updateRst(
			ListFmncQFilMNStep& rst
		) {
};

void TblFmncQFilMNStep::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFilMNStep::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFilMNStep::loadRecByQref(
			ubigint qref
			, FmncQFilMNStep** rec
		) {
	return false;
};

ubigint TblFmncQFilMNStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFilMNStep
 ******************************************************************************/

MyTblFmncQFilMNStep::MyTblFmncQFilMNStep() : TblFmncQFilMNStep(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFilMNStep::~MyTblFmncQFilMNStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFilMNStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFilMNStep (jref, jnum, mref, ref, ixVDir) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFilMNStep SET jref = ?, jnum = ?, mref = ?, ref = ?, ixVDir = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFilMNStep WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFilMNStep WHERE jref = ?", false);
};

bool MyTblFmncQFilMNStep::loadRecBySQL(
			const string& sqlstr
			, FmncQFilMNStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFilMNStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFilMNStep / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFilMNStep();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixVDir = atol((char*) dbrow[5]); else _rec->ixVDir = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQFilMNStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFilMNStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFilMNStep / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFilMNStep();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixVDir = atol((char*) dbrow[5]); else rec->ixVDir = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQFilMNStep::insertRec(
			FmncQFilMNStep* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVDir,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFilMNStep / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFilMNStep / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFilMNStep::insertRst(
			ListFmncQFilMNStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFilMNStep::updateRec(
			FmncQFilMNStep* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVDir,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFilMNStep / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFilMNStep / stmtUpdateRec)\n");
};

void MyTblFmncQFilMNStep::updateRst(
			ListFmncQFilMNStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFilMNStep::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFilMNStep / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFilMNStep / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFilMNStep::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFilMNStep / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFilMNStep / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFilMNStep::loadRecByQref(
			ubigint qref
			, FmncQFilMNStep** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFilMNStep WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFilMNStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFilMNStep WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFilMNStep
 ******************************************************************************/

PgTblFmncQFilMNStep::PgTblFmncQFilMNStep() : TblFmncQFilMNStep(), PgTable() {
};

PgTblFmncQFilMNStep::~PgTblFmncQFilMNStep() {
};

void PgTblFmncQFilMNStep::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFilMNStep_insertRec", "INSERT INTO TblFmncQFilMNStep (jref, jnum, mref, ref, ixVDir) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFilMNStep_updateRec", "UPDATE TblFmncQFilMNStep SET jref = $1, jnum = $2, mref = $3, ref = $4, ixVDir = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFilMNStep_removeRecByQref", "DELETE FROM TblFmncQFilMNStep WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFilMNStep_removeRstByJref", "DELETE FROM TblFmncQFilMNStep WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFilMNStep_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixVDir FROM TblFmncQFilMNStep WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFilMNStep_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixVDir FROM TblFmncQFilMNStep WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFilMNStep::loadRec(
			PGresult* res
			, FmncQFilMNStep** rec
		) {
	char* ptr;

	FmncQFilMNStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFilMNStep();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvdir")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVDir = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQFilMNStep::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFilMNStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvdir")
		};

		while (numread < numrow) {
			rec = new FmncQFilMNStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVDir = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQFilMNStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFilMNStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFilMNStep / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFilMNStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFilMNStep / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFilMNStep::loadRecBySQL(
			const string& sqlstr
			, FmncQFilMNStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFilMNStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFilMNStep::insertRec(
			FmncQFilMNStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVDir = htonl(rec->ixVDir);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixVDir
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFilMNStep_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFilMNStep_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFilMNStep::insertRst(
			ListFmncQFilMNStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFilMNStep::updateRec(
			FmncQFilMNStep* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVDir = htonl(rec->ixVDir);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixVDir,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFilMNStep_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFilMNStep_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFilMNStep::updateRst(
			ListFmncQFilMNStep& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFilMNStep::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFilMNStep_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFilMNStep_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFilMNStep::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFilMNStep_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFilMNStep_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFilMNStep::loadRecByQref(
			ubigint qref
			, FmncQFilMNStep** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFilMNStep_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFilMNStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFilMNStep& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFilMNStep_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

