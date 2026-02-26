#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  LL(K);
  setp(12);
  print(bina_real<re>([&](re x) {
    ll s = 0;
    for (int e : a) {
      s += floor(e / x);
      if (s >= K) return 1;
    }
    return 0;
  }, 0, SUM<ll>(a)));
}
#include "YRS/aa/main.hpp"