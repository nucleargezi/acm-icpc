#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
void Yorisou() {
  RE a, b, k, c;
  IN(a, b, k, c);
  setp(9);

  k *= (a / b);
  c /= b;
  RE x = 0, y = k * x + c, xx = 10, yy = k * xx + c;
  Z pp = circle<RE>({0, 0}, 1).cross_point(line<RE>(point{x, y}, {xx, yy}));
  Z l = pp[0], r = pp[1];
  RE d = dist(l, r) / 2, t = sqrtl(1 - d * d), g = acosl(t) * 2;
  print(pi * a * b - pi * a * b * ((pi * (g / pi / 2) - t * d) / (pi)));
}
#include "YRS/Z_H/main.hpp"