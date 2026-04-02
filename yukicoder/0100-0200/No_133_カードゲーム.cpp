#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  vc<int> ia(N);
  iota(all(ia), 0);
  int s = 0, t = 0;
  do {
    vc<int> x = rearrange(a, ia);
    vc<int> ib(N);
    iota(all(ib), 0);
    do {
      ++t;
      vc<int> y = rearrange(b, ib);
      int w = 0;
      FOR(i, N) w += x[i] > y[i];
      s += w > N / 2;
    } while (next_permutation(all(ib)));
  } while (next_permutation(all(ia)));
  print(ld(s) / t);
}
#include "YRS/aa/main.hpp"