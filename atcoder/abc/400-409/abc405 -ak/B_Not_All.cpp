#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  map<ll, ll> M;
  FOR(i, n) ++M[a[i]];
  FOR(i, 1, m + 1) if (not M[i]) iroha UL(0);
  FOR_R(i, n) {
    if (not --M[a[i]]) iroha UL(n - i);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"