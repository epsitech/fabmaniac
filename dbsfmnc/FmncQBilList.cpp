/**
  * \file FmncQBilList.cpp
  * Dbs and XML wrapper for table TblFmncQBilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQBilList.h"

/******************************************************************************
 class FmncQBilList
 ******************************************************************************/

FmncQBilList::FmncQBilList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint Date
			, const string ftmDate
			, const ubigint refFmncMFabproject
			, const string stubRefFmncMFabproject
			, const ubigint refFmncMFile
			, const string stubRefFmncMFile
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint Prdstart
			, const string ftmPrdstart
			, const uint Prdstop
			, const string ftmPrdstop
			, const double Amount
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Date = Date;
	this->ftmDate = ftmDate;
	this->refFmncMFabproject = refFmncMFabproject;
	this->stubRefFmncMFabproject = stubRefFmncMFabproject;
	this->refFmncMFile = refFmncMFile;
	this->stubRefFmncMFile = stubRefFmncMFile;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->Prdstart = Prdstart;
	this->ftmPrdstart = ftmPrdstart;
	this->Prdstop = Prdstop;
	this->ftmPrdstop = ftmPrdstop;
	this->Amount = Amount;
};

void FmncQBilList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQBilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "dat", ftmDate);
		writeString(wr, "prj", stubRefFmncMFabproject);
		writeString(wr, "fil", stubRefFmncMFile);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "pra", ftmPrdstart);
		writeString(wr, "pro", ftmPrdstop);
		writeDouble(wr, "amt", Amount);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "ftmDate", ftmDate);
		writeString(wr, "stubRefFmncMFabproject", stubRefFmncMFabproject);
		writeString(wr, "stubRefFmncMFile", stubRefFmncMFile);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "ftmPrdstart", ftmPrdstart);
		writeString(wr, "ftmPrdstop", ftmPrdstop);
		writeDouble(wr, "Amount", Amount);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQBilList
 ******************************************************************************/

ListFmncQBilList::ListFmncQBilList() {
};

ListFmncQBilList::ListFmncQBilList(
			const ListFmncQBilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQBilList(*(src.nodes[i]));
};

ListFmncQBilList::~ListFmncQBilList() {
	clear();
};

void ListFmncQBilList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQBilList::size() const {
	return(nodes.size());
};

void ListFmncQBilList::append(
			FmncQBilList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQBilList& ListFmncQBilList::operator=(
			const ListFmncQBilList& src
		) {
	FmncQBilList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQBilList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQBilList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQBilList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQBilList
 ******************************************************************************/

TblFmncQBilList::TblFmncQBilList() {
};

TblFmncQBilList::~TblFmncQBilList() {
};

bool TblFmncQBilList::loadRecBySQL(
			const string& sqlstr
			, FmncQBilList** rec
		) {
	return false;
};

ubigint TblFmncQBilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQBilList& rst
		) {
	return 0;
};

void TblFmncQBilList::insertRec(
			FmncQBilList* rec
		) {
};

ubigint TblFmncQBilList::insertNewRec(
			FmncQBilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint Date
			, const string ftmDate
			, const ubigint refFmncMFabproject
			, const string stubRefFmncMFabproject
			, const ubigint refFmncMFile
			, const string stubRefFmncMFile
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint Prdstart
			, const string ftmPrdstart
			, const uint Prdstop
			, const string ftmPrdstop
			, const double Amount
		) {
	ubigint retval = 0;
	FmncQBilList* _rec = NULL;

	_rec = new FmncQBilList(0, jref, jnum, ref, sref, Date, ftmDate, refFmncMFabproject, stubRefFmncMFabproject, refFmncMFile, stubRefFmncMFile, ixVState, srefIxVState, titIxVState, Prdstart, ftmPrdstart, Prdstop, ftmPrdstop, Amount);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQBilList::appendNewRecToRst(
			ListFmncQBilList& rst
			, FmncQBilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint Date
			, const string ftmDate
			, const ubigint refFmncMFabproject
			, const string stubRefFmncMFabproject
			, const ubigint refFmncMFile
			, const string stubRefFmncMFile
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint Prdstart
			, const string ftmPrdstart
			, const uint Prdstop
			, const string ftmPrdstop
			, const double Amount
		) {
	ubigint retval = 0;
	FmncQBilList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Date, ftmDate, refFmncMFabproject, stubRefFmncMFabproject, refFmncMFile, stubRefFmncMFile, ixVState, srefIxVState, titIxVState, Prdstart, ftmPrdstart, Prdstop, ftmPrdstop, Amount);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQBilList::insertRst(
			ListFmncQBilList& rst
		) {
};

void TblFmncQBilList::updateRec(
			FmncQBilList* rec
		) {
};

void TblFmncQBilList::updateRst(
			ListFmncQBilList& rst
		) {
};

void TblFmncQBilList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQBilList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQBilList::loadRecByQref(
			ubigint qref
			, FmncQBilList** rec
		) {
	return false;
};

ubigint TblFmncQBilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQBilList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQBilList
 ******************************************************************************/

MyTblFmncQBilList::MyTblFmncQBilList() : TblFmncQBilList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQBilList::~MyTblFmncQBilList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQBilList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQBilList (jref, jnum, ref, sref, Date, refFmncMFabproject, refFmncMFile, ixVState, Prdstart, Prdstop, Amount) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQBilList SET jref = ?, jnum = ?, ref = ?, sref = ?, Date = ?, refFmncMFabproject = ?, refFmncMFile = ?, ixVState = ?, Prdstart = ?, Prdstop = ?, Amount = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQBilList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQBilList WHERE jref = ?", false);
};

bool MyTblFmncQBilList::loadRecBySQL(
			const string& sqlstr
			, FmncQBilList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQBilList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQBilList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQBilList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Date = atol((char*) dbrow[5]); else _rec->Date = 0;
		if (dbrow[6]) _rec->refFmncMFabproject = atoll((char*) dbrow[6]); else _rec->refFmncMFabproject = 0;
		if (dbrow[7]) _rec->refFmncMFile = atoll((char*) dbrow[7]); else _rec->refFmncMFile = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->Prdstart = atol((char*) dbrow[9]); else _rec->Prdstart = 0;
		if (dbrow[10]) _rec->Prdstop = atol((char*) dbrow[10]); else _rec->Prdstop = 0;
		if (dbrow[11]) _rec->Amount = atof((char*) dbrow[11]); else _rec->Amount = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQBilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQBilList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQBilList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQBilList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQBilList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Date = atol((char*) dbrow[5]); else rec->Date = 0;
			if (dbrow[6]) rec->refFmncMFabproject = atoll((char*) dbrow[6]); else rec->refFmncMFabproject = 0;
			if (dbrow[7]) rec->refFmncMFile = atoll((char*) dbrow[7]); else rec->refFmncMFile = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->Prdstart = atol((char*) dbrow[9]); else rec->Prdstart = 0;
			if (dbrow[10]) rec->Prdstop = atol((char*) dbrow[10]); else rec->Prdstop = 0;
			if (dbrow[11]) rec->Amount = atof((char*) dbrow[11]); else rec->Amount = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQBilList::insertRec(
			FmncQBilList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->Date,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMFabproject,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refFmncMFile,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->Prdstart,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->Prdstop,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->Amount,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQBilList::insertRst(
			ListFmncQBilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQBilList::updateRec(
			FmncQBilList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->Date,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMFabproject,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refFmncMFile,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->Prdstart,&(l[8]),&(n[8]),&(e[8])), 
		bindUint(&rec->Prdstop,&(l[9]),&(n[9]),&(e[9])), 
		bindDouble(&rec->Amount,&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilList / stmtUpdateRec)\n");
};

void MyTblFmncQBilList::updateRst(
			ListFmncQBilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQBilList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQBilList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQBilList::loadRecByQref(
			ubigint qref
			, FmncQBilList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQBilList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQBilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQBilList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQBilList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQBilList
 ******************************************************************************/

PgTblFmncQBilList::PgTblFmncQBilList() : TblFmncQBilList(), PgTable() {
};

PgTblFmncQBilList::~PgTblFmncQBilList() {
};

void PgTblFmncQBilList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQBilList_insertRec", "INSERT INTO TblFmncQBilList (jref, jnum, ref, sref, Date, refFmncMFabproject, refFmncMFile, ixVState, Prdstart, Prdstop, Amount) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilList_updateRec", "UPDATE TblFmncQBilList SET jref = $1, jnum = $2, ref = $3, sref = $4, Date = $5, refFmncMFabproject = $6, refFmncMFile = $7, ixVState = $8, Prdstart = $9, Prdstop = $10, Amount = $11 WHERE qref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilList_removeRecByQref", "DELETE FROM TblFmncQBilList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilList_removeRstByJref", "DELETE FROM TblFmncQBilList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQBilList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Date, refFmncMFabproject, refFmncMFile, ixVState, Prdstart, Prdstop, Amount FROM TblFmncQBilList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Date, refFmncMFabproject, refFmncMFile, ixVState, Prdstart, Prdstop, Amount FROM TblFmncQBilList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQBilList::loadRec(
			PGresult* res
			, FmncQBilList** rec
		) {
	char* ptr;

	FmncQBilList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQBilList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "prdstart"),
			PQfnumber(res, "prdstop"),
			PQfnumber(res, "amount")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Date = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refFmncMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Prdstart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Prdstop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Amount = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQBilList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQBilList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQBilList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "prdstart"),
			PQfnumber(res, "prdstop"),
			PQfnumber(res, "amount")
		};

		while (numread < numrow) {
			rec = new FmncQBilList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Date = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refFmncMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Prdstart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Prdstop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Amount = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQBilList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQBilList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQBilList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQBilList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQBilList::loadRecBySQL(
			const string& sqlstr
			, FmncQBilList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQBilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQBilList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQBilList::insertRec(
			FmncQBilList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _Date = htonl(rec->Date);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _ixVState = htonl(rec->ixVState);
	uint _Prdstart = htonl(rec->Prdstart);
	uint _Prdstop = htonl(rec->Prdstop);
	string _Amount = to_string(rec->Amount);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_refFmncMFabproject,
		(char*) &_refFmncMFile,
		(char*) &_ixVState,
		(char*) &_Prdstart,
		(char*) &_Prdstop,
		_Amount.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQBilList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQBilList::insertRst(
			ListFmncQBilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQBilList::updateRec(
			FmncQBilList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _Date = htonl(rec->Date);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _ixVState = htonl(rec->ixVState);
	uint _Prdstart = htonl(rec->Prdstart);
	uint _Prdstop = htonl(rec->Prdstop);
	string _Amount = to_string(rec->Amount);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_refFmncMFabproject,
		(char*) &_refFmncMFile,
		(char*) &_ixVState,
		(char*) &_Prdstart,
		(char*) &_Prdstop,
		_Amount.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQBilList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQBilList::updateRst(
			ListFmncQBilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQBilList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQBilList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQBilList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQBilList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQBilList::loadRecByQref(
			ubigint qref
			, FmncQBilList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQBilList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQBilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQBilList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQBilList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

