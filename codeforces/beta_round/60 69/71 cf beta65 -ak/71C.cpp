#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/divisors.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) a.ep(a[i]);
  for (int d : divisor(N)) {
    if (N / d < 3) continue;
    FOR(i, d) {
      int x = i, ok = a[x];
      while (x + d < i + N and ok) {
        x += d;
        ok &= a[x];
      }
      if (ok) return YES();
    }
  }
  NO();
}
#include "YRS/Z_H/main.hpp"