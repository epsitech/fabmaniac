/**
  * \file FmncQArtMNOrg.cpp
  * Dbs and XML wrapper for table TblFmncQArtMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQArtMNOrg.h"

/******************************************************************************
 class FmncQArtMNOrg
 ******************************************************************************/

FmncQArtMNOrg::FmncQArtMNOrg(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string Itemno
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->Itemno = Itemno;
};

void FmncQArtMNOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQArtMNOrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "itn", Itemno);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "Itemno", Itemno);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQArtMNOrg
 ******************************************************************************/

ListFmncQArtMNOrg::ListFmncQArtMNOrg() {
};

ListFmncQArtMNOrg::ListFmncQArtMNOrg(
			const ListFmncQArtMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArtMNOrg(*(src.nodes[i]));
};

ListFmncQArtMNOrg::~ListFmncQArtMNOrg() {
	clear();
};

void ListFmncQArtMNOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQArtMNOrg::size() const {
	return(nodes.size());
};

void ListFmncQArtMNOrg::append(
			FmncQArtMNOrg* rec
		) {
	nodes.push_back(rec);
};

ListFmncQArtMNOrg& ListFmncQArtMNOrg::operator=(
			const ListFmncQArtMNOrg& src
		) {
	FmncQArtMNOrg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQArtMNOrg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQArtMNOrg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQArtMNOrg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQArtMNOrg
 ******************************************************************************/

TblFmncQArtMNOrg::TblFmncQArtMNOrg() {
};

TblFmncQArtMNOrg::~TblFmncQArtMNOrg() {
};

bool TblFmncQArtMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQArtMNOrg** rec
		) {
	return false;
};

ubigint TblFmncQArtMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	return 0;
};

void TblFmncQArtMNOrg::insertRec(
			FmncQArtMNOrg* rec
		) {
};

ubigint TblFmncQArtMNOrg::insertNewRec(
			FmncQArtMNOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string Itemno
		) {
	ubigint retval = 0;
	FmncQArtMNOrg* _rec = NULL;

	_rec = new FmncQArtMNOrg(0, jref, jnum, mref, stubMref, ref, Itemno);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQArtMNOrg::appendNewRecToRst(
			ListFmncQArtMNOrg& rst
			, FmncQArtMNOrg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string Itemno
		) {
	ubigint retval = 0;
	FmncQArtMNOrg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, Itemno);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQArtMNOrg::insertRst(
			ListFmncQArtMNOrg& rst
		) {
};

void TblFmncQArtMNOrg::updateRec(
			FmncQArtMNOrg* rec
		) {
};

void TblFmncQArtMNOrg::updateRst(
			ListFmncQArtMNOrg& rst
		) {
};

void TblFmncQArtMNOrg::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQArtMNOrg::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQArtMNOrg::loadRecByQref(
			ubigint qref
			, FmncQArtMNOrg** rec
		) {
	return false;
};

ubigint TblFmncQArtMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQArtMNOrg
 ******************************************************************************/

MyTblFmncQArtMNOrg::MyTblFmncQArtMNOrg() : TblFmncQArtMNOrg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQArtMNOrg::~MyTblFmncQArtMNOrg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQArtMNOrg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQArtMNOrg (jref, jnum, mref, ref, Itemno) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQArtMNOrg SET jref = ?, jnum = ?, mref = ?, ref = ?, Itemno = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQArtMNOrg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQArtMNOrg WHERE jref = ?", false);
};

bool MyTblFmncQArtMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQArtMNOrg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQArtMNOrg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQArtMNOrg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQArtMNOrg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->Itemno.assign(dbrow[5], dblengths[5]); else _rec->Itemno = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQArtMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQArtMNOrg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQArtMNOrg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQArtMNOrg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->Itemno.assign(dbrow[5], dblengths[5]); else rec->Itemno = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQArtMNOrg::insertRec(
			FmncQArtMNOrg* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Itemno.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtMNOrg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtMNOrg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQArtMNOrg::insertRst(
			ListFmncQArtMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQArtMNOrg::updateRec(
			FmncQArtMNOrg* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Itemno.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtMNOrg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtMNOrg / stmtUpdateRec)\n");
};

void MyTblFmncQArtMNOrg::updateRst(
			ListFmncQArtMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQArtMNOrg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtMNOrg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtMNOrg / stmtRemoveRecByQref)\n");
};

void MyTblFmncQArtMNOrg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQArtMNOrg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQArtMNOrg / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQArtMNOrg::loadRecByQref(
			ubigint qref
			, FmncQArtMNOrg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQArtMNOrg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQArtMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQArtMNOrg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQArtMNOrg
 ******************************************************************************/

PgTblFmncQArtMNOrg::PgTblFmncQArtMNOrg() : TblFmncQArtMNOrg(), PgTable() {
};

PgTblFmncQArtMNOrg::~PgTblFmncQArtMNOrg() {
};

void PgTblFmncQArtMNOrg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQArtMNOrg_insertRec", "INSERT INTO TblFmncQArtMNOrg (jref, jnum, mref, ref, Itemno) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtMNOrg_updateRec", "UPDATE TblFmncQArtMNOrg SET jref = $1, jnum = $2, mref = $3, ref = $4, Itemno = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtMNOrg_removeRecByQref", "DELETE FROM TblFmncQArtMNOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtMNOrg_removeRstByJref", "DELETE FROM TblFmncQArtMNOrg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQArtMNOrg_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, Itemno FROM TblFmncQArtMNOrg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQArtMNOrg_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, Itemno FROM TblFmncQArtMNOrg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQArtMNOrg::loadRec(
			PGresult* res
			, FmncQArtMNOrg** rec
		) {
	char* ptr;

	FmncQArtMNOrg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQArtMNOrg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "itemno")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Itemno.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQArtMNOrg::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQArtMNOrg* rec;

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
			PQfnumber(res, "itemno")
		};

		while (numread < numrow) {
			rec = new FmncQArtMNOrg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Itemno.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQArtMNOrg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQArtMNOrg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtMNOrg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQArtMNOrg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtMNOrg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQArtMNOrg::loadRecBySQL(
			const string& sqlstr
			, FmncQArtMNOrg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQArtMNOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQArtMNOrg::insertRec(
			FmncQArtMNOrg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->Itemno.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncQArtMNOrg_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtMNOrg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQArtMNOrg::insertRst(
			ListFmncQArtMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQArtMNOrg::updateRec(
			FmncQArtMNOrg* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->Itemno.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQArtMNOrg_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtMNOrg_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQArtMNOrg::updateRst(
			ListFmncQArtMNOrg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQArtMNOrg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQArtMNOrg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtMNOrg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQArtMNOrg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQArtMNOrg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQArtMNOrg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQArtMNOrg::loadRecByQref(
			ubigint qref
			, FmncQArtMNOrg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQArtMNOrg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQArtMNOrg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQArtMNOrg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQArtMNOrg_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

