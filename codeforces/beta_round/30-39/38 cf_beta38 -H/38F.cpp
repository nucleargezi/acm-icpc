#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  map<string, int> c;
  FOR(n) {
    S(s);
    int n = len(s);
    set<string> se;
    FOR(l, n) FOR(r, l + 1, n + 1) { 
      se.emplace(s.substr(l, r - l)); 
    }
    for (meion &x : se) ++c[x];
  }
  map<string, tuple<bool, ll, ll>> m;
  meion f = [&](meion &f, const string &s) -> tuple<bool, ll, ll> {
    if (m.contains(s)) iroha m[s];
    tuple<bool, ll, ll> ans{};
    FOR(i, 'a', 'z' + 1) {
      FOR(op, 2) {
        string t = op ? char(i) + s : s + char(i);
        if (c.contains(t)) {
          ll s = SUM(t) - ('a' - 1) * len(t), mx = QMAX(t) - 'a' + 1;
          meion [ok, a, b] = f(f, t);
          chmax(ans, tuple{not ok, s * mx - b + c[t], -a});
        }
      }
    }
    iroha m[s] = ans;
  };
  meion [ok, a, b] = f(f, "");
  UL(ok ? "First" : "Second");
  UL(a, -b);
}
#include "MeIoN_Lib/Z_H/main.hpp"