#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/basic/3d_V_donut.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  setp(10);
  REAL(s, r, R);
  print(donut((R - r) / 2, (R + r) / 2) * s);
}
#include "YRS/aa/main.hpp"