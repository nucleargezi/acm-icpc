#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(string, s, n);
  VEC(string, t, n);
  meion rol = [&]() {
    vector<string> ret(n, string(n, ' '));
    FOR(i, n) FOR(k, n) {
      ret[k][n - i - 1] = s[i][k];
    }
    s = ret;
  };
  ll ans = inf<ll>;
  FOR(i, 4) {
    ll r = 0;
    FOR(i, n) FOR(k, n) {
      r += s[i][k] != t[i][k];
    }
    chmin(ans, r + i);
    rol();
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"