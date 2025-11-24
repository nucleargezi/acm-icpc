#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/all.hpp"

#define tests 1
#define fl 0
#define DB 10
using RE = long double;
using P = point<ll>;
void Yorisou() {
  INT(N, M);
  VEC(P, a, N);
  VEC(P, b, M);
  for (Z &[x, y] : b) x = -x, y = -y;
  setp(12);
  print((RE)area(a) / area(minkovski_sum(a, b)) * area(b) / 2);
}
#include "YRS/Z_H/main.hpp"