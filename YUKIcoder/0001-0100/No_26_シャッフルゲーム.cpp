#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  bool f[3]{};
  f[N - 1] = 1;
  FOR(M) {
    INT(x, y);
    --x, --y;
    swap(f[x], f[y]);
  }
  FOR(i, 3) if (f[i]) print(i + 1);
}
#include "YRS/aa/main.hpp"