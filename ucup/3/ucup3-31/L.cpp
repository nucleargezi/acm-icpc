#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/basic/queue.hpp"

void Yorisou() {
  static constexpr int dx[]{0, -1, 0, 1}, dy[]{1, 0, -1, 0};
  INT(N, Q);
  VEC(string, s, N);
  FOR(i, N) FOR(k, N) s[i][k] = s[i][k] == '.';
  retsu<array<int, 4>> rs(N, N, {-1, -1, -1, -1});
  retsu<array<bool, 4>> vis(N, N);
  queue<T3<int>> q(N * N);
  FOR(i, N) FOR(k, N) if (s[i][k]) {
    if (min(i, k) == 0 or max(i, k) == N - 1) {
      FOR(d, 4) FOR(g, -1, 3) {
        int t = (d + g + 4) & 3, x = i + dx[t], y = k + dy[t];
        if (min(x, y) < 0 or max(x, y) >= N) {
          q.eb(i, k, d);
          rs[i][k][d] = 1;
          vis[i][k][d] = 1;
        } else if (s[x][y]) break;
      }
    }
  }

  while (not q.empty()) {
    Z [x, y, rd] = pop(q);
    FOR(g, 4) {
      int xx = x + dx[g], yy = y + dy[g];
      if (min(xx, yy) >= 0 and max(xx, yy) < N and s[xx][yy]) {
        FOR(d, 4) if (not vis[xx][yy][d]) FOR(dd, -1, 3) {
          int t = (d + dd + 4) & 3, gx = xx + dx[t], gy = yy + dy[t];
          if (min(gx, gy) >= 0 and max(gx, gy) < N and s[gx][gy]) {
            if (gx == x and gy == y and t == rd) {
              rs[xx][yy][d] = rs[x][y][t] + 1;
              q.eb(xx, yy, d);
              vis[xx][yy][d] = 1;
            }
            break;
          }
        }
      }
    }
  }

  FOR(Q) {
    INT(x, y);
    CH(c);
    --x, --y;
    FOR(i, 4) if (c == "RULD"[i]) print(rs[x][y][i]);
  }
}

int main() {
  Yorisou();
  return 0;
}