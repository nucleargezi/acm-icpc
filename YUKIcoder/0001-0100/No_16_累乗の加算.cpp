#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<1'000'003>;
void Yorisou() {
  INT(x, N);
  mint s;
  FOR(N) {
    INT(p);
    s += mint(x).pow(p);
  }
  print(s);
}
#include "YRS/aa/main.hpp"