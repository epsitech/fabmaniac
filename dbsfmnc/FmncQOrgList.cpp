/**
  * \file FmncQOrgList.cpp
  * Dbs and XML wrapper for table TblFmncQOrgList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgList.h"

/******************************************************************************
 class FmncQOrgList
 ******************************************************************************/

FmncQOrgList::FmncQOrgList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixWDerivate
			, const string srefsIxWDerivate
			, const string titsIxWDerivate
			, const ubigint refFmncMAddress
			, const string stubRefFmncMAddress
			, const ubigint supRefFmncMOrg
			, const string stubSupRefFmncMOrg
			, const string Tel
			, const string Eml
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->ixWDerivate = ixWDerivate;
	this->srefsIxWDerivate = srefsIxWDerivate;
	this->titsIxWDerivate = titsIxWDerivate;
	this->refFmncMAddress = refFmncMAddress;
	this->stubRefFmncMAddress = stubRefFmncMAddress;
	this->supRefFmncMOrg = supRefFmncMOrg;
	this->stubSupRefFmncMOrg = stubSupRefFmncMOrg;
	this->Tel = Tel;
	this->Eml = Eml;
};

void FmncQOrgList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQOrgList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "drv", srefsIxWDerivate);
		writeString(wr, "drv2", titsIxWDerivate);
		writeString(wr, "adr", stubRefFmncMAddress);
		writeString(wr, "sup", stubSupRefFmncMOrg);
		writeString(wr, "tel", Tel);
		writeString(wr, "eml", Eml);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "srefsIxWDerivate", srefsIxWDerivate);
		writeString(wr, "titsIxWDerivate", titsIxWDerivate);
		writeString(wr, "stubRefFmncMAddress", stubRefFmncMAddress);
		writeString(wr, "stubSupRefFmncMOrg", stubSupRefFmncMOrg);
		writeString(wr, "Tel", Tel);
		writeString(wr, "Eml", Eml);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQOrgList
 ******************************************************************************/

ListFmncQOrgList::ListFmncQOrgList() {
};

ListFmncQOrgList::ListFmncQOrgList(
			const ListFmncQOrgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgList(*(src.nodes[i]));
};

ListFmncQOrgList::~ListFmncQOrgList() {
	clear();
};

void ListFmncQOrgList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQOrgList::size() const {
	return(nodes.size());
};

void ListFmncQOrgList::append(
			FmncQOrgList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQOrgList& ListFmncQOrgList::operator=(
			const ListFmncQOrgList& src
		) {
	FmncQOrgList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQOrgList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQOrgList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQOrgList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQOrgList
 ******************************************************************************/

TblFmncQOrgList::TblFmncQOrgList() {
};

TblFmncQOrgList::~TblFmncQOrgList() {
};

bool TblFmncQOrgList::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgList** rec
		) {
	return false;
};

ubigint TblFmncQOrgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgList& rst
		) {
	return 0;
};

void TblFmncQOrgList::insertRec(
			FmncQOrgList* rec
		) {
};

ubigint TblFmncQOrgList::insertNewRec(
			FmncQOrgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixWDerivate
			, const string srefsIxWDerivate
			, const string titsIxWDerivate
			, const ubigint refFmncMAddress
			, const string stubRefFmncMAddress
			, const ubigint supRefFmncMOrg
			, const string stubSupRefFmncMOrg
			, const string Tel
			, const string Eml
		) {
	ubigint retval = 0;
	FmncQOrgList* _rec = NULL;

	_rec = new FmncQOrgList(0, jref, jnum, ref, sref, Title, ixWDerivate, srefsIxWDerivate, titsIxWDerivate, refFmncMAddress, stubRefFmncMAddress, supRefFmncMOrg, stubSupRefFmncMOrg, Tel, Eml);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQOrgList::appendNewRecToRst(
			ListFmncQOrgList& rst
			, FmncQOrgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixWDerivate
			, const string srefsIxWDerivate
			, const string titsIxWDerivate
			, const ubigint refFmncMAddress
			, const string stubRefFmncMAddress
			, const ubigint supRefFmncMOrg
			, const string stubSupRefFmncMOrg
			, const string Tel
			, const string Eml
		) {
	ubigint retval = 0;
	FmncQOrgList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, ixWDerivate, srefsIxWDerivate, titsIxWDerivate, refFmncMAddress, stubRefFmncMAddress, supRefFmncMOrg, stubSupRefFmncMOrg, Tel, Eml);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQOrgList::insertRst(
			ListFmncQOrgList& rst
		) {
};

void TblFmncQOrgList::updateRec(
			FmncQOrgList* rec
		) {
};

void TblFmncQOrgList::updateRst(
			ListFmncQOrgList& rst
		) {
};

void TblFmncQOrgList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQOrgList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQOrgList::loadRecByQref(
			ubigint qref
			, FmncQOrgList** rec
		) {
	return false;
};

ubigint TblFmncQOrgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQOrgList
 ******************************************************************************/

MyTblFmncQOrgList::MyTblFmncQOrgList() : TblFmncQOrgList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQOrgList::~MyTblFmncQOrgList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQOrgList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQOrgList (jref, jnum, ref, sref, Title, ixWDerivate, refFmncMAddress, supRefFmncMOrg, Tel, Eml) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQOrgList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, ixWDerivate = ?, refFmncMAddress = ?, supRefFmncMOrg = ?, Tel = ?, Eml = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQOrgList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQOrgList WHERE jref = ?", false);
};

bool MyTblFmncQOrgList::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQOrgList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQOrgList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->ixWDerivate = atol((char*) dbrow[6]); else _rec->ixWDerivate = 0;
		if (dbrow[7]) _rec->refFmncMAddress = atoll((char*) dbrow[7]); else _rec->refFmncMAddress = 0;
		if (dbrow[8]) _rec->supRefFmncMOrg = atoll((char*) dbrow[8]); else _rec->supRefFmncMOrg = 0;
		if (dbrow[9]) _rec->Tel.assign(dbrow[9], dblengths[9]); else _rec->Tel = "";
		if (dbrow[10]) _rec->Eml.assign(dbrow[10], dblengths[10]); else _rec->Eml = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQOrgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQOrgList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQOrgList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQOrgList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->ixWDerivate = atol((char*) dbrow[6]); else rec->ixWDerivate = 0;
			if (dbrow[7]) rec->refFmncMAddress = atoll((char*) dbrow[7]); else rec->refFmncMAddress = 0;
			if (dbrow[8]) rec->supRefFmncMOrg = atoll((char*) dbrow[8]); else rec->supRefFmncMOrg = 0;
			if (dbrow[9]) rec->Tel.assign(dbrow[9], dblengths[9]); else rec->Tel = "";
			if (dbrow[10]) rec->Eml.assign(dbrow[10], dblengths[10]); else rec->Eml = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQOrgList::insertRec(
			FmncQOrgList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[8] = rec->Tel.length();
	l[9] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWDerivate,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refFmncMAddress,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->supRefFmncMOrg,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Tel.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Eml.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQOrgList::insertRst(
			ListFmncQOrgList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQOrgList::updateRec(
			FmncQOrgList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[8] = rec->Tel.length();
	l[9] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixWDerivate,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refFmncMAddress,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->supRefFmncMOrg,&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Tel.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Eml.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgList / stmtUpdateRec)\n");
};

void MyTblFmncQOrgList::updateRst(
			ListFmncQOrgList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQOrgList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQOrgList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQOrgList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQOrgList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQOrgList::loadRecByQref(
			ubigint qref
			, FmncQOrgList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQOrgList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQOrgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQOrgList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQOrgList
 ******************************************************************************/

PgTblFmncQOrgList::PgTblFmncQOrgList() : TblFmncQOrgList(), PgTable() {
};

PgTblFmncQOrgList::~PgTblFmncQOrgList() {
};

void PgTblFmncQOrgList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQOrgList_insertRec", "INSERT INTO TblFmncQOrgList (jref, jnum, ref, sref, Title, ixWDerivate, refFmncMAddress, supRefFmncMOrg, Tel, Eml) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgList_updateRec", "UPDATE TblFmncQOrgList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, ixWDerivate = $6, refFmncMAddress = $7, supRefFmncMOrg = $8, Tel = $9, Eml = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgList_removeRecByQref", "DELETE FROM TblFmncQOrgList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgList_removeRstByJref", "DELETE FROM TblFmncQOrgList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQOrgList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, ixWDerivate, refFmncMAddress, supRefFmncMOrg, Tel, Eml FROM TblFmncQOrgList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQOrgList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, ixWDerivate, refFmncMAddress, supRefFmncMOrg, Tel, Eml FROM TblFmncQOrgList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQOrgList::loadRec(
			PGresult* res
			, FmncQOrgList** rec
		) {
	char* ptr;

	FmncQOrgList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQOrgList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "supreffmncmorg"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "eml")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWDerivate = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refFmncMAddress = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->supRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Tel.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Eml.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQOrgList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQOrgList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQOrgList* rec;

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
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "supreffmncmorg"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "eml")
		};

		while (numread < numrow) {
			rec = new FmncQOrgList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWDerivate = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refFmncMAddress = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->supRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Tel.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Eml.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQOrgList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQOrgList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQOrgList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQOrgList::loadRecBySQL(
			const string& sqlstr
			, FmncQOrgList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQOrgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQOrgList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQOrgList::insertRec(
			FmncQOrgList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	ubigint _supRefFmncMOrg = htonl64(rec->supRefFmncMOrg);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixWDerivate,
		(char*) &_refFmncMAddress,
		(char*) &_supRefFmncMOrg,
		rec->Tel.c_str(),
		rec->Eml.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQOrgList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQOrgList::insertRst(
			ListFmncQOrgList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQOrgList::updateRec(
			FmncQOrgList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	ubigint _supRefFmncMOrg = htonl64(rec->supRefFmncMOrg);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixWDerivate,
		(char*) &_refFmncMAddress,
		(char*) &_supRefFmncMOrg,
		rec->Tel.c_str(),
		rec->Eml.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQOrgList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQOrgList::updateRst(
			ListFmncQOrgList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQOrgList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQOrgList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQOrgList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQOrgList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQOrgList::loadRecByQref(
			ubigint qref
			, FmncQOrgList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQOrgList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQOrgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQOrgList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQOrgList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

