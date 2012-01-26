AC_PREREQ([2.68])
AC_INIT([gtk-by-example], [0.0.1], [ldotlopez@gmail.com])
AM_INIT_AUTOMAKE([1.10 -Wno-portability foreign])
# AC_CONFIG_SRCDIR([01_inheritance/gel-generator.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG(PKG_CONFIG, pkg-config)

# Checks for libraries.
GLIB_VERSION="2.0.0"
glib_modules="\
  glib-2.0 >= $GLIB_VERSION,    \
  gobject-2.0 >= $GLIB_VERSION"
PKG_CHECK_MODULES(GLIB, $glib_modules)
PACKAGE_CFLAGS="-Wall -Werror -Wl,--no-as-needed -std=c99 $GLIB_CFLAGS"
PACKAGE_LIBS="$GLIB_LIBS"

AC_SUBST(PACKAGE_CFLAGS)
AC_SUBST(PACKAGE_LIBS)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
01_inheritance/Makefile
02_signals/Makefile
Makefile])

AC_OUTPUT
