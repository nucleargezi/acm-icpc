#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M);
  retsu<int> a(N, M);
  int t = 0;
  if (N == 2 and M == 3) {
    Yes();
    print(0, 4, 2);
    print(3, 1, 5);
    return;
  }
  if (N == 3 and M == 2) {
    Yes();
    print(0, 3);
    print(4, 1);
    print(2, 5);
    return;
  }
  if (N > M) {
    FOR(i, N) FOR(k, M) {
      a[i][k] = t;
      t += 2;
      if (t >= N * M) t = 1;
    }
  } else {
    FOR(k, M) FOR(i, N) {
      a[i][k] = t;
      t += 2;
      if (t >= N * M) t = 1;
    }
  }
  Z ck = [&](int x, int y) {
    return (x + 1) % (N * M) == y or (y + 1) % (N * M) == x;
  };
  FOR(i, N) FOR(k, M) {
    if (i and ck(a[i][k], a[i - 1][k])) return No();
    if (k and ck(a[i][k], a[i][k - 1])) return No();
  }
  Yes();
  print(a);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}