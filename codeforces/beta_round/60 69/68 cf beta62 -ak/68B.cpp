#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  INT(N, K);
  RE g = 1 - RE(K) / 100;
  VEC(int, a, N);
  Z ck = [&](RE m) -> bool {
    RE s = 0;
    FOR(i, N) {
      if (a[i] >= m) s += g * (a[i] - m);
      else s -= m - a[i];
    }
    return s >= 0;
  };
  setp(9);
  print(binary_search_real<RE>(ck, 0, QMAX(a)));
}
#include "YRS/Z_H/main.hpp"