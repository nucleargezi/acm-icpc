#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  map<ll, ll> M;
  FOR(i, n) ++M[a[i]];
  ll s = 0, mx = 0;
  for (meion [x, y] : M) {
    chmax(mx, y);
  }
  UL(mx, len(M));
}
#include "MeIoN_Lib/Z_H/main.hpp"