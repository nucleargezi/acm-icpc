#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  map<int, int> c;
  FOR(i, N) c[b[i]] += a[i];
  int mx = 0;
  for (Z [x, y] : c) chmax(mx, y);
  YES(mx == c[0]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"