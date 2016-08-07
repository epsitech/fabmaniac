/**
  * \file FmncQFusList.cpp
  * Dbs and XML wrapper for table TblFmncQFusList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFusList.h"

/******************************************************************************
 class FmncQFusList
 ******************************************************************************/

FmncQFusList::FmncQFusList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMPerson
			, const string stubRefFmncMPerson
			, const string sref
			, const ubigint refFmncMFab
			, const string stubRefFmncMFab
			, const ubigint refFmncMFabproject
			, const string stubRefFmncMFabproject
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->stubRefFmncMPerson = stubRefFmncMPerson;
	this->sref = sref;
	this->refFmncMFab = refFmncMFab;
	this->stubRefFmncMFab = stubRefFmncMFab;
	this->refFmncMFabproject = refFmncMFabproject;
	this->stubRefFmncMFabproject = stubRefFmncMFabproject;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

void FmncQFusList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFusList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prs", stubRefFmncMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "fab", stubRefFmncMFab);
		writeString(wr, "fpj", stubRefFmncMFabproject);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
	} else {
		writeString(wr, "stubRefFmncMPerson", stubRefFmncMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefFmncMFab", stubRefFmncMFab);
		writeString(wr, "stubRefFmncMFabproject", stubRefFmncMFabproject);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQFusList
 ******************************************************************************/

ListFmncQFusList::ListFmncQFusList() {
};

ListFmncQFusList::ListFmncQFusList(
			const ListFmncQFusList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusList(*(src.nodes[i]));
};

ListFmncQFusList::~ListFmncQFusList() {
	clear();
};

void ListFmncQFusList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFusList::size() const {
	return(nodes.size());
};

void ListFmncQFusList::append(
			FmncQFusList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFusList& ListFmncQFusList::operator=(
			const ListFmncQFusList& src
		) {
	FmncQFusList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFusList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFusList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFusList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFusList
 ******************************************************************************/

TblFmncQFusList::TblFmncQFusList() {
};

TblFmncQFusList::~TblFmncQFusList() {
};

bool TblFmncQFusList::loadRecBySQL(
			const string& sqlstr
			, FmncQFusList** rec
		) {
	return false;
};

ubigint TblFmncQFusList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusList& rst
		) {
	return 0;
};

void TblFmncQFusList::insertRec(
			FmncQFusList* rec
		) {
};

ubigint TblFmncQFusList::insertNewRec(
			FmncQFusList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMPerson
			, const string stubRefFmncMPerson
			, const string sref
			, const ubigint refFmncMFab
			, const string stubRefFmncMFab
			, const ubigint refFmncMFabproject
			, const string stubRefFmncMFabproject
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQFusList* _rec = NULL;

	_rec = new FmncQFusList(0, jref, jnum, ref, refFmncMPerson, stubRefFmncMPerson, sref, refFmncMFab, stubRefFmncMFab, refFmncMFabproject, stubRefFmncMFabproject, ixVState, srefIxVState, titIxVState);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFusList::appendNewRecToRst(
			ListFmncQFusList& rst
			, FmncQFusList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMPerson
			, const string stubRefFmncMPerson
			, const string sref
			, const ubigint refFmncMFab
			, const string stubRefFmncMFab
			, const ubigint refFmncMFabproject
			, const string stubRefFmncMFabproject
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQFusList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refFmncMPerson, stubRefFmncMPerson, sref, refFmncMFab, stubRefFmncMFab, refFmncMFabproject, stubRefFmncMFabproject, ixVState, srefIxVState, titIxVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFusList::insertRst(
			ListFmncQFusList& rst
		) {
};

void TblFmncQFusList::updateRec(
			FmncQFusList* rec
		) {
};

void TblFmncQFusList::updateRst(
			ListFmncQFusList& rst
		) {
};

void TblFmncQFusList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFusList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFusList::loadRecByQref(
			ubigint qref
			, FmncQFusList** rec
		) {
	return false;
};

ubigint TblFmncQFusList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFusList
 ******************************************************************************/

MyTblFmncQFusList::MyTblFmncQFusList() : TblFmncQFusList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFusList::~MyTblFmncQFusList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFusList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFusList (jref, jnum, ref, refFmncMPerson, sref, refFmncMFab, refFmncMFabproject, ixVState) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFusList SET jref = ?, jnum = ?, ref = ?, refFmncMPerson = ?, sref = ?, refFmncMFab = ?, refFmncMFabproject = ?, ixVState = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFusList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFusList WHERE jref = ?", false);
};

bool MyTblFmncQFusList::loadRecBySQL(
			const string& sqlstr
			, FmncQFusList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFusList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFusList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFusList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refFmncMPerson = atoll((char*) dbrow[4]); else _rec->refFmncMPerson = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->refFmncMFab = atoll((char*) dbrow[6]); else _rec->refFmncMFab = 0;
		if (dbrow[7]) _rec->refFmncMFabproject = atoll((char*) dbrow[7]); else _rec->refFmncMFabproject = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQFusList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFusList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFusList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFusList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refFmncMPerson = atoll((char*) dbrow[4]); else rec->refFmncMPerson = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->refFmncMFab = atoll((char*) dbrow[6]); else rec->refFmncMFab = 0;
			if (dbrow[7]) rec->refFmncMFabproject = atoll((char*) dbrow[7]); else rec->refFmncMFabproject = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQFusList::insertRec(
			FmncQFusList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMFab,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refFmncMFabproject,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFusList::insertRst(
			ListFmncQFusList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFusList::updateRec(
			FmncQFusList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMFab,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refFmncMFabproject,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusList / stmtUpdateRec)\n");
};

void MyTblFmncQFusList::updateRst(
			ListFmncQFusList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFusList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFusList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFusList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFusList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFusList::loadRecByQref(
			ubigint qref
			, FmncQFusList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFusList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFusList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFusList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFusList
 ******************************************************************************/

PgTblFmncQFusList::PgTblFmncQFusList() : TblFmncQFusList(), PgTable() {
};

PgTblFmncQFusList::~PgTblFmncQFusList() {
};

void PgTblFmncQFusList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFusList_insertRec", "INSERT INTO TblFmncQFusList (jref, jnum, ref, refFmncMPerson, sref, refFmncMFab, refFmncMFabproject, ixVState) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusList_updateRec", "UPDATE TblFmncQFusList SET jref = $1, jnum = $2, ref = $3, refFmncMPerson = $4, sref = $5, refFmncMFab = $6, refFmncMFabproject = $7, ixVState = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusList_removeRecByQref", "DELETE FROM TblFmncQFusList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusList_removeRstByJref", "DELETE FROM TblFmncQFusList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFusList_loadRecByQref", "SELECT qref, jref, jnum, ref, refFmncMPerson, sref, refFmncMFab, refFmncMFabproject, ixVState FROM TblFmncQFusList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFusList_loadRstByJref", "SELECT qref, jref, jnum, ref, refFmncMPerson, sref, refFmncMFab, refFmncMFabproject, ixVState FROM TblFmncQFusList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFusList::loadRec(
			PGresult* res
			, FmncQFusList** rec
		) {
	char* ptr;

	FmncQFusList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFusList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQFusList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFusList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFusList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncQFusList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQFusList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFusList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFusList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFusList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFusList::loadRecBySQL(
			const string& sqlstr
			, FmncQFusList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFusList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFusList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFusList::insertRec(
			FmncQFusList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refFmncMPerson,
		rec->sref.c_str(),
		(char*) &_refFmncMFab,
		(char*) &_refFmncMFabproject,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFusList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFusList::insertRst(
			ListFmncQFusList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFusList::updateRec(
			FmncQFusList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refFmncMPerson,
		rec->sref.c_str(),
		(char*) &_refFmncMFab,
		(char*) &_refFmncMFabproject,
		(char*) &_ixVState,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFusList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFusList::updateRst(
			ListFmncQFusList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFusList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFusList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFusList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFusList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFusList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFusList::loadRecByQref(
			ubigint qref
			, FmncQFusList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFusList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFusList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFusList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFusList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

