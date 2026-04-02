#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/nt/fib_search.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N);
  print(fib_search<i128, 0, ll>([&](ll d) -> i128 {
    ll u = N - d;
    return d - 1 + i128(u + 1) * d;
  }, 1, N + 1).fi % 1'000'007);
}
#include "YRS/aa/main.hpp"