/**
  * \file FmncQTtyMNTool.cpp
  * Dbs and XML wrapper for table TblFmncQTtyMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtyMNTool.h"

/******************************************************************************
 class FmncQTtyMNTool
 ******************************************************************************/

FmncQTtyMNTool::FmncQTtyMNTool(
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

void FmncQTtyMNTool::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQTtyMNTool";

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
 class ListFmncQTtyMNTool
 ******************************************************************************/

ListFmncQTtyMNTool::ListFmncQTtyMNTool() {
};

ListFmncQTtyMNTool::ListFmncQTtyMNTool(
			const ListFmncQTtyMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyMNTool(*(src.nodes[i]));
};

ListFmncQTtyMNTool::~ListFmncQTtyMNTool() {
	clear();
};

void ListFmncQTtyMNTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQTtyMNTool::size() const {
	return(nodes.size());
};

void ListFmncQTtyMNTool::append(
			FmncQTtyMNTool* rec
		) {
	nodes.push_back(rec);
};

ListFmncQTtyMNTool& ListFmncQTtyMNTool::operator=(
			const ListFmncQTtyMNTool& src
		) {
	FmncQTtyMNTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQTtyMNTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQTtyMNTool::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQTtyMNTool";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQTtyMNTool
 ******************************************************************************/

TblFmncQTtyMNTool::TblFmncQTtyMNTool() {
};

TblFmncQTtyMNTool::~TblFmncQTtyMNTool() {
};

bool TblFmncQTtyMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyMNTool** rec
		) {
	return false;
};

ubigint TblFmncQTtyMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	return 0;
};

void TblFmncQTtyMNTool::insertRec(
			FmncQTtyMNTool* rec
		) {
};

ubigint TblFmncQTtyMNTool::insertNewRec(
			FmncQTtyMNTool** rec
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
	FmncQTtyMNTool* _rec = NULL;

	_rec = new FmncQTtyMNTool(0, jref, jnum, mref, stubMref, ref, srefsFmncKToolchar, titsSrefsFmncKToolchar, defSrefsFmncKSteppar, titsDefSrefsFmncKSteppar, optSrefsFmncKSteppar, titsOptSrefsFmncKSteppar);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQTtyMNTool::appendNewRecToRst(
			ListFmncQTtyMNTool& rst
			, FmncQTtyMNTool** rec
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
	FmncQTtyMNTool* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, srefsFmncKToolchar, titsSrefsFmncKToolchar, defSrefsFmncKSteppar, titsDefSrefsFmncKSteppar, optSrefsFmncKSteppar, titsOptSrefsFmncKSteppar);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQTtyMNTool::insertRst(
			ListFmncQTtyMNTool& rst
		) {
};

void TblFmncQTtyMNTool::updateRec(
			FmncQTtyMNTool* rec
		) {
};

void TblFmncQTtyMNTool::updateRst(
			ListFmncQTtyMNTool& rst
		) {
};

void TblFmncQTtyMNTool::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQTtyMNTool::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQTtyMNTool::loadRecByQref(
			ubigint qref
			, FmncQTtyMNTool** rec
		) {
	return false;
};

ubigint TblFmncQTtyMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQTtyMNTool
 ******************************************************************************/

MyTblFmncQTtyMNTool::MyTblFmncQTtyMNTool() : TblFmncQTtyMNTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQTtyMNTool::~MyTblFmncQTtyMNTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQTtyMNTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQTtyMNTool (jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQTtyMNTool SET jref = ?, jnum = ?, mref = ?, ref = ?, srefsFmncKToolchar = ?, defSrefsFmncKSteppar = ?, optSrefsFmncKSteppar = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQTtyMNTool WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQTtyMNTool WHERE jref = ?", false);
};

bool MyTblFmncQTtyMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyMNTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQTtyMNTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtyMNTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQTtyMNTool();

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

ubigint MyTblFmncQTtyMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQTtyMNTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQTtyMNTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQTtyMNTool();

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

void MyTblFmncQTtyMNTool::insertRec(
			FmncQTtyMNTool* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyMNTool / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyMNTool / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQTtyMNTool::insertRst(
			ListFmncQTtyMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQTtyMNTool::updateRec(
			FmncQTtyMNTool* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyMNTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyMNTool / stmtUpdateRec)\n");
};

void MyTblFmncQTtyMNTool::updateRst(
			ListFmncQTtyMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQTtyMNTool::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyMNTool / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyMNTool / stmtRemoveRecByQref)\n");
};

void MyTblFmncQTtyMNTool::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQTtyMNTool / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQTtyMNTool / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQTtyMNTool::loadRecByQref(
			ubigint qref
			, FmncQTtyMNTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQTtyMNTool WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQTtyMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQTtyMNTool WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQTtyMNTool
 ******************************************************************************/

PgTblFmncQTtyMNTool::PgTblFmncQTtyMNTool() : TblFmncQTtyMNTool(), PgTable() {
};

PgTblFmncQTtyMNTool::~PgTblFmncQTtyMNTool() {
};

void PgTblFmncQTtyMNTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQTtyMNTool_insertRec", "INSERT INTO TblFmncQTtyMNTool (jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyMNTool_updateRec", "UPDATE TblFmncQTtyMNTool SET jref = $1, jnum = $2, mref = $3, ref = $4, srefsFmncKToolchar = $5, defSrefsFmncKSteppar = $6, optSrefsFmncKSteppar = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyMNTool_removeRecByQref", "DELETE FROM TblFmncQTtyMNTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyMNTool_removeRstByJref", "DELETE FROM TblFmncQTtyMNTool WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQTtyMNTool_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar FROM TblFmncQTtyMNTool WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQTtyMNTool_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar FROM TblFmncQTtyMNTool WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQTtyMNTool::loadRec(
			PGresult* res
			, FmncQTtyMNTool** rec
		) {
	char* ptr;

	FmncQTtyMNTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQTtyMNTool();

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

ubigint PgTblFmncQTtyMNTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQTtyMNTool* rec;

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
			rec = new FmncQTtyMNTool();

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

bool PgTblFmncQTtyMNTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQTtyMNTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyMNTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtyMNTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyMNTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQTtyMNTool::loadRecBySQL(
			const string& sqlstr
			, FmncQTtyMNTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQTtyMNTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQTtyMNTool::insertRec(
			FmncQTtyMNTool* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTtyMNTool_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyMNTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQTtyMNTool::insertRst(
			ListFmncQTtyMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQTtyMNTool::updateRec(
			FmncQTtyMNTool* rec
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

	res = PQexecPrepared(dbs, "TblFmncQTtyMNTool_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyMNTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQTtyMNTool::updateRst(
			ListFmncQTtyMNTool& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQTtyMNTool::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtyMNTool_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyMNTool_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQTtyMNTool::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblFmncQTtyMNTool_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQTtyMNTool_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQTtyMNTool::loadRecByQref(
			ubigint qref
			, FmncQTtyMNTool** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQTtyMNTool_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQTtyMNTool::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQTtyMNTool& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQTtyMNTool_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

