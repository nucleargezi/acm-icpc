#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/po/f/fac_large.hpp"
#include "YRS/aa/def.hpp"

using mint = M17;
constexpr ll mod = mint::get_mod();
void Yorisou() {
  INT(Q);
  fac_large<mint, 13> x;
  FOR(Q) {
    STR(C, P);
    if (len(P) <= 10) {
      ll p = stoll(P), c = 0;
      for (char x : C) {
        c = c * 10 + x - '0';
        if (c >= 2 * mod) c = c % mod + 2 * mod;
      }
      if (p < mod and c >= 2 * p - 1) {
        c = mint(c + 1 - p).val();
        if (c >= p) print(x[c] / x[c - p]);
        else print(0);
      } else print(0);
    } else print(0);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"