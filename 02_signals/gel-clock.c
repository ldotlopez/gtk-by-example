/* gel-clock.c */

#include "gel-clock.h"

G_DEFINE_TYPE (GelClock, gel_clock, G_TYPE_OBJECT)

#define GET_PRIVATE(o) \
  (G_TYPE_INSTANCE_GET_PRIVATE ((o), GEL_TYPE_CLOCK, GelClockPrivate))

typedef struct _GelClockPrivate GelClockPrivate;

struct _GelClockPrivate {
	time_t stamp;      // Store last tick
	guint  timeout_id; // Store timeout callback reference
};


/*
 * For signals is common to define some enum value to refer them.
 * With this enums you can use them to store the 'signal-ids'
 * in an array and use this array to emit the signals.
 *
 * The array (signals) will be filled at gel_clock_class_init
 */
enum {
	TICK,
	LAST_SIGNAL // Just a convention
};
guint signals[LAST_SIGNAL] = { 0 };



static gboolean
_timeout_cb(GelClock *self);

static void
gel_clock_dispose (GObject *object)
{
  /*
   * Here you can see and example about how the dispose function is meant for.
   * Dispose can be called one or more time when instance is destroyed.
   * GelClock uses glib's timeout functions to 'tick', so before destroy the
   * instance the timeout must be deactivated. This is a good place to do it.
   */
   GelClock *self = GEL_CLOCK(object);
  GelClockPrivate *priv = GET_PRIVATE(self);

  /*
   * This is a common idiom to prevent double free of resources (remember,
   * dispose can be called multiple times. It's not thread safe but you can get
   * the point.
   */
  if (priv->timeout_id)
  {
  	g_source_remove(priv->timeout_id);
	priv->timeout_id = 0;
  }

  /*
   * Note that parent's class dispose is called anyway. It's part of the
   * GObject chain-up mechanism, just follow it.
   */
  G_OBJECT_CLASS (gel_clock_parent_class)->dispose (object);
}

static void
gel_clock_finalize (GObject *object)
{
  G_OBJECT_CLASS (gel_clock_parent_class)->finalize (object);
}

static void
gel_clock_class_init (GelClockClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (GelClockPrivate));

  object_class->dispose = gel_clock_dispose;
  object_class->finalize = gel_clock_finalize;


  /*
   * Here is where the signal is really declared
   */
   signals[TICK] =
		// signal name
		g_signal_new ("tick",

		// attach to GelClockClass class
		G_OBJECT_CLASS_TYPE (klass),

		// See docs
		G_SIGNAL_RUN_LAST,

		// Use 'tick' function from GelClockClass struct
		G_STRUCT_OFFSET (GelClockClass, tick),

		// See docs. I have never use this
		NULL, NULL,

		// Special 'bridge' funcion. You can see the VOID__VOID here, it
		// means that the bridge, or closure marshal, has no paramaters but the
		// instance itself and returns nothing.
		// Other predefined marshalers can be:
		// g_cclosure_marshal_VOID__INT -> signal handler recieves an int with
		// the instance
		// g_cclosure_marshal_INT_VOID -> signal handler must return an int but
		// doesn't recieve aditional paramaters but the instances.
		//
		g_cclosure_marshal_VOID__VOID,

		// Defines the return type of the handler, in this case is none but it
		// can be anything: G_TYPE_INT, G_TYPE_STRING, G_TYPE_OBJECT, etc...
		G_TYPE_NONE,

		// Number of additional parameters, in this case 0. In other examples
		// you can find how to use this.
		0);
}

static void
gel_clock_init (GelClock *self)
{
	GelClockPrivate *priv = GET_PRIVATE(self);
	priv->stamp = 0;
	priv->timeout_id = g_timeout_add(100, (GSourceFunc) _timeout_cb, self);
}

GelClock*
gel_clock_new (void)
{
  return g_object_new (GEL_TYPE_CLOCK, NULL);
}

static gboolean
_timeout_cb(GelClock *self)
{
	GelClockPrivate *priv = GET_PRIVATE(self);

	time_t stamp = time(NULL);
	if ((stamp - priv->stamp) > 1)
	{
		priv->stamp = stamp;
		g_signal_emit(self, signals[TICK], 0);
	}
	return TRUE;
}
