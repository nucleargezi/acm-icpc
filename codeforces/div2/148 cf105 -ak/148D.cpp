#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

using re = ld;
void Yorisou() {
  INT(a, b);
  retsu<array<re, 2>> f(a + 1, b + 1, {});
  FOR(i, a + 1) FOR(k, b + 1) FOR(c, 2) {
    re s = 0;
    if (i + k == 0 or (i + k <= 2 and c)) {
      s = 0;
    } else {
      re ls = re(i) / (i + k), rs = re(k) / (i + k);
      if (c) {
        if (k) {
          re ii = re(i) / (i + k - 1), kk = re(k - 1) / (i + k - 1);
          if (i) s += rs * ii * f[i - 1][k - 1][0];
          if (k > 1) s += rs * kk * f[i][k - 2][0];
        } else {
          s = 0;
        }
      } else {
        s += ls;
        if (k) s += rs * f[i][k - 1][1];
      }
    }
    f[i][k][c] = s;
  }
  setp(9);
  print(f[a][b][0]);
}

int main() {
  Yorisou();
  return 0;
}