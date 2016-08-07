/**
  * \file FmncQTolAChar.cpp
  * Dbs and XML wrapper for table TblFmncQTolAChar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolAChar.h"

/******************************************************************************
 class FmncQTolAChar
 ******************************************************************************/

FmncQTolAChar::FmncQTolAChar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1OsrefFmncKToolchar
			, const string titX1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1OsrefFmncKToolchar = x1OsrefFmncKToolchar;
	this->titX1OsrefFmncKToolchar = titX1OsrefFmncKToolchar;
	this->Val = Val;
	this->Comment = Comment;
};

void FmncQTolAChar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolAChar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tch", x1OsrefFmncKToolchar);
		writeString(wr, "tch2", titX1OsrefFmncKToolchar);
		writeString(wr, "val", Val);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "x1OsrefFmncKToolchar", x1OsrefFmncKToolchar);
		writeString(wr, "titX1OsrefFmncKToolchar", titX1OsrefFmncKToolchar);
		writeString(wr, "Val", Val);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolAChar
 ******************************************************************************/

ListFmncQTolAChar::ListFmncQTolAChar() {
};

ListFmncQTolAChar::ListFmncQTolAChar(
			const ListFmncQTolAChar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAChar(*(src.nodes[i]));
};

ListFmncQTolAChar::~ListFmncQTolAChar() {
	clear();
};

void ListFmncQTolAChar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolAChar::size() const {
	return(nodes.size());
};

void ListFmncQTolAChar::append(
			FmncQTolAChar* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolAChar& ListFmncQTolAChar::operator=(
			const ListFmncQTolAChar& src
		) {
	FmncQTolAChar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolAChar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolAChar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolAChar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolAChar
 ******************************************************************************/

TblFmncQTolAChar::TblFmncQTolAChar() {
};

TblFmncQTolAChar::~TblFmncQTolAChar() {
};

bool TblFmncQTolAChar::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAChar** rec
		) {
	return false;
};

ubigint TblFmncQTolAChar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	return 0;
};

void TblFmncQTolAChar::insertRec(
			FmncQTolAChar* rec
		) {
};

ubigint TblFmncQTolAChar::insertNewRec(
			FmncQTolAChar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1OsrefFmncKToolchar
			, const string titX1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTolAChar* _rec = NULL;

	_rec = new FmncQTolAChar(0, jref, jnum, ref, x1OsrefFmncKToolchar, titX1OsrefFmncKToolchar, Val, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolAChar::appendNewRecToRst(
			ListFmncQTolAChar& rst
			, FmncQTolAChar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1OsrefFmncKToolchar
			, const string titX1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTolAChar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1OsrefFmncKToolchar, titX1OsrefFmncKToolchar, Val, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolAChar::insertRst(
			ListFmncQTolAChar& rst
		) {
};

void TblFmncQTolAChar::updateRec(
			FmncQTolAChar* rec
		) {
};

void TblFmncQTolAChar::updateRst(
			ListFmncQTolAChar& rst
		) {
};

void TblFmncQTolAChar::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolAChar::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolAChar::loadRecByQref(
			ubigint qref
			, FmncQTolAChar** rec
		) {
	return false;
};

ubigint TblFmncQTolAChar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolAChar
 ******************************************************************************/

MyTblFmncQTolAChar::MyTblFmncQTolAChar() : TblFmncQTolAChar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolAChar::~MyTblFmncQTolAChar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolAChar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolAChar (jref, jnum, ref, x1OsrefFmncKToolchar, Val, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolAChar SET jref = ?, jnum = ?, ref = ?, x1OsrefFmncKToolchar = ?, Val = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolAChar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolAChar WHERE jref = ?", false);
};

bool MyTblFmncQTolAChar::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAChar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolAChar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolAChar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolAChar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1OsrefFmncKToolchar.assign(dbrow[4], dblengths[4]); else _rec->x1OsrefFmncKToolchar = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolAChar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolAChar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolAChar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolAChar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1OsrefFmncKToolchar.assign(dbrow[4], dblengths[4]); else rec->x1OsrefFmncKToolchar = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolAChar::insertRec(
			FmncQTolAChar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1OsrefFmncKToolchar.length();
	l[4] = rec->Val.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1OsrefFmncKToolchar.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAChar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAChar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolAChar::insertRst(
			ListFmncQTolAChar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolAChar::updateRec(
			FmncQTolAChar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->x1OsrefFmncKToolchar.length();
	l[4] = rec->Val.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x1OsrefFmncKToolchar.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAChar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAChar / stmtUpdateRec)\n");
};

void MyTblFmncQTolAChar::updateRst(
			ListFmncQTolAChar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolAChar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAChar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAChar / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolAChar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAChar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAChar / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolAChar::loadRecByQref(
			ubigint qref
			, FmncQTolAChar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolAChar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolAChar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolAChar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolAChar
 ******************************************************************************/

PgTblFmncQTolAChar::PgTblFmncQTolAChar() : TblFmncQTolAChar(), PgTable() {
};

PgTblFmncQTolAChar::~PgTblFmncQTolAChar() {
};

void PgTblFmncQTolAChar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolAChar_insertRec", "INSERT INTO TblFmncQTolAChar (jref, jnum, ref, x1OsrefFmncKToolchar, Val, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAChar_updateRec", "UPDATE TblFmncQTolAChar SET jref = $1, jnum = $2, ref = $3, x1OsrefFmncKToolchar = $4, Val = $5, Comment = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAChar_removeRecByQref", "DELETE FROM TblFmncQTolAChar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAChar_removeRstByJref", "DELETE FROM TblFmncQTolAChar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolAChar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1OsrefFmncKToolchar, Val, Comment FROM TblFmncQTolAChar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAChar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1OsrefFmncKToolchar, Val, Comment FROM TblFmncQTolAChar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolAChar::loadRec(
			PGresult* res
			, FmncQTolAChar** rec
		) {
	char* ptr;

	FmncQTolAChar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolAChar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1osreffmncktoolchar"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1OsrefFmncKToolchar.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolAChar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolAChar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1osreffmncktoolchar"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncQTolAChar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1OsrefFmncKToolchar.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolAChar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolAChar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAChar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolAChar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAChar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolAChar::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAChar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolAChar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolAChar::insertRec(
			FmncQTolAChar* rec
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
		rec->x1OsrefFmncKToolchar.c_str(),
		rec->Val.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolAChar_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAChar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolAChar::insertRst(
			ListFmncQTolAChar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolAChar::updateRec(
			FmncQTolAChar* rec
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
		rec->x1OsrefFmncKToolchar.c_str(),
		rec->Val.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolAChar_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAChar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolAChar::updateRst(
			ListFmncQTolAChar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolAChar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolAChar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAChar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolAChar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolAChar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAChar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolAChar::loadRecByQref(
			ubigint qref
			, FmncQTolAChar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolAChar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolAChar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAChar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolAChar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

