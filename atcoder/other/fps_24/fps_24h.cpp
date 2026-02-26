#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  print(CC(N + M - 1, N - 1) * mint(2).pow(M) +
        CC(N + M - 1, N) * mint(2).pow(M - 1));
}
#include "YRS/aa/main.hpp"