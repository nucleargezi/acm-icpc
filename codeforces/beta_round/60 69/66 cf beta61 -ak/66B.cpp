#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int ans = 0;
  FOR(i, N) {
    int l = i, r = i;
    while (l > 0 and a[l - 1] <= a[l]) --l;
    while (r + 1 < N and a[r + 1] <= a[r]) ++r;
    chmax(ans, r - l + 1);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"