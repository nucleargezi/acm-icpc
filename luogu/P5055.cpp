#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_sayo_rev.hpp"
#include "YRS/al/am/sum_add.hpp"

using MX = Sum_add<ll>;
using DS = wblt_sayo_rev<MX>;
using np = DS::np;
void Yorisou() {
  INT(Q);
  DS g;
  vc<np> t(Q + 1);
  ll ls = 0;
  FOR(c, 1, Q + 1) {
    LL(v, op);
    if (op == 1) {
      LL(i, x);
      i ^= ls, x ^= ls;
      t[c] = g.ins(t[v], i, x);
    } else if (op == 2) {
      LL(i);
      i ^= ls;
      --i;
      t[c] = g.del(t[v], i);
    } else if (op == 3) {
      LL(l, r);
      l ^= ls, r ^= ls;
      if (l > r) swap(l, r);
      --l;
      t[c] = g.reverse(t[v], l, r);
    } else {
      LL(l, r);
      l ^= ls, r ^= ls;
      if (l > r) swap(l, r);
      --l;
      print(ls = g.prod(t[c] = t[v], l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}