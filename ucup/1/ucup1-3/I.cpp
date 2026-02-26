#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/seq/inversion.hpp"
#include "YRS/dp/monge.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  retsu<int> pr = all_range_inversion(a);
  print(monge_dp_k<ll>(
      N, min(K + 1, N), N * N, [&](int l, int r) { return pr[l][r]; }));
}
#include "YRS/aa/main.hpp"