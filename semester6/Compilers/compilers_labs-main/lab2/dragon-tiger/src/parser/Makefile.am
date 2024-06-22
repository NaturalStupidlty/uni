AM_YFLAGS = -v --report-file=bison-report.txt --graph=bison-graph.gv -Wno-yacc
AM_LFLAGS = -otiger_lexer.cc

noinst_LIBRARIES = libparser.a
libparser_a_SOURCES = tiger_parser.yy tiger_lexer.ll parser_driver.cc parser_driver.hh
AM_CXXFLAGS = -pedantic -Wall

EXTRA_DIST=tiger_parser.hh tiger_parser.cc tiger_lexer.cc location.hh stack.hh position.hh
CLEANFILES=tiger_parser.hh tiger_parser.cc tiger_lexer.cc location.hh stack.hh position.hh
