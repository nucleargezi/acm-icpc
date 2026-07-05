#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> b, c;
  FOR(i, N) ((pc(a[0] ^ a[i]) & 1) ? c : b).ep(a[i]);
  print(max(SUM<ll>(c), SUM<ll>(b)));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}