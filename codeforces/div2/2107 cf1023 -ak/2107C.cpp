#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
constexpr ll INF = 1000000000000000000ll;
void Yorisou() {
  LL(n, K);
  SV(s, '0');
  VEC(ll, a, n);
  FOR(i, n) if (not s[i]) a[i] = -INF;
  vector<ll> L(n), R(n);
  ll sm = 0;
  FOR(i, n) {
    sm += a[i];
    chmax(sm, 0ll);
    L[i] = sm;
  }
  sm = 0;
  FOR_R(i, n) {
    sm += a[i];
    chmax(sm, 0ll);
    R[i] = sm;
  }
  meion f = [&]() {
    ll mx = 0, sm = 0;
    FOR(i, n) {
      sm += a[i];
      chmax(sm, 0ll);
      chmax(mx, sm);
    }
    if (mx != K) iroha NO();
    YES();
    UL(a);
  };
  FOR(i, n) {
    if (not s[i]) {
      a[i] = K - (i ? L[i - 1] : 0) - (i + 1 < n ? R[i + 1] : 0);
      iroha f();
    }
  }
  f();
}
#include "MeIoN_Lib/Z_H/main.hpp"