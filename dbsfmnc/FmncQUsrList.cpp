/**
  * \file FmncQUsrList.cpp
  * Dbs and XML wrapper for table TblFmncQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsrList.h"

/******************************************************************************
 class FmncQUsrList
 ******************************************************************************/

FmncQUsrList::FmncQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMPerson
			, const string stubRefFmncMPerson
			, const string sref
			, const ubigint refFmncMUsergroup
			, const string stubRefFmncMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixFmncVLocale
			, const string srefIxFmncVLocale
			, const string titIxFmncVLocale
			, const uint ixFmncVUserlevel
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->stubRefFmncMPerson = stubRefFmncMPerson;
	this->sref = sref;
	this->refFmncMUsergroup = refFmncMUsergroup;
	this->stubRefFmncMUsergroup = stubRefFmncMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixFmncVLocale = ixFmncVLocale;
	this->srefIxFmncVLocale = srefIxFmncVLocale;
	this->titIxFmncVLocale = titIxFmncVLocale;
	this->ixFmncVUserlevel = ixFmncVUserlevel;
	this->srefIxFmncVUserlevel = srefIxFmncVUserlevel;
	this->titIxFmncVUserlevel = titIxFmncVUserlevel;
};

void FmncQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prs", stubRefFmncMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefFmncMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxFmncVLocale);
		writeString(wr, "lcl2", titIxFmncVLocale);
		writeString(wr, "ulv", srefIxFmncVUserlevel);
		writeString(wr, "ulv2", titIxFmncVUserlevel);
	} else {
		writeString(wr, "stubRefFmncMPerson", stubRefFmncMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefFmncMUsergroup", stubRefFmncMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxFmncVLocale", srefIxFmncVLocale);
		writeString(wr, "titIxFmncVLocale", titIxFmncVLocale);
		writeString(wr, "srefIxFmncVUserlevel", srefIxFmncVUserlevel);
		writeString(wr, "titIxFmncVUserlevel", titIxFmncVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQUsrList
 ******************************************************************************/

ListFmncQUsrList::ListFmncQUsrList() {
};

ListFmncQUsrList::ListFmncQUsrList(
			const ListFmncQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrList(*(src.nodes[i]));
};

ListFmncQUsrList::~ListFmncQUsrList() {
	clear();
};

void ListFmncQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQUsrList::size() const {
	return(nodes.size());
};

void ListFmncQUsrList::append(
			FmncQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQUsrList& ListFmncQUsrList::operator=(
			const ListFmncQUsrList& src
		) {
	FmncQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQUsrList
 ******************************************************************************/

TblFmncQUsrList::TblFmncQUsrList() {
};

TblFmncQUsrList::~TblFmncQUsrList() {
};

bool TblFmncQUsrList::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrList** rec
		) {
	return false;
};

ubigint TblFmncQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrList& rst
		) {
	return 0;
};

void TblFmncQUsrList::insertRec(
			FmncQUsrList* rec
		) {
};

ubigint TblFmncQUsrList::insertNewRec(
			FmncQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMPerson
			, const string stubRefFmncMPerson
			, const string sref
			, const ubigint refFmncMUsergroup
			, const string stubRefFmncMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixFmncVLocale
			, const string srefIxFmncVLocale
			, const string titIxFmncVLocale
			, const uint ixFmncVUserlevel
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	ubigint retval = 0;
	FmncQUsrList* _rec = NULL;

	_rec = new FmncQUsrList(0, jref, jnum, ref, refFmncMPerson, stubRefFmncMPerson, sref, refFmncMUsergroup, stubRefFmncMUsergroup, ixVState, srefIxVState, titIxVState, ixFmncVLocale, srefIxFmncVLocale, titIxFmncVLocale, ixFmncVUserlevel, srefIxFmncVUserlevel, titIxFmncVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQUsrList::appendNewRecToRst(
			ListFmncQUsrList& rst
			, FmncQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMPerson
			, const string stubRefFmncMPerson
			, const string sref
			, const ubigint refFmncMUsergroup
			, const string stubRefFmncMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixFmncVLocale
			, const string srefIxFmncVLocale
			, const string titIxFmncVLocale
			, const uint ixFmncVUserlevel
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	ubigint retval = 0;
	FmncQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refFmncMPerson, stubRefFmncMPerson, sref, refFmncMUsergroup, stubRefFmncMUsergroup, ixVState, srefIxVState, titIxVState, ixFmncVLocale, srefIxFmncVLocale, titIxFmncVLocale, ixFmncVUserlevel, srefIxFmncVUserlevel, titIxFmncVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQUsrList::insertRst(
			ListFmncQUsrList& rst
		) {
};

void TblFmncQUsrList::updateRec(
			FmncQUsrList* rec
		) {
};

void TblFmncQUsrList::updateRst(
			ListFmncQUsrList& rst
		) {
};

void TblFmncQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQUsrList::loadRecByQref(
			ubigint qref
			, FmncQUsrList** rec
		) {
	return false;
};

ubigint TblFmncQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQUsrList
 ******************************************************************************/

MyTblFmncQUsrList::MyTblFmncQUsrList() : TblFmncQUsrList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQUsrList::~MyTblFmncQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQUsrList (jref, jnum, ref, refFmncMPerson, sref, refFmncMUsergroup, ixVState, ixFmncVLocale, ixFmncVUserlevel) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQUsrList SET jref = ?, jnum = ?, ref = ?, refFmncMPerson = ?, sref = ?, refFmncMUsergroup = ?, ixVState = ?, ixFmncVLocale = ?, ixFmncVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQUsrList WHERE jref = ?", false);
};

bool MyTblFmncQUsrList::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsrList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refFmncMPerson = atoll((char*) dbrow[4]); else _rec->refFmncMPerson = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->refFmncMUsergroup = atoll((char*) dbrow[6]); else _rec->refFmncMUsergroup = 0;
		if (dbrow[7]) _rec->ixVState = atol((char*) dbrow[7]); else _rec->ixVState = 0;
		if (dbrow[8]) _rec->ixFmncVLocale = atol((char*) dbrow[8]); else _rec->ixFmncVLocale = 0;
		if (dbrow[9]) _rec->ixFmncVUserlevel = atol((char*) dbrow[9]); else _rec->ixFmncVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQUsrList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refFmncMPerson = atoll((char*) dbrow[4]); else rec->refFmncMPerson = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->refFmncMUsergroup = atoll((char*) dbrow[6]); else rec->refFmncMUsergroup = 0;
			if (dbrow[7]) rec->ixVState = atol((char*) dbrow[7]); else rec->ixVState = 0;
			if (dbrow[8]) rec->ixFmncVLocale = atol((char*) dbrow[8]); else rec->ixFmncVLocale = 0;
			if (dbrow[9]) rec->ixFmncVUserlevel = atol((char*) dbrow[9]); else rec->ixFmncVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQUsrList::insertRec(
			FmncQUsrList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMUsergroup,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixFmncVLocale,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixFmncVUserlevel,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQUsrList::insertRst(
			ListFmncQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQUsrList::updateRec(
			FmncQUsrList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMUsergroup,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixVState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixFmncVLocale,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixFmncVUserlevel,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrList / stmtUpdateRec)\n");
};

void MyTblFmncQUsrList::updateRst(
			ListFmncQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQUsrList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQUsrList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQUsrList::loadRecByQref(
			ubigint qref
			, FmncQUsrList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQUsrList
 ******************************************************************************/

PgTblFmncQUsrList::PgTblFmncQUsrList() : TblFmncQUsrList(), PgTable() {
};

PgTblFmncQUsrList::~PgTblFmncQUsrList() {
};

void PgTblFmncQUsrList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQUsrList_insertRec", "INSERT INTO TblFmncQUsrList (jref, jnum, ref, refFmncMPerson, sref, refFmncMUsergroup, ixVState, ixFmncVLocale, ixFmncVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrList_updateRec", "UPDATE TblFmncQUsrList SET jref = $1, jnum = $2, ref = $3, refFmncMPerson = $4, sref = $5, refFmncMUsergroup = $6, ixVState = $7, ixFmncVLocale = $8, ixFmncVUserlevel = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrList_removeRecByQref", "DELETE FROM TblFmncQUsrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrList_removeRstByJref", "DELETE FROM TblFmncQUsrList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, refFmncMPerson, sref, refFmncMUsergroup, ixVState, ixFmncVLocale, ixFmncVUserlevel FROM TblFmncQUsrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, refFmncMPerson, sref, refFmncMUsergroup, ixVState, ixFmncVLocale, ixFmncVUserlevel FROM TblFmncQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQUsrList::loadRec(
			PGresult* res
			, FmncQUsrList** rec
		) {
	char* ptr;

	FmncQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixfmncvlocale"),
			PQfnumber(res, "ixfmncvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixFmncVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixFmncVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQUsrList* rec;

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
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixfmncvlocale"),
			PQfnumber(res, "ixfmncvuserlevel")
		};

		while (numread < numrow) {
			rec = new FmncQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixFmncVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixFmncVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQUsrList::loadRecBySQL(
			const string& sqlstr
			, FmncQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQUsrList::insertRec(
			FmncQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixFmncVLocale = htonl(rec->ixFmncVLocale);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refFmncMPerson,
		rec->sref.c_str(),
		(char*) &_refFmncMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixFmncVLocale,
		(char*) &_ixFmncVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQUsrList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQUsrList::insertRst(
			ListFmncQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQUsrList::updateRec(
			FmncQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixFmncVLocale = htonl(rec->ixFmncVLocale);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refFmncMPerson,
		rec->sref.c_str(),
		(char*) &_refFmncMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixFmncVLocale,
		(char*) &_ixFmncVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQUsrList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQUsrList::updateRst(
			ListFmncQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQUsrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQUsrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQUsrList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQUsrList::loadRecByQref(
			ubigint qref
			, FmncQUsrList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

