#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, M, S);
  fps f(S + 1);
  FOR(i, min(M, S) + 1) f[i] = 1;
  print(fps_pow(f, N)[S]);
}
#include "YRS/aa/main.hpp"