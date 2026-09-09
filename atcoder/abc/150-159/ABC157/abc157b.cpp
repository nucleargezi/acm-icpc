#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  int a[3][3], c[3][3]{};
  FOR(i, 3) FOR(k, 3) IN(a[i][k]);
  INT(Q);
  FOR(Q) {
    INT(x);
    FOR(i, 3) FOR(k, 3) if (a[i][k] == x) c[i][k] = 1;
  }
  bool f = 0;
  FOR(i, 3) {
    f |= c[i][0] and c[i][1] and c[i][2];
    f |= c[0][i] and c[1][i] and c[2][i];
  }
  f |= c[0][0] and c[1][1] and c[2][2];
  f |= c[0][2] and c[1][1] and c[2][0];
  Yes(f);
}

int main() { Yorisou(); }