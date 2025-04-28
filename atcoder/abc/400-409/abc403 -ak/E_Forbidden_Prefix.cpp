#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  static int tr[2145141][26], c[2145141];
  static bool cut[2145141];
  ll tot = 0, ans = 0;
  LL(q);
  FOR(q) {
    LL(op);
    S(s);
    ll n = len(s), p = 0;
    vector<ll> path;
    FOR(i, n) {
      ll c = s[i] - 'a';
      if (not tr[p][c]) tr[p][c] = ++tot;
      p = tr[p][c];
      if (cut[p]) {
        p = -1;
        break;
      }
      path += p;
    }
    if (~p) {
      if (op == 1) {
        ans -= c[p];
        for (ll x : path) c[x] -= c[p];
        cut[p] = 1;
      } else {
        for (ll x : path) ++c[x];
        ++ans;
      }
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"