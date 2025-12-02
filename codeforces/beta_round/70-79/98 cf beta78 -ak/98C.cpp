#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/golden_search.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
constexpr RE eps = 1e-9;
void Yorisou() {
  LL(a, b, l);
  if (l <= max(a, b)) return print(min({a, b, l}));
  Z f = [&](RE th) -> RE {
    RE c = std::cos(th), s = std::sin(th);
    return a * s - l * c * s + b * c;
  };
  RE r = golden_search<RE, 1>(f, 0, pi / 2, 30).fi;
  if (r < eps) return print("My poor head =(");
  setp(7);
  print(r);
}
#include "YRS/Z_H/main.hpp"