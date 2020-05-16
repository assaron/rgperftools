#include <Rcpp.h>
using namespace Rcpp;

#include "gperftools/profiler.h"

// [[Rcpp::export]]
void start_profiler(String str) {
  ProfilerStart(str.get_cstring());
}

// [[Rcpp::export]]
void stop_profiler() {
  ProfilerStop();
}
