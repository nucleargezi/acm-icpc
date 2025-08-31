#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/max_independent_set.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(PII, e, m);
  static constexpr int N = 50;
  ull v[N]{};
  for (meion &[x, y] : e) {
    --x, --y;
    v[x] |= 1ull << y;
    v[y] |= 1ull << x;
  }
  max_independent_set_solver seg;
  meion f = [&]() -> void {
    graph g(n);
    FOR(i, n) v[i] = ~v[i];
    FOR(i, n) FOR(k, i + 1, n) if (v[i] >> k & 1) {
      g.add(i, k);
    }
    g.build();
    meion [se, c] = seg.keis(g);
    UL(len(se), c);
    for (int &x : se) ++x;
    UL(se);
  };
  f(), f();
}
#include "YRS/Z_H/main.hpp"