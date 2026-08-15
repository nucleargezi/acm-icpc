#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_mono_rev.hpp"
#include "YRS/al/m/max_subarray_sum.hpp"

using MX = Max_subarr_sum<ll>;
using DS = wblt_mono_rev<MX>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  constexpr int lm = 524288 * 7 / 5;
  DS g(lm);
  vc<MX::X> dat(N);
  FOR(i, N) {
    INT(x);
    dat[i] = x;
  }
  np t = g.newnode(dat);
  string op;
  FOR(Q) {
    if (IN(op); op[0] == 'I') {
      INT(i, K);
      dat.resize(K);
      FOR(i, K) {
        INT(x);
        dat[i] = x;
      }
      Z m = g.newnode(dat);
      Z [l, r] = g.spl(t, i);
      t = g.me(l, m, r);
    } else if (op[0] == 'D') {
      INT(i, sz);
      --i;
      Z [l, m, r] = g.spl(t, i, i + sz);
      t = g.me(l, r);
    } else if (op[0] == 'M' and si(op) == 9) {
      INT(i, sz, x);
      --i;
      Z [l, m, r] = g.spl(t, i, i + sz);
      np a = g.newnode(x);
      m = 0;
      int n = topbit(sz) + 1;
      FOR(i, n) {
        if (sz >> i & 1) m = g.me(m, a);
        a = g.me(a, a);
      }
      t = g.me(l, m, r);
    } else if (op[0] == 'R') {
      INT(i, sz);
      --i;
      t = g.reverse(t, i, i + sz);
    } else if (op[0] == 'G') {
      INT(i, sz);
      --i;
      print(g.prod(t, i, i + sz).s);
    } else {
      print(g.prod(t).mx);
    }
    if (si(g.tr) - g.fr > lm - 1000) g.gc(t);
  }
}

int main() {
  Yorisou();
  return 0;
}