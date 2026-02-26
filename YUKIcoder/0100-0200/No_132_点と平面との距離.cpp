#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/ge/basic/bs3.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
using P = p3<re>;
void Yorisou() {
  INT(N);
  P s;
  IN(s);
  VEC(P, a, N);
  re ans = 0;
  FOR(i, N) FOR(k, i + 1, N) FOR(j, k + 1, N) {
    ans += s.dist(a[i], a[k], a[j]);
  }
  setp(10);
  print(ans);
}
#include "YRS/aa/main.hpp"