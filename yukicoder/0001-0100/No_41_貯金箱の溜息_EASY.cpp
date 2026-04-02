#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/prod_of_one_minus_xn.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<1'000'000'000 + 9>;
using fps = vc<mint>;
void Yorisou() {
  int N = 1'000'00;
  vc<int> a(9);
  iota(all(a), 1);
  fps f = prod_of_inv_one_minus_xn<mint>(a, N);
  FOR(i, 1, N) f[i] += f[i - 1];
  
  INT(Q);
  FOR(Q) {
    LL(x);
    print(f[x / 111'111]);
  }
}
#include "YRS/aa/main.hpp"