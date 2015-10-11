#ifndef __CRAWLBACK_H__
#define __CRAWLBACK_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Event types */
typedef enum {
  EVENT_START,
  EVENT_RUN,
  EVENT_END
} crawlback_callback_type;

/* Mock event struct */
typedef struct {
  void *data;
} crawlback_event;

/* Callback fp */
typedef void (*crawlback_callback)(crawlback_event* ev);

/* Main "object" that stores callbacks */
typedef struct {
  crawlback_event *start_ev;
  crawlback_callback start_cb;
  int start_cb_set;

  crawlback_event *run_ev;
  crawlback_callback run_cb;
  int run_cb_set;

  crawlback_event *end_ev;
  crawlback_callback end_cb;
  int end_cb_set;

} crawlback_object;

crawlback_object * crawlback_new(void);
crawlback_object * crawlback_add_callback(crawlback_object * c, crawlback_callback_type callback_type,
                            crawlback_callback callback, void * d);
crawlback_object * crawlback_run(crawlback_object * c);
void crawlback_delete(crawlback_object * c);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __CRAWLBACK_H__ */
