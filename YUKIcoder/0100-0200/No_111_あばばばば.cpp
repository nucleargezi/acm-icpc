#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
ll f(ll N) { return N * (N - 1) / 2; }
void Yorisou() {
  LL(N);
  print(f(N / 2) + f(N - N / 2));
}
#include "YRS/aa/main.hpp"