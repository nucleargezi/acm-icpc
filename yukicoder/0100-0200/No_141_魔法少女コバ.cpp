#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

void Yorisou() {
  LL(N, M);
  ll g = gcd(N, M);
  N /= g, M /= g;
  ll s = 0;
  while (max(N, M) != 1) {
    if (N < M) swap(N, M), ++s;
    else s += M == 1 ? N - 1 : N / M, N %= M;
    ll g = gcd(N, M);
    N /= g, M /= g;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"