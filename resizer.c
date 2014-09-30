#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gtk/gtk.h>

static gint width;
static gint height;
static gchar *method;
static gchar *input;

static GOptionEntry entries[] =
{
  {"width", 'w', 0, G_OPTION_ARG_INT, &width, "", ""},
  {"height", 'h', 0, G_OPTION_ARG_INT, &height, "", ""},
  {"method", 'm', 0, G_OPTION_ARG_STRING, &method, "", "Use nearest,tiles,bilinear, or hyper"},
  {"input", 'i', 0, G_OPTION_ARG_STRING, &input, "", "Specify original image"},
  {NULL}
};

int
main(int argc, char *argv[])
{
  GOptionContext *context;
  GError *error = NULL;
  GdkInterpType type;
  GdkPixbuf *pixbuf, *scaled;

  gtk_init(&argc, &argv);

  context = g_option_context_new("FILE");
  g_option_context_add_main_entries(context, entries, "resizer");
  if (!g_option_context_parse(context, &argc, &argv, &error)) {
    g_printerr("option parsing failed: %s\n", error->message);
    g_error_free(error);
    g_option_context_free(context);
    exit(1);
  }

  if (g_ascii_strcasecmp(method, "nearest") == 0) {
    type = GDK_INTERP_NEAREST;
  } else if (g_ascii_strcasecmp(method, "tiles") == 0) {
    type = GDK_INTERP_TILES;
  } else if (g_ascii_strcasecmp(method, "bilinear") == 0) {
    type = GDK_INTERP_BILINEAR;
  } else if (g_ascii_strcasecmp(method, "hyper") == 0) {
    type = GDK_INTERP_HYPER;
  } else {
    type = GDK_INTERP_NEAREST;
  }

  pixbuf = gdk_pixbuf_new_from_file(input, &error);
  scaled = gdk_pixbuf_scale_simple(pixbuf,
                                   width,
                                   height,
                                   type);
  if (!g_file_test(input, G_FILE_TEST_IS_REGULAR)) {
    g_printerr("invalid input file: %s\n", input);
    g_option_context_free(context);
    exit(1);
  }

  gdk_pixbuf_save(scaled, argv[1], "png", &error, NULL);
  if (error) {
    g_warning("%s\n", error->message);
    g_error_free(error);
    exit(1);
  }
  return 0;
}
