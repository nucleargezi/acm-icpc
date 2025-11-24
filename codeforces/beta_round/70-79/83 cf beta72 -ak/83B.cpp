// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  LL(K);
  VEC(ll, a, N);
  if (SUM(a) < K) return print(-1);
  if (SUM(a) == K) return print();
  vector<int> ans;
  bina([&](ll m) -> bool {
    ll s = 0;
    for (ll x : a) s += min(x, m);
    vector<int> q;
    FOR(i, N) if (a[i] > m) q.ep(i);
    int l = 0;
    if (s + len(q) < K) return false;
    while (s < K) {
      if (a[q[l]] - 1 > m) q.ep(q[l]);
      ++s, ++l;
    }
    ans = {q.begin() + l, q.end()};
    return true;
  }, 1'000'000'000, -1);
  for (int &x : ans) ++x;
  print(ans);
}
#include "YRS/Z_H/main.hpp"