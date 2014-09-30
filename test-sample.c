#include <gcutter.h>
#include <gcutter/gcut-process.h>
#include <gtk/gtk.h>
#include <gdkcutter-pixbuf.h>

CUT_EXPORT void cut_setup(void)
{
  cut_set_fixture_data_dir(cut_get_test_directory(),
                           "fixtures",
                           NULL);
  gtk_init(NULL, NULL);
}

CUT_EXPORT void cut_teardown(void)
{
}

GdkPixbuf *load_fixture_image(gchar *filename)
{
  GError *error = NULL;
  gchar *path;
  GdkPixbuf *pixbuf;
  path = cut_build_fixture_data_path(filename, NULL);
  pixbuf = gdk_pixbuf_new_from_file(path, &error);
  gcut_assert_error(error);
  g_free(path);
  return pixbuf;
}

CUT_EXPORT void test_equal(void)
{
  GdkPixbuf *expected, *actual;
  expected = load_fixture_image("base.png");
  actual = load_fixture_image("copy.png");

  gdkcut_pixbuf_assert_equal(expected, actual, 0);
}

CUT_EXPORT void test_diff(void)
{
  GdkPixbuf *expected, *actual;
  expected = load_fixture_image("OK.png");
  actual = load_fixture_image("NG.png");

  gdkcut_pixbuf_assert_equal(expected, actual, 0);
}

CUT_EXPORT void test_blur10(void)
{
  GdkPixbuf *expected, *actual;
  expected = load_fixture_image("NG.png");
  actual = load_fixture_image("NG-blur-10.png");

  gdkcut_pixbuf_assert_equal(expected, actual, 0);
}

CUT_EXPORT void test_blur10_threshold(void)
{
  GdkPixbuf *expected, *actual;
  expected = load_fixture_image("NG.png");
  actual = load_fixture_image("NG-blur-10.png");

  gdkcut_pixbuf_assert_equal(expected, actual, 1000);
}
