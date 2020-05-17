#include <Rcpp.h>
using namespace Rcpp;

#include "gperftools/profiler.h"

//' @export
// [[Rcpp::export]]
void start_profiler(String str) {
  ProfilerStart(str.get_cstring());
}

//' @export
// [[Rcpp::export]]
void stop_profiler() {
  ProfilerStop();
}
