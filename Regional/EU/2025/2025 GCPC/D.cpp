#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  int l = inf<int>, r = -l, u = -l, d = l;
  for (Z [x, y] : a) {
    chmin(l, x);
    chmax(r, x);
    chmin(d, y);
    chmax(u, y);
  }
  print(4);
  print(l, d);
  print(r, d);
  print(r, u);
  print(l, u);
}
#include "YRS/Z_H/main.hpp"