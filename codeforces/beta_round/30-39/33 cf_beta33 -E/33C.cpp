#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<ll> b(n);
  FOR(i, n) b[i] = -a[i];
  Seg<monoid_add<ll>> A(a), B(b);
  vector<ll> L(n), R(n);
  FOR(i, n) {
    chmax(L[i], B.prod(0, i + 1) - A.prod(0, i + 1));
  }
  FOR(i, n) {
    chmax(R[i], B.prod(i, n) - A.prod(i, n));
  }
  ll ans = MAX(qmax(L), qmax(R));
  FOR(i, 1, n) chmax(L[i], L[i - 1]);
  FOR_R(i, n - 1) chmax(R[i], R[i + 1]);
  FOR(i, n - 1) {
    chmax(ans, L[i] + R[i + 1]);
  }
  UL(ans + SUM(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"