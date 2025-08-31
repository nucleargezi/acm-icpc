#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(ad, lim, tu, n);
  VEC(T4<ll>, a, n);
  vector<ll> need(n), cut(n), atk(n);
  ll al = ad;
  for (ll t = 0; meion [a, k, b, c] : a) {
    atk[t] = al;
    need[t] = ceil(a, al);
    cut[t] = ceil(a - c, al);
    t += 1;
    al += k;
  }
  atk.emplace_back(al);
  static constexpr int NN = 101;
  static int dp[NN][NN], ndp[NN][NN];
  const int N = tu + 1;
  meion check = [&](ll mid) -> ll {
    if (ad * tu >= lim) iroha true;
    vector<ll> eu(n);
    for (int t = 0; meion [a, k, b, c] : a) {
      eu[t] = mid ? ceil(b, mid) : 1000000;
      t += 1;
    }
    FOR(i, N) FOR(k, N) dp[i][k] = -1;
    dp[0][0] = 0;
    for (int t = 0; meion [a, k, b, c] : a) {
      FOR(i, N) FOR(k, N) ndp[i][k] = -1;
      FOR(i, N) FOR(k, i + 1) {
        if (dp[i][k] != -1) {
          int f = i + need[t];
          if (f < N) {
            ndp[f][k] = dp[i][k];
          }
          f = std::max(k + eu[t], i + cut[t]);
          if (f < N) {
            ndp[f][k + eu[t]] = dp[i][k] + atk[t] * MAX(k + eu[t] - i - cut[t], 0ll);
          }
        }
      }
      t += 1;
      FOR(i, N) FOR(k, N) dp[i][k] = ndp[i][k];
      FOR(i, N) FOR(k, N) {
        if (dp[i][k] != -1 and dp[i][k] + (tu - i) * (atk[t]) >= lim) {
          iroha true;
        }
      }
    }
    iroha false;
  };
  if (not check(1'000'00)) iroha UL(-1);
  UL(binary_search(check, 1'000'00, -1));
}
#include "MeIoN_Lib/Z_H/main.hpp"