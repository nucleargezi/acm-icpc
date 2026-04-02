#include "YRS/all.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  VEC(int, b, N);
  if (K == 0) return print(0);

  ll s = 0, g = 0;

  Z sp = [&](int i, int k) {
    g -= abs(a[i] - b[i]) + abs(a[k] - b[k]);
    swap(a[i], a[k]);
    g += abs(a[i] - b[i]) + abs(a[k] - b[k]);
  };
  
  Z f = [&]() -> bool {
    int l = 0, r = N, i = 0;
    if (l == r) return 0;
    ++i;
    if (i == r) return 0;
    i = r;
    --i;
    while (1) {
      int ii = i;
      --i;
      if (a[i] < a[ii]) {
        int k = r;
        while (not (a[i] < a[--k]));
        sp(i, k);
        FOR(e, (r - ii) >> 1) sp(e + ii, r - e - 1);
        return 1;
      }
      if (i == l) {
        --r;
        while (l < r) sp(l, r), ++l, --r;
        return 0;
      }
    }
  };
  FOR(i, N) g += abs(a[i] - b[i]);
  s += g;
  FOR(K - 1) f(), s += g;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"