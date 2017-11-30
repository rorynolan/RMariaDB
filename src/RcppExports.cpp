// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "RMariaDB_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// connection_create
XPtr<DbConnectionPtr> connection_create(const Nullable<std::string>& host, const Nullable<std::string>& user, const Nullable<std::string>& password, const Nullable<std::string>& db, unsigned int port, const Nullable<std::string>& unix_socket, unsigned long client_flag, const Nullable<std::string>& groups, const Nullable<std::string>& default_file, const Nullable<std::string>& ssl_key, const Nullable<std::string>& ssl_cert, const Nullable<std::string>& ssl_ca, const Nullable<std::string>& ssl_capath, const Nullable<std::string>& ssl_cipher);
RcppExport SEXP _RMariaDB_connection_create(SEXP hostSEXP, SEXP userSEXP, SEXP passwordSEXP, SEXP dbSEXP, SEXP portSEXP, SEXP unix_socketSEXP, SEXP client_flagSEXP, SEXP groupsSEXP, SEXP default_fileSEXP, SEXP ssl_keySEXP, SEXP ssl_certSEXP, SEXP ssl_caSEXP, SEXP ssl_capathSEXP, SEXP ssl_cipherSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type host(hostSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type user(userSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type password(passwordSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type db(dbSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type port(portSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type unix_socket(unix_socketSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type client_flag(client_flagSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type groups(groupsSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type default_file(default_fileSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type ssl_key(ssl_keySEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type ssl_cert(ssl_certSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type ssl_ca(ssl_caSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type ssl_capath(ssl_capathSEXP);
    Rcpp::traits::input_parameter< const Nullable<std::string>& >::type ssl_cipher(ssl_cipherSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_create(host, user, password, db, port, unix_socket, client_flag, groups, default_file, ssl_key, ssl_cert, ssl_ca, ssl_capath, ssl_cipher));
    return rcpp_result_gen;
END_RCPP
}
// connection_valid
bool connection_valid(XPtr<DbConnectionPtr> con_);
RcppExport SEXP _RMariaDB_connection_valid(SEXP con_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con_(con_SEXP);
    rcpp_result_gen = Rcpp::wrap(connection_valid(con_));
    return rcpp_result_gen;
END_RCPP
}
// connection_release
void connection_release(XPtr<DbConnectionPtr> con_);
RcppExport SEXP _RMariaDB_connection_release(SEXP con_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con_(con_SEXP);
    connection_release(con_);
    return R_NilValue;
END_RCPP
}
// connection_info
List connection_info(DbConnection* con);
RcppExport SEXP _RMariaDB_connection_info(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_info(con));
    return rcpp_result_gen;
END_RCPP
}
// connection_quote_string
CharacterVector connection_quote_string(XPtr<DbConnectionPtr> con, CharacterVector input);
RcppExport SEXP _RMariaDB_connection_quote_string(SEXP conSEXP, SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type input(inputSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_quote_string(con, input));
    return rcpp_result_gen;
END_RCPP
}
// connection_begin_transaction
void connection_begin_transaction(XPtr<DbConnectionPtr> con);
RcppExport SEXP _RMariaDB_connection_begin_transaction(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    connection_begin_transaction(con);
    return R_NilValue;
END_RCPP
}
// connection_commit
void connection_commit(XPtr<DbConnectionPtr> con);
RcppExport SEXP _RMariaDB_connection_commit(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    connection_commit(con);
    return R_NilValue;
END_RCPP
}
// connection_rollback
void connection_rollback(XPtr<DbConnectionPtr> con);
RcppExport SEXP _RMariaDB_connection_rollback(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    connection_rollback(con);
    return R_NilValue;
END_RCPP
}
// connection_is_transacting
bool connection_is_transacting(DbConnection* con);
RcppExport SEXP _RMariaDB_connection_is_transacting(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_is_transacting(con));
    return rcpp_result_gen;
END_RCPP
}
// driver_init
void driver_init();
RcppExport SEXP _RMariaDB_driver_init() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    driver_init();
    return R_NilValue;
END_RCPP
}
// driver_done
void driver_done();
RcppExport SEXP _RMariaDB_driver_done() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    driver_done();
    return R_NilValue;
END_RCPP
}
// version
IntegerVector version();
RcppExport SEXP _RMariaDB_version() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(version());
    return rcpp_result_gen;
END_RCPP
}
// init_logging
void init_logging(const std::string& log_level);
RcppExport SEXP _RMariaDB_init_logging(SEXP log_levelSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type log_level(log_levelSEXP);
    init_logging(log_level);
    return R_NilValue;
END_RCPP
}
// result_create
XPtr<DbResult> result_create(XPtr<DbConnectionPtr> con, std::string sql, bool is_statement);
RcppExport SEXP _RMariaDB_result_create(SEXP conSEXP, SEXP sqlSEXP, SEXP is_statementSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    Rcpp::traits::input_parameter< std::string >::type sql(sqlSEXP);
    Rcpp::traits::input_parameter< bool >::type is_statement(is_statementSEXP);
    rcpp_result_gen = Rcpp::wrap(result_create(con, sql, is_statement));
    return rcpp_result_gen;
END_RCPP
}
// result_release
void result_release(XPtr<DbResult> res);
RcppExport SEXP _RMariaDB_result_release(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbResult> >::type res(resSEXP);
    result_release(res);
    return R_NilValue;
END_RCPP
}
// result_valid
bool result_valid(XPtr<DbResult> res_);
RcppExport SEXP _RMariaDB_result_valid(SEXP res_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbResult> >::type res_(res_SEXP);
    rcpp_result_gen = Rcpp::wrap(result_valid(res_));
    return rcpp_result_gen;
END_RCPP
}
// result_fetch
List result_fetch(DbResult* res, const int n);
RcppExport SEXP _RMariaDB_result_fetch(SEXP resSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(result_fetch(res, n));
    return rcpp_result_gen;
END_RCPP
}
// result_bind
void result_bind(DbResult* res, List params);
RcppExport SEXP _RMariaDB_result_bind(SEXP resSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    Rcpp::traits::input_parameter< List >::type params(paramsSEXP);
    result_bind(res, params);
    return R_NilValue;
END_RCPP
}
// result_has_completed
bool result_has_completed(DbResult* res);
RcppExport SEXP _RMariaDB_result_has_completed(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_has_completed(res));
    return rcpp_result_gen;
END_RCPP
}
// result_rows_fetched
int result_rows_fetched(DbResult* res);
RcppExport SEXP _RMariaDB_result_rows_fetched(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_rows_fetched(res));
    return rcpp_result_gen;
END_RCPP
}
// result_rows_affected
int result_rows_affected(DbResult* res);
RcppExport SEXP _RMariaDB_result_rows_affected(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_rows_affected(res));
    return rcpp_result_gen;
END_RCPP
}
// result_column_info
List result_column_info(DbResult* res);
RcppExport SEXP _RMariaDB_result_column_info(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_column_info(res));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RMariaDB_connection_create", (DL_FUNC) &_RMariaDB_connection_create, 14},
    {"_RMariaDB_connection_valid", (DL_FUNC) &_RMariaDB_connection_valid, 1},
    {"_RMariaDB_connection_release", (DL_FUNC) &_RMariaDB_connection_release, 1},
    {"_RMariaDB_connection_info", (DL_FUNC) &_RMariaDB_connection_info, 1},
    {"_RMariaDB_connection_quote_string", (DL_FUNC) &_RMariaDB_connection_quote_string, 2},
    {"_RMariaDB_connection_begin_transaction", (DL_FUNC) &_RMariaDB_connection_begin_transaction, 1},
    {"_RMariaDB_connection_commit", (DL_FUNC) &_RMariaDB_connection_commit, 1},
    {"_RMariaDB_connection_rollback", (DL_FUNC) &_RMariaDB_connection_rollback, 1},
    {"_RMariaDB_connection_is_transacting", (DL_FUNC) &_RMariaDB_connection_is_transacting, 1},
    {"_RMariaDB_driver_init", (DL_FUNC) &_RMariaDB_driver_init, 0},
    {"_RMariaDB_driver_done", (DL_FUNC) &_RMariaDB_driver_done, 0},
    {"_RMariaDB_version", (DL_FUNC) &_RMariaDB_version, 0},
    {"_RMariaDB_init_logging", (DL_FUNC) &_RMariaDB_init_logging, 1},
    {"_RMariaDB_result_create", (DL_FUNC) &_RMariaDB_result_create, 3},
    {"_RMariaDB_result_release", (DL_FUNC) &_RMariaDB_result_release, 1},
    {"_RMariaDB_result_valid", (DL_FUNC) &_RMariaDB_result_valid, 1},
    {"_RMariaDB_result_fetch", (DL_FUNC) &_RMariaDB_result_fetch, 2},
    {"_RMariaDB_result_bind", (DL_FUNC) &_RMariaDB_result_bind, 2},
    {"_RMariaDB_result_has_completed", (DL_FUNC) &_RMariaDB_result_has_completed, 1},
    {"_RMariaDB_result_rows_fetched", (DL_FUNC) &_RMariaDB_result_rows_fetched, 1},
    {"_RMariaDB_result_rows_affected", (DL_FUNC) &_RMariaDB_result_rows_affected, 1},
    {"_RMariaDB_result_column_info", (DL_FUNC) &_RMariaDB_result_column_info, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_RMariaDB(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
