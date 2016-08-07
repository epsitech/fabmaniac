/**
  * \file FmncQTolList.cpp
  * Dbs and XML wrapper for table TblFmncQTolList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolList.h"

/******************************************************************************
 class FmncQTolList
 ******************************************************************************/

FmncQTolList::FmncQTolList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint fabRefFmncMFab
			, const string stubFabRefFmncMFab
			, const ubigint mnfRefFmncMOrg
			, const string stubMnfRefFmncMOrg
			, const double Unitprice
			, const string Training
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->fabRefFmncMFab = fabRefFmncMFab;
	this->stubFabRefFmncMFab = stubFabRefFmncMFab;
	this->mnfRefFmncMOrg = mnfRefFmncMOrg;
	this->stubMnfRefFmncMOrg = stubMnfRefFmncMOrg;
	this->Unitprice = Unitprice;
	this->Training = Training;
};

void FmncQTolList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "fab", stubFabRefFmncMFab);
		writeString(wr, "mnf", stubMnfRefFmncMOrg);
		writeDouble(wr, "upr", Unitprice);
		writeString(wr, "trn", Training);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "stubFabRefFmncMFab", stubFabRefFmncMFab);
		writeString(wr, "stubMnfRefFmncMOrg", stubMnfRefFmncMOrg);
		writeDouble(wr, "Unitprice", Unitprice);
		writeString(wr, "Training", Training);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolList
 ******************************************************************************/

ListFmncQTolList::ListFmncQTolList() {
};

ListFmncQTolList::ListFmncQTolList(
			const ListFmncQTolList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolList(*(src.nodes[i]));
};

ListFmncQTolList::~ListFmncQTolList() {
	clear();
};

void ListFmncQTolList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolList::size() const {
	return(nodes.size());
};

void ListFmncQTolList::append(
			FmncQTolList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolList& ListFmncQTolList::operator=(
			const ListFmncQTolList& src
		) {
	FmncQTolList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolList
 ******************************************************************************/

TblFmncQTolList::TblFmncQTolList() {
};

TblFmncQTolList::~TblFmncQTolList() {
};

bool TblFmncQTolList::loadRecBySQL(
			const string& sqlstr
			, FmncQTolList** rec
		) {
	return false;
};

ubigint TblFmncQTolList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolList& rst
		) {
	return 0;
};

void TblFmncQTolList::insertRec(
			FmncQTolList* rec
		) {
};

ubigint TblFmncQTolList::insertNewRec(
			FmncQTolList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint fabRefFmncMFab
			, const string stubFabRefFmncMFab
			, const ubigint mnfRefFmncMOrg
			, const string stubMnfRefFmncMOrg
			, const double Unitprice
			, const string Training
		) {
	ubigint retval = 0;
	FmncQTolList* _rec = NULL;

	_rec = new FmncQTolList(0, jref, jnum, ref, Title, fabRefFmncMFab, stubFabRefFmncMFab, mnfRefFmncMOrg, stubMnfRefFmncMOrg, Unitprice, Training);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolList::appendNewRecToRst(
			ListFmncQTolList& rst
			, FmncQTolList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint fabRefFmncMFab
			, const string stubFabRefFmncMFab
			, const ubigint mnfRefFmncMOrg
			, const string stubMnfRefFmncMOrg
			, const double Unitprice
			, const string Training
		) {
	ubigint retval = 0;
	FmncQTolList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, fabRefFmncMFab, stubFabRefFmncMFab, mnfRefFmncMOrg, stubMnfRefFmncMOrg, Unitprice, Training);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolList::insertRst(
			ListFmncQTolList& rst
		) {
};

void TblFmncQTolList::updateRec(
			FmncQTolList* rec
		) {
};

void TblFmncQTolList::updateRst(
			ListFmncQTolList& rst
		) {
};

void TblFmncQTolList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolList::loadRecByQref(
			ubigint qref
			, FmncQTolList** rec
		) {
	return false;
};

ubigint TblFmncQTolList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolList
 ******************************************************************************/

MyTblFmncQTolList::MyTblFmncQTolList() : TblFmncQTolList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolList::~MyTblFmncQTolList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolList (jref, jnum, ref, Title, fabRefFmncMFab, mnfRefFmncMOrg, Unitprice, Training) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolList SET jref = ?, jnum = ?, ref = ?, Title = ?, fabRefFmncMFab = ?, mnfRefFmncMOrg = ?, Unitprice = ?, Training = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolList WHERE jref = ?", false);
};

bool MyTblFmncQTolList::loadRecBySQL(
			const string& sqlstr
			, FmncQTolList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->fabRefFmncMFab = atoll((char*) dbrow[5]); else _rec->fabRefFmncMFab = 0;
		if (dbrow[6]) _rec->mnfRefFmncMOrg = atoll((char*) dbrow[6]); else _rec->mnfRefFmncMOrg = 0;
		if (dbrow[7]) _rec->Unitprice = atof((char*) dbrow[7]); else _rec->Unitprice = 0.0;
		if (dbrow[8]) _rec->Training.assign(dbrow[8], dblengths[8]); else _rec->Training = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->fabRefFmncMFab = atoll((char*) dbrow[5]); else rec->fabRefFmncMFab = 0;
			if (dbrow[6]) rec->mnfRefFmncMOrg = atoll((char*) dbrow[6]); else rec->mnfRefFmncMOrg = 0;
			if (dbrow[7]) rec->Unitprice = atof((char*) dbrow[7]); else rec->Unitprice = 0.0;
			if (dbrow[8]) rec->Training.assign(dbrow[8], dblengths[8]); else rec->Training = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolList::insertRec(
			FmncQTolList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->Title.length();
	l[7] = rec->Training.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->fabRefFmncMFab,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->mnfRefFmncMOrg,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Training.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolList::insertRst(
			ListFmncQTolList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolList::updateRec(
			FmncQTolList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Title.length();
	l[7] = rec->Training.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->fabRefFmncMFab,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->mnfRefFmncMOrg,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Training.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolList / stmtUpdateRec)\n");
};

void MyTblFmncQTolList::updateRst(
			ListFmncQTolList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolList::loadRecByQref(
			ubigint qref
			, FmncQTolList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolList
 ******************************************************************************/

PgTblFmncQTolList::PgTblFmncQTolList() : TblFmncQTolList(), PgTable() {
};

PgTblFmncQTolList::~PgTblFmncQTolList() {
};

void PgTblFmncQTolList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolList_insertRec", "INSERT INTO TblFmncQTolList (jref, jnum, ref, Title, fabRefFmncMFab, mnfRefFmncMOrg, Unitprice, Training) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolList_updateRec", "UPDATE TblFmncQTolList SET jref = $1, jnum = $2, ref = $3, Title = $4, fabRefFmncMFab = $5, mnfRefFmncMOrg = $6, Unitprice = $7, Training = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolList_removeRecByQref", "DELETE FROM TblFmncQTolList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolList_removeRstByJref", "DELETE FROM TblFmncQTolList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, fabRefFmncMFab, mnfRefFmncMOrg, Unitprice, Training FROM TblFmncQTolList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, fabRefFmncMFab, mnfRefFmncMOrg, Unitprice, Training FROM TblFmncQTolList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolList::loadRec(
			PGresult* res
			, FmncQTolList** rec
		) {
	char* ptr;

	FmncQTolList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "fabreffmncmfab"),
			PQfnumber(res, "mnfreffmncmorg"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "training")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->fabRefFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->mnfRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Training.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "fabreffmncmfab"),
			PQfnumber(res, "mnfreffmncmorg"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "training")
		};

		while (numread < numrow) {
			rec = new FmncQTolList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->fabRefFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->mnfRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Training.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolList::loadRecBySQL(
			const string& sqlstr
			, FmncQTolList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolList::insertRec(
			FmncQTolList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _fabRefFmncMFab = htonl64(rec->fabRefFmncMFab);
	ubigint _mnfRefFmncMOrg = htonl64(rec->mnfRefFmncMOrg);
	string _Unitprice = to_string(rec->Unitprice);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_fabRefFmncMFab,
		(char*) &_mnfRefFmncMOrg,
		_Unitprice.c_str(),
		rec->Training.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolList::insertRst(
			ListFmncQTolList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolList::updateRec(
			FmncQTolList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _fabRefFmncMFab = htonl64(rec->fabRefFmncMFab);
	ubigint _mnfRefFmncMOrg = htonl64(rec->mnfRefFmncMOrg);
	string _Unitprice = to_string(rec->Unitprice);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_fabRefFmncMFab,
		(char*) &_mnfRefFmncMOrg,
		_Unitprice.c_str(),
		rec->Training.c_str(),
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
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolList::updateRst(
			ListFmncQTolList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolList::loadRecByQref(
			ubigint qref
			, FmncQTolList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

