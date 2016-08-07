/**
  * \file FmncMUser.cpp
  * database access for table TblFmncMUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMUser.h"

/******************************************************************************
 class FmncMUser
 ******************************************************************************/

FmncMUser::FmncMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refFmncMUsergroup
			, const ubigint refFmncMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixFmncVLocale
			, const uint ixFmncVUserlevel
			, const string Password
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refFmncMUsergroup = refFmncMUsergroup;
	this->refFmncMPerson = refFmncMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixFmncVLocale = ixFmncVLocale;
	this->ixFmncVUserlevel = ixFmncVUserlevel;
	this->Password = Password;
};

bool FmncMUser::operator==(
			const FmncMUser& comp
		) {
	return false;
};

bool FmncMUser::operator!=(
			const FmncMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMUser
 ******************************************************************************/

ListFmncMUser::ListFmncMUser() {
};

ListFmncMUser::ListFmncMUser(
			const ListFmncMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMUser(*(src.nodes[i]));
};

ListFmncMUser::~ListFmncMUser() {
	clear();
};

void ListFmncMUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMUser::size() const {
	return(nodes.size());
};

void ListFmncMUser::append(
			FmncMUser* rec
		) {
	nodes.push_back(rec);
};

FmncMUser* ListFmncMUser::operator[](
			const uint ix
		) {
	FmncMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMUser& ListFmncMUser::operator=(
			const ListFmncMUser& src
		) {
	FmncMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMUser::operator==(
			const ListFmncMUser& comp
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

bool ListFmncMUser::operator!=(
			const ListFmncMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMUser
 ******************************************************************************/

TblFmncMUser::TblFmncMUser() {
};

TblFmncMUser::~TblFmncMUser() {
};

bool TblFmncMUser::loadRecBySQL(
			const string& sqlstr
			, FmncMUser** rec
		) {
	return false;
};

ubigint TblFmncMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMUser& rst
		) {
	return 0;
};

void TblFmncMUser::insertRec(
			FmncMUser* rec
		) {
};

ubigint TblFmncMUser::insertNewRec(
			FmncMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refFmncMUsergroup
			, const ubigint refFmncMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixFmncVLocale
			, const uint ixFmncVUserlevel
			, const string Password
		) {
	ubigint retval = 0;
	FmncMUser* _rec = NULL;

	_rec = new FmncMUser(0, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMUser::appendNewRecToRst(
			ListFmncMUser& rst
			, FmncMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refFmncMUsergroup
			, const ubigint refFmncMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixFmncVLocale
			, const uint ixFmncVUserlevel
			, const string Password
		) {
	ubigint retval = 0;
	FmncMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMUser::insertRst(
			ListFmncMUser& rst
			, bool transact
		) {
};

void TblFmncMUser::updateRec(
			FmncMUser* rec
		) {
};

void TblFmncMUser::updateRst(
			ListFmncMUser& rst
			, bool transact
		) {
};

void TblFmncMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMUser::loadRecByRef(
			ubigint ref
			, FmncMUser** rec
		) {
	return false;
};

bool TblFmncMUser::loadRecByPrs(
			ubigint refFmncMPerson
			, FmncMUser** rec
		) {
	return false;
};

bool TblFmncMUser::loadRecBySrf(
			string sref
			, FmncMUser** rec
		) {
	return false;
};

bool TblFmncMUser::loadRefByPrs(
			ubigint refFmncMPerson
			, ubigint& ref
		) {
	return false;
};

bool TblFmncMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblFmncMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {
	return false;
};

bool TblFmncMUser::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMUser& rst
		) {
	ubigint numload = 0;
	FmncMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMUser
 ******************************************************************************/

MyTblFmncMUser::MyTblFmncMUser() : TblFmncMUser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMUser::~MyTblFmncMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMUser (grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMUser SET grp = ?, own = ?, refRUsergroup = ?, refFmncMUsergroup = ?, refFmncMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixFmncVLocale = ?, ixFmncVUserlevel = ?, Password = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMUser WHERE ref = ?", false);
};

bool MyTblFmncMUser::loadRecBySQL(
			const string& sqlstr
			, FmncMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMUser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refFmncMUsergroup = atoll((char*) dbrow[4]); else _rec->refFmncMUsergroup = 0;
		if (dbrow[5]) _rec->refFmncMPerson = atoll((char*) dbrow[5]); else _rec->refFmncMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixFmncVLocale = atol((char*) dbrow[9]); else _rec->ixFmncVLocale = 0;
		if (dbrow[10]) _rec->ixFmncVUserlevel = atol((char*) dbrow[10]); else _rec->ixFmncVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMUser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refFmncMUsergroup = atoll((char*) dbrow[4]); else rec->refFmncMUsergroup = 0;
			if (dbrow[5]) rec->refFmncMPerson = atoll((char*) dbrow[5]); else rec->refFmncMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixFmncVLocale = atol((char*) dbrow[9]); else rec->ixFmncVLocale = 0;
			if (dbrow[10]) rec->ixFmncVUserlevel = atol((char*) dbrow[10]); else rec->ixFmncVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMUser::insertRec(
			FmncMUser* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixFmncVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixFmncVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMUser / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMUser / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMUser::insertRst(
			ListFmncMUser& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMUser::updateRec(
			FmncMUser* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMUsergroup,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMPerson,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixFmncVLocale,&(l[8]),&(n[8]),&(e[8])), 
		bindUint(&rec->ixFmncVUserlevel,&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMUser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMUser / stmtUpdateRec)\n");
};

void MyTblFmncMUser::updateRst(
			ListFmncMUser& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMUser / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMUser / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMUser::loadRecByRef(
			ubigint ref
			, FmncMUser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMUser::loadRecByPrs(
			ubigint refFmncMPerson
			, FmncMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password FROM TblFmncMUser WHERE refFmncMPerson = " + to_string(refFmncMPerson) + "", rec);
};

bool MyTblFmncMUser::loadRecBySrf(
			string sref
			, FmncMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password FROM TblFmncMUser WHERE sref = '" + sref + "'", rec);
};

bool MyTblFmncMUser::loadRefByPrs(
			ubigint refFmncMPerson
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMUser WHERE refFmncMPerson = " + to_string(refFmncMPerson) + "", ref);
};

bool MyTblFmncMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMUser WHERE sref = '" + sref + "'", ref);
};

bool MyTblFmncMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", ref);
};

bool MyTblFmncMUser::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblFmncMUser WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMUser
 ******************************************************************************/

PgTblFmncMUser::PgTblFmncMUser() : TblFmncMUser(), PgTable() {
};

PgTblFmncMUser::~PgTblFmncMUser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMUser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMUser_insertRec", "INSERT INTO TblFmncMUser (grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_updateRec", "UPDATE TblFmncMUser SET grp = $1, own = $2, refRUsergroup = $3, refFmncMUsergroup = $4, refFmncMPerson = $5, sref = $6, refJState = $7, ixVState = $8, ixFmncVLocale = $9, ixFmncVUserlevel = $10, Password = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_removeRecByRef", "DELETE FROM TblFmncMUser WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMUser_loadRecByRef", "SELECT ref, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password FROM TblFmncMUser WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMUser_loadRecByPrs", "SELECT ref, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password FROM TblFmncMUser WHERE refFmncMPerson = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_loadRecBySrf", "SELECT ref, grp, own, refRUsergroup, refFmncMUsergroup, refFmncMPerson, sref, refJState, ixVState, ixFmncVLocale, ixFmncVUserlevel, Password FROM TblFmncMUser WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_loadRefByPrs", "SELECT ref FROM TblFmncMUser WHERE refFmncMPerson = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_loadRefBySrf", "SELECT ref FROM TblFmncMUser WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_loadRefBySrfPwd", "SELECT ref FROM TblFmncMUser WHERE sref = $1 AND Password = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUser_loadSrfByRef", "SELECT sref FROM TblFmncMUser WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMUser::loadRec(
			PGresult* res
			, FmncMUser** rec
		) {
	char* ptr;

	FmncMUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMUser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixfmncvlocale"),
			PQfnumber(res, "ixfmncvuserlevel"),
			PQfnumber(res, "password")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refRUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixFmncVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixFmncVUserlevel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Password.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMUser::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMUser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixfmncvlocale"),
			PQfnumber(res, "ixfmncvuserlevel"),
			PQfnumber(res, "password")
		};

		while (numread < numrow) {
			rec = new FmncMUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refRUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixFmncVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixFmncVUserlevel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Password.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMUser::loadRecBySQL(
			const string& sqlstr
			, FmncMUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMUser::insertRec(
			FmncMUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixFmncVLocale = htonl(rec->ixFmncVLocale);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refFmncMUsergroup,
		(char*) &_refFmncMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixFmncVLocale,
		(char*) &_ixFmncVUserlevel,
		rec->Password.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMUser_insertRec", 11, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUser_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMUser::insertRst(
			ListFmncMUser& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMUser::updateRec(
			FmncMUser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixFmncVLocale = htonl(rec->ixFmncVLocale);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refFmncMUsergroup,
		(char*) &_refFmncMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixFmncVLocale,
		(char*) &_ixFmncVUserlevel,
		rec->Password.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMUser_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUser_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMUser::updateRst(
			ListFmncMUser& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMUser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMUser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUser_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMUser::loadRecByRef(
			ubigint ref
			, FmncMUser** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMUser_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMUser::loadRecByPrs(
			ubigint refFmncMPerson
			, FmncMUser** rec
		) {
	ubigint _refFmncMPerson = htonl64(refFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMUser_loadRecByPrs", 1, vals, l, f, rec);
};

bool PgTblFmncMUser::loadRecBySrf(
			string sref
			, FmncMUser** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblFmncMUser_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblFmncMUser::loadRefByPrs(
			ubigint refFmncMPerson
			, ubigint& ref
		) {
	ubigint _refFmncMPerson = htonl64(refFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblFmncMUser_loadRefByPrs", 1, vals, l, f, ref);
};

bool PgTblFmncMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadUbigintByStmt("TblFmncMUser_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblFmncMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str(),
		Password.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadUbigintByStmt("TblFmncMUser_loadRefBySrfPwd", 2, vals, l, f, ref);
};

bool PgTblFmncMUser::loadSrfByRef(
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

	return loadStringByStmt("TblFmncMUser_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

