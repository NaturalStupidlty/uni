bin_PROGRAMS = dtiger

dtiger_SOURCES = driver.cc
dtiger_CXXFLAGS = -pedantic -Wall -fexceptions
dtiger_LDADD = ../ast/libast.a ../parser/libparser.a ../utils/libutils.a $(BOOST_PROGRAM_OPTIONS_LIB)
AM_LDFLAGS = $(BOOST_LDFLAGS)
CLEANFILES=
