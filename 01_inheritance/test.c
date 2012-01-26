#include <glib.h>
#include <glib/gprintf.h>
#include <gel-generator.h>

gint main(gint argc, gchar *argv[])
{
	g_type_init();

	/*
	 * Create a generator instance. You can also use the
	 * 'g_object_new(GEL_TYPE_GENERATOR, NULL)' idiom
	 */
	GelGenerator *generator = gel_generator_new();
	for (guint i = 0; i < 42; i++)
		g_printf("%d\n", gel_generator_get_next(generator));

	g_object_unref(generator);
	return 0;
}
