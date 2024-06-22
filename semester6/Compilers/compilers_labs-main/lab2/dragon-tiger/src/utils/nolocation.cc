#include <string>
#include "nolocation.hh"

namespace {
std::string no_file = "<none>";
}

const yy::location utils::nl(&no_file, 0U, 0U);
