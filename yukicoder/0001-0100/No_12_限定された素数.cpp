#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/primtable.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int s = 0;
  for (int x : a) s |= 1 << x;
  Z pr = primtable(5'000'000);
  pr.insert(pr.begin(), 0);
  pr.ep(5'000'001);
  int sz = len(pr);

  queue<int> q;
  int c[10]{}, msk = 0, ans = -1;
  FOR(i, 1, sz - 1) {
    int x = pr[i];
    q.eb(i);
    while (x) ++c[x % 10], msk |= 1 << (x % 10), x /= 10;
    while (msk != s and (msk | s) != s) {
      x = pr[pop(q)];
      while (x) {
        if (not --c[x % 10]) msk ^= 1 << (x % 10);
        x /= 10;
      }
    }
    if (msk == s) chmax(ans, pr[q.back() + 1] - pr[q.front() - 1] - 2);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"