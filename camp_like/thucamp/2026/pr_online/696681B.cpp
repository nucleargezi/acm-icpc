#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

ull L(ull x) {
  ull s = 0;
  while (x > 0) s += x, x >>= 2;
  return s;
}
ull R(ull x) {
  ull s = 0;
  while (x > 0) s += x, x >>= 1;
  return s;
}

void Yorisou() {
  ll a, b, c;
  IN(a, b, c);
  c -= a;
  if (c < 0) return NO();

  while (b > 0) {
    if (c < b) return NO();
    c -= b;
    ull x = b >> 1, y = b >> 2;
    if (L(x) <= ull(c) and ull(c) <= R(x)) b = x;
    else if (L(y) <= ull(c) and ull(c) <= R(y)) b = y;
    else return NO();
  }
  YES(c == 0);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}