/**
  * \file FmncQTolMNTooltype.cpp
  * Dbs and XML wrapper for table TblFmncQTolMNTooltype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolMNTooltype.h"

/******************************************************************************
 class FmncQTolMNTooltype
 ******************************************************************************/

FmncQTolMNTooltype::FmncQTolMNTooltype(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefsFmncKToolchar
			, const string titsSrefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string titsDefSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
			, const string titsOptSrefsFmncKSteppar
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->srefsFmncKToolchar = srefsFmncKToolchar;
	this->titsSrefsFmncKToolchar = titsSrefsFmncKToolchar;
	this->defSrefsFmncKSteppar = defSrefsFmncKSteppar;
	this->titsDefSrefsFmncKSteppar = titsDefSrefsFmncKSteppar;
	this->optSrefsFmncKSteppar = optSrefsFmncKSteppar;
	this->titsOptSrefsFmncKSteppar = titsOptSrefsFmncKSteppar;
};

void FmncQTolMNTooltype::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTolMNTooltype";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "tch", srefsFmncKToolchar);
		writeString(wr, "tch2", titsSrefsFmncKToolchar);
		writeString(wr, "def", defSrefsFmncKSteppar);
		writeString(wr, "def2", titsDefSrefsFmncKSteppar);
		writeString(wr, "opt", optSrefsFmncKSteppar);
		writeString(wr, "opt2", titsOptSrefsFmncKSteppar);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefsFmncKToolchar", srefsFmncKToolchar);
		writeString(wr, "titsSrefsFmncKToolchar", titsSrefsFmncKToolchar);
		writeString(wr, "defSrefsFmncKSteppar", defSrefsFmncKSteppar);
		writeString(wr, "titsDefSrefsFmncKSteppar", titsDefSrefsFmncKSteppar);
		writeString(wr, "optSrefsFmncKSteppar", optSrefsFmncKSteppar);
		writeString(wr, "titsOptSrefsFmncKSteppar", titsOptSrefsFmncKSteppar);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQTolMNTooltype
 ******************************************************************************/

ListFmncQTolMNTooltype::ListFmncQTolMNTooltype() {
};

ListFmncQTolMNTooltype::ListFmncQTolMNTooltype(
			const ListFmncQTolMNTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolMNTooltype(*(src.nodes[i]));
};

ListFmncQTolMNTooltype::~ListFmncQTolMNTooltype() {
	clear();
};

void ListFmncQTolMNTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTolMNTooltype::size() const {
	return(nodes.size());
};

void ListFmncQTolMNTooltype::append(
			FmncQTolMNTooltype* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTolMNTooltype& ListFmncQTolMNTooltype::operator=(
			const ListFmncQTolMNTooltype& src
		) {
	FmncQTolMNTooltype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTolMNTooltype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTolMNTooltype::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTolMNTooltype";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTolMNTooltype
 ******************************************************************************/

TblFmncQTolMNTooltype::TblFmncQTolMNTooltype() {
};

TblFmncQTolMNTooltype::~TblFmncQTolMNTooltype() {
};

bool TblFmncQTolMNTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncQTolMNTooltype** rec
		) {
	return false;
};

ubigint TblFmncQTolMNTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	return 0;
};

void TblFmncQTolMNTooltype::insertRec(
			FmncQTolMNTooltype* rec
		) {
};

ubigint TblFmncQTolMNTooltype::insertNewRec(
			FmncQTolMNTooltype** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefsFmncKToolchar
			, const string titsSrefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string titsDefSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
			, const string titsOptSrefsFmncKSteppar
		) {
	ubigint retval = 0;
	FmncQTolMNTooltype* _rec = NULL;

	_rec = new FmncQTolMNTooltype(0, jref, jnum, mref, stubMref, ref, srefsFmncKToolchar, titsSrefsFmncKToolchar, defSrefsFmncKSteppar, titsDefSrefsFmncKSteppar, optSrefsFmncKSteppar, titsOptSrefsFmncKSteppar);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTolMNTooltype::appendNewRecToRst(
			ListFmncQTolMNTooltype& rst
			, FmncQTolMNTooltype** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefsFmncKToolchar
			, const string titsSrefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string titsDefSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
			, const string titsOptSrefsFmncKSteppar
		) {
	ubigint retval = 0;
	FmncQTolMNTooltype* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, srefsFmncKToolchar, titsSrefsFmncKToolchar, defSrefsFmncKSteppar, titsDefSrefsFmncKSteppar, optSrefsFmncKSteppar, titsOptSrefsFmncKSteppar);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTolMNTooltype::insertRst(
			ListFmncQTolMNTooltype& rst
		) {
};

void TblFmncQTolMNTooltype::updateRec(
			FmncQTolMNTooltype* rec
		) {
};

void TblFmncQTolMNTooltype::updateRst(
			ListFmncQTolMNTooltype& rst
		) {
};

void TblFmncQTolMNTooltype::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTolMNTooltype::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTolMNTooltype::loadRecByQref(
			ubigint qref
			, FmncQTolMNTooltype** rec
		) {
	return false;
};

ubigint TblFmncQTolMNTooltype::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTolMNTooltype
 ******************************************************************************/

MyTblFmncQTolMNTooltype::MyTblFmncQTolMNTooltype() : TblFmncQTolMNTooltype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTolMNTooltype::~MyTblFmncQTolMNTooltype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTolMNTooltype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTolMNTooltype (jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTolMNTooltype SET jref = ?, jnum = ?, mref = ?, ref = ?, srefsFmncKToolchar = ?, defSrefsFmncKSteppar = ?, optSrefsFmncKSteppar = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTolMNTooltype WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTolMNTooltype WHERE jref = ?", false);
};

bool MyTblFmncQTolMNTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncQTolMNTooltype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTolMNTooltype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolMNTooltype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTolMNTooltype();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->srefsFmncKToolchar.assign(dbrow[5], dblengths[5]); else _rec->srefsFmncKToolchar = "";
		if (dbrow[6]) _rec->defSrefsFmncKSteppar.assign(dbrow[6], dblengths[6]); else _rec->defSrefsFmncKSteppar = "";
		if (dbrow[7]) _rec->optSrefsFmncKSteppar.assign(dbrow[7], dblengths[7]); else _rec->optSrefsFmncKSteppar = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQTolMNTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTolMNTooltype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTolMNTooltype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTolMNTooltype();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->srefsFmncKToolchar.assign(dbrow[5], dblengths[5]); else rec->srefsFmncKToolchar = "";
			if (dbrow[6]) rec->defSrefsFmncKSteppar.assign(dbrow[6], dblengths[6]); else rec->defSrefsFmncKSteppar = "";
			if (dbrow[7]) rec->optSrefsFmncKSteppar.assign(dbrow[7], dblengths[7]); else rec->optSrefsFmncKSteppar = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQTolMNTooltype::insertRec(
			FmncQTolMNTooltype* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->srefsFmncKToolchar.length();
	l[5] = rec->defSrefsFmncKSteppar.length();
	l[6] = rec->optSrefsFmncKSteppar.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsFmncKToolchar.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->defSrefsFmncKSteppar.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->optSrefsFmncKSteppar.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNTooltype / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNTooltype / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTolMNTooltype::insertRst(
			ListFmncQTolMNTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTolMNTooltype::updateRec(
			FmncQTolMNTooltype* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->srefsFmncKToolchar.length();
	l[5] = rec->defSrefsFmncKSteppar.length();
	l[6] = rec->optSrefsFmncKSteppar.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->srefsFmncKToolchar.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->defSrefsFmncKSteppar.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->optSrefsFmncKSteppar.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNTooltype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNTooltype / stmtUpdateRec)\n");
};

void MyTblFmncQTolMNTooltype::updateRst(
			ListFmncQTolMNTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTolMNTooltype::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNTooltype / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNTooltype / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTolMNTooltype::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTolMNTooltype / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTolMNTooltype / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTolMNTooltype::loadRecByQref(
			ubigint qref
			, FmncQTolMNTooltype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTolMNTooltype WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTolMNTooltype::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTolMNTooltype WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTolMNTooltype
 ******************************************************************************/

PgTblFmncQTolMNTooltype::PgTblFmncQTolMNTooltype() : TblFmncQTolMNTooltype(), PgTable() {
};

PgTblFmncQTolMNTooltype::~PgTblFmncQTolMNTooltype() {
};

void PgTblFmncQTolMNTooltype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTolMNTooltype_insertRec", "INSERT INTO TblFmncQTolMNTooltype (jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNTooltype_updateRec", "UPDATE TblFmncQTolMNTooltype SET jref = $1, jnum = $2, mref = $3, ref = $4, srefsFmncKToolchar = $5, defSrefsFmncKSteppar = $6, optSrefsFmncKSteppar = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNTooltype_removeRecByQref", "DELETE FROM TblFmncQTolMNTooltype WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNTooltype_removeRstByJref", "DELETE FROM TblFmncQTolMNTooltype WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTolMNTooltype_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar FROM TblFmncQTolMNTooltype WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTolMNTooltype_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar FROM TblFmncQTolMNTooltype WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTolMNTooltype::loadRec(
			PGresult* res
			, FmncQTolMNTooltype** rec
		) {
	char* ptr;

	FmncQTolMNTooltype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTolMNTooltype();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefsfmncktoolchar"),
			PQfnumber(res, "defsrefsfmncksteppar"),
			PQfnumber(res, "optsrefsfmncksteppar")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefsFmncKToolchar.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->defSrefsFmncKSteppar.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->optSrefsFmncKSteppar.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQTolMNTooltype::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTolMNTooltype* rec;

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
			PQfnumber(res, "srefsfmncktoolchar"),
			PQfnumber(res, "defsrefsfmncksteppar"),
			PQfnumber(res, "optsrefsfmncksteppar")
		};

		while (numread < numrow) {
			rec = new FmncQTolMNTooltype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefsFmncKToolchar.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->defSrefsFmncKSteppar.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->optSrefsFmncKSteppar.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQTolMNTooltype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTolMNTooltype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNTooltype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolMNTooltype::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNTooltype / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTolMNTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncQTolMNTooltype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTolMNTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTolMNTooltype::insertRec(
			FmncQTolMNTooltype* rec
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
		rec->srefsFmncKToolchar.c_str(),
		rec->defSrefsFmncKSteppar.c_str(),
		rec->optSrefsFmncKSteppar.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQTolMNTooltype_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNTooltype_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTolMNTooltype::insertRst(
			ListFmncQTolMNTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTolMNTooltype::updateRec(
			FmncQTolMNTooltype* rec
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
		rec->srefsFmncKToolchar.c_str(),
		rec->defSrefsFmncKSteppar.c_str(),
		rec->optSrefsFmncKSteppar.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQTolMNTooltype_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNTooltype_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTolMNTooltype::updateRst(
			ListFmncQTolMNTooltype& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTolMNTooltype::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolMNTooltype_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNTooltype_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTolMNTooltype::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTolMNTooltype_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTolMNTooltype_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTolMNTooltype::loadRecByQref(
			ubigint qref
			, FmncQTolMNTooltype** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTolMNTooltype_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTolMNTooltype::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTolMNTooltype& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTolMNTooltype_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

