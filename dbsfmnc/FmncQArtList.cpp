/**
  * \file FmncQArtList.cpp
  * Dbs and XML wrapper for table TblFmncQArtList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQArtList.h"

/******************************************************************************
 class FmncQArtList
 ******************************************************************************/

FmncQArtList::FmncQArtList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMTool
			, const string stubRefFmncMTool
			, const string srefKType
			, const string titSrefKType
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->refFmncMOrg = refFmncMOrg;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
	this->refFmncMTool = refFmncMTool;
	this->stubRefFmncMTool = stubRefFmncMTool;
	this->srefKType = srefKType;
	this->titSrefKType = titSrefKType;
};

void FmncQArtList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQArtList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "org", stubRefFmncMOrg);
		writeString(wr, "tol", stubRefFmncMTool);
		writeString(wr, "typ", srefKType);
		writeString(wr, "typ2", titSrefKType);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefFmncMOrg", stubRefFmncMOrg);
		writeString(wr, "stubRefFmncMTool", stubRefFmncMTool);
		writeString(wr, "srefKType", srefKType);
		writeString(wr, "titSrefKType", titSrefKType);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQArtList
 ******************************************************************************/

ListFmncQArtList::ListFmncQArtList() {
};

ListFmncQArtList::ListFmncQArtList(
			const ListFmncQArtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArtList(*(src.nodes[i]));
};

ListFmncQArtList::~ListFmncQArtList() {
	clear();
};

void ListFmncQArtList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQArtList::size() const {
	return(nodes.size());
};

void ListFmncQArtList::append(
			FmncQArtList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQArtList& ListFmncQArtList::operator=(
			const ListFmncQArtList& src
		) {
	FmncQArtList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQArtList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQArtList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQArtList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQArtList
 ******************************************************************************/

TblFmncQArtList::TblFmncQArtList() {
};

TblFmncQArtList::~TblFmncQArtList() {
};

bool TblFmncQArtList::loadRecBySQL(
			const string& sqlstr
			, FmncQArtList** rec
		) {
	return false;
};

ubigint TblFmncQArtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArtList& rst
		) {
	return 0;
};

void TblFmncQArtList::insertRec(
			FmncQArtList* rec
		) {
};

ubigint TblFmncQArtList::insertNewRec(
			FmncQArtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMTool
			, const string stubRefFmncMTool
			, const string srefKType
			, const string titSrefKType
		) {
	ubigint retval = 0;
	FmncQArtList* _rec = NULL;

	_rec = new FmncQArtList(0, jref, jnum, ref, sref, Title, refFmncMOrg, stubRefFmncMOrg, refFmncMTool, stubRefFmncMTool, srefKType, titSrefKType);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQArtList::appendNewRecToRst(
			ListFmncQArtList& rst
			, FmncQArtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMTool
			, const string stubRefFmncMTool
			, const string srefKType
			, const string titSrefKType
		) {
	ubigint retval = 0;
	FmncQArtList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, refFmncMOrg, stubRefFmncMOrg, refFmncMTool, stubRefFmncMTool, srefKType, titSrefKType);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQArtList::insertRst(
			ListFmncQArtList& rst
		) {
};

void TblFmncQArtList::updateRec(
			FmncQArtList* rec
		) {
};

void TblFmncQArtList::updateRst(
			ListFmncQArtList& rst
		) {
};

void TblFmncQArtList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQArtList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQArtList::loadRecByQref(
			ubigint qref
			, FmncQArtList** rec
		) {
	return false;
};

ubigint TblFmncQArtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArtList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQArtList
 ******************************************************************************/

MyTblFmncQArtList::MyTblFmncQArtList() : TblFmncQArtList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQArtList::~MyTblFmncQArtList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQArtList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQArtList (jref, jnum, ref, sref, Title, refFmncMOrg, refFmncMTool, srefKType) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQArtList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, refFmncMOrg = ?, refFmncMTool = ?, srefKType = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQArtList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQArtList WHERE jref = ?", false);
};

bool MyTblFmncQArtList::loadRecBySQL(
			const string& sqlstr
			, FmncQArtList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQArtList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQArtList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQArtList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->refFmncMOrg = atoll((char*) dbrow[6]); else _rec->refFmncMOrg = 0;
		if (dbrow[7]) _rec->refFmncMTool = atoll((char*) dbrow[7]); else _rec->refFmncMTool = 0;
		if (dbrow[8]) _rec->srefKType.assign(dbrow[8], dblengths[8]); else _rec->srefKType = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQArtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArtList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQArtList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQArtList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQArtList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->refFmncMOrg = atoll((char*) dbrow[6]); else rec->refFmncMOrg = 0;
			if (dbrow[7]) rec->refFmncMTool = atoll((char*) dbrow[7]); else rec->refFmncMTool = 0;
			if (dbrow[8]) rec->srefKType.assign(dbrow[8], dblengths[8]); else rec->srefKType = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQArtList::insertRec(
			FmncQArtList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[7] = rec->srefKType.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMOrg,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refFmncMTool,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKType.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQArtList::insertRst(
			ListFmncQArtList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQArtList::updateRec(
			FmncQArtList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[7] = rec->srefKType.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMOrg,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refFmncMTool,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->srefKType.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtList / stmtUpdateRec)\n");
};

void MyTblFmncQArtList::updateRst(
			ListFmncQArtList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQArtList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQArtList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQArtList::loadRecByQref(
			ubigint qref
			, FmncQArtList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQArtList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQArtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArtList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQArtList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQArtList
 ******************************************************************************/

PgTblFmncQArtList::PgTblFmncQArtList() : TblFmncQArtList(), PgTable() {
};

PgTblFmncQArtList::~PgTblFmncQArtList() {
};

void PgTblFmncQArtList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQArtList_insertRec", "INSERT INTO TblFmncQArtList (jref, jnum, ref, sref, Title, refFmncMOrg, refFmncMTool, srefKType) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtList_updateRec", "UPDATE TblFmncQArtList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, refFmncMOrg = $6, refFmncMTool = $7, srefKType = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtList_removeRecByQref", "DELETE FROM TblFmncQArtList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtList_removeRstByJref", "DELETE FROM TblFmncQArtList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQArtList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, refFmncMOrg, refFmncMTool, srefKType FROM TblFmncQArtList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, refFmncMOrg, refFmncMTool, srefKType FROM TblFmncQArtList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQArtList::loadRec(
			PGresult* res
			, FmncQArtList** rec
		) {
	char* ptr;

	FmncQArtList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQArtList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "srefktype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefKType.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQArtList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQArtList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQArtList* rec;

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
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "srefktype")
		};

		while (numread < numrow) {
			rec = new FmncQArtList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefKType.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQArtList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQArtList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQArtList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQArtList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQArtList::loadRecBySQL(
			const string& sqlstr
			, FmncQArtList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQArtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArtList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQArtList::insertRec(
			FmncQArtList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMTool,
		rec->srefKType.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQArtList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQArtList::insertRst(
			ListFmncQArtList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQArtList::updateRec(
			FmncQArtList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMTool,
		rec->srefKType.c_str(),
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
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQArtList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQArtList::updateRst(
			ListFmncQArtList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQArtList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQArtList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQArtList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQArtList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQArtList::loadRecByQref(
			ubigint qref
			, FmncQArtList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQArtList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQArtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArtList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQArtList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

