/**
  * \file FmncQUsgMNUser.cpp
  * Dbs and XML wrapper for table TblFmncQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsgMNUser.h"

/******************************************************************************
 class FmncQUsgMNUser
 ******************************************************************************/

FmncQUsgMNUser::FmncQUsgMNUser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixFmncVUserlevel
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixFmncVUserlevel = ixFmncVUserlevel;
	this->srefIxFmncVUserlevel = srefIxFmncVUserlevel;
	this->titIxFmncVUserlevel = titIxFmncVUserlevel;
};

void FmncQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQUsgMNUser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxFmncVUserlevel);
		writeString(wr, "ulv2", titIxFmncVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxFmncVUserlevel", srefIxFmncVUserlevel);
		writeString(wr, "titIxFmncVUserlevel", titIxFmncVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQUsgMNUser
 ******************************************************************************/

ListFmncQUsgMNUser::ListFmncQUsgMNUser() {
};

ListFmncQUsgMNUser::ListFmncQUsgMNUser(
			const ListFmncQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsgMNUser(*(src.nodes[i]));
};

ListFmncQUsgMNUser::~ListFmncQUsgMNUser() {
	clear();
};

void ListFmncQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQUsgMNUser::size() const {
	return(nodes.size());
};

void ListFmncQUsgMNUser::append(
			FmncQUsgMNUser* rec
		) {
	nodes.push_back(rec);
};

ListFmncQUsgMNUser& ListFmncQUsgMNUser::operator=(
			const ListFmncQUsgMNUser& src
		) {
	FmncQUsgMNUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQUsgMNUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQUsgMNUser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQUsgMNUser
 ******************************************************************************/

TblFmncQUsgMNUser::TblFmncQUsgMNUser() {
};

TblFmncQUsgMNUser::~TblFmncQUsgMNUser() {
};

bool TblFmncQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, FmncQUsgMNUser** rec
		) {
	return false;
};

ubigint TblFmncQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	return 0;
};

void TblFmncQUsgMNUser::insertRec(
			FmncQUsgMNUser* rec
		) {
};

ubigint TblFmncQUsgMNUser::insertNewRec(
			FmncQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixFmncVUserlevel
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	ubigint retval = 0;
	FmncQUsgMNUser* _rec = NULL;

	_rec = new FmncQUsgMNUser(0, jref, jnum, mref, stubMref, ref, ixFmncVUserlevel, srefIxFmncVUserlevel, titIxFmncVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQUsgMNUser::appendNewRecToRst(
			ListFmncQUsgMNUser& rst
			, FmncQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixFmncVUserlevel
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	ubigint retval = 0;
	FmncQUsgMNUser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixFmncVUserlevel, srefIxFmncVUserlevel, titIxFmncVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQUsgMNUser::insertRst(
			ListFmncQUsgMNUser& rst
		) {
};

void TblFmncQUsgMNUser::updateRec(
			FmncQUsgMNUser* rec
		) {
};

void TblFmncQUsgMNUser::updateRst(
			ListFmncQUsgMNUser& rst
		) {
};

void TblFmncQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQUsgMNUser::loadRecByQref(
			ubigint qref
			, FmncQUsgMNUser** rec
		) {
	return false;
};

ubigint TblFmncQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQUsgMNUser
 ******************************************************************************/

MyTblFmncQUsgMNUser::MyTblFmncQUsgMNUser() : TblFmncQUsgMNUser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQUsgMNUser::~MyTblFmncQUsgMNUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQUsgMNUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQUsgMNUser (jref, jnum, mref, ref, ixFmncVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQUsgMNUser SET jref = ?, jnum = ?, mref = ?, ref = ?, ixFmncVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQUsgMNUser WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQUsgMNUser WHERE jref = ?", false);
};

bool MyTblFmncQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, FmncQUsgMNUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQUsgMNUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsgMNUser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQUsgMNUser();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixFmncVUserlevel = atol((char*) dbrow[5]); else _rec->ixFmncVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQUsgMNUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsgMNUser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQUsgMNUser();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixFmncVUserlevel = atol((char*) dbrow[5]); else rec->ixFmncVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQUsgMNUser::insertRec(
			FmncQUsgMNUser* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixFmncVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgMNUser / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgMNUser / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQUsgMNUser::insertRst(
			ListFmncQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQUsgMNUser::updateRec(
			FmncQUsgMNUser* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixFmncVUserlevel,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgMNUser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgMNUser / stmtUpdateRec)\n");
};

void MyTblFmncQUsgMNUser::updateRst(
			ListFmncQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgMNUser / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgMNUser / stmtRemoveRecByQref)\n");
};

void MyTblFmncQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgMNUser / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgMNUser / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQUsgMNUser::loadRecByQref(
			ubigint qref
			, FmncQUsgMNUser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQUsgMNUser WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQUsgMNUser WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQUsgMNUser
 ******************************************************************************/

PgTblFmncQUsgMNUser::PgTblFmncQUsgMNUser() : TblFmncQUsgMNUser(), PgTable() {
};

PgTblFmncQUsgMNUser::~PgTblFmncQUsgMNUser() {
};

void PgTblFmncQUsgMNUser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQUsgMNUser_insertRec", "INSERT INTO TblFmncQUsgMNUser (jref, jnum, mref, ref, ixFmncVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgMNUser_updateRec", "UPDATE TblFmncQUsgMNUser SET jref = $1, jnum = $2, mref = $3, ref = $4, ixFmncVUserlevel = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgMNUser_removeRecByQref", "DELETE FROM TblFmncQUsgMNUser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgMNUser_removeRstByJref", "DELETE FROM TblFmncQUsgMNUser WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQUsgMNUser_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixFmncVUserlevel FROM TblFmncQUsgMNUser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgMNUser_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixFmncVUserlevel FROM TblFmncQUsgMNUser WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQUsgMNUser::loadRec(
			PGresult* res
			, FmncQUsgMNUser** rec
		) {
	char* ptr;

	FmncQUsgMNUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQUsgMNUser();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixfmncvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixFmncVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQUsgMNUser::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQUsgMNUser* rec;

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
			PQfnumber(res, "ixfmncvuserlevel")
		};

		while (numread < numrow) {
			rec = new FmncQUsgMNUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixFmncVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQUsgMNUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQUsgMNUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgMNUser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsgMNUser::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgMNUser / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, FmncQUsgMNUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQUsgMNUser::insertRec(
			FmncQUsgMNUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixFmncVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQUsgMNUser_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgMNUser_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQUsgMNUser::insertRst(
			ListFmncQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQUsgMNUser::updateRec(
			FmncQUsgMNUser* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixFmncVUserlevel,
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

	res = PQexecPrepared(dbs, "TblFmncQUsgMNUser_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgMNUser_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQUsgMNUser::updateRst(
			ListFmncQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQUsgMNUser::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsgMNUser_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgMNUser_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQUsgMNUser::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsgMNUser_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgMNUser_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQUsgMNUser::loadRecByQref(
			ubigint qref
			, FmncQUsgMNUser** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQUsgMNUser_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsgMNUser& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQUsgMNUser_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

