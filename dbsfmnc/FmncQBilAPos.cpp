/**
  * \file FmncQBilAPos.cpp
  * Dbs and XML wrapper for table TblFmncQBilAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQBilAPos.h"

/******************************************************************************
 class FmncQBilAPos
 ******************************************************************************/

FmncQBilAPos::FmncQBilAPos(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint bilNum
			, const ubigint x1RefFmncMFabuser
			, const string stubX1RefFmncMFabuser
			, const ubigint x2RefFmncMTool
			, const string stubX2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->bilNum = bilNum;
	this->x1RefFmncMFabuser = x1RefFmncMFabuser;
	this->stubX1RefFmncMFabuser = stubX1RefFmncMFabuser;
	this->x2RefFmncMTool = x2RefFmncMTool;
	this->stubX2RefFmncMTool = stubX2RefFmncMTool;
	this->Quantity = Quantity;
	this->Article = Article;
	this->Unitprice = Unitprice;
	this->Price = Price;
};

void FmncQBilAPos::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQBilAPos";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fus", stubX1RefFmncMFabuser);
		writeString(wr, "tol", stubX2RefFmncMTool);
		writeDouble(wr, "qty", Quantity);
		writeString(wr, "art", Article);
		writeDouble(wr, "upr", Unitprice);
		writeDouble(wr, "prc", Price);
	} else {
		writeString(wr, "stubX1RefFmncMFabuser", stubX1RefFmncMFabuser);
		writeString(wr, "stubX2RefFmncMTool", stubX2RefFmncMTool);
		writeDouble(wr, "Quantity", Quantity);
		writeString(wr, "Article", Article);
		writeDouble(wr, "Unitprice", Unitprice);
		writeDouble(wr, "Price", Price);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQBilAPos
 ******************************************************************************/

ListFmncQBilAPos::ListFmncQBilAPos() {
};

ListFmncQBilAPos::ListFmncQBilAPos(
			const ListFmncQBilAPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQBilAPos(*(src.nodes[i]));
};

ListFmncQBilAPos::~ListFmncQBilAPos() {
	clear();
};

void ListFmncQBilAPos::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQBilAPos::size() const {
	return(nodes.size());
};

void ListFmncQBilAPos::append(
			FmncQBilAPos* rec
		) {
	nodes.push_back(rec);
};

ListFmncQBilAPos& ListFmncQBilAPos::operator=(
			const ListFmncQBilAPos& src
		) {
	FmncQBilAPos* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQBilAPos(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQBilAPos::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQBilAPos";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQBilAPos
 ******************************************************************************/

TblFmncQBilAPos::TblFmncQBilAPos() {
};

TblFmncQBilAPos::~TblFmncQBilAPos() {
};

bool TblFmncQBilAPos::loadRecBySQL(
			const string& sqlstr
			, FmncQBilAPos** rec
		) {
	return false;
};

ubigint TblFmncQBilAPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	return 0;
};

void TblFmncQBilAPos::insertRec(
			FmncQBilAPos* rec
		) {
};

ubigint TblFmncQBilAPos::insertNewRec(
			FmncQBilAPos** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint bilNum
			, const ubigint x1RefFmncMFabuser
			, const string stubX1RefFmncMFabuser
			, const ubigint x2RefFmncMTool
			, const string stubX2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncQBilAPos* _rec = NULL;

	_rec = new FmncQBilAPos(0, jref, jnum, ref, bilNum, x1RefFmncMFabuser, stubX1RefFmncMFabuser, x2RefFmncMTool, stubX2RefFmncMTool, Quantity, Article, Unitprice, Price);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQBilAPos::appendNewRecToRst(
			ListFmncQBilAPos& rst
			, FmncQBilAPos** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint bilNum
			, const ubigint x1RefFmncMFabuser
			, const string stubX1RefFmncMFabuser
			, const ubigint x2RefFmncMTool
			, const string stubX2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncQBilAPos* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, bilNum, x1RefFmncMFabuser, stubX1RefFmncMFabuser, x2RefFmncMTool, stubX2RefFmncMTool, Quantity, Article, Unitprice, Price);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQBilAPos::insertRst(
			ListFmncQBilAPos& rst
		) {
};

void TblFmncQBilAPos::updateRec(
			FmncQBilAPos* rec
		) {
};

void TblFmncQBilAPos::updateRst(
			ListFmncQBilAPos& rst
		) {
};

void TblFmncQBilAPos::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQBilAPos::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQBilAPos::loadRecByQref(
			ubigint qref
			, FmncQBilAPos** rec
		) {
	return false;
};

ubigint TblFmncQBilAPos::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQBilAPos
 ******************************************************************************/

MyTblFmncQBilAPos::MyTblFmncQBilAPos() : TblFmncQBilAPos(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQBilAPos::~MyTblFmncQBilAPos() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQBilAPos::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQBilAPos (jref, jnum, ref, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQBilAPos SET jref = ?, jnum = ?, ref = ?, bilNum = ?, x1RefFmncMFabuser = ?, x2RefFmncMTool = ?, Quantity = ?, Article = ?, Unitprice = ?, Price = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQBilAPos WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQBilAPos WHERE jref = ?", false);
};

bool MyTblFmncQBilAPos::loadRecBySQL(
			const string& sqlstr
			, FmncQBilAPos** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQBilAPos* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQBilAPos / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQBilAPos();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->bilNum = atol((char*) dbrow[4]); else _rec->bilNum = 0;
		if (dbrow[5]) _rec->x1RefFmncMFabuser = atoll((char*) dbrow[5]); else _rec->x1RefFmncMFabuser = 0;
		if (dbrow[6]) _rec->x2RefFmncMTool = atoll((char*) dbrow[6]); else _rec->x2RefFmncMTool = 0;
		if (dbrow[7]) _rec->Quantity = atof((char*) dbrow[7]); else _rec->Quantity = 0.0;
		if (dbrow[8]) _rec->Article.assign(dbrow[8], dblengths[8]); else _rec->Article = "";
		if (dbrow[9]) _rec->Unitprice = atof((char*) dbrow[9]); else _rec->Unitprice = 0.0;
		if (dbrow[10]) _rec->Price = atof((char*) dbrow[10]); else _rec->Price = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQBilAPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQBilAPos* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQBilAPos / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQBilAPos();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->bilNum = atol((char*) dbrow[4]); else rec->bilNum = 0;
			if (dbrow[5]) rec->x1RefFmncMFabuser = atoll((char*) dbrow[5]); else rec->x1RefFmncMFabuser = 0;
			if (dbrow[6]) rec->x2RefFmncMTool = atoll((char*) dbrow[6]); else rec->x2RefFmncMTool = 0;
			if (dbrow[7]) rec->Quantity = atof((char*) dbrow[7]); else rec->Quantity = 0.0;
			if (dbrow[8]) rec->Article.assign(dbrow[8], dblengths[8]); else rec->Article = "";
			if (dbrow[9]) rec->Unitprice = atof((char*) dbrow[9]); else rec->Unitprice = 0.0;
			if (dbrow[10]) rec->Price = atof((char*) dbrow[10]); else rec->Price = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQBilAPos::insertRec(
			FmncQBilAPos* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[7] = rec->Article.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->bilNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->x2RefFmncMTool,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->Quantity,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Article.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->Unitprice,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->Price,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilAPos / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilAPos / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQBilAPos::insertRst(
			ListFmncQBilAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQBilAPos::updateRec(
			FmncQBilAPos* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[7] = rec->Article.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->bilNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->x2RefFmncMTool,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->Quantity,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Article.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindDouble(&rec->Unitprice,&(l[8]),&(n[8]),&(e[8])), 
		bindDouble(&rec->Price,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilAPos / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilAPos / stmtUpdateRec)\n");
};

void MyTblFmncQBilAPos::updateRst(
			ListFmncQBilAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQBilAPos::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilAPos / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilAPos / stmtRemoveRecByQref)\n");
};

void MyTblFmncQBilAPos::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQBilAPos / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQBilAPos / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQBilAPos::loadRecByQref(
			ubigint qref
			, FmncQBilAPos** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQBilAPos WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQBilAPos::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQBilAPos WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQBilAPos
 ******************************************************************************/

PgTblFmncQBilAPos::PgTblFmncQBilAPos() : TblFmncQBilAPos(), PgTable() {
};

PgTblFmncQBilAPos::~PgTblFmncQBilAPos() {
};

void PgTblFmncQBilAPos::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQBilAPos_insertRec", "INSERT INTO TblFmncQBilAPos (jref, jnum, ref, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilAPos_updateRec", "UPDATE TblFmncQBilAPos SET jref = $1, jnum = $2, ref = $3, bilNum = $4, x1RefFmncMFabuser = $5, x2RefFmncMTool = $6, Quantity = $7, Article = $8, Unitprice = $9, Price = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilAPos_removeRecByQref", "DELETE FROM TblFmncQBilAPos WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilAPos_removeRstByJref", "DELETE FROM TblFmncQBilAPos WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQBilAPos_loadRecByQref", "SELECT qref, jref, jnum, ref, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price FROM TblFmncQBilAPos WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQBilAPos_loadRstByJref", "SELECT qref, jref, jnum, ref, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price FROM TblFmncQBilAPos WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQBilAPos::loadRec(
			PGresult* res
			, FmncQBilAPos** rec
		) {
	char* ptr;

	FmncQBilAPos* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQBilAPos();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "bilnum"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "x2reffmncmtool"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "article"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->bilNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1RefFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x2RefFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Quantity = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Article.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Price = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQBilAPos::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQBilAPos* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "bilnum"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "x2reffmncmtool"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "article"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		while (numread < numrow) {
			rec = new FmncQBilAPos();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->bilNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1RefFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x2RefFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Quantity = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Article.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Price = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQBilAPos::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQBilAPos** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilAPos / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQBilAPos::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilAPos / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQBilAPos::loadRecBySQL(
			const string& sqlstr
			, FmncQBilAPos** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQBilAPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQBilAPos::insertRec(
			FmncQBilAPos* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _bilNum = htonl(rec->bilNum);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	ubigint _x2RefFmncMTool = htonl64(rec->x2RefFmncMTool);
	string _Quantity = to_string(rec->Quantity);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_bilNum,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_x2RefFmncMTool,
		_Quantity.c_str(),
		rec->Article.c_str(),
		_Unitprice.c_str(),
		_Price.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQBilAPos_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilAPos_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQBilAPos::insertRst(
			ListFmncQBilAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQBilAPos::updateRec(
			FmncQBilAPos* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _bilNum = htonl(rec->bilNum);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	ubigint _x2RefFmncMTool = htonl64(rec->x2RefFmncMTool);
	string _Quantity = to_string(rec->Quantity);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_bilNum,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_x2RefFmncMTool,
		_Quantity.c_str(),
		rec->Article.c_str(),
		_Unitprice.c_str(),
		_Price.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQBilAPos_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilAPos_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQBilAPos::updateRst(
			ListFmncQBilAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQBilAPos::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQBilAPos_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilAPos_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQBilAPos::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQBilAPos_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQBilAPos_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQBilAPos::loadRecByQref(
			ubigint qref
			, FmncQBilAPos** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQBilAPos_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQBilAPos::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQBilAPos& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQBilAPos_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

