#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/beats/beats_no_sum.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = beats_no_sum<ll>;
void Yorisou() {
  INT(N, Q);
  DS seg(N, [&](int i) -> ll { return 0; });
  FOR(Q) {
    INT(op, l, r, x);
    ++r;
    if (op == 1) seg.chmax(l, r, x);
    else seg.chmin(l, r, x);
  }
  FOR(i, N) print(seg.prod(i, i + 1).fi);
}
#include "YRS/aa/main.hpp"