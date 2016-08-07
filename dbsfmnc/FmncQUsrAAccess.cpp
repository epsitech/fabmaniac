/**
  * \file FmncQUsrAAccess.cpp
  * Dbs and XML wrapper for table TblFmncQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsrAAccess.h"

/******************************************************************************
 class FmncQUsrAAccess
 ******************************************************************************/

FmncQUsrAAccess::FmncQUsrAAccess(
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

void FmncQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQUsrAAccess";

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
 class ListFmncQUsrAAccess
 ******************************************************************************/

ListFmncQUsrAAccess::ListFmncQUsrAAccess() {
};

ListFmncQUsrAAccess::ListFmncQUsrAAccess(
			const ListFmncQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrAAccess(*(src.nodes[i]));
};

ListFmncQUsrAAccess::~ListFmncQUsrAAccess() {
	clear();
};

void ListFmncQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQUsrAAccess::size() const {
	return(nodes.size());
};

void ListFmncQUsrAAccess::append(
			FmncQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListFmncQUsrAAccess& ListFmncQUsrAAccess::operator=(
			const ListFmncQUsrAAccess& src
		) {
	FmncQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQUsrAAccess
 ******************************************************************************/

TblFmncQUsrAAccess::TblFmncQUsrAAccess() {
};

TblFmncQUsrAAccess::~TblFmncQUsrAAccess() {
};

bool TblFmncQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrAAccess** rec
		) {
	return false;
};

ubigint TblFmncQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	return 0;
};

void TblFmncQUsrAAccess::insertRec(
			FmncQUsrAAccess* rec
		) {
};

ubigint TblFmncQUsrAAccess::insertNewRec(
			FmncQUsrAAccess** rec
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
	FmncQUsrAAccess* _rec = NULL;

	_rec = new FmncQUsrAAccess(0, jref, jnum, ref, x1IxFmncVCard, srefX1IxFmncVCard, titX1IxFmncVCard, ixFmncWUiaccess, srefsIxFmncWUiaccess, titsIxFmncWUiaccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQUsrAAccess::appendNewRecToRst(
			ListFmncQUsrAAccess& rst
			, FmncQUsrAAccess** rec
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
	FmncQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxFmncVCard, srefX1IxFmncVCard, titX1IxFmncVCard, ixFmncWUiaccess, srefsIxFmncWUiaccess, titsIxFmncWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQUsrAAccess::insertRst(
			ListFmncQUsrAAccess& rst
		) {
};

void TblFmncQUsrAAccess::updateRec(
			FmncQUsrAAccess* rec
		) {
};

void TblFmncQUsrAAccess::updateRst(
			ListFmncQUsrAAccess& rst
		) {
};

void TblFmncQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQUsrAAccess::loadRecByQref(
			ubigint qref
			, FmncQUsrAAccess** rec
		) {
	return false;
};

ubigint TblFmncQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQUsrAAccess
 ******************************************************************************/

MyTblFmncQUsrAAccess::MyTblFmncQUsrAAccess() : TblFmncQUsrAAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQUsrAAccess::~MyTblFmncQUsrAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQUsrAAccess (jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQUsrAAccess SET jref = ?, jnum = ?, ref = ?, x1IxFmncVCard = ?, ixFmncWUiaccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQUsrAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQUsrAAccess WHERE jref = ?", false);
};

bool MyTblFmncQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQUsrAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsrAAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQUsrAAccess();

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

ubigint MyTblFmncQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQUsrAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsrAAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQUsrAAccess();

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

void MyTblFmncQUsrAAccess::insertRec(
			FmncQUsrAAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxFmncVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixFmncWUiaccess,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrAAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrAAccess / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQUsrAAccess::insertRst(
			ListFmncQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQUsrAAccess::updateRec(
			FmncQUsrAAccess* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrAAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrAAccess / stmtUpdateRec)\n");
};

void MyTblFmncQUsrAAccess::updateRst(
			ListFmncQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrAAccess / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrAAccess / stmtRemoveRecByQref)\n");
};

void MyTblFmncQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrAAccess / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrAAccess / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQUsrAAccess::loadRecByQref(
			ubigint qref
			, FmncQUsrAAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQUsrAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQUsrAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQUsrAAccess
 ******************************************************************************/

PgTblFmncQUsrAAccess::PgTblFmncQUsrAAccess() : TblFmncQUsrAAccess(), PgTable() {
};

PgTblFmncQUsrAAccess::~PgTblFmncQUsrAAccess() {
};

void PgTblFmncQUsrAAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQUsrAAccess_insertRec", "INSERT INTO TblFmncQUsrAAccess (jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrAAccess_updateRec", "UPDATE TblFmncQUsrAAccess SET jref = $1, jnum = $2, ref = $3, x1IxFmncVCard = $4, ixFmncWUiaccess = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrAAccess_removeRecByQref", "DELETE FROM TblFmncQUsrAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrAAccess_removeRstByJref", "DELETE FROM TblFmncQUsrAAccess WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQUsrAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncQUsrAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncQUsrAAccess WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQUsrAAccess::loadRec(
			PGresult* res
			, FmncQUsrAAccess** rec
		) {
	char* ptr;

	FmncQUsrAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQUsrAAccess();

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

ubigint PgTblFmncQUsrAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQUsrAAccess* rec;

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
			rec = new FmncQUsrAAccess();

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

bool PgTblFmncQUsrAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrAAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsrAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrAAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQUsrAAccess::insertRec(
			FmncQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblFmncQUsrAAccess_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrAAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQUsrAAccess::insertRst(
			ListFmncQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQUsrAAccess::updateRec(
			FmncQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblFmncQUsrAAccess_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrAAccess_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQUsrAAccess::updateRst(
			ListFmncQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQUsrAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsrAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrAAccess_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQUsrAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsrAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrAAccess_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQUsrAAccess::loadRecByQref(
			ubigint qref
			, FmncQUsrAAccess** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQUsrAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQUsrAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

