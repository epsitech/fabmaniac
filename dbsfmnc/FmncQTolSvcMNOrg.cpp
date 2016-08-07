/**
  * \file FmncQTolSvcMNOrg.cpp
  * Dbs and XML wrapper for table TblFmncQTolSvcMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolSvcMNOrg.h"

/******************************************************************************
 class FmncQTolSvcMNOrg
 ******************************************************************************/

FmncQTolSvcMNOrg::FmncQTolSvcMNOrg(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMPerson
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->stubsTrefFmncMPerson = stubsTrefFmncMPerson;
	this->ref = ref;
};

void FmncQTolSvcMNOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolSvcMNOrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "tprs", stubsTrefFmncMPerson);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubsTrefFmncMPerson", stubsTrefFmncMPerson);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolSvcMNOrg
 ******************************************************************************/

ListFmncQTolSvcMNOrg::ListFmncQTolSvcMNOrg() {
};

ListFmncQTolSvcMNOrg::ListFmncQTolSvcMNOrg(
			const ListFmncQTolSvcMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolSvcMNOrg(*(src.nodes[i]));
};

ListFmncQTolSvcMNOrg::~ListFmncQTolSvcMNOrg() {
	clear();
};

void ListFmncQTolSvcMNOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolSvcMNOrg::size() const {
	return(nodes.size());
};

void ListFmncQTolSvcMNOrg::append(
			FmncQTolSvcMNOrg* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolSvcMNOrg& ListFmncQTolSvcMNOrg::operator=(
			const ListFmncQTolSvcMNOrg& src
		) {
	FmncQTolSvcMNOrg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolSvcMNOrg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolSvcMNOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolSvcMNOrg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolSvcMNOrg
 ******************************************************************************/

TblFmncQTolSvcMNOrg::TblFmncQTolSvcMNOrg() {
};

TblFmncQTolSvcMNOrg::~TblFmncQTolSvcMNOrg() {
};

bool TblFmncQTolSvcMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQTolSvcMNOrg** rec
		) {
	return false;
};

ubigint TblFmncQTolSvcMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	return 0;
};

void TblFmncQTolSvcMNOrg::insertRec(
			FmncQTolSvcMNOrg* rec
		) {
};

ubigint TblFmncQTolSvcMNOrg::insertNewRec(
			FmncQTolSvcMNOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMPerson
			, const ubigint ref
		) {
	ubigint retval = 0;
	FmncQTolSvcMNOrg* _rec = NULL;

	_rec = new FmncQTolSvcMNOrg(0, jref, jnum, mref, stubMref, stubsTrefFmncMPerson, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolSvcMNOrg::appendNewRecToRst(
			ListFmncQTolSvcMNOrg& rst
			, FmncQTolSvcMNOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMPerson
			, const ubigint ref
		) {
	ubigint retval = 0;
	FmncQTolSvcMNOrg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, stubsTrefFmncMPerson, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolSvcMNOrg::insertRst(
			ListFmncQTolSvcMNOrg& rst
		) {
};

void TblFmncQTolSvcMNOrg::updateRec(
			FmncQTolSvcMNOrg* rec
		) {
};

void TblFmncQTolSvcMNOrg::updateRst(
			ListFmncQTolSvcMNOrg& rst
		) {
};

void TblFmncQTolSvcMNOrg::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolSvcMNOrg::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolSvcMNOrg::loadRecByQref(
			ubigint qref
			, FmncQTolSvcMNOrg** rec
		) {
	return false;
};

ubigint TblFmncQTolSvcMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolSvcMNOrg
 ******************************************************************************/

MyTblFmncQTolSvcMNOrg::MyTblFmncQTolSvcMNOrg() : TblFmncQTolSvcMNOrg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolSvcMNOrg::~MyTblFmncQTolSvcMNOrg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolSvcMNOrg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolSvcMNOrg (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolSvcMNOrg SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolSvcMNOrg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolSvcMNOrg WHERE jref = ?", false);
};

bool MyTblFmncQTolSvcMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQTolSvcMNOrg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolSvcMNOrg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolSvcMNOrg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolSvcMNOrg();

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

ubigint MyTblFmncQTolSvcMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolSvcMNOrg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolSvcMNOrg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolSvcMNOrg();

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

void MyTblFmncQTolSvcMNOrg::insertRec(
			FmncQTolSvcMNOrg* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolSvcMNOrg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolSvcMNOrg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolSvcMNOrg::insertRst(
			ListFmncQTolSvcMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolSvcMNOrg::updateRec(
			FmncQTolSvcMNOrg* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolSvcMNOrg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolSvcMNOrg / stmtUpdateRec)\n");
};

void MyTblFmncQTolSvcMNOrg::updateRst(
			ListFmncQTolSvcMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolSvcMNOrg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolSvcMNOrg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolSvcMNOrg / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolSvcMNOrg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolSvcMNOrg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolSvcMNOrg / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolSvcMNOrg::loadRecByQref(
			ubigint qref
			, FmncQTolSvcMNOrg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolSvcMNOrg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolSvcMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolSvcMNOrg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolSvcMNOrg
 ******************************************************************************/

PgTblFmncQTolSvcMNOrg::PgTblFmncQTolSvcMNOrg() : TblFmncQTolSvcMNOrg(), PgTable() {
};

PgTblFmncQTolSvcMNOrg::~PgTblFmncQTolSvcMNOrg() {
};

void PgTblFmncQTolSvcMNOrg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolSvcMNOrg_insertRec", "INSERT INTO TblFmncQTolSvcMNOrg (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolSvcMNOrg_updateRec", "UPDATE TblFmncQTolSvcMNOrg SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolSvcMNOrg_removeRecByQref", "DELETE FROM TblFmncQTolSvcMNOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolSvcMNOrg_removeRstByJref", "DELETE FROM TblFmncQTolSvcMNOrg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolSvcMNOrg_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblFmncQTolSvcMNOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolSvcMNOrg_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblFmncQTolSvcMNOrg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolSvcMNOrg::loadRec(
			PGresult* res
			, FmncQTolSvcMNOrg** rec
		) {
	char* ptr;

	FmncQTolSvcMNOrg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolSvcMNOrg();

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

ubigint PgTblFmncQTolSvcMNOrg::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolSvcMNOrg* rec;

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
			rec = new FmncQTolSvcMNOrg();

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

bool PgTblFmncQTolSvcMNOrg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolSvcMNOrg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolSvcMNOrg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolSvcMNOrg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolSvcMNOrg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolSvcMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQTolSvcMNOrg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolSvcMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolSvcMNOrg::insertRec(
			FmncQTolSvcMNOrg* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTolSvcMNOrg_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolSvcMNOrg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolSvcMNOrg::insertRst(
			ListFmncQTolSvcMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolSvcMNOrg::updateRec(
			FmncQTolSvcMNOrg* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTolSvcMNOrg_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolSvcMNOrg_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolSvcMNOrg::updateRst(
			ListFmncQTolSvcMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolSvcMNOrg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolSvcMNOrg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolSvcMNOrg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolSvcMNOrg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolSvcMNOrg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolSvcMNOrg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolSvcMNOrg::loadRecByQref(
			ubigint qref
			, FmncQTolSvcMNOrg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolSvcMNOrg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolSvcMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolSvcMNOrg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolSvcMNOrg_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

