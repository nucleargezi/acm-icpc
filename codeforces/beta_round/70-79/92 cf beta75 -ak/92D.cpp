#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vector mn = a;
  FOR_R(i, N - 1) chmin(mn[i], mn[i + 1]);
  vector<int> ans(N, -1);
  FOR(i, N) {
    if (mn[i] >= a[i]) continue;
    ans[i] = bina([&](int x) { return mn[x] < a[i]; }, i, N) - i - 1;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"