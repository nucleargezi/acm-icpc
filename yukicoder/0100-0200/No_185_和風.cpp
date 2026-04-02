#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(N);
  vc<int> f;
  FOR(N) {
    INT(l, r);
    f.ep(r - l);
  }
  unique(f);
  print(len(f) == 1 and f[0] > 0 ? f[0] : -1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"