/**
  * \file FmncQSepMNFile.cpp
  * Dbs and XML wrapper for table TblFmncQSepMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSepMNFile.h"

/******************************************************************************
 class FmncQSepMNFile
 ******************************************************************************/

FmncQSepMNFile::FmncQSepMNFile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const ubigint ref
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->stubsTrefFmncMSample = stubsTrefFmncMSample;
	this->ref = ref;
	this->ixVDir = ixVDir;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
};

void FmncQSepMNFile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQSepMNFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "tsmp", stubsTrefFmncMSample);
		writeString(wr, "dir", srefIxVDir);
		writeString(wr, "dir2", titIxVDir);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubsTrefFmncMSample", stubsTrefFmncMSample);
		writeString(wr, "srefIxVDir", srefIxVDir);
		writeString(wr, "titIxVDir", titIxVDir);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQSepMNFile
 ******************************************************************************/

ListFmncQSepMNFile::ListFmncQSepMNFile() {
};

ListFmncQSepMNFile::ListFmncQSepMNFile(
			const ListFmncQSepMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepMNFile(*(src.nodes[i]));
};

ListFmncQSepMNFile::~ListFmncQSepMNFile() {
	clear();
};

void ListFmncQSepMNFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQSepMNFile::size() const {
	return(nodes.size());
};

void ListFmncQSepMNFile::append(
			FmncQSepMNFile* rec
		) {
	nodes.push_back(rec);
};

ListFmncQSepMNFile& ListFmncQSepMNFile::operator=(
			const ListFmncQSepMNFile& src
		) {
	FmncQSepMNFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQSepMNFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQSepMNFile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQSepMNFile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQSepMNFile
 ******************************************************************************/

TblFmncQSepMNFile::TblFmncQSepMNFile() {
};

TblFmncQSepMNFile::~TblFmncQSepMNFile() {
};

bool TblFmncQSepMNFile::loadRecBySQL(
			const string& sqlstr
			, FmncQSepMNFile** rec
		) {
	return false;
};

ubigint TblFmncQSepMNFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	return 0;
};

void TblFmncQSepMNFile::insertRec(
			FmncQSepMNFile* rec
		) {
};

ubigint TblFmncQSepMNFile::insertNewRec(
			FmncQSepMNFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const ubigint ref
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
		) {
	ubigint retval = 0;
	FmncQSepMNFile* _rec = NULL;

	_rec = new FmncQSepMNFile(0, jref, jnum, mref, stubMref, stubsTrefFmncMSample, ref, ixVDir, srefIxVDir, titIxVDir);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQSepMNFile::appendNewRecToRst(
			ListFmncQSepMNFile& rst
			, FmncQSepMNFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const ubigint ref
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
		) {
	ubigint retval = 0;
	FmncQSepMNFile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, stubsTrefFmncMSample, ref, ixVDir, srefIxVDir, titIxVDir);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQSepMNFile::insertRst(
			ListFmncQSepMNFile& rst
		) {
};

void TblFmncQSepMNFile::updateRec(
			FmncQSepMNFile* rec
		) {
};

void TblFmncQSepMNFile::updateRst(
			ListFmncQSepMNFile& rst
		) {
};

void TblFmncQSepMNFile::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQSepMNFile::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQSepMNFile::loadRecByQref(
			ubigint qref
			, FmncQSepMNFile** rec
		) {
	return false;
};

ubigint TblFmncQSepMNFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQSepMNFile
 ******************************************************************************/

MyTblFmncQSepMNFile::MyTblFmncQSepMNFile() : TblFmncQSepMNFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQSepMNFile::~MyTblFmncQSepMNFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQSepMNFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQSepMNFile (jref, jnum, mref, ref, ixVDir) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQSepMNFile SET jref = ?, jnum = ?, mref = ?, ref = ?, ixVDir = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQSepMNFile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQSepMNFile WHERE jref = ?", false);
};

bool MyTblFmncQSepMNFile::loadRecBySQL(
			const string& sqlstr
			, FmncQSepMNFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQSepMNFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSepMNFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQSepMNFile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixVDir = atol((char*) dbrow[5]); else _rec->ixVDir = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQSepMNFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQSepMNFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQSepMNFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQSepMNFile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixVDir = atol((char*) dbrow[5]); else rec->ixVDir = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQSepMNFile::insertRec(
			FmncQSepMNFile* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVDir,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepMNFile / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepMNFile / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQSepMNFile::insertRst(
			ListFmncQSepMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQSepMNFile::updateRec(
			FmncQSepMNFile* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVDir,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepMNFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepMNFile / stmtUpdateRec)\n");
};

void MyTblFmncQSepMNFile::updateRst(
			ListFmncQSepMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQSepMNFile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepMNFile / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepMNFile / stmtRemoveRecByQref)\n");
};

void MyTblFmncQSepMNFile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQSepMNFile / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQSepMNFile / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQSepMNFile::loadRecByQref(
			ubigint qref
			, FmncQSepMNFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQSepMNFile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQSepMNFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQSepMNFile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQSepMNFile
 ******************************************************************************/

PgTblFmncQSepMNFile::PgTblFmncQSepMNFile() : TblFmncQSepMNFile(), PgTable() {
};

PgTblFmncQSepMNFile::~PgTblFmncQSepMNFile() {
};

void PgTblFmncQSepMNFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQSepMNFile_insertRec", "INSERT INTO TblFmncQSepMNFile (jref, jnum, mref, ref, ixVDir) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepMNFile_updateRec", "UPDATE TblFmncQSepMNFile SET jref = $1, jnum = $2, mref = $3, ref = $4, ixVDir = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepMNFile_removeRecByQref", "DELETE FROM TblFmncQSepMNFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepMNFile_removeRstByJref", "DELETE FROM TblFmncQSepMNFile WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQSepMNFile_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixVDir FROM TblFmncQSepMNFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQSepMNFile_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixVDir FROM TblFmncQSepMNFile WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQSepMNFile::loadRec(
			PGresult* res
			, FmncQSepMNFile** rec
		) {
	char* ptr;

	FmncQSepMNFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQSepMNFile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvdir")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVDir = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQSepMNFile::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQSepMNFile* rec;

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
			PQfnumber(res, "ixvdir")
		};

		while (numread < numrow) {
			rec = new FmncQSepMNFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVDir = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQSepMNFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQSepMNFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepMNFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSepMNFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepMNFile / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQSepMNFile::loadRecBySQL(
			const string& sqlstr
			, FmncQSepMNFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQSepMNFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQSepMNFile::insertRec(
			FmncQSepMNFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVDir = htonl(rec->ixVDir);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixVDir
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQSepMNFile_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepMNFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQSepMNFile::insertRst(
			ListFmncQSepMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQSepMNFile::updateRec(
			FmncQSepMNFile* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVDir = htonl(rec->ixVDir);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixVDir,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncQSepMNFile_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepMNFile_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQSepMNFile::updateRst(
			ListFmncQSepMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQSepMNFile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQSepMNFile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepMNFile_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQSepMNFile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQSepMNFile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQSepMNFile_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQSepMNFile::loadRecByQref(
			ubigint qref
			, FmncQSepMNFile** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQSepMNFile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQSepMNFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQSepMNFile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQSepMNFile_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

