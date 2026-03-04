#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/pr/crt.hpp"

void Yorisou() {
  vc<ll> x, mod;
  FOR(3) {
    INT(a, b);
    x.ep(a);
    mod.ep(b);
  }
  ll ans = crt_reduce(x, mod);
  print(ans == 0 ? lcm(lcm(mod[0], mod[1]), mod[2]) : ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"