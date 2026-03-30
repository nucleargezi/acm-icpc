#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  sort(a);
  if (N & 1) print(a[N >> 1]);
  else print((a[N >> 1] + a[(N >> 1) - 1]) / ld(2));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"