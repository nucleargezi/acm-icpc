#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/line/01/sp.hpp"

void Yorisou() {
  sp<int> s;
  INT(N);
  FOR(N) {
    INT(x);
    s.add(x);
  }
  print(1 << len(s));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"