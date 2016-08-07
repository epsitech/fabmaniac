/**
  * \file FmncQUsgAAccess.cpp
  * Dbs and XML wrapper for table TblFmncQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsgAAccess.h"

/******************************************************************************
 class FmncQUsgAAccess
 ******************************************************************************/

FmncQUsgAAccess::FmncQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxFmncVCard
			, const string srefX1IxFmncVCard
			, const string titX1IxFmncVCard
			, const uint ixFmncWUiaccess
			, const string srefsIxFmncWUiaccess
			, const string titsIxFmncWUiaccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxFmncVCard = x1IxFmncVCard;
	this->srefX1IxFmncVCard = srefX1IxFmncVCard;
	this->titX1IxFmncVCard = titX1IxFmncVCard;
	this->ixFmncWUiaccess = ixFmncWUiaccess;
	this->srefsIxFmncWUiaccess = srefsIxFmncWUiaccess;
	this->titsIxFmncWUiaccess = titsIxFmncWUiaccess;
};

void FmncQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "crd", srefX1IxFmncVCard);
		writeString(wr, "crd2", titX1IxFmncVCard);
		writeString(wr, "uac", srefsIxFmncWUiaccess);
		writeString(wr, "uac2", titsIxFmncWUiaccess);
	} else {
		writeString(wr, "srefX1IxFmncVCard", srefX1IxFmncVCard);
		writeString(wr, "titX1IxFmncVCard", titX1IxFmncVCard);
		writeString(wr, "srefsIxFmncWUiaccess", srefsIxFmncWUiaccess);
		writeString(wr, "titsIxFmncWUiaccess", titsIxFmncWUiaccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQUsgAAccess
 ******************************************************************************/

ListFmncQUsgAAccess::ListFmncQUsgAAccess() {
};

ListFmncQUsgAAccess::ListFmncQUsgAAccess(
			const ListFmncQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsgAAccess(*(src.nodes[i]));
};

ListFmncQUsgAAccess::~ListFmncQUsgAAccess() {
	clear();
};

void ListFmncQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQUsgAAccess::size() const {
	return(nodes.size());
};

void ListFmncQUsgAAccess::append(
			FmncQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListFmncQUsgAAccess& ListFmncQUsgAAccess::operator=(
			const ListFmncQUsgAAccess& src
		) {
	FmncQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQUsgAAccess
 ******************************************************************************/

TblFmncQUsgAAccess::TblFmncQUsgAAccess() {
};

TblFmncQUsgAAccess::~TblFmncQUsgAAccess() {
};

bool TblFmncQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, FmncQUsgAAccess** rec
		) {
	return false;
};

ubigint TblFmncQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	return 0;
};

void TblFmncQUsgAAccess::insertRec(
			FmncQUsgAAccess* rec
		) {
};

ubigint TblFmncQUsgAAccess::insertNewRec(
			FmncQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxFmncVCard
			, const string srefX1IxFmncVCard
			, const string titX1IxFmncVCard
			, const uint ixFmncWUiaccess
			, const string srefsIxFmncWUiaccess
			, const string titsIxFmncWUiaccess
		) {
	ubigint retval = 0;
	FmncQUsgAAccess* _rec = NULL;

	_rec = new FmncQUsgAAccess(0, jref, jnum, ref, x1IxFmncVCard, srefX1IxFmncVCard, titX1IxFmncVCard, ixFmncWUiaccess, srefsIxFmncWUiaccess, titsIxFmncWUiaccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQUsgAAccess::appendNewRecToRst(
			ListFmncQUsgAAccess& rst
			, FmncQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxFmncVCard
			, const string srefX1IxFmncVCard
			, const string titX1IxFmncVCard
			, const uint ixFmncWUiaccess
			, const string srefsIxFmncWUiaccess
			, const string titsIxFmncWUiaccess
		) {
	ubigint retval = 0;
	FmncQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxFmncVCard, srefX1IxFmncVCard, titX1IxFmncVCard, ixFmncWUiaccess, srefsIxFmncWUiaccess, titsIxFmncWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQUsgAAccess::insertRst(
			ListFmncQUsgAAccess& rst
		) {
};

void TblFmncQUsgAAccess::updateRec(
			FmncQUsgAAccess* rec
		) {
};

void TblFmncQUsgAAccess::updateRst(
			ListFmncQUsgAAccess& rst
		) {
};

void TblFmncQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQUsgAAccess::loadRecByQref(
			ubigint qref
			, FmncQUsgAAccess** rec
		) {
	return false;
};

ubigint TblFmncQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQUsgAAccess
 ******************************************************************************/

MyTblFmncQUsgAAccess::MyTblFmncQUsgAAccess() : TblFmncQUsgAAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQUsgAAccess::~MyTblFmncQUsgAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQUsgAAccess (jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQUsgAAccess SET jref = ?, jnum = ?, ref = ?, x1IxFmncVCard = ?, ixFmncWUiaccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQUsgAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQUsgAAccess WHERE jref = ?", false);
};

bool MyTblFmncQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, FmncQUsgAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQUsgAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsgAAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQUsgAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxFmncVCard = atol((char*) dbrow[4]); else _rec->x1IxFmncVCard = 0;
		if (dbrow[5]) _rec->ixFmncWUiaccess = atol((char*) dbrow[5]); else _rec->ixFmncWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQUsgAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsgAAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQUsgAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxFmncVCard = atol((char*) dbrow[4]); else rec->x1IxFmncVCard = 0;
			if (dbrow[5]) rec->ixFmncWUiaccess = atol((char*) dbrow[5]); else rec->ixFmncWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQUsgAAccess::insertRec(
			FmncQUsgAAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxFmncVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixFmncWUiaccess,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgAAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgAAccess / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQUsgAAccess::insertRst(
			ListFmncQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQUsgAAccess::updateRec(
			FmncQUsgAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->x1IxFmncVCard,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixFmncWUiaccess,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgAAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgAAccess / stmtUpdateRec)\n");
};

void MyTblFmncQUsgAAccess::updateRst(
			ListFmncQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgAAccess / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgAAccess / stmtRemoveRecByQref)\n");
};

void MyTblFmncQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsgAAccess / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsgAAccess / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQUsgAAccess::loadRecByQref(
			ubigint qref
			, FmncQUsgAAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQUsgAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQUsgAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQUsgAAccess
 ******************************************************************************/

PgTblFmncQUsgAAccess::PgTblFmncQUsgAAccess() : TblFmncQUsgAAccess(), PgTable() {
};

PgTblFmncQUsgAAccess::~PgTblFmncQUsgAAccess() {
};

void PgTblFmncQUsgAAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQUsgAAccess_insertRec", "INSERT INTO TblFmncQUsgAAccess (jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgAAccess_updateRec", "UPDATE TblFmncQUsgAAccess SET jref = $1, jnum = $2, ref = $3, x1IxFmncVCard = $4, ixFmncWUiaccess = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgAAccess_removeRecByQref", "DELETE FROM TblFmncQUsgAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgAAccess_removeRstByJref", "DELETE FROM TblFmncQUsgAAccess WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQUsgAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncQUsgAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsgAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncQUsgAAccess WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQUsgAAccess::loadRec(
			PGresult* res
			, FmncQUsgAAccess** rec
		) {
	char* ptr;

	FmncQUsgAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQUsgAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixfmncvcard"),
			PQfnumber(res, "ixfmncwuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxFmncVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixFmncWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQUsgAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQUsgAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixfmncvcard"),
			PQfnumber(res, "ixfmncwuiaccess")
		};

		while (numread < numrow) {
			rec = new FmncQUsgAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxFmncVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixFmncWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQUsgAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgAAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsgAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgAAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, FmncQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQUsgAAccess::insertRec(
			FmncQUsgAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxFmncVCard = htonl(rec->x1IxFmncVCard);
	uint _ixFmncWUiaccess = htonl(rec->ixFmncWUiaccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxFmncVCard,
		(char*) &_ixFmncWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQUsgAAccess_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgAAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQUsgAAccess::insertRst(
			ListFmncQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQUsgAAccess::updateRec(
			FmncQUsgAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxFmncVCard = htonl(rec->x1IxFmncVCard);
	uint _ixFmncWUiaccess = htonl(rec->ixFmncWUiaccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxFmncVCard,
		(char*) &_ixFmncWUiaccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQUsgAAccess_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgAAccess_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQUsgAAccess::updateRst(
			ListFmncQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQUsgAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsgAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgAAccess_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQUsgAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsgAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsgAAccess_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQUsgAAccess::loadRecByQref(
			ubigint qref
			, FmncQUsgAAccess** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQUsgAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsgAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQUsgAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

