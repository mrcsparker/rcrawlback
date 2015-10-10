# Hello, world!
#
# This is an example function named 'hello'
# which prints 'Hello, world!'.
#
# You can learn more about package authoring with RStudio at:
#
#   http://r-pkgs.had.co.nz/
#
# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Cmd + Shift + B'
#   Check Package:             'Cmd + Shift + E'
#   Test Package:              'Cmd + Shift + T'

hello <- function() {
  print("Hello, world!")
}

add <- function() {
  print("add")
}

run_callbacks <- function() {
  print("running callbacks")
  x <- r_crawlback_new()
  r_crawlback_add_start_callback(x, add)
  r_crawlback_run(x)
}
