#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/multipoint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, M, K);
  fps f(N + 1);
  FOR(i, K + 1) f[N - i] = CC(N, i);
  fps x(M);
  iota(all(x), 1);
  for (mint s : multi_eval(f, x)) print(s);
}
#include "YRS/aa/main.hpp"