#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

constexpr int dx[] {1, -1, 0, 0, 1, -1, 1, -1},
              dy[] {0, 0, 1, -1, 1, -1, -1, 1};
void Yorisou() {
  INT(N, M);
  VEC(string, a, N);
  retsu<int> d(N, M, -1);
  vc<PII> q;
  int l = 0;
  FOR(i, N) FOR(k, M) if (a[i][k] == '.') {
    FOR(g, 8) {
      int x = i + dx[g], y = k + dy[g];
      if (x >= 0 and y >= 0 and x < N and y < M and a[x][y] == '#') {
        q.ep(i, k), d[i][k] = 0;
        break;
      }
    }
  }
  if (q.empty()) {
    FOR(i, N) {
      FOR(k, M) a[i][k] = '.';
      print(a[i]);
    }
    return;
  }
  while (l < si(q)) {
    Z [x, y] = q[l++];
    FOR(k, 8) {
      int xx = x + dx[k], yy = y + dy[k];
      if (xx >= 0 and yy >= 0 and xx < N and yy < M and d[xx][yy] == -1) {
        d[xx][yy] = d[x][y] + 1;
        q.ep(xx, yy);
      }
    }
  }
  FOR(i, N) {
    FOR(k, M) a[i][k] = (d[i][k] & 1) ? '#' : '.';
    print(a[i]);
  }
}

int main() {
  Yorisou();
  return 0;
}