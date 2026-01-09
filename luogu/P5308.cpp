#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monge.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = double;
void Yorisou() {
  INT(N, K);
  setp(9);
  print(-monge_dp_k_aliens<re>(N, K, N, 60,
      [&](int l, int r) -> re { return -re(r - l) / (N - l); }));
}
#include "YRS/aa/main.hpp"