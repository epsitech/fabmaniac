/**
  * \file FmncMSample.cpp
  * database access for table TblFmncMSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMSample.h"

/******************************************************************************
 class FmncMSample
 ******************************************************************************/

FmncMSample::FmncMSample(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint supRefFmncMSample
			, const usmallint supLvl
			, const ubigint refFmncMArticle
			, const string sref
			, const string Material
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->supRefFmncMSample = supRefFmncMSample;
	this->supLvl = supLvl;
	this->refFmncMArticle = refFmncMArticle;
	this->sref = sref;
	this->Material = Material;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Comment = Comment;
};

bool FmncMSample::operator==(
			const FmncMSample& comp
		) {
	return false;
};

bool FmncMSample::operator!=(
			const FmncMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMSample
 ******************************************************************************/

ListFmncMSample::ListFmncMSample() {
};

ListFmncMSample::ListFmncMSample(
			const ListFmncMSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMSample(*(src.nodes[i]));
};

ListFmncMSample::~ListFmncMSample() {
	clear();
};

void ListFmncMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMSample::size() const {
	return(nodes.size());
};

void ListFmncMSample::append(
			FmncMSample* rec
		) {
	nodes.push_back(rec);
};

FmncMSample* ListFmncMSample::operator[](
			const uint ix
		) {
	FmncMSample* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMSample& ListFmncMSample::operator=(
			const ListFmncMSample& src
		) {
	FmncMSample* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMSample(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMSample::operator==(
			const ListFmncMSample& comp
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

bool ListFmncMSample::operator!=(
			const ListFmncMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMSample
 ******************************************************************************/

TblFmncMSample::TblFmncMSample() {
};

TblFmncMSample::~TblFmncMSample() {
};

bool TblFmncMSample::loadRecBySQL(
			const string& sqlstr
			, FmncMSample** rec
		) {
	return false;
};

ubigint TblFmncMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMSample& rst
		) {
	return 0;
};

void TblFmncMSample::insertRec(
			FmncMSample* rec
		) {
};

ubigint TblFmncMSample::insertNewRec(
			FmncMSample** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint supRefFmncMSample
			, const usmallint supLvl
			, const ubigint refFmncMArticle
			, const string sref
			, const string Material
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMSample* _rec = NULL;

	_rec = new FmncMSample(0, grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMSample::appendNewRecToRst(
			ListFmncMSample& rst
			, FmncMSample** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint supRefFmncMSample
			, const usmallint supLvl
			, const ubigint refFmncMArticle
			, const string sref
			, const string Material
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMSample* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMSample::insertRst(
			ListFmncMSample& rst
			, bool transact
		) {
};

void TblFmncMSample::updateRec(
			FmncMSample* rec
		) {
};

void TblFmncMSample::updateRst(
			ListFmncMSample& rst
			, bool transact
		) {
};

void TblFmncMSample::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMSample::loadRecByRef(
			ubigint ref
			, FmncMSample** rec
		) {
	return false;
};

bool TblFmncMSample::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblFmncMSample::loadRefBySupSrf(
			ubigint supRefFmncMSample
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblFmncMSample::loadRefsBySup(
			ubigint supRefFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMSample::loadRstBySup(
			ubigint supRefFmncMSample
			, const bool append
			, ListFmncMSample& rst
		) {
	return 0;
};

bool TblFmncMSample::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

bool TblFmncMSample::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

ubigint TblFmncMSample::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMSample& rst
		) {
	ubigint numload = 0;
	FmncMSample* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP loadHrefsup --- BEGIN
ubigint TblFmncMSample::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
ubigint TblFmncMSample::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
ubigint TblFmncMSample::loadHrstup(
			ubigint ref
			, ListFmncMSample& rst
		) {
	FmncMSample* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefFmncMSample;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
ubigint TblFmncMSample::loadHrstdown(
			ubigint ref
			, const bool append
			, ListFmncMSample& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	FmncMSample* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};
// IP loadHrstdown --- END

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMSample
 ******************************************************************************/

MyTblFmncMSample::MyTblFmncMSample() : TblFmncMSample(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMSample::~MyTblFmncMSample() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMSample::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMSample (grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMSample SET grp = ?, own = ?, supRefFmncMSample = ?, supLvl = ?, refFmncMArticle = ?, sref = ?, Material = ?, refJState = ?, ixVState = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMSample WHERE ref = ?", false);
};

bool MyTblFmncMSample::loadRecBySQL(
			const string& sqlstr
			, FmncMSample** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMSample* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMSample / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMSample();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->supRefFmncMSample = atoll((char*) dbrow[3]); else _rec->supRefFmncMSample = 0;
		if (dbrow[4]) _rec->supLvl = atoi((char*) dbrow[4]); else _rec->supLvl = 0;
		if (dbrow[5]) _rec->refFmncMArticle = atoll((char*) dbrow[5]); else _rec->refFmncMArticle = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Material.assign(dbrow[7], dblengths[7]); else _rec->Material = "";
		if (dbrow[8]) _rec->refJState = atoll((char*) dbrow[8]); else _rec->refJState = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMSample& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMSample* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMSample / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMSample();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->supRefFmncMSample = atoll((char*) dbrow[3]); else rec->supRefFmncMSample = 0;
			if (dbrow[4]) rec->supLvl = atoi((char*) dbrow[4]); else rec->supLvl = 0;
			if (dbrow[5]) rec->refFmncMArticle = atoll((char*) dbrow[5]); else rec->refFmncMArticle = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Material.assign(dbrow[7], dblengths[7]); else rec->Material = "";
			if (dbrow[8]) rec->refJState = atoll((char*) dbrow[8]); else rec->refJState = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMSample::insertRec(
			FmncMSample* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->sref.length();
	l[6] = rec->Material.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->supRefFmncMSample,&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->supLvl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMArticle,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Material.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refJState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMSample / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMSample / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMSample::insertRst(
			ListFmncMSample& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMSample::updateRec(
			FmncMSample* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->sref.length();
	l[6] = rec->Material.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->supRefFmncMSample,&(l[2]),&(n[2]),&(e[2])), 
		bindUsmallint(&rec->supLvl,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMArticle,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Material.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->refJState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMSample / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMSample / stmtUpdateRec)\n");
};

void MyTblFmncMSample::updateRst(
			ListFmncMSample& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMSample::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMSample / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMSample / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMSample::loadRecByRef(
			ubigint ref
			, FmncMSample** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMSample WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMSample::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadUbigintBySQL("SELECT ref FROM TblFmncMSample WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblFmncMSample::loadRefBySupSrf(
			ubigint supRefFmncMSample
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMSample WHERE supRefFmncMSample = " + to_string(supRefFmncMSample) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblFmncMSample::loadRefsBySup(
			ubigint supRefFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMSample WHERE supRefFmncMSample = " + to_string(supRefFmncMSample) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblFmncMSample::loadRstBySup(
			ubigint supRefFmncMSample
			, const bool append
			, ListFmncMSample& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment FROM TblFmncMSample WHERE supRefFmncMSample = " + to_string(supRefFmncMSample) + " ORDER BY sref ASC", append, rst);
};

bool MyTblFmncMSample::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblFmncMSample WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblFmncMSample::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT supRefFmncMSample FROM TblFmncMSample WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMSample
 ******************************************************************************/

PgTblFmncMSample::PgTblFmncMSample() : TblFmncMSample(), PgTable() {
};

PgTblFmncMSample::~PgTblFmncMSample() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMSample::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMSample_insertRec", "INSERT INTO TblFmncMSample (grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_updateRec", "UPDATE TblFmncMSample SET grp = $1, own = $2, supRefFmncMSample = $3, supLvl = $4, refFmncMArticle = $5, sref = $6, Material = $7, refJState = $8, ixVState = $9, Comment = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_removeRecByRef", "DELETE FROM TblFmncMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMSample_loadRecByRef", "SELECT ref, grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment FROM TblFmncMSample WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMSample_confirmByRef", "SELECT ref FROM TblFmncMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_loadRefBySupSrf", "SELECT ref FROM TblFmncMSample WHERE supRefFmncMSample = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_loadRefsBySup", "SELECT ref FROM TblFmncMSample WHERE supRefFmncMSample = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_loadRstBySup", "SELECT ref, grp, own, supRefFmncMSample, supLvl, refFmncMArticle, sref, Material, refJState, ixVState, Comment FROM TblFmncMSample WHERE supRefFmncMSample = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_loadSrfByRef", "SELECT sref FROM TblFmncMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSample_loadSupByRef", "SELECT supRefFmncMSample FROM TblFmncMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMSample::loadRec(
			PGresult* res
			, FmncMSample** rec
		) {
	char* ptr;

	FmncMSample* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMSample();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "supreffmncmsample"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "material"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supRefFmncMSample = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Material.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMSample::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMSample& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMSample* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "supreffmncmsample"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "material"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMSample();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supRefFmncMSample = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Material.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMSample::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMSample** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSample / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncMSample::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncMSample& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSample / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncMSample::loadRecBySQL(
			const string& sqlstr
			, FmncMSample** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMSample& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMSample::insertRec(
			FmncMSample* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _supRefFmncMSample = htonl64(rec->supRefFmncMSample);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_supRefFmncMSample,
		(char*) &_supLvl,
		(char*) &_refFmncMArticle,
		rec->sref.c_str(),
		rec->Material.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMSample_insertRec", 10, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSample_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMSample::insertRst(
			ListFmncMSample& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMSample::updateRec(
			FmncMSample* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _supRefFmncMSample = htonl64(rec->supRefFmncMSample);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_supRefFmncMSample,
		(char*) &_supLvl,
		(char*) &_refFmncMArticle,
		rec->sref.c_str(),
		rec->Material.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMSample_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSample_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMSample::updateRst(
			ListFmncMSample& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMSample::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMSample_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSample_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMSample::loadRecByRef(
			ubigint ref
			, FmncMSample** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMSample_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMSample::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblFmncMSample_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblFmncMSample::loadRefBySupSrf(
			ubigint supRefFmncMSample
			, string sref
			, ubigint& ref
		) {
	ubigint _supRefFmncMSample = htonl64(supRefFmncMSample);

	const char* vals[] = {
		(char*) &_supRefFmncMSample,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblFmncMSample_loadRefBySupSrf", 2, vals, l, f, ref);
};

ubigint PgTblFmncMSample::loadRefsBySup(
			ubigint supRefFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefFmncMSample = htonl64(supRefFmncMSample);

	const char* vals[] = {
		(char*) &_supRefFmncMSample
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMSample_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncMSample::loadRstBySup(
			ubigint supRefFmncMSample
			, const bool append
			, ListFmncMSample& rst
		) {
	ubigint _supRefFmncMSample = htonl64(supRefFmncMSample);

	const char* vals[] = {
		(char*) &_supRefFmncMSample
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncMSample_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblFmncMSample::loadSrfByRef(
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

	return loadStringByStmt("TblFmncMSample_loadSrfByRef", 1, vals, l, f, val);
};

bool PgTblFmncMSample::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblFmncMSample_loadSupByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

