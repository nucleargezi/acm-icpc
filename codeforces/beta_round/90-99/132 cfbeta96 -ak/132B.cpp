#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  VEC(string, s, N);
  int M = si(s[0]);

  Z ck = [&](int x, int y) {
    return min(x, y) >= 0 and x < N and y < M;
  };
  Z hsh = [&](int x, int y, int c, int d) {
    return 2 * c + d + 8 * (x * M + y);
  };

  vc<int> f(N * M << 3);
  FOR(x, N) FOR(y, M) FOR(c, 4) FOR(d, 2) {
    int xx = x, yy = y, di[]{c, (c + (d ? 3 : 1)) & 3};
    static constexpr int dx[]{1, 0, -1, 0}, dy[]{0, 1, 0, -1};
    FOR(i, 2) for (;;) {
      int nx = xx + dx[di[i]], ny = yy + dy[di[i]];
      if (ck(nx, ny) and s[x][y] == s[nx][ny]) xx = nx, yy = ny;
      else break;
    }
    xx += dx[di[0]], yy += dy[di[0]];
    if (ck(xx, yy) and s[xx][yy] != '0') {
      f[hsh(x, y, c, d)] = hsh(xx, yy, c, d);
      continue;
    }
    if (d) f[hsh(x, y, c, d)] = hsh(x, y, (c + 3) & 3, 0);
    else f[hsh(x, y, c, d)] = hsh(x, y, c, d + 1);
  }

  char rs;
  for (int e = hsh(0, 0, 1, 0); K--; ) {
    int t = f[e], p = t >> 3, x = p / M, y = p % M;
    rs = s[x][y];
    e = t;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}