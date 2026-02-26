#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/divisors.hpp"
#include "YRS/ds/heap/erase_heap.hpp"

#define tests 0
#define fl 0
#define DB 10
vc<int> lpf = lpf_table(1'0000);
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int mx = QMAX(a) + 1;
  vc<vc<int>> div(N);
  vc<min_erase_heap<PII>> q(mx);
  FOR(i, N) {
    for (int e : divisor_by_lpf(a[i], lpf)) {
      div[i].ep(e);
      q[e].eb(a[i], i);
    }
  }
  int i = 0;
  vc<int> ans{a[i]};
  FOR(N - 1) {
    for (int e : div[i]) q[e].pop({a[i], i});
    int mx = inf<int>, nx = 0;
    for (int e : div[i]) if (not q[e].empty()) {
      Z [x, id] = q[e].top();
      if (chmin(mx, lcm(a[i], x)) or (mx == lcm(a[i], x) and x < a[nx])) nx = id;
    }
    i = nx;
    ans.ep(a[i]);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"