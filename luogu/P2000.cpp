#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/nt/bigint/big.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  using ll = bigint;
  LL(N);
  print((N + 1) * (N + 2) * (N + 3) * (N + 4) / 24);
}
#include "YRS/aa/main.hpp"