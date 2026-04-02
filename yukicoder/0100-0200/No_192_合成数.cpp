#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/pr/ptest.hpp"

void Yorisou() {
  INT(N);
  FOR(i, max(4, N - 100), N + 101) {
    if (not ptest(i)) return print(i);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"