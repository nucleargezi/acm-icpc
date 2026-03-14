#include "YRS/all.hpp"

void Yorisou() {
  vc<ll> f(1000);
  f[0] = 1, f[1] = 2;
  i128 s = 2;
  FOR(i, 2, 100) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] <= 4000000) s += f[i] & 1 ? 0 : f[i];
    else break;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"