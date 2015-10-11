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
void r_crawlback_run(XPtr<CrawlbackWrapper> c,
                     Function& onStart,
                     Function& onRun,
                     Function& onEnd) {

  c->addStartCallback(onStart);
  c->addRunCallback(onRun);
  c->addEndCallback(onEnd);
  c->run();
}

