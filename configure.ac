#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cutter-with-image-test], [0.1.0], [hayashi@clear-code.com])
AC_CONFIG_SRCDIR([test-sample.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

# Checks for libraries.

PKG_CHECK_MODULES(GLIB, glib-2.0)
PKG_CHECK_MODULES(GTK, gtk+-2.0)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CHECK_CUTTER
AC_CHECK_GDKCUTTER_PIXBUF

AM_CONDITIONAL([WITH_CUTTER], [test "$ac_cv_use_cutter" != "no"])
if test "$ac_cv_use_cutter" != "no"; then
  AC_DEFINE(WITH_CUTTER, 1, [Define to 1 if you use Cutter])
  have_cutter=yes
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

glib_version=`pkg-config --modversion glib-2.0`
gtk_version=`pkg-config --modversion gtk+-2.0`

echo
echo "Configure Result:"
echo
echo "  prefix             : ${prefix}"
echo "  GLib               : ${glib_version}"
echo "  GTK+               : ${gtk_version}"
echo "  Cutter             : ${have_cutter}"
echo
