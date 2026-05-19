#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/fset.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/pr/enum_density_range.hpp"

void yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(i, N) g[--a[i]].ep(i);

  fset se(N << 1 | 1);
  vc<vc<int>> v(N << 1 | 1);
  dsu un(N);
  Z ke = [&](int l, int r, int t) -> void {
    chmax(l, 0), chmin(r, N);
    int of = N;
    FOR(i, l, r) {
      v[of].ep(i), se.emplace(of);
      if (a[i] == t) ++of;
      else --of;
      int nx = -1;
      while (1) {
        int k = se.prev(of - 1);
        if (k >= 0) {
          for (var x : v[k]) un.merge(x, i);
          v[k].clear();
          se.erase(k);
          nx = k;
        } else break;
      }
      if (nx != -1) v[nx].ep(i), se.eb(nx);
    }
    for (int x : se.get_all()) se.erase(x), v[x].clear();
  };
  FOR(t, N) if (si(g[t]) > 1) {
    for (var [l, r] : enum_density_range(2, g[t])) {
      ke(l, r, t);
    }
  }
  print(un.c);
}

int main() {
  INT(T);
  FOR(T) yorisou();
  return 0;
}