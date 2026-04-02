#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(N);
  vc<PII> b, a;
  int l = 1, r = 1000;
  while (len(b) < N) {
    b.ep(l, r);
    b.ep(l, r);
    a.ep(l, r);
    a.ep(l, r);
    a.ep(l, r);
    ++l;
    b.ep(l, r);
    --r;
    a.ep(l, r);
    ++l;
    b.ep(l, r);
    --r;
    a.ep(l, r);
    a.ep(l, r);
    b.ep(l, r);
    b.ep(l, r);
    ++l, --r;
  }
  sh(b, N);
  sh(a, N);
  for (Z [x, y] : a) print(x, y);
  for (Z [x, y] : b) print(x, y);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"