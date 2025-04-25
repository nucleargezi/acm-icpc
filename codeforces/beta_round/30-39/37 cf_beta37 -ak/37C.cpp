#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  map<ll, ll> M;
  meion I = argsort(a);
  static int tr[10000000][2], tot;
  static bool ed[10000000];
  vector<string> ans(n);
  FOR(i, n) {
    ll L = a[I[i]];
    string res;
    int p = 0;
    FOR(i, L) {
      FOR(bit, 2) {
        if (not tr[p][bit]) {
          tr[p][bit] = ++tot;
        }
        if (tr[p][bit] and not ed[tr[p][bit]]) {
          p = tr[p][bit];
          res += '0' + bit;
          break;
        }
      }
    }
    if (len(res) != L) iroha NO();
    ed[p] = 1;
    FOR_R(i, 1, tot + 1) {
      if (ed[tr[i][0]] and ed[tr[i][1]]) {
        ed[i] = 1;
      }
    }
    ans[I[i]] = res;
  }
  YES();
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"