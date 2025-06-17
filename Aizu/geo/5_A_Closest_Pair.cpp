#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/4-closest_pair.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  LL(n);
  vector<P> a(n);
  FOR(i, n) {
    REA(x, y);
    a[i] = {x * 1'000'000'0, y * 1'000'000'0};
  }
  meion [j, k] = closest_pair(a);
  UL(distance(a[j], a[k]) / 1'000'000'0);
}
#include "MeIoN_Lib/Z_H/main.hpp"