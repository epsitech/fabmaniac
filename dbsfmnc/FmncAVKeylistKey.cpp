/**
  * \file FmncAVKeylistKey.cpp
  * database access for table TblFmncAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAVKeylistKey.h"

/******************************************************************************
 class FmncAVKeylistKey
 ******************************************************************************/

FmncAVKeylistKey::FmncAVKeylistKey(
			const ubigint ref
			, const uint klsIxFmncVKeylist
			, const uint klsNum
			, const uint x1IxFmncVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxFmncVKeylist = klsIxFmncVKeylist;
	this->klsNum = klsNum;
	this->x1IxFmncVMaintable = x1IxFmncVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool FmncAVKeylistKey::operator==(
			const FmncAVKeylistKey& comp
		) {
	return false;
};

bool FmncAVKeylistKey::operator!=(
			const FmncAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAVKeylistKey
 ******************************************************************************/

ListFmncAVKeylistKey::ListFmncAVKeylistKey() {
};

ListFmncAVKeylistKey::ListFmncAVKeylistKey(
			const ListFmncAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAVKeylistKey(*(src.nodes[i]));
};

ListFmncAVKeylistKey::~ListFmncAVKeylistKey() {
	clear();
};

void ListFmncAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAVKeylistKey::size() const {
	return(nodes.size());
};

void ListFmncAVKeylistKey::append(
			FmncAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

FmncAVKeylistKey* ListFmncAVKeylistKey::operator[](
			const uint ix
		) {
	FmncAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAVKeylistKey& ListFmncAVKeylistKey::operator=(
			const ListFmncAVKeylistKey& src
		) {
	FmncAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAVKeylistKey::operator==(
			const ListFmncAVKeylistKey& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListFmncAVKeylistKey::operator!=(
			const ListFmncAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAVKeylistKey
 ******************************************************************************/

TblFmncAVKeylistKey::TblFmncAVKeylistKey() {
};

TblFmncAVKeylistKey::~TblFmncAVKeylistKey() {
};

bool TblFmncAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, FmncAVKeylistKey** rec
		) {
	return false;
};

ubigint TblFmncAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	return 0;
};

void TblFmncAVKeylistKey::insertRec(
			FmncAVKeylistKey* rec
		) {
};

ubigint TblFmncAVKeylistKey::insertNewRec(
			FmncAVKeylistKey** rec
			, const uint klsIxFmncVKeylist
			, const uint klsNum
			, const uint x1IxFmncVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAVKeylistKey* _rec = NULL;

	_rec = new FmncAVKeylistKey(0, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAVKeylistKey::appendNewRecToRst(
			ListFmncAVKeylistKey& rst
			, FmncAVKeylistKey** rec
			, const uint klsIxFmncVKeylist
			, const uint klsNum
			, const uint x1IxFmncVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAVKeylistKey::insertRst(
			ListFmncAVKeylistKey& rst
			, bool transact
		) {
};

void TblFmncAVKeylistKey::updateRec(
			FmncAVKeylistKey* rec
		) {
};

void TblFmncAVKeylistKey::updateRst(
			ListFmncAVKeylistKey& rst
			, bool transact
		) {
};

void TblFmncAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAVKeylistKey::loadRecByRef(
			ubigint ref
			, FmncAVKeylistKey** rec
		) {
	return false;
};

bool TblFmncAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxFmncVKeylist
			, uint x1IxFmncVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblFmncAVKeylistKey::loadRefByKlsSrf(
			uint klsIxFmncVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblFmncAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxFmncVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAVKeylistKey::loadRstByKls(
			uint klsIxFmncVKeylist
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblFmncAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxFmncVKeylist
			, uint x1IxFmncVMaintable
			, ubigint x1Uref
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	return 0;
};

bool TblFmncAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	ubigint numload = 0;
	FmncAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAVKeylistKey
 ******************************************************************************/

MyTblFmncAVKeylistKey::MyTblFmncAVKeylistKey() : TblFmncAVKeylistKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAVKeylistKey::~MyTblFmncAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAVKeylistKey (klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAVKeylistKey SET klsIxFmncVKeylist = ?, klsNum = ?, x1IxFmncVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAVKeylistKey WHERE ref = ?", false);
};

bool MyTblFmncAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, FmncAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAVKeylistKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxFmncVKeylist = atol((char*) dbrow[1]); else _rec->klsIxFmncVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxFmncVMaintable = atol((char*) dbrow[3]); else _rec->x1IxFmncVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAVKeylistKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxFmncVKeylist = atol((char*) dbrow[1]); else rec->klsIxFmncVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxFmncVMaintable = atol((char*) dbrow[3]); else rec->x1IxFmncVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAVKeylistKey::insertRec(
			FmncAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxFmncVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxFmncVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVKeylistKey / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVKeylistKey / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAVKeylistKey::insertRst(
			ListFmncAVKeylistKey& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAVKeylistKey::updateRec(
			FmncAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxFmncVKeylist,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x1IxFmncVMaintable,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])), 
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVKeylistKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVKeylistKey / stmtUpdateRec)\n");
};

void MyTblFmncAVKeylistKey::updateRst(
			ListFmncAVKeylistKey& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVKeylistKey / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVKeylistKey / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAVKeylistKey::loadRecByRef(
			ubigint ref
			, FmncAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxFmncVKeylist
			, uint x1IxFmncVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = " + to_string(klsIxFmncVKeylist) + " AND x1IxFmncVMaintable = " + to_string(x1IxFmncVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblFmncAVKeylistKey::loadRefByKlsSrf(
			uint klsIxFmncVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = " + to_string(klsIxFmncVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblFmncAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxFmncVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAVKeylistKey WHERE x1IxFmncVMaintable = " + to_string(x1IxFmncVMaintable) + " AND x1Uref = " + to_string(x1Uref) + "", append, refs);
};

ubigint MyTblFmncAVKeylistKey::loadRstByKls(
			uint klsIxFmncVKeylist
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = " + to_string(klsIxFmncVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblFmncAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxFmncVKeylist
			, uint x1IxFmncVMaintable
			, ubigint x1Uref
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = " + to_string(klsIxFmncVKeylist) + " AND x1IxFmncVMaintable = " + to_string(x1IxFmncVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblFmncAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncAVKeylistKey WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAVKeylistKey
 ******************************************************************************/

PgTblFmncAVKeylistKey::PgTblFmncAVKeylistKey() : TblFmncAVKeylistKey(), PgTable() {
};

PgTblFmncAVKeylistKey::~PgTblFmncAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAVKeylistKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAVKeylistKey_insertRec", "INSERT INTO TblFmncAVKeylistKey (klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_updateRec", "UPDATE TblFmncAVKeylistKey SET klsIxFmncVKeylist = $1, klsNum = $2, x1IxFmncVMaintable = $3, x1Uref = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_removeRecByRef", "DELETE FROM TblFmncAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadRecByRef", "SELECT ref, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncAVKeylistKey WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadRefByKlsMtbUrfSrf", "SELECT ref FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = $1 AND x1IxFmncVMaintable = $2 AND x1Uref = $3 AND sref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadRefByKlsSrf", "SELECT ref FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadRefsByMtbUrf", "SELECT ref FROM TblFmncAVKeylistKey WHERE x1IxFmncVMaintable = $1 AND x1Uref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadRstByKls", "SELECT ref, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = $1 ORDER BY klsNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadRstByKlsMtbUrf", "SELECT ref, klsIxFmncVKeylist, klsNum, x1IxFmncVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblFmncAVKeylistKey WHERE klsIxFmncVKeylist = $1 AND x1IxFmncVMaintable = $2 AND x1Uref = $3 ORDER BY klsNum ASC", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVKeylistKey_loadTitByRef", "SELECT Title FROM TblFmncAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAVKeylistKey::loadRec(
			PGresult* res
			, FmncAVKeylistKey** rec
		) {
	char* ptr;

	FmncAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixfmncvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixfmncvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->klsIxFmncVKeylist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxFmncVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixfmncvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixfmncvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->klsIxFmncVKeylist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxFmncVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVKeylistKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVKeylistKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, FmncAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAVKeylistKey::insertRec(
			FmncAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	uint _klsIxFmncVKeylist = htonl(rec->klsIxFmncVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxFmncVMaintable = htonl(rec->x1IxFmncVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_klsIxFmncVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxFmncVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAVKeylistKey_insertRec", 11, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVKeylistKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAVKeylistKey::insertRst(
			ListFmncAVKeylistKey& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAVKeylistKey::updateRec(
			FmncAVKeylistKey* rec
		) {
	PGresult* res;

	uint _klsIxFmncVKeylist = htonl(rec->klsIxFmncVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxFmncVMaintable = htonl(rec->x1IxFmncVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_klsIxFmncVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxFmncVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAVKeylistKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVKeylistKey_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAVKeylistKey::updateRst(
			ListFmncAVKeylistKey& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVKeylistKey_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAVKeylistKey::loadRecByRef(
			ubigint ref
			, FmncAVKeylistKey** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxFmncVKeylist
			, uint x1IxFmncVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	uint _klsIxFmncVKeylist = htonl(klsIxFmncVKeylist);
	uint _x1IxFmncVMaintable = htonl(x1IxFmncVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxFmncVKeylist,
		(char*) &_x1IxFmncVMaintable,
		(char*) &_x1Uref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadUbigintByStmt("TblFmncAVKeylistKey_loadRefByKlsMtbUrfSrf", 4, vals, l, f, ref);
};

bool PgTblFmncAVKeylistKey::loadRefByKlsSrf(
			uint klsIxFmncVKeylist
			, string sref
			, ubigint& ref
		) {
	uint _klsIxFmncVKeylist = htonl(klsIxFmncVKeylist);

	const char* vals[] = {
		(char*) &_klsIxFmncVKeylist,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblFmncAVKeylistKey_loadRefByKlsSrf", 2, vals, l, f, ref);
};

ubigint PgTblFmncAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxFmncVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _x1IxFmncVMaintable = htonl(x1IxFmncVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_x1IxFmncVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblFmncAVKeylistKey_loadRefsByMtbUrf", 2, vals, l, f, append, refs);
};

ubigint PgTblFmncAVKeylistKey::loadRstByKls(
			uint klsIxFmncVKeylist
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	uint _klsIxFmncVKeylist = htonl(klsIxFmncVKeylist);

	const char* vals[] = {
		(char*) &_klsIxFmncVKeylist
	};
	const int l[] = {
		sizeof(uint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncAVKeylistKey_loadRstByKls", 1, vals, l, f, append, rst);
};

ubigint PgTblFmncAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxFmncVKeylist
			, uint x1IxFmncVMaintable
			, ubigint x1Uref
			, const bool append
			, ListFmncAVKeylistKey& rst
		) {
	uint _klsIxFmncVKeylist = htonl(klsIxFmncVKeylist);
	uint _x1IxFmncVMaintable = htonl(x1IxFmncVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxFmncVKeylist,
		(char*) &_x1IxFmncVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblFmncAVKeylistKey_loadRstByKlsMtbUrf", 3, vals, l, f, append, rst);
};

bool PgTblFmncAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblFmncAVKeylistKey_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

