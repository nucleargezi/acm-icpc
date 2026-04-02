#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n - 1);
  VEC(ll, c, n - 2);
  map<ll, ll> aa, bb, cc;
  FOR(i, n) ++aa[a[i]];
  FOR(i, n - 1) ++bb[b[i]];
  FOR(i, n - 2) ++cc[c[i]];
  for (meion [x, y] : bb) aa[x] -= y;
  for (meion [x, y] : aa) if (y & 1) UL(x);
  for (meion [x, y] : cc) bb[x] -= y;
  for (meion [x, y] : bb) if (y & 1) UL(x);
}
#include "MeIoN_Lib/Z_H/main.hpp"