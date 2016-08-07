/**
  * \file FmncQPrsList.cpp
  * Dbs and XML wrapper for table TblFmncQPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrsList.h"

/******************************************************************************
 class FmncQPrsList
 ******************************************************************************/

FmncQPrsList::FmncQPrsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMAddress
			, const string stubRefFmncMAddress
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refFmncMOrg = refFmncMOrg;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
	this->refFmncMAddress = refFmncMAddress;
	this->stubRefFmncMAddress = stubRefFmncMAddress;
	this->ixVSex = ixVSex;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->Tel = Tel;
	this->Eml = Eml;
};

void FmncQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "fnm", Firstname);
		writeString(wr, "lnm", Lastname);
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "org", stubRefFmncMOrg);
		writeString(wr, "adr", stubRefFmncMAddress);
		writeString(wr, "sex", srefIxVSex);
		writeString(wr, "sex2", titIxVSex);
		writeString(wr, "tel", Tel);
		writeString(wr, "eml", Eml);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "Firstname", Firstname);
		writeString(wr, "Lastname", Lastname);
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefFmncMOrg", stubRefFmncMOrg);
		writeString(wr, "stubRefFmncMAddress", stubRefFmncMAddress);
		writeString(wr, "srefIxVSex", srefIxVSex);
		writeString(wr, "titIxVSex", titIxVSex);
		writeString(wr, "Tel", Tel);
		writeString(wr, "Eml", Eml);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQPrsList
 ******************************************************************************/

ListFmncQPrsList::ListFmncQPrsList() {
};

ListFmncQPrsList::ListFmncQPrsList(
			const ListFmncQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsList(*(src.nodes[i]));
};

ListFmncQPrsList::~ListFmncQPrsList() {
	clear();
};

void ListFmncQPrsList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQPrsList::size() const {
	return(nodes.size());
};

void ListFmncQPrsList::append(
			FmncQPrsList* rec
		) {
	nodes.push_back(rec);
};

ListFmncQPrsList& ListFmncQPrsList::operator=(
			const ListFmncQPrsList& src
		) {
	FmncQPrsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQPrsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQPrsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQPrsList
 ******************************************************************************/

TblFmncQPrsList::TblFmncQPrsList() {
};

TblFmncQPrsList::~TblFmncQPrsList() {
};

bool TblFmncQPrsList::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsList** rec
		) {
	return false;
};

ubigint TblFmncQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsList& rst
		) {
	return 0;
};

void TblFmncQPrsList::insertRec(
			FmncQPrsList* rec
		) {
};

ubigint TblFmncQPrsList::insertNewRec(
			FmncQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMAddress
			, const string stubRefFmncMAddress
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	ubigint retval = 0;
	FmncQPrsList* _rec = NULL;

	_rec = new FmncQPrsList(0, jref, jnum, ref, Title, Firstname, Lastname, grp, stubGrp, own, stubOwn, refFmncMOrg, stubRefFmncMOrg, refFmncMAddress, stubRefFmncMAddress, ixVSex, srefIxVSex, titIxVSex, Tel, Eml);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQPrsList::appendNewRecToRst(
			ListFmncQPrsList& rst
			, FmncQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refFmncMOrg
			, const string stubRefFmncMOrg
			, const ubigint refFmncMAddress
			, const string stubRefFmncMAddress
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	ubigint retval = 0;
	FmncQPrsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, Firstname, Lastname, grp, stubGrp, own, stubOwn, refFmncMOrg, stubRefFmncMOrg, refFmncMAddress, stubRefFmncMAddress, ixVSex, srefIxVSex, titIxVSex, Tel, Eml);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQPrsList::insertRst(
			ListFmncQPrsList& rst
		) {
};

void TblFmncQPrsList::updateRec(
			FmncQPrsList* rec
		) {
};

void TblFmncQPrsList::updateRst(
			ListFmncQPrsList& rst
		) {
};

void TblFmncQPrsList::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQPrsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQPrsList::loadRecByQref(
			ubigint qref
			, FmncQPrsList** rec
		) {
	return false;
};

ubigint TblFmncQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQPrsList
 ******************************************************************************/

MyTblFmncQPrsList::MyTblFmncQPrsList() : TblFmncQPrsList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQPrsList::~MyTblFmncQPrsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQPrsList (jref, jnum, ref, Title, Firstname, Lastname, grp, own, refFmncMOrg, refFmncMAddress, ixVSex, Tel, Eml) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQPrsList SET jref = ?, jnum = ?, ref = ?, Title = ?, Firstname = ?, Lastname = ?, grp = ?, own = ?, refFmncMOrg = ?, refFmncMAddress = ?, ixVSex = ?, Tel = ?, Eml = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQPrsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQPrsList WHERE jref = ?", false);
};

bool MyTblFmncQPrsList::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQPrsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPrsList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQPrsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->Firstname.assign(dbrow[5], dblengths[5]); else _rec->Firstname = "";
		if (dbrow[6]) _rec->Lastname.assign(dbrow[6], dblengths[6]); else _rec->Lastname = "";
		if (dbrow[7]) _rec->grp = atoll((char*) dbrow[7]); else _rec->grp = 0;
		if (dbrow[8]) _rec->own = atoll((char*) dbrow[8]); else _rec->own = 0;
		if (dbrow[9]) _rec->refFmncMOrg = atoll((char*) dbrow[9]); else _rec->refFmncMOrg = 0;
		if (dbrow[10]) _rec->refFmncMAddress = atoll((char*) dbrow[10]); else _rec->refFmncMAddress = 0;
		if (dbrow[11]) _rec->ixVSex = atol((char*) dbrow[11]); else _rec->ixVSex = 0;
		if (dbrow[12]) _rec->Tel.assign(dbrow[12], dblengths[12]); else _rec->Tel = "";
		if (dbrow[13]) _rec->Eml.assign(dbrow[13], dblengths[13]); else _rec->Eml = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQPrsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPrsList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQPrsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->Firstname.assign(dbrow[5], dblengths[5]); else rec->Firstname = "";
			if (dbrow[6]) rec->Lastname.assign(dbrow[6], dblengths[6]); else rec->Lastname = "";
			if (dbrow[7]) rec->grp = atoll((char*) dbrow[7]); else rec->grp = 0;
			if (dbrow[8]) rec->own = atoll((char*) dbrow[8]); else rec->own = 0;
			if (dbrow[9]) rec->refFmncMOrg = atoll((char*) dbrow[9]); else rec->refFmncMOrg = 0;
			if (dbrow[10]) rec->refFmncMAddress = atoll((char*) dbrow[10]); else rec->refFmncMAddress = 0;
			if (dbrow[11]) rec->ixVSex = atol((char*) dbrow[11]); else rec->ixVSex = 0;
			if (dbrow[12]) rec->Tel.assign(dbrow[12], dblengths[12]); else rec->Tel = "";
			if (dbrow[13]) rec->Eml.assign(dbrow[13], dblengths[13]); else rec->Eml = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQPrsList::insertRec(
			FmncQPrsList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->Title.length();
	l[4] = rec->Firstname.length();
	l[5] = rec->Lastname.length();
	l[11] = rec->Tel.length();
	l[12] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->grp,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->own,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refFmncMOrg,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refFmncMAddress,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVSex,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Tel.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Eml.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQPrsList::insertRst(
			ListFmncQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQPrsList::updateRec(
			FmncQPrsList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->Title.length();
	l[4] = rec->Firstname.length();
	l[5] = rec->Lastname.length();
	l[11] = rec->Tel.length();
	l[12] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Firstname.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Lastname.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->grp,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->own,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refFmncMOrg,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->refFmncMAddress,&(l[9]),&(n[9]),&(e[9])), 
		bindUint(&rec->ixVSex,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->Tel.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindCstring((char*) (rec->Eml.c_str()),&(l[12]),&(n[12]),&(e[12])), 
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsList / stmtUpdateRec)\n");
};

void MyTblFmncQPrsList::updateRst(
			ListFmncQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQPrsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsList / stmtRemoveRecByQref)\n");
};

void MyTblFmncQPrsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPrsList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPrsList / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQPrsList::loadRecByQref(
			ubigint qref
			, FmncQPrsList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQPrsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQPrsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQPrsList
 ******************************************************************************/

PgTblFmncQPrsList::PgTblFmncQPrsList() : TblFmncQPrsList(), PgTable() {
};

PgTblFmncQPrsList::~PgTblFmncQPrsList() {
};

void PgTblFmncQPrsList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQPrsList_insertRec", "INSERT INTO TblFmncQPrsList (jref, jnum, ref, Title, Firstname, Lastname, grp, own, refFmncMOrg, refFmncMAddress, ixVSex, Tel, Eml) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsList_updateRec", "UPDATE TblFmncQPrsList SET jref = $1, jnum = $2, ref = $3, Title = $4, Firstname = $5, Lastname = $6, grp = $7, own = $8, refFmncMOrg = $9, refFmncMAddress = $10, ixVSex = $11, Tel = $12, Eml = $13 WHERE qref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsList_removeRecByQref", "DELETE FROM TblFmncQPrsList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsList_removeRstByJref", "DELETE FROM TblFmncQPrsList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQPrsList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, Firstname, Lastname, grp, own, refFmncMOrg, refFmncMAddress, ixVSex, Tel, Eml FROM TblFmncQPrsList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPrsList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, Firstname, Lastname, grp, own, refFmncMOrg, refFmncMAddress, ixVSex, Tel, Eml FROM TblFmncQPrsList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQPrsList::loadRec(
			PGresult* res
			, FmncQPrsList** rec
		) {
	char* ptr;

	FmncQPrsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQPrsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "eml")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refFmncMAddress = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Tel.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Eml.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQPrsList::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQPrsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQPrsList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmaddress"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "eml")
		};

		while (numread < numrow) {
			rec = new FmncQPrsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refFmncMAddress = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Tel.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Eml.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQPrsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQPrsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPrsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQPrsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQPrsList::loadRecBySQL(
			const string& sqlstr
			, FmncQPrsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPrsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQPrsList::insertRec(
			FmncQPrsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	uint _ixVSex = htonl(rec->ixVSex);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMAddress,
		(char*) &_ixVSex,
		rec->Tel.c_str(),
		rec->Eml.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQPrsList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQPrsList::insertRst(
			ListFmncQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQPrsList::updateRec(
			FmncQPrsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMAddress = htonl64(rec->refFmncMAddress);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMAddress,
		(char*) &_ixVSex,
		rec->Tel.c_str(),
		rec->Eml.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQPrsList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsList_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQPrsList::updateRst(
			ListFmncQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQPrsList::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncQPrsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQPrsList::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncQPrsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPrsList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQPrsList::loadRecByQref(
			ubigint qref
			, FmncQPrsList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQPrsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPrsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQPrsList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

