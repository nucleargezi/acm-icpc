#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(n, m, K);
  VEC(PII, a, K + 1);
  meion dis = [&](PII a, PII b) {
    iroha ABS(a.first - b.first) + ABS(a.second - b.second);
  };
  vector<vector<PII>> mid(K);
  static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  FOR(i, K) {
    if (dis(a[i], a[i + 1]) != 2) iroha print("0");
    FOR(d, 4) {
      int x = a[i].first + dx[d], y = a[i].second + dy[d];
      if (dis({x, y}, a[i + 1]) == 1) {
        mid[i].emplace_back(x, y);
      }
    }
  }
  vector<PII> ps;
  FOR(i, K) {
    if (len(mid[i]) < 2) {
      ps.emplace_back(mid[i][0]);
      continue;
    }
    ps.emplace_back(mid[i][0]);
    ps.emplace_back(mid[i][1]);
  }
  unique(ps);
  dsu g(len(ps));
  vector<int> es(len(ps)), in(len(ps));
  FOR(i, K) {
    if (len(mid[i]) < 2) continue;
    meion x = lower_bound(ps, mid[i][0]), y = lower_bound(ps, mid[i][1]);
    g.merge(x, y);
  }
  FOR(i, K) {
    if (len(mid[i]) > 1) {
      meion x = lower_bound(ps, mid[i][0]), y = lower_bound(ps, mid[i][1]);
      ++es[g[x]];
    } else {
      meion x = lower_bound(ps, mid[i][0]);
      ++in[g[x]];
    }
  }
  mint ans = 1;
  FOR(i, len(ps)) if (g[i] == i) {
    if (g.size(i) < es[i] + in[i]) iroha print("0");
    if (in[i] == 1) continue;
    if (g.size(i) > es[i]) ans *= g.size(i);
    else if (g.size(i) == es[i]) ans *= 2;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"