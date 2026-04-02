#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  vc<u8> a(N);
  iota(all(a), 1);
  FOR(Q) {
    INT(x);
    --x;
    FOR_R(i, x) swap(a[i], a[i + 1]);
  }
  print(int(a[0]));
}
#include "YRS/aa/main.hpp"