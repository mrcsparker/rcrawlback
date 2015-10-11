# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Cmd + Shift + B'
#   Check Package:             'Cmd + Shift + E'
#   Test Package:              'Cmd + Shift + T'

library(R6)

RCrawlback <- R6Class("RCrawlback",

  public = list(

    crawlback_object = NA,
    start_callback = NA,
    run_callback = NA,
    end_callback = NA,

    initialize = function(){
      self$crawlback_object <- r_crawlback_new()
    },

    add_start_callback = function(cb) {
      self$start_callback <- cb
    },

    add_run_callback = function(cb) {
      self$run_callback <- cb
    },

    add_end_callback = function(cb) {
      self$end_callback <- cb
    },

    run = function() {
      r_crawlback_run(self$crawlback_object,
                      self$start_callback,
                      self$run_callback,
                      self$end_callback)
    }
  )
)

# Sample code on how to run callbacks

do_start <- function() {
  print("starting")
}

do_run <- function() {
  print("running")
}

do_end <- function() {
  print("ending")
}

run_callbacks <- function() {
  print("running callbacks")

  x <- RCrawlback$new()
  x$add_start_callback(do_start)
  x$add_run_callback(do_run)
  x$add_end_callback(do_end)
  x$run()
}
