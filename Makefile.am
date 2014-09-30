AM_INCLUDES = \
        -I$(srcdir) \
        -I$(top_srcdir)

AM_CFLAGS = \
        $(GTHREAD_CFLAGS) \
        $(GLIB_CFLAGS) \
        $(GTK_CFLAGS) \
        $(GDKCUTTER_PIXBUF_CFLAGS) \
        -g -Wall

AM_LDFLAGS = \
        -module \
        -rpath "`pwd`/.libs" \
        -avoid-version \
        -no-undefined

LIBS = \
        $(GTHREAD_LIBS) \
        $(GLIB_LIBS) \
        $(GTK_LIBS) \
        $(GDKCUTTER_PIXBUF_LIBS)

bin_PROGRAMS = resizer

bin_SOURCES = resizer.c

lib_LTLIBRARIES = libsample.la
libsample_la_SOURCES = sample.c

libsample_la_LDFLAGS = \
  -version-info 1:0:0 \
  -no-undefined \
  $(LIBTOOL_EXPORT_OPTIONS)

libsample_la_CFLAGS = \
  $(GTK_CFLAGS) \
  -g -Wall

libsample_la_LIBADD = \
  $(GTK_LIBS)

noinst_LTLIBRARIES = \
	test_sample.la

test_sample_la_LIBADD = \
        $(top_builddir)/libsample.la

test_sample_la_SOURCES = test-sample.c
