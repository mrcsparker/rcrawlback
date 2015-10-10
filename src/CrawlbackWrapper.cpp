#include "CrawlbackWrapper.h"

void on_cb(crawlback_Event * ev) {
  Rcpp::Rcout << "Starting on_cb" << std::endl;
  r_Function *f = (r_Function *) ev->data;
  Rcpp::Function * arr_call = f->function;
  Rcpp::Rcout << "Making call" <<  std::endl;
  (*arr_call)();
}

CrawlbackWrapper::CrawlbackWrapper() {
  _crawlback_Object = crawlback_new();
}

CrawlbackWrapper::~CrawlbackWrapper() {
  for (r_Function *f : _crawlback_Functions) {
    free(f);
  }
  crawlback_delete(_crawlback_Object);
}

// Memory leak.  Just for demo
void CrawlbackWrapper::addStartCallback(Rcpp::Function f) {

  r_Function *r_func = (r_Function *) malloc(sizeof(r_Function));
  r_func->function = &f;

  _crawlback_Functions.push_back(r_func);

  crawlback_addCallback(_crawlback_Object, EVENT_START, on_cb, r_func);
}

void CrawlbackWrapper::run() {
  crawlback_run(_crawlback_Object);
}

