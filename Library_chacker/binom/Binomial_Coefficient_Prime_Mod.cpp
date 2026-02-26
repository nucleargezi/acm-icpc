#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint_d.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = dmint;
void Yorisou() {
  INT(Q, mod);
  mint::set_mod(mod);
  FOR(Q) {
    INT(x, y);
    print(C<mint>(x, y));
  }
}
#include "YRS/aa/main.hpp"