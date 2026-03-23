#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/pr/ptable.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/factors.hpp"
#include "YRS/tr/hld.hpp"

constexpr int sz = 1'000'000, B = 200;
vc<int> pt = ptable(sz), lpf = lpf_table(sz), to(sz, -1);
void Yorisou() {
  for (int t = 0; int x : pt) to[x] = t, t++;
  
  INT(N);
  vc<int> a(N);
  IN(a[0]);

  VEC(T3<int>, es, N - 1);
  graph g(N);
  vc<int> fa(N, -1);
  for (int t = 1; Z &[c, x, y] : es) {
    --x, --y;
    g.add(y, t);
    fa[t] = y;
    ++t;
  }
  g.build();
  hld v(g, 0);
  
  vc<array<int, B>> c(N);
  static set<int> se[200000];
  for (Z [e, p] : factor_by_lpf(a[0], lpf)) {
    int id = to[e];
    if (id < 200) c[0][id] += p;
    else se[id - 200].eb(0);
  }
  for (int t = 0; Z [w, x, y] : es) {
    ++t;
    vector fac = factor_by_lpf(w, lpf);
    int lca = v.lca(x, y), ff = fa[lca];
    for (Z &[e, p] : fac) {
      int id = to[e];
      if (id >= 200) {
        id -= 200;
        for (Z [l, r] : v.dec(x, y, 0)) {
          if (l > r) swap(l, r);
          Z it = se[id].lower_bound(l);
          if (it != se[id].ed() and (*it) <= r) {
            p -= 1;
            break;
          }
        }
        continue;
      }
      int d = c[x][id] + c[y][id] - c[lca][id] - (ff == -1 ? 0 : c[ff][id]);
      p -= d;
      chmax(p, 0);
    }
    c[t] = c[fa[t]];
    int val = 1;
    for (Z &[e, p] : fac) if (p) {
      FOR(p) val *= e;
      int id = to[e];
      if (id < 200) c[t][id] += p;
      else se[id - 200].eb(v.L[t]);
    }
    a[t] = val;
  }
  print(a);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"