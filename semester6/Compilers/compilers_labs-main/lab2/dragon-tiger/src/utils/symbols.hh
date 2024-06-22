#ifndef SYMBOLS_HH
#define SYMBOLS_HH

#include <ostream>
#include <string>

namespace utils {

// Symbol is a small implementation of the flyweight pattern. Strings are
// stored through a pointer. Similar strings will use the same instance in
// memory, and comparaison is fast since it boils down to comparing two
// pointers.
//
// This implementation is not thread-safe, but the dragon-tiger compiler
// is single-threaded.

class Symbol {
  const std::string *str;

public:
  Symbol() : str(nullptr) {}
  Symbol(std::string const &);
  Symbol(Symbol const &s) : str(s.str) {}
  size_t hash() const noexcept { return std::hash<std::string>()(*str); }
  std::string const &get() const { return *str; }
  operator std::string() const { return *str; }
  bool operator==(Symbol const &other) const { return str == other.str; }
  bool operator!=(Symbol const &other) const { return str != other.str; }
  friend std::ostream &operator<<(std::ostream &o, Symbol const &s) {
    return o << (s.str ? *s.str : "<null>");
  }
};

} // namespace utils

namespace std {

template <> class hash<utils::Symbol> {
public:
  size_t operator()(utils::Symbol const &s) const noexcept { return s.hash(); }
};

} // namespace std

#endif // SYMBOLS_HH
