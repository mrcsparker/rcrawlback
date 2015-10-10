# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Cmd + Shift + B'
#   Check Package:             'Cmd + Shift + E'
#   Test Package:              'Cmd + Shift + T'

library(R6)

RCrawlback <- R6Class("RCrawlback",

  public = list(

    crawlbackObject = NA,

    initialize = function(){
      self$crawlbackObject <- r_crawlback_new()
    },

    add_start_callback = function(cb) {
      r_crawlback_add_start_callback(self$crawlbackObject, cb)
    },

    run = function() {
      r_crawlback_run(self$crawlbackObject)
    }
  )
)

add <- function() {
  print("add")
}

run_callbacks <- function() {
  print("running callbacks")

  x <- RCrawlback$new()
  x$add_start_callback(add)
  x$run()
}
