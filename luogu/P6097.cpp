#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/sps/conv.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<1'000'000'009>;
void Yorisou() {
  INT(N);
  VEC(mint, a, 1 << N);
  VEC(mint, b, 1 << N);
  print(sps_conv(a, b));
}
#include "YRS/aa/main.hpp"