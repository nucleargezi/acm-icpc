#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segd.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/un/dsu.hpp"

using MX = Add<int>;
using DS = segd<MX>;
using np = DS::np;

void Yorisou() {
  INT(N, M);
  dsu fa(N);
  DS seg(0, N);
  vc<np> t(N);
  VEC(int, a, N);
  vc<int> to(N);
  FOR(i, N) {
    --a[i];
    t[i] = seg.add(t[i], a[i], 1);
    to[a[i]] = i + 1;
  }

  FOR(M) {
    INT(a, b);
    if (min(a, b) == 0) continue;
    a = fa[a - 1], b = fa[b - 1];
    if (not fa.merge(a, b)) continue;
    int c = fa[a];
    t[c] = seg.merge(t[c], t[a ^ b ^ c]);
  }

  INT(Q);
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(i, k);
      if (min(i, k) == 0) continue;
      i = fa[i - 1];
      if (seg.prod(t[i]) < k) print(-1);
      else print(to[seg.maxr(t[i], [&](int s) { return s < k; }, 0)]);
    } else {
      INT(a, b);
      if (min(a, b) == 0) continue;
      a = fa[a - 1], b = fa[b - 1];
      if (not fa.merge(a, b)) continue;
      int c = fa[a];
      t[c] = seg.merge(t[c], t[a ^ b ^ c]);
    }
  }
}

int main() { Yorisou(); }