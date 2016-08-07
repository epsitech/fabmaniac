/**
  * \file FmncQPrsMNOrg.cpp
  * Dbs and XML wrapper for table TblFmncQPrsMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrsMNOrg.h"

/******************************************************************************
 class FmncQPrsMNOrg
 ******************************************************************************/

FmncQPrsMNOrg::FmncQPrsMNOrg(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1Startd = x1Startd;
	this->ftmX1Startd = ftmX1Startd;
	this->x1Stopd = x1Stopd;
	this->ftmX1Stopd = ftmX1Stopd;
	this->srefKFunction = srefKFunction;
	this->titSrefKFunction = titSrefKFunction;
};

void FmncQPrsMNOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQPrsMNOrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1Startd);
		writeString(wr, "sto", ftmX1Stopd);
		writeString(wr, "fct", srefKFunction);
		writeString(wr, "fct2", titSrefKFunction);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1Startd", ftmX1Startd);
		writeString(wr, "ftmX1Stopd", ftmX1Stopd);
		writeString(wr, "srefKFunction", srefKFunction);
		writeString(wr, "titSrefKFunction", titSrefKFunction);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQPrsMNOrg
 ******************************************************************************/

ListFmncQPrsMNOrg::ListFmncQPrsMNOrg() {
};

ListFmncQPrsMNOrg::ListFmncQPrsMNOrg(
			const ListFmncQPrsMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsMNOrg(*(src.nodes[i]));
};

ListFmncQPrsMNOrg::~ListFmncQPrsMNOrg() {
	clear();
};

void ListFmncQPrsMNOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQPrsMNOrg::size() const {
	return(nodes.size());
};

void ListFmncQPrsMNOrg::append(
			FmncQPrsMNOrg* rec
		) {
	nodes.push_back(rec);
};

ListFmncQPrsMNOrg& ListFmncQPrsMNOrg::operator=(
			const ListFmncQPrsMNOrg& src
		) {
	FmncQPrsMNOrg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQPrsMNOrg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQPrsMNOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQPrsMNOrg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQPrsMNOrg
 ******************************************************************************/

TblFmncQPrsMNOrg::TblFmncQPrsMNOrg() {
};

TblFmncQPrsMNOrg::~TblFmncQPrsMNOrg() {
};

bool TblFmncQPrsMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsMNOrg** rec
		) {
	return false;
};

ubigint TblFmncQPrsMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	return 0;
};

void TblFmncQPrsMNOrg::insertRec(
			FmncQPrsMNOrg* rec
		) {
};

ubigint TblFmncQPrsMNOrg::insertNewRec(
			FmncQPrsMNOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	FmncQPrsMNOrg* _rec = NULL;

	_rec = new FmncQPrsMNOrg(0, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQPrsMNOrg::appendNewRecToRst(
			ListFmncQPrsMNOrg& rst
			, FmncQPrsMNOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	FmncQPrsMNOrg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQPrsMNOrg::insertRst(
			ListFmncQPrsMNOrg& rst
		) {
};

void TblFmncQPrsMNOrg::updateRec(
			FmncQPrsMNOrg* rec
		) {
};

void TblFmncQPrsMNOrg::updateRst(
			ListFmncQPrsMNOrg& rst
		) {
};

void TblFmncQPrsMNOrg::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQPrsMNOrg::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQPrsMNOrg::loadRecByQref(
			ubigint qref
			, FmncQPrsMNOrg** rec
		) {
	return false;
};

ubigint TblFmncQPrsMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQPrsMNOrg
 ******************************************************************************/

MyTblFmncQPrsMNOrg::MyTblFmncQPrsMNOrg() : TblFmncQPrsMNOrg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQPrsMNOrg::~MyTblFmncQPrsMNOrg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQPrsMNOrg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQPrsMNOrg (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQPrsMNOrg SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Startd = ?, x1Stopd = ?, srefKFunction = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQPrsMNOrg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQPrsMNOrg WHERE jref = ?", false);
};

bool MyTblFmncQPrsMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsMNOrg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQPrsMNOrg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPrsMNOrg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQPrsMNOrg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Startd = atol((char*) dbrow[5]); else _rec->x1Startd = 0;
		if (dbrow[6]) _rec->x1Stopd = atol((char*) dbrow[6]); else _rec->x1Stopd = 0;
		if (dbrow[7]) _rec->srefKFunction.assign(dbrow[7], dblengths[7]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQPrsMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQPrsMNOrg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPrsMNOrg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQPrsMNOrg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Startd = atol((char*) dbrow[5]); else rec->x1Startd = 0;
			if (dbrow[6]) rec->x1Stopd = atol((char*) dbrow[6]); else rec->x1Stopd = 0;
			if (dbrow[7]) rec->srefKFunction.assign(dbrow[7], dblengths[7]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQPrsMNOrg::insertRec(
			FmncQPrsMNOrg* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Startd,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stopd,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsMNOrg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsMNOrg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQPrsMNOrg::insertRst(
			ListFmncQPrsMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQPrsMNOrg::updateRec(
			FmncQPrsMNOrg* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->x1Startd,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->x1Stopd,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsMNOrg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsMNOrg / stmtUpdateRec)\n");
};

void MyTblFmncQPrsMNOrg::updateRst(
			ListFmncQPrsMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQPrsMNOrg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsMNOrg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsMNOrg / stmtRemoveRecByQref)\n");
};

void MyTblFmncQPrsMNOrg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsMNOrg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsMNOrg / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQPrsMNOrg::loadRecByQref(
			ubigint qref
			, FmncQPrsMNOrg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQPrsMNOrg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQPrsMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQPrsMNOrg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQPrsMNOrg
 ******************************************************************************/

PgTblFmncQPrsMNOrg::PgTblFmncQPrsMNOrg() : TblFmncQPrsMNOrg(), PgTable() {
};

PgTblFmncQPrsMNOrg::~PgTblFmncQPrsMNOrg() {
};

void PgTblFmncQPrsMNOrg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQPrsMNOrg_insertRec", "INSERT INTO TblFmncQPrsMNOrg (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsMNOrg_updateRec", "UPDATE TblFmncQPrsMNOrg SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Startd = $5, x1Stopd = $6, srefKFunction = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsMNOrg_removeRecByQref", "DELETE FROM TblFmncQPrsMNOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsMNOrg_removeRstByJref", "DELETE FROM TblFmncQPrsMNOrg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQPrsMNOrg_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblFmncQPrsMNOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsMNOrg_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblFmncQPrsMNOrg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQPrsMNOrg::loadRec(
			PGresult* res
			, FmncQPrsMNOrg** rec
		) {
	char* ptr;

	FmncQPrsMNOrg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQPrsMNOrg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQPrsMNOrg::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQPrsMNOrg* rec;

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
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new FmncQPrsMNOrg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQPrsMNOrg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQPrsMNOrg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsMNOrg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPrsMNOrg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsMNOrg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQPrsMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsMNOrg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPrsMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQPrsMNOrg::insertRec(
			FmncQPrsMNOrg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQPrsMNOrg_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsMNOrg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQPrsMNOrg::insertRst(
			ListFmncQPrsMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQPrsMNOrg::updateRec(
			FmncQPrsMNOrg* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		rec->srefKFunction.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQPrsMNOrg_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsMNOrg_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQPrsMNOrg::updateRst(
			ListFmncQPrsMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQPrsMNOrg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQPrsMNOrg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsMNOrg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQPrsMNOrg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQPrsMNOrg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsMNOrg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQPrsMNOrg::loadRecByQref(
			ubigint qref
			, FmncQPrsMNOrg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQPrsMNOrg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQPrsMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsMNOrg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQPrsMNOrg_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

