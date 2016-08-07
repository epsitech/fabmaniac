/**
  * \file FmncMBill.cpp
  * database access for table TblFmncMBill (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMBill.h"

/******************************************************************************
 class FmncMBill
 ******************************************************************************/

FmncMBill::FmncMBill(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFabproject
			, const ubigint refFmncMFile
			, const string sref
			, const uint Date
			, const ubigint refJState
			, const uint ixVState
			, const uint Prdstart
			, const uint Prdstop
			, const double Amount
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMFabproject = refFmncMFabproject;
	this->refFmncMFile = refFmncMFile;
	this->sref = sref;
	this->Date = Date;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Prdstart = Prdstart;
	this->Prdstop = Prdstop;
	this->Amount = Amount;
	this->Comment = Comment;
};

bool FmncMBill::operator==(
			const FmncMBill& comp
		) {
	return false;
};

bool FmncMBill::operator!=(
			const FmncMBill& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMBill
 ******************************************************************************/

ListFmncMBill::ListFmncMBill() {
};

ListFmncMBill::ListFmncMBill(
			const ListFmncMBill& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMBill(*(src.nodes[i]));
};

ListFmncMBill::~ListFmncMBill() {
	clear();
};

void ListFmncMBill::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMBill::size() const {
	return(nodes.size());
};

void ListFmncMBill::append(
			FmncMBill* rec
		) {
	nodes.push_back(rec);
};

FmncMBill* ListFmncMBill::operator[](
			const uint ix
		) {
	FmncMBill* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMBill& ListFmncMBill::operator=(
			const ListFmncMBill& src
		) {
	FmncMBill* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMBill(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMBill::operator==(
			const ListFmncMBill& comp
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

bool ListFmncMBill::operator!=(
			const ListFmncMBill& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMBill
 ******************************************************************************/

TblFmncMBill::TblFmncMBill() {
};

TblFmncMBill::~TblFmncMBill() {
};

bool TblFmncMBill::loadRecBySQL(
			const string& sqlstr
			, FmncMBill** rec
		) {
	return false;
};

ubigint TblFmncMBill::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMBill& rst
		) {
	return 0;
};

void TblFmncMBill::insertRec(
			FmncMBill* rec
		) {
};

ubigint TblFmncMBill::insertNewRec(
			FmncMBill** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFabproject
			, const ubigint refFmncMFile
			, const string sref
			, const uint Date
			, const ubigint refJState
			, const uint ixVState
			, const uint Prdstart
			, const uint Prdstop
			, const double Amount
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMBill* _rec = NULL;

	_rec = new FmncMBill(0, grp, own, refFmncMFabproject, refFmncMFile, sref, Date, refJState, ixVState, Prdstart, Prdstop, Amount, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMBill::appendNewRecToRst(
			ListFmncMBill& rst
			, FmncMBill** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFabproject
			, const ubigint refFmncMFile
			, const string sref
			, const uint Date
			, const ubigint refJState
			, const uint ixVState
			, const uint Prdstart
			, const uint Prdstop
			, const double Amount
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMBill* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMFabproject, refFmncMFile, sref, Date, refJState, ixVState, Prdstart, Prdstop, Amount, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMBill::insertRst(
			ListFmncMBill& rst
			, bool transact
		) {
};

void TblFmncMBill::updateRec(
			FmncMBill* rec
		) {
};

void TblFmncMBill::updateRst(
			ListFmncMBill& rst
			, bool transact
		) {
};

void TblFmncMBill::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMBill::loadRecByRef(
			ubigint ref
			, FmncMBill** rec
		) {
	return false;
};

ubigint TblFmncMBill::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMBill& rst
		) {
	ubigint numload = 0;
	FmncMBill* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMBill
 ******************************************************************************/

MyTblFmncMBill::MyTblFmncMBill() : TblFmncMBill(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMBill::~MyTblFmncMBill() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMBill::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMBill (grp, own, refFmncMFabproject, refFmncMFile, sref, Date, refJState, ixVState, Prdstart, Prdstop, Amount, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMBill SET grp = ?, own = ?, refFmncMFabproject = ?, refFmncMFile = ?, sref = ?, Date = ?, refJState = ?, ixVState = ?, Prdstart = ?, Prdstop = ?, Amount = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMBill WHERE ref = ?", false);
};

bool MyTblFmncMBill::loadRecBySQL(
			const string& sqlstr
			, FmncMBill** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMBill* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMBill / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMBill();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMFabproject = atoll((char*) dbrow[3]); else _rec->refFmncMFabproject = 0;
		if (dbrow[4]) _rec->refFmncMFile = atoll((char*) dbrow[4]); else _rec->refFmncMFile = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Date = atol((char*) dbrow[6]); else _rec->Date = 0;
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->Prdstart = atol((char*) dbrow[9]); else _rec->Prdstart = 0;
		if (dbrow[10]) _rec->Prdstop = atol((char*) dbrow[10]); else _rec->Prdstop = 0;
		if (dbrow[11]) _rec->Amount = atof((char*) dbrow[11]); else _rec->Amount = 0.0;
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMBill::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMBill& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMBill* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMBill / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMBill();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMFabproject = atoll((char*) dbrow[3]); else rec->refFmncMFabproject = 0;
			if (dbrow[4]) rec->refFmncMFile = atoll((char*) dbrow[4]); else rec->refFmncMFile = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Date = atol((char*) dbrow[6]); else rec->Date = 0;
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->Prdstart = atol((char*) dbrow[9]); else rec->Prdstart = 0;
			if (dbrow[10]) rec->Prdstop = atol((char*) dbrow[10]); else rec->Prdstop = 0;
			if (dbrow[11]) rec->Amount = atof((char*) dbrow[11]); else rec->Amount = 0.0;
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMBill::insertRec(
			FmncMBill* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[4] = rec->sref.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMFabproject,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMFile,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->Date,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->Prdstart,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->Prdstop,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->Amount,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMBill / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMBill / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMBill::insertRst(
			ListFmncMBill& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMBill::updateRec(
			FmncMBill* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[4] = rec->sref.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMFabproject,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMFile,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->Date,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->Prdstart,&(l[8]),&(n[8]),&(e[8])), 
		bindUint(&rec->Prdstop,&(l[9]),&(n[9]),&(e[9])), 
		bindDouble(&rec->Amount,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMBill / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMBill / stmtUpdateRec)\n");
};

void MyTblFmncMBill::updateRst(
			ListFmncMBill& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMBill::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMBill / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMBill / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMBill::loadRecByRef(
			ubigint ref
			, FmncMBill** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMBill WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMBill
 ******************************************************************************/

PgTblFmncMBill::PgTblFmncMBill() : TblFmncMBill(), PgTable() {
};

PgTblFmncMBill::~PgTblFmncMBill() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMBill::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMBill_insertRec", "INSERT INTO TblFmncMBill (grp, own, refFmncMFabproject, refFmncMFile, sref, Date, refJState, ixVState, Prdstart, Prdstop, Amount, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMBill_updateRec", "UPDATE TblFmncMBill SET grp = $1, own = $2, refFmncMFabproject = $3, refFmncMFile = $4, sref = $5, Date = $6, refJState = $7, ixVState = $8, Prdstart = $9, Prdstop = $10, Amount = $11, Comment = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMBill_removeRecByRef", "DELETE FROM TblFmncMBill WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMBill_loadRecByRef", "SELECT ref, grp, own, refFmncMFabproject, refFmncMFile, sref, Date, refJState, ixVState, Prdstart, Prdstop, Amount, Comment FROM TblFmncMBill WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMBill::loadRec(
			PGresult* res
			, FmncMBill** rec
		) {
	char* ptr;

	FmncMBill* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMBill();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "prdstart"),
			PQfnumber(res, "prdstop"),
			PQfnumber(res, "amount"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Date = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Prdstart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Prdstop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Amount = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMBill::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMBill& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMBill* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "date"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "prdstart"),
			PQfnumber(res, "prdstop"),
			PQfnumber(res, "amount"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMBill();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Date = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Prdstart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Prdstop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Amount = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMBill::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMBill** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMBill / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMBill::loadRecBySQL(
			const string& sqlstr
			, FmncMBill** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMBill::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMBill& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMBill::insertRec(
			FmncMBill* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _Date = htonl(rec->Date);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _Prdstart = htonl(rec->Prdstart);
	uint _Prdstop = htonl(rec->Prdstop);
	string _Amount = to_string(rec->Amount);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMFabproject,
		(char*) &_refFmncMFile,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_Prdstart,
		(char*) &_Prdstop,
		_Amount.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMBill_insertRec", 12, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMBill_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMBill::insertRst(
			ListFmncMBill& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMBill::updateRec(
			FmncMBill* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	uint _Date = htonl(rec->Date);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _Prdstart = htonl(rec->Prdstart);
	uint _Prdstop = htonl(rec->Prdstop);
	string _Amount = to_string(rec->Amount);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMFabproject,
		(char*) &_refFmncMFile,
		rec->sref.c_str(),
		(char*) &_Date,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_Prdstart,
		(char*) &_Prdstop,
		_Amount.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMBill_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMBill_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMBill::updateRst(
			ListFmncMBill& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMBill::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMBill_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMBill_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMBill::loadRecByRef(
			ubigint ref
			, FmncMBill** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMBill_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

