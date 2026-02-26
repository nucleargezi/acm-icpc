// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monge.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  if (K == 1) {
    i128 s = 0;
    FOR(i, N) {
      INT(x);
      s += x;
    }
    return print(s * N);
  }
  vc<i128> a, b;
  FOR(N) {
    INT(x);
    if (x < 0) a.ep(x);
    else b.ep(x);
  }
  sort(a);
  sort(b, greater());
  i128 s = SUM(a), sz = len(a);
  while (not b.empty()) {
    int x = b.back();
    if (len(b) > K - 1 and s * sz + x >= (s + x) * (sz + 1)) {
      a.ep(pop(b));
      ++sz;
      s += x;
    } else break;
  }
  reverse(all(b));
  if (a.empty()) {
    N = len(b);
    b = pre_sum(b);
    print(monge_dp_k<i128>(N, K, (i128)b[N] * N * 2,
        [&](int l, int r) { return (b[r] - b[l]) * (r - l); }));
  } else if (K > len(b)) {
    i128 ans = SUM(b);
    K -= len(b);
    while (K > 1) --K, ans += pop(a);
    ans += SUM(a) * len(a);
    print(ans);
  } else {
    i128 lm = -SUM(a) + SUM(b);
    b.insert(b.begin(), SUM(a));
    int N = len(b);
    lm *= N;
    vc<int> ls(N, 1);
    ls[0] = len(a);
    b = pre_sum(b);
    ls = pre_sum(ls);
    print(monge_dp_k<i128>(N, K, lm,
        [&](int l, int r) { return (b[r] - b[l]) * (ls[r] - ls[l]); }));
  }
}
#include "YRS/aa/main.hpp"