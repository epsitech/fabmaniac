/**
  * \file FmncQTolARes.cpp
  * Dbs and XML wrapper for table TblFmncQTolARes (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolARes.h"

/******************************************************************************
 class FmncQTolARes
 ******************************************************************************/

FmncQTolARes::FmncQTolARes(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefFmncMFabuser
			, const string stubX1RefFmncMFabuser
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
			, const uint stopt
			, const string ftmStopt
			, const string srefKRestype
			, const string titSrefKRestype
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefFmncMFabuser = x1RefFmncMFabuser;
	this->stubX1RefFmncMFabuser = stubX1RefFmncMFabuser;
	this->startd = startd;
	this->ftmStartd = ftmStartd;
	this->startt = startt;
	this->ftmStartt = ftmStartt;
	this->stopt = stopt;
	this->ftmStopt = ftmStopt;
	this->srefKRestype = srefKRestype;
	this->titSrefKRestype = titSrefKRestype;
	this->Comment = Comment;
};

void FmncQTolARes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolARes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fus", stubX1RefFmncMFabuser);
		writeString(wr, "dat", ftmStartd);
		writeString(wr, "sta", ftmStartt);
		writeString(wr, "sto", ftmStopt);
		writeString(wr, "rty", srefKRestype);
		writeString(wr, "rty2", titSrefKRestype);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "stubX1RefFmncMFabuser", stubX1RefFmncMFabuser);
		writeString(wr, "ftmStartd", ftmStartd);
		writeString(wr, "ftmStartt", ftmStartt);
		writeString(wr, "ftmStopt", ftmStopt);
		writeString(wr, "srefKRestype", srefKRestype);
		writeString(wr, "titSrefKRestype", titSrefKRestype);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolARes
 ******************************************************************************/

ListFmncQTolARes::ListFmncQTolARes() {
};

ListFmncQTolARes::ListFmncQTolARes(
			const ListFmncQTolARes& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolARes(*(src.nodes[i]));
};

ListFmncQTolARes::~ListFmncQTolARes() {
	clear();
};

void ListFmncQTolARes::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolARes::size() const {
	return(nodes.size());
};

void ListFmncQTolARes::append(
			FmncQTolARes* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolARes& ListFmncQTolARes::operator=(
			const ListFmncQTolARes& src
		) {
	FmncQTolARes* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolARes(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolARes::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolARes";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolARes
 ******************************************************************************/

TblFmncQTolARes::TblFmncQTolARes() {
};

TblFmncQTolARes::~TblFmncQTolARes() {
};

bool TblFmncQTolARes::loadRecBySQL(
			const string& sqlstr
			, FmncQTolARes** rec
		) {
	return false;
};

ubigint TblFmncQTolARes::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolARes& rst
		) {
	return 0;
};

void TblFmncQTolARes::insertRec(
			FmncQTolARes* rec
		) {
};

ubigint TblFmncQTolARes::insertNewRec(
			FmncQTolARes** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefFmncMFabuser
			, const string stubX1RefFmncMFabuser
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
			, const uint stopt
			, const string ftmStopt
			, const string srefKRestype
			, const string titSrefKRestype
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTolARes* _rec = NULL;

	_rec = new FmncQTolARes(0, jref, jnum, ref, x1RefFmncMFabuser, stubX1RefFmncMFabuser, startd, ftmStartd, startt, ftmStartt, stopt, ftmStopt, srefKRestype, titSrefKRestype, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolARes::appendNewRecToRst(
			ListFmncQTolARes& rst
			, FmncQTolARes** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefFmncMFabuser
			, const string stubX1RefFmncMFabuser
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
			, const uint stopt
			, const string ftmStopt
			, const string srefKRestype
			, const string titSrefKRestype
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTolARes* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefFmncMFabuser, stubX1RefFmncMFabuser, startd, ftmStartd, startt, ftmStartt, stopt, ftmStopt, srefKRestype, titSrefKRestype, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolARes::insertRst(
			ListFmncQTolARes& rst
		) {
};

void TblFmncQTolARes::updateRec(
			FmncQTolARes* rec
		) {
};

void TblFmncQTolARes::updateRst(
			ListFmncQTolARes& rst
		) {
};

void TblFmncQTolARes::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolARes::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolARes::loadRecByQref(
			ubigint qref
			, FmncQTolARes** rec
		) {
	return false;
};

ubigint TblFmncQTolARes::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolARes& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolARes
 ******************************************************************************/

MyTblFmncQTolARes::MyTblFmncQTolARes() : TblFmncQTolARes(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolARes::~MyTblFmncQTolARes() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolARes::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolARes (jref, jnum, ref, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolARes SET jref = ?, jnum = ?, ref = ?, x1RefFmncMFabuser = ?, startd = ?, startt = ?, stopt = ?, srefKRestype = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolARes WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolARes WHERE jref = ?", false);
};

bool MyTblFmncQTolARes::loadRecBySQL(
			const string& sqlstr
			, FmncQTolARes** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolARes* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolARes / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolARes();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefFmncMFabuser = atoll((char*) dbrow[4]); else _rec->x1RefFmncMFabuser = 0;
		if (dbrow[5]) _rec->startd = atol((char*) dbrow[5]); else _rec->startd = 0;
		if (dbrow[6]) _rec->startt = atol((char*) dbrow[6]); else _rec->startt = 0;
		if (dbrow[7]) _rec->stopt = atol((char*) dbrow[7]); else _rec->stopt = 0;
		if (dbrow[8]) _rec->srefKRestype.assign(dbrow[8], dblengths[8]); else _rec->srefKRestype = "";
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolARes::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolARes& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolARes* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolARes / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolARes();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefFmncMFabuser = atoll((char*) dbrow[4]); else rec->x1RefFmncMFabuser = 0;
			if (dbrow[5]) rec->startd = atol((char*) dbrow[5]); else rec->startd = 0;
			if (dbrow[6]) rec->startt = atol((char*) dbrow[6]); else rec->startt = 0;
			if (dbrow[7]) rec->stopt = atol((char*) dbrow[7]); else rec->stopt = 0;
			if (dbrow[8]) rec->srefKRestype.assign(dbrow[8], dblengths[8]); else rec->srefKRestype = "";
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolARes::insertRec(
			FmncQTolARes* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[7] = rec->srefKRestype.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->startd,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->startt,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->stopt,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKRestype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolARes / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolARes / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolARes::insertRst(
			ListFmncQTolARes& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolARes::updateRec(
			FmncQTolARes* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[7] = rec->srefKRestype.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->startd,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->startt,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->stopt,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->srefKRestype.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolARes / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolARes / stmtUpdateRec)\n");
};

void MyTblFmncQTolARes::updateRst(
			ListFmncQTolARes& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolARes::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolARes / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolARes / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolARes::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolARes / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolARes / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolARes::loadRecByQref(
			ubigint qref
			, FmncQTolARes** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolARes WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolARes::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolARes& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolARes WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolARes
 ******************************************************************************/

PgTblFmncQTolARes::PgTblFmncQTolARes() : TblFmncQTolARes(), PgTable() {
};

PgTblFmncQTolARes::~PgTblFmncQTolARes() {
};

void PgTblFmncQTolARes::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolARes_insertRec", "INSERT INTO TblFmncQTolARes (jref, jnum, ref, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolARes_updateRec", "UPDATE TblFmncQTolARes SET jref = $1, jnum = $2, ref = $3, x1RefFmncMFabuser = $4, startd = $5, startt = $6, stopt = $7, srefKRestype = $8, Comment = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolARes_removeRecByQref", "DELETE FROM TblFmncQTolARes WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolARes_removeRstByJref", "DELETE FROM TblFmncQTolARes WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolARes_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment FROM TblFmncQTolARes WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolARes_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment FROM TblFmncQTolARes WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolARes::loadRec(
			PGresult* res
			, FmncQTolARes** rec
		) {
	char* ptr;

	FmncQTolARes* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolARes();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "srefkrestype"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->startt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->stopt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefKRestype.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolARes::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolARes& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolARes* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "srefkrestype"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncQTolARes();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->startt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->stopt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefKRestype.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolARes::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolARes** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolARes / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolARes::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolARes& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolARes / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolARes::loadRecBySQL(
			const string& sqlstr
			, FmncQTolARes** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolARes::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolARes& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolARes::insertRec(
			FmncQTolARes* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		rec->srefKRestype.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolARes_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolARes_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolARes::insertRst(
			ListFmncQTolARes& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolARes::updateRec(
			FmncQTolARes* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		rec->srefKRestype.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolARes_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolARes_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolARes::updateRst(
			ListFmncQTolARes& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolARes::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolARes_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolARes_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolARes::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolARes_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolARes_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolARes::loadRecByQref(
			ubigint qref
			, FmncQTolARes** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolARes_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolARes::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolARes& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolARes_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

