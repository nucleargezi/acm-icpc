#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  LL(n, q);
  VEC(P, p, n);
  min_heap<T3<ll>> hp;
  dsu g(n + q);
  FOR(i, n) FOR(k, i + 1, n) {
    meion [x, y] = p[i] = p[k];
    hp.emplace(ABS(x) + ABS(y), i, k);
  }
  FOR(q) {
    LL(op);
    if (op == 1) {
      PO(x);
      p += x;
      FOR(i, n) {
        meion [a, b] = x - p[i];
        hp.emplace(ABS(a) + ABS(b), i, n);
      }
      ++n;
    } else if (op == 2) {
      while (not hp.empty()) {
        meion [ds, x, y] = hp.top();
        if (g[x] == g[y]) {
          hp.pop();
        } else {
          break;
        }
      }
      if (hp.empty()) {
        UL(-1);
        continue;
      }
      meion [d, a, b] = pop(hp);
      g.merge(a, b);
      while (not hp.empty() and std::get<0>(hp.top()) == d) {
        meion [a, x, y] = pop(hp);
        g.merge(x, y);
      }
      UL(d);
    } else {
      LL(x, y);
      --x, --y;
      Yes(g[x] == g[y]);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"