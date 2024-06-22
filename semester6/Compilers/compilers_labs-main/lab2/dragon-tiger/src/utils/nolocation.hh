#ifndef NOLOCATION_HH
#define NOLOCATION_HH

#include "../parser/location.hh"

namespace utils {
// This represents an absence of location in the source code
// (such as primitive function declaration).
extern const yy::location nl;
}
#endif // NOLOCATION_HH
