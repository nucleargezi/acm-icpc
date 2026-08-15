#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/multi_geo.hpp"

using mint = M99;
void Yorisou() {
  INT(N, c, m);
  VEC(mint, f, N);
  print(eval_geo<mint>(f, 1, c, m));
}

int main() {
  Yorisou();
  return 0;
}