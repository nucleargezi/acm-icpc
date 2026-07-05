#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M);
  RET(char, a, N, M);
  FOR(i, N) FOR(k, M) a[i][k] -= '0';
  int rs = 0;
  FOR(i, N - 1) FOR(k, M - 1) {
    if (a[i][k] and a[i][k + 1] and a[i + 1][k] and a[i + 1][k + 1]) {
      rs = 4;
    }
  }
  
  bool fl = 0;
  int cc, tt;
  retsu<char> vis(N, M);
  retsu<int> to(N, M);
  Z f = [&](Z &f, int x, int y, int c) -> void {
    fl |= x == 0 or x == N - 1 or y == 0 or y == M - 1;
    a[x][y] = 2;
    FOR(dx, -1, 2) FOR(dy, -1, 2) if (dx or dy) {
      int xx = x + dx, yy = y + dy;
      if (xx < 0 or yy < 0 or xx >= N or yy >= M) continue;
      if (a[xx][yy] == 0) f(f, xx, yy, c);
      else if (a[xx][yy] == 1 and to[xx][yy] != c) {
        to[xx][yy] = c;
        vis[xx][yy] = 1;
        ++cc;
      } 
    }
  };

  Z ck = [&](Z &f, int x, int y) -> void {
    vis[x][y] = 0;
    ++tt;
    int cc = 0;
    static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    FOR(i, 4) {
      int xx = dx[i] + x, yy = dy[i] + y;
      if (xx < 0 or yy < 0 or xx >= N or yy >= M) continue;
      if (to[xx][yy] == to[x][y]) {
        ++cc;
        if (vis[xx][yy]) f(f, xx, yy);
      }
    }
    fl |= cc != 2;
  };

  FOR(i, N) FOR(k, M) if (not a[i][k]) {
    fl = 0;
    cc = 0;
    f(f, i, k, i * M + k);
    if (fl or cc < rs) continue;
    fl = tt = 0;
    ck(ck, i - 1, k - 1);
    if (not fl and tt == cc) rs = cc;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}