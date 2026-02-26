#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<10007>;
void Yorisou() {
  INT(N, M);
  print(lucas<mint>(N * M, N - 1) / N);
}
#include "YRS/aa/main.hpp"