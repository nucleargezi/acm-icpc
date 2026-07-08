#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  RET(int, a, N, N);
  for (int &x : a.a) --x;
  VEC(int, b, N);
  b = argsort(b);
  vc<int> rs(N);
  FOR(i, N) FOR(k, N) if (a[i][k] != i) {
    int f = 0;
    FOR(j, a[i][k]) {
      if (b[j] < b[a[i][k]] and i != j) {
        f = 1;
        break;
      }
    }
    if (f) continue;
    rs[i] = a[i][k] + 1;
    break;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}