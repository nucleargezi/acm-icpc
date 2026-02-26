#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N);
  ll ans = N;
  FOR(d, 1, N) {
    ll u = N - d;
    chmax(ans, d - 1 + (u + 1) * d);
  } 
  print(ans);
}
#include "YRS/aa/main.hpp"