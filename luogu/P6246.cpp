#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monge.hpp"
#include "YRS/dp/monoton.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  sort(a);
  a = pre_sum(a);
  Z w = [&](int l, int r) {
    int m = (l + r + 1) >> 1;
    ll R = a[r] - a[m];
    int e = m - ((r - l) & 1);
    ll L = a[e] - a[l];
    return R - L;
  };
  if (K < 50)
    print(monoton_dp<int>(N + 1, K, w)[N]);
  else
    print(monge_dp_k<ll>(N, K, a[N], w));
}
#include "YRS/aa/main.hpp"