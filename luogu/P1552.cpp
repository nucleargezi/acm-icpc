#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, V);
  vc<vc<int>> g(N);
  vector<int> c(N), w(N);
  int t = -1;
  FOR(i, N) {
    INT(fa);
    --fa;
    IN(c[i], w[i]);
    if (fa != -1) g[fa].ep(i); 
    else t = i;
  }
  ll ans = 0;
  vector<max_heap<int>> q(N);
  vector<ll> s(N);
  Z f = [&](Z &f, int n) -> void {
    q[n].eb(c[n]), s[n] = c[n];
    for (int t : g[n]) {
      f(f, t);
      s[n] += s[t];
      if (len(q[n]) < len(q[t])) q[n].swap(q[t]);
      while (not q[t].empty()) q[n].eb(pop(q[t]));
    }
    while (s[n] > V) s[n] -= pop(q[n]);
    chmax(ans, w[n] * len(q[n]));
  };
  f(f, t);
  print(ans);
}
#include "YRS/Z_H/main.hpp"