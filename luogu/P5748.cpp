#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/bell.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  vc<mint> f = bell<mint>(1'000'00);
  INT(Q);
  FOR(Q) {
    INT(x);
    print(f[x]);
  }
}
#include "YRS/aa/main.hpp"