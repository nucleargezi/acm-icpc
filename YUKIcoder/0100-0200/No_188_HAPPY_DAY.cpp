#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/others/date_time.hpp"

void Yorisou() {
  datetime X(2015, 1, 1);
  int s = 0;
  while (X.y == 2015) {
    int a = X.m, b = X.d;
    b = b / 10 + b % 10;
    s += a == b;
    ++X;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"