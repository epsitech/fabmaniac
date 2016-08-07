/**
  * \file FmncQSepAPar.cpp
  * Dbs and XML wrapper for table TblFmncQSepAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSepAPar.h"

/******************************************************************************
 class FmncQSepAPar
 ******************************************************************************/

FmncQSepAPar::FmncQSepAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1OsrefFmncKSteppar
			, const string titX1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const string srefX2IxVTbl
			, const string titX2IxVTbl
			, const ubigint x2Uref
			, const string stubX2Uref
			, const string Val
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1OsrefFmncKSteppar = x1OsrefFmncKSteppar;
	this->titX1OsrefFmncKSteppar = titX1OsrefFmncKSteppar;
	this->x2IxVTbl = x2IxVTbl;
	this->srefX2IxVTbl = srefX2IxVTbl;
	this->titX2IxVTbl = titX2IxVTbl;
	this->x2Uref = x2Uref;
	this->stubX2Uref = stubX2Uref;
	this->Val = Val;
	this->Comment = Comment;
};

void FmncQSepAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSepAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "spa", x1OsrefFmncKSteppar);
		writeString(wr, "spa2", titX1OsrefFmncKSteppar);
		writeString(wr, "ret", srefX2IxVTbl);
		writeString(wr, "ret2", titX2IxVTbl);
		writeString(wr, "reu", stubX2Uref);
		writeString(wr, "val", Val);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "x1OsrefFmncKSteppar", x1OsrefFmncKSteppar);
		writeString(wr, "titX1OsrefFmncKSteppar", titX1OsrefFmncKSteppar);
		writeString(wr, "srefX2IxVTbl", srefX2IxVTbl);
		writeString(wr, "titX2IxVTbl", titX2IxVTbl);
		writeString(wr, "stubX2Uref", stubX2Uref);
		writeString(wr, "Val", Val);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQSepAPar
 ******************************************************************************/

ListFmncQSepAPar::ListFmncQSepAPar() {
};

ListFmncQSepAPar::ListFmncQSepAPar(
			const ListFmncQSepAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepAPar(*(src.nodes[i]));
};

ListFmncQSepAPar::~ListFmncQSepAPar() {
	clear();
};

void ListFmncQSepAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSepAPar::size() const {
	return(nodes.size());
};

void ListFmncQSepAPar::append(
			FmncQSepAPar* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSepAPar& ListFmncQSepAPar::operator=(
			const ListFmncQSepAPar& src
		) {
	FmncQSepAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSepAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSepAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSepAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSepAPar
 ******************************************************************************/

TblFmncQSepAPar::TblFmncQSepAPar() {
};

TblFmncQSepAPar::~TblFmncQSepAPar() {
};

bool TblFmncQSepAPar::loadRecBySQL(
			const string& sqlstr
			, FmncQSepAPar** rec
		) {
	return false;
};

ubigint TblFmncQSepAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	return 0;
};

void TblFmncQSepAPar::insertRec(
			FmncQSepAPar* rec
		) {
};

ubigint TblFmncQSepAPar::insertNewRec(
			FmncQSepAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1OsrefFmncKSteppar
			, const string titX1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const string srefX2IxVTbl
			, const string titX2IxVTbl
			, const ubigint x2Uref
			, const string stubX2Uref
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQSepAPar* _rec = NULL;

	_rec = new FmncQSepAPar(0, jref, jnum, ref, x1OsrefFmncKSteppar, titX1OsrefFmncKSteppar, x2IxVTbl, srefX2IxVTbl, titX2IxVTbl, x2Uref, stubX2Uref, Val, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSepAPar::appendNewRecToRst(
			ListFmncQSepAPar& rst
			, FmncQSepAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1OsrefFmncKSteppar
			, const string titX1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const string srefX2IxVTbl
			, const string titX2IxVTbl
			, const ubigint x2Uref
			, const string stubX2Uref
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncQSepAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1OsrefFmncKSteppar, titX1OsrefFmncKSteppar, x2IxVTbl, srefX2IxVTbl, titX2IxVTbl, x2Uref, stubX2Uref, Val, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSepAPar::insertRst(
			ListFmncQSepAPar& rst
		) {
};

void TblFmncQSepAPar::updateRec(
			FmncQSepAPar* rec
		) {
};

void TblFmncQSepAPar::updateRst(
			ListFmncQSepAPar& rst
		) {
};

void TblFmncQSepAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSepAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSepAPar::loadRecByQref(
			ubigint qref
			, FmncQSepAPar** rec
		) {
	return false;
};

ubigint TblFmncQSepAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSepAPar
 ******************************************************************************/

MyTblFmncQSepAPar::MyTblFmncQSepAPar() : TblFmncQSepAPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSepAPar::~MyTblFmncQSepAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSepAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSepAPar (jref, jnum, ref, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSepAPar SET jref = ?, jnum = ?, ref = ?, x1OsrefFmncKSteppar = ?, x2IxVTbl = ?, x2Uref = ?, Val = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSepAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSepAPar WHERE jref = ?", false);
};

bool MyTblFmncQSepAPar::loadRecBySQL(
			const string& sqlstr
			, FmncQSepAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSepAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSepAPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSepAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1OsrefFmncKSteppar.assign(dbrow[4], dblengths[4]); else _rec->x1OsrefFmncKSteppar = "";
		if (dbrow[5]) _rec->x2IxVTbl = atol((char*) dbrow[5]); else _rec->x2IxVTbl = 0;
		if (dbrow[6]) _rec->x2Uref = atoll((char*) dbrow[6]); else _rec->x2Uref = 0;
		if (dbrow[7]) _rec->Val.assign(dbrow[7], dblengths[7]); else _rec->Val = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQSepAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSepAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSepAPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSepAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1OsrefFmncKSteppar.assign(dbrow[4], dblengths[4]); else rec->x1OsrefFmncKSteppar = "";
			if (dbrow[5]) rec->x2IxVTbl = atol((char*) dbrow[5]); else rec->x2IxVTbl = 0;
			if (dbrow[6]) rec->x2Uref = atoll((char*) dbrow[6]); else rec->x2Uref = 0;
			if (dbrow[7]) rec->Val.assign(dbrow[7], dblengths[7]); else rec->Val = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQSepAPar::insertRec(
			FmncQSepAPar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->x1OsrefFmncKSteppar.length();
	l[6] = rec->Val.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1OsrefFmncKSteppar.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x2IxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->x2Uref,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Val.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepAPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepAPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSepAPar::insertRst(
			ListFmncQSepAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSepAPar::updateRec(
			FmncQSepAPar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->x1OsrefFmncKSteppar.length();
	l[6] = rec->Val.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x1OsrefFmncKSteppar.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->x2IxVTbl,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->x2Uref,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepAPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepAPar / stmtUpdateRec)\n");
};

void MyTblFmncQSepAPar::updateRst(
			ListFmncQSepAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSepAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepAPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepAPar / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSepAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepAPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepAPar / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSepAPar::loadRecByQref(
			ubigint qref
			, FmncQSepAPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSepAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSepAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSepAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSepAPar
 ******************************************************************************/

PgTblFmncQSepAPar::PgTblFmncQSepAPar() : TblFmncQSepAPar(), PgTable() {
};

PgTblFmncQSepAPar::~PgTblFmncQSepAPar() {
};

void PgTblFmncQSepAPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSepAPar_insertRec", "INSERT INTO TblFmncQSepAPar (jref, jnum, ref, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepAPar_updateRec", "UPDATE TblFmncQSepAPar SET jref = $1, jnum = $2, ref = $3, x1OsrefFmncKSteppar = $4, x2IxVTbl = $5, x2Uref = $6, Val = $7, Comment = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepAPar_removeRecByQref", "DELETE FROM TblFmncQSepAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepAPar_removeRstByJref", "DELETE FROM TblFmncQSepAPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSepAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment FROM TblFmncQSepAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment FROM TblFmncQSepAPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSepAPar::loadRec(
			PGresult* res
			, FmncQSepAPar** rec
		) {
	char* ptr;

	FmncQSepAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSepAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1osreffmncksteppar"),
			PQfnumber(res, "x2ixvtbl"),
			PQfnumber(res, "x2uref"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1OsrefFmncKSteppar.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2IxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x2Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQSepAPar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSepAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1osreffmncksteppar"),
			PQfnumber(res, "x2ixvtbl"),
			PQfnumber(res, "x2uref"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncQSepAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1OsrefFmncKSteppar.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2IxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x2Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQSepAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSepAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepAPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSepAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepAPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSepAPar::loadRecBySQL(
			const string& sqlstr
			, FmncQSepAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSepAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSepAPar::insertRec(
			FmncQSepAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x2IxVTbl = htonl(rec->x2IxVTbl);
	ubigint _x2Uref = htonl64(rec->x2Uref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1OsrefFmncKSteppar.c_str(),
		(char*) &_x2IxVTbl,
		(char*) &_x2Uref,
		rec->Val.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQSepAPar_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepAPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSepAPar::insertRst(
			ListFmncQSepAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSepAPar::updateRec(
			FmncQSepAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x2IxVTbl = htonl(rec->x2IxVTbl);
	ubigint _x2Uref = htonl64(rec->x2Uref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1OsrefFmncKSteppar.c_str(),
		(char*) &_x2IxVTbl,
		(char*) &_x2Uref,
		rec->Val.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQSepAPar_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepAPar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSepAPar::updateRst(
			ListFmncQSepAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSepAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSepAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepAPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSepAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSepAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepAPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSepAPar::loadRecByQref(
			ubigint qref
			, FmncQSepAPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSepAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSepAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSepAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

