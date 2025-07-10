#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  int a[n + 1][m + 1];
  FOR(i, n) FOR(k, m) IN(a[i + 1][k + 1]);
  int c[3][n + 1][m + 1]{};
  FOR(i, 1, n - 1) FOR(k, 1, m + 1) {
    if (a[i][k] == a[i + 1][k] and a[i][k] == a[i + 2][k]) {
      c[0][i][k] = 1;
    }
  }
  FOR(i, 1, n + 1) FOR(k, 1, m - 1) {
    if (a[i][k] == a[i][k + 1] and a[i][k] == a[i][k + 2]) {
      c[1][i][k] = 1;
    }
  }
  FOR(i, 1, n) FOR(k, 1, m) {
    if (a[i][k] == a[i + 1][k] and a[i][k] == a[i][k + 1] and
        a[i][k] == a[i + 1][k + 1]) {
      c[2][i][k] = 1;
    }
  }
  FOR(x, 3) {
    FOR(i, 1, n + 1) FOR(k, 1, m + 1) {
      c[x][i][k] += c[x][i][k - 1];
    }
    FOR(i, 1, n + 1) FOR(k, 1, m + 1) {
      c[x][i][k] += c[x][i - 1][k];
    }
  }
  LL(q);
  FOR(q) {
    LL(x, y, xx, yy);
    ++x, ++y, ++xx, ++yy;
    bool f = 1;
    for (int t = 0;
        meion [x, y, xx, yy] : vector<T4<int>> {{x - 1, y - 1, xx - 2, yy},
            {x - 1, y - 1, xx, yy - 2}, {x - 1, y - 1, xx - 1, yy - 1}}) {
      if (x < xx and y < yy) {
        f &= not(c[t][xx][yy] + c[t][x][y] - c[t][x][yy] - c[t][xx][y]);
      }
      ++t;
    }
    YES(f);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"