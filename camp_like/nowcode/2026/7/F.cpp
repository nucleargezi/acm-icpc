#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/sps/bit.hpp"

void Yorisou() {
  INT(N, d);
  VEC(int, a, N);
  VEC(int, b, N);
  INT(T);
  int X = 0;
  for (int x : a) X ^= x;
  vc<int> c(1 << d);
  for (int x : a) ++c[x];
  for (int x : b) --c[x];
  hadamard(c);
  X ^= T;
  FOR(s, 1 << d) if ((pc(s & X) & 1) and c[s] == 0) return NO();
  YES();
}

int main() {
  Yorisou();
  return 0;
}