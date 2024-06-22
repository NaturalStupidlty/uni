AC_INIT([dragon-tiger], [submission], [])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall subdir-objects foreign])
AM_SILENT_RULES([yes])
AC_CONFIG_HEADERS([config.h])
AC_PROG_BISON([2.7])
AC_PROG_YACC
AC_PROG_LEX
AC_PROG_CXX
AM_PROG_AS
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AM_PROG_AR
AC_PROG_RANLIB

AC_REQUIRE_AUX_FILE([tap-driver.sh])

AX_BOOST_BASE([1.48],, [AC_MSG_ERROR([dragon-tiger needs Boost, but it was not found in your system])])
AX_BOOST_PROGRAM_OPTIONS


AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/ast/Makefile
                 src/driver/Makefile
                 src/parser/Makefile
                 src/utils/Makefile
                ])

AC_OUTPUT
