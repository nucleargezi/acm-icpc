#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_meld.hpp"
#include "YRS/al/m/add.hpp"

using MX = Add<ll>;
using DS = wblt_meld<MX>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  vc<pair<int, ll>> a(N);
  FOR(i, N) {
    INT(x);
    a[i] = {i, x};
  }
  DS seg;
  vc<np> t(Q + 1);
  t[0] = seg.newnode(a);
  int c = 1;
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(p, l, r);
      --p, --l;
      Z [ls, m, rs] = seg.splk(t[p], l, r);
      t[p] = seg.me(ls, rs);  
      t[c++] = m;
    } else if (op == 1) {
      INT(to, f);
      --to, --f;
      t[to] = seg.meld(t[to], t[f]);
    } else if (op == 2) {
      INT(p, c, x);
      --p, --x;
      t[p] = seg.ins(t[p], x, c);
    } else if (op == 3) {
      INT(p, l, r);
      --p, --l;
      print(seg.prod(t[p], l, r));
    } else {
      LL(p, k);
      --p, --k;
      if (seg.prod(t[p]) <= k) print(-1);
      else print(seg.kth(t[p], k, [&](ll x) { return x; }) + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}