#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr int N = 8, dx[]{1, -1, 0, 0, 1, 1, -1, -1, 0}, dy[]{0, 0, 1, -1, 1, -1, 1, -1, 0};
void Yorisou() {
  string s[N];
  char f[N][N][N + 1]{};
  FOR(i, N) IN(s[i]);
  FOR(i, N) FOR(k, N) {
    FOR(d, i + 1) {
      if (s[i - d][k] == 'S') f[i][k][d] = -1;
    }
  }
  vc<T3<int>> q;
  q.ep(N - 1, 0, 0);
  FOR(i, si(q)) {
    Z [x, y, t] = q[i];
    FOR(d, 9) {
      int xx = x + dx[d], yy = y + dy[d];
      if (min(xx, yy) < 0 or max(xx, yy) >= N) continue;
      int tt = min(t + 1, N);
      if (t < N and (f[xx][yy][t] == -1 or f[xx][yy][t + 1] == -1)) continue;
      if (f[xx][yy][tt]) continue;
      f[xx][yy][min(t + 1, N)] = 1;
      q.ep(xx, yy, min(t + 1, N));
    }
  }
  FOR(t, N + 1) if (f[0][N - 1][t]) return print("WIN");
  print("LOSE");
}

int main() {
  Yorisou();
  return 0;
}