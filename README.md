# crawlback

Playtime with R callbacks

Testing passing Rcpp Functions with C function pointers

```R
do_start <- function() {
  print("starting")
}

do_run <- function() {
  print("running")
}

do_end <- function() {
  print("ending")
}

print("running callbacks")

x <- RCrawlback$new()
x$add_start_callback(do_start)
x$add_run_callback(do_run)
x$add_end_callback(do_end)
x$run()

## Prints:
# [1] "starting"
# [1] "running"
# [1] "ending"

```
