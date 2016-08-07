/**
  * \file FmncQAdrList.cpp
  * Dbs and XML wrapper for table TblFmncQAdrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQAdrList.h"

/******************************************************************************
 class FmncQAdrList
 ******************************************************************************/

FmncQAdrList::FmncQAdrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Address1
			, const string City
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const string srefKAdrtype
			, const string titSrefKAdrtype
			, const string Zipcode
			, const string srefKCountry
			, const string titSrefKCountry
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Address1 = Address1;
	this->City = City;
	this->hkIxVTbl = hkIxVTbl;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->hkUref = hkUref;
	this->stubHkUref = stubHkUref;
	this->srefKAdrtype = srefKAdrtype;
	this->titSrefKAdrtype = titSrefKAdrtype;
	this->Zipcode = Zipcode;
	this->srefKCountry = srefKCountry;
	this->titSrefKCountry = titSrefKCountry;
};

void FmncQAdrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQAdrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ad1", Address1);
		writeString(wr, "cty", City);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
		writeString(wr, "aty", srefKAdrtype);
		writeString(wr, "aty2", titSrefKAdrtype);
		writeString(wr, "zip", Zipcode);
		writeString(wr, "cry", srefKCountry);
		writeString(wr, "cry2", titSrefKCountry);
	} else {
		writeString(wr, "Address1", Address1);
		writeString(wr, "City", City);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
		writeString(wr, "srefKAdrtype", srefKAdrtype);
		writeString(wr, "titSrefKAdrtype", titSrefKAdrtype);
		writeString(wr, "Zipcode", Zipcode);
		writeString(wr, "srefKCountry", srefKCountry);
		writeString(wr, "titSrefKCountry", titSrefKCountry);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQAdrList
 ******************************************************************************/

ListFmncQAdrList::ListFmncQAdrList() {
};

ListFmncQAdrList::ListFmncQAdrList(
			const ListFmncQAdrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQAdrList(*(src.nodes[i]));
};

ListFmncQAdrList::~ListFmncQAdrList() {
	clear();
};

void ListFmncQAdrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQAdrList::size() const {
	return(nodes.size());
};

void ListFmncQAdrList::append(
			FmncQAdrList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQAdrList& ListFmncQAdrList::operator=(
			const ListFmncQAdrList& src
		) {
	FmncQAdrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQAdrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQAdrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQAdrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQAdrList
 ******************************************************************************/

TblFmncQAdrList::TblFmncQAdrList() {
};

TblFmncQAdrList::~TblFmncQAdrList() {
};

bool TblFmncQAdrList::loadRecBySQL(
			const string& sqlstr
			, FmncQAdrList** rec
		) {
	return false;
};

ubigint TblFmncQAdrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQAdrList& rst
		) {
	return 0;
};

void TblFmncQAdrList::insertRec(
			FmncQAdrList* rec
		) {
};

ubigint TblFmncQAdrList::insertNewRec(
			FmncQAdrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Address1
			, const string City
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const string srefKAdrtype
			, const string titSrefKAdrtype
			, const string Zipcode
			, const string srefKCountry
			, const string titSrefKCountry
		) {
	ubigint retval = 0;
	FmncQAdrList* _rec = NULL;

	_rec = new FmncQAdrList(0, jref, jnum, ref, Address1, City, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, srefKAdrtype, titSrefKAdrtype, Zipcode, srefKCountry, titSrefKCountry);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQAdrList::appendNewRecToRst(
			ListFmncQAdrList& rst
			, FmncQAdrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Address1
			, const string City
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const string srefKAdrtype
			, const string titSrefKAdrtype
			, const string Zipcode
			, const string srefKCountry
			, const string titSrefKCountry
		) {
	ubigint retval = 0;
	FmncQAdrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Address1, City, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, srefKAdrtype, titSrefKAdrtype, Zipcode, srefKCountry, titSrefKCountry);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQAdrList::insertRst(
			ListFmncQAdrList& rst
		) {
};

void TblFmncQAdrList::updateRec(
			FmncQAdrList* rec
		) {
};

void TblFmncQAdrList::updateRst(
			ListFmncQAdrList& rst
		) {
};

void TblFmncQAdrList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQAdrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQAdrList::loadRecByQref(
			ubigint qref
			, FmncQAdrList** rec
		) {
	return false;
};

ubigint TblFmncQAdrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQAdrList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQAdrList
 ******************************************************************************/

MyTblFmncQAdrList::MyTblFmncQAdrList() : TblFmncQAdrList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQAdrList::~MyTblFmncQAdrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQAdrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQAdrList (jref, jnum, ref, Address1, City, hkIxVTbl, hkUref, srefKAdrtype, Zipcode, srefKCountry) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQAdrList SET jref = ?, jnum = ?, ref = ?, Address1 = ?, City = ?, hkIxVTbl = ?, hkUref = ?, srefKAdrtype = ?, Zipcode = ?, srefKCountry = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQAdrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQAdrList WHERE jref = ?", false);
};

bool MyTblFmncQAdrList::loadRecBySQL(
			const string& sqlstr
			, FmncQAdrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQAdrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQAdrList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQAdrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Address1.assign(dbrow[4], dblengths[4]); else _rec->Address1 = "";
		if (dbrow[5]) _rec->City.assign(dbrow[5], dblengths[5]); else _rec->City = "";
		if (dbrow[6]) _rec->hkIxVTbl = atol((char*) dbrow[6]); else _rec->hkIxVTbl = 0;
		if (dbrow[7]) _rec->hkUref = atoll((char*) dbrow[7]); else _rec->hkUref = 0;
		if (dbrow[8]) _rec->srefKAdrtype.assign(dbrow[8], dblengths[8]); else _rec->srefKAdrtype = "";
		if (dbrow[9]) _rec->Zipcode.assign(dbrow[9], dblengths[9]); else _rec->Zipcode = "";
		if (dbrow[10]) _rec->srefKCountry.assign(dbrow[10], dblengths[10]); else _rec->srefKCountry = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQAdrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQAdrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQAdrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQAdrList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQAdrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Address1.assign(dbrow[4], dblengths[4]); else rec->Address1 = "";
			if (dbrow[5]) rec->City.assign(dbrow[5], dblengths[5]); else rec->City = "";
			if (dbrow[6]) rec->hkIxVTbl = atol((char*) dbrow[6]); else rec->hkIxVTbl = 0;
			if (dbrow[7]) rec->hkUref = atoll((char*) dbrow[7]); else rec->hkUref = 0;
			if (dbrow[8]) rec->srefKAdrtype.assign(dbrow[8], dblengths[8]); else rec->srefKAdrtype = "";
			if (dbrow[9]) rec->Zipcode.assign(dbrow[9], dblengths[9]); else rec->Zipcode = "";
			if (dbrow[10]) rec->srefKCountry.assign(dbrow[10], dblengths[10]); else rec->srefKCountry = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQAdrList::insertRec(
			FmncQAdrList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Address1.length();
	l[4] = rec->City.length();
	l[7] = rec->srefKAdrtype.length();
	l[8] = rec->Zipcode.length();
	l[9] = rec->srefKCountry.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Address1.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->City.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->hkIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->hkUref,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKAdrtype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Zipcode.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKCountry.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQAdrList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQAdrList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQAdrList::insertRst(
			ListFmncQAdrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQAdrList::updateRec(
			FmncQAdrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->Address1.length();
	l[4] = rec->City.length();
	l[7] = rec->srefKAdrtype.length();
	l[8] = rec->Zipcode.length();
	l[9] = rec->srefKCountry.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Address1.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->City.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->hkIxVTbl,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->hkUref,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->srefKAdrtype.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Zipcode.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->srefKCountry.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQAdrList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQAdrList / stmtUpdateRec)\n");
};

void MyTblFmncQAdrList::updateRst(
			ListFmncQAdrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQAdrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQAdrList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQAdrList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQAdrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQAdrList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQAdrList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQAdrList::loadRecByQref(
			ubigint qref
			, FmncQAdrList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQAdrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQAdrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQAdrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQAdrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQAdrList
 ******************************************************************************/

PgTblFmncQAdrList::PgTblFmncQAdrList() : TblFmncQAdrList(), PgTable() {
};

PgTblFmncQAdrList::~PgTblFmncQAdrList() {
};

void PgTblFmncQAdrList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQAdrList_insertRec", "INSERT INTO TblFmncQAdrList (jref, jnum, ref, Address1, City, hkIxVTbl, hkUref, srefKAdrtype, Zipcode, srefKCountry) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQAdrList_updateRec", "UPDATE TblFmncQAdrList SET jref = $1, jnum = $2, ref = $3, Address1 = $4, City = $5, hkIxVTbl = $6, hkUref = $7, srefKAdrtype = $8, Zipcode = $9, srefKCountry = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQAdrList_removeRecByQref", "DELETE FROM TblFmncQAdrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQAdrList_removeRstByJref", "DELETE FROM TblFmncQAdrList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQAdrList_loadRecByQref", "SELECT qref, jref, jnum, ref, Address1, City, hkIxVTbl, hkUref, srefKAdrtype, Zipcode, srefKCountry FROM TblFmncQAdrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQAdrList_loadRstByJref", "SELECT qref, jref, jnum, ref, Address1, City, hkIxVTbl, hkUref, srefKAdrtype, Zipcode, srefKCountry FROM TblFmncQAdrList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQAdrList::loadRec(
			PGresult* res
			, FmncQAdrList** rec
		) {
	char* ptr;

	FmncQAdrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQAdrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "address1"),
			PQfnumber(res, "city"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "srefkadrtype"),
			PQfnumber(res, "zipcode"),
			PQfnumber(res, "srefkcountry")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Address1.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->City.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefKAdrtype.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Zipcode.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefKCountry.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQAdrList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQAdrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQAdrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "address1"),
			PQfnumber(res, "city"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "srefkadrtype"),
			PQfnumber(res, "zipcode"),
			PQfnumber(res, "srefkcountry")
		};

		while (numread < numrow) {
			rec = new FmncQAdrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Address1.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->City.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefKAdrtype.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Zipcode.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefKCountry.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQAdrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQAdrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQAdrList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQAdrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQAdrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQAdrList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQAdrList::loadRecBySQL(
			const string& sqlstr
			, FmncQAdrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQAdrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQAdrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQAdrList::insertRec(
			FmncQAdrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Address1.c_str(),
		rec->City.c_str(),
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->srefKAdrtype.c_str(),
		rec->Zipcode.c_str(),
		rec->srefKCountry.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQAdrList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQAdrList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQAdrList::insertRst(
			ListFmncQAdrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQAdrList::updateRec(
			FmncQAdrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Address1.c_str(),
		rec->City.c_str(),
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->srefKAdrtype.c_str(),
		rec->Zipcode.c_str(),
		rec->srefKCountry.c_str(),
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
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQAdrList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQAdrList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQAdrList::updateRst(
			ListFmncQAdrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQAdrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQAdrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQAdrList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQAdrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQAdrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQAdrList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQAdrList::loadRecByQref(
			ubigint qref
			, FmncQAdrList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQAdrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQAdrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQAdrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQAdrList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

