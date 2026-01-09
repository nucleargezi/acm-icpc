#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/range_on/range_major_voting.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  major_voting<1 << 20> seg(a, N);
  FOR(Q) {
    INT(l, r, s, sz);
    --l;
    int x = seg.prod(l, r);
    if (x == -1) x = s;
    print(x);
    FOR(sz) {
      INT(i);
      --i;
      seg.set(i, x);
    }
  }
  print(seg.prod(0, N));
}
#include "YRS/aa/main.hpp"