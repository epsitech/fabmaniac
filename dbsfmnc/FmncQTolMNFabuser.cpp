/**
  * \file FmncQTolMNFabuser.cpp
  * Dbs and XML wrapper for table TblFmncQTolMNFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolMNFabuser.h"

/******************************************************************************
 class FmncQTolMNFabuser
 ******************************************************************************/

FmncQTolMNFabuser::FmncQTolMNFabuser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint trnRefFmncMPerson
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->trnRefFmncMPerson = trnRefFmncMPerson;
	this->stubTrnRefFmncMPerson = stubTrnRefFmncMPerson;
	this->srefKLvl = srefKLvl;
	this->titSrefKLvl = titSrefKLvl;
};

void FmncQTolMNFabuser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolMNFabuser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "trn", stubTrnRefFmncMPerson);
		writeString(wr, "lvl", srefKLvl);
		writeString(wr, "lvl2", titSrefKLvl);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubTrnRefFmncMPerson", stubTrnRefFmncMPerson);
		writeString(wr, "srefKLvl", srefKLvl);
		writeString(wr, "titSrefKLvl", titSrefKLvl);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolMNFabuser
 ******************************************************************************/

ListFmncQTolMNFabuser::ListFmncQTolMNFabuser() {
};

ListFmncQTolMNFabuser::ListFmncQTolMNFabuser(
			const ListFmncQTolMNFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolMNFabuser(*(src.nodes[i]));
};

ListFmncQTolMNFabuser::~ListFmncQTolMNFabuser() {
	clear();
};

void ListFmncQTolMNFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolMNFabuser::size() const {
	return(nodes.size());
};

void ListFmncQTolMNFabuser::append(
			FmncQTolMNFabuser* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolMNFabuser& ListFmncQTolMNFabuser::operator=(
			const ListFmncQTolMNFabuser& src
		) {
	FmncQTolMNFabuser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolMNFabuser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolMNFabuser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolMNFabuser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolMNFabuser
 ******************************************************************************/

TblFmncQTolMNFabuser::TblFmncQTolMNFabuser() {
};

TblFmncQTolMNFabuser::~TblFmncQTolMNFabuser() {
};

bool TblFmncQTolMNFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncQTolMNFabuser** rec
		) {
	return false;
};

ubigint TblFmncQTolMNFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	return 0;
};

void TblFmncQTolMNFabuser::insertRec(
			FmncQTolMNFabuser* rec
		) {
};

ubigint TblFmncQTolMNFabuser::insertNewRec(
			FmncQTolMNFabuser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint trnRefFmncMPerson
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	ubigint retval = 0;
	FmncQTolMNFabuser* _rec = NULL;

	_rec = new FmncQTolMNFabuser(0, jref, jnum, mref, stubMref, ref, trnRefFmncMPerson, stubTrnRefFmncMPerson, srefKLvl, titSrefKLvl);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolMNFabuser::appendNewRecToRst(
			ListFmncQTolMNFabuser& rst
			, FmncQTolMNFabuser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint trnRefFmncMPerson
			, const string stubTrnRefFmncMPerson
			, const string srefKLvl
			, const string titSrefKLvl
		) {
	ubigint retval = 0;
	FmncQTolMNFabuser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, trnRefFmncMPerson, stubTrnRefFmncMPerson, srefKLvl, titSrefKLvl);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolMNFabuser::insertRst(
			ListFmncQTolMNFabuser& rst
		) {
};

void TblFmncQTolMNFabuser::updateRec(
			FmncQTolMNFabuser* rec
		) {
};

void TblFmncQTolMNFabuser::updateRst(
			ListFmncQTolMNFabuser& rst
		) {
};

void TblFmncQTolMNFabuser::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolMNFabuser::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolMNFabuser::loadRecByQref(
			ubigint qref
			, FmncQTolMNFabuser** rec
		) {
	return false;
};

ubigint TblFmncQTolMNFabuser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolMNFabuser
 ******************************************************************************/

MyTblFmncQTolMNFabuser::MyTblFmncQTolMNFabuser() : TblFmncQTolMNFabuser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolMNFabuser::~MyTblFmncQTolMNFabuser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolMNFabuser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolMNFabuser (jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolMNFabuser SET jref = ?, jnum = ?, mref = ?, ref = ?, trnRefFmncMPerson = ?, srefKLvl = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolMNFabuser WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolMNFabuser WHERE jref = ?", false);
};

bool MyTblFmncQTolMNFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncQTolMNFabuser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolMNFabuser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolMNFabuser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolMNFabuser();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->trnRefFmncMPerson = atoll((char*) dbrow[5]); else _rec->trnRefFmncMPerson = 0;
		if (dbrow[6]) _rec->srefKLvl.assign(dbrow[6], dblengths[6]); else _rec->srefKLvl = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolMNFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolMNFabuser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolMNFabuser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolMNFabuser();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->trnRefFmncMPerson = atoll((char*) dbrow[5]); else rec->trnRefFmncMPerson = 0;
			if (dbrow[6]) rec->srefKLvl.assign(dbrow[6], dblengths[6]); else rec->srefKLvl = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolMNFabuser::insertRec(
			FmncQTolMNFabuser* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->srefKLvl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->trnRefFmncMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefKLvl.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNFabuser / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNFabuser / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolMNFabuser::insertRst(
			ListFmncQTolMNFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolMNFabuser::updateRec(
			FmncQTolMNFabuser* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->srefKLvl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->trnRefFmncMPerson,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->srefKLvl.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNFabuser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNFabuser / stmtUpdateRec)\n");
};

void MyTblFmncQTolMNFabuser::updateRst(
			ListFmncQTolMNFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolMNFabuser::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNFabuser / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNFabuser / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolMNFabuser::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNFabuser / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNFabuser / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolMNFabuser::loadRecByQref(
			ubigint qref
			, FmncQTolMNFabuser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolMNFabuser WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolMNFabuser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolMNFabuser WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolMNFabuser
 ******************************************************************************/

PgTblFmncQTolMNFabuser::PgTblFmncQTolMNFabuser() : TblFmncQTolMNFabuser(), PgTable() {
};

PgTblFmncQTolMNFabuser::~PgTblFmncQTolMNFabuser() {
};

void PgTblFmncQTolMNFabuser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolMNFabuser_insertRec", "INSERT INTO TblFmncQTolMNFabuser (jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNFabuser_updateRec", "UPDATE TblFmncQTolMNFabuser SET jref = $1, jnum = $2, mref = $3, ref = $4, trnRefFmncMPerson = $5, srefKLvl = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNFabuser_removeRecByQref", "DELETE FROM TblFmncQTolMNFabuser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNFabuser_removeRstByJref", "DELETE FROM TblFmncQTolMNFabuser WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolMNFabuser_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl FROM TblFmncQTolMNFabuser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNFabuser_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, trnRefFmncMPerson, srefKLvl FROM TblFmncQTolMNFabuser WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolMNFabuser::loadRec(
			PGresult* res
			, FmncQTolMNFabuser** rec
		) {
	char* ptr;

	FmncQTolMNFabuser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolMNFabuser();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "trnreffmncmperson"),
			PQfnumber(res, "srefklvl")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->trnRefFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefKLvl.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolMNFabuser::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolMNFabuser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "trnreffmncmperson"),
			PQfnumber(res, "srefklvl")
		};

		while (numread < numrow) {
			rec = new FmncQTolMNFabuser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->trnRefFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefKLvl.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolMNFabuser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolMNFabuser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNFabuser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolMNFabuser::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNFabuser / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolMNFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncQTolMNFabuser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolMNFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolMNFabuser::insertRec(
			FmncQTolMNFabuser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _trnRefFmncMPerson = htonl64(rec->trnRefFmncMPerson);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_trnRefFmncMPerson,
		rec->srefKLvl.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolMNFabuser_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNFabuser_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolMNFabuser::insertRst(
			ListFmncQTolMNFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolMNFabuser::updateRec(
			FmncQTolMNFabuser* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _trnRefFmncMPerson = htonl64(rec->trnRefFmncMPerson);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_trnRefFmncMPerson,
		rec->srefKLvl.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolMNFabuser_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNFabuser_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolMNFabuser::updateRst(
			ListFmncQTolMNFabuser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolMNFabuser::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolMNFabuser_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNFabuser_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolMNFabuser::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolMNFabuser_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNFabuser_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolMNFabuser::loadRecByQref(
			ubigint qref
			, FmncQTolMNFabuser** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolMNFabuser_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolMNFabuser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolMNFabuser& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolMNFabuser_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

