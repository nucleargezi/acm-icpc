#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, w, n);
  vector<vector<int>> v(n);
  FOR(i, n) v[a[i] - 1] += i;
  meion run_length = [&](vector<int> &v) -> vector<PII> {
    vector<PII> seg;
    for (int x : v) {
      if (seg.empty() or seg.back().second + 1 != x) {
        seg += PII(x, x);
      } else {
        seg.back().second = x;
      }
    }
    vector<PII> ret;
    for (int pr = 0; meion [l, r] : seg) {
      if (l - pr) ret += PII(pr, l - 1);
      pr = r + 1;
    }
    if (seg.empty())
      ret += PII(0, n - 1);
    else if (seg.back().second != n - 1)
      ret.emplace_back(seg.back().second + 1, n - 1);
    iroha ret;
  };
  vector<ll> ans(n);
  FOR(i, n) {
    meion seg = run_length(v[i]);
    ll res = 0;
    for (meion [l, r] : seg) {
      res += r - l + 1 + w[i];
    }
    FOR(k, 1, len(seg)) {
      meion [l, r] = seg[k];
      meion [_, pr] = seg[k - 1];
      res -= MAX(0ll, w[i] - (l - pr - 1));
    }
    ans[i] = res;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"