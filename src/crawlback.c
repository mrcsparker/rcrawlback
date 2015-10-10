#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "crawlback.h"

crawlback_Object * crawlback_new() {
  crawlback_Object *c = (crawlback_Object *)malloc(sizeof(crawlback_Object));
  memset(c, 0, sizeof(crawlback_Object));
  c->start_cb_set = 0;
  c->run_cb_set = 0;
  c->end_cb_set = 0;
  return c;
}

crawlback_Event * _create_event(void * data) {
  crawlback_Event *e = (crawlback_Event *) malloc(sizeof(crawlback_Event));
  memset(e, 0, sizeof(crawlback_Event));
  e->data = data;
  return e;
}

void crawlback_addCallback(crawlback_Object * c, crawlback_CallbackType callback_type, crawlback_Callback callback, void * d) {
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
}

void crawlback_run(crawlback_Object * c) {
  if (c->start_cb_set == 1) {
    c->start_cb(c->start_ev);
  }
  if (c->run_cb_set == 1) {
    c->run_cb(c->run_ev);
  }
  if (c->end_cb_set == 1) {
    c->end_cb(c->end_ev);
  }
}

void crawlback_delete(crawlback_Object * c) {
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
