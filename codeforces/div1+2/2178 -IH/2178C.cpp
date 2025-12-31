#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  vc<ll> c(a), cc(a);
  FOR_R(i, N - 1) c[i] += c[i + 1];
  c.ep(0);
  cc[0] = 0;
  FOR(i, 1, N) cc[i] = std::abs(cc[i]);
  cc = pre_sum<0>(cc);
  ll s = -c[1];
  FOR(i, 1, N) chmax(s, a[0] + cc[i - 1] - c[i + 1]);
  print(s);
}
#include "YRS/aa/main.hpp"