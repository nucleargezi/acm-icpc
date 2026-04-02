#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(x, y, xx, yy);
  print(max(x, y) + (x == y and xx == yy and x > xx));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"