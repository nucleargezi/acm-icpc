#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

using re = ld;
void Yorisou() {
  INT(K);
  re s = 0;
  for (int x : {2, 3, 5, 7, 11, 13}) {
    for (int y : {4, 6, 8, 9, 10, 12}) {
      s += x * y == K;
    }
  }
  setp(15);
  print(s / 36);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"