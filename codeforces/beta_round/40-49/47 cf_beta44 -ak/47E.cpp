#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
using P = pair<RE, RE>;
constexpr RE g = 9.8L;
void Yorisou() {
  LL(n, v);
  VEC(RE, a, n);
  LL(m);
  VEC(P, wal, m);
  sort(wal);
  wal.emplace_back(2'000'000, 2'000'000);
  ++m;
  vector<P> ans(n);
  meion keis = [&](RE ang, P p) {
    meion [x, y] = p;
    RE dx = v * std::cos(ang);
    RE t = x / dx;
    y = v * std::sin(ang) * t - g * t * t / 2;
    if (y < 0) {
      y = 0;
      t = binary_search_real([&](RE m) {
        iroha v * std::sin(ang) * m - g * m * m / 2 >= 0;
      }, 0, t);
      x = dx * t;
    }
    iroha P{x, y};
  };
  meion pass = [&](RE ang, P p) {
    iroha keis(ang, p).second >= p.second;
  };
  for (int i = 0; int id : argsort(a)) {
    while (i < m and pass(a[id], wal[i])) ++i;
    ans[id] = keis(a[id], wal[i]);
  }
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"