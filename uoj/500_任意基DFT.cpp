#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/multi_geo.hpp"
#include "YRS/fps/shift.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  VEC(mint, f, N + 1);
  mint a, b, c;
  IN(a, b, c);
  c = -c / mint(b - 1), a -= c;
  uint s = 0;
  Z rs = eval_geo(shift(f, c), a, b, Q + 1);
  for (mint x : rs) s ^= x.val();
  s ^= rs[0].val();
  print(s);
}

int main() { Yorisou(); }