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
} crawlback_CallbackType;

/* Mock event struct */
typedef struct {
  void *data;
} crawlback_Event;

/* Callback fp */
typedef void (*crawlback_Callback)(crawlback_Event *);

/* Main "object" that stores callbacks */
typedef struct {
  crawlback_Event *start_ev;
  crawlback_Callback start_cb;
  int start_cb_set;

  crawlback_Event *run_ev;
  crawlback_Callback run_cb;
  int run_cb_set;

  crawlback_Event *end_ev;
  crawlback_Callback end_cb;
  int end_cb_set;

} crawlback_Object;

crawlback_Object * crawlback_new(void);
void crawlback_addCallback(crawlback_Object * c, crawlback_CallbackType callback_type, crawlback_Callback callback, void * d);
void crawlback_run(crawlback_Object * c);
void crawlback_delete(crawlback_Object * c);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __CRAWLBACK_H__ */
