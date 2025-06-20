#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, K);
  S(p);
  SV(vis, '0');
  while (len(vis) < n) vis.emplace_back(0);
  string ans(n, 0);
  vector<int> go;
  meion rv = vis;
  FOR_R(i, n) {
    if (vis[i]) {
      FOR(k, len(p)) {
        if (ans[k + i] and ans[k + i] != p[k]) iroha UL("No solution");
        ans[k + i] = p[k];
        vis[k + i] = 1;
      }
    }
  }
  FOR(i, n) if (not vis[i]) go += i;
  meion f = [&](meion &f, int n) -> void {
    if (n == len(ans)) {
      UL(ans);
      exit(0);
    }
    ll l, r;
    if (vis[n]) l = ans[n], r = l + 1;
    else l = 'a', r = l + K;
    FOR(i, l, r) {
      ans[n] = i;
      if (n < len(p) - 1) {
        f(f, n + 1);
      } else if (rv[n - len(p) + 1]) {
        if (ans.substr(n - len(p) + 1, len(p)) == p) {
          f(f, n + 1);
        }
      } else {
        if (ans.substr(n - len(p) + 1, len(p)) != p) {
          f(f, n + 1);
        }
      }
    }
  };
  f(f, 0);
  UL("No solution");
}
#include "MeIoN_Lib/Z_H/main.hpp"