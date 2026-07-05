#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_sayo.hpp"
#include "YRS/al/am/sum_add.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }

  hld v(g, 0);
  hld_sayo<int, Sum_add<ll>> seg(v);

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a);
      --a;
      seg.apply_sub(a, 1);
    } else {
      INT(a, b);
      --a, --b;
      seg.apply(a, b, 1);
    }
    ll s = seg.prod() >> 1;
    int i = v.V[seg.seg.maxr([&](ll x) { return x <= s; }, 0)];
    print(v.max_lo(i, [&](int x) { return seg.prod_sub(x) > s; }) + 1);
  }
}

int main() {
  Yorisou();
  return 0;
}