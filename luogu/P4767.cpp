#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct retsu {
  int N, M;
  vc<int> a;
  retsu(int N, int M) : N(N), M(M), a(N * M, 0) {}
  int* operator[](int i) { return a.data() + i * M; }
  const int* operator[](int i) const { return a.data() + i * M; }
};
void Yorisou() {
  INT(N, P);
  VEC(int, a, N);
  sort(a);
  a.insert(a.begin(), 0);
  retsu c(N + 1, N + 1);
  FOR_R(i, 1, N + 1) FOR(k, i, N + 1) 
    c[i][k] = c[i + 1][k - 1] + a[k] - a[i];
  vc<int> dp(N + 1, inf<int>), ndp(dp);
  dp[0] = 0;
  FOR(i, 1, N + 1) dp[i] = c[1][i];
  Z f = [&](Z &f, int l, int r, int ql, int qr) -> void {
    if (l > r) return;
    int m = (l + r) >> 1, id = -1, nr = min(qr, m - 1);
    int e = inf<int>;
    FOR(k, ql, nr + 1) if (chmin(e, dp[k] + c[k + 1][m])) id = k;
    ndp[m] = e;
    if (l < m) f(f, l, m - 1, ql, id);
    if (m < r) f(f, m + 1, r, id, qr);
  };
  FOR(i, 2, P + 1) {
    ndp[0] = 0;
    f(f, i, N, i - 1, N - 1);
    dp.swap(ndp);
  }
  print(dp[N]);
}
#include "YRS/Z_H/main.hpp" 