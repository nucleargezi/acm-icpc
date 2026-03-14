#include "YRS/all.hpp"

void Yorisou() {
  LL(A);
  constexpr ll x[]{3, 5, 17, 257, 65537};
  int s = 0;
  FOR(m, 1 << 5) {
    ll g = 1;
    FOR(k, 5) if (m >> k & 1) g *= x[k];
    while (g <= A) s += g >= 3, g <<= 1;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"