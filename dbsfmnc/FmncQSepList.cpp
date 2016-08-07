/**
  * \file FmncQSepList.cpp
  * Dbs and XML wrapper for table TblFmncQSepList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSepList.h"

/******************************************************************************
 class FmncQSepList
 ******************************************************************************/

FmncQSepList::FmncQSepList(
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

void FmncQSepList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSepList";

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
 class ListFmncQSepList
 ******************************************************************************/

ListFmncQSepList::ListFmncQSepList() {
};

ListFmncQSepList::ListFmncQSepList(
			const ListFmncQSepList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepList(*(src.nodes[i]));
};

ListFmncQSepList::~ListFmncQSepList() {
	clear();
};

void ListFmncQSepList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSepList::size() const {
	return(nodes.size());
};

void ListFmncQSepList::append(
			FmncQSepList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSepList& ListFmncQSepList::operator=(
			const ListFmncQSepList& src
		) {
	FmncQSepList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSepList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSepList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSepList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSepList
 ******************************************************************************/

TblFmncQSepList::TblFmncQSepList() {
};

TblFmncQSepList::~TblFmncQSepList() {
};

bool TblFmncQSepList::loadRecBySQL(
			const string& sqlstr
			, FmncQSepList** rec
		) {
	return false;
};

ubigint TblFmncQSepList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepList& rst
		) {
	return 0;
};

void TblFmncQSepList::insertRec(
			FmncQSepList* rec
		) {
};

ubigint TblFmncQSepList::insertNewRec(
			FmncQSepList** rec
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
	FmncQSepList* _rec = NULL;

	_rec = new FmncQSepList(0, jref, jnum, ref, Title, refFmncMActivity, stubRefFmncMActivity, rlvIxVTbl, srefRlvIxVTbl, titRlvIxVTbl, rlvUref, stubRlvUref, tplRefFmncMStep, stubTplRefFmncMStep, start, ftmStart);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSepList::appendNewRecToRst(
			ListFmncQSepList& rst
			, FmncQSepList** rec
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
	FmncQSepList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, refFmncMActivity, stubRefFmncMActivity, rlvIxVTbl, srefRlvIxVTbl, titRlvIxVTbl, rlvUref, stubRlvUref, tplRefFmncMStep, stubTplRefFmncMStep, start, ftmStart);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSepList::insertRst(
			ListFmncQSepList& rst
		) {
};

void TblFmncQSepList::updateRec(
			FmncQSepList* rec
		) {
};

void TblFmncQSepList::updateRst(
			ListFmncQSepList& rst
		) {
};

void TblFmncQSepList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSepList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSepList::loadRecByQref(
			ubigint qref
			, FmncQSepList** rec
		) {
	return false;
};

ubigint TblFmncQSepList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSepList
 ******************************************************************************/

MyTblFmncQSepList::MyTblFmncQSepList() : TblFmncQSepList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSepList::~MyTblFmncQSepList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSepList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSepList (jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSepList SET jref = ?, jnum = ?, ref = ?, Title = ?, refFmncMActivity = ?, rlvIxVTbl = ?, rlvUref = ?, tplRefFmncMStep = ?, start = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSepList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSepList WHERE jref = ?", false);
};

bool MyTblFmncQSepList::loadRecBySQL(
			const string& sqlstr
			, FmncQSepList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSepList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSepList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSepList();

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

ubigint MyTblFmncQSepList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSepList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSepList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSepList();

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

void MyTblFmncQSepList::insertRec(
			FmncQSepList* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSepList::insertRst(
			ListFmncQSepList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSepList::updateRec(
			FmncQSepList* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepList / stmtUpdateRec)\n");
};

void MyTblFmncQSepList::updateRst(
			ListFmncQSepList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSepList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSepList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSepList::loadRecByQref(
			ubigint qref
			, FmncQSepList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSepList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSepList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSepList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSepList
 ******************************************************************************/

PgTblFmncQSepList::PgTblFmncQSepList() : TblFmncQSepList(), PgTable() {
};

PgTblFmncQSepList::~PgTblFmncQSepList() {
};

void PgTblFmncQSepList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSepList_insertRec", "INSERT INTO TblFmncQSepList (jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepList_updateRec", "UPDATE TblFmncQSepList SET jref = $1, jnum = $2, ref = $3, Title = $4, refFmncMActivity = $5, rlvIxVTbl = $6, rlvUref = $7, tplRefFmncMStep = $8, start = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepList_removeRecByQref", "DELETE FROM TblFmncQSepList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepList_removeRstByJref", "DELETE FROM TblFmncQSepList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSepList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start FROM TblFmncQSepList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, start FROM TblFmncQSepList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSepList::loadRec(
			PGresult* res
			, FmncQSepList** rec
		) {
	char* ptr;

	FmncQSepList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSepList();

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

ubigint PgTblFmncQSepList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSepList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSepList* rec;

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
			rec = new FmncQSepList();

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

bool PgTblFmncQSepList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSepList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSepList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSepList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSepList::loadRecBySQL(
			const string& sqlstr
			, FmncQSepList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSepList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSepList::insertRec(
			FmncQSepList* rec
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

	res = PQexecPrepared(dbs, "TblFmncQSepList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSepList::insertRst(
			ListFmncQSepList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSepList::updateRec(
			FmncQSepList* rec
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

	res = PQexecPrepared(dbs, "TblFmncQSepList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSepList::updateRst(
			ListFmncQSepList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSepList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSepList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSepList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSepList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSepList::loadRecByQref(
			ubigint qref
			, FmncQSepList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSepList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSepList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSepList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

