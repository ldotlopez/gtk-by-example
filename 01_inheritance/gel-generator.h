/* gel-generator.h */

#ifndef _GEL_GENERATOR
#define _GEL_GENERATOR

#include <glib-object.h>

G_BEGIN_DECLS

/*
 * Everything below this is the 'boilerplate' stuff.
 * It's necesary to make the class work with all the GObject infrastructure.
 * After those declarations you can find the interesting stuff
 */

#define GEL_TYPE_GENERATOR gel_generator_get_type()

#define GEL_GENERATOR(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GEL_TYPE_GENERATOR, GelGenerator))

#define GEL_GENERATOR_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), GEL_TYPE_GENERATOR, GelGeneratorClass))

#define GEL_IS_GENERATOR(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GEL_TYPE_GENERATOR))

#define GEL_IS_GENERATOR_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), GEL_TYPE_GENERATOR))

#define GEL_GENERATOR_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GEL_TYPE_GENERATOR, GelGeneratorClass))

typedef struct {
  GObject parent;
} GelGenerator;

typedef struct {
  GObjectClass parent_class;
} GelGeneratorClass;

GType gel_generator_get_type (void);

GelGenerator* gel_generator_new (void);

/*
 * Here you can add your methods, basic C
 */
guint
gel_generator_get_next(GelGenerator *self);

G_END_DECLS

#endif /* _GEL_GENERATOR */

