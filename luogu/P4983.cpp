#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monge.hpp"
#include "YRS/dp/monoton.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  a = pre_sum(a);
  print(monge_dp_k<i128>(N, K, (a[N] + 1) * (a[N] + 1), [&](int l, int r) -> ll {
    ll x = a[r] - a[l] + 1;
    return x * x;
  }));
}
#include "YRS/aa/main.hpp"