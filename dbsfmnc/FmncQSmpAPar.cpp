/**
  * \file FmncQSmpAPar.cpp
  * Dbs and XML wrapper for table TblFmncQSmpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpAPar.h"

/******************************************************************************
 class FmncQSmpAPar
 ******************************************************************************/

FmncQSmpAPar::FmncQSmpAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1SrefKKey = x1SrefKKey;
	this->titX1SrefKKey = titX1SrefKKey;
	this->osrefKVal = osrefKVal;
	this->titOsrefKVal = titOsrefKVal;
};

void FmncQSmpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSmpAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "key", x1SrefKKey);
		writeString(wr, "key2", titX1SrefKKey);
		writeString(wr, "val", osrefKVal);
		writeString(wr, "val2", titOsrefKVal);
	} else {
		writeString(wr, "x1SrefKKey", x1SrefKKey);
		writeString(wr, "titX1SrefKKey", titX1SrefKKey);
		writeString(wr, "osrefKVal", osrefKVal);
		writeString(wr, "titOsrefKVal", titOsrefKVal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQSmpAPar
 ******************************************************************************/

ListFmncQSmpAPar::ListFmncQSmpAPar() {
};

ListFmncQSmpAPar::ListFmncQSmpAPar(
			const ListFmncQSmpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpAPar(*(src.nodes[i]));
};

ListFmncQSmpAPar::~ListFmncQSmpAPar() {
	clear();
};

void ListFmncQSmpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSmpAPar::size() const {
	return(nodes.size());
};

void ListFmncQSmpAPar::append(
			FmncQSmpAPar* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSmpAPar& ListFmncQSmpAPar::operator=(
			const ListFmncQSmpAPar& src
		) {
	FmncQSmpAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSmpAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSmpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSmpAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSmpAPar
 ******************************************************************************/

TblFmncQSmpAPar::TblFmncQSmpAPar() {
};

TblFmncQSmpAPar::~TblFmncQSmpAPar() {
};

bool TblFmncQSmpAPar::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpAPar** rec
		) {
	return false;
};

ubigint TblFmncQSmpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	return 0;
};

void TblFmncQSmpAPar::insertRec(
			FmncQSmpAPar* rec
		) {
};

ubigint TblFmncQSmpAPar::insertNewRec(
			FmncQSmpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	ubigint retval = 0;
	FmncQSmpAPar* _rec = NULL;

	_rec = new FmncQSmpAPar(0, jref, jnum, ref, x1SrefKKey, titX1SrefKKey, osrefKVal, titOsrefKVal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSmpAPar::appendNewRecToRst(
			ListFmncQSmpAPar& rst
			, FmncQSmpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	ubigint retval = 0;
	FmncQSmpAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKKey, titX1SrefKKey, osrefKVal, titOsrefKVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSmpAPar::insertRst(
			ListFmncQSmpAPar& rst
		) {
};

void TblFmncQSmpAPar::updateRec(
			FmncQSmpAPar* rec
		) {
};

void TblFmncQSmpAPar::updateRst(
			ListFmncQSmpAPar& rst
		) {
};

void TblFmncQSmpAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSmpAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSmpAPar::loadRecByQref(
			ubigint qref
			, FmncQSmpAPar** rec
		) {
	return false;
};

ubigint TblFmncQSmpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSmpAPar
 ******************************************************************************/

MyTblFmncQSmpAPar::MyTblFmncQSmpAPar() : TblFmncQSmpAPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSmpAPar::~MyTblFmncQSmpAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSmpAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSmpAPar (jref, jnum, ref, x1SrefKKey, osrefKVal) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSmpAPar SET jref = ?, jnum = ?, ref = ?, x1SrefKKey = ?, osrefKVal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSmpAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSmpAPar WHERE jref = ?", false);
};

bool MyTblFmncQSmpAPar::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSmpAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSmpAPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSmpAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKKey.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKKey = "";
		if (dbrow[5]) _rec->osrefKVal.assign(dbrow[5], dblengths[5]); else _rec->osrefKVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQSmpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSmpAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSmpAPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSmpAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKKey.assign(dbrow[4], dblengths[4]); else rec->x1SrefKKey = "";
			if (dbrow[5]) rec->osrefKVal.assign(dbrow[5], dblengths[5]); else rec->osrefKVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQSmpAPar::insertRec(
			FmncQSmpAPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x1SrefKKey.length();
	l[4] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpAPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpAPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSmpAPar::insertRst(
			ListFmncQSmpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSmpAPar::updateRec(
			FmncQSmpAPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKKey.length();
	l[4] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpAPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpAPar / stmtUpdateRec)\n");
};

void MyTblFmncQSmpAPar::updateRst(
			ListFmncQSmpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSmpAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpAPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpAPar / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSmpAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpAPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpAPar / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSmpAPar::loadRecByQref(
			ubigint qref
			, FmncQSmpAPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSmpAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSmpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSmpAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSmpAPar
 ******************************************************************************/

PgTblFmncQSmpAPar::PgTblFmncQSmpAPar() : TblFmncQSmpAPar(), PgTable() {
};

PgTblFmncQSmpAPar::~PgTblFmncQSmpAPar() {
};

void PgTblFmncQSmpAPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSmpAPar_insertRec", "INSERT INTO TblFmncQSmpAPar (jref, jnum, ref, x1SrefKKey, osrefKVal) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpAPar_updateRec", "UPDATE TblFmncQSmpAPar SET jref = $1, jnum = $2, ref = $3, x1SrefKKey = $4, osrefKVal = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpAPar_removeRecByQref", "DELETE FROM TblFmncQSmpAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpAPar_removeRstByJref", "DELETE FROM TblFmncQSmpAPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSmpAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1SrefKKey, osrefKVal FROM TblFmncQSmpAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1SrefKKey, osrefKVal FROM TblFmncQSmpAPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSmpAPar::loadRec(
			PGresult* res
			, FmncQSmpAPar** rec
		) {
	char* ptr;

	FmncQSmpAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSmpAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "osrefkval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->osrefKVal.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQSmpAPar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSmpAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "osrefkval")
		};

		while (numread < numrow) {
			rec = new FmncQSmpAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->osrefKVal.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQSmpAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSmpAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpAPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSmpAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpAPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSmpAPar::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSmpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSmpAPar::insertRec(
			FmncQSmpAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1SrefKKey.c_str(),
		rec->osrefKVal.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQSmpAPar_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpAPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSmpAPar::insertRst(
			ListFmncQSmpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSmpAPar::updateRec(
			FmncQSmpAPar* rec
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
		rec->x1SrefKKey.c_str(),
		rec->osrefKVal.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQSmpAPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpAPar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSmpAPar::updateRst(
			ListFmncQSmpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSmpAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSmpAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpAPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSmpAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSmpAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpAPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSmpAPar::loadRecByQref(
			ubigint qref
			, FmncQSmpAPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSmpAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSmpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSmpAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

