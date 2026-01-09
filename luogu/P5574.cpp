#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monoton.hpp"
#include "YRS/ds/fenw/fenw01.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  for (int t = 0; int i : argsort(a)) {
    a[i] = t++;
  }
  fenw01 bit(N + 1);
  int pl = 0, pr = 0, s = 0;
  print(monoton_dp<int>(N + 1, K, [&](int l, int r) {
    while (pl > l) --pl, s += bit.prod(a[pl] + 1, N), bit.set(a[pl]);
    while (pr < r) s += bit.prod(0, a[pr]), bit.set(a[pr]), ++pr;
    while (pl < l) s -= bit.prod(a[pl] + 1, N), bit.reset(a[pl]), ++pl;
    while (pr > r) --pr, s -= bit.prod(0, a[pr]), bit.reset(a[pr]);
    return s;
  })[N]);
}
#include "YRS/aa/main.hpp"