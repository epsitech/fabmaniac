/**
  * \file FmncQSmpList.cpp
  * Dbs and XML wrapper for table TblFmncQSmpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpList.h"

/******************************************************************************
 class FmncQSmpList
 ******************************************************************************/

FmncQSmpList::FmncQSmpList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint supRefFmncMSample
			, const string stubSupRefFmncMSample
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const string Material
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->supRefFmncMSample = supRefFmncMSample;
	this->stubSupRefFmncMSample = stubSupRefFmncMSample;
	this->refFmncMArticle = refFmncMArticle;
	this->stubRefFmncMArticle = stubRefFmncMArticle;
	this->Material = Material;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

void FmncQSmpList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSmpList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sup", stubSupRefFmncMSample);
		writeString(wr, "art", stubRefFmncMArticle);
		writeString(wr, "mat", Material);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubSupRefFmncMSample", stubSupRefFmncMSample);
		writeString(wr, "stubRefFmncMArticle", stubRefFmncMArticle);
		writeString(wr, "Material", Material);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQSmpList
 ******************************************************************************/

ListFmncQSmpList::ListFmncQSmpList() {
};

ListFmncQSmpList::ListFmncQSmpList(
			const ListFmncQSmpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpList(*(src.nodes[i]));
};

ListFmncQSmpList::~ListFmncQSmpList() {
	clear();
};

void ListFmncQSmpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSmpList::size() const {
	return(nodes.size());
};

void ListFmncQSmpList::append(
			FmncQSmpList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSmpList& ListFmncQSmpList::operator=(
			const ListFmncQSmpList& src
		) {
	FmncQSmpList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSmpList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSmpList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSmpList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSmpList
 ******************************************************************************/

TblFmncQSmpList::TblFmncQSmpList() {
};

TblFmncQSmpList::~TblFmncQSmpList() {
};

bool TblFmncQSmpList::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpList** rec
		) {
	return false;
};

ubigint TblFmncQSmpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpList& rst
		) {
	return 0;
};

void TblFmncQSmpList::insertRec(
			FmncQSmpList* rec
		) {
};

ubigint TblFmncQSmpList::insertNewRec(
			FmncQSmpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint supRefFmncMSample
			, const string stubSupRefFmncMSample
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const string Material
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQSmpList* _rec = NULL;

	_rec = new FmncQSmpList(0, jref, jnum, ref, sref, supRefFmncMSample, stubSupRefFmncMSample, refFmncMArticle, stubRefFmncMArticle, Material, ixVState, srefIxVState, titIxVState);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSmpList::appendNewRecToRst(
			ListFmncQSmpList& rst
			, FmncQSmpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint supRefFmncMSample
			, const string stubSupRefFmncMSample
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const string Material
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	FmncQSmpList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, supRefFmncMSample, stubSupRefFmncMSample, refFmncMArticle, stubRefFmncMArticle, Material, ixVState, srefIxVState, titIxVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSmpList::insertRst(
			ListFmncQSmpList& rst
		) {
};

void TblFmncQSmpList::updateRec(
			FmncQSmpList* rec
		) {
};

void TblFmncQSmpList::updateRst(
			ListFmncQSmpList& rst
		) {
};

void TblFmncQSmpList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSmpList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSmpList::loadRecByQref(
			ubigint qref
			, FmncQSmpList** rec
		) {
	return false;
};

ubigint TblFmncQSmpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSmpList
 ******************************************************************************/

MyTblFmncQSmpList::MyTblFmncQSmpList() : TblFmncQSmpList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSmpList::~MyTblFmncQSmpList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSmpList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSmpList (jref, jnum, ref, sref, supRefFmncMSample, refFmncMArticle, Material, ixVState) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSmpList SET jref = ?, jnum = ?, ref = ?, sref = ?, supRefFmncMSample = ?, refFmncMArticle = ?, Material = ?, ixVState = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSmpList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSmpList WHERE jref = ?", false);
};

bool MyTblFmncQSmpList::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSmpList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSmpList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSmpList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->supRefFmncMSample = atoll((char*) dbrow[5]); else _rec->supRefFmncMSample = 0;
		if (dbrow[6]) _rec->refFmncMArticle = atoll((char*) dbrow[6]); else _rec->refFmncMArticle = 0;
		if (dbrow[7]) _rec->Material.assign(dbrow[7], dblengths[7]); else _rec->Material = "";
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQSmpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSmpList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSmpList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSmpList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->supRefFmncMSample = atoll((char*) dbrow[5]); else rec->supRefFmncMSample = 0;
			if (dbrow[6]) rec->refFmncMArticle = atoll((char*) dbrow[6]); else rec->refFmncMArticle = 0;
			if (dbrow[7]) rec->Material.assign(dbrow[7], dblengths[7]); else rec->Material = "";
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQSmpList::insertRec(
			FmncQSmpList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[6] = rec->Material.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->supRefFmncMSample,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMArticle,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Material.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSmpList::insertRst(
			ListFmncQSmpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSmpList::updateRec(
			FmncQSmpList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[6] = rec->Material.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->supRefFmncMSample,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMArticle,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Material.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpList / stmtUpdateRec)\n");
};

void MyTblFmncQSmpList::updateRst(
			ListFmncQSmpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSmpList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSmpList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSmpList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSmpList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSmpList::loadRecByQref(
			ubigint qref
			, FmncQSmpList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSmpList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSmpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSmpList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSmpList
 ******************************************************************************/

PgTblFmncQSmpList::PgTblFmncQSmpList() : TblFmncQSmpList(), PgTable() {
};

PgTblFmncQSmpList::~PgTblFmncQSmpList() {
};

void PgTblFmncQSmpList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSmpList_insertRec", "INSERT INTO TblFmncQSmpList (jref, jnum, ref, sref, supRefFmncMSample, refFmncMArticle, Material, ixVState) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpList_updateRec", "UPDATE TblFmncQSmpList SET jref = $1, jnum = $2, ref = $3, sref = $4, supRefFmncMSample = $5, refFmncMArticle = $6, Material = $7, ixVState = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpList_removeRecByQref", "DELETE FROM TblFmncQSmpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpList_removeRstByJref", "DELETE FROM TblFmncQSmpList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSmpList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, supRefFmncMSample, refFmncMArticle, Material, ixVState FROM TblFmncQSmpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSmpList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, supRefFmncMSample, refFmncMArticle, Material, ixVState FROM TblFmncQSmpList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSmpList::loadRec(
			PGresult* res
			, FmncQSmpList** rec
		) {
	char* ptr;

	FmncQSmpList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSmpList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "supreffmncmsample"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "material"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->supRefFmncMSample = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Material.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQSmpList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSmpList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSmpList* rec;

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
			PQfnumber(res, "supreffmncmsample"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "material"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncQSmpList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->supRefFmncMSample = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Material.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQSmpList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSmpList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSmpList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSmpList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSmpList::loadRecBySQL(
			const string& sqlstr
			, FmncQSmpList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSmpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSmpList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSmpList::insertRec(
			FmncQSmpList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _supRefFmncMSample = htonl64(rec->supRefFmncMSample);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_supRefFmncMSample,
		(char*) &_refFmncMArticle,
		rec->Material.c_str(),
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQSmpList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSmpList::insertRst(
			ListFmncQSmpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSmpList::updateRec(
			FmncQSmpList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _supRefFmncMSample = htonl64(rec->supRefFmncMSample);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_supRefFmncMSample,
		(char*) &_refFmncMArticle,
		rec->Material.c_str(),
		(char*) &_ixVState,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQSmpList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSmpList::updateRst(
			ListFmncQSmpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSmpList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSmpList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSmpList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSmpList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSmpList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSmpList::loadRecByQref(
			ubigint qref
			, FmncQSmpList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSmpList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSmpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSmpList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSmpList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

