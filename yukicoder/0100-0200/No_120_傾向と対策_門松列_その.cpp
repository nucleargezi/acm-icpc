#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  map<int, int> mp;
  for (int x : a) ++mp[x];
  a.clear();
  for (Z [x, y] : mp) a.ep(y);
  sort(a);
  int ans = N / 3;
  chmin(ans, (N - a.back()) / 2);
  if (len(a) >= 2) chmin(ans, accumulate(begin(a), begin(a) + len(a) - 2, 0));
  print(ans);
}
#include "YRS/aa/main.hpp"