/**
  * \file FmncQPcoList.cpp
  * Dbs and XML wrapper for table TblFmncQPcoList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPcoList.h"

/******************************************************************************
 class FmncQPcoList
 ******************************************************************************/

FmncQPcoList::FmncQPcoList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint Date
			, const string ftmDate
			, const ubigint pcoRefFmncMOrg
			, const string stubPcoRefFmncMOrg
			, const ubigint splRefFmncMOrg
			, const string stubSplRefFmncMOrg
			, const ubigint refFmncMFile
			, const string stubRefFmncMFile
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const double Amount
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Date = Date;
	this->ftmDate = ftmDate;
	this->pcoRefFmncMOrg = pcoRefFmncMOrg;
	this->stubPcoRefFmncMOrg = stubPcoRefFmncMOrg;
	this->splRefFmncMOrg = splRefFmncMOrg;
	this->stubSplRefFmncMOrg = stubSplRefFmncMOrg;
	this->refFmncMFile = refFmncMFile;
	this->stubRefFmncMFile = stubRefFmncMFile;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->Amount = Amount;
};

void FmncQPcoList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQPcoList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "dat", ftmDate);
		writeString(wr, "pco", stubPcoRefFmncMOrg);
		writeString(wr, "spl", stubSplRefFmncMOrg);
		writeString(wr, "fil", stubRefFmncMFile);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeDouble(wr, "amt", Amount);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "ftmDate", ftmDate);
		writeString(wr, "stubPcoRefFmncMOrg", stubPcoRefFmncMOrg);
		writeString(wr, "stubSplRefFmncMOrg", stubSplRefFmncMOrg);
		writeString(wr, "stubRefFmncMFile", stubRefFmncMFile);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeDouble(wr, "Amount", Amount);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQPcoList
 ******************************************************************************/

ListFmncQPcoList::ListFmncQPcoList() {
};

ListFmncQPcoList::ListFmncQPcoList(
			const ListFmncQPcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPcoList(*(src.nodes[i]));
};

ListFmncQPcoList::~ListFmncQPcoList() {
	clear();
};

void ListFmncQPcoList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQPcoList::size() const {
	return(nodes.size());
};

void ListFmncQPcoList::append(
			FmncQPcoList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQPcoList& ListFmncQPcoList::operator=(
			const ListFmncQPcoList& src
		) {
	FmncQPcoList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQPcoList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQPcoList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQPcoList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQPcoList
 ******************************************************************************/

TblFmncQPcoList::TblFmncQPcoList() {
};

TblFmncQPcoList::~TblFmncQPcoList() {
};

bool TblFmncQPcoList::loadRecBySQL(
			const string& sqlstr
			, FmncQPcoList** rec
		) {
	return false;
};

ubigint TblFmncQPcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPcoList& rst
		) {
	return 0;
};

void TblFmncQPcoList::insertRec(
			FmncQPcoList* rec
		) {
};

ubigint TblFmncQPcoList::insertNewRec(
			FmncQPcoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint Date
			, const string ftmDate
			, const ubigint pcoRefFmncMOrg
			, const string stubPcoRefFmncMOrg
			, const ubigint splRefFmncMOrg
			, const string stubSplRefFmncMOrg
			, const ubigint refFmncMFile
			, const string stubRefFmncMFile
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const double Amount
		) {
	ubigint retval = 0;
	FmncQPcoList* _rec = NULL;

	_rec = new FmncQPcoList(0, jref, jnum, ref, sref, Date, ftmDate, pcoRefFmncMOrg, stubPcoRefFmncMOrg, splRefFmncMOrg, stubSplRefFmncMOrg, refFmncMFile, stubRefFmncMFile, ixVState, srefIxVState, titIxVState, Amount);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQPcoList::appendNewRecToRst(
			ListFmncQPcoList& rst
			, FmncQPcoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint Date
			, const string ftmDate
			, const ubigint pcoRefFmncMOrg
			, const string stubPcoRefFmncMOrg
			, const ubigint splRefFmncMOrg
			, const string stubSplRefFmncMOrg
			, const ubigint refFmncMFile
			, const string stubRefFmncMFile
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const double Amount
		) {
	ubigint retval = 0;
	FmncQPcoList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Date, ftmDate, pcoRefFmncMOrg, stubPcoRefFmncMOrg, splRefFmncMOrg, stubSplRefFmncMOrg, refFmncMFile, stubRefFmncMFile, ixVState, srefIxVState, titIxVState, Amount);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQPcoList::insertRst(
			ListFmncQPcoList& rst
		) {
};

void TblFmncQPcoList::updateRec(
			FmncQPcoList* rec
		) {
};

void TblFmncQPcoList::updateRst(
			ListFmncQPcoList& rst
		) {
};

void TblFmncQPcoList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQPcoList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQPcoList::loadRecByQref(
			ubigint qref
			, FmncQPcoList** rec
		) {
	return false;
};

ubigint TblFmncQPcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPcoList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQPcoList
 ******************************************************************************/

MyTblFmncQPcoList::MyTblFmncQPcoList() : TblFmncQPcoList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQPcoList::~MyTblFmncQPcoList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQPcoList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQPcoList (jref, jnum, ref, sref, Date, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, ixVState, Amount) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQPcoList SET jref = ?, jnum = ?, ref = ?, sref = ?, Date = ?, pcoRefFmncMOrg = ?, splRefFmncMOrg = ?, refFmncMFile = ?, ixVState = ?, Amount = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQPcoList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQPcoList WHERE jref = ?", false);
};

bool MyTblFmncQPcoList::loadRecBySQL(
			const string& sqlstr
			, FmncQPcoList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQPcoList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPcoList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQPcoList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Date = atol((char*) dbrow[5]); else _rec->Date = 0;
		if (dbrow[6]) _rec->pcoRefFmncMOrg = atoll((char*) dbrow[6]); else _rec->pcoRefFmncMOrg = 0;
		if (dbrow[7]) _rec->splRefFmncMOrg = atoll((char*) dbrow[7]); else _rec->splRefFmncMOrg = 0;
		if (dbrow[8]) _rec->refFmncMFile = atoll((char*) dbrow[8]); else _rec->refFmncMFile = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->Amount = atof((char*) dbrow[10]); else _rec->Amount = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQPcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPcoList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQPcoList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPcoList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQPcoList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Date = atol((char*) dbrow[5]); else rec->Date = 0;
			if (dbrow[6]) rec->pcoRefFmncMOrg = atoll((char*) dbrow[6]); else rec->pcoRefFmncMOrg = 0;
			if (dbrow[7]) rec->splRefFmncMOrg = atoll((char*) dbrow[7]); else rec->splRefFmncMOrg = 0;
			if (dbrow[8]) rec->refFmncMFile = atoll((char*) dbrow[8]); else rec->refFmncMFile = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->Amount = atof((char*) dbrow[10]); else rec->Amount = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQPcoList::insertRec(
			FmncQPcoList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->Date,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->pcoRefFmncMOrg,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->splRefFmncMOrg,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refFmncMFile,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->Amount,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQPcoList::insertRst(
			ListFmncQPcoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQPcoList::updateRec(
			FmncQPcoList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->Date,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->pcoRefFmncMOrg,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->splRefFmncMOrg,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->refFmncMFile,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])), 
		bindDouble(&rec->Amount,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoList / stmtUpdateRec)\n");
};

void MyTblFmncQPcoList::updateRst(
			ListFmncQPcoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQPcoList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQPcoList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQPcoList::loadRecByQref(
			ubigint qref
			, FmncQPcoList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQPcoList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQPcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPcoList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQPcoList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQPcoList
 ******************************************************************************/

PgTblFmncQPcoList::PgTblFmncQPcoList() : TblFmncQPcoList(), PgTable() {
};

PgTblFmncQPcoList::~PgTblFmncQPcoList() {
};

void PgTblFmncQPcoList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQPcoList_insertRec", "INSERT INTO TblFmncQPcoList (jref, jnum, ref, sref, Date, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, ixVState, Amount) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoList_updateRec", "UPDATE TblFmncQPcoList SET jref = $1, jnum = $2, ref = $3, sref = $4, Date = $5, pcoRefFmncMOrg = $6, splRefFmncMOrg = $7, refFmncMFile = $8, ixVState = $9, Amount = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoList_removeRecByQref", "DELETE FROM TblFmncQPcoList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoList_removeRstByJref", "DELETE FROM TblFmncQPcoList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQPcoList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Date, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, ixVState, Amount FROM TblFmncQPcoList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Date, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, ixVState, Amount FROM TblFmncQPcoList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQPcoList::loadRec(
			PGresult* res
			, FmncQPcoList** rec
		) {
	char* ptr;

	FmncQPcoList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQPcoList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "pcoreffmncmorg"),
			PQfnumber(res, "splreffmncmorg"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "amount")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Date = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->pcoRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->splRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refFmncMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Amount = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQPcoList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQPcoList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQPcoList* rec;

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
			PQfnumber(res, "pcoreffmncmorg"),
			PQfnumber(res, "splreffmncmorg"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "amount")
		};

		while (numread < numrow) {
			rec = new FmncQPcoList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Date = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->pcoRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->splRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refFmncMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Amount = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQPcoList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQPcoList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPcoList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQPcoList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQPcoList::loadRecBySQL(
			const string& sqlstr
			, FmncQPcoList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPcoList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQPcoList::insertRec(
			FmncQPcoList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _Date = htonl(rec->Date);
	ubigint _pcoRefFmncMOrg = htonl64(rec->pcoRefFmncMOrg);
	ubigint _splRefFmncMOrg = htonl64(rec->splRefFmncMOrg);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _ixVState = htonl(rec->ixVState);
	string _Amount = to_string(rec->Amount);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_pcoRefFmncMOrg,
		(char*) &_splRefFmncMOrg,
		(char*) &_refFmncMFile,
		(char*) &_ixVState,
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
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQPcoList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQPcoList::insertRst(
			ListFmncQPcoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQPcoList::updateRec(
			FmncQPcoList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _Date = htonl(rec->Date);
	ubigint _pcoRefFmncMOrg = htonl64(rec->pcoRefFmncMOrg);
	ubigint _splRefFmncMOrg = htonl64(rec->splRefFmncMOrg);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _ixVState = htonl(rec->ixVState);
	string _Amount = to_string(rec->Amount);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_pcoRefFmncMOrg,
		(char*) &_splRefFmncMOrg,
		(char*) &_refFmncMFile,
		(char*) &_ixVState,
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
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQPcoList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQPcoList::updateRst(
			ListFmncQPcoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQPcoList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQPcoList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQPcoList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQPcoList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQPcoList::loadRecByQref(
			ubigint qref
			, FmncQPcoList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQPcoList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQPcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPcoList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQPcoList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

