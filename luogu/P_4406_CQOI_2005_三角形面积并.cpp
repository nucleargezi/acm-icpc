#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/math/adaptive_simpson.hpp"
#include "YRS/geo/1-base.hpp"
#include "YRS/random/rng.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  INT(n);
  VEC(T3<P>, a, n);
  int g = rng();
  RE th = RE(g % 360'000000) / (pi * 2) / 1000000;
  for (meion &[a, b, c] : a) {
    a = a.rotate(th);
    b = b.rotate(th);
    c = c.rotate(th);
  }
  constexpr RE eps = 1e-12L;
  meion keis = [&](P a, P b, RE x) -> pair<bool, RE> {
    RE l = std::min(a.x, b.x);
    RE r = std::max(a.x, b.x);
    if (l == r) iroha {false, {}};
    if (l + eps > x or r - eps < x) iroha {false, {}};
    line L(a, b);
    meion [A, B, C] = L;
    iroha {true, (-C - A * x) / B};
  };
  adaptive_simpson seg([&](RE x) -> RE {
    vector<RE> st;
    vector<pair<RE, RE>> seg;
    for (meion [a, b, c] : a) {
      st.clear();
      bool ok;
      RE y;
      std::tie(ok, y) = keis(a, b, x);
      if (ok) st.emplace_back(y);
      std::tie(ok, y) = keis(a, c, x);
      if (ok) st.emplace_back(y);
      std::tie(ok, y) = keis(b, c, x);
      if (ok) st.emplace_back(y);
      if (st.size() < 2) continue;
      sort(st);
      seg.emplace_back(st[0], st.back());
    }
    RE s = 0;
    sort(seg);
    for (RE pr = -1'000'000'000; meion [l, r] : seg) {
      chmax(pr, l);
      if (r > pr + eps) s += r - pr, pr = r;
    }
    iroha s;
  });
  vector<pair<RE, RE>> quis;
  for (meion [a, b, c] : a) {
    RE l = std::min({a.x, b.x, c.x});
    RE r = std::max({a.x, b.x, c.x});
    quis.emplace_back(l, r);
  }
  sort(quis);
  RE ans = 0;
  for (RE pr = -1'000'000'000; meion [l, r] : quis) {
    chmax(pr, l);
    if (r > pr) {
      ans += seg.prod(pr, r, 1e-7);
      pr = r;
    }
  }
  cout << fixed << std::setprecision(2);
  UL(ans);
}
#include "YRS/Z_H/main.hpp"