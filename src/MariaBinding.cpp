#include "pch.h"
#include <ctime>
#include <math.h>
#include "MariaBinding.h"

MariaBinding::MariaBinding() {
}

MariaBinding::~MariaBinding() {
}

void MariaBinding::setUp(MYSQL_STMT* pStatement) {
  pStatement_ = pStatement;
  p_ = static_cast<int>(mysql_stmt_param_count(pStatement_));

  bindings_.resize(p_);
  types_.resize(p_);
  isNull_.resize(p_);
  timeBuffers_.resize(p_);
}

void MariaBinding::initBinding(List params) {
  if (p_ != params.size()) {
    stop("Number of params don't match (%i vs %i)", p_, params.size());
  }

  for (int j = 0; j < p_; ++j) {
    MariaFieldType type = variableType(RObject(params[j]));
    types_[j] = type;

    switch (type) {
    case MY_LGL:
      bindingUpdate(j, MYSQL_TYPE_TINY, 1);
      break;
    case MY_INT32:
      bindingUpdate(j, MYSQL_TYPE_LONG, 4);
      break;
    case MY_DBL:
      bindingUpdate(j, MYSQL_TYPE_DOUBLE, 8);
      break;
    case MY_DATE:
      bindingUpdate(j, MYSQL_TYPE_DATE, sizeof(MYSQL_TIME));
      break;
    case MY_DATE_TIME:
      bindingUpdate(j, MYSQL_TYPE_DATETIME, sizeof(MYSQL_TIME));
      break;
    case MY_TIME:
      bindingUpdate(j, MYSQL_TYPE_TIME, sizeof(MYSQL_TIME));
      break;
    case MY_FACTOR:
      bindingUpdate(j, MYSQL_TYPE_DOUBLE, 8);
      break;
    case MY_STR:
      bindingUpdate(j, MYSQL_TYPE_STRING, 0);
      break;
    case MY_RAW:
      bindingUpdate(j, MYSQL_TYPE_BLOB, 0);
      break;
    case MY_INT64:
      // FIXME: 64-bit handling
      break;
    }
  }
}

void MariaBinding::bindRow(List params, int i) {
  for (int j = 0; j < p_; ++j) {
    bool missing = false;
    RObject col(params[j]);

    switch (types_[j]) {
    case MY_LGL:
      if (LOGICAL(col)[i] == NA_LOGICAL) {
        missing = true;
        break;
      }
      bindings_[j].buffer = &LOGICAL(col)[i];
      break;
    case MY_INT32:
      if (INTEGER(col)[i] == NA_INTEGER) {
        missing = true;
        break;
      }
      bindings_[j].buffer = &INTEGER(col)[i];
      break;
    case MY_DBL:
      if (ISNA(REAL(col)[i])) {
        missing = true;
        break;
      }
      bindings_[j].buffer = &REAL(col)[i];
      break;
    case MY_STR:
      if (STRING_ELT(col, i) == NA_STRING) {
        missing = true;
        break;
      } else {
        SEXP string = STRING_ELT(col, i);
        bindings_[j].buffer_length = Rf_length(string);
        bindings_[j].buffer = (void*) CHAR(string);
      }
      break;
    case MY_RAW: {
      SEXP raw = VECTOR_ELT(col, i);
      bindings_[j].buffer_length = Rf_length(raw);
      bindings_[j].buffer = RAW(raw);
    }
    case MY_DATE:
    case MY_DATE_TIME:
      if (ISNAN(REAL(col)[i])) {
        missing = true;
        break;
      } else {
        double val = REAL(col)[i];
        setDateTimeBuffer(j, static_cast<int>(val * (types_[j] == MY_DATE ? 86400.0 : 1.0)));
        bindings_[j].buffer_length = sizeof(MYSQL_TIME);
        bindings_[j].buffer = &timeBuffers_[j];
      }
      break;
    case MY_TIME:
      if (ISNAN(REAL(col)[i])) {
        missing = true;
        break;
      } else {
        double val = REAL(col)[i];
        setTimeBuffer(j, val);
        bindings_[j].buffer_length = sizeof(MYSQL_TIME);
        bindings_[j].buffer = &timeBuffers_[j];
      }
      break;
    case MY_FACTOR:
      stop("Not yet supported");
    case MY_INT64:
      // FIXME: 64-bit handling
      break;
    }
    isNull_[j] = missing;
  }
  mysql_stmt_bind_param(pStatement_, &bindings_[0]);
}

void MariaBinding::bindingUpdate(int j, enum_field_types type, int size) {
  bindings_[j].buffer_length = size;
  bindings_[j].buffer_type = type;
  bindings_[j].is_null = &isNull_[j];
}

void MariaBinding::setDateTimeBuffer(int j, time_t time) {
  struct tm* tm = gmtime(&time);

  timeBuffers_[j].year = tm->tm_year + 1900;
  timeBuffers_[j].month = tm->tm_mon + 1 ;
  timeBuffers_[j].day = tm->tm_mday;
  timeBuffers_[j].hour = tm->tm_hour;
  timeBuffers_[j].minute = tm->tm_min;
  timeBuffers_[j].second = tm->tm_sec;
}

void MariaBinding::setTimeBuffer(int j, double time) {
  bool neg = false;
  if (time < 0) {
    neg = true;
    time = -time;
  }
  double whole_seconds = ::trunc(time);
  double frac_seconds = time - whole_seconds;
  double whole_minutes = ::trunc(time / 60.0);
  double seconds = whole_seconds - whole_minutes * 60.0;
  double hours = ::trunc(time / 3600.0);
  double minutes = whole_minutes - hours * 60.0;

  timeBuffers_[j].year = 0;
  timeBuffers_[j].month = 0;
  timeBuffers_[j].day = 0;
  timeBuffers_[j].hour = static_cast<unsigned int>(hours);
  timeBuffers_[j].minute = static_cast<unsigned int>(minutes);
  timeBuffers_[j].second = static_cast<unsigned int>(seconds);
  timeBuffers_[j].second_part = static_cast<unsigned long>(frac_seconds * 1000000.0);
  timeBuffers_[j].neg = neg;
}
