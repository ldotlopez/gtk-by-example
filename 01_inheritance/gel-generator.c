/* gel-generator.c */

#include "gel-generator.h"

G_DEFINE_TYPE (GelGenerator, gel_generator, G_TYPE_OBJECT)

#define GET_PRIVATE(o) \
  (G_TYPE_INSTANCE_GET_PRIVATE ((o), GEL_TYPE_GENERATOR, GelGeneratorPrivate))

typedef struct _GelGeneratorPrivate GelGeneratorPrivate;

struct _GelGeneratorPrivate {
	/*
	 * Use the private struct to store interal state of the instance.
	 * Each instance has his own private struct.
	 */
    guint counter;
};

static void
gel_generator_dispose (GObject *object)
{
  G_OBJECT_CLASS (gel_generator_parent_class)->dispose (object);
}

static void
gel_generator_finalize (GObject *object)
{
  G_OBJECT_CLASS (gel_generator_parent_class)->finalize (object);
}

static void
gel_generator_class_init (GelGeneratorClass *klass)
{
  /* This function (_class_init) is here just for reference, you can
   * ignore it for now and use "as-is". However everything here is
   * required, so, don't delete anything
   */
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (GelGeneratorPrivate));

  object_class->dispose = gel_generator_dispose;
  object_class->finalize = gel_generator_finalize;
}

static void
gel_generator_init (GelGenerator *self)
{
    /* This function is called for each instance, initialize the
	 * private struct here
	 */
	GelGeneratorPrivate *priv = GET_PRIVATE(self);
	priv->counter = 0;
}

GelGenerator*
gel_generator_new (void)
{
  /* You can also use this function 'as-is', it's irrelevant for now
   */
  return g_object_new (GEL_TYPE_GENERATOR, NULL);
}

guint
gel_generator_get_next(GelGenerator *self)
{
  /* This is a method. You can do whatever you want here. As you can see you
   * can access instance's internal data with the GET_PRIVATE macro
   */
  GelGeneratorPrivate *priv = GET_PRIVATE(self);
  return ++priv->counter;
}

