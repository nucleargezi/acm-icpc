#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/9-furthest_pair.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  FOR(i, n) a[i] *= 1000000;
  meion [i, k] = furthest_pair(a);
  UL(distance(a[i], a[k]) / 1000000);
}
#include "MeIoN_Lib/Z_H/main.hpp"