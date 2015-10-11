#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <assert.h>

#include "crawlback.h"

crawlback_object * crawlback_new() {
  crawlback_object *c = (crawlback_object *)malloc(sizeof(crawlback_object));
  assert(c != NULL);
  memset(c, 0, sizeof(crawlback_object));
  c->start_cb_set = 0;
  c->run_cb_set = 0;
  c->end_cb_set = 0;
  return c;
}

crawlback_event * _create_event(void * data) {
  crawlback_event *e = (crawlback_event *) malloc(sizeof(crawlback_event));
  assert(e != NULL);
  memset(e, 0, sizeof(crawlback_event));
  e->data = data;
  assert(e->data != NULL);
  return e;
}

crawlback_object * crawlback_add_callback(crawlback_object * c, crawlback_callback_type callback_type,
                            crawlback_callback callback, void * d) {
  switch(callback_type) {
  case EVENT_START:
    c->start_cb = callback;
    c->start_ev = _create_event(d);
    c->start_cb_set = 1;
    break;
  case EVENT_RUN:
    c->run_cb = callback;
    c->run_ev = _create_event(d);
    c->run_cb_set = 1;
    break;
  case EVENT_END:
    c->end_cb = callback;
    c->end_ev = _create_event(d);
    c->end_cb_set = 1;
    break;
  }

  return c;
}

crawlback_object * crawlback_run(crawlback_object * c) {
  if (c->start_cb_set == 1) {
    c->start_cb(c->start_ev);
  }
  if (c->run_cb_set == 1) {
    c->run_cb(c->run_ev);
  }
  if (c->end_cb_set == 1) {
    c->end_cb(c->end_ev);
  }

  return c;
}

void crawlback_delete(crawlback_object * c) {
  if (c->start_ev != NULL) {
    free(c->start_ev);
  }
  if (c->run_ev != NULL) {
    free(c->run_ev);
  }
  if (c->end_ev != NULL) {
    free(c->end_ev);
  }
  free(c);
}
