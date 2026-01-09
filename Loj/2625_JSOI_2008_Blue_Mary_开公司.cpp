#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/slope/CHT.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = double;
void Yorisou() {
  INT(N);
  CHT<RE> g;
  g.add(0, 0);
  FOR(N) {
    STR(op);
    if (op[0] == 'P') {
      REAL(b, a);
      b -= a;
      g.add(a, b);
    } else {
      INT(x);
      print(ll(g.f(x) / 100));
    }
  }
}