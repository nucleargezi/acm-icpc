#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

using re = ld;
void Yorisou() {
  vc<int> a{2, 3, 5, 7, 11, 13};
  vc<int> b{4, 6, 8, 9, 10, 12};
  map<ll, re> dp;
  dp[1] = 1;
  INT(N, M);
  FOR(N) {
    map<ll, re> ndp;
    for (Z [x, s] : dp) {
      for (int y : a) ndp[x * y] += s / 6;
    }
    dp.swap(ndp);
  }
  FOR(M) {
    map<ll, re> ndp;
    for (Z [x, s] : dp) {
      for (int y : b) ndp[x * y] += s / 6;
    }
    dp.swap(ndp);
  }
  setp(15);
  re s = 0;
  for (Z [x, y] : dp) s += x * y;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"