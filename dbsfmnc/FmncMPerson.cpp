/**
  * \file FmncMPerson.cpp
  * database access for table TblFmncMPerson (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMPerson.h"

/******************************************************************************
 class FmncMPerson
 ******************************************************************************/

FmncMPerson::FmncMPerson(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const ubigint refROrg
			, const ubigint refFmncMOrg
			, const ubigint refFmncMAddress
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
			, const string Salutation
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixWDerivate = ixWDerivate;
	this->refROrg = refROrg;
	this->refFmncMOrg = refFmncMOrg;
	this->refFmncMAddress = refFmncMAddress;
	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->refJLastname = refJLastname;
	this->Lastname = Lastname;
	this->telRefADetail = telRefADetail;
	this->Tel = Tel;
	this->emlRefADetail = emlRefADetail;
	this->Eml = Eml;
	this->Salutation = Salutation;
};

bool FmncMPerson::operator==(
			const FmncMPerson& comp
		) {
	return false;
};

bool FmncMPerson::operator!=(
			const FmncMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMPerson
 ******************************************************************************/

ListFmncMPerson::ListFmncMPerson() {
};

ListFmncMPerson::ListFmncMPerson(
			const ListFmncMPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMPerson(*(src.nodes[i]));
};

ListFmncMPerson::~ListFmncMPerson() {
	clear();
};

void ListFmncMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMPerson::size() const {
	return(nodes.size());
};

void ListFmncMPerson::append(
			FmncMPerson* rec
		) {
	nodes.push_back(rec);
};

FmncMPerson* ListFmncMPerson::operator[](
			const uint ix
		) {
	FmncMPerson* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMPerson& ListFmncMPerson::operator=(
			const ListFmncMPerson& src
		) {
	FmncMPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMPerson::operator==(
			const ListFmncMPerson& comp
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

bool ListFmncMPerson::operator!=(
			const ListFmncMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMPerson
 ******************************************************************************/

TblFmncMPerson::TblFmncMPerson() {
};

TblFmncMPerson::~TblFmncMPerson() {
};

bool TblFmncMPerson::loadRecBySQL(
			const string& sqlstr
			, FmncMPerson** rec
		) {
	return false;
};

ubigint TblFmncMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMPerson& rst
		) {
	return 0;
};

void TblFmncMPerson::insertRec(
			FmncMPerson* rec
		) {
};

ubigint TblFmncMPerson::insertNewRec(
			FmncMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const ubigint refROrg
			, const ubigint refFmncMOrg
			, const ubigint refFmncMAddress
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
			, const string Salutation
		) {
	ubigint retval = 0;
	FmncMPerson* _rec = NULL;

	_rec = new FmncMPerson(0, grp, own, ixWDerivate, refROrg, refFmncMOrg, refFmncMAddress, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMPerson::appendNewRecToRst(
			ListFmncMPerson& rst
			, FmncMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const ubigint refROrg
			, const ubigint refFmncMOrg
			, const ubigint refFmncMAddress
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
			, const string Salutation
		) {
	ubigint retval = 0;
	FmncMPerson* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixWDerivate, refROrg, refFmncMOrg, refFmncMAddress, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMPerson::insertRst(
			ListFmncMPerson& rst
			, bool transact
		) {
};

void TblFmncMPerson::updateRec(
			FmncMPerson* rec
		) {
};

void TblFmncMPerson::updateRst(
			ListFmncMPerson& rst
			, bool transact
		) {
};

void TblFmncMPerson::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMPerson::loadRecByRef(
			ubigint ref
			, FmncMPerson** rec
		) {
	return false;
};

ubigint TblFmncMPerson::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMPerson& rst
		) {
	ubigint numload = 0;
	FmncMPerson* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMPerson
 ******************************************************************************/

MyTblFmncMPerson::MyTblFmncMPerson() : TblFmncMPerson(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMPerson::~MyTblFmncMPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMPerson (grp, own, ixWDerivate, refROrg, refFmncMOrg, refFmncMAddress, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMPerson SET grp = ?, own = ?, ixWDerivate = ?, refROrg = ?, refFmncMOrg = ?, refFmncMAddress = ?, ixVSex = ?, Title = ?, Firstname = ?, refJLastname = ?, Lastname = ?, telRefADetail = ?, Tel = ?, emlRefADetail = ?, Eml = ?, Salutation = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMPerson WHERE ref = ?", false);
};

bool MyTblFmncMPerson::loadRecBySQL(
			const string& sqlstr
			, FmncMPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMPerson / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMPerson();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixWDerivate = atol((char*) dbrow[3]); else _rec->ixWDerivate = 0;
		if (dbrow[4]) _rec->refROrg = atoll((char*) dbrow[4]); else _rec->refROrg = 0;
		if (dbrow[5]) _rec->refFmncMOrg = atoll((char*) dbrow[5]); else _rec->refFmncMOrg = 0;
		if (dbrow[6]) _rec->refFmncMAddress = atoll((char*) dbrow[6]); else _rec->refFmncMAddress = 0;
		if (dbrow[7]) _rec->ixVSex = atol((char*) dbrow[7]); else _rec->ixVSex = 0;
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";
		if (dbrow[9]) _rec->Firstname.assign(dbrow[9], dblengths[9]); else _rec->Firstname = "";
		if (dbrow[10]) _rec->refJLastname = atoll((char*) dbrow[10]); else _rec->refJLastname = 0;
		if (dbrow[11]) _rec->Lastname.assign(dbrow[11], dblengths[11]); else _rec->Lastname = "";
		if (dbrow[12]) _rec->telRefADetail = atoll((char*) dbrow[12]); else _rec->telRefADetail = 0;
		if (dbrow[13]) _rec->Tel.assign(dbrow[13], dblengths[13]); else _rec->Tel = "";
		if (dbrow[14]) _rec->emlRefADetail = atoll((char*) dbrow[14]); else _rec->emlRefADetail = 0;
		if (dbrow[15]) _rec->Eml.assign(dbrow[15], dblengths[15]); else _rec->Eml = "";
		if (dbrow[16]) _rec->Salutation.assign(dbrow[16], dblengths[16]); else _rec->Salutation = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMPerson / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMPerson();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixWDerivate = atol((char*) dbrow[3]); else rec->ixWDerivate = 0;
			if (dbrow[4]) rec->refROrg = atoll((char*) dbrow[4]); else rec->refROrg = 0;
			if (dbrow[5]) rec->refFmncMOrg = atoll((char*) dbrow[5]); else rec->refFmncMOrg = 0;
			if (dbrow[6]) rec->refFmncMAddress = atoll((char*) dbrow[6]); else rec->refFmncMAddress = 0;
			if (dbrow[7]) rec->ixVSex = atol((char*) dbrow[7]); else rec->ixVSex = 0;
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			if (dbrow[9]) rec->Firstname.assign(dbrow[9], dblengths[9]); else rec->Firstname = "";
			if (dbrow[10]) rec->refJLastname = atoll((char*) dbrow[10]); else rec->refJLastname = 0;
			if (dbrow[11]) rec->Lastname.assign(dbrow[11], dblengths[11]); else rec->Lastname = "";
			if (dbrow[12]) rec->telRefADetail = atoll((char*) dbrow[12]); else rec->telRefADetail = 0;
			if (dbrow[13]) rec->Tel.assign(dbrow[13], dblengths[13]); else rec->Tel = "";
			if (dbrow[14]) rec->emlRefADetail = atoll((char*) dbrow[14]); else rec->emlRefADetail = 0;
			if (dbrow[15]) rec->Eml.assign(dbrow[15], dblengths[15]); else rec->Eml = "";
			if (dbrow[16]) rec->Salutation.assign(dbrow[16], dblengths[16]); else rec->Salutation = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMPerson::insertRec(
			FmncMPerson* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	l[7] = rec->Title.length();
	l[8] = rec->Firstname.length();
	l[10] = rec->Lastname.length();
	l[12] = rec->Tel.length();
	l[14] = rec->Eml.length();
	l[15] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refROrg,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMOrg,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMAddress,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVSex,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refJLastname,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->telRefADetail,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Tel.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->emlRefADetail,&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Eml.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->Salutation.c_str()),&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMPerson / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMPerson / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMPerson::insertRst(
			ListFmncMPerson& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMPerson::updateRec(
			FmncMPerson* rec
		) {
	unsigned long l[17]; my_bool n[17]; my_bool e[17];

	l[7] = rec->Title.length();
	l[8] = rec->Firstname.length();
	l[10] = rec->Lastname.length();
	l[12] = rec->Tel.length();
	l[14] = rec->Eml.length();
	l[15] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refROrg,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMOrg,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMAddress,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixVSex,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Firstname.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->refJLastname,&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Lastname.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->telRefADetail,&(l[11]),&(n[11]),&(e[11])), 
		bindCstring((char*) (rec->Tel.c_str()),&(l[12]),&(n[12]),&(e[12])), 
		bindUbigint(&rec->emlRefADetail,&(l[13]),&(n[13]),&(e[13])), 
		bindCstring((char*) (rec->Eml.c_str()),&(l[14]),&(n[14]),&(e[14])), 
		bindCstring((char*) (rec->Salutation.c_str()),&(l[15]),&(n[15]),&(e[15])), 
		bindUbigint(&rec->ref,&(l[16]),&(n[16]),&(e[16]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMPerson / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMPerson / stmtUpdateRec)\n");
};

void MyTblFmncMPerson::updateRst(
			ListFmncMPerson& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMPerson::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMPerson / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMPerson / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMPerson::loadRecByRef(
			ubigint ref
			, FmncMPerson** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMPerson WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMPerson
 ******************************************************************************/

PgTblFmncMPerson::PgTblFmncMPerson() : TblFmncMPerson(), PgTable() {
};

PgTblFmncMPerson::~PgTblFmncMPerson() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMPerson::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMPerson_insertRec", "INSERT INTO TblFmncMPerson (grp, own, ixWDerivate, refROrg, refFmncMOrg, refFmncMAddress, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16) RETURNING ref", 16, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMPerson_updateRec", "UPDATE TblFmncMPerson SET grp = $1, own = $2, ixWDerivate = $3, refROrg = $4, refFmncMOrg = $5, refFmncMAddress = $6, ixVSex = $7, Title = $8, Firstname = $9, refJLastname = $10, Lastname = $11, telRefADetail = $12, Tel = $13, emlRefADetail = $14, Eml = $15, Salutation = $16 WHERE ref = $17", 17, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMPerson_removeRecByRef", "DELETE FROM TblFmncMPerson WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMPerson_loadRecByRef", "SELECT ref, grp, own, ixWDerivate, refROrg, refFmncMOrg, refFmncMAddress, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation FROM TblFmncMPerson WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMPerson::loadRec(
			PGresult* res
			, FmncMPerson** rec
		) {
	char* ptr;

	FmncMPerson* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMPerson();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "refrorg"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "refjlastname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "eml"),
			PQfnumber(res, "salutation")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWDerivate = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refROrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMAddress = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refJLastname = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->telRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Tel.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->emlRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->Eml.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->Salutation.assign(ptr, PQgetlength(res, 0, fnum[16]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMPerson::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMPerson& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMPerson* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "refrorg"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "refjlastname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "eml"),
			PQfnumber(res, "salutation")
		};

		while (numread < numrow) {
			rec = new FmncMPerson();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWDerivate = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refROrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMAddress = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refJLastname = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->telRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Tel.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->emlRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->Eml.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->Salutation.assign(ptr, PQgetlength(res, numread, fnum[16]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMPerson::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMPerson** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPerson / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMPerson::loadRecBySQL(
			const string& sqlstr
			, FmncMPerson** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMPerson& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMPerson::insertRec(
			FmncMPerson* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	ubigint _refROrg = htonl64(rec->refROrg);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _refJLastname = htonl64(rec->refJLastname);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWDerivate,
		(char*) &_refROrg,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMAddress,
		(char*) &_ixVSex,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		(char*) &_refJLastname,
		rec->Lastname.c_str(),
		(char*) &_telRefADetail,
		rec->Tel.c_str(),
		(char*) &_emlRefADetail,
		rec->Eml.c_str(),
		rec->Salutation.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMPerson_insertRec", 16, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPerson_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMPerson::insertRst(
			ListFmncMPerson& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMPerson::updateRec(
			FmncMPerson* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	ubigint _refROrg = htonl64(rec->refROrg);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _refJLastname = htonl64(rec->refJLastname);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWDerivate,
		(char*) &_refROrg,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMAddress,
		(char*) &_ixVSex,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		(char*) &_refJLastname,
		rec->Lastname.c_str(),
		(char*) &_telRefADetail,
		rec->Tel.c_str(),
		(char*) &_emlRefADetail,
		rec->Eml.c_str(),
		rec->Salutation.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMPerson_updateRec", 17, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPerson_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMPerson::updateRst(
			ListFmncMPerson& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMPerson::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMPerson_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMPerson_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMPerson::loadRecByRef(
			ubigint ref
			, FmncMPerson** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMPerson_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

