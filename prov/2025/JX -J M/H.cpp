#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  FOR(i, N) a[i] -= i + 1;
  if (QMIN(a) < 0) return print(-1);
  
  vector<ll> min = a;
  FOR_R(i, N - 1) chmin(min[i], min[i + 1]);
  ll ad = 0, ans = N, c = 0;
  FOR(i, N) {
    ans += min[i] - ad;
    ll d = std::min(c, min[i] - ad);
    ad = min[i];
    ans += a[i] - ad;
    ans -= d;
    c -= d;
    c += a[i] - ad;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"