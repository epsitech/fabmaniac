/**
  * \file FmncMAddress.cpp
  * database access for table TblFmncMAddress (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMAddress.h"

/******************************************************************************
 class FmncMAddress
 ******************************************************************************/

FmncMAddress::FmncMAddress(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint x1Startd
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string srefKAdrtype
			, const string Address1
			, const string Address2
			, const string Zipcode
			, const string City
			, const string State
			, const string srefKCountry
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->x1Startd = x1Startd;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->srefKAdrtype = srefKAdrtype;
	this->Address1 = Address1;
	this->Address2 = Address2;
	this->Zipcode = Zipcode;
	this->City = City;
	this->State = State;
	this->srefKCountry = srefKCountry;
};

bool FmncMAddress::operator==(
			const FmncMAddress& comp
		) {
	return false;
};

bool FmncMAddress::operator!=(
			const FmncMAddress& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMAddress
 ******************************************************************************/

ListFmncMAddress::ListFmncMAddress() {
};

ListFmncMAddress::ListFmncMAddress(
			const ListFmncMAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMAddress(*(src.nodes[i]));
};

ListFmncMAddress::~ListFmncMAddress() {
	clear();
};

void ListFmncMAddress::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMAddress::size() const {
	return(nodes.size());
};

void ListFmncMAddress::append(
			FmncMAddress* rec
		) {
	nodes.push_back(rec);
};

FmncMAddress* ListFmncMAddress::operator[](
			const uint ix
		) {
	FmncMAddress* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMAddress& ListFmncMAddress::operator=(
			const ListFmncMAddress& src
		) {
	FmncMAddress* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMAddress(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMAddress::operator==(
			const ListFmncMAddress& comp
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

bool ListFmncMAddress::operator!=(
			const ListFmncMAddress& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMAddress
 ******************************************************************************/

TblFmncMAddress::TblFmncMAddress() {
};

TblFmncMAddress::~TblFmncMAddress() {
};

bool TblFmncMAddress::loadRecBySQL(
			const string& sqlstr
			, FmncMAddress** rec
		) {
	return false;
};

ubigint TblFmncMAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMAddress& rst
		) {
	return 0;
};

void TblFmncMAddress::insertRec(
			FmncMAddress* rec
		) {
};

ubigint TblFmncMAddress::insertNewRec(
			FmncMAddress** rec
			, const ubigint grp
			, const ubigint own
			, const uint x1Startd
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string srefKAdrtype
			, const string Address1
			, const string Address2
			, const string Zipcode
			, const string City
			, const string State
			, const string srefKCountry
		) {
	ubigint retval = 0;
	FmncMAddress* _rec = NULL;

	_rec = new FmncMAddress(0, grp, own, x1Startd, hkIxVTbl, hkUref, srefKAdrtype, Address1, Address2, Zipcode, City, State, srefKCountry);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMAddress::appendNewRecToRst(
			ListFmncMAddress& rst
			, FmncMAddress** rec
			, const ubigint grp
			, const ubigint own
			, const uint x1Startd
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string srefKAdrtype
			, const string Address1
			, const string Address2
			, const string Zipcode
			, const string City
			, const string State
			, const string srefKCountry
		) {
	ubigint retval = 0;
	FmncMAddress* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, x1Startd, hkIxVTbl, hkUref, srefKAdrtype, Address1, Address2, Zipcode, City, State, srefKCountry);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMAddress::insertRst(
			ListFmncMAddress& rst
			, bool transact
		) {
};

void TblFmncMAddress::updateRec(
			FmncMAddress* rec
		) {
};

void TblFmncMAddress::updateRst(
			ListFmncMAddress& rst
			, bool transact
		) {
};

void TblFmncMAddress::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMAddress::loadRecByRef(
			ubigint ref
			, FmncMAddress** rec
		) {
	return false;
};

ubigint TblFmncMAddress::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMAddress::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMAddress& rst
		) {
	ubigint numload = 0;
	FmncMAddress* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMAddress
 ******************************************************************************/

MyTblFmncMAddress::MyTblFmncMAddress() : TblFmncMAddress(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMAddress::~MyTblFmncMAddress() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMAddress::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMAddress (grp, own, x1Startd, hkIxVTbl, hkUref, srefKAdrtype, Address1, Address2, Zipcode, City, State, srefKCountry) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMAddress SET grp = ?, own = ?, x1Startd = ?, hkIxVTbl = ?, hkUref = ?, srefKAdrtype = ?, Address1 = ?, Address2 = ?, Zipcode = ?, City = ?, State = ?, srefKCountry = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMAddress WHERE ref = ?", false);
};

bool MyTblFmncMAddress::loadRecBySQL(
			const string& sqlstr
			, FmncMAddress** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMAddress* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMAddress / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMAddress();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->x1Startd = atol((char*) dbrow[3]); else _rec->x1Startd = 0;
		if (dbrow[4]) _rec->hkIxVTbl = atol((char*) dbrow[4]); else _rec->hkIxVTbl = 0;
		if (dbrow[5]) _rec->hkUref = atoll((char*) dbrow[5]); else _rec->hkUref = 0;
		if (dbrow[6]) _rec->srefKAdrtype.assign(dbrow[6], dblengths[6]); else _rec->srefKAdrtype = "";
		if (dbrow[7]) _rec->Address1.assign(dbrow[7], dblengths[7]); else _rec->Address1 = "";
		if (dbrow[8]) _rec->Address2.assign(dbrow[8], dblengths[8]); else _rec->Address2 = "";
		if (dbrow[9]) _rec->Zipcode.assign(dbrow[9], dblengths[9]); else _rec->Zipcode = "";
		if (dbrow[10]) _rec->City.assign(dbrow[10], dblengths[10]); else _rec->City = "";
		if (dbrow[11]) _rec->State.assign(dbrow[11], dblengths[11]); else _rec->State = "";
		if (dbrow[12]) _rec->srefKCountry.assign(dbrow[12], dblengths[12]); else _rec->srefKCountry = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMAddress& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMAddress* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMAddress / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMAddress();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->x1Startd = atol((char*) dbrow[3]); else rec->x1Startd = 0;
			if (dbrow[4]) rec->hkIxVTbl = atol((char*) dbrow[4]); else rec->hkIxVTbl = 0;
			if (dbrow[5]) rec->hkUref = atoll((char*) dbrow[5]); else rec->hkUref = 0;
			if (dbrow[6]) rec->srefKAdrtype.assign(dbrow[6], dblengths[6]); else rec->srefKAdrtype = "";
			if (dbrow[7]) rec->Address1.assign(dbrow[7], dblengths[7]); else rec->Address1 = "";
			if (dbrow[8]) rec->Address2.assign(dbrow[8], dblengths[8]); else rec->Address2 = "";
			if (dbrow[9]) rec->Zipcode.assign(dbrow[9], dblengths[9]); else rec->Zipcode = "";
			if (dbrow[10]) rec->City.assign(dbrow[10], dblengths[10]); else rec->City = "";
			if (dbrow[11]) rec->State.assign(dbrow[11], dblengths[11]); else rec->State = "";
			if (dbrow[12]) rec->srefKCountry.assign(dbrow[12], dblengths[12]); else rec->srefKCountry = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMAddress::insertRec(
			FmncMAddress* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->srefKAdrtype.length();
	l[6] = rec->Address1.length();
	l[7] = rec->Address2.length();
	l[8] = rec->Zipcode.length();
	l[9] = rec->City.length();
	l[10] = rec->State.length();
	l[11] = rec->srefKCountry.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1Startd,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->hkUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefKAdrtype.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Address1.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Address2.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Zipcode.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->City.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->State.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefKCountry.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMAddress / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMAddress / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMAddress::insertRst(
			ListFmncMAddress& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMAddress::updateRec(
			FmncMAddress* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->srefKAdrtype.length();
	l[6] = rec->Address1.length();
	l[7] = rec->Address2.length();
	l[8] = rec->Zipcode.length();
	l[9] = rec->City.length();
	l[10] = rec->State.length();
	l[11] = rec->srefKCountry.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x1Startd,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->hkIxVTbl,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->hkUref,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->srefKAdrtype.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Address1.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Address2.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Zipcode.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->City.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->State.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->srefKCountry.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMAddress / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMAddress / stmtUpdateRec)\n");
};

void MyTblFmncMAddress::updateRst(
			ListFmncMAddress& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMAddress::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMAddress / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMAddress / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMAddress::loadRecByRef(
			ubigint ref
			, FmncMAddress** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMAddress WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMAddress::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMAddress WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMAddress
 ******************************************************************************/

PgTblFmncMAddress::PgTblFmncMAddress() : TblFmncMAddress(), PgTable() {
};

PgTblFmncMAddress::~PgTblFmncMAddress() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMAddress::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMAddress_insertRec", "INSERT INTO TblFmncMAddress (grp, own, x1Startd, hkIxVTbl, hkUref, srefKAdrtype, Address1, Address2, Zipcode, City, State, srefKCountry) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMAddress_updateRec", "UPDATE TblFmncMAddress SET grp = $1, own = $2, x1Startd = $3, hkIxVTbl = $4, hkUref = $5, srefKAdrtype = $6, Address1 = $7, Address2 = $8, Zipcode = $9, City = $10, State = $11, srefKCountry = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMAddress_removeRecByRef", "DELETE FROM TblFmncMAddress WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMAddress_loadRecByRef", "SELECT ref, grp, own, x1Startd, hkIxVTbl, hkUref, srefKAdrtype, Address1, Address2, Zipcode, City, State, srefKCountry FROM TblFmncMAddress WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMAddress_loadRefsByHktHku", "SELECT ref FROM TblFmncMAddress WHERE hkIxVTbl = $1 AND hkUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMAddress::loadRec(
			PGresult* res
			, FmncMAddress** rec
		) {
	char* ptr;

	FmncMAddress* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMAddress();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "srefkadrtype"),
			PQfnumber(res, "address1"),
			PQfnumber(res, "address2"),
			PQfnumber(res, "zipcode"),
			PQfnumber(res, "city"),
			PQfnumber(res, "state"),
			PQfnumber(res, "srefkcountry")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefKAdrtype.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Address1.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Address2.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Zipcode.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->City.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->State.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->srefKCountry.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMAddress::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMAddress& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMAddress* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "srefkadrtype"),
			PQfnumber(res, "address1"),
			PQfnumber(res, "address2"),
			PQfnumber(res, "zipcode"),
			PQfnumber(res, "city"),
			PQfnumber(res, "state"),
			PQfnumber(res, "srefkcountry")
		};

		while (numread < numrow) {
			rec = new FmncMAddress();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefKAdrtype.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Address1.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Address2.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Zipcode.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->City.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->State.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->srefKCountry.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMAddress::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMAddress** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMAddress / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMAddress::loadRecBySQL(
			const string& sqlstr
			, FmncMAddress** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMAddress::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMAddress& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMAddress::insertRec(
			FmncMAddress* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_x1Startd,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->srefKAdrtype.c_str(),
		rec->Address1.c_str(),
		rec->Address2.c_str(),
		rec->Zipcode.c_str(),
		rec->City.c_str(),
		rec->State.c_str(),
		rec->srefKCountry.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMAddress_insertRec", 12, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMAddress_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMAddress::insertRst(
			ListFmncMAddress& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMAddress::updateRec(
			FmncMAddress* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_x1Startd,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->srefKAdrtype.c_str(),
		rec->Address1.c_str(),
		rec->Address2.c_str(),
		rec->Zipcode.c_str(),
		rec->City.c_str(),
		rec->State.c_str(),
		rec->srefKCountry.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMAddress_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMAddress_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMAddress::updateRst(
			ListFmncMAddress& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMAddress::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMAddress_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMAddress_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMAddress::loadRecByRef(
			ubigint ref
			, FmncMAddress** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMAddress_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMAddress::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblFmncMAddress_loadRefsByHktHku", 2, vals, l, f, append, refs);
};

// IP pgTbl --- END

