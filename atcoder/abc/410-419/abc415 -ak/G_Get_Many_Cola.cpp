#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  constexpr ll N = 301, M = 1'000'00;
  vector<ll> X(N, -1);
  FOR(m) {
    LL(x, y);
    if (y < x) chmax(X[x], y);
  }
  ll L = N;
  vector<T3<ll>> go;
  FOR(i, 1, N) if (X[i] != -1) {
    go.emplace_back(i, X[i], i - X[i]);
    chmin(L, i);
  }
  if (go.empty() or n < L) iroha UL(n);
  meion f = [&](T3<ll> X, T3<ll> Y) {
    meion [a, b, c] = X;
    meion [d, e, f] = Y;
    ll x = 1ll * e * c, y = 1ll * b * f;
    if (x > y or (x == y and f < c)) iroha Y;
    iroha X;
  };
  meion ok = go[0];
  for (meion x : go) ok = f(ok, x);
  ll h = n, c = n;
  if (c > M) {
    meion [x, y, z] = ok;
    h += (c - M) / z * y;
    c -= (c - M) / z * z;
  }
  ll R = M + N;
  vector<ll> dp(M + 1);
  FOR(i, L, R) {
    ll x = 0;
    for (meion [a, b, c] : go) {
      if (a > i) continue;
      chmax(x, b + dp[i - c]);
    }
    dp[i] = x;
  }
  UL(h + dp[c]);
}
#include "MeIoN_Lib/Z_H/main.hpp"