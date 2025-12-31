#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/multi.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, V);
  vc<ll> v(N), w(N), c(N);
  FOR(i, N) IN(v[i], w[i], c[i]);
  print(knapsack_multi(w, v, c, V));
}
#include "YRS/aa/main.hpp"