#include "YRS/all.hpp"

using re = ld;
void Yorisou() {
  INT(a, b, x, y);
  int g = gcd(a, b);
  a /= g, b /= g;
  setp(10);
  print(min((re)x / a, (re)y / b) * (a + b));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"