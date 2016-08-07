/**
  * \file FmncMTool.cpp
  * database access for table TblFmncMTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMTool.h"

/******************************************************************************
 class FmncMTool
 ******************************************************************************/

FmncMTool::FmncMTool(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint fabRefFmncMFab
			, const ubigint mnfRefFmncMOrg
			, const string Title
			, const ubigint refJUnitprice
			, const double Unitprice
			, const string Training
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->fabRefFmncMFab = fabRefFmncMFab;
	this->mnfRefFmncMOrg = mnfRefFmncMOrg;
	this->Title = Title;
	this->refJUnitprice = refJUnitprice;
	this->Unitprice = Unitprice;
	this->Training = Training;
	this->Comment = Comment;
};

bool FmncMTool::operator==(
			const FmncMTool& comp
		) {
	return false;
};

bool FmncMTool::operator!=(
			const FmncMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMTool
 ******************************************************************************/

ListFmncMTool::ListFmncMTool() {
};

ListFmncMTool::ListFmncMTool(
			const ListFmncMTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMTool(*(src.nodes[i]));
};

ListFmncMTool::~ListFmncMTool() {
	clear();
};

void ListFmncMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMTool::size() const {
	return(nodes.size());
};

void ListFmncMTool::append(
			FmncMTool* rec
		) {
	nodes.push_back(rec);
};

FmncMTool* ListFmncMTool::operator[](
			const uint ix
		) {
	FmncMTool* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMTool& ListFmncMTool::operator=(
			const ListFmncMTool& src
		) {
	FmncMTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMTool::operator==(
			const ListFmncMTool& comp
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

bool ListFmncMTool::operator!=(
			const ListFmncMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMTool
 ******************************************************************************/

TblFmncMTool::TblFmncMTool() {
};

TblFmncMTool::~TblFmncMTool() {
};

bool TblFmncMTool::loadRecBySQL(
			const string& sqlstr
			, FmncMTool** rec
		) {
	return false;
};

ubigint TblFmncMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMTool& rst
		) {
	return 0;
};

void TblFmncMTool::insertRec(
			FmncMTool* rec
		) {
};

ubigint TblFmncMTool::insertNewRec(
			FmncMTool** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint fabRefFmncMFab
			, const ubigint mnfRefFmncMOrg
			, const string Title
			, const ubigint refJUnitprice
			, const double Unitprice
			, const string Training
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMTool* _rec = NULL;

	_rec = new FmncMTool(0, grp, own, fabRefFmncMFab, mnfRefFmncMOrg, Title, refJUnitprice, Unitprice, Training, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMTool::appendNewRecToRst(
			ListFmncMTool& rst
			, FmncMTool** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint fabRefFmncMFab
			, const ubigint mnfRefFmncMOrg
			, const string Title
			, const ubigint refJUnitprice
			, const double Unitprice
			, const string Training
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMTool* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, fabRefFmncMFab, mnfRefFmncMOrg, Title, refJUnitprice, Unitprice, Training, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMTool::insertRst(
			ListFmncMTool& rst
			, bool transact
		) {
};

void TblFmncMTool::updateRec(
			FmncMTool* rec
		) {
};

void TblFmncMTool::updateRst(
			ListFmncMTool& rst
			, bool transact
		) {
};

void TblFmncMTool::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMTool::loadRecByRef(
			ubigint ref
			, FmncMTool** rec
		) {
	return false;
};

ubigint TblFmncMTool::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMTool& rst
		) {
	ubigint numload = 0;
	FmncMTool* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMTool
 ******************************************************************************/

MyTblFmncMTool::MyTblFmncMTool() : TblFmncMTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMTool::~MyTblFmncMTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMTool (grp, own, fabRefFmncMFab, mnfRefFmncMOrg, Title, refJUnitprice, Unitprice, Training, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMTool SET grp = ?, own = ?, fabRefFmncMFab = ?, mnfRefFmncMOrg = ?, Title = ?, refJUnitprice = ?, Unitprice = ?, Training = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMTool WHERE ref = ?", false);
};

bool MyTblFmncMTool::loadRecBySQL(
			const string& sqlstr
			, FmncMTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMTool();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->fabRefFmncMFab = atoll((char*) dbrow[3]); else _rec->fabRefFmncMFab = 0;
		if (dbrow[4]) _rec->mnfRefFmncMOrg = atoll((char*) dbrow[4]); else _rec->mnfRefFmncMOrg = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->refJUnitprice = atoll((char*) dbrow[6]); else _rec->refJUnitprice = 0;
		if (dbrow[7]) _rec->Unitprice = atof((char*) dbrow[7]); else _rec->Unitprice = 0.0;
		if (dbrow[8]) _rec->Training.assign(dbrow[8], dblengths[8]); else _rec->Training = "";
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMTool();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->fabRefFmncMFab = atoll((char*) dbrow[3]); else rec->fabRefFmncMFab = 0;
			if (dbrow[4]) rec->mnfRefFmncMOrg = atoll((char*) dbrow[4]); else rec->mnfRefFmncMOrg = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->refJUnitprice = atoll((char*) dbrow[6]); else rec->refJUnitprice = 0;
			if (dbrow[7]) rec->Unitprice = atof((char*) dbrow[7]); else rec->Unitprice = 0.0;
			if (dbrow[8]) rec->Training.assign(dbrow[8], dblengths[8]); else rec->Training = "";
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMTool::insertRec(
			FmncMTool* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->Title.length();
	l[7] = rec->Training.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->fabRefFmncMFab,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->mnfRefFmncMOrg,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJUnitprice,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Training.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMTool / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMTool / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMTool::insertRst(
			ListFmncMTool& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMTool::updateRec(
			FmncMTool* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->Title.length();
	l[7] = rec->Training.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->fabRefFmncMFab,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->mnfRefFmncMOrg,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refJUnitprice,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Training.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMTool / stmtUpdateRec)\n");
};

void MyTblFmncMTool::updateRst(
			ListFmncMTool& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMTool::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMTool / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMTool / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMTool::loadRecByRef(
			ubigint ref
			, FmncMTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMTool WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMTool
 ******************************************************************************/

PgTblFmncMTool::PgTblFmncMTool() : TblFmncMTool(), PgTable() {
};

PgTblFmncMTool::~PgTblFmncMTool() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMTool_insertRec", "INSERT INTO TblFmncMTool (grp, own, fabRefFmncMFab, mnfRefFmncMOrg, Title, refJUnitprice, Unitprice, Training, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTool_updateRec", "UPDATE TblFmncMTool SET grp = $1, own = $2, fabRefFmncMFab = $3, mnfRefFmncMOrg = $4, Title = $5, refJUnitprice = $6, Unitprice = $7, Training = $8, Comment = $9 WHERE ref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMTool_removeRecByRef", "DELETE FROM TblFmncMTool WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMTool_loadRecByRef", "SELECT ref, grp, own, fabRefFmncMFab, mnfRefFmncMOrg, Title, refJUnitprice, Unitprice, Training, Comment FROM TblFmncMTool WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMTool::loadRec(
			PGresult* res
			, FmncMTool** rec
		) {
	char* ptr;

	FmncMTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMTool();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "fabreffmncmfab"),
			PQfnumber(res, "mnfreffmncmorg"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjunitprice"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "training"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->fabRefFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->mnfRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refJUnitprice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Training.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMTool* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "fabreffmncmfab"),
			PQfnumber(res, "mnfreffmncmorg"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjunitprice"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "training"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->fabRefFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->mnfRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refJUnitprice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Training.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMTool::loadRecBySQL(
			const string& sqlstr
			, FmncMTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMTool::insertRec(
			FmncMTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _fabRefFmncMFab = htonl64(rec->fabRefFmncMFab);
	ubigint _mnfRefFmncMOrg = htonl64(rec->mnfRefFmncMOrg);
	ubigint _refJUnitprice = htonl64(rec->refJUnitprice);
	string _Unitprice = to_string(rec->Unitprice);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_fabRefFmncMFab,
		(char*) &_mnfRefFmncMOrg,
		rec->Title.c_str(),
		(char*) &_refJUnitprice,
		_Unitprice.c_str(),
		rec->Training.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMTool_insertRec", 9, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMTool::insertRst(
			ListFmncMTool& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMTool::updateRec(
			FmncMTool* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _fabRefFmncMFab = htonl64(rec->fabRefFmncMFab);
	ubigint _mnfRefFmncMOrg = htonl64(rec->mnfRefFmncMOrg);
	ubigint _refJUnitprice = htonl64(rec->refJUnitprice);
	string _Unitprice = to_string(rec->Unitprice);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_fabRefFmncMFab,
		(char*) &_mnfRefFmncMOrg,
		rec->Title.c_str(),
		(char*) &_refJUnitprice,
		_Unitprice.c_str(),
		rec->Training.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMTool_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMTool::updateRst(
			ListFmncMTool& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMTool::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMTool_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMTool_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMTool::loadRecByRef(
			ubigint ref
			, FmncMTool** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMTool_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

