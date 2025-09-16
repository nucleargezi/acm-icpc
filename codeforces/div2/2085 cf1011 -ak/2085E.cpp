#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/PR/divisors.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  ll x = SUM(a) - SUM(b);
  if (x < 0) return print(-1);
  if (x == 0) return print(sorted(a) != sorted(b) ? -1 : 1'000'000'000);

  static int c[1'000'000 + 1];
  FOR(i, N) ++c[b[i]];
  vector<int> his;
  Z rollback = [&]() -> void {
    for (int x : his) ++c[x];
    his.clear();
  };
  int max = QMAX(b);
  for (Z e : sorted(divisor(x))) {
    if (max < e) {
      bool f = true;
      FOR(i, N) {
        ll x = a[i] % e;
        if (c[x] == 0) {
          rollback();
          f = false;
          break;
        } else {
          --c[x];
          his.emplace_back(x);
        }
      }
      if (f) return print(e);
    }
  }
  print(-1);
  FOR(i, N) c[b[i]] = 0;
}
#include "YRS/Z_H/main.hpp"