#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/10-triangle_area.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
constexpr RE eps = 1e-8L;
void Yorisou() {
  VEC(ll, sz, 3);
  vector<vector<P>> p;
  vector<vector<RE>> dis;
  FOR(i, 3) {
    VEC(P, v, sz[i]);
    p += v;
    vector<RE> rg;
    FOR(k, 1, sz[i]) {
      rg += dist(v[k], v[k - 1]);
    }
    dis += pre_sum(rg);
  }
  vector t = dis[0] + dis[1] + dis[2];
  sort(t);

  meion get_p = [&](RE t, int i) -> P {
    if (sz[i] == 1) iroha p[i][0];
    if (t >= dis[i].back()) iroha p[i].back();
    ll idx = upper_bound(dis[i], t);
    RE G = (t - dis[i][idx - 1]) / (dis[i][idx] - dis[i][idx - 1]);
    if (G <= eps) iroha p[i][idx - 1];
    iroha p[i][idx - 1] + (p[i][idx] - p[i][idx - 1]) * G;
  };
  meion keis = [&](RE t) -> RE {
    iroha triangle_area(get_p(t, 0), get_p(t, 1), get_p(t, 2));
  };
  RE ans = keis(0);
  FOR(i, len(t) - 1) {
    meion l = t[i], r = t[i + 1];
    if (ABS(r - l) <= eps) continue;
    FOR(i, 0721 >> 3) {
      RE x = (l + l + r) / 3, y = (r + r + l) / 3;
      if (keis(x) > keis(y)) {
        r = y;
      } else {
        l = x;
      }
    }
    chmax(ans, keis(l));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"