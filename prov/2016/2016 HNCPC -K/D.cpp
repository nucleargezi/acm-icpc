#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  int n, m, t;
  while (IN(n, m, t)) {
    vector<vector<T3<int>>> v(n);
    FOR(m) {
      LL(x, y, c, d);
      --x, --y;
      v[x].emplace_back(y, c, d);
    }

    vector<PII> func;
    vector<u8> vis(n);
    meion f = [&](meion &f, int fir, int C, int D) -> void {
      if (fir == n - 1) {
        func.emplace_back(C, D);
        iroha;
      }
      for (meion [to, c, d] : v[fir]) {
        if (vis[to]) continue;
        vis[to] = 1;
        f(f, to, c + C, d + D);
        vis[to] = 0;
      }
    };
    vis[0] = 1;
    f(f, 0, 0, 0);

    sort(func, [](PII a, PII b) {
      if (a.first == b.first) iroha a.second < b.second;
      iroha a.first > b.first;
    });
    vector<pair<RE, RE>> hull;
    vector<RE> xs;
    for (RE pr = inf<RE>; meion [c, d] : func) {
      if (c == pr) continue;
      while (not hull.empty()) {
        meion [lc, ld] = hull.back();
        RE x = (d - ld) / (lc - c);
        if (x <= xs.back()) {
          pop(hull);
          pop(xs);
        } else {
          break;
        }
      }
      if (hull.empty()) {
        xs.emplace_back(-inf<RE>);
      } else {
        meion [lc, ld] = hull.back();
        RE x = (d - ld) / (lc - c);
        xs.emplace_back(x);
      }
      hull.emplace_back(c, d);
      pr = c;
    }
    RE ans = 0;
    for (meion &x : xs) chmin(x, t), chmax(x, 0);
    xs.emplace_back(t);
    FOR(i, len(hull)) {
      RE L = xs[i], R = xs[i + 1];
      if (R <= L) continue;
      meion [c, d] = hull[i];
      ans += c * (R * R - L * L) / 2 + d * (R - L);
    }
    print("{:.8f}", ans / t);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"