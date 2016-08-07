/**
  * \file FmncQRunList.cpp
  * Dbs and XML wrapper for table TblFmncQRunList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQRunList.h"

/******************************************************************************
 class FmncQRunList
 ******************************************************************************/

FmncQRunList::FmncQRunList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refFmncMProject
			, const string stubRefFmncMProject
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->refFmncMProject = refFmncMProject;
	this->stubRefFmncMProject = stubRefFmncMProject;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

void FmncQRunList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQRunList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "prj", stubRefFmncMProject);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefFmncMProject", stubRefFmncMProject);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQRunList
 ******************************************************************************/

ListFmncQRunList::ListFmncQRunList() {
};

ListFmncQRunList::ListFmncQRunList(
			const ListFmncQRunList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunList(*(src.nodes[i]));
};

ListFmncQRunList::~ListFmncQRunList() {
	clear();
};

void ListFmncQRunList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQRunList::size() const {
	return(nodes.size());
};

void ListFmncQRunList::append(
			FmncQRunList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQRunList& ListFmncQRunList::operator=(
			const ListFmncQRunList& src
		) {
	FmncQRunList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQRunList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQRunList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQRunList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQRunList
 ******************************************************************************/

TblFmncQRunList::TblFmncQRunList() {
};

TblFmncQRunList::~TblFmncQRunList() {
};

bool TblFmncQRunList::loadRecBySQL(
			const string& sqlstr
			, FmncQRunList** rec
		) {
	return false;
};

ubigint TblFmncQRunList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQRunList& rst
		) {
	return 0;
};

void TblFmncQRunList::insertRec(
			FmncQRunList* rec
		) {
};

ubigint TblFmncQRunList::insertNewRec(
			FmncQRunList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refFmncMProject
			, const string stubRefFmncMProject
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQRunList* _rec = NULL;

	_rec = new FmncQRunList(0, jref, jnum, ref, Title, refFmncMProject, stubRefFmncMProject, ixVState, srefIxVState, titIxVState);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQRunList::appendNewRecToRst(
			ListFmncQRunList& rst
			, FmncQRunList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refFmncMProject
			, const string stubRefFmncMProject
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQRunList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, refFmncMProject, stubRefFmncMProject, ixVState, srefIxVState, titIxVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQRunList::insertRst(
			ListFmncQRunList& rst
		) {
};

void TblFmncQRunList::updateRec(
			FmncQRunList* rec
		) {
};

void TblFmncQRunList::updateRst(
			ListFmncQRunList& rst
		) {
};

void TblFmncQRunList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQRunList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQRunList::loadRecByQref(
			ubigint qref
			, FmncQRunList** rec
		) {
	return false;
};

ubigint TblFmncQRunList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQRunList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQRunList
 ******************************************************************************/

MyTblFmncQRunList::MyTblFmncQRunList() : TblFmncQRunList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQRunList::~MyTblFmncQRunList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQRunList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQRunList (jref, jnum, ref, Title, refFmncMProject, ixVState) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQRunList SET jref = ?, jnum = ?, ref = ?, Title = ?, refFmncMProject = ?, ixVState = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQRunList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQRunList WHERE jref = ?", false);
};

bool MyTblFmncQRunList::loadRecBySQL(
			const string& sqlstr
			, FmncQRunList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQRunList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQRunList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQRunList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->refFmncMProject = atoll((char*) dbrow[5]); else _rec->refFmncMProject = 0;
		if (dbrow[6]) _rec->ixVState = atol((char*) dbrow[6]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQRunList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQRunList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQRunList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQRunList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQRunList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->refFmncMProject = atoll((char*) dbrow[5]); else rec->refFmncMProject = 0;
			if (dbrow[6]) rec->ixVState = atol((char*) dbrow[6]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQRunList::insertRec(
			FmncQRunList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMProject,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVState,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQRunList::insertRst(
			ListFmncQRunList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQRunList::updateRec(
			FmncQRunList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMProject,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVState,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunList / stmtUpdateRec)\n");
};

void MyTblFmncQRunList::updateRst(
			ListFmncQRunList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQRunList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQRunList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQRunList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQRunList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQRunList::loadRecByQref(
			ubigint qref
			, FmncQRunList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQRunList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQRunList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQRunList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQRunList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQRunList
 ******************************************************************************/

PgTblFmncQRunList::PgTblFmncQRunList() : TblFmncQRunList(), PgTable() {
};

PgTblFmncQRunList::~PgTblFmncQRunList() {
};

void PgTblFmncQRunList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQRunList_insertRec", "INSERT INTO TblFmncQRunList (jref, jnum, ref, Title, refFmncMProject, ixVState) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunList_updateRec", "UPDATE TblFmncQRunList SET jref = $1, jnum = $2, ref = $3, Title = $4, refFmncMProject = $5, ixVState = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunList_removeRecByQref", "DELETE FROM TblFmncQRunList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunList_removeRstByJref", "DELETE FROM TblFmncQRunList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQRunList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, refFmncMProject, ixVState FROM TblFmncQRunList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQRunList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, refFmncMProject, ixVState FROM TblFmncQRunList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQRunList::loadRec(
			PGresult* res
			, FmncQRunList** rec
		) {
	char* ptr;

	FmncQRunList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQRunList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "reffmncmproject"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQRunList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQRunList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQRunList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "reffmncmproject"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncQRunList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQRunList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQRunList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQRunList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQRunList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQRunList::loadRecBySQL(
			const string& sqlstr
			, FmncQRunList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQRunList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQRunList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQRunList::insertRec(
			FmncQRunList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMProject = htonl64(rec->refFmncMProject);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refFmncMProject,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQRunList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQRunList::insertRst(
			ListFmncQRunList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQRunList::updateRec(
			FmncQRunList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMProject = htonl64(rec->refFmncMProject);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refFmncMProject,
		(char*) &_ixVState,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQRunList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQRunList::updateRst(
			ListFmncQRunList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQRunList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQRunList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQRunList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQRunList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQRunList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQRunList::loadRecByQref(
			ubigint qref
			, FmncQRunList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQRunList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQRunList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQRunList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQRunList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

