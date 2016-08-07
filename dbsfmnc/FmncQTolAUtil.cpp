/**
  * \file FmncQTolAUtil.cpp
  * Dbs and XML wrapper for table TblFmncQTolAUtil (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolAUtil.h"

/******************************************************************************
 class FmncQTolAUtil
 ******************************************************************************/

FmncQTolAUtil::FmncQTolAUtil(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefFmncMFabproject
			, const string stubX1RefFmncMFabproject
			, const ubigint x2RefFmncMFabuser
			, const string stubX2RefFmncMFabuser
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
			, const uint stopt
			, const string ftmStopt
			, const double Unitprice
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefFmncMFabproject = x1RefFmncMFabproject;
	this->stubX1RefFmncMFabproject = stubX1RefFmncMFabproject;
	this->x2RefFmncMFabuser = x2RefFmncMFabuser;
	this->stubX2RefFmncMFabuser = stubX2RefFmncMFabuser;
	this->startd = startd;
	this->ftmStartd = ftmStartd;
	this->startt = startt;
	this->ftmStartt = ftmStartt;
	this->stopt = stopt;
	this->ftmStopt = ftmStopt;
	this->Unitprice = Unitprice;
	this->Comment = Comment;
};

void FmncQTolAUtil::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolAUtil";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fpj", stubX1RefFmncMFabproject);
		writeString(wr, "fus", stubX2RefFmncMFabuser);
		writeString(wr, "dat", ftmStartd);
		writeString(wr, "sta", ftmStartt);
		writeString(wr, "sto", ftmStopt);
		writeDouble(wr, "upr", Unitprice);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "stubX1RefFmncMFabproject", stubX1RefFmncMFabproject);
		writeString(wr, "stubX2RefFmncMFabuser", stubX2RefFmncMFabuser);
		writeString(wr, "ftmStartd", ftmStartd);
		writeString(wr, "ftmStartt", ftmStartt);
		writeString(wr, "ftmStopt", ftmStopt);
		writeDouble(wr, "Unitprice", Unitprice);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolAUtil
 ******************************************************************************/

ListFmncQTolAUtil::ListFmncQTolAUtil() {
};

ListFmncQTolAUtil::ListFmncQTolAUtil(
			const ListFmncQTolAUtil& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAUtil(*(src.nodes[i]));
};

ListFmncQTolAUtil::~ListFmncQTolAUtil() {
	clear();
};

void ListFmncQTolAUtil::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolAUtil::size() const {
	return(nodes.size());
};

void ListFmncQTolAUtil::append(
			FmncQTolAUtil* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolAUtil& ListFmncQTolAUtil::operator=(
			const ListFmncQTolAUtil& src
		) {
	FmncQTolAUtil* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolAUtil(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolAUtil::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolAUtil";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolAUtil
 ******************************************************************************/

TblFmncQTolAUtil::TblFmncQTolAUtil() {
};

TblFmncQTolAUtil::~TblFmncQTolAUtil() {
};

bool TblFmncQTolAUtil::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAUtil** rec
		) {
	return false;
};

ubigint TblFmncQTolAUtil::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	return 0;
};

void TblFmncQTolAUtil::insertRec(
			FmncQTolAUtil* rec
		) {
};

ubigint TblFmncQTolAUtil::insertNewRec(
			FmncQTolAUtil** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefFmncMFabproject
			, const string stubX1RefFmncMFabproject
			, const ubigint x2RefFmncMFabuser
			, const string stubX2RefFmncMFabuser
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
			, const uint stopt
			, const string ftmStopt
			, const double Unitprice
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTolAUtil* _rec = NULL;

	_rec = new FmncQTolAUtil(0, jref, jnum, ref, x1RefFmncMFabproject, stubX1RefFmncMFabproject, x2RefFmncMFabuser, stubX2RefFmncMFabuser, startd, ftmStartd, startt, ftmStartt, stopt, ftmStopt, Unitprice, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolAUtil::appendNewRecToRst(
			ListFmncQTolAUtil& rst
			, FmncQTolAUtil** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefFmncMFabproject
			, const string stubX1RefFmncMFabproject
			, const ubigint x2RefFmncMFabuser
			, const string stubX2RefFmncMFabuser
			, const uint startd
			, const string ftmStartd
			, const uint startt
			, const string ftmStartt
			, const uint stopt
			, const string ftmStopt
			, const double Unitprice
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTolAUtil* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefFmncMFabproject, stubX1RefFmncMFabproject, x2RefFmncMFabuser, stubX2RefFmncMFabuser, startd, ftmStartd, startt, ftmStartt, stopt, ftmStopt, Unitprice, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolAUtil::insertRst(
			ListFmncQTolAUtil& rst
		) {
};

void TblFmncQTolAUtil::updateRec(
			FmncQTolAUtil* rec
		) {
};

void TblFmncQTolAUtil::updateRst(
			ListFmncQTolAUtil& rst
		) {
};

void TblFmncQTolAUtil::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolAUtil::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolAUtil::loadRecByQref(
			ubigint qref
			, FmncQTolAUtil** rec
		) {
	return false;
};

ubigint TblFmncQTolAUtil::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolAUtil
 ******************************************************************************/

MyTblFmncQTolAUtil::MyTblFmncQTolAUtil() : TblFmncQTolAUtil(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolAUtil::~MyTblFmncQTolAUtil() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolAUtil::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolAUtil (jref, jnum, ref, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolAUtil SET jref = ?, jnum = ?, ref = ?, x1RefFmncMFabproject = ?, x2RefFmncMFabuser = ?, startd = ?, startt = ?, stopt = ?, Unitprice = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolAUtil WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolAUtil WHERE jref = ?", false);
};

bool MyTblFmncQTolAUtil::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAUtil** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolAUtil* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolAUtil / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolAUtil();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefFmncMFabproject = atoll((char*) dbrow[4]); else _rec->x1RefFmncMFabproject = 0;
		if (dbrow[5]) _rec->x2RefFmncMFabuser = atoll((char*) dbrow[5]); else _rec->x2RefFmncMFabuser = 0;
		if (dbrow[6]) _rec->startd = atol((char*) dbrow[6]); else _rec->startd = 0;
		if (dbrow[7]) _rec->startt = atol((char*) dbrow[7]); else _rec->startt = 0;
		if (dbrow[8]) _rec->stopt = atol((char*) dbrow[8]); else _rec->stopt = 0;
		if (dbrow[9]) _rec->Unitprice = atof((char*) dbrow[9]); else _rec->Unitprice = 0.0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolAUtil::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolAUtil* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolAUtil / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolAUtil();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefFmncMFabproject = atoll((char*) dbrow[4]); else rec->x1RefFmncMFabproject = 0;
			if (dbrow[5]) rec->x2RefFmncMFabuser = atoll((char*) dbrow[5]); else rec->x2RefFmncMFabuser = 0;
			if (dbrow[6]) rec->startd = atol((char*) dbrow[6]); else rec->startd = 0;
			if (dbrow[7]) rec->startt = atol((char*) dbrow[7]); else rec->startt = 0;
			if (dbrow[8]) rec->stopt = atol((char*) dbrow[8]); else rec->stopt = 0;
			if (dbrow[9]) rec->Unitprice = atof((char*) dbrow[9]); else rec->Unitprice = 0.0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolAUtil::insertRec(
			FmncQTolAUtil* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefFmncMFabproject,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefFmncMFabuser,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->startd,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->startt,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->stopt,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->Unitprice,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAUtil / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAUtil / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolAUtil::insertRst(
			ListFmncQTolAUtil& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolAUtil::updateRec(
			FmncQTolAUtil* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefFmncMFabproject,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->x2RefFmncMFabuser,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->startd,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->startt,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->stopt,&(l[7]),&(n[7]),&(e[7])), 
		bindDouble(&rec->Unitprice,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAUtil / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAUtil / stmtUpdateRec)\n");
};

void MyTblFmncQTolAUtil::updateRst(
			ListFmncQTolAUtil& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolAUtil::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAUtil / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAUtil / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolAUtil::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolAUtil / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolAUtil / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolAUtil::loadRecByQref(
			ubigint qref
			, FmncQTolAUtil** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolAUtil WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolAUtil::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolAUtil WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolAUtil
 ******************************************************************************/

PgTblFmncQTolAUtil::PgTblFmncQTolAUtil() : TblFmncQTolAUtil(), PgTable() {
};

PgTblFmncQTolAUtil::~PgTblFmncQTolAUtil() {
};

void PgTblFmncQTolAUtil::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolAUtil_insertRec", "INSERT INTO TblFmncQTolAUtil (jref, jnum, ref, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAUtil_updateRec", "UPDATE TblFmncQTolAUtil SET jref = $1, jnum = $2, ref = $3, x1RefFmncMFabproject = $4, x2RefFmncMFabuser = $5, startd = $6, startt = $7, stopt = $8, Unitprice = $9, Comment = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAUtil_removeRecByQref", "DELETE FROM TblFmncQTolAUtil WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAUtil_removeRstByJref", "DELETE FROM TblFmncQTolAUtil WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolAUtil_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment FROM TblFmncQTolAUtil WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolAUtil_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment FROM TblFmncQTolAUtil WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolAUtil::loadRec(
			PGresult* res
			, FmncQTolAUtil** rec
		) {
	char* ptr;

	FmncQTolAUtil* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolAUtil();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1reffmncmfabproject"),
			PQfnumber(res, "x2reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2RefFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->startt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->stopt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolAUtil::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolAUtil* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1reffmncmfabproject"),
			PQfnumber(res, "x2reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncQTolAUtil();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2RefFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->startt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->stopt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolAUtil::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolAUtil** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAUtil / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolAUtil::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAUtil / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolAUtil::loadRecBySQL(
			const string& sqlstr
			, FmncQTolAUtil** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolAUtil::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolAUtil::insertRec(
			FmncQTolAUtil* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefFmncMFabproject = htonl64(rec->x1RefFmncMFabproject);
	ubigint _x2RefFmncMFabuser = htonl64(rec->x2RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);
	string _Unitprice = to_string(rec->Unitprice);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefFmncMFabproject,
		(char*) &_x2RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		_Unitprice.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolAUtil_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAUtil_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolAUtil::insertRst(
			ListFmncQTolAUtil& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolAUtil::updateRec(
			FmncQTolAUtil* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefFmncMFabproject = htonl64(rec->x1RefFmncMFabproject);
	ubigint _x2RefFmncMFabuser = htonl64(rec->x2RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);
	string _Unitprice = to_string(rec->Unitprice);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefFmncMFabproject,
		(char*) &_x2RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		_Unitprice.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolAUtil_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAUtil_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolAUtil::updateRst(
			ListFmncQTolAUtil& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolAUtil::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolAUtil_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAUtil_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolAUtil::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolAUtil_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolAUtil_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolAUtil::loadRecByQref(
			ubigint qref
			, FmncQTolAUtil** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolAUtil_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolAUtil::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolAUtil& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolAUtil_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

