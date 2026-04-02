#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, K);
  STR(s);
  FOR(i, N) s[i] -= '0';
  vc<int> c(all(s));
  c = pre_sum(c);
  ll al = SUM(s);
  print(bina([&](ll x) -> bool {
    if (x >= N and al >= N) return 1;
    ll s = x, p = 0, fx = x;
    while (x) {
      if (fx < N and s > N * 10) return 1;
      Z X = divmod(x, N);
      ll a = X.fi, b = X.se, nx = a * al;
      while (b) {
        ll d = min(N - p, b);
        b -= d;
        nx += c[p + d] - c[p];
        p = (p + d) % N;
      }
      if ((s += x = nx) >= K) return 1;
    }
    return 0;
  }, K * N, 0));
}
#include "YRS/aa/main.hpp"