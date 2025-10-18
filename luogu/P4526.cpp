#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/math/adaptive_simpson.hpp"
// #define tests

using RE = long double;
void Yorisou() {
  REA(a);
  adaptive_simpson seg([&](RE x) -> RE {
    if (x <= 0) return 0;
    RE exponent = a / x - x;
    return std::pow(x, exponent);
  });
  if (a < 0) iroha UL("orz");
  cout << fixed << std::setprecision(5);
  UL(seg.prod(1e-9L, 20, 1e-9L));
}
#include "YRS/Z_H/main.hpp"