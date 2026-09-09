#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/conv_gcd.hpp"

void Yorisou() {
  INT(N);
  VEC(int, f, N);
  int M = QMAX(f) + 1;
  vc<ll> a(M + 1);
  for (int x : f) a[x] += x;
  multi_zeta(a);
  FOR(i, M + 1) a[i] *= a[i];
  multi_mobius(a);
  ll s = 0;
  FOR(i, 1, M + 1) s += a[i] / i;
  print(s);
}

int main() { Yorisou(); }