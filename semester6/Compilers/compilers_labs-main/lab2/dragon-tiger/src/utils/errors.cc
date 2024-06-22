#include <cstdlib>
#include <iostream>

#include "errors.hh"

namespace utils {

void non_fatal_error(const yy::location &l, const std::string &m) {
  std::cerr << l << ": " << m << std::endl;
}

void non_fatal_error(const std::string &m) { std::cerr << m << std::endl; }

void error(const yy::location &l, const std::string &m) {
  non_fatal_error(l, m);
  exit(EXIT_FAILURE);
}

void error(const std::string &m) {
  non_fatal_error(m);
  exit(EXIT_FAILURE);
}

} // namespace utils
