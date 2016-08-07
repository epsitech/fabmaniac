/**
  * \file FmncQOrgSup1NOrg.cpp
  * Dbs and XML wrapper for table TblFmncQOrgSup1NOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgSup1NOrg.h"

/******************************************************************************
 class FmncQOrgSup1NOrg
 ******************************************************************************/

FmncQOrgSup1NOrg::FmncQOrgSup1NOrg(
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

void FmncQOrgSup1NOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrgSup1NOrg";

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
 class ListFmncQOrgSup1NOrg
 ******************************************************************************/

ListFmncQOrgSup1NOrg::ListFmncQOrgSup1NOrg() {
};

ListFmncQOrgSup1NOrg::ListFmncQOrgSup1NOrg(
			const ListFmncQOrgSup1NOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSup1NOrg(*(src.nodes[i]));
};

ListFmncQOrgSup1NOrg::~ListFmncQOrgSup1NOrg() {
	clear();
};

void ListFmncQOrgSup1NOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrgSup1NOrg::size() const {
	return(nodes.size());
};

void ListFmncQOrgSup1NOrg::append(
			FmncQOrgSup1NOrg* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrgSup1NOrg& ListFmncQOrgSup1NOrg::operator=(
			const ListFmncQOrgSup1NOrg& src
		) {
	FmncQOrgSup1NOrg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrgSup1NOrg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrgSup1NOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrgSup1NOrg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrgSup1NOrg
 ******************************************************************************/

TblFmncQOrgSup1NOrg::TblFmncQOrgSup1NOrg() {
};

TblFmncQOrgSup1NOrg::~TblFmncQOrgSup1NOrg() {
};

bool TblFmncQOrgSup1NOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgSup1NOrg** rec
		) {
	return false;
};

ubigint TblFmncQOrgSup1NOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	return 0;
};

void TblFmncQOrgSup1NOrg::insertRec(
			FmncQOrgSup1NOrg* rec
		) {
};

ubigint TblFmncQOrgSup1NOrg::insertNewRec(
			FmncQOrgSup1NOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgSup1NOrg* _rec = NULL;

	_rec = new FmncQOrgSup1NOrg(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrgSup1NOrg::appendNewRecToRst(
			ListFmncQOrgSup1NOrg& rst
			, FmncQOrgSup1NOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQOrgSup1NOrg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrgSup1NOrg::insertRst(
			ListFmncQOrgSup1NOrg& rst
		) {
};

void TblFmncQOrgSup1NOrg::updateRec(
			FmncQOrgSup1NOrg* rec
		) {
};

void TblFmncQOrgSup1NOrg::updateRst(
			ListFmncQOrgSup1NOrg& rst
		) {
};

void TblFmncQOrgSup1NOrg::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrgSup1NOrg::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrgSup1NOrg::loadRecByQref(
			ubigint qref
			, FmncQOrgSup1NOrg** rec
		) {
	return false;
};

ubigint TblFmncQOrgSup1NOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrgSup1NOrg
 ******************************************************************************/

MyTblFmncQOrgSup1NOrg::MyTblFmncQOrgSup1NOrg() : TblFmncQOrgSup1NOrg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrgSup1NOrg::~MyTblFmncQOrgSup1NOrg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrgSup1NOrg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrgSup1NOrg (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrgSup1NOrg SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrgSup1NOrg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrgSup1NOrg WHERE jref = ?", false);
};

bool MyTblFmncQOrgSup1NOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgSup1NOrg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrgSup1NOrg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgSup1NOrg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrgSup1NOrg();

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

ubigint MyTblFmncQOrgSup1NOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrgSup1NOrg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgSup1NOrg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrgSup1NOrg();

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

void MyTblFmncQOrgSup1NOrg::insertRec(
			FmncQOrgSup1NOrg* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSup1NOrg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSup1NOrg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrgSup1NOrg::insertRst(
			ListFmncQOrgSup1NOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrgSup1NOrg::updateRec(
			FmncQOrgSup1NOrg* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSup1NOrg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSup1NOrg / stmtUpdateRec)\n");
};

void MyTblFmncQOrgSup1NOrg::updateRst(
			ListFmncQOrgSup1NOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrgSup1NOrg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSup1NOrg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSup1NOrg / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrgSup1NOrg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSup1NOrg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSup1NOrg / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrgSup1NOrg::loadRecByQref(
			ubigint qref
			, FmncQOrgSup1NOrg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrgSup1NOrg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrgSup1NOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrgSup1NOrg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrgSup1NOrg
 ******************************************************************************/

PgTblFmncQOrgSup1NOrg::PgTblFmncQOrgSup1NOrg() : TblFmncQOrgSup1NOrg(), PgTable() {
};

PgTblFmncQOrgSup1NOrg::~PgTblFmncQOrgSup1NOrg() {
};

void PgTblFmncQOrgSup1NOrg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrgSup1NOrg_insertRec", "INSERT INTO TblFmncQOrgSup1NOrg (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSup1NOrg_updateRec", "UPDATE TblFmncQOrgSup1NOrg SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSup1NOrg_removeRecByQref", "DELETE FROM TblFmncQOrgSup1NOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSup1NOrg_removeRstByJref", "DELETE FROM TblFmncQOrgSup1NOrg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrgSup1NOrg_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgSup1NOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSup1NOrg_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQOrgSup1NOrg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrgSup1NOrg::loadRec(
			PGresult* res
			, FmncQOrgSup1NOrg** rec
		) {
	char* ptr;

	FmncQOrgSup1NOrg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrgSup1NOrg();

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

ubigint PgTblFmncQOrgSup1NOrg::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrgSup1NOrg* rec;

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
			rec = new FmncQOrgSup1NOrg();

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

bool PgTblFmncQOrgSup1NOrg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrgSup1NOrg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSup1NOrg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgSup1NOrg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSup1NOrg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrgSup1NOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgSup1NOrg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgSup1NOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrgSup1NOrg::insertRec(
			FmncQOrgSup1NOrg* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSup1NOrg_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSup1NOrg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrgSup1NOrg::insertRst(
			ListFmncQOrgSup1NOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrgSup1NOrg::updateRec(
			FmncQOrgSup1NOrg* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSup1NOrg_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSup1NOrg_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrgSup1NOrg::updateRst(
			ListFmncQOrgSup1NOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrgSup1NOrg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSup1NOrg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSup1NOrg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrgSup1NOrg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSup1NOrg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSup1NOrg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrgSup1NOrg::loadRecByQref(
			ubigint qref
			, FmncQOrgSup1NOrg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrgSup1NOrg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrgSup1NOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgSup1NOrg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrgSup1NOrg_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

