/**
  * \file FmncQTtyKToolchar.cpp
  * Dbs and XML wrapper for table TblFmncQTtyKToolchar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtyKToolchar.h"

/******************************************************************************
 class FmncQTtyKToolchar
 ******************************************************************************/

FmncQTtyKToolchar::FmncQTtyKToolchar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->klsNum = klsNum;
	this->Fixed = Fixed;
	this->yesnoFixed = yesnoFixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

void FmncQTtyKToolchar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTtyKToolchar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fix", yesnoFixed);
		writeString(wr, "srf", sref);
		writeString(wr, "avl", Avail);
		writeString(wr, "imp", Implied);
		writeString(wr, "tit", Title);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "yesnoFixed", yesnoFixed);
		writeString(wr, "sref", sref);
		writeString(wr, "Avail", Avail);
		writeString(wr, "Implied", Implied);
		writeString(wr, "Title", Title);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTtyKToolchar
 ******************************************************************************/

ListFmncQTtyKToolchar::ListFmncQTtyKToolchar() {
};

ListFmncQTtyKToolchar::ListFmncQTtyKToolchar(
			const ListFmncQTtyKToolchar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyKToolchar(*(src.nodes[i]));
};

ListFmncQTtyKToolchar::~ListFmncQTtyKToolchar() {
	clear();
};

void ListFmncQTtyKToolchar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTtyKToolchar::size() const {
	return(nodes.size());
};

void ListFmncQTtyKToolchar::append(
			FmncQTtyKToolchar* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTtyKToolchar& ListFmncQTtyKToolchar::operator=(
			const ListFmncQTtyKToolchar& src
		) {
	FmncQTtyKToolchar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTtyKToolchar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTtyKToolchar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTtyKToolchar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTtyKToolchar
 ******************************************************************************/

TblFmncQTtyKToolchar::TblFmncQTtyKToolchar() {
};

TblFmncQTtyKToolchar::~TblFmncQTtyKToolchar() {
};

bool TblFmncQTtyKToolchar::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyKToolchar** rec
		) {
	return false;
};

ubigint TblFmncQTtyKToolchar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	return 0;
};

void TblFmncQTtyKToolchar::insertRec(
			FmncQTtyKToolchar* rec
		) {
};

ubigint TblFmncQTtyKToolchar::insertNewRec(
			FmncQTtyKToolchar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTtyKToolchar* _rec = NULL;

	_rec = new FmncQTtyKToolchar(0, jref, jnum, ref, klsNum, Fixed, yesnoFixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTtyKToolchar::appendNewRecToRst(
			ListFmncQTtyKToolchar& rst
			, FmncQTtyKToolchar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQTtyKToolchar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, klsNum, Fixed, yesnoFixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTtyKToolchar::insertRst(
			ListFmncQTtyKToolchar& rst
		) {
};

void TblFmncQTtyKToolchar::updateRec(
			FmncQTtyKToolchar* rec
		) {
};

void TblFmncQTtyKToolchar::updateRst(
			ListFmncQTtyKToolchar& rst
		) {
};

void TblFmncQTtyKToolchar::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTtyKToolchar::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTtyKToolchar::loadRecByQref(
			ubigint qref
			, FmncQTtyKToolchar** rec
		) {
	return false;
};

ubigint TblFmncQTtyKToolchar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTtyKToolchar
 ******************************************************************************/

MyTblFmncQTtyKToolchar::MyTblFmncQTtyKToolchar() : TblFmncQTtyKToolchar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTtyKToolchar::~MyTblFmncQTtyKToolchar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTtyKToolchar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTtyKToolchar (jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTtyKToolchar SET jref = ?, jnum = ?, ref = ?, klsNum = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTtyKToolchar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTtyKToolchar WHERE jref = ?", false);
};

bool MyTblFmncQTtyKToolchar::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyKToolchar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTtyKToolchar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtyKToolchar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTtyKToolchar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->klsNum = atol((char*) dbrow[4]); else _rec->klsNum = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTtyKToolchar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTtyKToolchar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtyKToolchar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTtyKToolchar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->klsNum = atol((char*) dbrow[4]); else rec->klsNum = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTtyKToolchar::insertRec(
			FmncQTtyKToolchar* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyKToolchar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyKToolchar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTtyKToolchar::insertRst(
			ListFmncQTtyKToolchar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTtyKToolchar::updateRec(
			FmncQTtyKToolchar* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])), 
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyKToolchar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyKToolchar / stmtUpdateRec)\n");
};

void MyTblFmncQTtyKToolchar::updateRst(
			ListFmncQTtyKToolchar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTtyKToolchar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyKToolchar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyKToolchar / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTtyKToolchar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyKToolchar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyKToolchar / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTtyKToolchar::loadRecByQref(
			ubigint qref
			, FmncQTtyKToolchar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTtyKToolchar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTtyKToolchar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTtyKToolchar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTtyKToolchar
 ******************************************************************************/

PgTblFmncQTtyKToolchar::PgTblFmncQTtyKToolchar() : TblFmncQTtyKToolchar(), PgTable() {
};

PgTblFmncQTtyKToolchar::~PgTblFmncQTtyKToolchar() {
};

void PgTblFmncQTtyKToolchar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTtyKToolchar_insertRec", "INSERT INTO TblFmncQTtyKToolchar (jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyKToolchar_updateRec", "UPDATE TblFmncQTtyKToolchar SET jref = $1, jnum = $2, ref = $3, klsNum = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE qref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyKToolchar_removeRecByQref", "DELETE FROM TblFmncQTtyKToolchar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyKToolchar_removeRstByJref", "DELETE FROM TblFmncQTtyKToolchar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTtyKToolchar_loadRecByQref", "SELECT qref, jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncQTtyKToolchar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyKToolchar_loadRstByJref", "SELECT qref, jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncQTtyKToolchar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTtyKToolchar::loadRec(
			PGresult* res
			, FmncQTtyKToolchar** rec
		) {
	char* ptr;

	FmncQTtyKToolchar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTtyKToolchar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTtyKToolchar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTtyKToolchar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncQTtyKToolchar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTtyKToolchar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTtyKToolchar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyKToolchar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtyKToolchar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyKToolchar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTtyKToolchar::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyKToolchar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtyKToolchar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTtyKToolchar::insertRec(
			FmncQTtyKToolchar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQTtyKToolchar_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyKToolchar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTtyKToolchar::insertRst(
			ListFmncQTtyKToolchar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTtyKToolchar::updateRec(
			FmncQTtyKToolchar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTtyKToolchar_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyKToolchar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTtyKToolchar::updateRst(
			ListFmncQTtyKToolchar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTtyKToolchar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtyKToolchar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyKToolchar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTtyKToolchar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtyKToolchar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyKToolchar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTtyKToolchar::loadRecByQref(
			ubigint qref
			, FmncQTtyKToolchar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTtyKToolchar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTtyKToolchar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyKToolchar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTtyKToolchar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

