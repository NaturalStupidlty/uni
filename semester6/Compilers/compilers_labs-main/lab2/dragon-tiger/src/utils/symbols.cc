#include <unordered_set>

#include "symbols.hh"

namespace {

struct Hash {
  size_t operator()(std::string const *s) const noexcept {
    return std::hash<std::string>()(*s);
  }
};

struct Cmp {
  bool operator()(std::string const *a, std::string const *b) const noexcept {
    return *a == *b;
  }
};

std::unordered_set<const std::string *, Hash, Cmp> *symbols;

} // namespace

namespace utils {

Symbol::Symbol(std::string const &s) {
  if (symbols == nullptr)
    symbols = new std::unordered_set<const std::string *, Hash, Cmp>();
  auto f = symbols->find(&s);
  if (f == symbols->end())
    str = *symbols->insert(new std::string(s)).first;
  else
    str = *f;
}

} // namespace utils
