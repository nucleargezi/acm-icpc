#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/geo/9-furthest_pair.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  meion [x, y] = furthest_pair(a);
  RE ans = dist<RE>(a[x], a[y]);
  print("{:.16f}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"