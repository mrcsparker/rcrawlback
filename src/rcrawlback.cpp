#include <Rcpp.h>
#include "rcrawlback_types.h"

using namespace Rcpp;

// Note: this is not production code.

// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
XPtr<CrawlbackWrapper> r_crawlback_new() {
  return XPtr<CrawlbackWrapper>(
    new CrawlbackWrapper()
  );
}

// [[Rcpp::export]]
void r_crawlback_add_start_callback(XPtr<CrawlbackWrapper> c, Function f) {
  c->addStartCallback(f);
}

// [[Rcpp::export]]
void r_crawlback_run(XPtr<CrawlbackWrapper> c) {
  c->run();
}

// [[Rcpp::export]]
List rcpp_hello() {
  CharacterVector x = CharacterVector::create("foo", "bar");
  NumericVector y   = NumericVector::create(0.0, 1.0);
  List z            = List::create(x, y);
  return z;
}

