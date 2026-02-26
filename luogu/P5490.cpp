#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/off_line/rectangle_union.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  rectangle_union<int> g;
  FOR(N) {
    INT(a, b, c, d);
    g.add(a, b, c, d);
  }
  print(g.f<ll>());
}
#include "YRS/aa/main.hpp"