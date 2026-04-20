#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q, t);
  --t;
  VEC(ll, a, N);
  graph gt(N);
  gt.sc();
  hld v(gt, t);
  bit_t<monoid_add<ll>> f(N), g(N);
  vc<ll> s = pre_sum(rearrange(a, inverse(v.L)));

  Z ad = [&](int x, ll w) -> void {
    f.multiply(v.L[x], w);
    g.multiply(v.L[x], w * v.d[x] + w);
  };

  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y, w);
      --x, --y;
      int c = v.lca(x, y);
      ad(x, w);
      ad(y, w);
      ad(c, -w);
      if (v.fa[c] != -1) ad(v.fa[c], -w);
    } else if (op == 2) {
      INT(i);
      --i;
      print(a[i] + f.prod(v.L[i], v.R[i]));

    } else {
      INT(i);
      --i;
      int l = v.L[i], r = v.R[i];
      print(s[v.R[i]] - s[v.L[i]] + g.prod(l, r) - 1LL * v.d[i] * f.prod(l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}