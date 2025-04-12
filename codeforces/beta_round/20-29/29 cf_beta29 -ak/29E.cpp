#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  vector<vector<int>> v(n);
  FOR(m) {
    INT(x, y);
    --x, --y;
    v[x] += y, v[y] += x;
  }
  int dis[n][n];
  PII fa[n][n];
  memset(dis, -1, sizeof dis);
  memset(fa, -1, sizeof fa);
  queue<PII> q;
  q.emplace_back(0, n - 1);
  dis[0][n - 1] = 0;
  while (not q.empty()) {
    meion [x, y] = q.pop();
    for (int xx : v[x]) for (int yy : v[y]) {
      if (xx != yy and dis[xx][yy] == -1) {
        dis[xx][yy] = dis[x][y] + 1;
        fa[xx][yy] = {x, y};
        q.emplace_back(xx, yy);
      }
    }
  }
  if (dis[n - 1][0] == -1) iroha UL(-1);
  vector<int> L, R;
  int x{n - 1}, y{};
  while (~x) {
    L += y, R += x;
    std::tie(x, y) = fa[x][y];
  }
  for (int &x : L) ++x;
  for (int &x : R) ++x;
  UL(len(L) - 1);
  UL(L);
  UL(R);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}