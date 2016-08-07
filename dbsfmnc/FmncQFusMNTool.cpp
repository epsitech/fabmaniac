/**
  * \file FmncQFusMNTool.cpp
  * Dbs and XML wrapper for table TblFmncQFusMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFusMNTool.h"

/******************************************************************************
 class FmncQFusMNTool
 ******************************************************************************/

FmncQFusMNTool::FmncQFusMNTool(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint trnRefFmncMPerson
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->trnRefFmncMPerson = trnRefFmncMPerson;
	this->stubTrnRefFmncMPerson = stubTrnRefFmncMPerson;
	this->srefKLvl = srefKLvl;
	this->titSrefKLvl = titSrefKLvl;
};

void FmncQFusMNTool::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFusMNTool";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "trn", stubTrnRefFmncMPerson);
		writeString(wr, "lvl", srefKLvl);
		writeString(wr, "lvl2", titSrefKLvl);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubTrnRefFmncMPerson", stubTrnRefFmncMPerson);
		writeString(wr, "srefKLvl", srefKLvl);
		writeString(wr, "titSrefKLvl", titSrefKLvl);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQFusMNTool
 ******************************************************************************/

ListFmncQFusMNTool::ListFmncQFusMNTool() {
};

ListFmncQFusMNTool::ListFmncQFusMNTool(
			const ListFmncQFusMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusMNTool(*(src.nodes[i]));
};

ListFmncQFusMNTool::~ListFmncQFusMNTool() {
	clear();
};

void ListFmncQFusMNTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFusMNTool::size() const {
	return(nodes.size());
};

void ListFmncQFusMNTool::append(
			FmncQFusMNTool* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFusMNTool& ListFmncQFusMNTool::operator=(
			const ListFmncQFusMNTool& src
		) {
	FmncQFusMNTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFusMNTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFusMNTool::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFusMNTool";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFusMNTool
 ******************************************************************************/

TblFmncQFusMNTool::TblFmncQFusMNTool() {
};

TblFmncQFusMNTool::~TblFmncQFusMNTool() {
};

bool TblFmncQFusMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQFusMNTool** rec
		) {
	return false;
};

ubigint TblFmncQFusMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	return 0;
};

void TblFmncQFusMNTool::insertRec(
			FmncQFusMNTool* rec
		) {
};

ubigint TblFmncQFusMNTool::insertNewRec(
			FmncQFusMNTool** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint trnRefFmncMPerson
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	ubigint retval = 0;
	FmncQFusMNTool* _rec = NULL;

	_rec = new FmncQFusMNTool(0, jref, jnum, mref, stubMref, ref, trnRefFmncMPerson, stubTrnRefFmncMPerson, srefKLvl, titSrefKLvl);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFusMNTool::appendNewRecToRst(
			ListFmncQFusMNTool& rst
			, FmncQFusMNTool** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint trnRefFmncMPerson
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	ubigint retval = 0;
	FmncQFusMNTool* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, trnRefFmncMPerson, stubTrnRefFmncMPerson, srefKLvl, titSrefKLvl);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFusMNTool::insertRst(
			ListFmncQFusMNTool& rst
		) {
};

void TblFmncQFusMNTool::updateRec(
			FmncQFusMNTool* rec
		) {
};

void TblFmncQFusMNTool::updateRst(
			ListFmncQFusMNTool& rst
		) {
};

void TblFmncQFusMNTool::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFusMNTool::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFusMNTool::loadRecByQref(
			ubigint qref
			, FmncQFusMNTool** rec
		) {
	return false;
};

ubigint TblFmncQFusMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFusMNTool
 ******************************************************************************/

MyTblFmncQFusMNTool::MyTblFmncQFusMNTool() : TblFmncQFusMNTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFusMNTool::~MyTblFmncQFusMNTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFusMNTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFusMNTool (jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFusMNTool SET jref = ?, jnum = ?, mref = ?, ref = ?, trnRefFmncMPerson = ?, srefKLvl = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFusMNTool WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFusMNTool WHERE jref = ?", false);
};

bool MyTblFmncQFusMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQFusMNTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFusMNTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFusMNTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFusMNTool();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->trnRefFmncMPerson = atoll((char*) dbrow[5]); else _rec->trnRefFmncMPerson = 0;
		if (dbrow[6]) _rec->srefKLvl.assign(dbrow[6], dblengths[6]); else _rec->srefKLvl = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQFusMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFusMNTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFusMNTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFusMNTool();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->trnRefFmncMPerson = atoll((char*) dbrow[5]); else rec->trnRefFmncMPerson = 0;
			if (dbrow[6]) rec->srefKLvl.assign(dbrow[6], dblengths[6]); else rec->srefKLvl = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQFusMNTool::insertRec(
			FmncQFusMNTool* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->srefKLvl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->trnRefFmncMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefKLvl.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNTool / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNTool / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFusMNTool::insertRst(
			ListFmncQFusMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFusMNTool::updateRec(
			FmncQFusMNTool* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->srefKLvl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->trnRefFmncMPerson,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->srefKLvl.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNTool / stmtUpdateRec)\n");
};

void MyTblFmncQFusMNTool::updateRst(
			ListFmncQFusMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFusMNTool::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNTool / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNTool / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFusMNTool::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusMNTool / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusMNTool / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFusMNTool::loadRecByQref(
			ubigint qref
			, FmncQFusMNTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFusMNTool WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFusMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFusMNTool WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFusMNTool
 ******************************************************************************/

PgTblFmncQFusMNTool::PgTblFmncQFusMNTool() : TblFmncQFusMNTool(), PgTable() {
};

PgTblFmncQFusMNTool::~PgTblFmncQFusMNTool() {
};

void PgTblFmncQFusMNTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFusMNTool_insertRec", "INSERT INTO TblFmncQFusMNTool (jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNTool_updateRec", "UPDATE TblFmncQFusMNTool SET jref = $1, jnum = $2, mref = $3, ref = $4, trnRefFmncMPerson = $5, srefKLvl = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNTool_removeRecByQref", "DELETE FROM TblFmncQFusMNTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNTool_removeRstByJref", "DELETE FROM TblFmncQFusMNTool WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFusMNTool_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl FROM TblFmncQFusMNTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusMNTool_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl FROM TblFmncQFusMNTool WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFusMNTool::loadRec(
			PGresult* res
			, FmncQFusMNTool** rec
		) {
	char* ptr;

	FmncQFusMNTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFusMNTool();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "trnreffmncmperson"),
			PQfnumber(res, "srefklvl")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->trnRefFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefKLvl.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQFusMNTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFusMNTool* rec;

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
			PQfnumber(res, "trnreffmncmperson"),
			PQfnumber(res, "srefklvl")
		};

		while (numread < numrow) {
			rec = new FmncQFusMNTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->trnRefFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefKLvl.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQFusMNTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFusMNTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFusMNTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFusMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQFusMNTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFusMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFusMNTool::insertRec(
			FmncQFusMNTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _trnRefFmncMPerson = htonl64(rec->trnRefFmncMPerson);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_trnRefFmncMPerson,
		rec->srefKLvl.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQFusMNTool_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFusMNTool::insertRst(
			ListFmncQFusMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFusMNTool::updateRec(
			FmncQFusMNTool* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _trnRefFmncMPerson = htonl64(rec->trnRefFmncMPerson);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_trnRefFmncMPerson,
		rec->srefKLvl.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQFusMNTool_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFusMNTool::updateRst(
			ListFmncQFusMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFusMNTool::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFusMNTool_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNTool_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFusMNTool::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFusMNTool_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusMNTool_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFusMNTool::loadRecByQref(
			ubigint qref
			, FmncQFusMNTool** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFusMNTool_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFusMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusMNTool& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFusMNTool_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

