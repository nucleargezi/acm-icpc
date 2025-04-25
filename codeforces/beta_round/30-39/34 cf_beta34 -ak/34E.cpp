#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;;
struct node {
  RE x, v, m;
  ll id;
  void hit(node &p) {
    RE a = ((m - p.m) * v + 2 * p.m * p.v) / (m + p.m);
    RE b = ((p.m - m) * p.v + 2 * m * v) / (m + p.m);
    std::tie(v, p.v) = pair(a, b);
  }
};
constexpr RE eps = 1e-7;
void Yorisou() {
  LL(n, t);
  vector<node> a(n);
  FOR(i, n) {
    IN(a[i].x, a[i].v, a[i].m);
    a[i].id = i;
  }
  RE s = 0;
  ll c = 20;
  sort(a, [](const node &x, const node &y) { iroha x.x < y.x; });
  while (s + eps < t) {
    RE go = t;
    ll pos = -1;
    FOR(i, n - 1) if (a[i].v > 0) {
      if (a[i + 1].v + eps > a[i].v) continue;
      if (chmin(go, s + (a[i + 1].x - a[i].x) / (a[i].v - a[i + 1].v))) {
        pos = i;
      }
    }
    FOR(i, 1, n) if (a[i].v < 0) {
      if (a[i - 1].v - eps < a[i].v) continue;
      if (chmin(go, s + (a[i].x - a[i - 1].x) / (a[i - 1].v - a[i].v))) {
        pos = i - 1;
      }
    }
    FOR(i, n) a[i].x += a[i].v * (go - s);
    if (~pos) a[pos].hit(a[pos + 1]);
    s = go;
  }
  vector<RE> ans(n);
  FOR(i, n) ans[a[i].id] = a[i].x;
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"