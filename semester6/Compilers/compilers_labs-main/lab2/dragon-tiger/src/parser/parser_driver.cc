#include "parser_driver.hh"
#include "../utils/errors.hh"
#include "tiger_parser.hh"

bool ParserDriver::parse(const std::string &f) {
  file = f;
  lex_begin();
  yy::tiger_parser parser(*this);
  parser.set_debug_level(trace_parser);
  int res = parser.parse();
  lex_end();
  return res == 0;
}
