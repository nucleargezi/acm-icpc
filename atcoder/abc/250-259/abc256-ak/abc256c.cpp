#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  VEC(int, a, 3);
  VEC(int, b, 3);
  int c[3][3]{}, s = 0;
  Z ck = [&]() -> bool {
    c[0][2] = a[0] - c[0][0] - c[0][1];
    c[1][2] = a[1] - c[1][0] - c[1][1];
    c[2][0] = b[0] - c[1][0] - c[0][0];
    c[2][1] = b[1] - c[1][1] - c[0][1];
    int x = a[2] - c[2][0] - c[2][1];
    int y = b[2] - c[1][2] - c[0][2];
    if (x != y) return 0;
    c[2][2] = x;
    FOR(i, 3) FOR(k, 3) if (c[i][k] < 1) return 0;
    return 1;
  };
  FOR(i, 1, 31) FOR(k, 1, 31) FOR(j, 1, 31) FOR(l, 1, 31) {
    c[0][0] = i, c[0][1] = k, c[1][0] = j, c[1][1] = l;
    s += ck();
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}