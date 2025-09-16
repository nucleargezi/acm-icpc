#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests
using mint = M99;
constexpr int N = 3000;
int dis[N][N];
void Yorisou() {
  INT(N);
  vector<vector<int>> v(N);
  FOR(i, 1, N) {
    INT(x, y);
    --x, --y;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }
  FOR(i, N) FOR(k, N) dis[i][k] = 0;
  FOR(i, N) {
    queue<int> q;
    q.emplace(i);
    dis[i][i] = 1;
    while (not q.empty()) {
      int n = q.pop();
      for (int t : v[n]) {
        if (not dis[i][t]) {
          dis[i][t] = dis[i][n] + 1;
          q.emplace(t);
        }
      }
    }
  }

  mint ans = 1;
  FOR(i, N) FOR(k, i + 1, N) {
    int x = dis[i][k];
    if (x < 2) continue;
    ans += fact<mint>(x) - fact<mint>(x - 1) * 2 + fact<mint>(x - 2);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"