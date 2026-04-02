#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

using re = ld;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  max_heap<T3<re>> q;
  FOR(i, N) {
    q.eb(re(a[i]) / 1000 * re(b[i]) / 100, re(a[i]) / 1000, re(b[i]) /100);
  }
  re s = 0;
  FOR(i, 1, 1'000'000) {
    Z [sc, bs, w] = pop(q);
    s += i * sc;
    q.eb(bs * (1 - w) * w, bs * (1 - w), w);
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"