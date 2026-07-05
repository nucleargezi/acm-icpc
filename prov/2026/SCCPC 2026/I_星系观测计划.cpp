#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/hull.hpp"

using re = ld;
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  a = rearrange(a, hull(a));
  N = si(a);
  re s = 0;
  FOR(i, N) s += (a[i] - a[(i + 1) % N]).length();
  print(s * 4 / pi);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}