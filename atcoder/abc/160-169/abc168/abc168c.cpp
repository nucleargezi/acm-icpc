#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;

pair<re, re> f(re x, ll d) {
  x *= pi * 2;
  return {d * sin(x), d * cos(x)};
}

void Yorisou() {
  LL(a, b, h, m);
  Z [x, y] = f(re(h) / 12 + re(m) / 60 / 12, a);
  Z [c, d] = f(re(m) / 60, b);
  x -= c, y -= d;
  print(sqrtl(x * x + y * y));
}

int main() { Yorisou(); }