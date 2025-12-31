#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/01.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, V);
  vc<ll> v(N), w(N);
  FOR(i, N) IN(w[i], v[i]);
  print(knapsack01(w, v, V));
}
#include "YRS/aa/main.hpp"