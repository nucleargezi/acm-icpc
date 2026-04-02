#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/aa/def.hpp"
#include "YRS/nt/enum_pytagorean_triple.hpp"

using mint = mint_t<1'000'003>;
void Yorisou() {
  LL(N);
  mint s;
  for (Z [a, b, c] : enum_pytagorean_triple<1>(N)) s += a + b + c <= N / 4;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"