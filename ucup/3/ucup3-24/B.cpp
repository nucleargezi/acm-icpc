#include "YRS/all.hpp"

constexpr int N = 1000;
constexpr ll INF = inf<ll> / 4;

ll dis[N][N], one[N][N], two[N][N];
void yorisou() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> e[3];
  FOR(i, M) {
    int x, y, w, c;
    cin >> x >> y >> w >> c;
    --x, --y;
    e[c].ep(x, y, w);
  }
  
  FOR(i, N) FOR(k, N) dis[i][k] = INF;
  FOR(i, N) FOR(k, N) one[i][k] = INF;
  FOR(i, N) FOR(k, N) two[i][k] = INF;

  FOR(t, 3) {
    for (Z [x, y, w] : e[t]) {
      chmin(dis[x][y], w);
    }
  }
  FOR(k, N) FOR(x, N) FOR(y, N) {
    chmin(dis[x][y], dis[x][k] + dis[k][y]);
  }
  FOR(t, 1, 3) {
    for (Z [x, y, w] : e[t]) {
      chmin(one[x][y], w);
    }
  }
  FOR(k, N) FOR(x, N) FOR(y, N) {
    chmin(one[x][y], one[x][k] + one[k][y]);
  }
  for (Z [x, y, w] : e[2]) chmin(two[x][y], w);
  FOR(i, N) FOR(k, N) {
    if (one[i][k] == INF) continue;
    chmin(two[i][k], one[i][k] + one[i][k] + dis[k][i]);
  }
  FOR(k, N) FOR(x, N) FOR(y, N) {
    chmin(two[x][y], two[x][k] + two[k][y]);
  }
  FOR(i, N) FOR(k, N) {
    if (two[i][k] == INF) two[i][k] = -1;
    if (i == k) two[i][k] = 0;
    cout << two[i][k] << " \n"[k + 1 == N];
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  yorisou();
  return 0;
}