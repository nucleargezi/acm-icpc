#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/bs.hpp"

void Yorisou() {
  INT(N);
  vc<bs> f(N);
  FOR(i, N) {
    STR(s);
    f[i] = s;
  }
  int rs = 0;
  FOR(y, N) {
    int s = 0;
    FOR_R(x, y + 1, N) {
      if (f[x][y] ^ s) {
        f[x].range_flip(y, x + 1);
        s ^= 1;
        ++rs;
      }
    }
    if (s) f[y].flip(y);
  }
  FOR_R(y, N) {
    int s = 0;
    FOR(x, y) {
      if (f[x][y] ^ s) {
        f[x].range_flip(x, y + 1);
        s ^= 1;
        ++rs;
      }
    }
    if (s) f[y].flip(y);
  }
  FOR(i, N) rs += f[i][i];
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}