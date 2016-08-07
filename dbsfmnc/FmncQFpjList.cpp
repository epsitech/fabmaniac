/**
  * \file FmncQFpjList.cpp
  * Dbs and XML wrapper for table TblFmncQFpjList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFpjList.h"

/******************************************************************************
 class FmncQFpjList
 ******************************************************************************/

FmncQFpjList::FmncQFpjList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refFmncMFab
			, const string stubRefFmncMFab
			, const ubigint bioRefFmncMOrg
			, const string stubBioRefFmncMOrg
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->refFmncMFab = refFmncMFab;
	this->stubRefFmncMFab = stubRefFmncMFab;
	this->bioRefFmncMOrg = bioRefFmncMOrg;
	this->stubBioRefFmncMOrg = stubBioRefFmncMOrg;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

void FmncQFpjList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQFpjList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "fab", stubRefFmncMFab);
		writeString(wr, "bio", stubBioRefFmncMOrg);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefFmncMFab", stubRefFmncMFab);
		writeString(wr, "stubBioRefFmncMOrg", stubBioRefFmncMOrg);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQFpjList
 ******************************************************************************/

ListFmncQFpjList::ListFmncQFpjList() {
};

ListFmncQFpjList::ListFmncQFpjList(
			const ListFmncQFpjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpjList(*(src.nodes[i]));
};

ListFmncQFpjList::~ListFmncQFpjList() {
	clear();
};

void ListFmncQFpjList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQFpjList::size() const {
	return(nodes.size());
};

void ListFmncQFpjList::append(
			FmncQFpjList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQFpjList& ListFmncQFpjList::operator=(
			const ListFmncQFpjList& src
		) {
	FmncQFpjList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQFpjList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQFpjList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQFpjList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQFpjList
 ******************************************************************************/

TblFmncQFpjList::TblFmncQFpjList() {
};

TblFmncQFpjList::~TblFmncQFpjList() {
};

bool TblFmncQFpjList::loadRecBySQL(
			const string& sqlstr
			, FmncQFpjList** rec
		) {
	return false;
};

ubigint TblFmncQFpjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFpjList& rst
		) {
	return 0;
};

void TblFmncQFpjList::insertRec(
			FmncQFpjList* rec
		) {
};

ubigint TblFmncQFpjList::insertNewRec(
			FmncQFpjList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refFmncMFab
			, const string stubRefFmncMFab
			, const ubigint bioRefFmncMOrg
			, const string stubBioRefFmncMOrg
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQFpjList* _rec = NULL;

	_rec = new FmncQFpjList(0, jref, jnum, ref, sref, Title, refFmncMFab, stubRefFmncMFab, bioRefFmncMOrg, stubBioRefFmncMOrg, ixVState, srefIxVState, titIxVState);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQFpjList::appendNewRecToRst(
			ListFmncQFpjList& rst
			, FmncQFpjList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refFmncMFab
			, const string stubRefFmncMFab
			, const ubigint bioRefFmncMOrg
			, const string stubBioRefFmncMOrg
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQFpjList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, refFmncMFab, stubRefFmncMFab, bioRefFmncMOrg, stubBioRefFmncMOrg, ixVState, srefIxVState, titIxVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQFpjList::insertRst(
			ListFmncQFpjList& rst
		) {
};

void TblFmncQFpjList::updateRec(
			FmncQFpjList* rec
		) {
};

void TblFmncQFpjList::updateRst(
			ListFmncQFpjList& rst
		) {
};

void TblFmncQFpjList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQFpjList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQFpjList::loadRecByQref(
			ubigint qref
			, FmncQFpjList** rec
		) {
	return false;
};

ubigint TblFmncQFpjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFpjList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQFpjList
 ******************************************************************************/

MyTblFmncQFpjList::MyTblFmncQFpjList() : TblFmncQFpjList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQFpjList::~MyTblFmncQFpjList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQFpjList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQFpjList (jref, jnum, ref, sref, Title, refFmncMFab, bioRefFmncMOrg, ixVState) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQFpjList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, refFmncMFab = ?, bioRefFmncMOrg = ?, ixVState = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQFpjList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQFpjList WHERE jref = ?", false);
};

bool MyTblFmncQFpjList::loadRecBySQL(
			const string& sqlstr
			, FmncQFpjList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQFpjList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFpjList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQFpjList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->refFmncMFab = atoll((char*) dbrow[6]); else _rec->refFmncMFab = 0;
		if (dbrow[7]) _rec->bioRefFmncMOrg = atoll((char*) dbrow[7]); else _rec->bioRefFmncMOrg = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQFpjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFpjList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQFpjList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQFpjList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQFpjList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->refFmncMFab = atoll((char*) dbrow[6]); else rec->refFmncMFab = 0;
			if (dbrow[7]) rec->bioRefFmncMOrg = atoll((char*) dbrow[7]); else rec->bioRefFmncMOrg = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQFpjList::insertRec(
			FmncQFpjList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMFab,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->bioRefFmncMOrg,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFpjList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFpjList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQFpjList::insertRst(
			ListFmncQFpjList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQFpjList::updateRec(
			FmncQFpjList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMFab,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->bioRefFmncMOrg,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFpjList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFpjList / stmtUpdateRec)\n");
};

void MyTblFmncQFpjList::updateRst(
			ListFmncQFpjList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQFpjList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFpjList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFpjList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQFpjList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQFpjList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQFpjList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQFpjList::loadRecByQref(
			ubigint qref
			, FmncQFpjList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQFpjList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQFpjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFpjList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQFpjList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQFpjList
 ******************************************************************************/

PgTblFmncQFpjList::PgTblFmncQFpjList() : TblFmncQFpjList(), PgTable() {
};

PgTblFmncQFpjList::~PgTblFmncQFpjList() {
};

void PgTblFmncQFpjList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQFpjList_insertRec", "INSERT INTO TblFmncQFpjList (jref, jnum, ref, sref, Title, refFmncMFab, bioRefFmncMOrg, ixVState) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFpjList_updateRec", "UPDATE TblFmncQFpjList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, refFmncMFab = $6, bioRefFmncMOrg = $7, ixVState = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFpjList_removeRecByQref", "DELETE FROM TblFmncQFpjList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFpjList_removeRstByJref", "DELETE FROM TblFmncQFpjList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQFpjList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, refFmncMFab, bioRefFmncMOrg, ixVState FROM TblFmncQFpjList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQFpjList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, refFmncMFab, bioRefFmncMOrg, ixVState FROM TblFmncQFpjList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQFpjList::loadRec(
			PGresult* res
			, FmncQFpjList** rec
		) {
	char* ptr;

	FmncQFpjList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQFpjList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "bioreffmncmorg"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->bioRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQFpjList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQFpjList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQFpjList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "bioreffmncmorg"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncQFpjList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->bioRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQFpjList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQFpjList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFpjList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFpjList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQFpjList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFpjList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQFpjList::loadRecBySQL(
			const string& sqlstr
			, FmncQFpjList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQFpjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQFpjList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQFpjList::insertRec(
			FmncQFpjList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _bioRefFmncMOrg = htonl64(rec->bioRefFmncMOrg);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refFmncMFab,
		(char*) &_bioRefFmncMOrg,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFpjList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFpjList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQFpjList::insertRst(
			ListFmncQFpjList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQFpjList::updateRec(
			FmncQFpjList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _bioRefFmncMOrg = htonl64(rec->bioRefFmncMOrg);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refFmncMFab,
		(char*) &_bioRefFmncMOrg,
		(char*) &_ixVState,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQFpjList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFpjList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQFpjList::updateRst(
			ListFmncQFpjList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQFpjList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQFpjList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFpjList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQFpjList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQFpjList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQFpjList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQFpjList::loadRecByQref(
			ubigint qref
			, FmncQFpjList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQFpjList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQFpjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQFpjList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQFpjList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

