/* gel-clock.h */

#ifndef _GEL_CLOCK
#define _GEL_CLOCK

#include <glib-object.h>

G_BEGIN_DECLS

#define GEL_TYPE_CLOCK gel_clock_get_type()

#define GEL_CLOCK(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GEL_TYPE_CLOCK, GelClock))

#define GEL_CLOCK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), GEL_TYPE_CLOCK, GelClockClass))

#define GEL_IS_CLOCK(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GEL_TYPE_CLOCK))

#define GEL_IS_CLOCK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), GEL_TYPE_CLOCK))

#define GEL_CLOCK_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GEL_TYPE_CLOCK, GelClockClass))

typedef struct {
  GObject parent;
} GelClock;

typedef struct {
  GObjectClass parent_class;

  /*
   * Signals are defined by class. The following signal, 'tick', is a basic
   * signal with no arguments and no return value
   */
  void (*tick) (GelClock *self);
} GelClockClass;

GType gel_clock_get_type (void);

GelClock* gel_clock_new (void);

G_END_DECLS

#endif  // _GEL_CLOCK
