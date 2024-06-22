#ifndef ERRORS_HH
#define ERRORS_HH

#include "../parser/tiger_parser.hh"

namespace utils {

[[noreturn]] void error(const yy::location &l, const std::string &m);
[[noreturn]] void error(const std::string &m);

void non_fatal_error(const yy::location &l, const std::string &m);
void non_fatal_error(const std::string &m);

} // namespace utils

#endif // ERRORS_HH
