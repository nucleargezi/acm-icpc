#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z I(argsort(a));
  a = rearrange(a, I);
  for (int &i : I) ++i;
  print(I);
  ll s = 0;
  for (int i = 0; i < N; ++i) s += a[i] * (N - i - 1);
  setp(2);
  print(s / ld(N));
}

int main() {
  Yorisou();
  return 0;
}