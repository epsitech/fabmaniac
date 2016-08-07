/**
  * \file FmncQTolAAvl.cpp
  * Dbs and XML wrapper for table TblFmncQTolAAvl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolAAvl.h"

/******************************************************************************
 class FmncQTolAAvl
 ******************************************************************************/

FmncQTolAAvl::FmncQTolAAvl(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x2IxVWkday
			, const string srefX2IxVWkday
			, const uint x3Startt
			, const string ftmX3Startt
			, const uint x3Stopt
			, const string ftmX3Stopt
			, const string srefKAvltype
			, const string titSrefKAvltype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1Startd = x1Startd;
	this->ftmX1Startd = ftmX1Startd;
	this->x2IxVWkday = x2IxVWkday;
	this->srefX2IxVWkday = srefX2IxVWkday;
	this->x3Startt = x3Startt;
	this->ftmX3Startt = ftmX3Startt;
	this->x3Stopt = x3Stopt;
	this->ftmX3Stopt = ftmX3Stopt;
	this->srefKAvltype = srefKAvltype;
	this->titSrefKAvltype = titSrefKAvltype;
};

void FmncQTolAAvl::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolAAvl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "dat", ftmX1Startd);
		writeString(wr, "wdy", srefX2IxVWkday);
		writeString(wr, "sta", ftmX3Startt);
		writeString(wr, "sto", ftmX3Stopt);
		writeString(wr, "aty", srefKAvltype);
		writeString(wr, "aty2", titSrefKAvltype);
	} else {
		writeString(wr, "ftmX1Startd", ftmX1Startd);
		writeString(wr, "srefX2IxVWkday", srefX2IxVWkday);
		writeString(wr, "ftmX3Startt", ftmX3Startt);
		writeString(wr, "ftmX3Stopt", ftmX3Stopt);
		writeString(wr, "srefKAvltype", srefKAvltype);
		writeString(wr, "titSrefKAvltype", titSrefKAvltype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolAAvl
 ******************************************************************************/

ListFmncQTolAAvl::ListFmncQTolAAvl() {
};

ListFmncQTolAAvl::ListFmncQTolAAvl(
			const ListFmncQTolAAvl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAAvl(*(src.nodes[i]));
};

ListFmncQTolAAvl::~ListFmncQTolAAvl() {
	clear();
};

void ListFmncQTolAAvl::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolAAvl::size() const {
	return(nodes.size());
};

void ListFmncQTolAAvl::append(
			FmncQTolAAvl* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolAAvl& ListFmncQTolAAvl::operator=(
			const ListFmncQTolAAvl& src
		) {
	FmncQTolAAvl* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolAAvl(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolAAvl::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolAAvl";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolAAvl
 ******************************************************************************/

TblFmncQTolAAvl::TblFmncQTolAAvl() {
};

TblFmncQTolAAvl::~TblFmncQTolAAvl() {
};

bool TblFmncQTolAAvl::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAAvl** rec
		) {
	return false;
};

ubigint TblFmncQTolAAvl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	return 0;
};

void TblFmncQTolAAvl::insertRec(
			FmncQTolAAvl* rec
		) {
};

ubigint TblFmncQTolAAvl::insertNewRec(
			FmncQTolAAvl** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x2IxVWkday
			, const string srefX2IxVWkday
			, const uint x3Startt
			, const string ftmX3Startt
			, const uint x3Stopt
			, const string ftmX3Stopt
			, const string srefKAvltype
			, const string titSrefKAvltype
		) {
	ubigint retval = 0;
	FmncQTolAAvl* _rec = NULL;

	_rec = new FmncQTolAAvl(0, jref, jnum, ref, x1Startd, ftmX1Startd, x2IxVWkday, srefX2IxVWkday, x3Startt, ftmX3Startt, x3Stopt, ftmX3Stopt, srefKAvltype, titSrefKAvltype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolAAvl::appendNewRecToRst(
			ListFmncQTolAAvl& rst
			, FmncQTolAAvl** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x2IxVWkday
			, const string srefX2IxVWkday
			, const uint x3Startt
			, const string ftmX3Startt
			, const uint x3Stopt
			, const string ftmX3Stopt
			, const string srefKAvltype
			, const string titSrefKAvltype
		) {
	ubigint retval = 0;
	FmncQTolAAvl* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1Startd, ftmX1Startd, x2IxVWkday, srefX2IxVWkday, x3Startt, ftmX3Startt, x3Stopt, ftmX3Stopt, srefKAvltype, titSrefKAvltype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolAAvl::insertRst(
			ListFmncQTolAAvl& rst
		) {
};

void TblFmncQTolAAvl::updateRec(
			FmncQTolAAvl* rec
		) {
};

void TblFmncQTolAAvl::updateRst(
			ListFmncQTolAAvl& rst
		) {
};

void TblFmncQTolAAvl::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolAAvl::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolAAvl::loadRecByQref(
			ubigint qref
			, FmncQTolAAvl** rec
		) {
	return false;
};

ubigint TblFmncQTolAAvl::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolAAvl
 ******************************************************************************/

MyTblFmncQTolAAvl::MyTblFmncQTolAAvl() : TblFmncQTolAAvl(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolAAvl::~MyTblFmncQTolAAvl() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolAAvl::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolAAvl (jref, jnum, ref, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolAAvl SET jref = ?, jnum = ?, ref = ?, x1Startd = ?, x2IxVWkday = ?, x3Startt = ?, x3Stopt = ?, srefKAvltype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolAAvl WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolAAvl WHERE jref = ?", false);
};

bool MyTblFmncQTolAAvl::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAAvl** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolAAvl* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolAAvl / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolAAvl();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1Startd = atol((char*) dbrow[4]); else _rec->x1Startd = 0;
		if (dbrow[5]) _rec->x2IxVWkday = atol((char*) dbrow[5]); else _rec->x2IxVWkday = 0;
		if (dbrow[6]) _rec->x3Startt = atol((char*) dbrow[6]); else _rec->x3Startt = 0;
		if (dbrow[7]) _rec->x3Stopt = atol((char*) dbrow[7]); else _rec->x3Stopt = 0;
		if (dbrow[8]) _rec->srefKAvltype.assign(dbrow[8], dblengths[8]); else _rec->srefKAvltype = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolAAvl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolAAvl* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolAAvl / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolAAvl();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1Startd = atol((char*) dbrow[4]); else rec->x1Startd = 0;
			if (dbrow[5]) rec->x2IxVWkday = atol((char*) dbrow[5]); else rec->x2IxVWkday = 0;
			if (dbrow[6]) rec->x3Startt = atol((char*) dbrow[6]); else rec->x3Startt = 0;
			if (dbrow[7]) rec->x3Stopt = atol((char*) dbrow[7]); else rec->x3Stopt = 0;
			if (dbrow[8]) rec->srefKAvltype.assign(dbrow[8], dblengths[8]); else rec->srefKAvltype = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolAAvl::insertRec(
			FmncQTolAAvl* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[7] = rec->srefKAvltype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1Startd,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x2IxVWkday,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x3Startt,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->x3Stopt,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKAvltype.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAAvl / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAAvl / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolAAvl::insertRst(
			ListFmncQTolAAvl& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolAAvl::updateRec(
			FmncQTolAAvl* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[7] = rec->srefKAvltype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->x1Startd,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->x2IxVWkday,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->x3Startt,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->x3Stopt,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->srefKAvltype.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAAvl / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAAvl / stmtUpdateRec)\n");
};

void MyTblFmncQTolAAvl::updateRst(
			ListFmncQTolAAvl& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolAAvl::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAAvl / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAAvl / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolAAvl::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAAvl / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAAvl / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolAAvl::loadRecByQref(
			ubigint qref
			, FmncQTolAAvl** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolAAvl WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolAAvl::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolAAvl WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolAAvl
 ******************************************************************************/

PgTblFmncQTolAAvl::PgTblFmncQTolAAvl() : TblFmncQTolAAvl(), PgTable() {
};

PgTblFmncQTolAAvl::~PgTblFmncQTolAAvl() {
};

void PgTblFmncQTolAAvl::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolAAvl_insertRec", "INSERT INTO TblFmncQTolAAvl (jref, jnum, ref, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAAvl_updateRec", "UPDATE TblFmncQTolAAvl SET jref = $1, jnum = $2, ref = $3, x1Startd = $4, x2IxVWkday = $5, x3Startt = $6, x3Stopt = $7, srefKAvltype = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAAvl_removeRecByQref", "DELETE FROM TblFmncQTolAAvl WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAAvl_removeRstByJref", "DELETE FROM TblFmncQTolAAvl WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolAAvl_loadRecByQref", "SELECT qref, jref, jnum, ref, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype FROM TblFmncQTolAAvl WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAAvl_loadRstByJref", "SELECT qref, jref, jnum, ref, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype FROM TblFmncQTolAAvl WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolAAvl::loadRec(
			PGresult* res
			, FmncQTolAAvl** rec
		) {
	char* ptr;

	FmncQTolAAvl* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolAAvl();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x2ixvwkday"),
			PQfnumber(res, "x3startt"),
			PQfnumber(res, "x3stopt"),
			PQfnumber(res, "srefkavltype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2IxVWkday = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x3Startt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x3Stopt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefKAvltype.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolAAvl::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolAAvl* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x2ixvwkday"),
			PQfnumber(res, "x3startt"),
			PQfnumber(res, "x3stopt"),
			PQfnumber(res, "srefkavltype")
		};

		while (numread < numrow) {
			rec = new FmncQTolAAvl();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2IxVWkday = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x3Startt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x3Stopt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefKAvltype.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolAAvl::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolAAvl** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAAvl / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolAAvl::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAAvl / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolAAvl::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAAvl** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolAAvl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolAAvl::insertRec(
			FmncQTolAAvl* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x2IxVWkday = htonl(rec->x2IxVWkday);
	uint _x3Startt = htonl(rec->x3Startt);
	uint _x3Stopt = htonl(rec->x3Stopt);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x2IxVWkday,
		(char*) &_x3Startt,
		(char*) &_x3Stopt,
		rec->srefKAvltype.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolAAvl_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAAvl_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolAAvl::insertRst(
			ListFmncQTolAAvl& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolAAvl::updateRec(
			FmncQTolAAvl* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x2IxVWkday = htonl(rec->x2IxVWkday);
	uint _x3Startt = htonl(rec->x3Startt);
	uint _x3Stopt = htonl(rec->x3Stopt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x2IxVWkday,
		(char*) &_x3Startt,
		(char*) &_x3Stopt,
		rec->srefKAvltype.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolAAvl_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAAvl_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolAAvl::updateRst(
			ListFmncQTolAAvl& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolAAvl::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolAAvl_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAAvl_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolAAvl::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolAAvl_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAAvl_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolAAvl::loadRecByQref(
			ubigint qref
			, FmncQTolAAvl** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolAAvl_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolAAvl::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAAvl& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolAAvl_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

