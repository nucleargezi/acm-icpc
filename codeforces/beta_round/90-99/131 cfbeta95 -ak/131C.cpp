#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

i128 fac(i128 n) {
  i128 s = 1;
  FOR(i, 1, n + 1) s *= i;
  return s;
}

i128 C(i128 n, i128 k) {
  return fac(n) / fac(n - k) / fac(k);
}

void Yorisou() {
  LL(N, M, T);
  i128 s = 0;
  FOR(a, N + 1) if (a >= 4 and T - a >= 1) s += C(N, a) * C(M, T - a);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}