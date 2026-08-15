#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_mono_rev.hpp"
#include "YRS/al/m/add.hpp"

using DS = wblt_mono_rev<Add<int>>;
void Yorisou() {
  INT(N);
  STR(s);
  vc<int> a(N);
  FOR(i, N) a[i] = s[i] & 1;
  DS g;
  Z t = g.newnode(a);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op <= 2) {
      INT(l, r, k);
      --l;
      Z [x, m, y] = g.spl(t, l, r);
      t = g.me(x, op == 1 ? g.rep(m, k) : g.rep_tm(m, k), y);
    } else if (op == 3) {
      INT(l, r);
      --l;
      Z [x, m, y] = g.spl(t, l, r);
      t = g.me(x, y);
    } else {
      INT(k);
      if (k > g.prod(t)) print(-1);
      else print(g.maxr(t, [&](int x) { return x < k; }) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}