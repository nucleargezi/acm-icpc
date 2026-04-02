#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N);
  hashmap<int> mp;
  FOR(N) {
    INT(x);
    ++mp[x];
  }
  int s = 0;
  for (Z [x, y] : mp.get_all()) {
    if (y == 1) ++s;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"