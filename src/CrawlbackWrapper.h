#ifndef __CRAWLBACK_WRAPPER_H__
#define __CRAWLBACK_WRAPPER_H__

#include <vector>
#include "crawlback.h"
#include <Rcpp.h>

// Rcpp Function struct
typedef struct {
  Rcpp::Function *function;
} r_Function;

class CrawlbackWrapper {
public:
  CrawlbackWrapper();
  ~CrawlbackWrapper();

  void addStartCallback(Rcpp::Function f);
  void run();

private:
  crawlback_Object * _crawlback_Object;
  std::vector<r_Function *> _crawlback_Functions;
};

#endif /* __CRAWLBACK_WRAPPER_H__ */
