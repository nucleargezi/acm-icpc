#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, K);
  map<ll, ll> m;
  FOR(n) {
    LL(idx, t);
    ++m[t + K - idx];
  }
  ll ans = -inf<ll>;
  for (ll inq = 0, pr = 0; meion [x, sz] : m) {
    inq -= x - pr;
    chmax(inq, 0);
    chmax(ans, x + sz - 1 + inq);
    inq += sz;
    pr = x;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"