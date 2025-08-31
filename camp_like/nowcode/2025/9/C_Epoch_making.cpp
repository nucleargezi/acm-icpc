#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  int n, m;
  std::cin >> n >> m;
  int a[24]{};
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int e[24]{}; 
  for (int i = 0, x, y; i < m; ++i) {
    std::cin >> x >> y;
    --x, --y;
    e[x] |= 1 << y;
  }
  
  meion I = argsort(vector<int>{a, a + n});
  vector<int> seg;
  for (int i = 0; i < n; ) {
    seg.emplace_back(i);
    int k = i + 1;
    while (k < n and a[I[i]] == a[I[k]]) ++k;
    i = k;
  }
  seg.emplace_back(n);
  const int N = 1 << n;
  vector<int> dp(N, inf<int>);
  dp[0] = 0;

  for (int msk = 0; msk < N; ++msk) if (dp[msk] != inf<int>) {
    int go = 0;
    for (int i = 0; i < n; ++i) {
      if ((msk >> i & 1) == 0 and (e[i] & ~msk) == 0) {
        go |= 1 << i;
      }
    }
    if (not go) continue;
    int t = msk;
    for (int i = 0; i < (int)seg.size() - 1; ++i) {
      int l = seg[i], r = seg[i + 1], nx = 0;
      for (int k = l; k < r; ++k) {
        int ii = I[k];
        if (go >> ii & 1) nx |= 1 << ii;
      }
      if (nx) {
        t |= nx;
        chmin(dp[t], dp[msk] + a[I[l]]);
      }
    }
  }
  UL(dp[N - 1]);
}
#include "YRS/Z_H/main.hpp"