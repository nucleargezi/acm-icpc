#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = array<array<array<int, 6>, 6>, 6>;
void se(T &a) {
  FOR(i, 6) FOR(k, 6) FOR(j, 6) a[i][k][j] = -1;
}
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  T f, ff;
  se(f);
  f[a[0]][5][5] = 0;
  f[5][a[0]][a[0]] = 0;
  FOR(i, 1, N) {
    int x = a[i];
    se(ff);
    FOR(i, 6) FOR(k, 6) FOR(j, 6) if (f[i][k][j] != -1) {
      if (i == 5) {
        chmax(ff[x][k][j], f[i][k][j]);
        chmax(ff[i][k][x], f[i][k][j] + (x - j + 5) % 5);
      } else if (k == 5) {
        chmax(ff[x][k][j], f[i][k][j] + (x - i + 5) % 5);
        chmax(ff[i][x][x], f[i][k][j]);
      } else {
        chmax(ff[x][k][j], f[i][k][j] + (x - i + 5) % 5);
        chmax(ff[i][k][x], f[i][k][j] + (x - j + 5) % 5);
      }
    }
    f.swap(ff);
  }
  int rs = 0;
  FOR(i, 6) FOR(k, 6) FOR(j, 6) if (f[i][k][j] != -1) {
    if (i == 5 or k == 5) chmax(rs, f[i][k][j]);
    else chmax(rs, f[i][k][j] + (k - i + 5) % 5);
  }
  print(rs + N);
}

int main() {
  Yorisou();
  return 0;
}