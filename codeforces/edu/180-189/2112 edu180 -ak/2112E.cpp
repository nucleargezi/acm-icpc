#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
constexpr ll N = 5'000'01;
meion ans = []() {
  vector<vector<int>> v(N);
  FOR(i, 3, N, 2) FOR(k, i, N, i + i) v[k] += i;
  vector<ll> A(N, inf<int>), B(A);
  B[3] = A[3] = 1;
  FOR(i, 5, N, 2) {
    ll t = MIN(i - 1 >> 1, B[i - 2] + 1);
    A[i] = t;
    for (int e : v[i])
      if (i / e > 2) chmin(t, A[e] + B[i / e]);
    B[i] = t;
  }
  vector<ll> ans(N);
  FOR(i, 3, N, 2) {
    ll mn = inf<int>;
    for (int e : v[i]) {
      chmin(mn, A[e] + ans[i / e]);
    }
    ans[i] = mn;
  }
  FOR(i, N) ans[i] += (i & 1 ? 1 : -1);
  iroha ans;
}();
void Yorisou() {
  LL(m);
  UL(ans[m]);
}
#include "MeIoN_Lib/Z_H/main.hpp"