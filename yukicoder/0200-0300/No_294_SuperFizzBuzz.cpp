#include "YRS/all.hpp"

using T = i128;
map<T, T> mp;
T ke(T n, int md) {
  if (n < 10) {
    if (n >= 3 and md == 0) return 1;
    if (n >= 5 and md == 2) return 1;
    return 0;
  }
  if (mp.contains((n << 4) + md)) return mp[(n << 4) + md];
  T rs = md == 0 or md == 2;
  rs += ke((n - 3) / 10, md);
  rs += ke((n - 5) / 10, (md + 1) % 3);
  return mp[(n << 4) + md] = rs;
}
T ke(T n) { return ke((n - 5) / 10, 1); }
void Yorisou() {
  INT(N);
  T l = inf<i128>, r = 554;
  while (l - r > 1) {
    T m = (l + r) >> 1;
    ((ke(m) >= N) ? l : r) = m;
  }
  print(l);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"