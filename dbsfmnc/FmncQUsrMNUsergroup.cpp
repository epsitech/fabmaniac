/**
  * \file FmncQUsrMNUsergroup.cpp
  * Dbs and XML wrapper for table TblFmncQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsrMNUsergroup.h"

/******************************************************************************
 class FmncQUsrMNUsergroup
 ******************************************************************************/

FmncQUsrMNUsergroup::FmncQUsrMNUsergroup(
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

void FmncQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQUsrMNUsergroup";

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
 class ListFmncQUsrMNUsergroup
 ******************************************************************************/

ListFmncQUsrMNUsergroup::ListFmncQUsrMNUsergroup() {
};

ListFmncQUsrMNUsergroup::ListFmncQUsrMNUsergroup(
			const ListFmncQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrMNUsergroup(*(src.nodes[i]));
};

ListFmncQUsrMNUsergroup::~ListFmncQUsrMNUsergroup() {
	clear();
};

void ListFmncQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQUsrMNUsergroup::size() const {
	return(nodes.size());
};

void ListFmncQUsrMNUsergroup::append(
			FmncQUsrMNUsergroup* rec
		) {
	nodes.push_back(rec);
};

ListFmncQUsrMNUsergroup& ListFmncQUsrMNUsergroup::operator=(
			const ListFmncQUsrMNUsergroup& src
		) {
	FmncQUsrMNUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQUsrMNUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQUsrMNUsergroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQUsrMNUsergroup
 ******************************************************************************/

TblFmncQUsrMNUsergroup::TblFmncQUsrMNUsergroup() {
};

TblFmncQUsrMNUsergroup::~TblFmncQUsrMNUsergroup() {
};

bool TblFmncQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblFmncQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	return 0;
};

void TblFmncQUsrMNUsergroup::insertRec(
			FmncQUsrMNUsergroup* rec
		) {
};

ubigint TblFmncQUsrMNUsergroup::insertNewRec(
			FmncQUsrMNUsergroup** rec
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
	FmncQUsrMNUsergroup* _rec = NULL;

	_rec = new FmncQUsrMNUsergroup(0, jref, jnum, mref, stubMref, ref, ixFmncVUserlevel, srefIxFmncVUserlevel, titIxFmncVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQUsrMNUsergroup::appendNewRecToRst(
			ListFmncQUsrMNUsergroup& rst
			, FmncQUsrMNUsergroup** rec
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
	FmncQUsrMNUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixFmncVUserlevel, srefIxFmncVUserlevel, titIxFmncVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQUsrMNUsergroup::insertRst(
			ListFmncQUsrMNUsergroup& rst
		) {
};

void TblFmncQUsrMNUsergroup::updateRec(
			FmncQUsrMNUsergroup* rec
		) {
};

void TblFmncQUsrMNUsergroup::updateRst(
			ListFmncQUsrMNUsergroup& rst
		) {
};

void TblFmncQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, FmncQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblFmncQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQUsrMNUsergroup
 ******************************************************************************/

MyTblFmncQUsrMNUsergroup::MyTblFmncQUsrMNUsergroup() : TblFmncQUsrMNUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQUsrMNUsergroup::~MyTblFmncQUsrMNUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQUsrMNUsergroup (jref, jnum, mref, ref, ixFmncVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQUsrMNUsergroup SET jref = ?, jnum = ?, mref = ?, ref = ?, ixFmncVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQUsrMNUsergroup WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQUsrMNUsergroup WHERE jref = ?", false);
};

bool MyTblFmncQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrMNUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQUsrMNUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsrMNUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQUsrMNUsergroup();

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

ubigint MyTblFmncQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsrMNUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQUsrMNUsergroup();

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

void MyTblFmncQUsrMNUsergroup::insertRec(
			FmncQUsrMNUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixFmncVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrMNUsergroup / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrMNUsergroup / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQUsrMNUsergroup::insertRst(
			ListFmncQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQUsrMNUsergroup::updateRec(
			FmncQUsrMNUsergroup* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrMNUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrMNUsergroup / stmtUpdateRec)\n");
};

void MyTblFmncQUsrMNUsergroup::updateRst(
			ListFmncQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrMNUsergroup / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrMNUsergroup / stmtRemoveRecByQref)\n");
};

void MyTblFmncQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrMNUsergroup / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrMNUsergroup / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, FmncQUsrMNUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQUsrMNUsergroup WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQUsrMNUsergroup WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQUsrMNUsergroup
 ******************************************************************************/

PgTblFmncQUsrMNUsergroup::PgTblFmncQUsrMNUsergroup() : TblFmncQUsrMNUsergroup(), PgTable() {
};

PgTblFmncQUsrMNUsergroup::~PgTblFmncQUsrMNUsergroup() {
};

void PgTblFmncQUsrMNUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQUsrMNUsergroup_insertRec", "INSERT INTO TblFmncQUsrMNUsergroup (jref, jnum, mref, ref, ixFmncVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrMNUsergroup_updateRec", "UPDATE TblFmncQUsrMNUsergroup SET jref = $1, jnum = $2, mref = $3, ref = $4, ixFmncVUserlevel = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrMNUsergroup_removeRecByQref", "DELETE FROM TblFmncQUsrMNUsergroup WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrMNUsergroup_removeRstByJref", "DELETE FROM TblFmncQUsrMNUsergroup WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQUsrMNUsergroup_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixFmncVUserlevel FROM TblFmncQUsrMNUsergroup WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrMNUsergroup_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixFmncVUserlevel FROM TblFmncQUsrMNUsergroup WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQUsrMNUsergroup::loadRec(
			PGresult* res
			, FmncQUsrMNUsergroup** rec
		) {
	char* ptr;

	FmncQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQUsrMNUsergroup();

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

ubigint PgTblFmncQUsrMNUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQUsrMNUsergroup* rec;

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
			rec = new FmncQUsrMNUsergroup();

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

bool PgTblFmncQUsrMNUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrMNUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsrMNUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrMNUsergroup / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQUsrMNUsergroup::insertRec(
			FmncQUsrMNUsergroup* rec
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

	res = PQexecPrepared(dbs, "TblFmncQUsrMNUsergroup_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrMNUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQUsrMNUsergroup::insertRst(
			ListFmncQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQUsrMNUsergroup::updateRec(
			FmncQUsrMNUsergroup* rec
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

	res = PQexecPrepared(dbs, "TblFmncQUsrMNUsergroup_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrMNUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQUsrMNUsergroup::updateRst(
			ListFmncQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQUsrMNUsergroup::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsrMNUsergroup_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrMNUsergroup_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQUsrMNUsergroup::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsrMNUsergroup_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrMNUsergroup_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, FmncQUsrMNUsergroup** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQUsrMNUsergroup_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrMNUsergroup& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQUsrMNUsergroup_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

