#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/pow_fast.hpp"
#include "YRS/mod/mod_sqrt.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
ull SA, SB, SC;
void init() { IN(SA, SB, SC); }
ull gen() {
  SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1;
  ull t = SA;
  SA = SB, SB = SC, SC ^= t ^ SA;
  return SC;
}
void Yorisou() {
  constexpr mint a = (mint(233) + mod_sqrt(mint(233 * 233) + mint(4 * 666))) * mint(2).inv();
  constexpr mint b = (mint(233) - mod_sqrt(mint(233 * 233) + mint(4 * 666))) * mint(2).inv();
  pow_fast<mint> f(a), g(b);
  constexpr mint A = (a - b).inv();
  
  INT(Q);
  init();
  ull s = 0;
  FOR(Q) {
    ull x = gen() % (mint::get_mod() - 1);
    s ^= (A * (f(x) - g(x))).val;
  }
  print(s);
}
#include "YRS/aa/main.hpp"