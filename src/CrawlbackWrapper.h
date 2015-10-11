#ifndef __CRAWLBACK_WRAPPER_H__
#define __CRAWLBACK_WRAPPER_H__

#include <vector>
#include "crawlback.h"
#include <Rcpp.h>

#define DBG(MSG,X) Rprintf("%20s SEXP=<%p>. Function=%p\n", MSG, (SEXP)X, &X ) ;

// Rcpp Function struct
class CallbackFunction {
public:
  CallbackFunction(const Rcpp::Function *f, crawlback_object *o, std::string msg) {
    function = f;
    obj = o;
    message = msg;
  }
  const Rcpp::Function *function;
  crawlback_object *obj;
  std::string message;
};

class CrawlbackWrapper {
public:
  CrawlbackWrapper();
  ~CrawlbackWrapper();

  void addStartCallback(const Rcpp::Function& f);
  void addRunCallback(const Rcpp::Function& f);
  void addEndCallback(const Rcpp::Function& f);
  void run();

private:
  crawlback_object * _crawlbackObject;
  std::vector<CallbackFunction *> _crawlbackFunctions;
};

#endif /* __CRAWLBACK_WRAPPER_H__ */
