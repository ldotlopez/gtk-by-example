#include <glib.h>
#include <glib/gprintf.h>
#include <gel-clock.h>

void
tick_cb(void)
{
	g_printf("Clock has made 'tick'\n");
}

gint main(gint argc, gchar *argv[])
{
	g_type_init();

	GMainLoop *loop = g_main_loop_new(NULL, FALSE);
	GelClock *clock = gel_clock_new();
	g_signal_connect(clock, "tick", tick_cb, NULL);

	g_main_loop_run(loop);
}
