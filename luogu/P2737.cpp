#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  constexpr int sz = 256 * 256;
  vc<char> f(sz);
  f[0] = 1;
  for (int x : a) FOR(i, sz - x) if (f[i] and i + x < sz) f[i + x] = 1;
  FOR_R(i, sz) if (not f[i]) return print(i > 65024 ? 0 : i);
  print(0);
}

int main() { Yorisou(); }