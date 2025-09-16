#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  ll s = 0, ans = inf<ll>;
  for (int &x : a) --x;
  vector<int> lst(N, -1);
  vector<int> c(N + 1);
  FOR(i, N) {
    int x = a[i];
    if (lst[x] == -1) {
      s += i;
    } else {
      int pr = lst[x], m = (pr + i) >> 1;
      if ((pr + i) & 1) {
        --c[m], --c[m + 1];
      } else {
        c[m] -= 2;
      }
    }
    c[i] += 2;
    lst[x] = i;
  }
  ll d = -K;
  FOR(i, N) {
    chmin(ans, s);
    d += c[i];
    s += d;
  }
  FOR(i, K) ans -= std::abs(i + 1 - (K + 1) / 2);
  print(ans);
}
#include "YRS/Z_H/main.hpp"