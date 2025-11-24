#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/max_flow.hpp"

#define tests 0
#define fl 0
#define DB 10
int N, T;
int id(int x, int y) { return x * N + y; }
tuple<int, int, int> q[1'000];
bool vis[100][100], die[100][100];
constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
void Yorisou() {
  IN(N, T);
  int s = N * N * 2, t = s + 1;
  max_flow<int> FL(t + 1, s, t);
  int x{}, y{};
  VEC(string, a, N);
  VEC(string, b, N);
  FOR(i, N) FOR(k, N) {
    if (a[i][k] == 'Z') x = i, y = k;
    else if (a[i][k] == 'Y') continue;
    FL.add(s, id(i, k), a[i][k] - '0');
    FL.add(id(i, k) + N * N, t, b[i][k] - '0');
  }
  FOR(i, N) FOR(k, N) if (a[i][k] != 'Z' and a[i][k] != 'Y' and a[i][k] - '0') {
    int l = 0, r = 0;
    memset(vis, 0, sizeof vis);
    memset(die, 0, sizeof die);
    q[r++] = {1, i, k};
    q[r++] = {0, x, y};
    vis[i][k] = 1, die[x][y] = 1;
    while (l < r) {
      Z [op, x, y] = q[l++];
      if (op) {
        if (op - 1 > T) continue;
        FL.add(id(i, k), id(x, y) + N * N, 0721 << 4);
        if (die[x][y]) continue;
        FOR(t, 4) {
          int xx = x + dx[t], yy = y + dy[t];
          if (min(xx, yy) < 0 or max(xx, yy) >= N or vis[xx][yy] or die[xx][yy] or a[xx][yy] == 'Y') continue;
          vis[xx][yy] = 1;
          q[r++] = {op + 1, xx, yy};
        }
      } else {
        die[x][y] = 1;
        FOR(t, 4) {
          int xx = x + dx[t], yy = y + dy[t];
          if (min(xx, yy) < 0 or max(xx, yy) >= N or die[xx][yy] or a[xx][yy] == 'Y') continue;
          die[xx][yy] = 1;
          q[r++] = {0, xx, yy};
        }
      }
    }
  }
  print(FL.flow());
}
#include "YRS/Z_H/main.hpp"