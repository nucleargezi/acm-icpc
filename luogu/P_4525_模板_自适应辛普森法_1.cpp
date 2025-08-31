#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/math/adaptive_simpson.hpp"
// #define tests

using RE = long double;
void Yorisou() {
  REA(a, b, c, d, l, r);
  adaptive_simpson seg([&](RE x) { iroha(c * x + d) / (a * x + b); });

  cout << fixed << setprecision(6);
  UL(seg.prod(l, r, 1e-9L));
}
#include "YRS/Z_H/main.hpp"