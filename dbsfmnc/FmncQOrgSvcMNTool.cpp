/**
  * \file FmncQOrgSvcMNTool.cpp
  * Dbs and XML wrapper for table TblFmncQOrgSvcMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgSvcMNTool.h"

/******************************************************************************
 class FmncQOrgSvcMNTool
 ******************************************************************************/

FmncQOrgSvcMNTool::FmncQOrgSvcMNTool(
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

void FmncQOrgSvcMNTool::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrgSvcMNTool";

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
 class ListFmncQOrgSvcMNTool
 ******************************************************************************/

ListFmncQOrgSvcMNTool::ListFmncQOrgSvcMNTool() {
};

ListFmncQOrgSvcMNTool::ListFmncQOrgSvcMNTool(
			const ListFmncQOrgSvcMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSvcMNTool(*(src.nodes[i]));
};

ListFmncQOrgSvcMNTool::~ListFmncQOrgSvcMNTool() {
	clear();
};

void ListFmncQOrgSvcMNTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrgSvcMNTool::size() const {
	return(nodes.size());
};

void ListFmncQOrgSvcMNTool::append(
			FmncQOrgSvcMNTool* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrgSvcMNTool& ListFmncQOrgSvcMNTool::operator=(
			const ListFmncQOrgSvcMNTool& src
		) {
	FmncQOrgSvcMNTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrgSvcMNTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrgSvcMNTool::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrgSvcMNTool";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrgSvcMNTool
 ******************************************************************************/

TblFmncQOrgSvcMNTool::TblFmncQOrgSvcMNTool() {
};

TblFmncQOrgSvcMNTool::~TblFmncQOrgSvcMNTool() {
};

bool TblFmncQOrgSvcMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgSvcMNTool** rec
		) {
	return false;
};

ubigint TblFmncQOrgSvcMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	return 0;
};

void TblFmncQOrgSvcMNTool::insertRec(
			FmncQOrgSvcMNTool* rec
		) {
};

ubigint TblFmncQOrgSvcMNTool::insertNewRec(
			FmncQOrgSvcMNTool** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMPerson
			, const ubigint ref
		) {
	ubigint retval = 0;
	FmncQOrgSvcMNTool* _rec = NULL;

	_rec = new FmncQOrgSvcMNTool(0, jref, jnum, mref, stubMref, stubsTrefFmncMPerson, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrgSvcMNTool::appendNewRecToRst(
			ListFmncQOrgSvcMNTool& rst
			, FmncQOrgSvcMNTool** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMPerson
			, const ubigint ref
		) {
	ubigint retval = 0;
	FmncQOrgSvcMNTool* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, stubsTrefFmncMPerson, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrgSvcMNTool::insertRst(
			ListFmncQOrgSvcMNTool& rst
		) {
};

void TblFmncQOrgSvcMNTool::updateRec(
			FmncQOrgSvcMNTool* rec
		) {
};

void TblFmncQOrgSvcMNTool::updateRst(
			ListFmncQOrgSvcMNTool& rst
		) {
};

void TblFmncQOrgSvcMNTool::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrgSvcMNTool::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrgSvcMNTool::loadRecByQref(
			ubigint qref
			, FmncQOrgSvcMNTool** rec
		) {
	return false;
};

ubigint TblFmncQOrgSvcMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrgSvcMNTool
 ******************************************************************************/

MyTblFmncQOrgSvcMNTool::MyTblFmncQOrgSvcMNTool() : TblFmncQOrgSvcMNTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrgSvcMNTool::~MyTblFmncQOrgSvcMNTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrgSvcMNTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrgSvcMNTool (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrgSvcMNTool SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrgSvcMNTool WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrgSvcMNTool WHERE jref = ?", false);
};

bool MyTblFmncQOrgSvcMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgSvcMNTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrgSvcMNTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgSvcMNTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrgSvcMNTool();

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

ubigint MyTblFmncQOrgSvcMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrgSvcMNTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgSvcMNTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrgSvcMNTool();

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

void MyTblFmncQOrgSvcMNTool::insertRec(
			FmncQOrgSvcMNTool* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSvcMNTool / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSvcMNTool / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrgSvcMNTool::insertRst(
			ListFmncQOrgSvcMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrgSvcMNTool::updateRec(
			FmncQOrgSvcMNTool* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSvcMNTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSvcMNTool / stmtUpdateRec)\n");
};

void MyTblFmncQOrgSvcMNTool::updateRst(
			ListFmncQOrgSvcMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrgSvcMNTool::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSvcMNTool / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSvcMNTool / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrgSvcMNTool::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgSvcMNTool / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgSvcMNTool / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrgSvcMNTool::loadRecByQref(
			ubigint qref
			, FmncQOrgSvcMNTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrgSvcMNTool WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrgSvcMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrgSvcMNTool WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrgSvcMNTool
 ******************************************************************************/

PgTblFmncQOrgSvcMNTool::PgTblFmncQOrgSvcMNTool() : TblFmncQOrgSvcMNTool(), PgTable() {
};

PgTblFmncQOrgSvcMNTool::~PgTblFmncQOrgSvcMNTool() {
};

void PgTblFmncQOrgSvcMNTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrgSvcMNTool_insertRec", "INSERT INTO TblFmncQOrgSvcMNTool (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSvcMNTool_updateRec", "UPDATE TblFmncQOrgSvcMNTool SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSvcMNTool_removeRecByQref", "DELETE FROM TblFmncQOrgSvcMNTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSvcMNTool_removeRstByJref", "DELETE FROM TblFmncQOrgSvcMNTool WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrgSvcMNTool_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblFmncQOrgSvcMNTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgSvcMNTool_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblFmncQOrgSvcMNTool WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrgSvcMNTool::loadRec(
			PGresult* res
			, FmncQOrgSvcMNTool** rec
		) {
	char* ptr;

	FmncQOrgSvcMNTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrgSvcMNTool();

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

ubigint PgTblFmncQOrgSvcMNTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrgSvcMNTool* rec;

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
			rec = new FmncQOrgSvcMNTool();

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

bool PgTblFmncQOrgSvcMNTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrgSvcMNTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSvcMNTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgSvcMNTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSvcMNTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrgSvcMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgSvcMNTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgSvcMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrgSvcMNTool::insertRec(
			FmncQOrgSvcMNTool* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSvcMNTool_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSvcMNTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrgSvcMNTool::insertRst(
			ListFmncQOrgSvcMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrgSvcMNTool::updateRec(
			FmncQOrgSvcMNTool* rec
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSvcMNTool_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSvcMNTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrgSvcMNTool::updateRst(
			ListFmncQOrgSvcMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrgSvcMNTool::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSvcMNTool_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSvcMNTool_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrgSvcMNTool::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgSvcMNTool_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgSvcMNTool_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrgSvcMNTool::loadRecByQref(
			ubigint qref
			, FmncQOrgSvcMNTool** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrgSvcMNTool_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrgSvcMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgSvcMNTool& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrgSvcMNTool_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

