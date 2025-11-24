#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using P = point<ll>;
vector<P> get() {
  INT(N);
  VEC(P, a, N);
  return rearrange(a, hull(a));
}
void Yorisou() {
  Z a = get(), b = get(), c = get();
  a = minkovski_sum(a, b);
  a = minkovski_sum(a, c);
  convex_polygon g(a);
  INT(Q);
  FOR(Q) {
    P p;
    IN(p);
    p += p + p;
    YES(g.side(p) >= 0);
  }
}
#include "YRS/Z_H/main.hpp"