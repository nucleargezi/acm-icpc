#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/conv_all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  vc<vc<mint>> f(N);
  FOR(i, N) {
    INT(sz);
    f[i].resize(sz + 1);
    IN(f[i]);
  }
  print(conv_all(f));
}
#include "YRS/aa/main.hpp"