/**
  * \file FmncMOrg.cpp
  * database access for table TblFmncMOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMOrg.h"

/******************************************************************************
 class FmncMOrg
 ******************************************************************************/

FmncMOrg::FmncMOrg(
			const ubigint ref
			, const uint ixWDerivate
			, const ubigint refFmncMAddress
			, const ubigint supRefFmncMOrg
			, const usmallint supLvl
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
		) {

	this->ref = ref;
	this->ixWDerivate = ixWDerivate;
	this->refFmncMAddress = refFmncMAddress;
	this->supRefFmncMOrg = supRefFmncMOrg;
	this->supLvl = supLvl;
	this->sref = sref;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->telRefADetail = telRefADetail;
	this->Tel = Tel;
	this->emlRefADetail = emlRefADetail;
	this->Eml = Eml;
};

bool FmncMOrg::operator==(
			const FmncMOrg& comp
		) {
	return false;
};

bool FmncMOrg::operator!=(
			const FmncMOrg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMOrg
 ******************************************************************************/

ListFmncMOrg::ListFmncMOrg() {
};

ListFmncMOrg::ListFmncMOrg(
			const ListFmncMOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMOrg(*(src.nodes[i]));
};

ListFmncMOrg::~ListFmncMOrg() {
	clear();
};

void ListFmncMOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMOrg::size() const {
	return(nodes.size());
};

void ListFmncMOrg::append(
			FmncMOrg* rec
		) {
	nodes.push_back(rec);
};

FmncMOrg* ListFmncMOrg::operator[](
			const uint ix
		) {
	FmncMOrg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMOrg& ListFmncMOrg::operator=(
			const ListFmncMOrg& src
		) {
	FmncMOrg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMOrg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMOrg::operator==(
			const ListFmncMOrg& comp
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

bool ListFmncMOrg::operator!=(
			const ListFmncMOrg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMOrg
 ******************************************************************************/

TblFmncMOrg::TblFmncMOrg() {
};

TblFmncMOrg::~TblFmncMOrg() {
};

bool TblFmncMOrg::loadRecBySQL(
			const string& sqlstr
			, FmncMOrg** rec
		) {
	return false;
};

ubigint TblFmncMOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMOrg& rst
		) {
	return 0;
};

void TblFmncMOrg::insertRec(
			FmncMOrg* rec
		) {
};

ubigint TblFmncMOrg::insertNewRec(
			FmncMOrg** rec
			, const uint ixWDerivate
			, const ubigint refFmncMAddress
			, const ubigint supRefFmncMOrg
			, const usmallint supLvl
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
		) {
	ubigint retval = 0;
	FmncMOrg* _rec = NULL;

	_rec = new FmncMOrg(0, ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMOrg::appendNewRecToRst(
			ListFmncMOrg& rst
			, FmncMOrg** rec
			, const uint ixWDerivate
			, const ubigint refFmncMAddress
			, const ubigint supRefFmncMOrg
			, const usmallint supLvl
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
		) {
	ubigint retval = 0;
	FmncMOrg* _rec = NULL;

	retval = insertNewRec(&_rec, ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMOrg::insertRst(
			ListFmncMOrg& rst
			, bool transact
		) {
};

void TblFmncMOrg::updateRec(
			FmncMOrg* rec
		) {
};

void TblFmncMOrg::updateRst(
			ListFmncMOrg& rst
			, bool transact
		) {
};

void TblFmncMOrg::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMOrg::loadRecByRef(
			ubigint ref
			, FmncMOrg** rec
		) {
	return false;
};

bool TblFmncMOrg::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblFmncMOrg::loadRefBySupSrf(
			ubigint supRefFmncMOrg
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblFmncMOrg::loadRefsBySup(
			ubigint supRefFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMOrg::loadRstBySup(
			ubigint supRefFmncMOrg
			, const bool append
			, ListFmncMOrg& rst
		) {
	return 0;
};

bool TblFmncMOrg::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

bool TblFmncMOrg::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

bool TblFmncMOrg::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMOrg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMOrg& rst
		) {
	ubigint numload = 0;
	FmncMOrg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP loadHrefsup --- BEGIN
ubigint TblFmncMOrg::loadHrefsup(
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
ubigint TblFmncMOrg::loadHrefsdown(
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
ubigint TblFmncMOrg::loadHrstup(
			ubigint ref
			, ListFmncMOrg& rst
		) {
	FmncMOrg* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefFmncMOrg;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
ubigint TblFmncMOrg::loadHrstdown(
			ubigint ref
			, const bool append
			, ListFmncMOrg& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	FmncMOrg* rec = NULL;

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
 class MyTblFmncMOrg
 ******************************************************************************/

MyTblFmncMOrg::MyTblFmncMOrg() : TblFmncMOrg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMOrg::~MyTblFmncMOrg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMOrg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMOrg (ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMOrg SET ixWDerivate = ?, refFmncMAddress = ?, supRefFmncMOrg = ?, supLvl = ?, sref = ?, refJTitle = ?, Title = ?, telRefADetail = ?, Tel = ?, emlRefADetail = ?, Eml = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMOrg WHERE ref = ?", false);
};

bool MyTblFmncMOrg::loadRecBySQL(
			const string& sqlstr
			, FmncMOrg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMOrg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMOrg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMOrg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixWDerivate = atol((char*) dbrow[1]); else _rec->ixWDerivate = 0;
		if (dbrow[2]) _rec->refFmncMAddress = atoll((char*) dbrow[2]); else _rec->refFmncMAddress = 0;
		if (dbrow[3]) _rec->supRefFmncMOrg = atoll((char*) dbrow[3]); else _rec->supRefFmncMOrg = 0;
		if (dbrow[4]) _rec->supLvl = atoi((char*) dbrow[4]); else _rec->supLvl = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->refJTitle = atoll((char*) dbrow[6]); else _rec->refJTitle = 0;
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->telRefADetail = atoll((char*) dbrow[8]); else _rec->telRefADetail = 0;
		if (dbrow[9]) _rec->Tel.assign(dbrow[9], dblengths[9]); else _rec->Tel = "";
		if (dbrow[10]) _rec->emlRefADetail = atoll((char*) dbrow[10]); else _rec->emlRefADetail = 0;
		if (dbrow[11]) _rec->Eml.assign(dbrow[11], dblengths[11]); else _rec->Eml = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMOrg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMOrg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMOrg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMOrg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixWDerivate = atol((char*) dbrow[1]); else rec->ixWDerivate = 0;
			if (dbrow[2]) rec->refFmncMAddress = atoll((char*) dbrow[2]); else rec->refFmncMAddress = 0;
			if (dbrow[3]) rec->supRefFmncMOrg = atoll((char*) dbrow[3]); else rec->supRefFmncMOrg = 0;
			if (dbrow[4]) rec->supLvl = atoi((char*) dbrow[4]); else rec->supLvl = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->refJTitle = atoll((char*) dbrow[6]); else rec->refJTitle = 0;
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->telRefADetail = atoll((char*) dbrow[8]); else rec->telRefADetail = 0;
			if (dbrow[9]) rec->Tel.assign(dbrow[9], dblengths[9]); else rec->Tel = "";
			if (dbrow[10]) rec->emlRefADetail = atoll((char*) dbrow[10]); else rec->emlRefADetail = 0;
			if (dbrow[11]) rec->Eml.assign(dbrow[11], dblengths[11]); else rec->Eml = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMOrg::insertRec(
			FmncMOrg* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	l[6] = rec->Title.length();
	l[8] = rec->Tel.length();
	l[10] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWDerivate,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMAddress,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->supRefFmncMOrg,&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->supLvl,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJTitle,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->telRefADetail,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Tel.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->emlRefADetail,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Eml.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMOrg / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMOrg / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMOrg::insertRst(
			ListFmncMOrg& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMOrg::updateRec(
			FmncMOrg* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[4] = rec->sref.length();
	l[6] = rec->Title.length();
	l[8] = rec->Tel.length();
	l[10] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWDerivate,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMAddress,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->supRefFmncMOrg,&(l[2]),&(n[2]),&(e[2])), 
		bindUsmallint(&rec->supLvl,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refJTitle,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->telRefADetail,&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Tel.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->emlRefADetail,&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Eml.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMOrg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMOrg / stmtUpdateRec)\n");
};

void MyTblFmncMOrg::updateRst(
			ListFmncMOrg& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMOrg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMOrg / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMOrg / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMOrg::loadRecByRef(
			ubigint ref
			, FmncMOrg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMOrg WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMOrg::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadUbigintBySQL("SELECT ref FROM TblFmncMOrg WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblFmncMOrg::loadRefBySupSrf(
			ubigint supRefFmncMOrg
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMOrg WHERE supRefFmncMOrg = " + to_string(supRefFmncMOrg) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblFmncMOrg::loadRefsBySup(
			ubigint supRefFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMOrg WHERE supRefFmncMOrg = " + to_string(supRefFmncMOrg) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblFmncMOrg::loadRstBySup(
			ubigint supRefFmncMOrg
			, const bool append
			, ListFmncMOrg& rst
		) {
	return loadRstBySQL("SELECT ref, ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml FROM TblFmncMOrg WHERE supRefFmncMOrg = " + to_string(supRefFmncMOrg) + " ORDER BY sref ASC", append, rst);
};

bool MyTblFmncMOrg::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblFmncMOrg WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblFmncMOrg::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT supRefFmncMOrg FROM TblFmncMOrg WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblFmncMOrg::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncMOrg WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMOrg
 ******************************************************************************/

PgTblFmncMOrg::PgTblFmncMOrg() : TblFmncMOrg(), PgTable() {
};

PgTblFmncMOrg::~PgTblFmncMOrg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMOrg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMOrg_insertRec", "INSERT INTO TblFmncMOrg (ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_updateRec", "UPDATE TblFmncMOrg SET ixWDerivate = $1, refFmncMAddress = $2, supRefFmncMOrg = $3, supLvl = $4, sref = $5, refJTitle = $6, Title = $7, telRefADetail = $8, Tel = $9, emlRefADetail = $10, Eml = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_removeRecByRef", "DELETE FROM TblFmncMOrg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMOrg_loadRecByRef", "SELECT ref, ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml FROM TblFmncMOrg WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMOrg_confirmByRef", "SELECT ref FROM TblFmncMOrg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_loadRefBySupSrf", "SELECT ref FROM TblFmncMOrg WHERE supRefFmncMOrg = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_loadRefsBySup", "SELECT ref FROM TblFmncMOrg WHERE supRefFmncMOrg = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_loadRstBySup", "SELECT ref, ixWDerivate, refFmncMAddress, supRefFmncMOrg, supLvl, sref, refJTitle, Title, telRefADetail, Tel, emlRefADetail, Eml FROM TblFmncMOrg WHERE supRefFmncMOrg = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_loadSrfByRef", "SELECT sref FROM TblFmncMOrg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_loadSupByRef", "SELECT supRefFmncMOrg FROM TblFmncMOrg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMOrg_loadTitByRef", "SELECT Title FROM TblFmncMOrg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMOrg::loadRec(
			PGresult* res
			, FmncMOrg** rec
		) {
	char* ptr;

	FmncMOrg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMOrg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "supreffmncmorg"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "eml")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixWDerivate = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMAddress = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->telRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Tel.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->emlRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Eml.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMOrg::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMOrg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMOrg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "supreffmncmorg"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "eml")
		};

		while (numread < numrow) {
			rec = new FmncMOrg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixWDerivate = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMAddress = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->telRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Tel.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->emlRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Eml.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMOrg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMOrg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMOrg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncMOrg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncMOrg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMOrg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncMOrg::loadRecBySQL(
			const string& sqlstr
			, FmncMOrg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMOrg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMOrg::insertRec(
			FmncMOrg* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixWDerivate = htonl(rec->ixWDerivate);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	ubigint _supRefFmncMOrg = htonl64(rec->supRefFmncMOrg);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);

	const char* vals[] = {
		(char*) &_ixWDerivate,
		(char*) &_refFmncMAddress,
		(char*) &_supRefFmncMOrg,
		(char*) &_supLvl,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_telRefADetail,
		rec->Tel.c_str(),
		(char*) &_emlRefADetail,
		rec->Eml.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMOrg_insertRec", 11, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMOrg_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMOrg::insertRst(
			ListFmncMOrg& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMOrg::updateRec(
			FmncMOrg* rec
		) {
	PGresult* res;

	uint _ixWDerivate = htonl(rec->ixWDerivate);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	ubigint _supRefFmncMOrg = htonl64(rec->supRefFmncMOrg);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixWDerivate,
		(char*) &_refFmncMAddress,
		(char*) &_supRefFmncMOrg,
		(char*) &_supLvl,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_telRefADetail,
		rec->Tel.c_str(),
		(char*) &_emlRefADetail,
		rec->Eml.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMOrg_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMOrg_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMOrg::updateRst(
			ListFmncMOrg& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMOrg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMOrg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMOrg_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMOrg::loadRecByRef(
			ubigint ref
			, FmncMOrg** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMOrg_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMOrg::confirmByRef(
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

	return loadUbigintByStmt("TblFmncMOrg_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblFmncMOrg::loadRefBySupSrf(
			ubigint supRefFmncMOrg
			, string sref
			, ubigint& ref
		) {
	ubigint _supRefFmncMOrg = htonl64(supRefFmncMOrg);

	const char* vals[] = {
		(char*) &_supRefFmncMOrg,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblFmncMOrg_loadRefBySupSrf", 2, vals, l, f, ref);
};

ubigint PgTblFmncMOrg::loadRefsBySup(
			ubigint supRefFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefFmncMOrg = htonl64(supRefFmncMOrg);

	const char* vals[] = {
		(char*) &_supRefFmncMOrg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMOrg_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncMOrg::loadRstBySup(
			ubigint supRefFmncMOrg
			, const bool append
			, ListFmncMOrg& rst
		) {
	ubigint _supRefFmncMOrg = htonl64(supRefFmncMOrg);

	const char* vals[] = {
		(char*) &_supRefFmncMOrg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncMOrg_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblFmncMOrg::loadSrfByRef(
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

	return loadStringByStmt("TblFmncMOrg_loadSrfByRef", 1, vals, l, f, val);
};

bool PgTblFmncMOrg::loadSupByRef(
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

	return loadUbigintByStmt("TblFmncMOrg_loadSupByRef", 1, vals, l, f, val);
};

bool PgTblFmncMOrg::loadTitByRef(
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

	return loadStringByStmt("TblFmncMOrg_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

