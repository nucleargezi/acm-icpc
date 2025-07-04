#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bfs1.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  int a, b, c, d, e, f;
  while (std::cin >> a >> b >> c >> d >> e >> f) {
    --a, --b, --c, --d, --e, --f;
    static constexpr int n = 8;
    static constexpr meion I = [&](int x, int y) -> int {
      iroha x * n + y;
    };
    graph g(n * n);
    meion ad = [&](int x, int y) {
      if (x == I(e, f) or y == I(e, f)) iroha;
      g.add(x, y, 1);
    };
    FOR(i, n) FOR(k, n) {
      if (i) ad(I(i - 1, k), I(i, k));
      if (k) ad(I(i, k - 1), I(i, k));
      if (i and k) ad(I(i - 1, k - 1), I(i, k));
      if (i and k + 1 < n) ad(I(i - 1, k + 1), I(i, k));
    }
    g.build();
    UL(std::format("Case {}: {}", ++t, bfs1(g, I(a, b)).first[I(c, d)]));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"