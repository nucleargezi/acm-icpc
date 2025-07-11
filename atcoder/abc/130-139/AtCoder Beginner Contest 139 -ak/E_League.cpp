#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(n);
  int a[n][n - 1];
  FOR(i, n) FOR(k, n - 1) IN(a[i][k]), --a[i][k];
  const int N = n * n;
  vector<vector<int>> v(N);
  vector<int> in(N);
  FOR(i, n) {
    FOR(k, 1, n - 1) {
      meion [x, y] = MINMAX((int)i, a[i][k - 1]);
      int f = x * n + y;
      std::tie(x, y) = MINMAX((int)i, a[i][k]);
      int t = x * n + y;
      v[f].emplace_back(t);
      ++in[t];
    }
  }
  vector<int> dis(N, 1);
  int cnt = 0;
  queue<int> q;
  FOR(i, N) if (not in[i]) q.emplace_back(i);
  while (not q.empty()) {
    int n = q.pop();
    ++cnt;
    for (int t : v[n]) {
      chmax(dis[t], dis[n] + 1);
      if (not --in[t]) {
        q.emplace_back(t);
      }
    }
  }
  print("{}", cnt == N ? QMAX(dis) : -1);
}
#include "MeIoN_Lib/Z_H/main.hpp"