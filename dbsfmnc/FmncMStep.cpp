/**
  * \file FmncMStep.cpp
  * database access for table TblFmncMStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMStep.h"

/******************************************************************************
 class FmncMStep
 ******************************************************************************/

FmncMStep::FmncMStep(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMActivity
			, const uint rlvIxVTbl
			, const ubigint rlvUref
			, const ubigint tplRefFmncMStep
			, const uint ixWFilecfg
			, const string Title
			, const uint start
			, const ubigint refFmncMPerson
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMActivity = refFmncMActivity;
	this->rlvIxVTbl = rlvIxVTbl;
	this->rlvUref = rlvUref;
	this->tplRefFmncMStep = tplRefFmncMStep;
	this->ixWFilecfg = ixWFilecfg;
	this->Title = Title;
	this->start = start;
	this->refFmncMPerson = refFmncMPerson;
};

bool FmncMStep::operator==(
			const FmncMStep& comp
		) {
	return false;
};

bool FmncMStep::operator!=(
			const FmncMStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMStep
 ******************************************************************************/

ListFmncMStep::ListFmncMStep() {
};

ListFmncMStep::ListFmncMStep(
			const ListFmncMStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMStep(*(src.nodes[i]));
};

ListFmncMStep::~ListFmncMStep() {
	clear();
};

void ListFmncMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMStep::size() const {
	return(nodes.size());
};

void ListFmncMStep::append(
			FmncMStep* rec
		) {
	nodes.push_back(rec);
};

FmncMStep* ListFmncMStep::operator[](
			const uint ix
		) {
	FmncMStep* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMStep& ListFmncMStep::operator=(
			const ListFmncMStep& src
		) {
	FmncMStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMStep::operator==(
			const ListFmncMStep& comp
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

bool ListFmncMStep::operator!=(
			const ListFmncMStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMStep
 ******************************************************************************/

TblFmncMStep::TblFmncMStep() {
};

TblFmncMStep::~TblFmncMStep() {
};

bool TblFmncMStep::loadRecBySQL(
			const string& sqlstr
			, FmncMStep** rec
		) {
	return false;
};

ubigint TblFmncMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMStep& rst
		) {
	return 0;
};

void TblFmncMStep::insertRec(
			FmncMStep* rec
		) {
};

ubigint TblFmncMStep::insertNewRec(
			FmncMStep** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMActivity
			, const uint rlvIxVTbl
			, const ubigint rlvUref
			, const ubigint tplRefFmncMStep
			, const uint ixWFilecfg
			, const string Title
			, const uint start
			, const ubigint refFmncMPerson
		) {
	ubigint retval = 0;
	FmncMStep* _rec = NULL;

	_rec = new FmncMStep(0, grp, own, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, ixWFilecfg, Title, start, refFmncMPerson);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMStep::appendNewRecToRst(
			ListFmncMStep& rst
			, FmncMStep** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMActivity
			, const uint rlvIxVTbl
			, const ubigint rlvUref
			, const ubigint tplRefFmncMStep
			, const uint ixWFilecfg
			, const string Title
			, const uint start
			, const ubigint refFmncMPerson
		) {
	ubigint retval = 0;
	FmncMStep* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, ixWFilecfg, Title, start, refFmncMPerson);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMStep::insertRst(
			ListFmncMStep& rst
			, bool transact
		) {
};

void TblFmncMStep::updateRec(
			FmncMStep* rec
		) {
};

void TblFmncMStep::updateRst(
			ListFmncMStep& rst
			, bool transact
		) {
};

void TblFmncMStep::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMStep::loadRecByRef(
			ubigint ref
			, FmncMStep** rec
		) {
	return false;
};

ubigint TblFmncMStep::loadRefsByAct(
			ubigint refFmncMActivity
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMStep::loadRefsByRltRlu(
			uint rlvIxVTbl
			, ubigint rlvUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblFmncMStep::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMStep::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMStep& rst
		) {
	ubigint numload = 0;
	FmncMStep* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMStep
 ******************************************************************************/

MyTblFmncMStep::MyTblFmncMStep() : TblFmncMStep(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMStep::~MyTblFmncMStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMStep (grp, own, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, ixWFilecfg, Title, start, refFmncMPerson) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMStep SET grp = ?, own = ?, refFmncMActivity = ?, rlvIxVTbl = ?, rlvUref = ?, tplRefFmncMStep = ?, ixWFilecfg = ?, Title = ?, start = ?, refFmncMPerson = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMStep WHERE ref = ?", false);
};

bool MyTblFmncMStep::loadRecBySQL(
			const string& sqlstr
			, FmncMStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMStep / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMStep();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMActivity = atoll((char*) dbrow[3]); else _rec->refFmncMActivity = 0;
		if (dbrow[4]) _rec->rlvIxVTbl = atol((char*) dbrow[4]); else _rec->rlvIxVTbl = 0;
		if (dbrow[5]) _rec->rlvUref = atoll((char*) dbrow[5]); else _rec->rlvUref = 0;
		if (dbrow[6]) _rec->tplRefFmncMStep = atoll((char*) dbrow[6]); else _rec->tplRefFmncMStep = 0;
		if (dbrow[7]) _rec->ixWFilecfg = atol((char*) dbrow[7]); else _rec->ixWFilecfg = 0;
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";
		if (dbrow[9]) _rec->start = atol((char*) dbrow[9]); else _rec->start = 0;
		if (dbrow[10]) _rec->refFmncMPerson = atoll((char*) dbrow[10]); else _rec->refFmncMPerson = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMStep / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMStep();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMActivity = atoll((char*) dbrow[3]); else rec->refFmncMActivity = 0;
			if (dbrow[4]) rec->rlvIxVTbl = atol((char*) dbrow[4]); else rec->rlvIxVTbl = 0;
			if (dbrow[5]) rec->rlvUref = atoll((char*) dbrow[5]); else rec->rlvUref = 0;
			if (dbrow[6]) rec->tplRefFmncMStep = atoll((char*) dbrow[6]); else rec->tplRefFmncMStep = 0;
			if (dbrow[7]) rec->ixWFilecfg = atol((char*) dbrow[7]); else rec->ixWFilecfg = 0;
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			if (dbrow[9]) rec->start = atol((char*) dbrow[9]); else rec->start = 0;
			if (dbrow[10]) rec->refFmncMPerson = atoll((char*) dbrow[10]); else rec->refFmncMPerson = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMStep::insertRec(
			FmncMStep* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[7] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMActivity,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->rlvIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->rlvUref,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->tplRefFmncMStep,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixWFilecfg,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->start,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refFmncMPerson,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMStep / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMStep / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMStep::insertRst(
			ListFmncMStep& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMStep::updateRec(
			FmncMStep* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[7] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMActivity,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->rlvIxVTbl,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->rlvUref,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->tplRefFmncMStep,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixWFilecfg,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->start,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->refFmncMPerson,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMStep / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMStep / stmtUpdateRec)\n");
};

void MyTblFmncMStep::updateRst(
			ListFmncMStep& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMStep::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMStep / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMStep / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMStep::loadRecByRef(
			ubigint ref
			, FmncMStep** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMStep WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMStep::loadRefsByAct(
			ubigint refFmncMActivity
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMStep WHERE refFmncMActivity = " + to_string(refFmncMActivity) + "", append, refs);
};

ubigint MyTblFmncMStep::loadRefsByRltRlu(
			uint rlvIxVTbl
			, ubigint rlvUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMStep WHERE rlvIxVTbl = " + to_string(rlvIxVTbl) + " AND rlvUref = " + to_string(rlvUref) + "", append, refs);
};

bool MyTblFmncMStep::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncMStep WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMStep
 ******************************************************************************/

PgTblFmncMStep::PgTblFmncMStep() : TblFmncMStep(), PgTable() {
};

PgTblFmncMStep::~PgTblFmncMStep() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMStep::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMStep_insertRec", "INSERT INTO TblFmncMStep (grp, own, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, ixWFilecfg, Title, start, refFmncMPerson) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMStep_updateRec", "UPDATE TblFmncMStep SET grp = $1, own = $2, refFmncMActivity = $3, rlvIxVTbl = $4, rlvUref = $5, tplRefFmncMStep = $6, ixWFilecfg = $7, Title = $8, start = $9, refFmncMPerson = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMStep_removeRecByRef", "DELETE FROM TblFmncMStep WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMStep_loadRecByRef", "SELECT ref, grp, own, refFmncMActivity, rlvIxVTbl, rlvUref, tplRefFmncMStep, ixWFilecfg, Title, start, refFmncMPerson FROM TblFmncMStep WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMStep_loadRefsByAct", "SELECT ref FROM TblFmncMStep WHERE refFmncMActivity = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMStep_loadRefsByRltRlu", "SELECT ref FROM TblFmncMStep WHERE rlvIxVTbl = $1 AND rlvUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMStep_loadTitByRef", "SELECT Title FROM TblFmncMStep WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMStep::loadRec(
			PGresult* res
			, FmncMStep** rec
		) {
	char* ptr;

	FmncMStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMStep();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmactivity"),
			PQfnumber(res, "rlvixvtbl"),
			PQfnumber(res, "rlvuref"),
			PQfnumber(res, "tplreffmncmstep"),
			PQfnumber(res, "ixwfilecfg"),
			PQfnumber(res, "title"),
			PQfnumber(res, "start"),
			PQfnumber(res, "reffmncmperson")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMActivity = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->rlvIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->rlvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->tplRefFmncMStep = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixWFilecfg = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refFmncMPerson = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMStep::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmactivity"),
			PQfnumber(res, "rlvixvtbl"),
			PQfnumber(res, "rlvuref"),
			PQfnumber(res, "tplreffmncmstep"),
			PQfnumber(res, "ixwfilecfg"),
			PQfnumber(res, "title"),
			PQfnumber(res, "start"),
			PQfnumber(res, "reffmncmperson")
		};

		while (numread < numrow) {
			rec = new FmncMStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMActivity = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->rlvIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->rlvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->tplRefFmncMStep = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixWFilecfg = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refFmncMPerson = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStep / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMStep::loadRecBySQL(
			const string& sqlstr
			, FmncMStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMStep::insertRec(
			FmncMStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMActivity = htonl64(rec->refFmncMActivity);
	uint _rlvIxVTbl = htonl(rec->rlvIxVTbl);
	ubigint _rlvUref = htonl64(rec->rlvUref);
	ubigint _tplRefFmncMStep = htonl64(rec->tplRefFmncMStep);
	uint _ixWFilecfg = htonl(rec->ixWFilecfg);
	uint _start = htonl(rec->start);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMActivity,
		(char*) &_rlvIxVTbl,
		(char*) &_rlvUref,
		(char*) &_tplRefFmncMStep,
		(char*) &_ixWFilecfg,
		rec->Title.c_str(),
		(char*) &_start,
		(char*) &_refFmncMPerson
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMStep_insertRec", 10, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStep_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMStep::insertRst(
			ListFmncMStep& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMStep::updateRec(
			FmncMStep* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMActivity = htonl64(rec->refFmncMActivity);
	uint _rlvIxVTbl = htonl(rec->rlvIxVTbl);
	ubigint _rlvUref = htonl64(rec->rlvUref);
	ubigint _tplRefFmncMStep = htonl64(rec->tplRefFmncMStep);
	uint _ixWFilecfg = htonl(rec->ixWFilecfg);
	uint _start = htonl(rec->start);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMActivity,
		(char*) &_rlvIxVTbl,
		(char*) &_rlvUref,
		(char*) &_tplRefFmncMStep,
		(char*) &_ixWFilecfg,
		rec->Title.c_str(),
		(char*) &_start,
		(char*) &_refFmncMPerson,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMStep_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStep_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMStep::updateRst(
			ListFmncMStep& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMStep::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMStep_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStep_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMStep::loadRecByRef(
			ubigint ref
			, FmncMStep** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMStep_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMStep::loadRefsByAct(
			ubigint refFmncMActivity
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMActivity = htonl64(refFmncMActivity);

	const char* vals[] = {
		(char*) &_refFmncMActivity
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMStep_loadRefsByAct", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncMStep::loadRefsByRltRlu(
			uint rlvIxVTbl
			, ubigint rlvUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _rlvIxVTbl = htonl(rlvIxVTbl);
	ubigint _rlvUref = htonl64(rlvUref);

	const char* vals[] = {
		(char*) &_rlvIxVTbl,
		(char*) &_rlvUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblFmncMStep_loadRefsByRltRlu", 2, vals, l, f, append, refs);
};

bool PgTblFmncMStep::loadTitByRef(
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

	return loadStringByStmt("TblFmncMStep_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

