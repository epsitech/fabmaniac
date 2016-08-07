/**
  * \file FmncQStpRef1NFile.cpp
  * Dbs and XML wrapper for table TblFmncQStpRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQStpRef1NFile.h"

/******************************************************************************
 class FmncQStpRef1NFile
 ******************************************************************************/

FmncQStpRef1NFile::FmncQStpRef1NFile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void FmncQStpRef1NFile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQStpRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQStpRef1NFile
 ******************************************************************************/

ListFmncQStpRef1NFile::ListFmncQStpRef1NFile() {
};

ListFmncQStpRef1NFile::ListFmncQStpRef1NFile(
			const ListFmncQStpRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpRef1NFile(*(src.nodes[i]));
};

ListFmncQStpRef1NFile::~ListFmncQStpRef1NFile() {
	clear();
};

void ListFmncQStpRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQStpRef1NFile::size() const {
	return(nodes.size());
};

void ListFmncQStpRef1NFile::append(
			FmncQStpRef1NFile* rec
		) {
	nodes.push_back(rec);
};

ListFmncQStpRef1NFile& ListFmncQStpRef1NFile::operator=(
			const ListFmncQStpRef1NFile& src
		) {
	FmncQStpRef1NFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQStpRef1NFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQStpRef1NFile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQStpRef1NFile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQStpRef1NFile
 ******************************************************************************/

TblFmncQStpRef1NFile::TblFmncQStpRef1NFile() {
};

TblFmncQStpRef1NFile::~TblFmncQStpRef1NFile() {
};

bool TblFmncQStpRef1NFile::loadRecBySQL(
			const string& sqlstr
			, FmncQStpRef1NFile** rec
		) {
	return false;
};

ubigint TblFmncQStpRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	return 0;
};

void TblFmncQStpRef1NFile::insertRec(
			FmncQStpRef1NFile* rec
		) {
};

ubigint TblFmncQStpRef1NFile::insertNewRec(
			FmncQStpRef1NFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQStpRef1NFile* _rec = NULL;

	_rec = new FmncQStpRef1NFile(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQStpRef1NFile::appendNewRecToRst(
			ListFmncQStpRef1NFile& rst
			, FmncQStpRef1NFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	FmncQStpRef1NFile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQStpRef1NFile::insertRst(
			ListFmncQStpRef1NFile& rst
		) {
};

void TblFmncQStpRef1NFile::updateRec(
			FmncQStpRef1NFile* rec
		) {
};

void TblFmncQStpRef1NFile::updateRst(
			ListFmncQStpRef1NFile& rst
		) {
};

void TblFmncQStpRef1NFile::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQStpRef1NFile::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQStpRef1NFile::loadRecByQref(
			ubigint qref
			, FmncQStpRef1NFile** rec
		) {
	return false;
};

ubigint TblFmncQStpRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQStpRef1NFile
 ******************************************************************************/

MyTblFmncQStpRef1NFile::MyTblFmncQStpRef1NFile() : TblFmncQStpRef1NFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQStpRef1NFile::~MyTblFmncQStpRef1NFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQStpRef1NFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQStpRef1NFile (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQStpRef1NFile SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQStpRef1NFile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQStpRef1NFile WHERE jref = ?", false);
};

bool MyTblFmncQStpRef1NFile::loadRecBySQL(
			const string& sqlstr
			, FmncQStpRef1NFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQStpRef1NFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQStpRef1NFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQStpRef1NFile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQStpRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQStpRef1NFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQStpRef1NFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQStpRef1NFile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQStpRef1NFile::insertRec(
			FmncQStpRef1NFile* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpRef1NFile / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpRef1NFile / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQStpRef1NFile::insertRst(
			ListFmncQStpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQStpRef1NFile::updateRec(
			FmncQStpRef1NFile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpRef1NFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpRef1NFile / stmtUpdateRec)\n");
};

void MyTblFmncQStpRef1NFile::updateRst(
			ListFmncQStpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQStpRef1NFile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpRef1NFile / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpRef1NFile / stmtRemoveRecByQref)\n");
};

void MyTblFmncQStpRef1NFile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQStpRef1NFile / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQStpRef1NFile / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQStpRef1NFile::loadRecByQref(
			ubigint qref
			, FmncQStpRef1NFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQStpRef1NFile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQStpRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQStpRef1NFile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQStpRef1NFile
 ******************************************************************************/

PgTblFmncQStpRef1NFile::PgTblFmncQStpRef1NFile() : TblFmncQStpRef1NFile(), PgTable() {
};

PgTblFmncQStpRef1NFile::~PgTblFmncQStpRef1NFile() {
};

void PgTblFmncQStpRef1NFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQStpRef1NFile_insertRec", "INSERT INTO TblFmncQStpRef1NFile (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpRef1NFile_updateRec", "UPDATE TblFmncQStpRef1NFile SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpRef1NFile_removeRecByQref", "DELETE FROM TblFmncQStpRef1NFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpRef1NFile_removeRstByJref", "DELETE FROM TblFmncQStpRef1NFile WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQStpRef1NFile_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblFmncQStpRef1NFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQStpRef1NFile_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblFmncQStpRef1NFile WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQStpRef1NFile::loadRec(
			PGresult* res
			, FmncQStpRef1NFile** rec
		) {
	char* ptr;

	FmncQStpRef1NFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQStpRef1NFile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQStpRef1NFile::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQStpRef1NFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new FmncQStpRef1NFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQStpRef1NFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQStpRef1NFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpRef1NFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQStpRef1NFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpRef1NFile / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQStpRef1NFile::loadRecBySQL(
			const string& sqlstr
			, FmncQStpRef1NFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQStpRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQStpRef1NFile::insertRec(
			FmncQStpRef1NFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQStpRef1NFile_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpRef1NFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQStpRef1NFile::insertRst(
			ListFmncQStpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQStpRef1NFile::updateRec(
			FmncQStpRef1NFile* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQStpRef1NFile_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpRef1NFile_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQStpRef1NFile::updateRst(
			ListFmncQStpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQStpRef1NFile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQStpRef1NFile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpRef1NFile_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQStpRef1NFile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQStpRef1NFile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQStpRef1NFile_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQStpRef1NFile::loadRecByQref(
			ubigint qref
			, FmncQStpRef1NFile** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQStpRef1NFile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQStpRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQStpRef1NFile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQStpRef1NFile_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

