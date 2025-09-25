#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  vector<char> vis(N);
  int m0 = inf<int>, m1 = inf<int>, c0 = 0, c1 = 0;
  FOR(i, N) {
    c0 += a[i] - b[i];
    c1 += a[N - i - 1] - b[(N - i - 2 + N) % N];
    chmin(m0, c0);
    chmin(m1, c1);
  }
  FOR(i, N) {
    if (m0 > -1 and not vis[i]) vis[i] = 1;
    if (m1 > -1 and not vis[N - i - 1]) vis[N - i - 1] = 1;
    m0 -= a[i] - b[i];
    m1 -= a[N - i - 1] - b[(N - i - 2 + N) % N];
  }
  print(SUM<int>(vis));
  vector<int> ans;
  FOR(i, N) if (vis[i]) ans.ep(i + 1);
  print(ans);
}
#include "YRS/Z_H/main.hpp"