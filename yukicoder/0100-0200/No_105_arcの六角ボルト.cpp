#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/basic/point.hpp"

#define tests 1
#define fl 0
#define DB 10
using re = ld;
using P = point<re>;
void Yorisou() {
  VEC(P, p, 6);
  re ang = inf<re>;
  FOR(i, 6) FOR(k, 6) chmin(ang, p[i].rotate(pi / 3 * k).angle());
  setp(16);
  print(ang * 180 / pi);
}
#include "YRS/aa/main.hpp"