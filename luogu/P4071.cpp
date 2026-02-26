#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/f/derange.hpp"
#include "YRS/aa/def.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
constexpr int sz = 1'000'000 + 1;
void Yorisou() {
  set_comb(sz);
  vc<mint> f = derange<mint>(sz);
  
  INT(Q);
  FOR(Q) {
    INT(N, M);
    print(f[N - M] * ifac(M) * fac(N));
  }
}
#include "YRS/aa/main.hpp"