#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  N = 1 << N;
  VEC(ll, a, N);
  ll ans = QMAX(a);
  while (N > 1) {
    vector<ll> f(N >> 1);
    sort(a);
    FOR(i, 0, N, 2) f[i >> 1] = a[i] + a[i + 1];
    swap(f, a);
    chmax(ans, QMAX(a));
    N >>= 1;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"