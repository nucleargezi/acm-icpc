#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/kinbo.hpp"
#include "YRS/ds/seg/range_sum_point_add.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(uint, a, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  kinbo ds(g);
  vc<uint> dat(si(ds));
  FOR(i, N) ds.vs(i, [&](int x) { dat[x] += a[i]; });
  range_sum_point_add<Add<uint>> seg(dat);

  uint s = 0;
  FOR(Q) {
    INT(op, x, y);
    x ^= s, y ^= s;
    --x;
    if (op == 0) {
      s = 0;
      ds.range(x, 0, y + 1, [&](int l, int r) { s += seg.prod(l, r); });
      print(s);
    } else {
      int d = y - a[x];
      ds.vs(x, [&](int i) { seg.add(i, d); });
      a[x] = y;
    }
  }
}

int main() {
  Yorisou();
  return 0;
}