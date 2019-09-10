AC_PREREQ(2.61)
AC_INIT([libbacktrace],1.0.0)
AM_INIT_AUTOMAKE([-Wall gnu foreign])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Check for programs
AM_PROG_AS
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_PROG_AWK
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG

# Check for dependent libraries.
PKG_CHECK_MODULES([LIBBASE], [libbase])
AC_SUBST([LIBBASE_CFLAGS])
AC_SUBST([LIBSELINUX_LIBS])

PKG_CHECK_MODULES([LIBUNWIND], [libunwind])
AC_SUBST([LIBUNWIND_CFLAGS])
AC_SUBST([LIBUNWIND_LIBS])

AC_ARG_WITH([core_includes],
    AC_HELP_STRING([--with-core-includes=@<:@dir@:>@],
       [Specify the location of the core headers]),
    [core_incdir=$withval],
    with_core_includes=no)

if test "x$with_core_includes" != "xno"; then
   CPPFLAGS="${CPPFLAGS} -I${core_incdir}"
   AC_SUBST(core_incdir,${core_incdir})
fi

AC_CONFIG_FILES([ \
    Makefile \
    libbacktrace.pc \
])
AC_OUTPUT
