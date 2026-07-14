#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/dyn_kdt_sayo.hpp"
#include "YRS/al/am/sum_add.hpp"

TP<int K> void slv(int Q) {
  using DS = dyn_kdt_sayo<K, Sum_add<ull>, ull>;
  using P = DS::P;
  DS seg(Q);
  ull ls = 0;
  P p, l, r;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      FOR(i, K) IN(p[i]), p[i] ^= ls;
      ULL(x);
      x ^= ls;
      seg.ins(p, x);
    } else {
      FOR(i, K) IN(l[i]), l[i] ^= ls;
      FOR(i, K) IN(r[i]), r[i] ^= ls;
      if (op == 2) {
        ULL(x);
        x ^= ls;
        seg.apply(l, r, x);
      } else {
        print(ls = seg.prod(l, r));
      }
    }
  }
}

void Yorisou() {
  INT(K, Q);
  if (K == 2) slv<2>(Q);
  if (K == 3) slv<3>(Q);
}

int main() {
  Yorisou();
  return 0;
}