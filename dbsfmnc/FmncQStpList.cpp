/**
  * \file FmncQStpList.cpp
  * Dbs and XML wrapper for table TblFmncQStpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQStpList.h"

/******************************************************************************
 class FmncQStpList
 ******************************************************************************/

FmncQStpList::FmncQStpList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refFmncMActivity
			, const string stubRefFmncMActivity
			, const uint rlvIxVTbl
			, const string srefRlvIxVTbl
			, const string titRlvIxVTbl
			, const ubigint rlvUref
			, const string stubRlvUref
			, const ubigint tplRefFmncMStep
			, const string stubTplRefFmncMStep
			, const uint start
			, const string ftmStart
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->refFmncMActivity = refFmncMActivity;
	this->stubRefFmncMActivity = stubRefFmncMActivity;
	this->rlvIxVTbl = rlvIxVTbl;
	this->srefRlvIxVTbl = srefRlvIxVTbl;
	this->titRlvIxVTbl = titRlvIxVTbl;
	this->rlvUref = rlvUref;
	this->stubRlvUref = stubRlvUref;
	this->tplRefFmncMStep = tplRefFmncMStep;
	this->stubTplRefFmncMStep = stubTplRefFmncMStep;
	this->start = start;
	this->ftmStart = ftmStart;
};

void FmncQStpList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQStpList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "act", stubRefFmncMActivity);
		writeString(wr, "rlt", srefRlvIxVTbl);
		writeString(wr, "rlt2", titRlvIxVTbl);
		writeString(wr, "rlu", stubRlvUref);
		writeString(wr, "stp", stubTplRefFmncMStep);
		writeString(wr, "sta", ftmStart);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefFmncMActivity", stubRefFmncMActivity);
		writeString(wr, "srefRlvIxVTbl", srefRlvIxVTbl);
		writeString(wr, "titRlvIxVTbl", titRlvIxVTbl);
		writeString(wr, "stubRlvUref", stubRlvUref);
		writeString(wr, "stubTplRefFmncMStep", stubTplRefFmncMStep);
		writeString(wr, "ftmStart", ftmStart);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQStpList
 ******************************************************************************/

ListFmncQStpList::ListFmncQStpList() {
};

ListFmncQStpList::ListFmncQStpList(
			const ListFmncQStpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpList(*(src.nodes[i]));
};

ListFmncQStpList::~ListFmncQStpList() {
	clear();
};

void ListFmncQStpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQStpList::size() const {
	return(nodes.size());
};

void ListFmncQStpList::append(
			FmncQStpList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQStpList& ListFmncQStpList::operator=(
			const ListFmncQStpList& src
		) {
	FmncQStpList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQStpList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQStpList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQStpList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQStpList
 ******************************************************************************/

TblFmncQStpList::TblFmncQStpList() {
};

TblFmncQStpList::~TblFmncQStpList() {
};

bool TblFmncQStpList::loadRecBySQL(
			const string& sqlstr
			, FmncQStpList** rec
		) {
	return false;
};

ubigint TblFmncQStpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQStpList& rst
		) {
	return 0;
};

void TblFmncQStpList::insertRec(
			FmncQStpList* rec
		) {
};

ubigint TblFmncQStpList::insertNewRec(
			FmncQStpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refFmncMActivity
			, const string stubRefFmncMActivity
			, const uint rlvIxVTbl
			, const string srefRlvIxVTbl
			, const string titRlvIxVTbl
			, const ubigint rlvUref
			, const string stubRlvUref
			, const ubigint tplRefFmncMStep
			, const string stubTplRefFmncMStep
			, const uint start
			, const string ftmStart
		) {
	ubigint retval = 0;
	FmncQStpList* _rec = NULL;

	_rec = new FmncQStpList(0, jref, jnum, ref, Title, refFmncMActivity, stubRefFmncMActivity, rlvIxVTbl, srefRlvIxVTbl, titRlvIxVTbl, rlvUref, stubRlvUref, tplRefFmncMStep, stubTplRefFmncMStep, start, ftmStart);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQStpList::appendNewRecToRst(
			ListFmncQStpList& rst
			, FmncQStpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refFmncMActivity
			, const string stubRefFmncMActivity
			, const uint rlvIxVTbl
			, const string srefRlvIxVTbl
			, const string titRlvIxVTbl
			, const ubigint rlvUref
			, const string stubRlvUref
			, const ubigint tplRefFmncMStep
			, const string stubTplRefFmncMStep
			, const uint start
			, const string ftmStart
		) {
	ubigint retval = 0;
	FmncQStpList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, refFmncMActivity, stubRefFmncMActivity, rlvIxVTbl, srefRlvIxVTbl, titRlvIxVTbl, rlvUref, stubRlvUref, tplRefFmncMStep, stubTplRefFmncMStep, start, ftmStart);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQStpList::insertRst(
			ListFmncQStpList& rst
		) {
};

void TblFmncQStpList::updateRec(
			FmncQStpList* rec
		) {
};

void TblFmncQStpList::updateRst(
			ListFmncQStpList& rst
		) {
};

void TblFmncQStpList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQStpList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQStpList::loadRecByQref(
			ubigint qref
			, FmncQStpList** rec
		) {
	return false;
};

ubigint TblFmncQStpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQStpList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQStpList
 ******************************************************************************/

MyTblFmncQStpList::MyTblFmncQStpList() : TblFmncQStpList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQStpList::~MyTblFmncQStpList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQStpList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQStpList (jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQStpList SET jref = ?, jnum = ?, ref = ?, Title = ?, refFmncMActivity = ?, rlvIxVTbl = ?, rlvUref = ?, tplRefFmncMStep = ?, start = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQStpList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQStpList WHERE jref = ?", false);
};

bool MyTblFmncQStpList::loadRecBySQL(
			const string& sqlstr
			, FmncQStpList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQStpList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQStpList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQStpList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->refFmncMActivity = atoll((char*) dbrow[5]); else _rec->refFmncMActivity = 0;
		if (dbrow[6]) _rec->rlvIxVTbl = atol((char*) dbrow[6]); else _rec->rlvIxVTbl = 0;
		if (dbrow[7]) _rec->rlvUref = atoll((char*) dbrow[7]); else _rec->rlvUref = 0;
		if (dbrow[8]) _rec->tplRefFmncMStep = atoll((char*) dbrow[8]); else _rec->tplRefFmncMStep = 0;
		if (dbrow[9]) _rec->start = atol((char*) dbrow[9]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQStpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQStpList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQStpList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQStpList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQStpList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->refFmncMActivity = atoll((char*) dbrow[5]); else rec->refFmncMActivity = 0;
			if (dbrow[6]) rec->rlvIxVTbl = atol((char*) dbrow[6]); else rec->rlvIxVTbl = 0;
			if (dbrow[7]) rec->rlvUref = atoll((char*) dbrow[7]); else rec->rlvUref = 0;
			if (dbrow[8]) rec->tplRefFmncMStep = atoll((char*) dbrow[8]); else rec->tplRefFmncMStep = 0;
			if (dbrow[9]) rec->start = atol((char*) dbrow[9]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQStpList::insertRec(
			FmncQStpList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMActivity,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->rlvIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->rlvUref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->tplRefFmncMStep,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->start,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQStpList::insertRst(
			ListFmncQStpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQStpList::updateRec(
			FmncQStpList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMActivity,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->rlvIxVTbl,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->rlvUref,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->tplRefFmncMStep,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->start,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpList / stmtUpdateRec)\n");
};

void MyTblFmncQStpList::updateRst(
			ListFmncQStpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQStpList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQStpList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQStpList::loadRecByQref(
			ubigint qref
			, FmncQStpList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQStpList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQStpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQStpList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQStpList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQStpList
 ******************************************************************************/

PgTblFmncQStpList::PgTblFmncQStpList() : TblFmncQStpList(), PgTable() {
};

PgTblFmncQStpList::~PgTblFmncQStpList() {
};

void PgTblFmncQStpList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQStpList_insertRec", "INSERT INTO TblFmncQStpList (jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpList_updateRec", "UPDATE TblFmncQStpList SET jref = $1, jnum = $2, ref = $3, Title = $4, refFmncMActivity = $5, rlvIxVTbl = $6, rlvUref = $7, tplRefFmncMStep = $8, start = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpList_removeRecByQref", "DELETE FROM TblFmncQStpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpList_removeRstByJref", "DELETE FROM TblFmncQStpList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQStpList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start FROM TblFmncQStpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start FROM TblFmncQStpList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQStpList::loadRec(
			PGresult* res
			, FmncQStpList** rec
		) {
	char* ptr;

	FmncQStpList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQStpList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "reffmncmactivity"),
			PQfnumber(res, "rlvixvtbl"),
			PQfnumber(res, "rlvuref"),
			PQfnumber(res, "tplreffmncmstep"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMActivity = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->rlvIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->rlvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->tplRefFmncMStep = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQStpList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQStpList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQStpList* rec;

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
			PQfnumber(res, "reffmncmactivity"),
			PQfnumber(res, "rlvixvtbl"),
			PQfnumber(res, "rlvuref"),
			PQfnumber(res, "tplreffmncmstep"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new FmncQStpList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMActivity = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->rlvIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->rlvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->tplRefFmncMStep = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQStpList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQStpList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQStpList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQStpList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQStpList::loadRecBySQL(
			const string& sqlstr
			, FmncQStpList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQStpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQStpList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQStpList::insertRec(
			FmncQStpList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMActivity = htonl64(rec->refFmncMActivity);
	uint _rlvIxVTbl = htonl(rec->rlvIxVTbl);
	ubigint _rlvUref = htonl64(rec->rlvUref);
	ubigint _tplRefFmncMStep = htonl64(rec->tplRefFmncMStep);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refFmncMActivity,
		(char*) &_rlvIxVTbl,
		(char*) &_rlvUref,
		(char*) &_tplRefFmncMStep,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQStpList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQStpList::insertRst(
			ListFmncQStpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQStpList::updateRec(
			FmncQStpList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMActivity = htonl64(rec->refFmncMActivity);
	uint _rlvIxVTbl = htonl(rec->rlvIxVTbl);
	ubigint _rlvUref = htonl64(rec->rlvUref);
	ubigint _tplRefFmncMStep = htonl64(rec->tplRefFmncMStep);
	uint _start = htonl(rec->start);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refFmncMActivity,
		(char*) &_rlvIxVTbl,
		(char*) &_rlvUref,
		(char*) &_tplRefFmncMStep,
		(char*) &_start,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQStpList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQStpList::updateRst(
			ListFmncQStpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQStpList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQStpList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQStpList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQStpList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQStpList::loadRecByQref(
			ubigint qref
			, FmncQStpList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQStpList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQStpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQStpList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQStpList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

