#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/beats/beats_minmax.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = beats_minmax<ll>;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  DS seg(a);
  FOR(Q) {
    int op, l, r, x;
    IN(op, l, r);
    --l;
    if (op != 4) IN(x);
    if (op == 1) seg.add(l, r, x);
    else if (op == 2) seg.chmin(l, r, x);
    else if (op == 3) seg.chmax(l, r, x);
    else print(get<2>(seg.prod(l, r)));
  }
}
#include "YRS/aa/main.hpp"