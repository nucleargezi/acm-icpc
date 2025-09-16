#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int l = N, r = -1;
  FOR(i, N) if (a[i] == 0) chmin(l, i), chmax(r, i);
  if (l == N) {
    print(1);
    print(1, N);
    return;
  }
  if (l == 0 and r == N - 1) {
    print(3);
    print(3, N);
    print(1, 2);
    print(1, 2);
    return;
  }
  if (l == r) l ? --l : ++r;
  print(2);
  print(l + 1, r + 1);
  print(1, N - (r - l));
}
#include "YRS/Z_H/main.hpp"