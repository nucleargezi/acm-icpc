#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/static_range_prod.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/ds/monoid/dis_substr.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
using MX = monoid_dis_substr<mint, 10>;
using X = MX::X;
void Yorisou() {
  STR(s);
  int N = len(s);
  FOR(i, N) s[i] -= 'a';
  static_range_prod<MX> seg(N, [&](int i) {
    return MX::sing(s[i]);
  });
  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    print(seg.prod(l, r).f());
  }
}
#include "YRS/aa/main.hpp"