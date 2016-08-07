/**
  * \file FmncMTooltype.cpp
  * database access for table TblFmncMTooltype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMTooltype.h"

/******************************************************************************
 class FmncMTooltype
 ******************************************************************************/

FmncMTooltype::FmncMTooltype(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint supRefFmncMTooltype
			, const usmallint supLvl
			, const string sref
			, const string Title
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->supRefFmncMTooltype = supRefFmncMTooltype;
	this->supLvl = supLvl;
	this->sref = sref;
	this->Title = Title;
};

bool FmncMTooltype::operator==(
			const FmncMTooltype& comp
		) {
	return false;
};

bool FmncMTooltype::operator!=(
			const FmncMTooltype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMTooltype
 ******************************************************************************/

ListFmncMTooltype::ListFmncMTooltype() {
};

ListFmncMTooltype::ListFmncMTooltype(
			const ListFmncMTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMTooltype(*(src.nodes[i]));
};

ListFmncMTooltype::~ListFmncMTooltype() {
	clear();
};

void ListFmncMTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMTooltype::size() const {
	return(nodes.size());
};

void ListFmncMTooltype::append(
			FmncMTooltype* rec
		) {
	nodes.push_back(rec);
};

FmncMTooltype* ListFmncMTooltype::operator[](
			const uint ix
		) {
	FmncMTooltype* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMTooltype& ListFmncMTooltype::operator=(
			const ListFmncMTooltype& src
		) {
	FmncMTooltype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMTooltype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMTooltype::operator==(
			const ListFmncMTooltype& comp
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

bool ListFmncMTooltype::operator!=(
			const ListFmncMTooltype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMTooltype
 ******************************************************************************/

TblFmncMTooltype::TblFmncMTooltype() {
};

TblFmncMTooltype::~TblFmncMTooltype() {
};

bool TblFmncMTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncMTooltype** rec
		) {
	return false;
};

ubigint TblFmncMTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMTooltype& rst
		) {
	return 0;
};

void TblFmncMTooltype::insertRec(
			FmncMTooltype* rec
		) {
};

ubigint TblFmncMTooltype::insertNewRec(
			FmncMTooltype** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint supRefFmncMTooltype
			, const usmallint supLvl
			, const string sref
			, const string Title
		) {
	ubigint retval = 0;
	FmncMTooltype* _rec = NULL;

	_rec = new FmncMTooltype(0, grp, own, supRefFmncMTooltype, supLvl, sref, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMTooltype::appendNewRecToRst(
			ListFmncMTooltype& rst
			, FmncMTooltype** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint supRefFmncMTooltype
			, const usmallint supLvl
			, const string sref
			, const string Title
		) {
	ubigint retval = 0;
	FmncMTooltype* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, supRefFmncMTooltype, supLvl, sref, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMTooltype::insertRst(
			ListFmncMTooltype& rst
			, bool transact
		) {
};

void TblFmncMTooltype::updateRec(
			FmncMTooltype* rec
		) {
};

void TblFmncMTooltype::updateRst(
			ListFmncMTooltype& rst
			, bool transact
		) {
};

void TblFmncMTooltype::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMTooltype::loadRecByRef(
			ubigint ref
			, FmncMTooltype** rec
		) {
	return false;
};

bool TblFmncMTooltype::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblFmncMTooltype::loadRefBySupSrf(
			ubigint supRefFmncMTooltype
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblFmncMTooltype::loadRefsBySup(
			ubigint supRefFmncMTooltype
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMTooltype::loadRstBySup(
			ubigint supRefFmncMTooltype
			, const bool append
			, ListFmncMTooltype& rst
		) {
	return 0;
};

bool TblFmncMTooltype::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

ubigint TblFmncMTooltype::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMTooltype& rst
		) {
	ubigint numload = 0;
	FmncMTooltype* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP loadHrefsup --- BEGIN
ubigint TblFmncMTooltype::loadHrefsup(
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
ubigint TblFmncMTooltype::loadHrefsdown(
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
ubigint TblFmncMTooltype::loadHrstup(
			ubigint ref
			, ListFmncMTooltype& rst
		) {
	FmncMTooltype* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefFmncMTooltype;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
ubigint TblFmncMTooltype::loadHrstdown(
			ubigint ref
			, const bool append
			, ListFmncMTooltype& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	FmncMTooltype* rec = NULL;

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
 class MyTblFmncMTooltype
 ******************************************************************************/

MyTblFmncMTooltype::MyTblFmncMTooltype() : TblFmncMTooltype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMTooltype::~MyTblFmncMTooltype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMTooltype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMTooltype (grp, own, supRefFmncMTooltype, supLvl, sref, Title) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMTooltype SET grp = ?, own = ?, supRefFmncMTooltype = ?, supLvl = ?, sref = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMTooltype WHERE ref = ?", false);
};

bool MyTblFmncMTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncMTooltype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMTooltype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMTooltype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMTooltype();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->supRefFmncMTooltype = atoll((char*) dbrow[3]); else _rec->supRefFmncMTooltype = 0;
		if (dbrow[4]) _rec->supLvl = atoi((char*) dbrow[4]); else _rec->supLvl = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMTooltype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMTooltype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMTooltype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMTooltype();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->supRefFmncMTooltype = atoll((char*) dbrow[3]); else rec->supRefFmncMTooltype = 0;
			if (dbrow[4]) rec->supLvl = atoi((char*) dbrow[4]); else rec->supLvl = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMTooltype::insertRec(
			FmncMTooltype* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->supRefFmncMTooltype,&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->supLvl,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMTooltype / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMTooltype / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMTooltype::insertRst(
			ListFmncMTooltype& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMTooltype::updateRec(
			FmncMTooltype* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->supRefFmncMTooltype,&(l[2]),&(n[2]),&(e[2])), 
		bindUsmallint(&rec->supLvl,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMTooltype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMTooltype / stmtUpdateRec)\n");
};

void MyTblFmncMTooltype::updateRst(
			ListFmncMTooltype& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMTooltype::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMTooltype / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMTooltype / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMTooltype::loadRecByRef(
			ubigint ref
			, FmncMTooltype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMTooltype WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMTooltype::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadUbigintBySQL("SELECT ref FROM TblFmncMTooltype WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblFmncMTooltype::loadRefBySupSrf(
			ubigint supRefFmncMTooltype
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMTooltype WHERE supRefFmncMTooltype = " + to_string(supRefFmncMTooltype) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblFmncMTooltype::loadRefsBySup(
			ubigint supRefFmncMTooltype
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMTooltype WHERE supRefFmncMTooltype = " + to_string(supRefFmncMTooltype) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblFmncMTooltype::loadRstBySup(
			ubigint supRefFmncMTooltype
			, const bool append
			, ListFmncMTooltype& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, supRefFmncMTooltype, supLvl, sref, Title FROM TblFmncMTooltype WHERE supRefFmncMTooltype = " + to_string(supRefFmncMTooltype) + " ORDER BY sref ASC", append, rst);
};

bool MyTblFmncMTooltype::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT supRefFmncMTooltype FROM TblFmncMTooltype WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMTooltype
 ******************************************************************************/

PgTblFmncMTooltype::PgTblFmncMTooltype() : TblFmncMTooltype(), PgTable() {
};

PgTblFmncMTooltype::~PgTblFmncMTooltype() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMTooltype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMTooltype_insertRec", "INSERT INTO TblFmncMTooltype (grp, own, supRefFmncMTooltype, supLvl, sref, Title) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTooltype_updateRec", "UPDATE TblFmncMTooltype SET grp = $1, own = $2, supRefFmncMTooltype = $3, supLvl = $4, sref = $5, Title = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTooltype_removeRecByRef", "DELETE FROM TblFmncMTooltype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMTooltype_loadRecByRef", "SELECT ref, grp, own, supRefFmncMTooltype, supLvl, sref, Title FROM TblFmncMTooltype WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMTooltype_confirmByRef", "SELECT ref FROM TblFmncMTooltype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTooltype_loadRefBySupSrf", "SELECT ref FROM TblFmncMTooltype WHERE supRefFmncMTooltype = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTooltype_loadRefsBySup", "SELECT ref FROM TblFmncMTooltype WHERE supRefFmncMTooltype = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTooltype_loadRstBySup", "SELECT ref, grp, own, supRefFmncMTooltype, supLvl, sref, Title FROM TblFmncMTooltype WHERE supRefFmncMTooltype = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTooltype_loadSupByRef", "SELECT supRefFmncMTooltype FROM TblFmncMTooltype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMTooltype::loadRec(
			PGresult* res
			, FmncMTooltype** rec
		) {
	char* ptr;

	FmncMTooltype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMTooltype();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "supreffmncmtooltype"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supRefFmncMTooltype = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMTooltype::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMTooltype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMTooltype* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "supreffmncmtooltype"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new FmncMTooltype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supRefFmncMTooltype = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMTooltype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMTooltype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTooltype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncMTooltype::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncMTooltype& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTooltype / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncMTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncMTooltype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMTooltype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMTooltype::insertRec(
			FmncMTooltype* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _supRefFmncMTooltype = htonl64(rec->supRefFmncMTooltype);
	usmallint _supLvl = htons(rec->supLvl);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_supRefFmncMTooltype,
		(char*) &_supLvl,
		rec->sref.c_str(),
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMTooltype_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTooltype_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMTooltype::insertRst(
			ListFmncMTooltype& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMTooltype::updateRec(
			FmncMTooltype* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _supRefFmncMTooltype = htonl64(rec->supRefFmncMTooltype);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_supRefFmncMTooltype,
		(char*) &_supLvl,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMTooltype_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTooltype_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMTooltype::updateRst(
			ListFmncMTooltype& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMTooltype::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMTooltype_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTooltype_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMTooltype::loadRecByRef(
			ubigint ref
			, FmncMTooltype** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMTooltype_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMTooltype::confirmByRef(
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

	return loadUbigintByStmt("TblFmncMTooltype_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblFmncMTooltype::loadRefBySupSrf(
			ubigint supRefFmncMTooltype
			, string sref
			, ubigint& ref
		) {
	ubigint _supRefFmncMTooltype = htonl64(supRefFmncMTooltype);

	const char* vals[] = {
		(char*) &_supRefFmncMTooltype,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblFmncMTooltype_loadRefBySupSrf", 2, vals, l, f, ref);
};

ubigint PgTblFmncMTooltype::loadRefsBySup(
			ubigint supRefFmncMTooltype
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefFmncMTooltype = htonl64(supRefFmncMTooltype);

	const char* vals[] = {
		(char*) &_supRefFmncMTooltype
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMTooltype_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncMTooltype::loadRstBySup(
			ubigint supRefFmncMTooltype
			, const bool append
			, ListFmncMTooltype& rst
		) {
	ubigint _supRefFmncMTooltype = htonl64(supRefFmncMTooltype);

	const char* vals[] = {
		(char*) &_supRefFmncMTooltype
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncMTooltype_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblFmncMTooltype::loadSupByRef(
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

	return loadUbigintByStmt("TblFmncMTooltype_loadSupByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

