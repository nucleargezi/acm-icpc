#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/range_max_add.hpp"

void Yorisou() {
  INT(N, M);
  VEC(PII, a, N);
  vc<int> f;
  f.reserve(N << 1);
  for (Z &[l, r] : a) --l, f.ep(l), f.ep(r);
  sort(a, [&](var a, var b) {
    if (a.se - a.fi == b.se - b.fi) return a < b;
    return a.se - a.fi < b.se - b.fi;
  });
  unique(f);
  for (Z &[l, r] : a) l = lb(f, l), r = lb(f, r);
  range_max_add<int> seg(si(f), [](int) { return 0; });
  int s = inf<int>;
  for (int i = 0, k = 0; i < N; ++i) {
    var [l, r] = a[i];
    seg.apply(l, r, 1);
    while (seg.prod() >= M) {
      Z [ls, rs] = a[k++];
      chmin(s, f[r] - f[l] + f[ls] - f[rs]);
      seg.apply(ls, rs, -1);
    }
  }
  print(s == inf<int> ? -1 : s);
}

int main() { Yorisou(); }