#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

int slv(int a, int b) {
  if (gcd(a, b) != 1) return inf<int>;
  int s = 0;
  while (a + b > 2) {
    ll d = a / b;
    if (a == d * b) --d;
    a -= d * b;
    s += d;
    swap(a, b);
  }
  return s;
}

void Yorisou() {
  INT(N);
  int s = N;
  FOR(i, 1, N << 1 | 1) chmin(s, slv(i, N));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}