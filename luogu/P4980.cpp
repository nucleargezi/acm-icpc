#include <linux/limits.h>
#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/pr/factors.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M17;
constexpr int mod = mint::get_mod();
void Yorisou() {
  LL(N);
  ll m = N % mod;
  Z fs = factor(N);
  mint s = 0;
  Z f = [&](Z &f, int i, ll d, ll phd) -> void {
    if (i == len(fs)) return s += mint(phd) * mint(m).pow(N / d), void();
    Z [p, e] = fs[i];
    ll pp = 1, ml = 1;
    FOR(a, e + 1) {
      f(f, i + 1, d * pp, phd * ml);
      pp *= p;
      if (a == 0) ml = p - 1;
      else ml *= p;
    }
  };
  f(f, 0, 1, 1);
  print(s / N);
}
#include "YRS/aa/main.hpp"