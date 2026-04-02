#include "YRS/all.hpp"

constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
bool ck(int x, int y) { 
  return min(x, y) >= 0 and max(x, y) < 4; 
}
void Yorisou() {
  int a[4][4];
  FOR(i, 4) FOR(k, 4) {
    INT(x);
    x = (x + 15) & 15;
    a[i][k] = x;
  }
  while (1) {
    int x, y;
    FOR(i, 4) FOR(k, 4) if (a[i][k] == 15) x = i, y = k;
    FOR(d, 4) {
      int xx = x + dx[d], yy = y + dy[d];
      if (ck(xx, yy) and a[xx][yy] == x * 4 + y) {
        swap(a[xx][yy], a[x][y]);
        goto go;
      }
    }
    break;
    go: ;
  }
  FOR(i, 4) FOR(k, 4) if (a[i][k] != i * 4 + k) return No();
  Yes();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"