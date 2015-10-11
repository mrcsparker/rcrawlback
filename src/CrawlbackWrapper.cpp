#include "CrawlbackWrapper.h"
#include <assert.h>

void on_callback(crawlback_event * ev) {
  assert(ev != NULL);
  assert(ev->data != NULL);
  assert(ev->data->function != NULL);
  CallbackFunction *f = (CallbackFunction *) ev->data;
  const Rcpp::Function *arrRCall = f->function;
  (*arrRCall)();
}

CrawlbackWrapper::CrawlbackWrapper() {
  _crawlbackObject = crawlback_new();
}

CrawlbackWrapper::~CrawlbackWrapper() {
  for (CallbackFunction *f : _crawlbackFunctions) {
    std::cout << f->message << std::endl;
    delete f;
  }
  crawlback_delete(_crawlbackObject);
}

void CrawlbackWrapper::addStartCallback(const Rcpp::Function& f) {
  CallbackFunction *callbackFunction = new CallbackFunction(&f, _crawlbackObject, "start_cb");
  crawlback_add_callback(_crawlbackObject, EVENT_START, on_callback, callbackFunction);
  _crawlbackFunctions.push_back(callbackFunction);
}

void CrawlbackWrapper::addRunCallback(const Rcpp::Function& f) {
  CallbackFunction *callbackFunction = new CallbackFunction(&f, _crawlbackObject, "run_cb");
  crawlback_add_callback(_crawlbackObject, EVENT_RUN, on_callback, callbackFunction);
  _crawlbackFunctions.push_back(callbackFunction);
}

void CrawlbackWrapper::addEndCallback(const Rcpp::Function& f) {
  CallbackFunction *callbackFunction = new CallbackFunction(&f, _crawlbackObject, "end_cb");
  crawlback_add_callback(_crawlbackObject, EVENT_END, on_callback, callbackFunction);
  _crawlbackFunctions.push_back(callbackFunction);
}

void CrawlbackWrapper::run() {
  crawlback_run(_crawlbackObject);
}

