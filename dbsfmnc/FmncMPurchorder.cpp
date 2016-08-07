/**
  * \file FmncMPurchorder.cpp
  * database access for table TblFmncMPurchorder (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMPurchorder.h"

/******************************************************************************
 class FmncMPurchorder
 ******************************************************************************/

FmncMPurchorder::FmncMPurchorder(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint pcoRefFmncMOrg
			, const ubigint splRefFmncMOrg
			, const ubigint refFmncMFile
			, const string sref
			, const uint Date
			, const ubigint refJState
			, const uint ixVState
			, const double Amount
			, const ubigint pcpRefFmncMPerson
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->pcoRefFmncMOrg = pcoRefFmncMOrg;
	this->splRefFmncMOrg = splRefFmncMOrg;
	this->refFmncMFile = refFmncMFile;
	this->sref = sref;
	this->Date = Date;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Amount = Amount;
	this->pcpRefFmncMPerson = pcpRefFmncMPerson;
	this->Comment = Comment;
};

bool FmncMPurchorder::operator==(
			const FmncMPurchorder& comp
		) {
	return false;
};

bool FmncMPurchorder::operator!=(
			const FmncMPurchorder& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMPurchorder
 ******************************************************************************/

ListFmncMPurchorder::ListFmncMPurchorder() {
};

ListFmncMPurchorder::ListFmncMPurchorder(
			const ListFmncMPurchorder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMPurchorder(*(src.nodes[i]));
};

ListFmncMPurchorder::~ListFmncMPurchorder() {
	clear();
};

void ListFmncMPurchorder::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMPurchorder::size() const {
	return(nodes.size());
};

void ListFmncMPurchorder::append(
			FmncMPurchorder* rec
		) {
	nodes.push_back(rec);
};

FmncMPurchorder* ListFmncMPurchorder::operator[](
			const uint ix
		) {
	FmncMPurchorder* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMPurchorder& ListFmncMPurchorder::operator=(
			const ListFmncMPurchorder& src
		) {
	FmncMPurchorder* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMPurchorder(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMPurchorder::operator==(
			const ListFmncMPurchorder& comp
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

bool ListFmncMPurchorder::operator!=(
			const ListFmncMPurchorder& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMPurchorder
 ******************************************************************************/

TblFmncMPurchorder::TblFmncMPurchorder() {
};

TblFmncMPurchorder::~TblFmncMPurchorder() {
};

bool TblFmncMPurchorder::loadRecBySQL(
			const string& sqlstr
			, FmncMPurchorder** rec
		) {
	return false;
};

ubigint TblFmncMPurchorder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMPurchorder& rst
		) {
	return 0;
};

void TblFmncMPurchorder::insertRec(
			FmncMPurchorder* rec
		) {
};

ubigint TblFmncMPurchorder::insertNewRec(
			FmncMPurchorder** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint pcoRefFmncMOrg
			, const ubigint splRefFmncMOrg
			, const ubigint refFmncMFile
			, const string sref
			, const uint Date
			, const ubigint refJState
			, const uint ixVState
			, const double Amount
			, const ubigint pcpRefFmncMPerson
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMPurchorder* _rec = NULL;

	_rec = new FmncMPurchorder(0, grp, own, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, sref, Date, refJState, ixVState, Amount, pcpRefFmncMPerson, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMPurchorder::appendNewRecToRst(
			ListFmncMPurchorder& rst
			, FmncMPurchorder** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint pcoRefFmncMOrg
			, const ubigint splRefFmncMOrg
			, const ubigint refFmncMFile
			, const string sref
			, const uint Date
			, const ubigint refJState
			, const uint ixVState
			, const double Amount
			, const ubigint pcpRefFmncMPerson
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMPurchorder* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, sref, Date, refJState, ixVState, Amount, pcpRefFmncMPerson, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMPurchorder::insertRst(
			ListFmncMPurchorder& rst
			, bool transact
		) {
};

void TblFmncMPurchorder::updateRec(
			FmncMPurchorder* rec
		) {
};

void TblFmncMPurchorder::updateRst(
			ListFmncMPurchorder& rst
			, bool transact
		) {
};

void TblFmncMPurchorder::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMPurchorder::loadRecByRef(
			ubigint ref
			, FmncMPurchorder** rec
		) {
	return false;
};

ubigint TblFmncMPurchorder::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMPurchorder& rst
		) {
	ubigint numload = 0;
	FmncMPurchorder* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMPurchorder
 ******************************************************************************/

MyTblFmncMPurchorder::MyTblFmncMPurchorder() : TblFmncMPurchorder(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMPurchorder::~MyTblFmncMPurchorder() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMPurchorder::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMPurchorder (grp, own, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, sref, Date, refJState, ixVState, Amount, pcpRefFmncMPerson, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMPurchorder SET grp = ?, own = ?, pcoRefFmncMOrg = ?, splRefFmncMOrg = ?, refFmncMFile = ?, sref = ?, Date = ?, refJState = ?, ixVState = ?, Amount = ?, pcpRefFmncMPerson = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMPurchorder WHERE ref = ?", false);
};

bool MyTblFmncMPurchorder::loadRecBySQL(
			const string& sqlstr
			, FmncMPurchorder** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMPurchorder* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMPurchorder / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMPurchorder();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->pcoRefFmncMOrg = atoll((char*) dbrow[3]); else _rec->pcoRefFmncMOrg = 0;
		if (dbrow[4]) _rec->splRefFmncMOrg = atoll((char*) dbrow[4]); else _rec->splRefFmncMOrg = 0;
		if (dbrow[5]) _rec->refFmncMFile = atoll((char*) dbrow[5]); else _rec->refFmncMFile = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Date = atol((char*) dbrow[7]); else _rec->Date = 0;
		if (dbrow[8]) _rec->refJState = atoll((char*) dbrow[8]); else _rec->refJState = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->Amount = atof((char*) dbrow[10]); else _rec->Amount = 0.0;
		if (dbrow[11]) _rec->pcpRefFmncMPerson = atoll((char*) dbrow[11]); else _rec->pcpRefFmncMPerson = 0;
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMPurchorder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMPurchorder& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMPurchorder* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMPurchorder / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMPurchorder();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->pcoRefFmncMOrg = atoll((char*) dbrow[3]); else rec->pcoRefFmncMOrg = 0;
			if (dbrow[4]) rec->splRefFmncMOrg = atoll((char*) dbrow[4]); else rec->splRefFmncMOrg = 0;
			if (dbrow[5]) rec->refFmncMFile = atoll((char*) dbrow[5]); else rec->refFmncMFile = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Date = atol((char*) dbrow[7]); else rec->Date = 0;
			if (dbrow[8]) rec->refJState = atoll((char*) dbrow[8]); else rec->refJState = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->Amount = atof((char*) dbrow[10]); else rec->Amount = 0.0;
			if (dbrow[11]) rec->pcpRefFmncMPerson = atoll((char*) dbrow[11]); else rec->pcpRefFmncMPerson = 0;
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMPurchorder::insertRec(
			FmncMPurchorder* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->sref.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->pcoRefFmncMOrg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->splRefFmncMOrg,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMFile,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Date,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refJState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->Amount,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->pcpRefFmncMPerson,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMPurchorder / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMPurchorder / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMPurchorder::insertRst(
			ListFmncMPurchorder& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMPurchorder::updateRec(
			FmncMPurchorder* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->sref.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->pcoRefFmncMOrg,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->splRefFmncMOrg,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMFile,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->Date,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->refJState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])), 
		bindDouble(&rec->Amount,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->pcpRefFmncMPerson,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMPurchorder / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMPurchorder / stmtUpdateRec)\n");
};

void MyTblFmncMPurchorder::updateRst(
			ListFmncMPurchorder& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMPurchorder::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMPurchorder / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMPurchorder / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMPurchorder::loadRecByRef(
			ubigint ref
			, FmncMPurchorder** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMPurchorder WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMPurchorder
 ******************************************************************************/

PgTblFmncMPurchorder::PgTblFmncMPurchorder() : TblFmncMPurchorder(), PgTable() {
};

PgTblFmncMPurchorder::~PgTblFmncMPurchorder() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMPurchorder::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMPurchorder_insertRec", "INSERT INTO TblFmncMPurchorder (grp, own, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, sref, Date, refJState, ixVState, Amount, pcpRefFmncMPerson, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMPurchorder_updateRec", "UPDATE TblFmncMPurchorder SET grp = $1, own = $2, pcoRefFmncMOrg = $3, splRefFmncMOrg = $4, refFmncMFile = $5, sref = $6, Date = $7, refJState = $8, ixVState = $9, Amount = $10, pcpRefFmncMPerson = $11, Comment = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMPurchorder_removeRecByRef", "DELETE FROM TblFmncMPurchorder WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMPurchorder_loadRecByRef", "SELECT ref, grp, own, pcoRefFmncMOrg, splRefFmncMOrg, refFmncMFile, sref, Date, refJState, ixVState, Amount, pcpRefFmncMPerson, Comment FROM TblFmncMPurchorder WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMPurchorder::loadRec(
			PGresult* res
			, FmncMPurchorder** rec
		) {
	char* ptr;

	FmncMPurchorder* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMPurchorder();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "pcoreffmncmorg"),
			PQfnumber(res, "splreffmncmorg"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "amount"),
			PQfnumber(res, "pcpreffmncmperson"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->pcoRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->splRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Date = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Amount = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->pcpRefFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMPurchorder::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMPurchorder& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMPurchorder* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "pcoreffmncmorg"),
			PQfnumber(res, "splreffmncmorg"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "amount"),
			PQfnumber(res, "pcpreffmncmperson"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMPurchorder();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->pcoRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->splRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Date = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Amount = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->pcpRefFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMPurchorder::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMPurchorder** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPurchorder / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMPurchorder::loadRecBySQL(
			const string& sqlstr
			, FmncMPurchorder** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMPurchorder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMPurchorder& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMPurchorder::insertRec(
			FmncMPurchorder* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _pcoRefFmncMOrg = htonl64(rec->pcoRefFmncMOrg);
	ubigint _splRefFmncMOrg = htonl64(rec->splRefFmncMOrg);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _Date = htonl(rec->Date);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	string _Amount = to_string(rec->Amount);
	ubigint _pcpRefFmncMPerson = htonl64(rec->pcpRefFmncMPerson);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_pcoRefFmncMOrg,
		(char*) &_splRefFmncMOrg,
		(char*) &_refFmncMFile,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_refJState,
		(char*) &_ixVState,
		_Amount.c_str(),
		(char*) &_pcpRefFmncMPerson,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMPurchorder_insertRec", 12, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPurchorder_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMPurchorder::insertRst(
			ListFmncMPurchorder& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMPurchorder::updateRec(
			FmncMPurchorder* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _pcoRefFmncMOrg = htonl64(rec->pcoRefFmncMOrg);
	ubigint _splRefFmncMOrg = htonl64(rec->splRefFmncMOrg);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _Date = htonl(rec->Date);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	string _Amount = to_string(rec->Amount);
	ubigint _pcpRefFmncMPerson = htonl64(rec->pcpRefFmncMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_pcoRefFmncMOrg,
		(char*) &_splRefFmncMOrg,
		(char*) &_refFmncMFile,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_refJState,
		(char*) &_ixVState,
		_Amount.c_str(),
		(char*) &_pcpRefFmncMPerson,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMPurchorder_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPurchorder_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMPurchorder::updateRst(
			ListFmncMPurchorder& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMPurchorder::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMPurchorder_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPurchorder_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMPurchorder::loadRecByRef(
			ubigint ref
			, FmncMPurchorder** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMPurchorder_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

