#include "YRS/all.hpp"

void Yorisou() {
  LL(n, a, b);
  if (n < b) return print(n);
  ll s = 0, g = b - a, rs = n / b;
  while (rs > 0) {
    ll t = ceil(g * rs, b), k = ceil(rs - ((t - 1) * b) / g, t);
    s += k * (2 * rs - (k - 1) * t) / 2;
    rs -= k * t;
  }
  print(n - s * g);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"