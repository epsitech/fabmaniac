/**
  * \file FmncQSkiList.cpp
  * Dbs and XML wrapper for table TblFmncQSkiList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSkiList.h"

/******************************************************************************
 class FmncQSkiList
 ******************************************************************************/

FmncQSkiList::FmncQSkiList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const string titOsrefFmncKStocklcn
			, const uint Expdate
			, const string ftmExpdate
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refFmncMOrg = refFmncMOrg;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
	this->refFmncMArticle = refFmncMArticle;
	this->stubRefFmncMArticle = stubRefFmncMArticle;
	this->Quantity = Quantity;
	this->osrefFmncKStocklcn = osrefFmncKStocklcn;
	this->titOsrefFmncKStocklcn = titOsrefFmncKStocklcn;
	this->Expdate = Expdate;
	this->ftmExpdate = ftmExpdate;
};

void FmncQSkiList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSkiList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "org", stubRefFmncMOrg);
		writeString(wr, "art", stubRefFmncMArticle);
		writeString(wr, "qty", Quantity);
		writeString(wr, "lcn", osrefFmncKStocklcn);
		writeString(wr, "lcn2", titOsrefFmncKStocklcn);
		writeString(wr, "exd", ftmExpdate);
	} else {
		writeString(wr, "stubRefFmncMOrg", stubRefFmncMOrg);
		writeString(wr, "stubRefFmncMArticle", stubRefFmncMArticle);
		writeString(wr, "Quantity", Quantity);
		writeString(wr, "osrefFmncKStocklcn", osrefFmncKStocklcn);
		writeString(wr, "titOsrefFmncKStocklcn", titOsrefFmncKStocklcn);
		writeString(wr, "ftmExpdate", ftmExpdate);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQSkiList
 ******************************************************************************/

ListFmncQSkiList::ListFmncQSkiList() {
};

ListFmncQSkiList::ListFmncQSkiList(
			const ListFmncQSkiList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSkiList(*(src.nodes[i]));
};

ListFmncQSkiList::~ListFmncQSkiList() {
	clear();
};

void ListFmncQSkiList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSkiList::size() const {
	return(nodes.size());
};

void ListFmncQSkiList::append(
			FmncQSkiList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSkiList& ListFmncQSkiList::operator=(
			const ListFmncQSkiList& src
		) {
	FmncQSkiList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSkiList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSkiList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSkiList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSkiList
 ******************************************************************************/

TblFmncQSkiList::TblFmncQSkiList() {
};

TblFmncQSkiList::~TblFmncQSkiList() {
};

bool TblFmncQSkiList::loadRecBySQL(
			const string& sqlstr
			, FmncQSkiList** rec
		) {
	return false;
};

ubigint TblFmncQSkiList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSkiList& rst
		) {
	return 0;
};

void TblFmncQSkiList::insertRec(
			FmncQSkiList* rec
		) {
};

ubigint TblFmncQSkiList::insertNewRec(
			FmncQSkiList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const string titOsrefFmncKStocklcn
			, const uint Expdate
			, const string ftmExpdate
		) {
	ubigint retval = 0;
	FmncQSkiList* _rec = NULL;

	_rec = new FmncQSkiList(0, jref, jnum, ref, refFmncMOrg, stubRefFmncMOrg, refFmncMArticle, stubRefFmncMArticle, Quantity, osrefFmncKStocklcn, titOsrefFmncKStocklcn, Expdate, ftmExpdate);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSkiList::appendNewRecToRst(
			ListFmncQSkiList& rst
			, FmncQSkiList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const string titOsrefFmncKStocklcn
			, const uint Expdate
			, const string ftmExpdate
		) {
	ubigint retval = 0;
	FmncQSkiList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refFmncMOrg, stubRefFmncMOrg, refFmncMArticle, stubRefFmncMArticle, Quantity, osrefFmncKStocklcn, titOsrefFmncKStocklcn, Expdate, ftmExpdate);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSkiList::insertRst(
			ListFmncQSkiList& rst
		) {
};

void TblFmncQSkiList::updateRec(
			FmncQSkiList* rec
		) {
};

void TblFmncQSkiList::updateRst(
			ListFmncQSkiList& rst
		) {
};

void TblFmncQSkiList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSkiList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSkiList::loadRecByQref(
			ubigint qref
			, FmncQSkiList** rec
		) {
	return false;
};

ubigint TblFmncQSkiList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSkiList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSkiList
 ******************************************************************************/

MyTblFmncQSkiList::MyTblFmncQSkiList() : TblFmncQSkiList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSkiList::~MyTblFmncQSkiList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSkiList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSkiList (jref, jnum, ref, refFmncMOrg, refFmncMArticle, Quantity, osrefFmncKStocklcn, Expdate) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSkiList SET jref = ?, jnum = ?, ref = ?, refFmncMOrg = ?, refFmncMArticle = ?, Quantity = ?, osrefFmncKStocklcn = ?, Expdate = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSkiList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSkiList WHERE jref = ?", false);
};

bool MyTblFmncQSkiList::loadRecBySQL(
			const string& sqlstr
			, FmncQSkiList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSkiList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSkiList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSkiList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refFmncMOrg = atoll((char*) dbrow[4]); else _rec->refFmncMOrg = 0;
		if (dbrow[5]) _rec->refFmncMArticle = atoll((char*) dbrow[5]); else _rec->refFmncMArticle = 0;
		if (dbrow[6]) _rec->Quantity.assign(dbrow[6], dblengths[6]); else _rec->Quantity = "";
		if (dbrow[7]) _rec->osrefFmncKStocklcn.assign(dbrow[7], dblengths[7]); else _rec->osrefFmncKStocklcn = "";
		if (dbrow[8]) _rec->Expdate = atol((char*) dbrow[8]); else _rec->Expdate = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQSkiList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSkiList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSkiList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSkiList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSkiList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refFmncMOrg = atoll((char*) dbrow[4]); else rec->refFmncMOrg = 0;
			if (dbrow[5]) rec->refFmncMArticle = atoll((char*) dbrow[5]); else rec->refFmncMArticle = 0;
			if (dbrow[6]) rec->Quantity.assign(dbrow[6], dblengths[6]); else rec->Quantity = "";
			if (dbrow[7]) rec->osrefFmncKStocklcn.assign(dbrow[7], dblengths[7]); else rec->osrefFmncKStocklcn = "";
			if (dbrow[8]) rec->Expdate = atol((char*) dbrow[8]); else rec->Expdate = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQSkiList::insertRec(
			FmncQSkiList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->Quantity.length();
	l[6] = rec->osrefFmncKStocklcn.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMOrg,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMArticle,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Quantity.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefFmncKStocklcn.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->Expdate,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSkiList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSkiList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSkiList::insertRst(
			ListFmncQSkiList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSkiList::updateRec(
			FmncQSkiList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->Quantity.length();
	l[6] = rec->osrefFmncKStocklcn.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMOrg,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMArticle,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Quantity.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->osrefFmncKStocklcn.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->Expdate,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSkiList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSkiList / stmtUpdateRec)\n");
};

void MyTblFmncQSkiList::updateRst(
			ListFmncQSkiList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSkiList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSkiList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSkiList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSkiList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSkiList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSkiList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSkiList::loadRecByQref(
			ubigint qref
			, FmncQSkiList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSkiList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSkiList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSkiList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSkiList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSkiList
 ******************************************************************************/

PgTblFmncQSkiList::PgTblFmncQSkiList() : TblFmncQSkiList(), PgTable() {
};

PgTblFmncQSkiList::~PgTblFmncQSkiList() {
};

void PgTblFmncQSkiList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSkiList_insertRec", "INSERT INTO TblFmncQSkiList (jref, jnum, ref, refFmncMOrg, refFmncMArticle, Quantity, osrefFmncKStocklcn, Expdate) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSkiList_updateRec", "UPDATE TblFmncQSkiList SET jref = $1, jnum = $2, ref = $3, refFmncMOrg = $4, refFmncMArticle = $5, Quantity = $6, osrefFmncKStocklcn = $7, Expdate = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSkiList_removeRecByQref", "DELETE FROM TblFmncQSkiList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSkiList_removeRstByJref", "DELETE FROM TblFmncQSkiList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSkiList_loadRecByQref", "SELECT qref, jref, jnum, ref, refFmncMOrg, refFmncMArticle, Quantity, osrefFmncKStocklcn, Expdate FROM TblFmncQSkiList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSkiList_loadRstByJref", "SELECT qref, jref, jnum, ref, refFmncMOrg, refFmncMArticle, Quantity, osrefFmncKStocklcn, Expdate FROM TblFmncQSkiList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSkiList::loadRec(
			PGresult* res
			, FmncQSkiList** rec
		) {
	char* ptr;

	FmncQSkiList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSkiList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "osreffmnckstocklcn"),
			PQfnumber(res, "expdate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Quantity.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->osrefFmncKStocklcn.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Expdate = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQSkiList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSkiList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSkiList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "osreffmnckstocklcn"),
			PQfnumber(res, "expdate")
		};

		while (numread < numrow) {
			rec = new FmncQSkiList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Quantity.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->osrefFmncKStocklcn.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Expdate = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQSkiList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSkiList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSkiList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSkiList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSkiList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSkiList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSkiList::loadRecBySQL(
			const string& sqlstr
			, FmncQSkiList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSkiList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSkiList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSkiList::insertRec(
			FmncQSkiList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	uint _Expdate = htonl(rec->Expdate);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMArticle,
		rec->Quantity.c_str(),
		rec->osrefFmncKStocklcn.c_str(),
		(char*) &_Expdate
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQSkiList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSkiList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSkiList::insertRst(
			ListFmncQSkiList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSkiList::updateRec(
			FmncQSkiList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	uint _Expdate = htonl(rec->Expdate);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMArticle,
		rec->Quantity.c_str(),
		rec->osrefFmncKStocklcn.c_str(),
		(char*) &_Expdate,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQSkiList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSkiList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSkiList::updateRst(
			ListFmncQSkiList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSkiList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSkiList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSkiList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSkiList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSkiList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSkiList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSkiList::loadRecByQref(
			ubigint qref
			, FmncQSkiList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSkiList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSkiList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSkiList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSkiList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

