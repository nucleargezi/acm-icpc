#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};

void Yorisou() {
  INT(N, M);
  RET(char, a, N, M);
  for (char &c : a.a) c = c == '.';
  
  int s = 0;
  retsu<int> dis(N, M);
  vc<PII> q(N * M);
  
  FOR(i, N) FOR(k, M) if (a[i][k]) {
    dis.fill(-1);
    dis[i][k] = 0;
    q.clear();
    q.ep(i, k);
    FOR(i, si(q)) {
      Z [x, y] = q[i];
      FOR(d, 4) {
        int xx = x + dx[d], yy = y + dy[d];
        if (not(xx >= 0 and xx < N and yy >= 0 and yy < M) or not a[xx][yy]) continue;
        if (dis[xx][yy] == -1) dis[xx][yy] = dis[x][y] + 1, q.ep(xx, yy);
      }
    }
    chmax(s, dis.max());
  }
  print(s);
}

int main() { Yorisou(); }