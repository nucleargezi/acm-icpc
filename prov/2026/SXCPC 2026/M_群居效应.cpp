#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
void Yorisou() {
  INT(N, M, da, db);
  VEC(string, a, N);
  Z rs = a;
  FOR(i, N) FOR(k, M) a[i][k] = a[i][k] == '.';
  ll s = 0;
  FOR(i, N) FOR(k, M) if (a[i][k]) {
    int d = 0;
    FOR(t, 4) {
      int x = i + dx[t], y = k + dy[t];
      if (x < 0 or y < 0 or x >= N or y >= M) continue;
      if (a[x][y]) ++d;
    }
    if (da + d > db - d) {
      rs[i][k] = 'A';
      s += da + d;
    } else {
      rs[i][k] = 'B';
      s += db - d;
    }
  }
  print(s);
  FOR(i, N) print(rs[i]);
}

int main() {
  Yorisou();
  return 0;
}